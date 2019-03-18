private ["_v"];

_v = _this select 0;
_v setVariable ["wiperstate",0]; //init the wiper variable

//if (_v animationPhase "wiperr" > .8) then 
//{
(_v animate ["wiperr",0]);
(_v animate ["wiperl",0]);
//};

exit;