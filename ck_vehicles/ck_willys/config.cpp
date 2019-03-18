#define _ARMA_

#define true 1
#define false 0

#define WEST 1

#define times_4(a) a,a,a,a
#define times_8(a) a,a,a,a,a,a,a,a

#define magazine_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weapon_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}
#define backpack_xx(a,b) class _xx_##a {backpack = a; count = b;}

class CfgPatches
{
	class ck_willys
	{
		author = "Noks";
		version = "0.10.4";
		requiredVersion = 1.8;
		requiredAddons[] = {};
		units[] = {"ck_willys_cmd_cover","ck_willys_cmd","ck_modern_willys_cmd_smg"};
	};
};

class CfgFunctions
{
	class ck
	{
		class ck_core_functions
		{
			tag = "ck";
			class remoteSay3D
			{
				author = "Noks";
				file = "ck\ck_vehicles\ck_willys\functions\fn_remoteSay3D.sqf";
				recompile = 1;
			};
		};
	};
};

class CfgSounds
{
	class wipers
	{
		name = "";
		sound[] = {"ck\ck_vehicles\ck_willys\sounds\wipers.wss", 1, 1};
		titles[] = {1, "Essuis glace"};
	};
};

class CfgMovesBasic
{
	class DefaultDie;

	class ManActions
	{
		willys_driver = "willys_driver";
		KIA_willys_driver = "KIA_willys_driver";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesMale";

	class States
	{
		class Crew;
		class AmovPercMstpSnonWnonDnon;
		
