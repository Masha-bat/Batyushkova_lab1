#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe
{
    double length = 0, diametr = 0, repair = -1;
};

struct CS
{
    string name = "";
    double efficiency = 0, workshops = 0, workingWorkshops = -1;
};


double correctCinPipeCS(double x)
{
    while (x <= 0)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error! Please, enter value > 0" << endl;
        cin >> x;
    }
    return x;
}

int correctCinCs(double x)
{
    while ((x <= 0) || (x / trunc(x) != 1))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error! Please, enter integer value > 0" << endl;
        cin >> x;
    }
    return x;
}

int correctWorkingWorkshops(double x, double y)
{
    while ((x < y) || (x, y <= 0) || (x / trunc(x) != 1) || (y / trunc(y) != 1))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error! Please, enter integer value > 0 and no more then the number of workshops" << endl;
        cin >> y;
    }
    return y;
}

double correctAttribute(double x)
{
    while ((x < 1) || (x > 2) || (x / trunc(x) != 1))
    { 
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error! Please, enter right attribute (1 - pipe is under repair, 2 - pipe is working) " << endl;
        cin >> x;
    }
    return x;
}

string attribute(double x)
{
    if (x == 1)
        return ("Pipe is under repair");
    else if (x == 2)
        return ("Pipe is working");
    else
        return ("Unknown");
}

void addPipe(Pipe& p)
{
    cout << "Enter pipe length: ";
    cin >> p.length;
    p.length = correctCinPipeCS(p.length);
    cout << "Enter pipe diametr: ";
    cin >> p.diametr;
    p.diametr = correctCinPipeCS(p.diametr);
    cout << "Select attribute: \n1. pipe is under repair \n2. pipe is working \n";
    cin >> p.repair;
    p.repair = correctAttribute(p.repair);
    cout << attribute(p.repair) << endl;
}

void addCS(CS& cs)
{
    cout << "Give the name of the compressor station: ";
    cin.ignore();
    getline(cin, cs.name);
    cout << "Number of workshops: ";
    cin >> cs.workshops;
    cs.workshops = correctCinCs(cs.workshops);
    cout << "Number of working workshops: ";
    cin >> cs.workingWorkshops;
    cout << "Efficiency indicator = ";
    cin >> cs.efficiency;
    cs.efficiency = correctCinPipeCS(cs.efficiency);
}

void viewObjects(Pipe p, CS cs)
{
    if (p.length != 0)
    {
        cout << "\nPipe: "
            << "\nLength = " << p.length
            << "\nDiametr = " << p.diametr
            << "\nSelected attribute: " << attribute(p.repair) << endl;
        cout << "\nCS: \nName: " << cs.name
            << "\nNumber of workshops = " << cs.workshops
            << "\nNumber of working workshops = " << cs.workingWorkshops
            << "\nEfficiency indicator = " << cs.efficiency << "%" << endl;
    }
    else
        cout << "Error! Please, add options for pipe or CS" << endl;
    
}

void editPipe(Pipe& p)
{
    if (p.repair == -1)
        cout << "There is no pipe" << endl;
    else
    {
        cout << "Change pipe state: \n0. pipe is under repair \n1. pipe is working" << endl;
        cin >> p.repair;
        p.repair = correctAttribute(p.repair);
        cout << attribute(p.repair) << endl;
    }
}

void editCS(CS& cs)
{
    if (cs.workingWorkshops == -1)
        cout << "There is no working compressor stations" << endl;
    else
    {
        cout << "Number of workshops: " << cs.workshops << endl;
        cout << "Change number of working shops: ";
        cin >> cs.workingWorkshops;
        cs.workingWorkshops = correctWorkingWorkshops(cs.workshops, cs.workingWorkshops);
        cs.efficiency = double(cs.workingWorkshops) / double(cs.workshops) * 100;
    }


}

void saveToFile(Pipe& p, CS& cs)
{
    ofstream file;
    file.open("savedData.txt");
    if (file.is_open())
    {
        file << p.length << endl
             << p.diametr << endl
             << p.repair << endl
             << cs.name << endl
             << cs.workshops << endl
             << cs.workingWorkshops << endl
             << cs.efficiency << "%" << endl;
        file.close();
    }
}

void downloadFromFile(Pipe& p, CS& cs)
{
    ifstream file2;
    string line;
    file2.open("savedData.txt", ios::out);
    getline(file2, line);
    p.length = stoi(line);
    getline(file2, line);
    p.diametr = stoi(line);
    getline(file2, line);
    p.repair = stoi(line);
    getline(file2, line);
    cs.name = line;
    getline(file2, line);
    cs.workshops = stoi(line);
    getline(file2, line);
    cs.workingWorkshops = stoi(line);
    getline(file2, line);
    cs.efficiency = stod(line);
}

int main()
{
    int action = -1;
    Pipe p;
    CS cs;

    while (action)
    {
        cout << "\nMenu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n0. Exit \n\n";
        cin >> action;
        switch (action)
        {
        case 1:
        {
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

