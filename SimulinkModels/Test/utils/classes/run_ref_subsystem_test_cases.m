classdef run_ref_subsystem_test_cases < handle
    properties
        model
        file % File with three columns
        success % Simulation success flag
        failedModels
    end
    properties (Access = private)
        data
        
    end
    
    methods
        function obj = run_ref_subsystem_test_cases(file)
            
            obj.file = file;
            obj.success = true;
            obj.data = readtable(obj.file, 'Delimiter', ' ','Format', ...
                "%s%d%s",'VariableNamingRule','preserve'); % space-separated
            obj.failedModels={};
        end
        
        function runSimulations(obj)
            
            for i = 1:height(obj.data)
                obj.model=obj.data.modelName{i};
                open_system(obj.model);
                outputFileName = obj.data.resultDataFileName{i};
                time = uint32(obj.data.simulationTime(i));
                % Find the "read from file" block and set the file name property
                obj.setResultsFileName(outputFileName);
                                
                % Check the simulation result
                if obj.runSimulation(obj.model,time)
                    obj.success = false;
                end
            end
            
            if obj.success
                disp('All simulations passed successfully.');
            else
                disp('Simulation failed for one or more cases.');
                disp(['Failed models:' join(string(obj.failedModels),'-')]);
                %exit(1);
            end
        end
        
        function setResultsFileName(obj,outputFileName)
            blockList = find_system(bdroot,'Type', 'block','BlockType','FromFile','Name','results from file');
            if(length(blockList)) == 0
                error('Be sure that the block inport from file has the name ''results from file''');
                
            end
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