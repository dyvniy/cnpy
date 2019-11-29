// parce.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "data.h"
#include "../npy/cnpy.h"

using namespace std;

//vector<string> split(const string& s, const string sep = ",", int imax = 83) {
//	vector<string> out;
//	size_t old = 0;
//	size_t pos = s.find(sep, old);
//	int maxI = imax;
//	while ( pos > 0  && maxI > 0) {
//		out.push_back(s.substr(old+1, pos - old));
//		old = pos + 1;
//		if (old >= s.size()) {
//			old = s.size();
//		}
//		pos = s.find(",", old);
//		maxI--;
//	}
//	return out;
//}

size_t split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, fmin(pos, txt.size()) - initialPos + 1));

	return strs.size();
}

struct Int {
	int i;
	Int()
		:i(0)
	{}
	Int(int a)
		:i(a)
	{}
	int operator++(int) {
		return ++i;
	}
	operator int() {
		return i;
	}
};

ostream& operator << (ostream& os, unordered_map < string, Int> um) {
	for (pair<string, Int> p : um) {
		os << p.first << ":" << p.second.i << ", ";
	}
	return os;
}

vector<string> get_spl()
{
	string line{ "MachineIdentifier,ProductName,EngineVersion,AppVersion,AvSigVersion,IsBeta,"
		"RtpStateBitfield,IsSxsPassiveMode,DefaultBrowsersIdentifier,AVProductStatesIdentifier,"
		"AVProductsInstalled,AVProductsEnabled,HasTpm,CountryIdentifier,CityIdentifier,"
		"OrganizationIdentifier,GeoNameIdentifier,LocaleEnglishNameIdentifier,Platform,Processor,"
		"OsVer,OsBuild,OsSuite,OsPlatformSubRelease,OsBuildLab,SkuEdition,IsProtected,"
		"AutoSampleOptIn,PuaMode,SMode,IeVerIdentifier,SmartScreen,Firewall,UacLuaenable,"
		"Census_MDC2FormFactor,Census_DeviceFamily,Census_OEMNameIdentifier,"
		"Census_OEMModelIdentifier,Census_ProcessorCoreCount,Census_ProcessorManufacturerIdentifier,"
		"Census_ProcessorModelIdentifier,Census_ProcessorClass,Census_PrimaryDiskTotalCapacity,"
		"Census_PrimaryDiskTypeName,Census_SystemVolumeTotalCapacity,Census_HasOpticalDiskDrive,"
		"Census_TotalPhysicalRAM,Census_ChassisTypeName,Census_InternalPrimaryDiagonalDisplaySizeInInches,"
		"Census_InternalPrimaryDisplayResolutionHorizontal,Census_InternalPrimaryDisplayResolutionVertical,"
		"Census_PowerPlatformRoleName,Census_InternalBatteryType,Census_InternalBatteryNumberOfCharges,"
		"Census_OSVersion,Census_OSArchitecture,Census_OSBranch,Census_OSBuildNumber,Census_OSBuildRevision,"
		"Census_OSEdition,Census_OSSkuName,Census_OSInstallTypeName,Census_OSInstallLanguageIdentifier,"
		"Census_OSUILocaleIdentifier,Census_OSWUAutoUpdateOptionsName,Census_IsPortableOperatingSystem,"
		"Census_GenuineStateName,Census_ActivationChannel,Census_IsFlightingInternal,Census_IsFlightsDisabled,"
		"Census_FlightRing,Census_ThresholdOptIn,Census_FirmwareManufacturerIdentifier,"
		"Census_FirmwareVersionIdentifier,Census_IsSecureBootEnabled,Census_IsWIMBootEnabled,"
		"Census_IsVirtualDevice,Census_IsTouchEnabled,Census_IsPenCapable,Census_IsAlwaysOnAlwaysConnectedCapable"
		",Wdft_IsGamer,Wdft_RegionIdentifier,HasDetections" };
	vector<string> spl;
	split(line, spl, ',');
	cout << spl.size() << endl;
	return spl;
}

void saveMaps(ofstream& ofs, const vector<unordered_map<string, Int>>& varios) {
	auto spl = get_spl();
	for (int i = 1; i < varios.size(); ++i) {
		ofs << endl << spl[i] << endl << i << ": " << varios[i].size() << endl << varios[i] << endl;
		//cout << endl << i << ": " << varios[i].size() << " " << varios[i] << endl;
	}
}

void fillVarios(vector<unordered_map<string, Int>>& varios) {
	int i = 0;
	for (int k = 0; k < 83; ++k) {
		varios.push_back(unordered_map<string, Int>());
	}
	//cout << endl;
	string s(" ");
	ifstream fs(L"../../train.csv");
	if (!fs.is_open()) {
		return;
	}
	getline(fs, s); // head
	while (!fs.eof() && s.size() > 0) {
		getline(fs, s);
		vector<string> spl;
		split(s, spl, ',');
		int j = 0;
		for (string w : spl) {
			//cout << j << " ";
			varios[j][w]++;
			j++;
		}
		i++;
		if (i % 1000000 == 0) {
			cout << i << " " << s.size() << " ";
		}
	}
	ofstream ofs("../../maps.txt");
	saveMaps(ofs, varios);
}

