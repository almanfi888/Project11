#include <iostream>
#include <string>
using namespace std;
class person {
private:

	char* xm;
	char* xb;
	int age;
public:
	void set_p() {
		char name[20];
		cout << "请输入姓名：";
		cin >> name;
		xm = new char[strlen(name) + 1];
		strcpy_s(xm, strlen(name) + 1, name);
		char sex[20];
		cout << "请输入性别：";
		cin >> sex;
		xb = new char[strlen(sex) + 1];
		strcpy_s(xb, strlen(sex) + 1, sex);
		cout << "请输入年龄：";
		cin >> age;
	}
	void display_p() {
		cout << "姓名:" << xm << "性别：" << xb << "年龄:"<<age;
	}
	~person() {
		delete[] xm;
		delete[] xb;
	}

};
class student :public person {
private:
	int xuehao;
	int banji;
	char* zhuanye;
	int rxcj;
public:
	void set_t() {
		set_p();
		cout << "请输入学号：";
		cin >> xuehao;
		cout << "请输入班级：";
		cin >> banji;
		char zy[20];
		cout << "请输入专业：";
		cin >> zy;
		zhuanye = new char[strlen(zy) + 1];
		strcpy_s(zhuanye, strlen(zy) + 1, zy);
		cout << "请输入入学成绩：";
		cin >> rxcj;
	}
	void display_s() {
		display_p();
		cout << "学号：" << xuehao << "班级：" << banji << "专业：" << zhuanye << "入学成绩：" << rxcj;
	}
	~student() {
		delete[]zhuanye;
	}
};
int main() {
	student s;   
	s.set_t(); 

	s.display_s();

	return 0;

}


