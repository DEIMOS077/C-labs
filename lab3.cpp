#include <iostream>
#include <string>
#include<locale.h>
using namespace std;

class Goods {
	string name;
	string date;
	int cost;
	int num;
	int id;
public:
	Goods(string _name, string _date, int _cost, int _num, int _id) {
		name = _name;
		date = _date;
		cost = _cost;
		num = _num;
		id = _id;
		cout << "Counstructor" << endl;
	}
	Goods() {
		name = "Unkown";
		date = "0000-00-00";
		cost = 0;
		num = 0;
		id = 0;
		cout << "Default constructor" << endl;
	}
	Goods(Goods& _ob) {
		name = _ob.name;
		date = _ob.date;
		cost = _ob.cost;
		num = _ob.num;
		id = _ob.id;
		cout << "CopyCounstructor" << endl;
	}
	~Goods() {
		cout << "Destructor" << endl;
	};

public:
	void Show() {
		cout << endl << "Наименование товара: " << name << endl;
		cout << "Дата оформления товара: " << date << endl;
		cout << "Цена товара: " << cost << endl;
		cout << "Количество единиц товара: " << num << endl;
		cout << "Номер накладной: " << id << endl << endl;
	}

	Goods operator=(Goods& _ob);

};

Goods tovar(Goods& _s) {
	return _s;
}

Goods Goods::operator=(Goods& _ob) {
	name = _ob.name;
	date = _ob.date;
	cost = _ob.cost;
	num = _ob.num;
	id = _ob.id;
	cout << "Operator" << endl;
	return *this;
}


int main() {
	setlocale(LC_ALL, "Russian");
	Goods comp1("ASUS", "13.13.2021", 200, 10, 486);
	Goods comp2(comp1);
	Goods comp3;
	tovar(comp2);
	comp1 = comp3;
	comp1.Show();
	comp2.Show();
	return 0;
}
