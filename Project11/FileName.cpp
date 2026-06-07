#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
	int bh;         
	string name;    
public:
	employee(int bh0, string name0) :bh(bh0), name(name0) {}


	virtual ~employee() {}


	virtual double getsalary() = 0;
	virtual void showinfo() = 0;
};


class manager : public employee {
protected:
	double yuexin;
public:
	manager(int bh0, string name0, double yuexin0)
		: employee(bh0, name0), yuexin(yuexin0) {}

	double getsalary() override {
		return yuexin;
	}

	void showinfo() override {
		cout << "【管理人员】" << endl;
		cout << "编号：" << bh << "\t姓名：" << name << endl;
		cout << "固定月薪：" << getsalary() << " 元" << endl << endl;
	}
};


class hourlyworker : public employee {
protected:
	double shixin;  
	int hour;        
public:

	hourlyworker(int bh0, string name0, double shixin0, int hour0)
		: employee(bh0, name0), shixin(shixin0), hour(hour0) {}


	double getsalary() override {
		return shixin * hour;
	}

	void showinfo() override {
		cout << "【计时工人】" << endl;
		cout << "编号：" << bh << "\t姓名：" << name << endl;
		cout << "时薪：" << shixin << " 元\t工时：" << hour << " 小时" << endl;
		cout << "月薪：" << getsalary() << " 元" << endl << endl;
	}
};


class pieceworker : public employee {
protected:
	double jiaqian;  
	int jianshu;   
public:
	pieceworker(int bh0, string name0, double jiaqian0, int jianshu0)
		: employee(bh0, name0), jiaqian(jiaqian0), jianshu(jianshu0) {}

	double getsalary() override {
		return jiaqian * jianshu;
	}

	void showinfo() override {
		cout << "【计件工人】" << endl;
		cout << "编号：" << bh << "\t姓名：" << name << endl;
		cout << "每件：" << jiaqian << " 元\t件数：" << jianshu << endl;
		cout << "月薪：" << getsalary() << " 元" << endl << endl;
	}
};


int main() {

	employee* emp1 = new manager(101, "张三", 8000);
	employee* emp2 = new hourlyworker(102, "李四", 50, 160);
	employee* emp3 = new pieceworker(103, "王五", 20, 300);


	emp1->showinfo();
	emp2->showinfo();
	emp3->showinfo();

	delete emp1;
	delete emp2;
	delete emp3;

	return 0;
}