#define _ARMA_

class CfgPatches
{
	class ck_thompson_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		version = "0.94.36";
	};
};

class cfgRecoils
{
	class Default;

	class ck_recoil_default: Default
	{
		muzzleOuter[]	= { 0.3,	1.0,	0.3,	0.2 };
		muzzleInner[]	= { 0,		0,		0.1,	0.1	};
		kickBack[]		= { 0.03,	0.06 };
		permanent		= 0.1;
		temporary		= 0.01;
	};
	class ck_thompson_recoil: ck_recoil_default
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
	class ck_thompson_bullet: BulletBase
	{
		hit = 10;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		caliber = 2.6;
		deflecting = 45;
		model = "ck\ck_weapons\ck_thompson\ck_thompson_bullet.p3d";
		visibleFire = 5;
		audibleFire = 9;
		cost = 100;
		typicalSpeed = 280;
		airFriction = -0.0018;
	};
};

class CfgMagazines
{
	class Default;
	class CA_Magazine;
	class ck_thompson_magazine: CA_Magazine
	{
		scope = 2;
		author = "Noks";
		displayName = "30cps .45 cal";
		model = "ck\ck_weapons\ck_thompson\ck_thompson_magazine.p3d";
		picture = "ck\ck_weapons\ck_thompson\data\ui\ck_thompson_magazine_ico_ca.paa";
		ammo = "ck_thompson_bullet";
		count = 30;
		initSpeed = 280;
		type = 16;
	};
	class ck_thompson_m1928_50_mag: ck_thompson_magazine
	{
		scope = 2;
		author = "Noks";
		displayName = "Tambour 50cps .45cal";
		model = "ck\ck_weapons\ck_thompson\ck_thompson_m1928_magazine.p3d";
		picture = "ck\ck_weapons\ck_thompson\data\ui\ck_thompson_m1928_magazine_ico_ca.paa";
		count = 50;
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
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
	};
	class ck_thompson_w: Rifle_Base_F
	{
		author = "Noks";
		scope = 2;
		model = "ck\ck_weapons\ck_thompson\ck_thompson.p3d";
		picture = "ck\ck_weapons\ck_thompson\data\ui\ck_thompson_ico_ca.paa";
		displayName = "Thompson M1A1";
		descriptionShort = "Pistolet mitrailleur thompson";
		handAnim[] = {"OFP2_ManSkeleton","ck\ck_weapons\ck_thompson\anims\ck_thompson.rtm"};
		reloadAction = "ck_thompson_reload_g";
		reloadMagazineSound[] = {"ck\ck_weapons\ck_thompson\sounds\ck_thompson_reload.wss",1,1,30};
		class GunParticles: GunParticles {};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 60;
			class MuzzleSlot{};
			class CowsSlot{};
			class PointerSlot{};
		};
		drySound[] = {"A3\sounds_f\weapons\other\dry1",0.7,1,20};
		magazines[] = {"ck_thompson_magazine"};
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = -1;
		recoil = "ck_thompson_recoil";
		selectionFireAnim = "muzzleFlash";
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		cameraDir = "eye_look";
		discreteDistance[] = {50, 100, 150};
		discreteDistanceCameraPoint[] = {"eye_50","eye_100","eye_150"};
		discreteDistanceInitIndex = 0;
		modes[] = {"Single","Full"};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultHandgun";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_4",1.0351422,1,30};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_5",1.0351422,1.1,30};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"Zubr_Shot_SoundSet","Zubr_Tail_SoundSet","Zubr_InteriorTail_SoundSet"};
			};
			recoil = "recoil_single_primary_6outof10";
			recoilProne = "recoil_single_primary_prone_6outof10";
			reloadTime = 0.08571428;
			dispersion = 0.0085;
			minRange = 5;
			minRangeProbab = 0.3;
			midRange = 75;
			midRangeProbab = 0.6;
			maxRange = 150;
			maxRangeProbab = 0.1;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 25;
		};
		class Full: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultHandgun";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_4",1.0351422,1,30};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_5",1.0351422,1.1,30};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"Zubr_Shot_SoundSet","Zubr_Tail_SoundSet","Zubr_InteriorTail_SoundSet"};
			};
			recoil = "recoil_single_primary_6outof10";
			recoilProne = "recoil_single_primary_prone_6outof10";
			reloadTime = 0.08571428;
			dispersion = 0.0085;
			minRange = 5;
			minRangeProbab = 0.3;
			midRange = 75;
			midRangeProbab = 0.6;
			maxRange = 150;
			maxRangeProbab = 0.1;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 25;
		};
		bullet1[] = {"A3\Sounds_F\weapons\shells\9mm\metal_9mm_01",0.5011872,1,15};
		bullet2[] = {"A3\Sounds_F\weapons\shells\9mm\metal_9mm_02",0.5011872,1,15};
		bullet3[] = {"A3\Sounds_F\weapons\shells\9mm\metal_9mm_03",0.5011872,1,15};
		bullet4[] = {"A3\Sounds_F\weapons\shells\9mm\metal_9mm_04",0.5011872,1,15};
		bullet5[] = {"A3\Sounds_F\weapons\shells\9mm\dirt_9mm_01",0.39810717,1,15};
		bullet6[] = {"A3\Sounds_F\weapons\shells\9mm\dirt_9mm_02",0.39810717,1,15};
		bullet7[] = {"A3\Sounds_F\weapons\shells\9mm\dirt_9mm_03",0.39810717,1,15};
		bullet8[] = {"A3\Sounds_F\weapons\shells\9mm\dirt_9mm_04",0.39810717,1,15};
		bullet9[] = {"A3\Sounds_F\weapons\shells\9mm\grass_9mm_01",0.2238721,1,15};
		bullet10[] = {"A3\Sounds_F\weapons\shells\9mm\grass_9mm_02",0.2238721,1,15};
		bullet11[] = {"A3\Sounds_F\weapons\shells\9mm\grass_9mm_03",0.2238721,1,15};
		bullet12[] = {"A3\Sounds_F\weapons\shells\9mm\grass_9mm_04",0.2238721,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		class Library
		{
			libTextDesc = "Thompson utilisée notamment par les commandos britaniques dont le commando Kieffer";
		};
	};
	class ck_thompson_m1928_w: ck_thompson_w
	{
		author = "Noks";
		scope = 2;
		model = "ck\ck_weapons\ck_thompson\ck_thompson_m1928.p3d";
		picture = "ck\ck_weapons\ck_thompson\data\ui\ck_thompson_m1928_ico_ca.paa";
		displayName = "Thompson M1928A1";
		magazines[] = {"ck_thompson_m1928_50_mag"};
		discreteDistanceCameraPoint[] = {"eye_50"};
	};
};

class CfgGesturesMale
{
	class default;
	class States
	{
		class ck_thompson_reload_g: default
		{
			file = "ck\ck_weapons\ck_thompson\anims\ck_thompson_reload.rtm";
			speed = 0.18404908;
			looped = 0;
			mask = "handsWeapon";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKCurve[] = {1};
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
			leftHandIKCurve[] = {0,1,0.03125,0,0.831,0,0.887,1};
		};
	};
};

class CfgMovesBasic
{
	class Default;
	class DefaultDie;
	class ManActions
	{
		ck_thompson_reload_g[] = {"ck_thompson_reload_g","Gesture"};
	};
	class Actions
	{
		class NoActions: ManActions
		{
			ck_thompson_reload_g[] = {"ck_thompson_reload_g","Gesture"};
		};
	};
};