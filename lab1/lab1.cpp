#include <iostream>
#include <fstream>
using namespace std;

struct Pipe
{
    double length = 0, diametr = 0;
    int repair = -1;
};

struct CS
{
    string name = "";
    int workshops = 0, workingWorkshops = -1;
    double efficiency = 0;
};

double correctCinPipe(double x)
{
    while (x <= 0)
    {
        cin.clear();
        cin.ignore(1i64, '\n');
        cout << "Error! Please, enter value > 0" << endl;
        cin >> x;
    }
    return x;
}

int correctCinCs(int x)
{
    while (x <= 0)
    {
        cin.clear();
        cin.ignore(1i64, '\n');
        cout << "Error! Please, enter integer value > 0" << endl;
        cin >> x;
    }
    return x;
}

int correctWorkingWorkshops(int x, int y)
{
    while ((x < y) || (x <= 0) || (y <= 0))
    {
        cin.clear();
        cin.ignore(1i64, '\n');
        cout << "Error! Please, enter integer value > 0 and no more then the number of workshops" << endl;
        cin >> y;
    }
    return y;
}

int correctAttribute(int x)
{
    while ((x < 0) || (x > 1))
    { 
        cin.clear();
        cin.ignore(1i64, '\n');
        cout << "Error! Please, enter right attribute (0 - pipe is under repair, 1 - pipe is working) " << endl;
        cin >> x;
    }
    return x;
}

string attribute(int x)
{
    if (x == 0)
        return ("Pipe is under repair");
    else if (x == 1)
        return ("Pipe is working");
    else
        return ("Unknown");
}

void addPipe(Pipe& p)
{
    cout << "Enter pipe length: ";
    cin >> p.length;
    p.length = correctCinPipe(p.length);
    cout << "Enter pipe diametr: ";
    cin >> p.diametr;
    p.diametr = correctCinPipe(p.diametr);
    cout << "Select attribute: \n 0. pipe is under repair \n 1. pipe is working \n";
    cin >> p.repair;
    p.repair = correctAttribute(p.repair);
    cout << attribute(p.repair) << endl;
}

void addCS(CS& cs)
{
    cout << "Give the name of the compressor station: ";
    cin >> cs.name;
    cout << "Number of workshops: ";
    cin >> cs.workshops;
    cs.workshops = correctCinCs(cs.workshops);
    cout << "Number of working workshops: ";
    cin >> cs.workingWorkshops;
    cs.workingWorkshops = correctWorkingWorkshops(cs.workshops, cs.workingWorkshops);
    cs.efficiency = double(cs.workingWorkshops) / double(cs.workshops) * 100;
}

void viewObjects(Pipe p, CS cs)
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

void editCS(CS cs)
{

}

void save(Pipe& p, CS& cs)
{
    ofstream file;
    file.open("savedData.txt", 'w');
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

void download()
{

}

int main()
{
    int action = -1;
    Pipe p;
    CS cs;

    while (action)
    {
        cout << "Menu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n0. Exit \n\n";
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
            save(p, cs);
            break;
        }
        case 7:
        {
            download();
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

