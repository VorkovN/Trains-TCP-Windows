#pragma once
#include <map>
#include "Train.h"

using namespace std;

bool operator< (Train tr1, Train tr2);

class Station{
public:

	string getName();
	map<Train, int> getTrains();

	Station(string name);
	Station(string name, map<Train, int> trains);

	void receive(int cars_count, string freight_type);
	bool send(int cars_count, string freight_type);

	map<Train, int>::iterator findTrain(string freight_type, int cars_count);

private:
	string name;
	map<Train, int> trains;
};

