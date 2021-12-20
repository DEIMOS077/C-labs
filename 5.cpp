#include <iostream>;
#include <locale.h>;

using namespace std;

void fer() {
	cout << "Global" << endl;
}

class BASE {
	friend class DERIVED;
public: int i;
protected: long l;
private: double d;
public:
	BASE(int _i, long _l, double _d) {
		i = _i;
		l = _l;
		d = _d;
	}
	BASE() {
		i = 0;
		l = 0;
		d = 0;
	}
	~BASE() {}

	double GetD() {
		return d;
	}

	void SetD(double _d) {
		d = _d;
	}

	void fer() {
		cout << "BASE" << endl;
	}

	double* GetAdressD() {
		return &d;
	}

	int* GetAdressI() {
		return &i;
	}

	long* GetAdressL() {
		return &l;
	}
};

class DERIVED : public BASE {
private:
	float f;
public:
	DERIVED(float _f, int _i, long _l, double _d) :BASE(_i, _l, _d) {
		f = _f;
		i = _i;
		l = _l;
		d = _d;
	}
	DERIVED() {
		f = 0;
	}
	float* GetAddresF() {
		return &f;
	}
	void Show() {
		cout << f;
	}
	void fer() {
		cout << "DERIVED" << endl;
	}
	friend class DERIVED_1;
	friend ostream& operator<<(ostream& out, DERIVED& ob);
};

ostream& operator<<(ostream& out, DERIVED& ob) {

	out << ob.f << " " << ob.i << " " << ob.l << " " << ob.GetD() << endl;
	out << ob.GetAddresF() << " " << ob.GetAdressI() << " " << ob.GetAdressL() << " " << ob.GetAdressD();
	return out;
}

class DERIVED_1 : public DERIVED {
public:
	DERIVED_1(float _f, int _i, long _l, double _d) :DERIVED(_f, _i, _l, _d) {
		f = _f;
		i = _i;
		l = _l;
		SetD(_d);
	}
	void fokl() {
		i++;
		l += 1;
		fer();
	}
	void fer() {
		cout << "_DERIVED_" << endl<<"--------------------------"<<endl;
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	DERIVED_1 ob1(10, 20, 30, 40);
	ob1.fokl();
	cout << "Размер BASE : " << sizeof(BASE) << endl;
	cout << "Размер DERIVED : " << sizeof(DERIVED) << endl<<"--------------------------"<<endl;
	cout << ob1;
	return 0;
}