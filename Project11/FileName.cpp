#include <iostream>
#include<fstream>
#include<string>

using namespace std;



int main() {
	ofstream outFile("stu.txt");
	if (!outFile.is_open())
	{
		cout << "wenjianchuangjianshibai" << endl;
		return 1;
	}
	string name = "shuai123bi";
	string id = "1234122133341324";
	outFile << name << endl;
	outFile << id << endl;
	outFile.close();
	

	ifstream inFile("stu.txt");
	if (!inFile.is_open())
	{
		cout << "wenjiandakaishibai" << endl;
		return 1;

	}

	string readname, readid;
	getline(inFile, readname);
	getline(inFile, readid);

	inFile.close();
	cout << readname;
	cout << endl << readid << endl;



	

	return 0;
}