#define _ARMA_

#define true 1
#define false 0

class CfgPatches
{
	class ck_smle_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		version = "0.89.37";
	};
};

class cfgRecoils
{
	class Default;

	//	muzzleOuter[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	muzzleInner[]	= x,y,a,b = { horizontal axis, vertical axis, horizontal magnitude, vertical magnitude }; plot: ((p+x)/a)^2 + ((q+y)/b)^2 = 1;
	//	kickBack[]		= min&max = { minimum, maximum };

	class ck_recoil_default: Default
	{
		muzzleOuter[]	= { 0.3,	1.0,	0.3,	0.2 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 0.03,	0.06 };
		permanent		= 0.1;
		temporary		= 0.01;
	};
	class ck_smle_recoil: ck_recoil_default
	{
		muzzleOuter[]	= { 0.3,	1.0,	0.4,	0.3 };
		kickBack[]		= { 0.02,	0.04 };
		temporary		= 0.01;
	};
};

class CfgAmmo
{
	class Default;
	class BulletCore;
	class BulletBase;
	class ck_smle_bullet: BulletBase
	{
		hit = 12;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		caliber = 2.6;
		deflecting = 45;
		model = "ck\ck_weapons\ck_smle\ck_smle_bullet.p3d";
		visibleFire = 10;
		audibleFire = 15;
		cost = 100;
		typicalSpeed = 745;
		airFriction = -0.00071225;
	};
};

class CfgMagazines
{
	class Default;
	class CA_Magazine;
	class ck_smle_magazine: CA_Magazine
	{
		scope = 2;
		author = "Noks";
		displayName = "Chargeur de Lee Enfield 10cps";
		picture = "ck\ck_weapons\ck_smle\data\ui\ck_smle_magazine_ico_ca.paa";
		model = "ck\ck_weapons\ck_smle\ck_smle_magazine.p3d";
		ammo = "ck_smle_bullet";
		count = 10;
		initSpeed = 745;
		type = 16;
		lastRoundsTracer = 1;
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class ItemInfo;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class GunParticles;
class cfgWeapons
{
	class Default;
	class ItemCore;
	class InventoryItem_Base_F;
	class InventoryOpticsItem_Base_F;
 	class InventoryFlashLightItem_Base_F;
	
 	class ck_smle_sling_leather_w
 	{
 		scope = 2;
 		displayName = "Bandoulière en cuir";
 		picture="ck\ck_weapons\ca\sling_leather\ui\sling_ico_ca.paa";
 		model = "ck\ck_weapons\ck_smle\ck_smle_sling_leather.p3d";
 		class ItemInfo: InventoryFlashLightItem_Base_F
 		{
 			mass = 5;
 			class Pointer {};
 			class FlashLight {};
 		};
 	};
	class ck_smle_sling_nylon_w: ck_smle_sling_leather_w
	{
 		displayName = "[A venir] Bandoulière en nylon";
 		picture="ck\ck_weapons\ca\sling_leather\ui\sling_ico_ca.paa"; // sling_nylon
 		model = "ck\ck_weapons\ck_smle\ck_smle_sling_leather.p3d"; // sling_nylon
	};
	
	class ck_smle_scope_w: ItemCore
	{
		scope = 2;
		displayName = "Enfield No.32 Mk.II";
		author = "Noks";
		dlc = "CommandoKieffer";
		picture = "ck\ck_weapons\ck_smle\data\ui\ck_smle_scope_ico_ca.paa";
		model = "ck\ck_weapons\ck_smle\ck_smle_scope.p3d";
		descriptionShort = "Enfield No. 32 Mark II scope for SMLE";
		weaponInfoType = "RscWeaponZeroing";

		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass = 5;
			opticType = 2;
			optics = true;
			modelOptics = "ck\ck_weapons\ck_smle\ck_smle_scope_optic.p3d";
			memoryPointCamera = "eye_scope";
			weaponInfoType = "RscWeaponRangeZeroingFOV";
			class OpticsModes
			{
				class ck_smle_scope
				{
                    discreteDistance[] = {100,200,300,400,500,600,700,800};
                    discreteDistanceInitIndex = 0;
					discretefov[] = {0.04};
					discreteInitIndex = 0;
					opticsID = 1;
					useModelOptics = true;
					opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
					opticsFlare = true;
					opticsDisablePeripherialVision = false;
					opticsZoomInit = 0.04;
					opticsZoomMax = 0.04;
					opticsZoomMin = 0.04;
					distanceZoomMax = 600;
					distanceZoomMin = 600;
					memoryPointCamera = "eye_scope";
					cameraDir = "";
					visionMode[] = {"Normal"};
				};
			};
		};
		inertia = 0.1;
	};
	
