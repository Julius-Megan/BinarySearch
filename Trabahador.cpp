#include "Trabahador.h"
#include <iostream>
#include <string>

using namespace std;

Trabahador::Trabahador(string n, int i, int a, string j, int y) {
	name = n;
	id = i;
	age = a;
	job = j;
	year = y;
}

//This is my printing of details method for my class
void Trabahador::declareFound() {
	cout << "FOUND: Name: " << name << ", AGE: " << age<< ", JOB: "<< job << ", HIRED: " << year;
	/*cout << "ID:           " << id << endl;
	cout << "Age:          " << age << endl;
	cout << "Job:          " << job << endl;
	cout << "Hire year:    " << year << endl;
	cout << "*********************************\n";*/
}

int Trabahador::getID() {
	return id;
}