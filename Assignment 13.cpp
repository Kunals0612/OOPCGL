//Assignment 13
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int numStates
    cout << "Enter the number of states: ";
    cin >> numStates;
    string* states = new string[numStates];
    int* pops = new int[numStates];
    for (int j = 0; j < numStates; j++)
    {
        cout << "Enter state name for state " << j + 1 << ": ";
        cin >> states[j];


        cout << "Enter population for state " << j + 1 << ": ";
        cin >> pops[j];
    }
    map<string, int, less<string>> mapStates;
    for (int j = 0; j < numStates; j++)
    {
        mapStates[states[j]] = pops[j];
    }
    string name;
    int pop;
    cout << "Enter state: ";
    cin >> name;
    if (mapStates.find(name) != mapStates.end())
    {
        pop = mapStates[name];
        cout << "Population: " << pop << ",000\n";
    }
    else
    {
        cout << "State not found in the map.\n";
    }
    cout << endl;
    for (auto iter = mapStates.begin(); iter != mapStates.end(); iter++)
        cout << iter->first << ' ' << iter->second << ",000\n";
    delete[] states;
    delete[] pops;
    return 0;
}

