private _unit = _this select 0;
private _param1 = param [1];
private _param2 = param [2];
private _weapon = currentWeapon _unit;
private _muzzle = currentMuzzle _unit;
if (_unit ammo _weapon == 0) exitWith {};
waitUntil {_unit setWeaponReloadingTime [_unit,_muzzle,1]; (inputAction "DefaultAction" == 0)};
_unit playaction _param1;
if ((player == _unit) && (cameraView != "EXTERNAL")) then {
	playSound _param2;
} else {
	if (((positionCameraToWorld [0,0,0]) distance _unit) <= 30) then {
		private _dummy  = "#particlesource" createVehicleLocal (ASLtoATL (eyePos _unit));
		_dummy say3d _param2;
		sleep 2.5;
		deleteVehicle _dummy;
	};
};