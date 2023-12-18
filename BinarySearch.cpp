// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Trabahador.h"


int main(int argc, char** argv)
{
    //We send a warning if they forget to input the filename
    if (argc == 1) {
        cout << "You forgot the commandline parameter\n";
        exit(0);
    }

    //This is how we read the file. By putting the filename in the commandline argument.
    //An error message is also sent, just in case the file location is incorrect.
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not locate file" << argv[1] << endl;
        exit(0);
    }

    //We create a vector/arraylist of my object
    vector<Trabahador*> employees;

    //We read the first line and save that to a variable
    string line1;
    getline(ifs, line1);
    int n = stoi(line1);


    //This will loop depending on the number of lines in each file
    for (auto i = 0; i < n; i++) {
        string word[4];
        string y;

        //Loop through all the line and save it to my array of strings.
        for (int x = 0; x < 4; x++) {
            getline(ifs, word[x], '|');
        }
        getline(ifs, y);


        //Get all those element from the array and create a variable
        string name = word[0];
        int id = stoi(word[1]);
        int age = stoi(word[2]);
        string job = word[3];
        int year = stoi(y);

        //Initialize the new object and add it to our vector
        Trabahador* t = new Trabahador(name, id, age, job, year);
        employees.push_back(t);
    }

    //Get the amount of time we need to run the query
    string querieline;
    getline(ifs, querieline);
    int q = stoi(querieline);

    //I will add all total comparisons to this variable. 
    double totalComparisons = 0;

    for (auto x = 0; x < q; x++) {
        string currentId;
        getline(ifs, currentId);
        int id = stoi(currentId);

        //Use this counter to keep track of how many comparisons made
        int indexCount = 0;

        //Binary Search
        int low = 0;
        int high = employees.size();
        while (low < high) {
            indexCount++;
            int mid = (low + high) / 2;                
            if (id <= employees[mid]->getID()) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        /*employees[high]->declareFound();
        cout << " at index " << high << " after " << indexCount << " comparisons." << endl;*/
        totalComparisons += indexCount;
        


    }
    //I simply divided the number queries to the number of total comparisons
    cout << "Done!Average amount of work per query : " << totalComparisons / q << " comparisons." << endl;




}

