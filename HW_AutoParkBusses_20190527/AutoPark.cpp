#include "AutoPark.h"

AutoPark::AutoPark() {}

void AutoPark::addBus(Bus * b)
{
	buses.push_back(b);
}

void AutoPark::listBusRoute(int routeNumber) const
{
	ofstream file("reportListBusRoute.csv");
	cout << "\n========================================================\n"
		<< "\n������ ��������� - " << routeNumber << " ��������\n"
		<< "\n������ ���������: \n\n";
	file << "\n========================================================\n"
		<< "\n������ ��������� - " << routeNumber << " ��������\n"
		<< "\n������ ���������: \n\n";
	for (Bus*b : buses)
	{
		if (b->getRoute() == routeNumber) {
			cout << b->getBusNumber() << endl;
			file << b->getBusNumber() << endl;
		}
	}
	file.close();
	cout << "\n--------------------------------------------------------\n";
	cout << "\n����� ������� � ���� reportListBusRoute.csv\n\n";
}

void AutoPark::listOperationYears(int currentYear) const
{
	ofstream file("reportListOperationYears.csv");
	cout << "\n========================================================\n"
		<< "\n������ ���������, ������� ��������������� ������ 10 ���\n"
		<< "\n������ ���������: \n\n";
	file << "\n========================================================\n"
		<< "\n������ ���������, ������� ��������������� ������ 10 ���\n"
		<< "\n������ ���������: \n\n";
	for (Bus*b : buses)
	{
		if ((currentYear - b->getStartYear()) > 10) {
			cout << b->getBusNumber() << " - ������ ������������:" << b->getStartYear()
				<< "�., � ������������ " << currentYear - b->getStartYear() << "���\n";
			file << b->getBusNumber() << " - ������ ������������:" << b->getStartYear()
				<< "�., � ������������ " << currentYear - b->getStartYear() << "���\n";
		}
	}
	file.close();
	cout << "\n--------------------------------------------------------\n";
	cout << "\n����� ������� � ���� reportListOperationYears.csv\n\n";
}

void AutoPark::listKmAge(int kmAge) const
{
	ofstream file("reportListKmAge.csv");
	cout << "\n========================================================\n"
		<< "\n������ ���������, ������ � ������� ������ " << kmAge << "��\n"
		<< "\n������ ���������: \n\n";
	file << "\n========================================================\n"
		<< "\n������ ���������, ������ � ������� ������ " << kmAge << "��\n"
		<< "\n������ ���������: \n\n";
	for (Bus*b : buses)
	{
		if (b->getKmAge() > kmAge) {
			cout << b->getBusNumber() << " - ������� ������: " << b->getKmAge() << "��\n";
			file << b->getBusNumber() << " - ������� ������: " << b->getKmAge() << "��\n";
		}
	}
	file.close();
	cout << "\n--------------------------------------------------------\n";
	cout << "\n����� ������� � ���� reportListKmAge.csv\n\n";
}

void AutoPark::info() const
{
	for (Bus*b : buses)
		b->info();
}

void AutoPark::loadAutoPark(string fileName)
{
	ifstream file(fileName);
	try {
		if (!file)
			throw exception("���� loadAutoParkData.csv �� ������ ��� ���������!");
	}
	catch (exception&error) {
		cout << "\n----------------------------------------------------------\n"
			<< "!!! ������: " << error.what()
			<< "\n----------------------------------------------------------\n\n";
		system("pause");
		exit(0);
	}
	string tmp;

	getline(file, tmp);
	while (!file.eof())
	{
		getline(file, tmp);

		Bus b("", 1, 1, "", 1, 1);

		if (tmp.size() > 0) {
			int pos = 0;
			b.setDriverName(tmp.substr(0, tmp.find(";")));
			pos = tmp.find(";") + 1;
			tmp = tmp.substr(pos);

			b.setBusNumber(stoi(tmp.substr(0, tmp.find(";"))));
			pos = tmp.find(";") + 1;
			tmp = tmp.substr(pos);

			b.setRoute(stoi(tmp.substr(0, tmp.find(";"))));
			pos = tmp.find(";") + 1;
			tmp = tmp.substr(pos);

			b.setModel(tmp.substr(0, tmp.find(";")));
			pos = tmp.find(";") + 1;
			tmp = tmp.substr(pos);

			b.setStartYear(stoi(tmp.substr(0, tmp.find(";"))));
			pos = tmp.find(";") + 1;
			tmp = tmp.substr(pos);

			b.setKmAge(stoi(tmp.substr(0, tmp.find(";"))));
		}
		else {
			break;
		}
		addBus(new Bus(b));
	}
	cout << "\n������ ������� ��������� �� ����� loadAutoParkData.csv \n\n";
}

void AutoPark::saveAutoPark()const
{
	ofstream file("saveAutoParkData.csv");
	for (Bus*b : buses) {
		file << b->getDriverName() << ";"
			<< b->getBusNumber() << ";"
			<< b->getRoute() << ";"
			<< b->getModel() << ";"
			<< b->getStartYear() << ";"
			<< b->getKmAge() << endl;

	}
	file.close();
	cout << "\n������ ������� �������� � ���� saveAutoParkData.csv \n\n";
	//Bus(string driverName, int busNumber, int route, string model, int	startYear, int kmAge)
}


AutoPark::~AutoPark()
{
	for (Bus*b : buses)
		delete b;
}
