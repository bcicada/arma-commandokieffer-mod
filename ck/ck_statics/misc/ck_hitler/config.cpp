#define _ARMA_
#define WEST 1
#define times_4(a) a,a,a,a
#define times_8(a) a,a,a,a,a,a,a,a

class CfgPatches
{
	class ck_statics
	{
		author = "Noks";
		version = "0.10.4";
		requiredVersion = 1.8;
		requiredAddons[] = {};
		units[] = {"ck_hitler_o","ck_grave_noname_o"};
	};
};

class CfgVehicles
{	
	class Static;
	class ck_hitler_o : Static
	{
		scope = 2;
		model = "ck\ck_statics\ck_hitler.p3d";
		displayName = "Hitler";
		faction = "Empty";
		vehicleClass = "Small_items";
	};
	class ck_grave_noname_o: ck_hitler_o
	{
		model = "ck\ck_statics\ck_grave.p3d";
		displayName = "Tombe sans nom";
	};
};