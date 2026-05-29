#include <iostream>
#include <string>
using namespace std;
class person {
protected:

	char* xm;
	char* xb;
	int age;
public:
	friend ostream& operator<<(ostream& out, person& s) {
		out << "姓名:" << s.xm << "性别：" << s.xb << "年龄:" << s.age;
		return out;
	}
	friend istream& operator>>(istream& in, person& s) {
		char name[20];
		cout << "请输入姓名：";
		in >> name;
		s.xm = new char[strlen(name) + 1];
		strcpy_s(s.xm, strlen(name) + 1, name);		char sex[20];
		cout << "请输入性别：";
		in >> sex;
		s.xb = new char[strlen(sex) + 1];
		strcpy_s(s.xb, strlen(sex) + 1, sex);
		cout << "请输入年龄：";
		in >> s.age;
		return in;
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
	friend istream& operator>>(istream& in, student& s) {
		char name[20];
		cout << "请输入姓名：";
		in >> name;
		s.xm = new char[strlen(name) + 1];
		strcpy_s(s.xm, strlen(name) + 1, name);		char sex[20];
		cout << "请输入性别：";
		in >> sex;
		s.xb = new char[strlen(sex) + 1];
		strcpy_s(s.xb, strlen(sex) + 1, sex);
		cout << "请输入年龄：";
		in >> s.age;
		cout << "请输入学号：";
		cin >> s.xuehao;
		cout << "请输入班级：";
		cin >> s.banji;
		cout << "请输入专业：";
		char zy[20];
		cin >> zy;
		s.zhuanye = new char[strlen(zy) + 1];
		strcpy_s(s.zhuanye, strlen(zy) + 1, zy);
		cout << "请输入入学成绩：";
		cin >> s.rxcj;
		return in;
	}
	friend ostream& operator<<(ostream& out, student& s) {
		out << "姓名:" << s.xm << "性别：" << s.xb << "年龄:" << s.age;
		out << "学号：" << s.xuehao << "班级：" << s.banji << "专业：" << s.zhuanye << "入学成绩：" << s.rxcj;
		return out;
	}
	~student() {
		delete[] zhuanye;
	}
};
int main() {
	student s;

	cin >> s;


	cout << s;
	return 0;

}