vector<unordered_map<string, Int>> loadVarios() {
	vector<unordered_map<string, Int>> varios;
	ifstream ifs("../../maps.txt");
	string s(" ");
	if (!ifs.is_open()) {
		return varios;
	}
	while (!ifs.eof() && s.size() > 0) {
		string empty, name, smap;
		getline(ifs, empty); // empty
		getline(ifs, name); // name
		getline(ifs, s); // name
		getline(ifs, smap); // map

		cout << s << endl;
		unordered_map<string, Int> map;
		vector<string> spl;
		split(smap, spl, ',');
		for (string w : spl) {
			vector<string> w2;
			split(w, w2, ':');
			if (w2.size() == 2) {
				map[w2[0]] = atoi(w2[1].c_str());
			}
			else {
				cout << w2.size() << " ";
			}
		}
		varios.push_back(map);
	}
	for (auto m : varios) {
		cout << m.size() << " ";
	}
	cout << endl;
	return varios;
}

int csvToBytes(wstring inFile, vector<unordered_map<string, Int>>& numbers, vector<int> bytesNeed, wstring outFile) {
	ifstream ifs(inFile);
	ofstream ofs(outFile);
	string s(" ");
	if (!ifs.is_open()) {
		return -1;
	}
	if (!ofs.is_open()) {
		return -2;
	}
	int i = 0;
	getline(ifs, s); // head
	while (!ifs.eof() && s.size() > 0) {
		getline(ifs, s); 
		vector<string> spl;
		split(s, spl, ',');
		int j = -1;
		string line;
		for (string w : spl) {
			if (j == -1) {
				line += w; // code
			} else {
				int bn = bytesNeed[j];
				unordered_map<string, Int>& map = numbers[j];
				int nb = map[w];
				line += char(nb % 256);
				if (bn > 1) {
					line += char(int(nb / 256) % 256);
				}
				if (bn > 2) {
					line += char(int(nb / 256 / 256) % 256);
				}
			}
			j++;
		}
		ofs << line << "\n";
		i++;
		if (i % 1000000 == 0) {
			cout << i << " " << s.size() << " ";
		}
	}
	cout << endl << i << endl;
	return 0;
}

int csvToNumpy(wstring inFile, vector<unordered_map<string, Int>>& numbers, 
	vector<int> bytesNeed, 
	string outFile, int maxCount = INT_MAX) 
{
	if (bytesNeed.size() == 0) {
		printf("need more bytes\n");
		return -1;
	}
	ifstream ifs(inFile);
	//ofstream ofs(outFile);
	string s(" ");
	if (!ifs.is_open()) {
		return -1;
	}
	size_t i = 0;
	getline(ifs, s); // head
	//vector<vector<float>> batch;
	//vector<vector<float>> batchi;
	vector<float> line;
	vector<float> linei;
	while (!ifs.eof() && s.size() > 0 && i < maxCount) {
		getline(ifs, s);
		vector<string> spl;
		split(s, spl, ',');
		int j = -1;
		for (string w : spl) {
			if (j == -1) {
				for (char ch : w) {
					line.push_back(ch/256.0); // code
				}
			}
			else {
				int bn = bytesNeed[j];
				unordered_map<string, Int>& map = numbers[j];
				line.push_back(map[w]*1.0f/map.size());
			}
			j++;
		}
		linei.push_back(*(line.end() - 1));
		line.pop_back();
		//save it to file
		if (line.size() < 2) { // wrong lines
			continue;
		}
		//batch.push_back(line);
		//batchi.push_back(linei);
		i++;
		if (i % 1000000 == 0) {
			cout << i << " " << s.size() << " ";
			cnpy::npy_save(outFile + ".npy", &line[0], { 1000000, 113 }, "a");
			cnpy::npy_save(outFile + "_i.npy", &linei[0], { 1000000 }, "a");
			line = vector<float>();
			linei = vector<float>();
		}
	}
	cnpy::npy_save(outFile + "_test.npy", &line[0], { i%1000000, 113 }, "a");
	cnpy::npy_save(outFile + "_i_test.npy", &linei[0], { i%1000000 }, "a");
	cout << endl << i << endl;
	return 0;
}


int main()
{
    std::cout << "Hello World!\n";
	vector<unordered_map<string, Int>> varios = loadVarios();
	if (varios.size() == 0) {
		fillVarios(varios);
	}
	vector<unordered_map<string, Int>> numbers;
	vector<int> bytesNeed;
	int sum = 0;
	for (auto v: varios) {
		int sz = v.size();
		int n = int(log(sz)/log(256))+1;
		bytesNeed.push_back(n);
		sum += n;
		cout << sz << ":" << n << " ";
		unordered_map<string, Int> num;
		int i = 0;
		for (pair<string, Int> p : v) {
			num[p.first] = i;
			i++;
		}
		numbers.push_back(num);
	}
	ofstream ofs("../../mapsN.txt");
	saveMaps(ofs, numbers);

	//csvToBytes(L"../../train.csv", numbers, bytesNeed, L"../../train2.bin");
	csvToNumpy(L"../../train.csv", numbers, bytesNeed, "../../train6");// , 100000);

	cout << endl << sum;
	//fillVarios(varios);
	cout << "\nfinish\n" ;
	getchar();
}

