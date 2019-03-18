#define _ARMA_

class CfgPatches
{
	class ck_milsbomb_p
	{
		author = "Noks";
		version = "0.49.2";
		requiredVersion = 1.8;
		requiredAddons[] = {"A3_Weapons_F"};
	};
};

class CfgAmmo 
{
	class Default;
	class Grenade: Default {};
	class GrenadeHand: Grenade {};
	class ck_milsbomb_ammunition: GrenadeHand 
	{
		scope = 1;
		hit = 0.001;
		indirectHit = 0.001;
		indirectHitRange = 0.01;
		model = "ck\ck_weapons\ck_milsbomb\ck_milsbomb.p3d";
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		fuseDistance = 5;
	};
};

class cfgMagazines
{
	class Default;
	class CA_Magazine: Default {};
	class HandGrenade: CA_Magazine {};
	class ck_milsbomb_magazine:  HandGrenade
	{
		displayName = "Grenade milsbomb";
		picture = "" ;
		displayNameShort = "Mils";
		ammo = "ck_milsbomb_ammunition";
	};
};

class CfgWeapons 
{
	class Default;
	class GrenadeLauncher: Default {};
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle: GrenadeLauncher {};
		class HandGrenadeMuzzle: ThrowMuzzle {};
	};
	class ck_milsbomb_throw : Throw 
	{
		displayname = "Throw";
		muzzles[] = {"ck_milsbomb_muzzle"};
		class ThrowMuzzle: GrenadeLauncher {};
		class HandGrenadeMuzzle: ThrowMuzzle {};
		class ck_milsbomb_muzzle: HandGrenadeMuzzle
		{
			magazines[] = {"ck_milsbomb_magazine"};
		};
	};
};