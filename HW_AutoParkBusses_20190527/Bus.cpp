#include "Bus.h"



Bus::Bus()
{
	this->driverName = driverName;
	this->busNumber = busNumber;
	this->route = route;
	this->model = model;
	this->startYear = startYear;
	this->kmAge = kmAge;
}

Bus::Bus(string driverName, int busNumber, int route, string model, int	startYear, int kmAge)
{
	this->driverName = driverName;
	this->busNumber = busNumber;
	this->route = route;
	this->model = model;
	this->startYear = startYear;
	this->kmAge = kmAge;
}

void Bus::info() const
{
	cout << "\n==============================\n"
		<< "\n Имя водителя - " << driverName
		<< "\n Номер автобуса - " << busNumber
		<< "\n Маршрут - " << route
		<< "\n Модель - " << model
		<< "\n Год начала эксплуатации - " << startYear << "г."
		<< "\n Пробег - " << kmAge << "км \n\n";
}


Bus::~Bus()
{
}
