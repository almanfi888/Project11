#include<iostream>
using namespace std;
class fraction {
private:
	int zi;

	int mu;
public:
	fraction() {
		zi = 0; mu = 1;
	}
	fraction(int a, int b) {
		if (b < 0) {
			a = -a;
			b = -b;
		}
		if (b == 0) {
			cout << "错误：分母不能为0，已重置为1" << endl;
			b = 1;
		}
		int gcd0 = gcd(a, b);

		zi = a / gcd0;
		mu = b / gcd0;

	}
	int gcd(int a, int b) {
		a = abs(a);
		b = abs(b);

		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;  // 最终a即为GCD
	}
	int getzi()const {
		return zi;
	}
	int getmu()const {
		return mu;
	}

	friend fraction operator +(const fraction& d, const fraction& s);
	friend fraction operator -(const fraction& a, const fraction& s);
	friend fraction operator *(const fraction& a, const fraction& s);
	friend fraction operator /(const fraction& d, const fraction& s);

	friend	istream& operator >> (istream& in, fraction& s);
	friend ostream& operator <<(ostream& out, fraction& s);


};
fraction operator+(const fraction& ok, const fraction& s) {
	int zi1 = ok.getzi();
	int zi2 = s.getzi();
	int mu1 = ok.getmu();
	int mu2 = s.getmu();
	return fraction(zi1 * mu2 + zi2 * mu1, mu1 * mu2);
}
fraction operator-(const fraction& ok, const fraction& s) {
	int zi1 = ok.getzi();
	int zi2 = s.getzi();
	int mu1 = ok.getmu();
	int mu2 = s.getmu();
	return fraction(zi1 * mu2 - zi2 * mu1, mu1 * mu2);
}
fraction operator*(const fraction& ok, const fraction& s) {
	int zi1 = ok.getzi();
	int zi2 = s.getzi();
	int mu1 = ok.getmu();
	int mu2 = s.getmu();
	return fraction(zi1 * zi2, mu1 * mu2);
}
fraction operator/(const fraction& ok, const fraction& s) {
	int zi1 = ok.getzi();
	int zi2 = s.getzi();
	int mu1 = ok.getmu();
	int mu2 = s.getmu();
	return fraction(zi1 * mu2, zi2 * mu1);
}
ostream& operator<<(ostream& out, const fraction& s) {
	out << s.getzi() << "/" << s.getmu();
	return out;
}
istream& operator>>(istream& in,   fraction& s) {
	char a;
	in >> s.zi >> a >> s.mu;
	return in;
}
int main() {
	fraction f1, f2;

	cout << "请输入第一个分数: ";
	cin >> f1;

	cout << "请输入第二个分数: ";
	cin >> f2;

	cout << "加法结果: " << f1 + f2 << endl;
	cout << "减法结果: " << f1 - f2 << endl;
	cout << "乘法结果: " << f1 * f2 << endl;
	cout << "除法结果: " << f1 / f2 << endl;

	return 0;
}
