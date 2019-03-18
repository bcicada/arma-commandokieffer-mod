private ["_v"];
_v = _this select 0;

while {((isengineon _v) and (alive _v)) } do //alive and engine on
{
	if  (overcast > 0.8) then //raining
	{
		if  !(_v getVariable "wiperstate" == 1) then //and wipers off
		{
			_v setVariable ["wiperstate", 1];
			[_v] execVM "\uns_wheeled_w_c\scripts\wipers_on.sqf";
		};		
	};
/*
	else //not raining
	{
		if  !(_v getVariable "wiperstate" == 0) then //and wipers on
		{
			_v setVariable ["wiperstate", 0];
			[_v] execVM "\uns_wheeled_w_c\scripts\wipers_off.sqf";
		};		
	};
*/
	sleep 20.33; //between checks
};
