#define _ARMA_

#define true 1
#define false 0

class cfgPatches
{
	class ck_compat_ace_weapons_p
	{
		author = "Noks";
		requiredVersion = 1.8;
		version = "anatole 0.88";
		requiredAddons[] = {"ck_weapons_p","ace_main"};
	};
};

class cfgWeapons
{
	class Default;
	class ItemCore;
	class InventoryItem_Base_F;
	class InventoryOpticsItem_Base_F;
	
	class ck_smle_scope_w: ItemCore
	{
		ace_scopeZeroRange = 100;
		ace_scopeHeightAboveRail = 3.8;
		ace_scopeAdjust_vertical[] = {-4, 30};
		ace_scopeAdjust_horizontal[] = {-6, 6};
		ace_scopeAdjust_verticalIncrement = 0.1;
		ace_scopeAdjust_horizontalIncrement = 0.1;

		class ItemInfo: InventoryOpticsItem_Base_F
		{
			class OpticsModes
			{
				class ck_smle_scope
				{
                    discreteDistance[] = {100};
				};
			};
		};
	};
	
	class ck_smle_w
	{
		/*
        ace_overheating_mrbs = 2500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 0;
        ace_overheating_dispersion = 0.25;
		*/
        ace_railHeightAboveBore = 1.8;
        ace_railBaseAngle = 0.025;
        ace_ironSightBaseAngle = -0.138;
	};
	/*
	class ck_bren_w
	{
        ace_overheating_mrbs = 2500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 0;
        ace_overheating_dispersion = 0.65;
	};
	class ck_sten_w
	{
        ace_overheating_mrbs = 2500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 0;
        ace_overheating_dispersion = 0.65;
	};
	class ck_thompson_w
	{
        ace_overheating_mrbs = 2500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 0;
        ace_overheating_dispersion = 0.65;
	};
	class ck_m2_w
	{
        ace_overheating_mrbs = 2500;
        ace_overheating_slowdownFactor = 1;
        ace_overheating_allowSwapBarrel = 1;
        ace_overheating_dispersion = 0.7;
	};
	*/
};
