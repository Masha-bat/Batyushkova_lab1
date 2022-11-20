#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include "CS.h"
#include "Pipe.h"
#include <unordered_map>
#include <unordered_set>
#include "Header.h"

using namespace std;

unordered_map<int, Pipe> pipe_group;
unordered_map<int, CS> cs_group;
unordered_set<int> iddpipe;
unordered_set <int> iddcs;

bool checkNameP(Pipe& p, string name) 
{
	return (p.name.find(name) != string::npos);
}

bool checkStatusP(Pipe& p, bool status) 
{
	return (p.status == status);
}

bool checkNameCS(CS& cs, string name) 
{
	return (cs.name.find(name) != string::npos);
}

bool checkUnworking(CS& cs, double p) 
{
	return (cs.get_unused() >= p);
}


void viewObjects(unordered_map<int, Pipe>& pipe_group, unordered_map<int, CS>& cs_group) 
{
	for (auto& pipe : pipe_group) 
	{
		cout << pipe.second << endl;
	}
	for (auto& cs : cs_group) 
	{
		cout << cs.second << endl;
	}
}

void searchP(unordered_map <int, Pipe>& pipe_group, vector<int>& id) 
{
	int x;
	cout << "Search pipe by 1.name 2.status" << endl;
	x = correctNumber(1, 2);
	if (x == 1) {
		string name;
		cout << "Enter the name of pipe: " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, name);
		id = parametrP(pipe_group, checkNameP, name);
	}
	else {
		bool k;
		cout << "Select attribute: \n0. pipe is under repair \n1. pipe is working \n" << endl;
		k = correctNumber(0, 1);
		id = parametrP(pipe_group, checkStatusP, k);
	}
}

void searchCs(unordered_map <int, CS>& cs_group, vector<int>& id) 
{
	int x;
	cout << "Search CS by 1.name 2.percentage of unused shops" << endl;
	x = correctNumber(1, 2);
	if (x == 1) {
		string name;
		cout << "Enter the name of CS: " << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, name);
		id = parametrCs(cs_group, checkNameCS, name);

	}
	else {
		double k;
		cout << "Enter the percentage of unused shops" << endl;
		k = correctNumber(0, 100);
		id = parametrCs(cs_group, checkUnworking, k);
	}

}

void addPipe() 
{
	Pipe p;
	cin >> p;
	pipe_group.insert({ p.getIdP(), p});
}

void addCs() 
{
	CS cs;
	cin >> cs;
	cs_group.insert({ cs.getIdCs(),cs });
}

void editPipes() 
{
	int edit;
	int id1;
	int x;
	if (pipe_group.size() != 0) 
	{
		cout << "1.Choose one pipe 2.Choose pipes 3.Delete pipe" << endl;;
		edit = correctNumber(1, 3);

		if (edit == 1) 
		{
			cout << "1.Choose pipe to edit" << endl;
			cout << iddpipe;
			id1 = correctNumber(0, (int)pipe_group.size());
			pipe_group[id1].editPipe();
		}

		if (edit == 2) 
		{
			vector <int> idp;
			cout << "Choose pipes by 1.filter 2.id" << endl;
			x = correctNumber(1, 2);
			if (x == 1) 
			{
				searchP(pipe_group, idp);
				if (idp.size() != 0) 
				{
					cout << "Enter new status (0 if repairing, 1 if works)" << endl;
					bool s;
					s = correctNumber(0, 1);
					for (auto& i : idp)
						pipe_group[i].status = s;
				}
				else
					cout << "There is no pipe to edit";

			}


			if (x == 2) 
			{
				unordered_set <int> ids;
				cout << iddpipe;
				cout << "Enter the number of identifiers of pipe you want to edit" << endl;
				int n;
				n = correctNumber(0, Pipe::max_idp);
				cout << "Enter idetifiers of pipes" << endl;
				int y;
				for (int i = 0; i < n; i++) 
				{
					y = correctNumber(0, Pipe::max_idp - 1);
					if (pipe_group.find(y) != pipe_group.end())
						ids.insert(y);
				}

				cout << "Enter new status (0 if repairing, 1 if works)" << endl;
				bool s;
				s = correctNumber(0, 1);
				for (auto& i : ids)
					pipe_group[i].status = s;
			}
		}
		if (edit == 3) {
			cout << "Enter the id of pipe you want to delete" << endl;
			int n;
			n = correctNumber(0, Pipe::max_idp);
			pipe_group.erase(pipe_group.find(n));
			iddpipe.erase(iddpipe.find(n));
			cout << "Pipe was deleted";
		}
	}
	else
		cout << "There is no pipe to edit" << endl;

}

