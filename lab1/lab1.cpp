#include <iostream>
using namespace std;

struct Pipe
{
    double length = 0, diametr = 0;
    bool repair = false;
};

struct CS
{
    string name = "";
    int workshops = 0, workingWorkshops = -1;
    double efficiency = 0;
};

void addPipe()
{
    Pipe p;
    cout << "Enter pipe length: ";
    cin >> p.length;
    cout << "Enter pipe diametr: ";
    cin >> p.diametr;
    cout << "Select attribute: \n 0. pipe under repair \n 1. pipe is working \n";
    cin >> p.repair;
}

void addCS()
{
    CS cs;
    cout << "Give the name of the compressor station: ";
    cin >> cs.name;
    cout << "Number of workshops: ";
    cin >> cs.workshops;
    cout << "Number of working workshops: ";
    cin >> cs.workingWorkshops;
    cs.efficiency = double(cs.workingWorkshops) / double(cs.workshops) * 100;
}

void viewObjects()
{
    Pipe p;
    CS cs;
    cout << "\nPipe: \nLength = " << p.length << "\nDiametr = " << p.diametr << "\nSelected attribute: " << p.repair << endl;
    cout << "\nCS: \nName: " << cs.name << "\nNumber of workshops = " << cs.workshops << "\nNumber of working workshops = " << cs.workingWorkshops << "\nEfficiency indicator = " << cs.efficiency << endl;
}

void editPipe()
{

}

void editCS()
{

}

void save()
{

}

void download()
{

}

void exit()
{

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
            addPipe();
            break;
        }
        case 2:
        {
            addCS();
            break;
        }
        case 3:
        {
            viewObjects();
            break;
        }
        case 4:
        {
            editPipe();
            break;
        }
        case 5:
        {
            editCS();
            break;
        }
        case 6:
        {
            save();
            break;
        }
        case 7:
        {
            download();
            break;
        }
        case 0:
        {
            exit();
            break;
        }

        }
    }

}

