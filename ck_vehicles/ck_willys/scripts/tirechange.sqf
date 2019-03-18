if (isDedicated) exitWith {};

_M1161 = _this select 0;

_M1161 animate ["spare", 1];

// 'RepairingKneel' - 120 seconds
player playMove 'AinvPknlMstpSlayWrflDnon_medic';
sleep 8;
player playMove 'AinvPknlMstpSlayWrflDnon_medic';
sleep 7.2;

_M1161 setHit ["levy predni tlumic", 0];
_M1161 setHit ["levy zadni tlumic", 0];
_M1161 setHit ["pravy predni tlumic", 0];
_M1161 setHit ["pravy zadni tlumic", 0];

_M1161 setDamage 0.1;