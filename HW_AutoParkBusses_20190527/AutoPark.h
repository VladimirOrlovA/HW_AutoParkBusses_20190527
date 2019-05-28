#pragma once
#include<vector>
#include<fstream>
#include<Windows.h>
#include"Bus.h"

class AutoPark
{
	vector<Bus*> buses;
public:
	AutoPark();
	void addBus(Bus*b);
	void listBusRoute(int busRoute) const;
	void listOperationYears(int currentYear) const;
	void listKmAge(int kmAge) const;
	void info()const;
	void loadAutoPark(string file);
	void saveAutoPark()const;
	~AutoPark();
};

