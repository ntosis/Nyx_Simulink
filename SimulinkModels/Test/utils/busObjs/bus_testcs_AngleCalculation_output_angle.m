function bus_testcs_AngleCalculation_output_angle() 
% A initializes a set of bus objects in the MATLAB base workspace 

% Bus object: AngleBusObj 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'Elect';
elems(1).Dimensions = 1;
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'single';
elems(1).Complexity = 'real';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

elems(2) = Simulink.BusElement;
elems(2).Name = 'Mech';
elems(2).Dimensions = 1;
elems(2).DimensionsMode = 'Fixed';
elems(2).DataType = 'single';
elems(2).Complexity = 'real';
elems(2).Min = [];
elems(2).Max = [];
elems(2).DocUnits = '';
elems(2).Description = '';

AngleBusObj = Simulink.Bus;
AngleBusObj.HeaderFile = '';
AngleBusObj.Description = '';
AngleBusObj.DataScope = 'Auto';
AngleBusObj.Alignment = -1;
AngleBusObj.PreserveElementDimensions = 0;
AngleBusObj.Elements = elems;
clear elems;
assignin('base','AngleBusObj', AngleBusObj);

