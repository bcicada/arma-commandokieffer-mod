#define _ARMA_

class CfgPatches
{
	class ck_m1911_p
	{
		author = "Noks";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		version = "0.77.32";
	};
};

class CfgAmmo
{
	class Default;
	class BulletCore;
	class BulletBase;
	class ck_m1911_bullet: BulletBase
	{
		hit = 10;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		caliber = 2.6;
		deflecting = 45;
		model = "ck\ck_weapons\ck_m1911\ck_m1911_bullet.p3d";
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
	class ck_m1911_magazine: CA_Magazine
	{
		scope = 2;
		displayName = "Chargeur 6 cps .45acp";
		picture = "ck\ck_weapons\ck_m1911\data\ui\ck_magazine_m1911_ca.paa";
		model = "ck\ck_weapons\ck_m1911\ck_m1911_magazine.p3d";
		ammo = "ck_m1911_bullet";
		count = 7;
		initSpeed = 253;
		type = 16;
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
	class Pistol;
	class Pistol_Base_F: Pistol
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class ck_pistolbase: Pistol_Base_F
	{
		scope = 1;
		author = "Noks";
		reloadAction = "GestureReloadPistol";
		recoil = "recoil_default";
		class GunParticles: GunParticles {};
		cameraDir = "eye_look";
		discreteDistance[] = {10,25};
		discreteDistanceCameraPoint[] = {"eye","eye_zoom"};
		discreteDistanceInitIndex = 0;
	};
	class ck_m1911_w: ck_pistolbase
	{
		scope = 2;
		model = "ck\ck_weapons\ck_m1911\ck_m1911.p3d";
		picture = "ck\ck_weapons\ck_m1911\data\ui\ck_m1911_ca.paa";
		displayName = "Colt M1911";
		descriptionShort = "M1911A1 .45ACP";
		class GunParticles: GunParticles {};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 25;
			class MuzzleSlot{};
			class CowsSlot{};
			class PointerSlot{};
		};
		drySound[] = {"A3\sounds_f\weapons\other\dry1",0.7,1,20};
		reloadMagazineSound[] = {"ck\ck_weapons\ck_m1911\sounds\ck_m1911_reload.wss",1,1,30};
		magazines[] = {"ck_m1911_magazine"};
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = -1;
		recoil = "recoil_pistol_4five";
		selectionFireAnim = "muzzleFlash";
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"Zubr_Shot_SoundSet","Zubr_Tail_SoundSet","Zubr_InteriorTail_SoundSet"};
			};
			reloadTime = 0.05;
			dispersion = 0.00406;
			minRange = 5;
			minRangeProbab = 0.3;
			midRange = 25;
			midRangeProbab = 0.6;
			maxRange = 50;
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
			libTextDesc = "Colt m1911 utilisé notamment par les commandos britaniques dont le commando Kieffer";
		};
	};
};