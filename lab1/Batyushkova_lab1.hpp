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
    void editPipe();
    void savePipe(ofstream& file);
    void loadPipe(ifstream& file);
    int getIdP() { return idp; }

private:
    double lenght = 0, diameter = 0;
    int idp = 0;

};

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
    void saveCs(ofstream& file);
    void editCs();
    void loadCs(ifstream& file);
    int getIdCs() { return idcs; }
    double get_unused() { return (((double)workshop - (double)workingWorkshop) / (double)workshop) * 100; }
    string name = "";

private:
    int  workshop, workingWorkshop, idcs;
    double efficiency;
};

int Pipe::max_idp = 0;
int CS::max_idcs = 0;