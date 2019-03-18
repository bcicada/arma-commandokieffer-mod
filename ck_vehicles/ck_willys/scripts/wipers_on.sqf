private ["_v"];
_v = _this select 0;

//and (overcast > 0.8)
while {((isengineon _v) and (alive _v) and (_v getVariable "wiperstate" == 1) ) } do
{
	[_v, "wipers"] call ck_fnc_remoteSay3D;
	sleep 1.5;
	if (_v animationPhase "wiperr" < 0.05) then 
	{
		(_v animate ["wiperr",1]);
		(_v animate ["wiperl",1]);
	};
	sleep 1.5;
	if (_v animationPhase "wiperr" > .95) then 
	{
		(_v animate ["wiperr",0]);
		(_v animate ["wiperl",0]);
	};
};
//no engine, dead or switched off - return to default
_v animate ["wiperr",0];
_v animate ["wiperl",0];
_v setVariable ["wiperstate",0];

exit;