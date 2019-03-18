#define _ARMA_

class CfgPatches
{
	class ck_brodie_p
	{
		author = "Noks";
		version = "0.2.1";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Characters_F"};
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
	class ck_brodie_base_w: ItemCore
	{
		scope = 1;
		displayName = "Brodie Mk.II";
		picture = "";
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			uniformModel = "";
			allowedSlots[] = {701,801,901,605};
			modelSides[] = {6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName = "HitHead";
					armor = 0.25;
					passThrough	= 0.5;
				};
			};
		};
		allowedFacewear[] = {};
	};
	class ck_brodie_pristine_w: ck_brodie_base_w
	{
		scope = 2;
		displayName = "Brodie Mk.II neuf";
		picture = "ck\ck_equipments\ck_brodie\data\pristine\ui\ck_brodie_ico_ca.paa";
		model = "ck\ck_equipments\ck_brodie\ck_brodie_pristine.p3d";
		class ItemInfo: ItemInfo
		{
			uniformModel = "ck\ck_equipments\ck_brodie\ck_brodie_pristine.p3d";
		};
	};
	class ck_brodie_rusty_w: ck_brodie_base_w
	{
		scope = 2;
		displayName = "Brodie Mk.II usagé";
		picture = "ck\ck_equipments\ck_brodie\data\rusty\ui\ck_brodie_ico_ca.paa";
		model = "ck\ck_equipments\ck_brodie\ck_brodie_rusty.p3d";
		class ItemInfo: ItemInfo
		{
			uniformModel = "ck\ck_equipments\ck_brodie\ck_brodie_rusty.p3d";
		};
	};
};