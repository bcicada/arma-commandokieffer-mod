#define _ARMA_

class CfgPatches
{
	class swh_france_p
	{
		author = "$str_swh_authorname";
		version = "0.2.1";
		requiredVersion = 1.0;
		requiredAddons[] = {"shw_helmets_p"};
	};
};

class cfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	class HeadgearItem: InventoryItem_Base_F
	{
		allowedSlots[] = {901,605};
		type = 605;
		hiddenSelections[] = {};
		hitpointName = "HitHead";
	};

	class swh_france_pristine_e: ItemCore
	{
		scope = 2;
		displayName = "$str_swh_francepristinename";
		picture = "ck\ck_equipments\ck_beret\data\ui\ck_beret_ca.paa";
		model = "ck\ck_equipments\ck_beret\ck_beret.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"ck\ck_equipments\ck_beret\data\ck_beret_co.paa"};
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			uniformModel = "ck\ck_equipments\ck_beret\ck_beret.p3d";
			allowedSlots[] = {701,801,901,605};
			modelSides[] = {6};
			hiddenSelections[] = {"camo"};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 0;
					passThrough	= 0.5;
				};
			};
		};
		allowedFacewear[] = {};
	};
	class swh_france_rusty_e: swh_france_pristine_e
	{
		displayName = "$str_swh_francerustyname";
		picture = "ck\ck_equipments\ck_beret\data\ui\ck_beret_ca.paa";
		model = "ck\ck_equipments\ck_beret\ck_beret.p3d";
		
	};
};