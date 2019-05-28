#include"Bus.h"
#include"AutoPark.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	AutoPark b;

	/*b.addBus(new Bus("������ �.�.", 3152, 32, "Man", 2004, 9585));
	b.addBus(new Bus("������� �.�.", 4512, 67, "Man", 2005, 10156));
	b.addBus(new Bus("����� �.�.", 5615, 95, "Man", 2010, 5600));
	b.addBus(new Bus("������� �.�.", 1515, 32, "Man", 2005, 7865));
	b.addBus(new Bus("������� �.�.", 4032, 67, "Man", 2003, 10256));
	b.addBus(new Bus("�������� �.�.", 2125, 48, "Man", 2001, 11585));*/

	b.loadAutoPark("loadAutoParkData.csv"); // ���������� ������ � ���� � �������� �� �����.
	b.saveAutoPark();
	b.info();

	b.listBusRoute(32); // ����� ������ ��������� ��� ��������� ������ ��������; 
	b.listOperationYears(2019); //����� ������ ���������, ������� ��������������� ������ 10 ���;
	b.listKmAge(10000); //����� ������ ���������, ������ � ������� ������ 10000 ��;

	system("pause");
}