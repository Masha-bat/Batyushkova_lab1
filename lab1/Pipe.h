#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pipe
{
public:
    static int max_idp;
    string name = "";
    bool status = 0;
    Pipe()
    {
        idp = max_idp++;
    }
    friend istream& operator >> (istream& in, Pipe& p);
    friend ostream& operator << (ostream& out, Pipe& p);
    string pipeStatus();
    void editPipe();
    void savePipe(ofstream& file);
    void loadPipe(ifstream& file);
    int getIdP() { return idp; };

private:
    double lenght = 0, diameter = 0;
    int idp = 0;

};
