#include <iostream>
using namespace std;

struct Pipe 
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

void 

int main()
{
    int action = -1;
    Pipe p;
    CS cs;

    while (action)
    {
        cout << "Menu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n0. Exit \n";
        cin >> action;
        switch (action)
        {
        case1:
            {
                addPipe();
                break;
            }
        case2:
            {
                addCS();
                break;
            }
        case3:
            {
                viewObjects();
                break;
            }
        case4:
            {

            }
        case5:
            {

            }
        case6:
            {

            }
        case7:
            {
            
            }

        }
    }
    
}

