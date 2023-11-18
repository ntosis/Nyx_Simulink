classdef run_ADCRawToIab_test_cases < handle
    properties
        model
        file % File with three columns
        success % Simulation success flag
    end
    properties (Access = private)
        data
        failedModels={};
    end
    
    methods
        function obj = run_ADCRawToIab_test_cases(file)
            
            obj.file = file;
            obj.success = true;
            obj.data = readtable(obj.file, 'Delimiter', ' ','Format', ...
                "%s%s%d%s%d%s%s",'VariableNamingRule','preserve'); % space-separated
            obj.model=obj.data.modelName{1};
        end
        
        function runSimulations(obj)
            open_system(obj.model);
            for i = 1:height(obj.data)
                signalEditorInputFile=obj.data.signalEditorFileName{i};
                scenario = obj.data.Scenario{i};
                gain = obj.data.GainValue(i); %% use parenthesis becuase format is %d for this column
                outputFileName = obj.data.resultDataFileName{i};
                time = uint32(obj.data.simulationTime(i));
                %load bus Obj
                evalin('base', ['load(''' obj.data.busObj{i} ''')']);
                % Find the signal editor block and set the scenario name
                obj.setScenarioName(scenario,signalEditorInputFile);
                % Find the DRV_GAIN block and set the gain value
                obj.setGainValue(gain);                
                % Find the "read from file" block and set the file name property
                obj.setResultsFileName(outputFileName);
                % Simulation code here
                % Simulate the model
                
                % Check the simulation result
                if obj.runSimulation(obj.model,time)
                    obj.success = false;
                end
            end
            
            if obj.success
                disp('All simulations passed successfully.');
            else
                disp(['Failed models:' join(string(obj.failedModels),'-')]);
                error('Simulation failed for one or more cases.');
                %exit(1);
            end
        end
        
        function setGainValue(obj,gain)
            blockList = find_system(bdroot,'Type', 'Block','Name','DRV_GAIN');
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1}, 'Gain', num2str(gain));      
        end

        function setScenarioName(obj,scenarioName,signalEditorInputFile)
            blockList = find_system(bdroot,'Type', 'block','Name','Signal Editor');
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1}, 'FileName', signalEditorInputFile);
            set_param(blockList{1}, 'ActiveScenario', scenarioName);
            
                            
        end

        function setResultsFileName(obj,outputFileName)
            blockList = find_system(bdroot,'Type', 'block','BlockType','FromFile','Name','results from file');
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1}, 'FileName', outputFileName);
                            
        end

        function exit_code = runSimulation(obj,model,time)
            exit_code = 0;
    
        try
            sim(model,"StopTime",num2str(time));
        catch ME
            disp(getReport(ME))
            exit_code = 1;
            obj.failedModels{end+1}=model;
        end
        
        end    
        %%Destructor
        function delete(obj)
             for i = 1:height(obj.data)
                obj.model=obj.data.modelName{i};
                close_system(obj.model,0);
             end
        end 
    end
end
