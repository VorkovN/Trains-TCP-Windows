#include "Station.h"

Station::Station(string name) {
	this->name = name;
}

Station::Station(string name, map<Train, int> trains) {
	this->name = name;
	this->trains = trains;
}

string Station::getName() {
	return name;
}
map<Train, int> Station::getTrains() {
	return trains;
};

bool operator< (Train tr1, Train tr2) {
	if (tr1.freight_type < tr2.freight_type) {
		return true;
	}
	else if(tr1.freight_type == tr2.freight_type && tr1.cars_count < tr2.cars_count){
		return true;
	}
	return false;
}

void Station::receive(int cars_count, string freight_type) {
	map<Train, int>::iterator train = findTrain(freight_type, cars_count);
	if (train != trains.end()) {
		train->second++;
	}
	else {
		trains[Train(freight_type, cars_count)] = 1;
	}
}
bool Station::send(int cars_count, string freight_type) {
	map<Train, int>::iterator train = findTrain(freight_type, cars_count);
	if (train == trains.end()) {
		return false;
	}
	else {
		trains.erase(train);
		return true;
	}
}

map<Train, int>::iterator Station::findTrain(string freight_type, int cars_count) {
	map<Train, int>::iterator train_it;
	for (train_it = trains.begin(); train_it != trains.end(); ++train_it) {//TODO (++train_it = trains.end)?
		if (train_it->first.cars_count == cars_count && train_it->first.freight_type == freight_type) {
			break;
		}
	}
	return train_it;
}
