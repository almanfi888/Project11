#include <iostream>
using namespace std;
class Building {
protected:
	int ceng;
	int fangjian;
public:
	Building(int c,int cc):ceng(c),fangjian(cc){}
};
class Housing :public Building {
private:
	int woshi;
	int yushi;
public:
	Housing(int c, int cc, int w, int ww):Building(c, cc), woshi(w), yushi(ww){}

	void show() {
		cout << "层数：" << ceng<< endl;
		cout << "房间数：" << fangjian<< endl;
		cout << "卧室数：" << woshi<< endl;
		cout << "浴室数：" << yushi<< endl;
	}
};
class Office :public Building {
private:
	int miehuo;
	int phone;
public:
	Office(int c,int cc,int m,int mm):Building(c,cc),miehuo(m),phone(mm){}
	void show() {
		cout << "层数：" << ceng<< endl;
		cout << "房间数：" << fangjian<< endl;
		cout << "灭火器数：" << miehuo<< endl;
		cout << "电话数：" << phone<< endl;
	}
};

int main() {
	Housing house(6, 12, 8, 4);
	cout << "===== 住宅楼信息 =====" << endl;
	house.show();

	cout << endl;

	// 创建办公楼对象
	Office office(10, 30, 20, 50);
	cout << "===== 办公楼信息 =====" << endl;
	office.show();

	return 0;
}


