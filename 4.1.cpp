#include <iostream>;
#include <math.h>;
#include <locale.h>;

using namespace std;

double pointDiff(double x1, double y1, double x2, double y2);

double pointDiff(double x1, double y1, double z1, double x2, double y2, double z2);

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "|-------------------------------------|" << endl;

	cout <<"|1)Двумерное пространство :           |" << endl;

	double a = pointDiff(-5.5, 1.3, -1.7, 2.1);

	double b = pointDiff(-9.9, 2.4, -5.2, 1.3);

	double c = pointDiff(-0.8, 1.2, -1.7, 1.6);

	double P = a + b + c;

	cout <<"|Периметр треугольника равен : " << P <<"|" << endl;

	cout<<"|-------------------------------------|"<<endl;

	cout <<"|2)Трёхмерное пространство :          |"<< endl;

	a = pointDiff(23.1, 1.1, 2.0, 2.0, 0.1, 5.4);

	b = pointDiff(22.1, 1.2, 5.0, 3.8, -1.0, 5.2);

	c = pointDiff(15.0, -1.1, 0.0, 2.5, 1.0, 9.3);

	P = a + b + c;

	cout <<"|Периметр треугольника равен : " << P <<"|"<< endl;

	cout << "|-------------------------------------|" << endl;

	return 0;
}
double pointDiff(double x1, double y1, double x2, double y2) {

	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
double pointDiff(double x1, double y1, double z1, double x2, double y2, double z2) {

	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}
