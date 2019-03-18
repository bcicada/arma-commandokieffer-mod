#define _ARMA_

#define true 1
#define false 0

#define WEST 1
#define INDEP 2

#define times_4(a) a,a,a,a
#define times_8(a) a,a,a,a,a,a,a,a

#define magazine_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weapon_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}
#define backpack_xx(a,b) class _xx_##a {backpack = a; count = b;}

class CfgPatches
{
	class ck_jeepwillys_p
	{
		author = "Noks";
		version = "0.76.39";
		requiredVersion = 1.8;
		requiredAddons[] = {"A3_Soft_F","ck_main_p","task_force_radio"};
		units[] = {"ck_jeepwillys_v","ck_jeepwillys_mg_v"};
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
			file = "ck\ck_vehicles\ck_jeepwillys\anims\KIA_willys_driver.rtm";
		};
		class willys_driver: Crew
		{
			file = "ck\ck_vehicles\ck_jeepwillys\anims\willys_driver.rtm";
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
	class ck_jeepwillys_horn_w: carHorn
	{
		scope = 2;
		name = "Jeep Willys - Klaxon";
		displayName = "Klaxon";
		reloadTime = 0.2;
		drySound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_horn.wss",1,1};
	};
	class ck_jeepwillys_siren_w: carHorn
	{
		scope = 2;
		name = "Jeep Willys - Sirène";
		displayName = "Sirène";
		reloadTime = 0.2;
		drySound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_siren.wss",1,1};
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
	class ck_jeepwillys_base_v: Car_F
	{
		scope = 1;
		scopeCurator = 1;
		author = "Noks";
		dlc = "CommandoKieffer";
		displayName = "Jeep Willys";
		model = "ck\ck_vehicles\ck_jeepwillys\ck_jeepwillys.p3d";
		side = INDEP;
		faction = "ck_faction_1bfmc";
		vehicleClass = "ck_vehCls_vehicles";
		editorSubcategory = "ck_edtSubCat_vehicles";
		crew = "B_officer_F";
		typicalCargo[] = {"B_officer_F","B_officer_F"};
		irtarget = 0;
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCommander = "pos cmd";
		memoryPointsGetInCommanderDir = "pos cmd dir";
//		memoryPointsGetInGunner = "pos gunner";
//		memoryPointsGetInGunnerDir = "pos gunner dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		hiddenSelections[] = {"camo","plate","hood"};
		hiddenSelectionsTextures[] =
		{
			"ck\ck_vehicles\ck_jeepwillys\data\ck_jeepwillys_co.paa",
			"ck\ck_vehicles\ck_jeepwillys\data\decals\ck_jeepwillys_plate_blank_co.paa",
			"ck\ck_vehicles\ck_jeepwillys\data\decals\ck_jeepwillys_hood_blank_ca.paa"
		};
		Picture = "ck\ck_vehicles\ck_jeepwillys\data\ui\ck_jeepwillys_ui_ca.paa";
		Icon = "ck\ck_vehicles\ck_jeepwillys\data\ui\ck_jeepwillys_icomap_ca.paa";
		mapSize = 4;
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
		weapons[] = {"ck_jeepwillys_horn_w"};
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
		transportSoldier = 2;
		turnCoef = 3;
		steerAheadPlan = 0.2;
		steerAheadSimul = 0.4;
		predictTurnPlan = 0.9;
		predictTurnSimul = 0.5;
		brakeDistance = 1.0;
		terrainCoef = 1.5;
		maxSpeed = 90;
		brakeIdleSpeed = 1.78;
		fuelCapacity = 250;
		castDriverShadow = 0;
		hasDriver = true;
		hasCommander = true;
		hasGunner = false;
		driverAction = "willys_driver"; // driverAction = "uns_willy_Driver"; - driver_offroad01
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "gearboxhandle";
		cargoAction[] = {"passenger_low01","passenger_low01"};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		simulation = "carx";
		wheelCircumference = 2.8;
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
		insideSoundCoef = 1;
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
			class LF
			{
				boneName = "wheel_1_1_damper";
				steering = true;
				side = "left";
				center   = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				mass = 20;
				MOI = 3.3;
				dampingRate = 0.5;
				maxBrakeTorque = 2000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0, -0.5, 0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.1;
				mMaxDroop = 0.15;
				sprungMass = 350.0;
				springStrength = 22600;
				springDamperRate = 8680;
				longitudinalStiffnessPerUnitGravity = 100000;
				latStiffX = 25;
				latStiffY = 18000;
				frictionVsSlipGraph[] = {{0, 1}, {0.5, 1}, {1,1}};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				steering = false;
				center   = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;
				latStiffY = 180;	
				sprungMass = 190.0;
				springStrength = 4750;
				springDamperRate = 1760;				
			};
			class RF: LF
			{
				boneName = "wheel_2_1_damper";
				center   = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = true;
				side = "right";
			};
			class RR: RF
			{
				boneName = "wheel_2_2_damper";
				steering = false;
				center   = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3000;
				latStiffY = 180;				
				sprungMass = 190.0;
				springStrength = 4750;
				springDamperRate = 1760;					
			};
		};
		attenuationEffectType = "OpenCarAttenuation";
		soundGetIn[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getin",0.56234133,1};
		soundGetOut[] = {"A3\Sounds_F\vehicles\soft\MRAP_01\getout",0.56234133,1,40};
		soundDammage[] = {"",0.56234133,1};
		soundEngineOnInt[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_startup_int",0.35,1.0};
		soundEngineOnExt[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_startup_ext",0.7,1.0,200};
		soundEngineOffInt[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_shutdown_int",0.35,1.0};
		soundEngineOffExt[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_shutdown_ext",0.7,1.0,200};
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
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_idle",0.31622776,1,100};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class Engine
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm1",0.31622776,1,200};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm2",0.35481337,1,225};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm3",0.35481337,1,250};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm4",0.39810717,1,275};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm5",0.4466836,1,300};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm6",0.5011872,1,300};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_ext
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_ext_rpm7",0.56234133,1,300};
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
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_idle",0.2238721,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(200/ 3500),(580/ 3500)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(200/ 3500),(350/ 3500)]) * ((rpm/ 3500) factor[(580/ 3500),(400/ 3500)]))";
			};
			class Engine_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm1",0.25118864,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(380/ 3500),(960/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(380/ 3500),(580/ 3500)]) * ((rpm/ 3500) factor[(960/ 3500),(700/ 3500)]))";
			};
			class Engine1_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm2",0.17782794,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(700/ 3500),(1400/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(700/ 3500),(970/ 3500)]) * ((rpm/ 3500) factor[(1400/ 3500),(1100/ 3500)]))";
			};
			class Engine2_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm3",0.31622776,1};
				frequency = "0.9 + ((rpm/ 3500) factor[(1100/ 3500),(1860/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(1100/ 3500),(1430/ 3500)]) * ((rpm/ 3500) factor[(1860/ 3500),(1570/ 3500)]))";
			};
			class Engine3_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm4",0.35481337,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(1600/ 3500),(2200/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(1600/ 3500),(1860/ 3500)]) * ((rpm/ 3500) factor[(2200/ 3500),(2050/ 3500)]))";
			};
			class Engine4_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm5",0.39810717,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2040/ 3500),(2670/ 3500)]) *0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(2040/ 3500),(2200/ 3500)]) * ((rpm/ 3500) factor[(2670/ 3500),(2400/ 3500)]))";
			};
			class Engine5_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm6",0.39810717,1};
				frequency = "0.95 + ((rpm/ 3500) factor[(2400/ 3500),(3050/ 3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/ 3500) factor[(2400/ 3500),(2660/ 3500)]) * ((rpm/ 3500) factor[(3050/ 3500),(2800/ 3500)]))";
			};
			class Engine6_int
			{
				sound[] = {"ck\ck_vehicles\ck_jeepwillys\sounds\ck_jeepwillys_int_rpm7",0.4466836,1};
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
			class MainTurret: MainTurret
			{
				crew = "B_officer_F";
				gunnerName = "$STR_POSITION_COMMANDER";
				proxyType = "CPCommander";
				proxyIndex = 1;
				primaryObserver = 1;
				primaryGunner = 0;
				commanding = 2;
				startEngine = 0;
				weapons[] = {};
				gunnerAction = "passenger_low01";
				gunnerInAction = "GetInLow";
				memoryPointsGetInGunner = "pos cmd";
				memoryPointsGetInGunnerDir = "pos cmd dir";
				LODTurnedOut = 1200;
				LODTurnedIn = 1200;
				turretInfoType = "RscWeaponEmpty";
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				forceHideGunner = 0;
				gunnerOpticsModel = "a3\weapons_f\empty.p3d";
				gunnerOutOpticsModel = "a3\weapons_f\empty.p3d";
				memoryPointGunnerOptics = "commanderview";
				memoryPointGunnerOutOptics = "commanderview";
				enableManualFire = 0;
				GunnerForceOptics = 0;
				isPersonTurret = 0;
				minElev = -60;
				maxElev = 60;
				minTurn = -135;
				maxTurn = 80;
				initFov = 0.4;
				minFov = 0.25;
				maxFov = 1.1;
				class ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -60;
					maxAngleX = 60;
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
					minAngleX = -60;
					maxAngleX = 60;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 1;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};

		memoryPointTrackFLL = "TrackFLL";
		memoryPointTrackFLR = "TrackFLR";
		memoryPointTrackBLL = "TrackBLL";
		memoryPointTrackBLR = "TrackBLR";
		memoryPointTrackFRL = "TrackFRL";
		memoryPointTrackFRR = "TrackFRR";
		memoryPointTrackBRL = "TrackBRL";
		memoryPointTrackBRR = "TrackBRR";
		
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"ck\ck_vehicles\ck_jeepwillys\data\ck_jeepwillys.rvmat",
				"ck\ck_vehicles\ck_jeepwillys\data\ck_jeepwillys_damage.rvmat",
				"ck\ck_vehicles\ck_jeepwillys\data\ck_jeepwillys_destruct.rvmat"
			};
		};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[] 		= {1900,1300,950};
				ambient[]		= {5,5,5};
				position 		= "LightCarHeadL01";
				direction 		= "LightCarHeadL01_end";
				hitpoint 		= "headlight_left";
				selection 		= "headlight_left";
				size 			= 1;
				innerAngle 		= 90;
				outerAngle 		= 161;
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
				hitpoint 	= "headlight_right";
				selection 	= "headlight_right";
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
		class AnimationSources: AnimationSources
		{
			/*
			class HitLFWheel
			{
				source = "hit";
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
			*/
			
			class Damper_1_1_source
			{
				source = "damper";
				wheel = "LF";
			};
			class Damper_1_2_source: Damper_1_1_source
			{
				wheel = "LR";
			};
			class Damper_2_1_source: Damper_1_1_source
			{
				wheel = "RF";
			};
			class Damper_2_2_source: Damper_1_1_source
			{
				wheel = "RR";
			};
			
			class HitGlass1
			{
				source = "hit";
				raw = 1;
				hitpoint = "HitGlass1";
			};
			class HitGlass2: HitGlass1
			{
				hitpoint = "HitGlass2";
			};
			
			class HitSpareWheel: HitGlass1
			{
				source = "hit";
				raw = 1;
				hitpoint = "HitSpareWheel";
			};
			class sparewheel_hide
			{
				AnimPeriod = 0.1;
				source = "user";
				InitPhase = 0;
			};
			class fuelcan_hide: sparewheel_hide
			{
				AnimPeriod = 0.1;
			};
			class windshield_rotation: sparewheel_hide
			{
				AnimPeriod = 1.5;
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
			class HitSpareWheel: HitLFWheel
			{
				material = -1;
				name = "sparewheel";
				visual = "";				
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
				name = "karoserie";
				visual = "camo";
				passThrough = 1;
			};
			class HitGlass1: HitGlass1
			{
				armor = 0.25;
				material = -1;
				name = "glass_left";
				visual = "glass_left";
				passThrough = 0;
			};
			class HitGlass2: HitGlass2
			{
				armor = 0.25;
				material = -1;
				name = "glass_right";
				visual = "glass_right";
				passThrough = 0;
			};
		};
		class UserActions
		{
			class remove_windshield
			{
				displayName = "<t color='#EF4135'>Baisser le pare brise</t>";
				position = "camera";
				showWindow = 0;
				priority = 1;
				radius = 10;
				onlyForPlayer = 1;
				condition = "alive this and player in crew this and this animationphase 'windshield_rotation' < 1";
				statement = "this animate [""windshield_rotation"",1]";
			};
			class install_windshield: remove_windshield
			{
				displayName = "<t color='#0055A4'>Lever le pare brise</t>";
				condition = "alive this and player in crew this and this animationphase 'windshield_rotation' > 0";
				statement = "this animate [""windshield_rotation"",0]";
			};
			class repair: remove_windshield
			{
				displayName = "<t color='#0055A4'>Réparer</t>";
				condition = "alive this and not (player in crew this) and this animationphase 'sparewheel_hide' < 0.1  and speed this < 1 and not canMove this";
				statement = "this animate [""sparewheel_hide"", 1], this setDamage 0";
			};
			class refuel: remove_windshield
			{
				displayName = "<t color='#0055A4'>Faire le plein</t>";
				condition = "alive this and not (player in crew this) and this animationphase 'fuelcan' < 0.1 and fuel this < 0.8 and speed this < 1";
				statement = "this animate ['fuelcan_hide',1], this SetFuel (fuel this + 0.2)";
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
			magazine_xx(ck_thompson_magazine,5);
			magazine_xx(ck_smle_magazine,5);
			magazine_xx(ck_sten_magazine,5);
			magazine_xx(ck_bren_magazine,5);
		};
		class TransportWeapons
		{
			weapon_xx(ck_m1911_w,1);
			weapon_xx(ck_thompson_w,1);
			weapon_xx(ck_smle_w,1);
			weapon_xx(ck_sten_w,1);
			weapon_xx(ck_bren_w,1);
			weapon_xx(ck_binoculars_w,1);
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
	class ck_jeepwillys_v: ck_jeepwillys_base_v /// Model non armé -> 1 commander et 2 turrets
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys";
	};
	class ck_jeepwillys_mg_v: ck_jeepwillys_base_v /// Model armé -> 1 commander et 1 gunner
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys armée";
		model = "ck\ck_vehicles\ck_jeepwillys\ck_jeepwillys_mg.p3d";
	};
	class ck_jeepwillys_cmd_v: ck_jeepwillys_base_v
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys de commandement";
		weapons[] = {"ck_jeepwillys_horn_w","ck_jeepwillys_siren_w"};
	};
	class ck_jeepwillys_cmd_mg_v: ck_jeepwillys_cmd_v
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys de commandement armée";
		model = "ck\ck_vehicles\ck_jeepwillys\ck_jeepwillys_mg.p3d";
	};
	class ck_jeepwillys_medical_v: ck_jeepwillys_base_v
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys médicale";
		hiddenSelections[] = {"camo","plate","hood"};
		hiddenSelectionsTextures[] =
		{
			"ck\ck_vehicles\ck_jeepwillys\data\ck_jeepwillys_co.paa",
			"ck\ck_vehicles\ck_jeepwillys\data\decals\ck_jeepwillys_plate_blank_co.paa",
			"ck\ck_vehicles\ck_jeepwillys\data\decals\ck_jeepwillys_hood_medical_ca.paa"
		};
	};
	class ck_jeepwillys_medical_mg_v: ck_jeepwillys_medical_v
	{
		scope = 2;
		scopeCurator = 2;
		author = "Noks";
		displayName = "Jeep Willys médicale armée";
		model = "ck\ck_vehicles\ck_jeepwillys\ck_jeepwillys_mg.p3d";
	};
};