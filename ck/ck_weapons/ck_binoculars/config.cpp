#define _ARMA_

class cfgPatches
{
	class ck_binoculars_p
	{
		author = "Noks";
		version = "0.4.9";
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
	};
};


class cfgWeapons
{
	class Binocular;
	class ck_binoculars_w: Binocular
	{
		author = "Noks";
		displayName = "Prism No.2 Mk.II";
		model = "ck\ck_weapons\ck_binoculars\ck_binoculars.p3d";
		picture = "ck\ck_weapons\ck_binoculars\data\ui\ck_binoculars_ca.paa";
		descriptionShort = "Zoom 6x-30x";
		memoryPointCamera = "eye";
		opticsZoomMin = 0.01;
		opticsZoomMax = 0.06;
		opticsZoomInit = 0.05;
		distanceZoomMin = 100;
		distanceZoomMax = 500;
	};
};