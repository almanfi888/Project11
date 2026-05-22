#include <iostream>
using namespace std;

class Bclass {
public:
	Bclass(int i, int j) {
		x = i;
		y = j;
	}

	int fun() {
		return 0;
	}

protected:
	int x, y;
};

class Iclass : public Bclass {
private:
	int z;
public:
	Iclass(int i, int j, int k) : Bclass(i, j) {
		z = k;
	}

	int fun() {
		return (x + y + z) / 3;
	}
};


int main() {
	Iclass obj(2, 4, 10);
	Bclass p1 = obj;

	cout << p1.fun() << endl;

	return 0;



}