#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<float.h>

using namespace std;

class CS
{
public:
    static int max_idcs;
    CS()
    {
        idcs = max_idcs++;
    }
    friend istream& operator>> (istream& in, CS& p);
    friend ostream& operator<< (ostream& out, CS& cs);
    void editCs();
    void saveCs(ofstream& file);
    void loadCs(ifstream& file);
    int getIdCs() { return idcs; }
    double get_unused() { return (((double)workshop - (double)workingWorkshop) / (double)workshop) * 100; }
    string name = "";

private:
    int  workshop, workingWorkshop, idcs;
    double efficiency;
};
