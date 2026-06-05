#include <iostream>
#include <string>
using namespace std;
class animal {
public:
	int height;
	int weight;
	char* sex;
	animal() {
		height = 0; weight = 0;
		sex = new char[1];
		sex[0] = '\0';
	}

	animal(int a, int w, const char* s) {
		height = a;
		weight = w;
		sex = new char[strlen(s) + 1];
		strcpy_s(sex, strlen(s) + 1, s);

	}
	~animal() {
		delete[] sex;
	}
	void show_animal() {
		cout << "height:" << height << endl;
		cout << "weight:" << weight << endl;
		cout << "sex:" << sex << endl;
	}

};

class ter_animal :virtual public animal {
public:
	int running_speed;
	ter_animal(int a, int w, const char* s, int r) :animal(a, w, s) {
		running_speed = r;

	}
	ter_animal()
	{
		running_speed = 0;
	}
	void show_ter() {
		show_animal();

		cout << "running_speed:" << running_speed << endl;
	}
};
class aqu_animal :virtual public animal {

public:
	int swiming_speed;
	aqu_animal(int a, int w, const char* s, int r) :animal(a, w, s) {
		swiming_speed = r;
	}
	aqu_animal()
	{
		swiming_speed = 0;
	}
	void show_aqu() {
		show_animal();
		cout << "swimming_speed:" << swiming_speed << endl;
	}
};
class amp_animal :public ter_animal, public aqu_animal {
public:
	amp_animal(int a, int w, const char* s, int run, int swim) :animal(a, w, s) {
		running_speed = run;
		swiming_speed = swim;

	}
	void show_all() {
		show_animal();

		cout << "running_speed:" << running_speed << endl;
		cout << "swimming_speed:" << swiming_speed << endl;
	}
};
int main() {
	int h, w, run, swim;
	char sex[10];
	cin >> h >> w >> sex >> run >> swim;

	amp_animal amp(h, w, sex, run, swim);
	amp.show_all();

	return 0;

}


