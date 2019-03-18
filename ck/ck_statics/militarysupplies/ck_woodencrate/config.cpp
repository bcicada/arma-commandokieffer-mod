#define _ARMA_

class CfgPatches
{
	class ck_woodencrate_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F"};
		version = "0.1.1";
	};
};

class CfgVehicles
{
	class All;
	class Thing;
	class ThingX;
	class ReammoBox;
	class ReammoBox_F;
	class NATO_Box_Base;
	class Box_NATO_Wps_F;
	
	class ck_woodencrate_ammo_base_v: Box_NATO_Wps_F
	{
		scope = 1;
		author = "Noks";
		displayName = "Caisse de munitions";
		model = "ck\ck_statics\militarysupplies\ck_woodencrate\ck_woodencrate.p3d";
		icon = "ck\ck_main\data\ck_logo_32_ca.paa";
		picture = "ck\ck_statics\militarysupplies\ck_woodencrate\data\ui\ck_woodencrate_ico_ca.paa";
		editorPreview = "ck\ck_statics\militarysupplies\ck_woodencrate\data\ui\ck_woodencrate_ico_ca.jpg";
		dlc = "CommandoKieffer";
		editorCategory = "ck_edtCat_statics";
		vehicleClass = "ck_vehCls_statics_militarysupplies";
		editorSubCategory = "ck_edtSubCat_statics_militarysupplies";
		
		transportMaxWeapons = 0;
		transportMaxMagazines = 50;
		maximumLoad = 10000;
		class TransportWeapons{};
		class TransportMagazines
		{
			class xxck_thompson_magazine
			{
				magazine = "ck_thompson_magazine";
				count = 5;
			};
			class xxck_thompson_m1928_magazine
			{
				magazine = "ck_thompson_m1928_50_mag";
				count = 5;
			};
			class xxck_smle_magazine
			{
				magazine = "ck_smle_magazine";
				count = 10;
			};
			class xxck_sten_magazine
			{
				magazine = "ck_sten_magazine";
				count = 5;
			};
			class xxck_bren_magazine
			{
				magazine = "ck_bren_magazine";
				count = 5;
			};
			class xxck_m1911_w
			{
				magazine = "ck_m1911_magazine";
				count = 10;
			};
		};
	};
	
	class ck_woodencrate_weapons_base_v: ck_woodencrate_ammo_base_v
	{
		author = "Noks";
		displayName = "Caisse d'armes";
		transportMaxWeapons = 5;
		transportMaxMagazines = 0;
		class TransportWeapons
		{
			class xxck_thompson_w
			{
				weapon = "ck_thompson_w";
				count = 1;
			};
			class xxck_thompson_m1928_w
			{
				weapon = "ck_thompson_m1928_w";
				count = 1;
			};
			class xxck_smle_w
			{
				weapon = "ck_smle_w";
				count = 1;
			};
			class xxck_sten_w
			{
				weapon = "ck_sten_w";
				count = 1;
			};
			class xxck_bren_w
			{
				weapon = "ck_bren_w";
				count = 1;
			};
			class xxck_m1911_w
			{
				weapon = "ck_m1911_w";
				count = 1;
			};
		};
		class TransportMagazines{};
	};
	
	class ck_woodencrate_arsenal_base_v: ck_woodencrate_ammo_base_v
	{
		author = "Noks";
		displayName = "Caisses de ravitaillement";
		model = "ck\ck_statics\militarysupplies\ck_woodencrate\ck_woodencrate_arsenal.p3d";
		transportMaxWeapons = 60;
		transportMaxMagazines = 600;
		class TransportWeapons
		{
			class xxck_thompson_w
			{
				weapon = "ck_thompson_w";
				count = 5;
			};
			class xxck_thompson_m1928_w
			{
				weapon = "ck_thompson_m1928_w";
				count = 5;
			};
			class xxck_smle_w
			{
				weapon = "ck_smle_w";
				count = 10;
			};
			class xxck_sten_w
			{
				weapon = "ck_sten_w";
				count = 5;
			};
			class xxck_bren_w
			{
				weapon = "ck_bren_w";
				count = 5;
			};
			class xxck_m1911_w
			{
				weapon = "ck_m1911_w";
				count = 20;
			};
		};
		class TransportMagazines
		{
			class xxck_thompson_magazine
			{
				magazine = "ck_thompson_magazine";
				count = 50;
			};
			class xxck_thompson_m1928_magazine
			{
				magazine = "ck_thompson_m1928_50_mag";
				count = 50;
			};
			class xxck_smle_magazine
			{
				magazine = "ck_smle_magazine";
				count = 100;
			};
			class xxck_sten_magazine
			{
				magazine = "ck_sten_magazine";
				count = 50;
			};
			class xxck_bren_magazine
			{
				magazine = "ck_bren_magazine";
				count = 50;
			};
			class xxck_m1911_w
			{
				magazine = "ck_m1911_magazine";
				count = 150;
			};
		};
	};
	
	
	class ck_woodencrate_ammo_v: ck_woodencrate_ammo_base_v
	{
		author = "Noks";
		scope = 2;
	};
	class ck_woodencrate_weapons_v: ck_woodencrate_weapons_base_v
	{
		author = "Noks";
		scope = 2;
	};
	
	class ck_woodencrate_arsenal_v: ck_woodencrate_arsenal_base_v
	{
		author = "Noks";
		scope = 2;
	};
	class ck_woodencrate_arsenal_plus_v: ck_woodencrate_arsenal_base_v
	{
		author = "Noks";
		scope = 2;
		displayName = "Caisses de ravitaillement (Arsenal)";
		class UserActions
		{
			class initArsenalAce
			{
				displayName = "Arsenal ace";
				position = "camera";
				showWindow = 0;
				radius = 5;
				onlyForPlayer = 0;
				priority = -1;
				condition = "(alive this) and (isClass(configFile >> ""CfgPatches"" >> ""ace_arsenal""))";
				statement = "[player,player,true] call ace_arsenal_fnc_openBox";
				shortcut = "";
			};
			class initArsenalBis
			{
				displayName = "Arsenal bis";
				position = "camera";
				showWindow = 0;
				radius = 5;
				onlyForPlayer = 0;
				priority = -1;
				condition = "(alive this)";
				statement = "[""Open"",[true]] call BIS_fnc_arsenal;";
				shortcut = "";
			};
		};
	};
};