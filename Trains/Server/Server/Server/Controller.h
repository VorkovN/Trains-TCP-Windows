#pragma once
#include "Station.h"
#include <vector>
#include <string>

using namespace std;

class Controller{

public:

	//bool checkStation(string name);
	//
	//Station& findStation(string name);

	vector<Station>::iterator findStation(string name);

	bool order(string from, string to, string freight_type, int cars_count);

	bool chooseTrain(string from, string to, string freight_type, int volume);

private:

	vector<Station> stations = { Station("Moscow"),Station("SPB") };// инициаллизация начальных городов

};

