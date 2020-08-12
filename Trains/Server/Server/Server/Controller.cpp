#include "Controller.h"

//bool Controller::checkStation(string name) {
//	for (Station station : stations) {
//		if (station.getName() == name) {
//			return true;
//		}
//	}
//	return false;
//}
//		
//Station& Controller::findStation(string name) {
//	for (Station station : stations) {
//		if (station.getName() == name) {
//			return station;
//		}
//	}
//}

vector<Station>::iterator Controller::findStation(string name) {
	vector<Station>::iterator station_it;
	for (station_it = stations.begin(); station_it < stations.end(); ++station_it) {
		if (station_it->getName() == name) {
			break;
		}
	}
	return station_it;
}


bool Controller::chooseTrain(string from, string to, string freight_type, int volume) {
	return order(from, to, freight_type, int(volume/1));//138
}

bool Controller::order(string from, string to, string freight_type, int cars_count) {
	if (findStation(from) == stations.end()) {
		stations.push_back(Station(to));
	}
	vector<Station>::iterator findStationIt = findStation(from);
	if (findStationIt != stations.end()) {
		if (findStationIt->send(cars_count, freight_type)) {
			findStation(to)->receive(cars_count, freight_type);
			return true;
		}
	}
	return false;

};


