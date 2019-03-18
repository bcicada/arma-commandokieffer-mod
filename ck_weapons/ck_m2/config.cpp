#define _ARMA_

class CfgPatches
{
	class ck_m2_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		version = "0.75.12";
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
	class ck_m2_recoil: ck_recoil_default
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
	class ck_m2_bullet: BulletBase
	{
		hit = 15;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		caliber = 4;
		deflecting = 45;
		//model = "ck\ck_weapons\ck_m2\ck_m2_bullet.p3d";
		visibleFire = 12;
		audibleFire = 25;
		cost = 100;
		typicalSpeed = 930;
		airFriction = -0.0018;
	};
};

class CfgMagazines
{
	class Default;
	class CA_Magazine;
	class ck_m2_magazine: CA_Magazine
	{
		scope = 2;
		author = "Noks";
		displayName = "Chargeur de M2";
		picture = "ck\ck_weapons\ck_m2\data\ui\ck_m2_magazine_ico_ca.paa";
		//model = "ck\ck_weapons\ck_m2\ck_m2_magazine.p3d";
		ammo = "ck_m2_bullet";
		count = 100;
		initSpeed = 940;
		type = 16;
	};
	class ck_m2_magazine_tracers_5: ck_m2_magazine
	{
		displayName = "Chargeur M2 20 trançantes";
		tracersEvery = 5;
	};
	class ck_m2_magazine_tracers: ck_m2_magazine
	{
		displayName = "Chargeur M2 trançantes";
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
	class Rifle_Base_F: Rifle{};
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
		class GunParticles;
		class EventHandlers;
	};
	class ck_m2_w: Rifle_Long_Base_F
	{
		author = "Noks";
		scope = 2;
		model = "ck\ck_weapons\ck_m2\ck_m2.p3d";
		picture = "ck\ck_weapons\ck_m2\data\ui\ck_m2_ico_ca.paa";
		displayName = "Browning M2";
		descriptionShort = "Fusil mitrailleur lourd Browning M2";
		handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F\Rifles\MX\data\Anim\MX_gl.rtm"};
		drySound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_dry",0.501187,1,20};
		reloadMagazineSound[] = {"ck\ck_weapons\ck_m2\sounds\ck_m2_reload.wss",1,1,30};
		magazines[] = {"ck_m2_magazine","ck_m2_magazine_tracers_5","ck_m2_magazine_tracers"};
		cursor = "arifle";
		cursorSize = 1.5;
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = -1;
		recoil = "ck_m2_recoil";
		selectionFireAnim = "muzzleFlash";
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		cameraDir = "eye_look";
		discreteDistance[] = {200,400,600,800,1000,1200};
		discreteDistanceCameraPoint[] = {"eye_200","eye_400","eye_600","eye_800","eye_1000","eye_1200"};
		discreteDistanceInitIndex = 0;
		class GunParticles: GunParticles {};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 75;
			class MuzzleSlot{};
			class CowsSlot{};
			class PointerSlot{};
		};
		modes[] = {"Single","Full"};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"ck\ck_weapons\ck_m2\sounds\ck_m2.wss",1,1,700};
				soundBegin[] = {"begin1",1};
			};
			recoil = "recoil_single_dmr";
			recoilProne = "recoil_single_prone_dmr";
			reloadTime = 0.12;
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
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"ck\ck_weapons\ck_m2\sounds\ck_m2.wss",1,1,700};
				soundBegin[] = {"begin1",1};
			};
			recoil = "recoil_single_dmr";
			recoilProne = "recoil_single_prone_dmr";
			reloadTime = 0.12;
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
			libTextDesc = "M2 utilisée notamment par les commandos britaniques dont le commando Kieffer";
		};
	};
};