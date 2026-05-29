#include <iostream>
using namespace std;
class vehicle {
protected:
	int wheels;
	double weight;
public:
	vehicle(int w, double ww) :wheels(w), weight(ww) {}
};
class car :private vehicle {
private:
	int passenger_load;
public:
	car(int w, double ww, int p) :vehicle(w, ww), passenger_load(p) {}
	void show() {
		cout << "car" << endl;
		cout << "wheels:" << wheels << endl;
		cout << "weight:" << weight << endl;
		cout << "passenger_load:" << passenger_load << endl;
	}
};
class truck :private vehicle {
private:
	int passenger_load;
	double payload;
public:
	truck(int w, double ww, int p, double pp) :vehicle(w, ww), passenger_load(p), payload(pp) {}
	void show() {
		cout << "truck" << endl;
		cout << "wheels:" << wheels << endl;
		cout << "weight:" << weight << endl;
		cout << "passenger_load:" << passenger_load << endl;
		cout << "payload:" << payload << endl;

	}
};
int main() {
	car myCar(4, 1500, 5);
	truck myTruck(6, 8000, 3, 20000);

	myCar.show();
	myTruck.show();
	return 0;

}


