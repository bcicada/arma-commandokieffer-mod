//unused
private ["_v"];
_v = _this select 0;

while {((isengineon _v) and (alive _v) and (overcast > 0.8) )} do
{
	_v say3D "wiper";
	sleep 1.5;
	if (_v animationPhase "wiperr" < 0.2) then
	{
		(_v animate ["wiperr",1]);
		(_v animate ["wiperl",1]);
	};
	sleep 1.5;
	if (_v animationPhase "wiperr" > .8) then
	{
		(_v animate ["wiperr",0]);
		(_v animate ["wiperl",0]);
	};
};

