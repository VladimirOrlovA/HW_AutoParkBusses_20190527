#pragma once
#include<string>
#include<iostream>
using namespace std;

class Bus
{
	string driverName;
	int busNumber;
	int route;
	string model;
	int	startYear;
	int kmAge;
public:
	Bus();
	Bus(string driverName, int busNumber, int route, string model, int	startYear, int kmAge);

	void setDriverName(string driverName) { this->driverName = driverName; }
	void setBusNumber(int busNumber) { this->busNumber = busNumber; }
	void setRoute(int route) { this->route = route; }
	void setModel(string model) { this->model = model; }
	void setStartYear(int startYear) { this->startYear = startYear; }
	void setKmAge(int kmAge) { this->kmAge = kmAge; }

	string getDriverName()const { return this->driverName; }
	int getBusNumber()const { return this->busNumber; }
	int getRoute()const { return this->route; }
	string getModel()const { return this->model; }
	int	getStartYear()const { return this->startYear; }
	int getKmAge()const { return this->kmAge; }

	void info() const;
	~Bus();
};

