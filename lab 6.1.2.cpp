#include <iostream>;
#include <string>;
#include <locale.h>;

using namespace std;

class DomesticAnimal {
protected:
	int price;
	int weight;
	string color;

public:
	DomesticAnimal() {
		price = 0;
		weight = 0;
		color = "black";
	}

	DomesticAnimal(int _price, int _weight, string _color) {
		price = _price;
		weight = _weight;
		color = _color;
	}

	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "Class domestic ";
	}

};

class Cow : virtual public DomesticAnimal {
public:
	Cow() {};
	Cow(int _price, int _weight, string _color) : DomesticAnimal(_price, _weight, _color) {}

	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "Class Cow ";
	}
};

class Buffalo : virtual public DomesticAnimal {
public:
	Buffalo() {};
	Buffalo(int _price, int _weight, string _color) : DomesticAnimal(_price, _weight, _color) {}

	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "Class Buffalo ";
	}
};

class Beefalo : public Cow, public Buffalo {
public:
	Beefalo(int _price, int _weight, string _color) {
		price = _price;
		weight = _weight;
		color = _color;
	}
	void Print() {
		cout << price << "  " << weight << "  " << color << "  ";
		cout << "class Beefalo ";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "это лаба 6.1.2" << endl;
	Cow a(1, 1, "red");
	Beefalo b(2, 2, "blue");
	a.Print();
	b.Print();

	return 0;
}
