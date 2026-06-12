#include <iostream>
#include<fstream>
#include<string>

using namespace std;



int main() {
	ofstream outFile("test.txt");
	if (!outFile.is_open())
	{
		cout << "wenjianchuangjianshibai" << endl;
		return 1;
	}
	int zhengshu = 1234;
	double fudian = 88.98;
	char zifu = 'q';
	string zifuchuan0 = "almanfi";
	string zifuchuan1 = "shan shao qi";
	outFile << zhengshu << endl;
	outFile << fudian << endl;
	outFile << zifu << endl;
	outFile << zifuchuan0 << endl;

	outFile << zifuchuan1 << endl;
	outFile.close();


	ifstream inFile("test.txt");
	if (!inFile.is_open())
	{
		cout << "wenjiandakaishibai" << endl;
		return 1;

	}

	outFile.open("new.txt");
	if (!outFile.is_open()) {
		cout << "dakaishibai" << endl;
		return 1;
	}
	char ch;
	while (inFile.get(ch))
	{
		outFile.put(ch);
	}
	outFile.close();
	inFile.close();

	inFile.open("new.txt");

	int readi1;
	double readd;
	char readc;
	string read1, read2;
	inFile >> readi1;
	inFile >> readd;
	inFile >> readc;
	inFile.ignore();
	getline(inFile, read1);
	getline(inFile, read2);

	inFile.close();
	cout << readi1;
	cout << endl << readd;
	cout << endl << readc;
	cout << endl << read1;
	cout << endl;
	cout << read2;
	cout << endl;

	return 0;
}