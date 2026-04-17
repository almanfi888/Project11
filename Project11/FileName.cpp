#include <iostream>
using namespace std;
class sjx {
private:
	double d;
	double h;
public:

	sjx() {
		d = 0;
		h = 0;
	}
	sjx(double x, double y) :d(x), h(y) {}
	bool operator>(const sjx& a) {
		return d
			* h > a.d * a.h;


	}
	bool operator>=(const sjx& a) {
		return d * h >= a.d * a.h;

	}
	bool operator<(const sjx& a) {
		return d * h < a.d * a.h;

	}
	bool operator<=(const sjx& a) {
		return d * h <= a.d * a.h;

	}
	bool operator==(const sjx& a) {
		return d * h == a.d * a.h;

	}
	bool operator!=(const sjx& a) {
		return d * h != a.d * a.h;

	}

};

int main() {


	sjx s1(2, 6);
	sjx s2(3, 5);

	if (s1 > s2)  cout << "s1 > s2 成立" << endl;
	if (s1 >= s2) cout << "s1 >= s2 成立" << endl;
	if (s1 < s2)  cout << "s1 < s2 成立" << endl;
	if (s1 <= s2) cout << "s1 <= s2 成立" << endl;
	if (s1 == s2) cout << "s1 == s2 成立" << endl;
	if (s1 != s2) cout << "s1 != s2 成立" << endl;

	return 0;
}