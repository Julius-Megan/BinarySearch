#pragma once
#include <string>

using namespace std;

class Trabahador
{
private:
	string name;
	int id;
	int age;
	string job;
	int year;
public:
	Trabahador(string, int, int, string, int);
	void declareFound();
	int getID();
};