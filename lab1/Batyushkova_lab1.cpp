#include <iostream>
#include <fstream>
#include <string>
#include <Batyushkova_lab1.h>
using namespace std;

int Pipe::max_id = 0;
int CS::max_idd = 0;

template <typename T>
T correctNumber(T min, T max) {
    int x;
    do {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Type number (" << min << "-" << max << "):";
        cin >> x;
    } while (cin.fail() || x<min || x>max );
    return x;
}

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
    in.clear();
    in.ignore(INT_MAX, '\n');
    getline(in, p.name);
    cout << "\nInput lenght ";
    p.lenght = correctNumber(0.0, DBL_MAX);
    cout << "\nInput diameter ";
    p.diameter = correctNumber(0.0, DBL_MAX);
    cout << "\nChoose status of pipe (0 if repairing, 1 if works) ";
    p.status = correctNumber(1, 2);
    cout << pipeStatus(p.status) << endl;
    return in;
}

istream& operator>> (istream& in, CS& cs)
{
    cout << "\nIndex of cs: " << cs.idcs;
    cout << "\nInput name ";
    in.clear();
    in.ignore(INT_MAX, '\n');
    getline(in, cs.name);
    cout << "\nNumber of workshops ";
    cs.workshop = correctNumber(0, INT_MAX);
    cout << "\nNumber of working workshops ";
    cs.workingWorkshop = correctNumber(0, cs.workshop);
    cout << "\nEnter the effectiveness ";
    cs.efficiency = correctNumber(0, 100);
    return in;
}

ostream& operator<< (ostream& out, Pipe& p) 
{
    out << "\nIndex of pipe: " << p.idp << "\nPipe info: " << "\nName: " << p.name << "\nLenght: " << p.lenght << "\nDiameter : " << p.diameter
        << "\nStatus: " << pipeStatus(p.status) << endl;
    return out;
}

ostream& operator<< (ostream& out, CS& cs) 
{
    out << "\nIndex of CS: " << cs.idcs << "\nCS info:\nName: " << cs.name << "\nNumber of workshops: " << cs.workshop
        << "\nNumber of working workshops: " << cs.workingWorkshop << "\nEffectiveness: "
        << cs.efficiency << "%" << endl;
    return out;
}

void Pipe::edit_Pipe() {
    cout << "Status: " << pipeStatus(status) << endl;
    cout << "Change pipe state: \n1. pipe is working \n2. pipe is under repair" << endl;
    status = correctNumber(1, 2);
    cout << pipeStatus(status);
}

void CS::edit_cs() {
    cout << "Number of workshops: " << workshop << endl;
    cout << "Change number of working shops: ";
    workingWorkshop = correctNumber(0, workshop);
}

void Pipe::save_pipe(ofstream& file) 
{
    file << idp << endl << name << endl << lenght << endl << diameter << endl << status << endl;
}

void CS::save_cs(ofstream& file) 
{
    file << idcs << endl << name << endl << workshop << endl << workingWorkshop << endl << efficiency << endl;
}

void Pipe::load_pipe(ifstream& file) 
{
    file >> idp;
    getline(file, name);
    getline(file, name);
    file >> lenght;
    file >> diameter;
    file >> status;
}

void CS::load_cs(ifstream& file) 
{
    file >> idcs;
    getline(file, name);
    getline(file, name);
    file >> workshop;
    file >> workingWorkshop;
    file >> efficiency;
}

int main()
{
    int action = -1;
    while (action)
    {
        cout << "\nMenu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n0. Exit \n\n";
        action = correctNumber(0, 9);
        switch (action)
        {
        case 1:
        {
            Pipe p;
            cin >> p;
            addPipe(p);
            break;
        }
        case 2:
        {
            addCS(cs);
            break;
        }
        case 3:
        {
            viewObjects(p, cs);
            break;
        }
        case 4:
        {
            editPipe(p);
            break;
        }
        case 5:
        {
            editCS(cs);
            break;
        }
        case 6:
        {
            saveToFile(p, cs);
            break;
        }
        case 7:
        {
            downloadFromFile(p, cs);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action. Please, enter action from menu (0-7)" << endl;
        }
        }
    }

}

