#pragma once
#include <string>
using namespace std;

class Train
{	
public:

	Train(const string freight_type, const int cars_count) : freight_type(freight_type), cars_count(cars_count){};

public:

	const string freight_type;
	const int cars_count;

};