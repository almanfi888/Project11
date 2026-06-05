#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const double pi = 3.14;
class shape {
public:
	double x, y;
	shape() :x(0), y(0) {}


};
class yuan :public shape {
private:
	double r;
public:

	friend ostream& operator<<(ostream& out, yuan& s) {
		out << fixed << setprecision(2) << s.perimeter() << " ";
		return out;
	}

	friend istream& operator>>(istream& in, yuan& s) {
		in >> s.r;
		return in;
	}

	double perimeter() {
		return 2 * pi * r;
	}
};
class cfx :public shape {
private:
	double a, b;
public:
	friend ostream& operator<<(ostream& out, cfx& s) {
		out << fixed << setprecision(2) << s.perimeter() << " ";
		return out;
	}
	friend istream& operator>>(istream& in, cfx& s) {
		in >> s.a >> s.b;
		return in;
	}

	double perimeter() {
		return 2 * a + 2 * b;
	}

};
class sjx :public shape {
private:
	double a, b, c;
public:
	friend ostream& operator<<(ostream& out, sjx& s) {
		out << fixed << setprecision(2) << s.perimeter()<<" ";
		return out;
	}
	friend istream& operator>>(istream& in, sjx& s) {
		in >> s.a >> s.b >> s.c;
		return in;
	}
	double perimeter() { return a + b + c; }
};
int main() {
	yuan a;
	sjx b;
	cfx c;
	cin >> a >> b >> c;
	cout << a << b << c;
	return 0;
}


