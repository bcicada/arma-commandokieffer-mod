#define _ARMA_

class CfgPatches
{
	class ck_beret_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {};
	};
};

class cfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	class HeadgearItem: InventoryItem_Base_F
	{
		allowedSlots[] = {901,605};
		// vest -> 701 - uniform -> 801 - backpack -> 901
		type = 605;
		hiddenSelections[] = {};
		hitpointName = "HitHead";
	};

	class ck_beret_e: ItemCore
	{
		scope = 2;
		displayName = "Béret vert";
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
		allowedFacewear[] =
		{
			"ck_glasses_e",1
		};
	};
};