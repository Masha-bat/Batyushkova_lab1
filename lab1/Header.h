#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include "CS.h"
#include "Pipe.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
T correctNumber(T min, T max) {
	int x;
	while ((cin >> x).fail() || (x<min) || (x>max)) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	} 
	return x;
}

template <typename T>
ostream& operator<< (ostream& out, unordered_map <int,T>& par)
{
    out << "Existing id: ";
    for (auto& [i, obj] : par) 
    {
        out << i << " ";
    }
    out << endl;
    return out;
}

template <typename T>
using filter_p = bool (*) (Pipe& p, T par);

template <typename T>
using filter_cs = bool (*) (CS& cs, T par);

template <typename T>
vector <int> parametrP(unordered_map <int, Pipe>& pipe_group, filter_p<T> f, T par)
{
    vector <int> id;
    for (auto& pipe : pipe_group)
    {
        if (f(pipe.second, par))
            id.push_back(pipe.second.getIdP());
    }
    return id;
}

template <typename T>
vector <int> parametrCs(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par)
{
    vector <int> id;
    for (auto& cs : cs_group)
    {
        if (f(cs.second, par))
            id.push_back(cs.second.getIdCs());
    }
    return id;
}
