class CfgPatches
{
	class ck_weapons_p
	{
		author = "Noks";
		version = "Anatole 0.98";
		requiredVersion = 1.8;
		requiredAddons[] = {"A3_data_f"};
	};
};

class CfgVehicles
{
	class ReammoBox;
	class ThingX;
	class ReammoBox_F;
	class NATO_Box_Base;
	class Box_NATO_Wps_F;
	class ck_thompson_ammobox_s: Box_NATO_Wps_F
	{
		displayName = "Caisse de munition Thompson";
		author = "Noks";
		transportMaxWeapons = 5000;
		transportMaxMagazines = 20000;
		maximumLoad = 10000;
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
		};
		class TransportMagazines
		{
			class xxck_thompson_magazine
			{
				magazine = "ck_thompson_magazine";
				count = 25;
			};
			class xxck_thompson_m1928_magazine
			{
				magazine = "ck_thompson_m1928_50_mag";
				count = 25;
			};
		};
	};
	
	class ck_smle_ammobox_s: Box_NATO_Wps_F
	{
		displayName = "Caisse de munition SM Lee Enfield";
		author = "Noks";
		transportMaxWeapons = 5000;
		transportMaxMagazines = 20000;
		maximumLoad = 10000;
		class TransportWeapons
		{
			class xxck_smle_w
			{
				weapon = "ck_smle_w";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class xxck_smle_magazine
			{
				magazine = "ck_smle_magazine";
				count = 25;
			};
		};
	};
	
	class ck_sten_ammobox_s: Box_NATO_Wps_F
	{
		displayName = "Caisse de munition Sten";
		author = "Noks";
		transportMaxWeapons = 5000;
		transportMaxMagazines = 20000;
		maximumLoad = 10000;
		class TransportWeapons
		{
			class xxck_sten_w
			{
				weapon = "ck_sten_w";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class xxck_sten_magazine
			{
				magazine = "ck_sten_magazine";
				count = 25;
			};
		};
	};
	
	class ck_bren_ammobox_s: Box_NATO_Wps_F
	{
		displayName = "Caisse de munition Bren";
		author = "Noks";
		transportMaxWeapons = 5000;
		transportMaxMagazines = 20000;
		maximumLoad = 10000;
		class TransportWeapons
		{
			class xxck_bren_w
			{
				weapon = "ck_bren_w";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class xxck_bren_magazine
			{
				magazine = "ck_bren_magazine";
				count = 25;
			};
		};
	};
	
	class ck_m1911_ammobox_s: Box_NATO_Wps_F
	{
		displayName = "Caisse de munition M1911";
		author = "Noks";
		transportMaxWeapons = 5000;
		transportMaxMagazines = 20000;
		maximumLoad = 10000;
		class TransportWeapons
		{
			class xxck_m1911_w
			{
				weapon = "ck_m1911_w";
				count = 5;
			};
		};
		class TransportMagazines
		{
			class xxck_m1911_magazine
			{
				magazine = "ck_m1911_magazine";
				count = 25;
			};
		};
	};
};