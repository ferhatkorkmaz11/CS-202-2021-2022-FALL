/**
* Author : Ferhat Korkmaz
* ID: 21901940
* Section : 01
* Assignment : 4
*/
#include <iostream>
#include "HashTable.h"
#include <string>
#include <fstream>
#include <sstream>
void runForTheSceneriao(CollisionStrategy strat); //Run all of the scenearios helper function.
using namespace std;

int main()
{
	cout << "RUNNING FOR LINEAR PROBING WITH SIZE 53" << endl;
	runForTheSceneriao(LINEAR);
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "RUNNING FOR QUADRATIC PROBING WITH SIZE 53" << endl;
	runForTheSceneriao(QUADRATIC);
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "RUNNING FOR DOUBLE PROBING WITH SIZE 53" << endl;
	runForTheSceneriao(DOUBLE);
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
   
    return 0;
}
void runForTheSceneriao(CollisionStrategy strat)
{
	HashTable* myTable;
	if(strat == LINEAR)
		myTable = new HashTable(53, LINEAR);
	else if(strat == QUADRATIC)
		myTable = new HashTable(53, QUADRATIC);
	else 
		myTable = new HashTable(53, DOUBLE);
	
	string fileName = "input.txt";
    ifstream file(fileName);
    string curLine = "";
    while (getline(file, curLine))
    {
       //cout << curLine << endl;
       string operation = curLine.substr(0,1);
       stringstream s(curLine.substr(2,curLine.length() - 2));
       int item;
       s >> item;
       //cout << operation << " is the operation and " << item << " is the value. " << endl;
       if(operation == "I")
       {
           if(myTable->insert(item))
           {
               cout << item << " has been successfully inserted\n";
           }
           else
           {
               cout << item << " could not be inserted\n";
           }
       }
       else if(operation == "R")
       {
           if(myTable->remove(item))
           {
               cout << item << " has been successfully removed\n";
           }
           else
           {
               cout << item << " could not be removed\n";
           }
       }
       else if(operation == "S")
       {
           int probe = 0;
           if(myTable->search(item, probe))
           {
               cout << item << " has been successfully found after " << probe << " probes\n";
           }
           else
           {
               cout << item << " could not be  found after " << probe << " probes\n";
           }
       }
    }
    myTable->display();
    int unsuc = 0;
    int suc = 0;
    myTable->analyze(suc, unsuc);
    cout << "Average number of probes for a successful search: " << suc << endl;
    cout << "Average number of probes for an unsuccessful search: " << unsuc << endl;
	delete myTable;
}