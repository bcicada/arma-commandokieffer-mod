#define _ARMA_

class CfgPatches
{
	class ck_platform_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F"};
		version = "0.82.15";
	};
};

class CfgVehicles
{
	class All;
	class Thing: All{};
	class ThingX: Thing{};
	class ck_platform: ThingX
	{
		author = "Ohliger";
		displayName = "Estrade en bois";
		scope = 2;
		model = "ck\ck_statics\misc\ck_platform\ck_platform.p3d";
		icon = "ck\ck_main\data\ck_logo_32_ca.paa";
		picture = "ck\ck_main\data\ck_logo_ca.paa";
		dlc = "CommandoKieffer";
		editorCategory = "ck_edtCat_statics";
		vehicleClass = "ck_vehCls_statics_misc";
		editorSubCategory = "ck_edtSubCat_statics_misc";
	};
};