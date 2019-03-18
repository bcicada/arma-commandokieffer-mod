//if (isDedicated) exitWith {};
PRIVATE ["_boat","_pos","_list","_posflare","_flare"];

_boat = _this select 0;
_pos = position _boat;

_list = _pos nearObjects ["uns_vecflare_r", 250];
if ((count _list) > 1) exitWith {_boat vehicleChat "Il y a déjà trop de fusées éclairantes";};

// else...
_posflare = [_pos select 0, _pos select 1, (_pos select 2) + 250];
_boat say3D "pbr_flarelaunch";
_flare = "uns_vecflare_r" createVehicle _posflare;

// default flare isn't affected by weather or gravity
while {alive _flare} do
{
	_flare setPosASL [(getPosASL _flare select 0) + 0.1 * (wind select 0), (getPosASL _flare select 1) + 0.1 * (wind select 1), (getPosASL _flare select 2) - 0.25];
	sleep 0.075;
};
