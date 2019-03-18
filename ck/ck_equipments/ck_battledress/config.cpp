#define _ARMA_

class CfgPatches
{
	class ck_battledress_p
	{
		author = "Noks";
		version = "0.1.1";
		requiredVersion = 1.8;
		requiredAddons[] = {"A3_data_f"};
		units[] = {"ck_soldier_base_v"};
	};
};

class UniformSlotInfo;

class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class HitPoints
		{
			class HitHead;
			class HitBody;
			class HitHands;
			class HitLegs;
		};
	};

	class SoldierWB: CAManBase
	{
		threat[] = {1, 0.1, 0.1};
	};

	//Base class for BLUFOR soldiers
	class ck_soldier_base_v: SoldierWB
	{
		faceType = "Man_A3"; /// this soldier is going to use standard faces
		side = 2; /// that means BLUFOR
		faction = "ck_faction_1bfmc"; /// Standard NATO faction
		genericNames = "ck_names"; /// Standard names for lads of NATO (and European civils)
		vehicleClass = "Men"; /// Should be listed under Men

		scope = 1; /// base class should not be visible in editor
		class Wounds /// changes material of skin according to damage
		{
			tex[] = {};
			mat[] = {
				"A3\Characters_F\Common\Data\basicbody.rvmat", 			/// what material is changed
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",	/// how does the material look like in damage 0.5 and more
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",	/// how does the material look like while the part has damage 1

				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",			/// next materials are used through personality of the soldier
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};

		model 			= "ck\ck_equipments\ck_battledress\ck_battledress.p3d";
		modelSides[] 	= {2}; 				/// what sides could use this uniform, means civilians and BLUFOR can use it
		nakedUniform 	= "U_BasicBody";		/// what "uniform" does this soldier use without any other uniform
		uniformClass 	= "ck_webbingp37_w";	/// standard uniform used by this soldier, there is a special one defined later
		camouflage		= 0.8; 					/// how easy is to spot soldier -> bigger means better spotable, used by uniform

		class UniformInfo /// defines allowed slots of the uniform
		{
			class SlotsInfo
			{
				class NVG: UniformSlotInfo {slotType = 602; };
				class Googles: UniformSlotInfo {slotType = 603;};
				class Headgear: UniformSlotInfo {slotType = 605;};
			};
		};

		class HitPoints
		{
			class HitFace
			{
				armor               = 1; // coefficient of the total armor defined below for the whole object
				material            = -1; // damage material (-1 means "unused")
				name                = "face_hub"; // selection name from hit points LOD in object
				passThrough         = 0.1; // coefficient defining how much damage will pass into total damage when this hit point is damaged
				radius              = 0.08; // size of the hit point sphere, this is how it works: https://community.bistudio.com/wiki/Arma_3_Damage_Description
				explosionShielding  = 0.1; // multiplier of explosive damage (parameter: explosive > 0 in ammunition type)
				minimalHit          = 0.01; // minimal damage value that can be applied, damage below this threshold is ignored
			};
			class HitNeck: HitFace
			{
				armor				= 1;
				material			= -1;
				name				= "neck";
				passThrough			= 0.1;
				radius				= 0.1;
				explosionShielding	= 0.5;
				minimalHit			= 0.01;
			};
			class HitHead: HitNeck
			{
				armor				= 1;
				material			= -1;
				name				= "head";
				passThrough			= 0.1;
				radius				= 0.2;
				explosionShielding	= 0.5;
				minimalHit			= 0.01;
				depends				= "HitFace max HitNeck"; // returns the greater of HitFace and HitNeck
			};
			class HitPelvis
			{
				armor				= 1;
				material			= -1;
				name				= "pelvis";
				passThrough			= 0.1;
				radius				= 0.2;
				explosionShielding	= 1;
				visual				= "injury_body";
				minimalHit			= 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor				= 1;
				material			= -1;
				name				= "spine1";
				passThrough			= 0.1;
				radius				= 0.15;
				explosionShielding	= 1;
				visual				= "injury_body";
				minimalHit			= 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor				= 1;
				material			= -1;
				name				= "spine2";
				passThrough			= 0.1;
				radius				= 0.15;
				explosionShielding  = 6;
				visual				= "injury_body";
				minimalHit			= 0.01;
			};
			class HitChest: HitDiaphragm
			{
				armor				= 1;
				material			= -1;
				name				= "spine3";
				passThrough			= 0.1;
				radius				= 0.15;
				explosionShielding	= 6;
				visual				= "injury_body";
				minimalHit			= 0.01;
			};
			class HitBody: HitChest
			{
				armor				= 1000;
				material			= -1;
				name				= "body";
				passThrough			= 0.1;
				radius				= 0.16;
				explosionShielding	= 6;
				visual				= "injury_body";
				minimalHit			= 0.01;
				depends				= "HitPelvis max HitAbdomen max HitDiaphragm max HitChest"; // depends work only for hit points defined in inheritance chain
			};
			class HitArms
			{
				armor				= 1;
				material			= -1;
				name				= "arms";
				passThrough			= 1;
				radius				= 0.1;
				explosionShielding	= 1;
				visual				= "injury_hands";
				minimalHit			= 0.01;
			};
			class HitHands: HitArms
			{
				armor				= 1;
				material			= -1;
				name				= "hands";
				passThrough			= 1;
				radius				= 0.1;
				explosionShielding  = 1;
				visual				= "injury_hands";
				minimalHit			= 0.01;
				depends				= "HitArms";
			};
			class HitLegs
			{
				armor				= 1;
				material			= -1;
				name				= "legs";
				passThrough			= 1;
				radius				= 0.12;
				explosionShielding  = 1;
				visual				= "injury_legs";
				minimalHit			= 0.01;
			};
		};

		armor					= 2; // keep constant among various soldiers so that the hit points armor coefficients remains on the same scale
		armorStructural			= 0.4; // divide all damage taken to total hit point, either directly or through hit point passThrough coefficient, must be adjusted for each model to achieve consistent total damage results
		explosionShielding		= 0.04; // for consistent explosive damage after adjusting = ( armorStructural / 10 )
		minTotalDamageThreshold	= 0.001; // minimalHit for total damage
		impactDamageMultiplier	= 0.5; // multiplier for falling damage

		hiddenSelections[] = {"camo","unit","insiginia"}; /// selection defined in sections of model that may have texture and materials changed by setObjectTexture or next parameter
		hiddenSelectionsTextures[] =
		{
			"ck\ck_equipments\ck_battledress\data\ck_battledress_co.paa",
			"ck\ck_equipments\ck_battledress\data\ck_battledress_frenchpatch_ca.paa"
		}; /// what texture does this soldier use for camo selection
		hideProxySelections[] = {"ghillie_hide"}; /// names of selections hidden on proxies (used in vest in this case, see overlaySelectionsInfo[])

		weapons[] = {"Throw", "Put"}; /// we have a sample weapon, why not use it? Throw and put weapons are required for grenades/mines
		respawnWeapons[] = {"Throw", "Put"}; /// should be the same as previous most of the time
		Items[] = {}; /// one First aid kit is good to start with
		RespawnItems[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {"ItemMap", "ItemCompass", "ItemWatch"}; /// items directly in inventory slots
		respawnLinkedItems[] = {};
		
		
		headgearList[] =
		{
			/* [headgearClass1, probability1, headgearClass2, probability2, ...] */
			"", 0.1, // Empty array means no headgear nor face wear
			"H_Test_Headgear_2", // Our test headgear, defined in CfgHeadegar.hpp
			"H_FakeHeadgear", 0.9, // In this case, there is no headgear but there is a face wear
			"H_HelmetB_light", 0.6,
			"H_Booniehat_khk_hs", 0.4,
			"H_HelmetIA_net", 0.4,
			"H_HelmetIA_camo", 0.4,
			"H_HelmetB_grass", 0.4
		};
		class EventHandlers
		{
			// Documentation: https://community.bistudio.com/wiki/BIS_fnc_unitHeadgear
			// Args: Units, [] (headgear pool), [] (face wear pool)
			init = "if (local (_this select 0)) then {[(_this select 0), [], []] call BIS_fnc_unitHeadgear;};";
		};
	};

	class ck_soldier_unarmed_v: ck_soldier_base_v /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "Commando desarmé"; /// what's displayed in editor or on cursor over
	};
	/*
	class ck_themonstruosity_v: ck_soldier_base_v /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "The abomination"; /// what's displayed in editor or on cursor over
		model 			= "ck\ck_equipments\ck_battledress\ck_battledress_2.p3d";
	};
	*/
};


class cfgWeapons
{
	class InventoryItem_Base_F;
	class UniformItem;
	class ItemCore;
	class ck_webbingp37_w: Itemcore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		allowedSlots[] = {901}; /// where does the uniform fit to when not equipped
		displayName = "Uniforme P37 en toile"; /// how would the stuff be displayed in inventory and on ground
		picture = "\A3\characters_f\data\ui\icon_U_BasicBody_CA.paa"; /// this icon fits the uniform surprisingly well
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver"; /// how does the uniform look when put on ground

		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = "ck_soldier_base_v"; /// what soldier class contains parameters of the uniform (such as model, camouflage, hitpoints and others)
			containerClass = "Supply60"; /// what fake vehicle is used to describe size of uniform container, there is quite a lot SupplyXX classes ready
			mass = 80; /// combined weight and volume
		};
	};
};