	class Rifle;
	class Rifle_Base_F: Rifle{};
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
		class EventHandlers;
	};
	class ck_smle_w: Rifle_Long_Base_F
	{
		scope = 2;
		author = "Noks";
		dlc = "CommandoKieffer";
		model = "ck\ck_weapons\ck_smle\ck_smle.p3d";
		picture = "ck\ck_weapons\ck_smle\data\ui\ck_smle_ico_ca.paa";
		displayName = "SM Lee-Enfield No.4 Mk.I";
		descriptionShort = "Short Magazine Lee-Enfield No. 4 Mark I";
		handanim[] = {"OFP2_ManSkeleton","ck\ck_weapons\ck_smle\anims\ck_smle.rtm"};
		reloadAction = "ck_smle_reload_g";
		cursor = "srifle";
		zeroingSound[] = {"A3\Sounds_F\arsenal\sfx\shared\zeroing_knob_tick_metal",0.316228,1,5};
		drySound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_dry",0.501187,1,20};
		reloadMagazineSound[] = {"ck\ck_weapons\ck_smle\sounds\ck_smle_reload",1,1,15};
		magazines[] = {"ck_smle_magazine"};
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = -1;
		recoil = "ck_smle_recoil";
		selectionFireAnim = "muzzleFlash";
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		cameraDir = "eye_look";
		discreteDistance[] = {100, 200, 300, 400, 500,600};
		discreteDistanceCameraPoint[] = {"eye_100","eye_200","eye_300","eye_400","eye_500","eye_600"};
		discreteDistanceInitIndex = 0;
		modes[] = {"Single"};
		class EventHandlers: EventHandlers
		{
			fired = "[(_this select 0), 'ck_smle_reloadammo_g', 'ck_smle_reloadammo_s'] spawn ck_fnc_fired";
		};
		class GunParticles: GunParticles
		{
			class FirstEffect
			{
				effectName = "SniperCloud";
				positionName = "Usti hlavne";
				directionName = "Konec hlavne";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 110;
			class MuzzleSlot {};
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"ck_smle_scope_w"};
				linkproxy = "\A3\data_f\proxies\weapon_slots\TOP";
				iconPosition[] = {0.45,0.38};
				iconScale = 0.2;
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"ck_smle_sling_leather_w","ck_smle_sling_nylon_w"};
				linkproxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				iconPosition[] = {0.20, 0.45};
				iconScale = 0.25;
			};
		};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"DMR03_Shot_SoundSet","DMR03_tail_SoundSet","DMR03_InteriorTail_SoundSet"};
			};
			recoil = "recoil_single_dmr";
			recoilProne = "recoil_single_prone_dmr";
			reloadTime = 1.2;
			dispersion = 0.00035;
			minRange = 50;
			minRangeProbab = 0.3;
			midRange = 250;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 25;
		};
		bullet1[] = {"\A3\sounds_f\weapons\shells\7_62\metal_762_01",0.630957,1,15};
		bullet2[] = {"\A3\sounds_f\weapons\shells\7_62\metal_762_02",0.630957,1,15};
		bullet3[] = {"\A3\sounds_f\weapons\shells\7_62\metal_762_03",0.630957,1,15};
		bullet4[] = {"\A3\sounds_f\weapons\shells\7_62\metal_762_04",0.630957,1,15};
		bullet5[] = {"\A3\sounds_f\weapons\shells\7_62\dirt_762_01",0.630957,1,15};
		bullet6[] = {"\A3\sounds_f\weapons\shells\7_62\dirt_762_02",0.630957,1,15};
		bullet7[] = {"\A3\sounds_f\weapons\shells\7_62\dirt_762_03",0.630957,1,15};
		bullet8[] = {"\A3\sounds_f\weapons\shells\7_62\dirt_762_04",0.630957,1,15};
		bullet9[] = {"\A3\sounds_f\weapons\shells\7_62\grass_762_01",0.630957,1,15};
		bullet10[] = {"\A3\sounds_f\weapons\shells\7_62\grass_762_02",0.630957,1,15};
		bullet11[] = {"\A3\sounds_f\weapons\shells\7_62\grass_762_03",0.630957,1,15};
		bullet12[] = {"\A3\sounds_f\weapons\shells\7_62\grass_762_04",0.630957,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		class Library
		{
			libTextDesc = "SMLE utilisé notamment par les commandos britaniques dont le commando Kieffer";
		};
	};
};


class CfgGesturesMale
{
	class Default;
	class States
	{
		class ck_smle_reload_g: Default
		{
			file = "ck\ck_weapons\ck_smle\anims\ck_smle_reload.rtm";
			looped = 0;
			speed = -5;
			mask = "handsWeapon";
			headBobStrength = 0.2;
			headBobMode = 2;
			canPullTrigger = 0;
			rightHandIKCurve[] = {0,1,0.02,1,0.04,0,0.96,0,0.98,1,1,1};
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
			leftHandIKCurve[] = {1};
			preload = 1;
		};
		class ck_smle_reloadammo_g: ck_smle_reload_g
		{
			file = "ck\ck_weapons\ck_smle\anims\ck_smle_reloadammo.rtm";
			enableOptics = 1;
			speed = -1;
			rightHandIKCurve[] = {0,1,0.05,1,0.1,0,0.9,0,0.96,1,1,1};
		};
	};
};

class CfgMovesBasic
{
	class Default;
	class DefaultDie;
	class ManActions
	{
		ck_smle_reload_g[] = {"ck_smle_reload_g","Gesture"};
		ck_smle_reloadammo_g[] = {"ck_smle_reloadammo_g","Gesture"};
	};
	class Actions
	{
		class NoActions: ManActions
		{
			ck_smle_reload_g[] = {"ck_smle_reload_g","Gesture"};
			ck_smle_reloadammo_g[] = {"ck_smle_reloadammo_g","Gesture"};
		};
	};
};


class CfgSounds
{
	sounds[] = {};
	class ck_smle_reloadammo_s
	{
		name = "ck_smle_reloadammo";
		sound[] = {"ck\ck_weapons\ck_smle\sounds\ck_smle_reloadammo",1,1,10};
		titles[] = {};
	};
};