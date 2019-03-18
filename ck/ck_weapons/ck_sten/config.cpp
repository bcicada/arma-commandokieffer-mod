#define _ARMA_

class CfgPatches
{
	class ck_sten_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		version = "0.01.1";
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
	class ck_sten_recoil: ck_recoil_default
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
	class ck_sten_bullet: BulletBase
	{
		hit = 9;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		caliber = 1.8;
		deflecting = 45;
		model = "ck\ck_weapons\ck_sten\ck_sten_bullet.p3d";
		visibleFire = 4;
		audibleFire = 8;
		cost = 100;
		typicalSpeed = 380;
		airFriction = -0.0018;
	};
};

class CfgMagazines
{
	class Default;
	class CA_Magazine;
	class ck_sten_magazine: CA_Magazine
	{
		scope = 2;
		author = "Noks";
		displayName = "Chargeur de Sten";
		picture = "ck\ck_weapons\ck_sten\data\ui\ck_sten_magazine_ico_ca.paa";
		model = "ck\ck_weapons\ck_sten\ck_sten_magazine.p3d";
		ammo = "ck_sten_bullet";
		count = 32;
		initSpeed = 380;
		type = 16;
		descriptionShort = "32Rnd. Sten Magazine.  Calibre: 9x19mm parabellum.  Used in Sten SMGs";
	};
	class ck_sten_magazine_tracers_4: ck_sten_magazine
	{
		displayName = "Chargeur Sten 8 trançantes";
		tracersEvery = 4;
		lastRoundsTracer = 4;
	};
	class ck_sten_magazine_tracers: ck_sten_magazine
	{
		displayName = "Chargeur Sten trançantes";
		tracersEvery = 1;
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class ItemInfo;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class cfgWeapons
{
	class Default;
	class ItemCore;
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class ck_sten_w: Rifle_Base_F
	{
		author = "Noks";
		scope = 2;
		model = "ck\ck_weapons\ck_sten\ck_sten.p3d";
		picture = "ck\ck_weapons\ck_sten\data\ui\ck_sten_ico_ca.paa";
		displayName = "Sten Mk. II";
		descriptionShort = "Pistolet mitrailleur Sten Mark II";
		handAnim[] = {"OFP2_ManSkeleton","ck\ck_weapons\ck_sten\anims\ck_sten.rtm"};
		reloadAction = "ck_sten_reload_g";
		//reloadMagazineSound[] = {"\uns_weap_s\thompson\thompson_reload",1,1,25};
		class GunParticles: GunParticles {};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 75;
			class MuzzleSlot{};
			class CowsSlot{};
			class PointerSlot{};
		};
		drySound[] = {"A3\sounds_f\weapons\other\dry1",0.7,1,20};
		reloadMagazineSound[] = {"ck\ck_weapons\ck_sten\sounds\ck_sten_reload.wss",1,1,30};
		magazines[] = {"ck_sten_magazine","ck_sten_magazine_tracers_5","ck_sten_magazine_tracers"};
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = -1;
		recoil = "ck_sten_recoil";
		selectionFireAnim = "muzzleFlash";
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		cameraDir = "eye_look";
		discreteDistance[] = {50,100,150};
		discreteDistanceCameraPoint[] = {"eye_50","eye_100","eye_150"};
		discreteDistanceInitIndex = 0;
		modes[] = {"Single","Full"};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultHandgun";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_4",1.0351422,1,30};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_5",1.0351422,1.1,30};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"ck\ck_weapons\ck_sten\sounds\ck_sten.wss",1,1,700};
				soundBegin[] = {"begin1",1};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_interior",1.4125376,1,1400};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_trees",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_forest",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_meadows",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_houses",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType {};
			recoil = "recoil_auto_smg_01";
			recoilProne = "recoil_auto_prone_smg_01";
			reloadTime = 0.10909091;
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
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultHandgun";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_4",1.0351422,1,30};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_5",1.0351422,1.1,30};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"ck\ck_weapons\ck_sten\sounds\ck_sten.wss",1,1,700};
				soundBegin[] = {"begin1",1};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_interior",1.4125376,1,1400};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_trees",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_forest",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_meadows",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_tail_houses",1,1,1400};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType {};
			recoil = "recoil_auto_smg_01";
			recoilProne = "recoil_auto_prone_smg_01";
			reloadTime = 0.10909091;
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
			libTextDesc = "Sten Mk. II utilisée notamment par les commandos britaniques dont le commando Kieffer";
		};
	};
};

class CfgGesturesMale
{
	class Default;
	class States
	{
		class ck_sten_reload_g: Default
		{
			file = "ck\ck_weapons\ck_sten\anims\ck_sten_reload.rtm";
			looped = 0;
			speed = 0.2112676;
			mask = "handsWeapon";
			headBobStrength = 0.2;
			headBobMode = 2;
			leftHandIKCurve[] = {0,1,0.197183,1,0.204225,0,0.7957746,0,0.8450704,1};
			rightHandIKCurve[] = {0,1,0.04929,0,0.16197,0,0.19718309,1};
		};
	};
};

class CfgMovesBasic
{
	class Default;
	class DefaultDie;
	class ManActions
	{
		ck_sten_reload_g[] = {"ck_sten_reload_g","Gesture"};
	};
	class Actions
	{
		class NoActions: ManActions
		{
			ck_sten_reload_g[] = {"ck_sten_reload_g","Gesture"};
		};
	};
};