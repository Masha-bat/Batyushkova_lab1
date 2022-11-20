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

//string Pipe :: pipeStatus()
//{
//    if (x == true)
//        return ("Pipe is working");
//    else if (x == false)
//        return ("Pipe is under repair");
//}

string Pipe :: pipeStatus()
{
    return status ? "Pipe is working" : "Pipe is under repair";
}

istream& operator>> (istream& in, Pipe& p)
{
    cout << "\nIndex of pipe: " << p.idp;
    cout << "\nInput pipe name: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "Input lenght: ";
    p.lenght = correctNumber(0.0, DBL_MAX);
    cout << "Input diameter: ";
    p.diameter = correctNumber(0.0, DBL_MAX);
    cout << "Select attribute: \n0. pipe is under repair \n1. pipe is working \n";
    p.status = correctNumber(0, 1);
    cout << p.pipeStatus() << endl;
    return in;
}

ostream& operator<< (ostream& out, Pipe& p)
{
    out << "\nIndex of pipe: " << p.idp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: " << p.lenght << "\nDiameter : " << p.diameter
        << "\nStatus: " << p.pipeStatus() << endl;
    return out;
}

void Pipe::editPipe() {
    cout << "Status: " << pipeStatus() << endl;
    cout << "Select attribute: \n0. pipe is under repair \n1. pipe is working \n" << endl;
    status = correctNumber(1, 2);
    cout << pipeStatus();
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