		class KIA_willys_driver: Crew
		{
			file = "ck\ck_vehicles\ck_willys\anims\KIA_willys_driver.rtm";
		};
		class willys_driver: Crew
		{
			file = "ck\ck_vehicles\ck_willys\anims\willys_driver.rtm";
			interpolateTo[] = {"KIA_willys_driver", 1};
		};
	};
};

class cfgWeapons
{
	class Default;
	class MGunCore;
	class CannonCore;
	class LauncherCore;
	class carHorn;
	class ck_willys_horn_1: carHorn
	{
		scope = 2;
		name = "Jeep Willys - Horn 1";
		reloadTime = 0.5;
		drySound[] = {"ck\ck_vehicles\ck_willys\ck_willys\sounds\horn.wss",1.1220185,1};
	};
};

class DefaultEventHandlers;
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class AnimationSources;
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
		class ViewOptics;
		class Sounds;
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class EventHandlers;
	};
	class ck_jeepwillys_base: Car_F
	{
		scope = 1;
		author = "Noks";
		dlc = "commando_kieffer";
		displayName = "Jeep Willys";
		model = "ck\ck_vehicles\ck_willys\ck_willys.p3d";
		vehicleClass = "ck_core_vehClass_cmd_wheeled";
		editorSubcategory = "ck_core_editorSubCat_cmd_wheeled";
		side = WEST;
		faction = "ck_core_faction_ck";
		crew = "B_officer_F";
		typicalCargo[] = {times_4("B_officer_F")};
		memoryPointsGetInDriver = "pos driver";
		irtarget = 0;
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCommander = "pos cmd";
		memoryPointsGetInCommanderDir = "pos cmd dir";
		memoryPointsGetInGunner = "pos gunner";
		memoryPointsGetInGunnerDir = "pos gunner dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"ck\ck_vehicles\ck_willys\data\ck_willys_co.paa"};
		Picture = "ck\ck_vehicles\ck_willys\icons\willys_00_ca.paa";
		Icon = "ck\ck_vehicles\ck_willys\icons\icomap_willys_ca.paa";
		mapSize = 6;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_vehicle_armedcar_s"};
				speechPlural[] = {"veh_vehicle_armedcar_p"};
			};
		};
		textSingular = "$STR_A3_nameSound_veh_vehicle_armedcar_s";
		textPlural = "$STR_A3_nameSound_veh_vehicle_armedcar_p";
		nameSound = "veh_vehicle_armedcar_s";
		threat[] = {0.1,0.1,0.1};
		crewVulnerable = 1;
		crewCrashProtection = 0.0015;
		weapons[] = {"ck_willys_horn_1"};
		magazines[] = {};
		armor = 75;
		damageResistance = 0.00562;
		wheelDamageThreshold = 0.7;
		wheelDestroyThreshold = 0.99;
		wheelDamageRadiusCoef = 0.95;
		wheelDestroyRadiusCoef = 0.45;
		cost = 200;
		accuracy = 0.32;
		precision = 15;
		armorGlass = 0.5;
		armorWheels = 0.33;
		transportSoldier = 0;
		turnCoef = 3;
		steerAheadPlan = 0.2;
		steerAheadSimul = 0.4;
		predictTurnPlan = 0.9;
		predictTurnSimul = 0.5;
		brakeDistance = 1.0;
		terrainCoef = 1.5;
		maxSpeed = 110;
		brakeIdleSpeed = 1.78;
		fuelCapacity = 250;
		castDriverShadow = 0;
		driverAction = "willys_driver"; // driverAction = "uns_willy_Driver"; - driver_offroad01
		driverLeftHandAnimName = "drivewheel"; // driverLeftHandAnimName = "volant";
		driverRightHandAnimName = "drivewheel"; // driverRightHandAnimName = "volant";
		cargoAction[] = {"passenger_low01","passenger_low01"};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		simulation = "carx";
		wheelCircumference = 2.834;
		antiRollbarForceCoef = 24;
		antiRollbarForceLimit = 30;
		antiRollbarSpeedMin = 15;
		antiRollbarSpeedMax = 70;
		damperSize = 0.2;
		damperForce = 1;
		damperDamping = 1;
		dampersBumpCoef = 6.0;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.3;
		rearBias = 1.3;
		centreBias = 1.3;
		clutchStrength = 10;
		idleRpm = 700;
		redRpm = 5000;
		enginePower = 350;
		maxOmega = 600;
		peakTorque = 400;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 2;
		dampingRateZeroThrottleClutchDisengaged = 0.1;
		torqueCurve[] = {{0.0,"0/500"},{0.2,"175/500"},{0.3,"300/500"},{0.4,"400/500"},{0.6,"450/500"},{0.7,"275/500"},{0.9,"125/500"},{1.0,"0/500"}};
		changeGearMinEffectivity[] = {0.5,0.15,0.97,0.97,0.97,0.97,0.97,0.985};
		switchTime = 0.2;
		latency = 1.0;
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-4,"N",0,"D1","4.1","D2","2.21","D3","1.1","D4","0.47","D5","0.35","D6","0.15"};
			TransmissionRatios[] = {"High",7};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		class Wheels
		{
			class L1
			{
				boneName = "wheel_1_1_damper";
				boundary = "wheel_1_1_bound";
				center = "wheel_1_1_centre";
				suspForceAppPointOffset = "wheel_1_1_centre";
				tireForceAppPointOffset = "wheel_1_1_centre";
				steering = 1;
				side = "left";
				width = "0.2";
				mass = 50;
				MOI = 15;
				dampingRate = 0.4;
				dampingRateDamaged = 1;
				dampingRateDestroyed = 1000;
				dampingRateInAir = 1000;
				maxBrakeTorque = 1500;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0,-1,0};
				maxCompression = 0.05;
				maxDroop = 0.05;
				sprungMass = 502;
				springStrength = 13000;
				springDamperRate = 10000;
				longitudinalStiffnessPerUnitGravity = 5000;
				latStiffX = 25;
				latStiffY = 180;
				frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
			};
			class L3: L1
			{
				boneName = "wheel_1_2_damper";
				boundary = "wheel_1_2_bound";
				center = "wheel_1_2_centre";
				suspForceAppPointOffset = "wheel_1_2_centre";
				tireForceAppPointOffset = "wheel_1_2_centre";
				steering = 0;
				maxHandBrakeTorque = 300000;
			};
			class R1: L1
			{
				boneName = "wheel_2_1_damper";
				boundary = "wheel_2_1_bound";
				center = "wheel_2_1_centre";
				suspForceAppPointOffset = "wheel_2_1_centre";
				tireForceAppPointOffset = "wheel_2_1_centre";
				steering = 1;
				side = "right";
			};
			class R3: L1
			{
				boneName = "wheel_2_2_hide";
				boundary = "wheel_2_2_bound";
				center = "wheel_2_2_centre";
				suspForceAppPointOffset = "wheel_2_2_centre";
				tireForceAppPointOffset = "wheel_2_2_centre";
				side = "right";
				maxHandBrakeTorque = 300000;
				steering = 0;
			};
		};
		driveOnComponent[] = {"wheel_1_1_damper","wheel_1_2_damper","wheel_2_1_damper","wheel_2_2_damper"};
		attenuationEffectType = "OpenCarAttenuation";
		soundGetIn[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getin",0.56234133,1};
		soundGetOut[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getout",0.56234133,1,40};
		soundDammage[] = {"",0.56234133,1};
		soundEngineOnInt[] = {"ck\ck_vehicles\ck_willys\sounds\willy_startup_int",0.35,1.0};
		soundEngineOnExt[] = {"ck\ck_vehicles\ck_willys\sounds\willy_startup_ext",0.7,1.0,200};
		soundEngineOffInt[] = {"ck\ck_vehicles\ck_willys\sounds\willy_shutdown_int",0.35,1.0};
		soundEngineOffExt[] = {"ck\ck_vehicles\ck_willys\sounds\willy_shutdown_ext",0.7,1.0,200};
		buildCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_01",1.0,1,200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_02",1.0,1,200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_03",1.0,1,200};
		buildCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_04",1.0,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_01",1.0,1,200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_02",1.0,1,200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_03",1.0,1,200};
		WoodCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_04",1.0,1,200};
		WoodCrash4[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_05",1.0,1,200};
		WoodCrash5[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_06",1.0,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_01",1.0,1,200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_02",1.0,1,200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_03",1.0,1,200};
		ArmorCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_04",1.0,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_idle",0.31622776,1,100};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm1",0.31622776,1,200};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm2",0.35481337,1,225};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm3",0.35481337,1,250};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm4",0.39810717,1,275};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm5",0.4466836,1,300};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm6",0.5011872,1,300};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm7",0.56234133,1,300};
				frequency = "0.95 + ((rpm/ 3500) factor[(2700/ 3500),(3500/ 3500)])*0.2";
				volume = "engineOn*camPos*((rpm/ 3500) factor[(2700/ 3500),(3200/ 3500)])";
			};
			class IdleThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_idle",0.5011872,1,200};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class EngineThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm1",0.56234133,1,250};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm2",0.63095737,1,275};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm3",0.70794576,1,300};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm4",0.7943282,1,325};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm5",0.8912509,1,350};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm6",1.0,1,375};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm7",1.1220185,1,400};
				frequency = "0.95 + ((rpm/ 3500) factor[(2700/ 3500),(3500/ 3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3500) factor[(2700/ 3500),(3200/ 3500)])";
			};
			class Idle_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_idle",0.2238721,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class Engine_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm1",0.25118864,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm2",0.17782794,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm3",0.31622776,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm4",0.35481337,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm5",0.39810717,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm6",0.39810717,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm7",0.4466836,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2700/ 3500),(3500/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*((rpm/ 3500) factor[(2700/ 3500),(3200/ 3500)])";
			};
			class IdleThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_idle",0.31622776,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm1",0.35481337,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm2",0.39810717,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm3",0.4466836,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm4",0.5011872,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm5",0.56234133,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm6",0.63095737,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm7",0.70794576,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2700/ 3500),(3500/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3500) factor[(2700/ 3500),(3200/ 3500)])";
			};
			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",0.70794576,1.0,60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",0.56234133,1.0,90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",0.70794576,1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",0.15848932,1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.31622776,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust";
				direction = "exhaust_dir";
				effect = "ExhaustEffectOffroad";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret{};
			class Commander_Turret: MainTurret
			{
				crew = "B_officer_F";
				gunnerName = "$STR_POSITION_COMMANDER";
				proxyType = "CPCommander";
				proxyIndex = 1;
				primaryObserver = 1;
				primaryGunner = 0;
				commanding = 2;
				startEngine = 0;
				weapons[] = {"SEARCHLIGHT"};
				gunnerAction = "passenger_low01";
				gunnerInAction = "GetInLow";
				memoryPointsGetInGunner = "pos cmd";
				memoryPointsGetInGunnerDir = "pos cmd dir";
				body = "obsTurret";
				gun = "obsGun";
				animationSourceBody = "obsTurret";
				animationSourceGun = "obsGun";
				LODTurnedOut = 1200;
				LODTurnedIn = 1200;
				turretInfoType = "RscWeaponEmpty";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				forceHideGunner = 0;
				gunnerOpticsModel = "ck\ck_vehicles\ck_willys\ca\Weapons\optika_empty";
				gunnerOutOpticsModel = "ck\ck_vehicles\ck_willys\ca\Weapons\optika_empty";
				memoryPointGunnerOptics = "cmdrview";
				memoryPointGunnerOutOptics = "cmdrview";
				enableManualFire = 0;
				GunnerForceOptics = 0;
				isPersonTurret = 0;
				minElev = -10;
				maxElev = 65;
				minTurn = -135;
				maxTurn = 80;
				initFov = 0.4;
				minFov = 0.25;
				maxFov = 1.1;
				class ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 1;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 1;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"ck\ck_vehicles\ck_willys\data\willys.rvmat",
				"ck\ck_vehicles\ck_willys\data\willys_damage.rvmat",
				"ck\ck_vehicles\ck_willys\data\willys_destruct.rvmat"
			};
		};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[] 		= {1900, 1800, 1700};
				ambient[]		= {5, 5, 5};
				position 		= "LightCarHeadL01";
				direction 		= "LightCarHeadL01_end";
				hitpoint 		= "Light_L";
				selection 		= "Light_L";
				size 			= 1;
				innerAngle 		= 100;
				outerAngle 		= 179;
				coneFadeCoef 	= 10;
				intensity 		= 1;
				useFlare 		= true;
				dayLight 		= false;
				flareSize 		= 1.0;

				class Attenuation
				{
					start 			= 1.0;
					constant 		= 0;
					linear 			= 0;
					quadratic 		= 0.25;
					hardLimitStart 	= 30;
					hardLimitEnd 	= 60;
				};
			};

			class LightCarHeadR01: LightCarHeadL01
			{
				position 	= "LightCarHeadR01";
				direction 	= "LightCarHeadR01_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};
		};
		aggregateReflectors[] = {{}};
		class RenderTargets
		{
			class LeftMirror
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 4;
					fov = 0.7;
				};
			};
		};
		class AnimationSources
		{
			class wiperr
			{
				source = "user";
				animPeriod = 1.5;
			};
			class wiperl: wiperr{};
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
			class fuelcan
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class spare: fuelcan
			{
				initPhase = 0;
			};
			class sunroof: fuelcan{};
			class Damper_1_1_source
			{
				source = "damper";
				wheel = "L1";
			};
			class Damper_1_4_source: Damper_1_1_source
			{
				wheel = "L3";
			};
			class Damper_2_1_source: Damper_1_1_source
			{
				wheel = "R1";
			};
			class Damper_2_4_source: Damper_1_1_source
			{
				wheel = "R3";
			};
			class antennaL: Damper_1_1_source
			{
				animPeriod = 0.5;
			};
			class antennaL1: antennaL{};
			class antennaL2: antennaL{};
			class antennaR: antennaL{};
			class antennaR1: antennaL{};
			class antennaR2: antennaL{};
			class HitLGlass: HitLFWheel
			{
				hitpoint = "HitLGlass";
			};
			class windshield
			{
				source = "user";
				animPeriod = 1.5;
				initPhase = 0;
			};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor=0.125;
				passThrough=0;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=0.125;
				passThrough=0;
			};
			class HitRFWheel: HitRFWheel
			{
				armor=0.125;
				passThrough=0;
			};
			class HitRF2Wheel: HitRF2Wheel 
			{
				armor=0.125;
				passThrough=0;
			};
			class HitFuel
			{
				armor = 0.50;
				material = -1;
				name = "fueltank";
				visual = "";
				passThrough = 0.2;
			};
			class HitEngine
			{
				armor = 0.50;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.2;
			};
			class HitBody: HitBody
			{
				name = "body";
				visual = "camo";
				passThrough = 1;
			};
			class HitGlass1: HitGlass1
			{
				armor=0.25;
			};
			class HitGlass2: HitGlass2
			{
				armor=0.25;
			};
			/*
			class HitLGlass
			{
				armor = 0.25;
				material = -1;
				name = "glassL";
				visual = "glassL";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "zbytek";
				passThrough = 1;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				convexcomponent = "motor";
				visual = "";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1.0;
				material = -1;
				name = "palivo";
				convexcomponent = "palivo";
				visual = "";
				passThrough = 0;
			};
			class HitLFWheel
			{
				armor = 0.3;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0.3;
			};
			class HitLBWheel: HitLFWheel
			{
				name = "wheel_1_2_steering";
			};
			class HitRFWheel: HitLFWheel
			{
				name = "wheel_2_1_steering";
			};
			class HitRBWheel: HitLFWheel
			{
				name = "wheel_2_2_steering";
			};
			class HitLF2Wheel: HitLFWheel{};
			class HitRF2Wheel: HitLFWheel{};
			class HitLMWheel: HitLFWheel{};
			class HitRMWheel: HitLFWheel{};
			*/
		};
		class UserActions
		{
			class DropFlare
			{
				displayName = "<t color='#0055A4'>Fusée de signalement</t>";
				position = "steering_wheel";
				showWindow = 0;
				priority = 1;
				radius = 10;
				onlyForPlayer = 0;
				condition = "(((date select 3) < 7 or (date select 3) > 18) and (player in (crew this)))";
				statement = "[this] execVM 'ck\ck_vehicles\ck_willys\scripts\boatflare.sqf'";
				shortcut = "opticsMode";
			};
			class Sparetire: DropFlare
			{
				displayName = "<t color='#0055A4'>Réparer</t>";
				position = "spare";
				radius = 3;
				priority = -1;
				condition = "(alive this) and (this animationphase 'spare' < 1) and !(canMove this)";
				statement = "[this] execVM 'ck\ck_vehicles\ck_willys\scripts\tirechange.sqf'";
				shortcut = "";
			};
			class FuelCan: Sparetire
			{
				displayName = "<t color='#0055A4'>Utiliser le réservoir</t>";
				condition = "(alive this) and this animationphase 'fuelcan' < 0.1 and (fuel this < 0.5) and (speed this < 1)";
				statement = "[this] execVM 'ck\ck_vehicles\ck_willys\scripts\refuel.sqf'";
			};
			class initArsenalAce
			{
				displayName = "Arsenal ace";
				position = "camera";
				showWindow = 0;
				radius = 5;
				onlyForPlayer = 0;
				priority = -1;
				condition = "(alive this) and (isClass(configFile >> ""CfgPatches"" >> ""ace_arsenal""))";
				statement = "[player,player,true] call ace_arsenal_fnc_openBox";
				shortcut = "";
			};
			class initArsenalBis
			{
				displayName = "Arsenal bis";
				position = "camera";
				showWindow = 0;
				radius = 5;
				onlyForPlayer = 0;
				priority = -1;
				condition = "(alive this)";
				statement = "[""Open"",[true]] call BIS_fnc_arsenal;";
				shortcut = "";
			};
			class RaiseWindshield
			{
				displayName = "<t color='#0055A4'>Lever le pare brise</t>";
				position = "windshield_axis";
				showWindow = 0;
				radius = 3;
				priority = -1;
				onlyForPlayer = 0;
				condition = "(player in (crew this)) and (alive this) and this animationphase 'windshield' > 0.9 and (speed this < 5)";
				statement = "this animate ['windshield',0]";
			};
			class LowerWindShield: RaiseWindshield
			{
				displayName = "<t color='#0055A4'>Baisser le pare brise</t>";
				condition = "(player in (crew this)) and (alive this) and this animationphase 'windshield' < 0.1 and (speed this < 5)";
				statement = "this animate ['windshield',1]";
			};
		};
		transportMaxBackpacks = 8;
		class TransportItems
		{
			item_xx(FirstAidKit,4);
			item_xx(ToolKit,1);
		};
		class TransportMagazines
		{
			magazine_xx(ck_m1911_magazine,5);
		};
		class TransportWeapons
		{
			wepaon_xx(ck_m1911_w,1);
		};
		class Library
		{
			libTextDesc = "Jeep Willys";
		};
		
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio = 1;
		tf_encryptionCode = "tf_west_radio_code";
		tf_dialog = "rt1523g_radio_dialog";
		tf_subtype = "digital_lr";
		tf_isolatedAmount = 0.2;
		tf_range = 30000;
	};
	/*
		class CargoTurret;
		class Turrets: Turrets
		{
			class Commander_Turret: Commander_Turret{};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction = "passenger_inside_1";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInCargo = "pos backRight";
				memoryPointsGetInCargoDir = "pos backRight dir";
				gunnerName = "Passenger - Right";
				proxyIndex = 1;
				maxElev = 45;
				minElev = -35;
				maxTurn = 45;
				minTurn = -90;
				isPersonTurret = 1;
				ejectDeadGunner = 0;
				LODTurnedIn = 1000;
				LODTurnedOut = 1000;
				enabledByAnimationSource = "";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerAction = "passenger_inside_2";
				memoryPointsGetInCargo = "pos backLeft";
				memoryPointsGetInCargoDir = "pos backLeft dir";
				gunnerName = "Passenger - Left";
				proxyIndex = 2;
				maxTurn = 90;
				minTurn = -45;
			};
		};
	*/
};