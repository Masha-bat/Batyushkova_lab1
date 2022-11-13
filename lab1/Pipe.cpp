#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include "Pipe.h"
#include <unordered_map>
#include <unordered_set>
#include "Header.h"
int Pipe::max_idp = 0;
string pipeStatus(bool x)
{
    if (x == true)
        return ("Pipe is working");
    else if (x == false)
        return ("Pipe is under repair");
    else
        return ("Unknown");
}
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n Index of pipe: " << p.idp;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "\nInput lenght ";
    p.lenght = correctNumber(0.0, DBL_MAX);
    cout << "\nInput diameter ";
    p.diameter = correctNumber(0.0, DBL_MAX);
    cout << "\nChoose status of pipe (0 if repairing, 1 if works) ";
    p.status = correctNumber(1, 2);
    cout << pipeStatus(p.status) << endl;
    return in;
}

ostream& operator<< (ostream& out, Pipe& p)
{
    out << "\nIndex of pipe: " << p.idp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: " << p.lenght << "\nDiameter : " << p.diameter
        << "\nStatus: " << pipeStatus(p.status) << endl;
    return out;
}

void Pipe::editPipe() {
    cout << "Status: " << pipeStatus(status) << endl;
    cout << "Change pipe state: \n1. pipe is working \n2. pipe is under repair" << endl;
    status = correctNumber(1, 2);
    cout << pipeStatus(status);
}

void Pipe::savePipe(ofstream& file)
{
    file << idp << endl << name << endl << lenght << endl << diameter << endl << status << endl;
}

void Pipe::loadPipe(ifstream& file)
{
    file >> idp;
    getline(file, name);
    getline(file, name);
    file >> lenght;
    file >> diameter;
    file >> status;
}