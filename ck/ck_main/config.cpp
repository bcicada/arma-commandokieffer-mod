#define _ARMA_

#define EAST 0
#define WEST 1
#define INDEP 2
#define CIV 3
#define EMPTY 4

#define true 1
#define false 0

#define times_2(a) a,a
#define times_3(a) a,a,a
#define times_5(a) a,a,a,a,a
#define times_8(a) a,a,a,a,a,a,a,a
#define times_10(a) a,a,a,a,a,a,a,a,a,a

#define QUOTE(VAR) #VAR

class CfgPatches
{
	class ck_main_p
	{
		author = "Noks";
		name = "Commando Kieffer - Anatole";
		url = "https://commandokieffer.com";
		authorUrl = "https://commandokieffer.com";
		version = "0.48.17";
		requiredVersion = 1.8;
		requiredAddons[] = {};
	};
};

class CfgMods
{
	class CommandoKieffer
	{
		dir = "ck";
		artwork = "";
		picture = "ck\ck_main\data\ck_logo_ca.paa";
		logo = "ck\ck_main\data\ck_logo_ca.paa";
		logoSmall = "ck\ck_main\data\ck_logo_ca.paa";
		logoOver = "ck\ck_main\data\ck_logo_hover_ca.paa";
		logoTitle = "ck\ck_main\data\ck_logo_ca.paa"; // page de l'addon
		tooltipOwned = "Commando Kieffer";
		name = "Commando Kieffer";
		nameShort = "CK";
		description = "Mod du 1er Bataillon de fusilliers marins commando, qui fut nommé à posteriori commando Kieffer.";
		actionName = "Site";
		action = "https://commandokieffer.com";
		hideName = false;
		hidePicture = false;
		dlcColor[] = {0.00, 0.00, 0.00, 0.89};
		overview = "Mod du 1er Bataillon de fusilliers marins commando, qui fut nommé à posteriori commando Kieffer.";
		fieldManualTopicAndHint[] = {};
		// video - 1024x1024
	};
};

class CfgAddons
{
	class PreloadAddons
	{
		class ck
		{
			list[] =
			{
				"ck_jeepwillys_p"
				, "ck_weapons_p"
			};
		};
	};
};

class CfgFactionClasses
{
    class ck_faction_1bfmc
    {
        displayName = "1er BFMC";
        priority = 1;
        side = INDEP;
    };
};

class CfgEditorCategories
{
    class ck_edtCat_statics
    {
        displayName = "Objets";
    };
};

class CfgVehicleClasses
{
    class ck_vehCls_vehicles
    {
        displayName = "Véhicules 4 roues";
    };
    class ck_vehCls_statics_buildings
    {
        displayName = "Batiments";
    };
    class ck_vehCls_statics_furnitures
    {
        displayName = "Meubles";
    };
    class ck_vehCls_statics_militarysupplies
    {
        displayName = "Fournitures militaires";
    };
    class ck_vehCls_statics_misc
    {
        displayName = "Divers";
    };
};

class CfgEditorSubcategories
{
    class ck_edtSubCat_base
    {
        displayName = "CK Cat Base";
        side = INDEP;
    };
    class ck_edtSubCat_emptybase
    {
        displayName = "CK Cat Empty Base";
        side = EMPTY;
    };
    class ck_edtSubCat_vehicles: ck_edtSubCat_base
    {
        displayName = "Véhicules 4 roues";
    };
    class ck_edtSubCat_statics_buildings: ck_edtSubCat_emptybase
    {
        displayName = "Batiments";
    };
    class ck_edtSubCat_statics_furnitures: ck_edtSubCat_emptybase
    {
        displayName = "Meubles";
    };
    class ck_edtSubCat_statics_militarysupplies: ck_edtSubCat_emptybase
    {
        displayName = "Fournitures militaires";
    };
    class ck_edtSubCat_statics_misc: ck_edtSubCat_emptybase
    {
        displayName = "Divers";
    };
};


class CfgFunctions
{
	class ck
	{
		tag = "ck";
		class ck_functions
		{
			file = "ck\ck_main\functions";
			class fired{};
		};
	};
};


class CfgWorlds 
{
	class GenericNames 
	{
		class ck_names 
		{
			class FirstNames 
			{
				edouard = "Philippe";
			};

			class LastNames 
			{
				michelin = "Kieffer";
			};
		};
	};
};