void editCs() 
{
	vector <int> idcs;
	if (cs_group.size() != 0) 
	{
		cout << "1.Edit one CS 2.Edit CSs 3.Delete CS" << endl;
		int edit;
		edit = correctNumber(1, 3);
		if (edit == 1) 
		{
			int id;
			cout << "Choose CS to edit" << endl;
			id = correctNumber(0, (int)cs_group.size());
			cs_group[id].editCs();
		}

		if (edit == 2) 
		{
			unordered_set <int> idw;
			cout << "Choose by 1.filter 2.id" << endl;
			int n;
			n = correctNumber(1, 2);
			if (n == 2) 
			{
				cout << "Enter the number of cs you want to edit";
				int y;
				y = correctNumber(0, CS::max_idcs);
				cout << "Enter idetifiers of CSs" << endl;
				for (int i = 0; i < y; i++) 
				{
					if (cs_group.find(i) != cs_group.end())
						idw.insert(i);
				}
				for (auto& i : idw)
					cs_group[i].editCs();

			}
			else 
			{
				searchCs(cs_group, idcs);
				for (auto& i : idcs)
					cs_group[i].editCs();
			}

		}
		if (edit == 3) {
			cout << "1. identifier of one CS you want to delete 2.delete some CS" << endl;
			int d;
			d = correctNumber(1, 2);
			if (d == 1) {
				cout << "Enter id of CS you want to delete" << endl;
				int n;
				n = correctNumber(0, CS::max_idcs);
				cs_group.erase(cs_group.find(n));
			}
			else {
				unordered_set <int> idd;
				cout << "1.delete by filter 2.delete by id" << endl;
				int n;
				n = correctNumber(1, 2);
				if (n == 2) {
					cout << "Enter the number of cs you want to edit";
					int y;
					y = correctNumber(0, CS::max_idcs);
					cout << "Enter idetifiers of CSs" << endl;
					for (int i = 0; i < y; i++) {
						if (cs_group.find(i) != cs_group.end())
							idd.insert(i);
					}
					for (auto& i : idd)
						cs_group.erase(cs_group.find(i));
				}
				else {
					searchCs(cs_group, idcs);
					for (auto& i : idcs)
						cs_group.erase(cs_group.find(i));
					for (auto& i : iddcs)
						iddcs.erase(i);
				}

				cout << "CS was deleted";
			}
		}
	}
	else
		cout << "There is no CS to edit" << endl;

}

void saveToFile() 
{
	string x;
	cout << "Enter the name of your file: " << endl;
	cin >> x;
	ofstream file;
	file.open(x + ".txt");
	if (!file)
		cout << "file is not found" << endl;
	else 
	{
		file << pipe_group.size() << " " << cs_group.size() << endl;
		for (auto pipe : pipe_group)
			pipe.second.savePipe(file);
		for (auto cs : cs_group)
			cs.second.saveCs(file);
	}

}

void downloadFromFile() 
{
	string x;
	int p1, cs2;
	Pipe newpipe;
	CS newcs;
	cout << "Enter the name of your file:" << endl;
	cin >> x;
	ifstream file2;
	file2.open(x + ".txt");
	if (!file2)
		cout << "file is not found";
	else 
	{
		Pipe::max_idp = 0;
		CS::max_idcs = 0;
		pipe_group.clear();
		cs_group.clear();
		file2 >> p1 >> cs2;
		for (int i = 0; i < p1; i++) 
		{
			newpipe.loadPipe(file2);
			pipe_group.insert({ newpipe.getIdP(),newpipe });
			if (Pipe::max_idp < newpipe.getIdP())
				Pipe::max_idp = newpipe.getIdP();
		}
		for (int i = 0; i < cs2; i++) 
		{
			newcs.loadCs(file2);
			cs_group.insert({ newcs.getIdCs(),newcs });
			if (CS::max_idcs < newcs.getIdCs())
				CS::max_idcs = newcs.getIdCs();
		}
	}

}

void searchPipes() 
{
	vector <int> x;
	if (pipe_group.size() != 0) 
	{
		searchP(pipe_group, x);
		if (x.size() != 0) 
		{
			for (auto& i : x)
				cout << pipe_group[i] << endl;
		}
		else
			cout << "There is no such pipe" << endl;
	}
	else
		cout << "There is no pipe to find" << endl;
}

void searchCS() 
{
	vector <int> x;
	if (cs_group.size() != 0) 
	{
		searchCs(cs_group, x);
		if (x.size() != 0) 
		{
			for (auto& i : x)
				cout << cs_group[i] << endl;
		}
		else
			cout << "There is no such CS";
	}
	else
		cout << "There is no CS to find" << endl;
}


int main()
{
	int action = -1;
	while (action)
	{
		cout << "\nMenu \n1. Add pipe \n2. Add CS \n3. View all objects \n4. Edit pipe \n5. Edit CS \n6. Save \n7. Download \n8. Search pipe \n9. Search CS \n0. Exit \n\n";
		action = correctNumber(0, 9);
		switch (action)
		{
		case 1:
		{
			addPipe();
			break;
		}
		case 2:
		{
			addCs();
			break;
		}
		case 3:
		{
			viewObjects(pipe_group, cs_group);
			break;
		}
		case 4:
		{
			editPipes();
			break;
		}
		case 5:
		{
			editCs();
			break;
		}
		case 6:
		{
			saveToFile();
			break;
		}
		case 7:
		{
			downloadFromFile();
			break;
		}
		case 8: 
		{
			searchPipes();
			break;
		}
		case 9: 
		{
			searchCS();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Wrong action. Please, enter action from menu (0-9)" << endl;
		}
		}
	}
}