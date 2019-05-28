#include"Bus.h"
#include"AutoPark.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	AutoPark b;

	/*b.addBus(new Bus("Леонов П.Н.", 3152, 32, "Man", 2004, 9585));
	b.addBus(new Bus("Малыгин Н.И.", 4512, 67, "Man", 2005, 10156));
	b.addBus(new Bus("Журов О.М.", 5615, 95, "Man", 2010, 5600));
	b.addBus(new Bus("Потапов М.С.", 1515, 32, "Man", 2005, 7865));
	b.addBus(new Bus("Зарубин О.Н.", 4032, 67, "Man", 2003, 10256));
	b.addBus(new Bus("Ларионов П.Н.", 2125, 48, "Man", 2001, 11585));*/

	b.loadAutoPark("loadAutoParkData.csv"); // сохранение данных в файл и загрузку из файла.
	b.saveAutoPark();
	b.info();

	b.listBusRoute(32); // вывод списка автобусов для заданного номера маршрута; 
	b.listOperationYears(2019); //вывод списка автобусов, которые эксплуатируются больше 10 лет;
	b.listKmAge(10000); //вывод списка автобусов, пробег у которых больше 10000 км;

	system("pause");
}