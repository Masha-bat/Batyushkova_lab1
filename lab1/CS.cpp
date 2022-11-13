#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "Header.h"

using namespace std;

int CS::max_idcs = 0;

istream& operator>> (istream& in, CS& cs)
{
    cout << "\nIndex of cs: " << cs.idcs;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(in, cs.name);
    cout << "\nNumber of workshops ";
    cs.workshop = correctNumber(0, INT_MAX);
    cout << "\nNumber of working workshops ";
    cs.workingWorkshop = correctNumber(0, cs.workshop);
    cout << "\nEnter the effectiveness ";
    cs.efficiency = correctNumber(0, 100);
    return in;
}

ostream& operator<< (ostream& out, CS& cs)
{
    out << "\nIndex of CS: " << cs.idcs << "\nCS info:\nName: " << cs.name << "\nNumber of workshops: " << cs.workshop
        << "\nNumber of working workshops: " << cs.workingWorkshop << "\nEffectiveness: "
        << cs.efficiency << "%" << endl;
    return out;
}

void CS::editCs() {
    cout << "Number of workshops: " << workshop << endl;
    cout << "Change number of working shops: ";
    workingWorkshop = correctNumber(0, workshop);
}

void CS::saveCs(ofstream& file)
{
    file << idcs << endl << name << endl << workshop << endl << workingWorkshop << endl << efficiency << endl;
}

void CS::loadCs(ifstream& file)
{
    file >> idcs;
    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> workingWorkshop;
    file >> efficiency;
}