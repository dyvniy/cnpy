#pragma once

#include <string>
#include <sstream>

using namespace std;

struct Version {
	static stringstream ss;
	int main;
	int sub1;
	int sub2;
	int sub3;
	Version(string s) {
		// for init
	}
};

struct Data {
	string MachineIdentifier;									// 00 // 000007535c3f730efa9ea0b7ef1bd645
	string ProductName;											// 01 // win8defender
	Version EngineVersion;										// 02 // 1.1.14600.4
	Version AppVersion;											// 03 // 4.13.17134.1
	Version AvSigVersion;										// 04 // 1.263.48.0
	bool IsBeta;												// 05 // 0
	int	RtpStateBitfield;										// 06 // 7
	int	IsSxsPassiveMode;										// 07 // 0
	string DefaultBrowsersIdentifier;							// 08 // ""
	int AVProductStatesIdentifier;								// 09 // 53447
	bool AVProductsInstalled;									// 10 // 1
	bool AVProductsEnabled;										// 11 // 1
	bool HasTpm;												// 12 // 1
	int CountryIdentifier;										// 13 // 93
	int	CityIdentifier;											// 14 // 1482
	int	OrganizationIdentifier;									// 15 // 18
	int	GeoNameIdentifier;										// 16 // 119
	int	LocaleEnglishNameIdentifier;							// 17 // 64
	string Platform;											// 18 // windows10
	string Processor;											// 19 // x64
	Version OsVer;												// 20 // 10.0.0.0 
	int OsBuild;												// 21 // 17134
	int OsSuite;												// 22 // 256
	string OsPlatformSubRelease;								// 23 // rs4
	string OsBuildLab;											// 24 // 17134.1.amd64fre.rs4_release.180410-1804
	string SkuEdition;											// 25 // Pro
	bool IsProtected;											// 26 // 1
	bool AutoSampleOptIn;										// 27 // 0
	string PuaMode;												// 28 // ""
	bool SMode;													// 29 // 0
	int IeVerIdentifier;										// 30 // 137
	string SmartScreen;											// 31 // ""
	bool Firewall;												// 32 // 1
	bool UacLuaenable;											// 33 // 1
	string Census_MDC2FormFactor;								// 34 // Notebook
	string Census_DeviceFamily;									// 35 // Windows.Desktop
	int Census_OEMNameIdentifier;								// 36 // 2668
	int Census_OEMModelIdentifier;								// 37 // 91656
	int Census_ProcessorCoreCount;								// 38 // 4
	int Census_ProcessorManufacturerIdentifier;					// 39 // 5
	int Census_ProcessorModelIdentifier;						// 40 // 2405
	string Census_ProcessorClass;								// 41 // ""
	int Census_PrimaryDiskTotalCapacity;						// 42 // 476940
	string Census_PrimaryDiskTypeName;							// 43 // HDD 
	int Census_SystemVolumeTotalCapacity;						// 44 // 102385
	int Census_HasOpticalDiskDrive;								// 45 // 0
	int Census_TotalPhysicalRAM;								// 46 // 4096
	string Census_ChassisTypeName;								// 47 // Notebook
	float Census_InternalPrimaryDiagonalDisplaySizeInInches;	// 48 // 13.9
	int Census_InternalPrimaryDisplayResolutionHorizontal;		// 49 // 1366
	int	Census_InternalPrimaryDisplayResolutionVertical;		// 50 // 768
	string Census_PowerPlatformRoleName;						// 51 // Mobile
	bool Census_InternalBatteryType;							// 53 // ""
	string Census_InternalBatteryNumberOfCharges;				// 54 // 1
	string Census_OSVersion;									// 55 // 10.0.17134.1
	string Census_OSArchitecture;								// 56 // amd64
	int Census_OSBranch;										// 57 // rs4_release
	int Census_OSBuildNumber;									// 58 // 17134
	string Census_OSBuildRevision;								// 58 // 1
	string Census_OSEdition;									// 59 // Professional
	string Census_OSSkuName;									// 60 // PROFESSIONAL
	string Census_OSInstallTypeName;									// 61 // IBSClean
	int Census_OSInstallLanguageIdentifier;						// 62 // 8
	int Census_OSUILocaleIdentifier;							// 63 // 31
	string Census_OSWUAutoUpdateOptionsName;						// 64 // UNKNOWN
	int Census_IsPortableOperatingSystem;						// 65 // 0
	string Census_GenuineStateName;								// 66 // OFFLINE
	string Census_ActivationChannel;								// 67 // Retail
	string Census_IsFlightingInternal;								// 68 // ""
	bool Census_IsFlightsDisabled;								// 69 // 0
	string Census_FlightRing;										// 70 // NOT_SET
	string Census_ThresholdOptIn;									// 71 // ""
	int Census_FirmwareManufacturerIdentifier;					// 72 // 628
	int Census_FirmwareVersionIdentifier;						// 73 // 57858
	bool Census_IsSecureBootEnabled;								// 74 // 0
	string Census_IsWIMBootEnabled;								// 75 // ""
	bool Census_IsVirtualDevice;									// 76 // 0
	bool Census_IsTouchEnabled;									// 77 // 0
	bool Census_IsPenCapable;									// 78 // 0
	bool Census_IsAlwaysOnAlwaysConnectedCapable;				// 79 // 0
	bool Wdft_IsGamer;											// 80 // 0
	int Wdft_RegionIdentifier;									// 81 // 8
	bool HasDetections;										// 82 // 0
};