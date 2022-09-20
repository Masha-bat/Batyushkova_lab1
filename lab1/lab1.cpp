#include <iostream>
using namespace std;

struct pipe 
{
    float length = 0, diametr = 0;
    bool repair = 0;
};

struct CS
{
    string name = "";
    int workshops = 0, workingWorkshops = -1;
    float efficiency = 0;
};



int main()
{
    cout << "Menu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n0. Exit \n";
}

