classdef run_AngleCalculation_test_cases < handle
    properties
        model
        file % File with three columns
        success % Simulation success flag
    end
    properties (Access = private)
        data
        failedModels={}
    end
    
    methods
        function obj = run_AngleCalculation_test_cases(file)
            
            obj.file = file;
            obj.success = true;
            obj.data = readtable(obj.file, 'Delimiter', ' ','Format', ...
                "%s%s%s%s%d%s%s",'VariableNamingRule','preserve'); % space-separated
            obj.model=obj.data.modelName{1};
        end
        
        function runSimulations(obj)
            open_system(obj.model);
            for i = 1:height(obj.data)
                
                
                time = uint32(obj.data.simulationTime(i));
                %load bus Obj
                obj.loadBus(obj.data.busObj{i})                
                % Find the ManualSwitch and set
                obj.setManualSwitch(obj.data.switch_name{1},obj.data.switch_position{i});      
                % Find the "read from file" block and set the file name property
                obj.setResultsFileName(obj.data.sensor_encoder_out_results_file{i},obj.data.angle_out_results_file{i})
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
                %error(1);
            end
        end

        function setManualSwitch(obj,name,pos)
            blockList = find_system(bdroot,'Type', 'Block','Name',name);
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1}, 'sw', pos); 
        end

        
        function setResultsFileName(obj,counter_out_file,angle_out_file)
            blockList = find_system(bdroot,'Type', 'block','Name','angle_out');
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1},'FileName', angle_out_file);

            blockList = find_system(bdroot,'Type', 'block','Name','counter_out');
            if ~iscell(blockList)
            blockList = {blockList};
            end
            set_param(blockList{1},'FileName', counter_out_file);
                      
                            
        end

        function loadBus(obj,file)
            [fPath, fName, fExt] = fileparts(file);
            switch lower(fExt)
                case '.mat'
                 % A MAT file
                 evalin('base', ['load(''' file ''')']);
                case '.m'
                  % A m file
                  evalin('base', ['run(''' file ''')']);
                otherwise  % Under all circumstances SWITCH gets an OTHERWISE!
                error('Unexpected file extension: %s', fExt);
            end
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
