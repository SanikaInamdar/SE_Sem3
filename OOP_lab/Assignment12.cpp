// Write a program in C++ to use map associative container. The 
// keys will be the names of states and the values will be the 
// populations of the states. When the program runs, the user is 
// prompted to type the name of a state. The program then looks in 
// the map, using the state name as an index and returns the 
// population of the state.



#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;

class MAP
{

    map<string, int> sp;
    map<string, int>::iterator it;

public:
    MAP()
    {
        sp.insert(make_pair("UTTAR PRADESH", 199812341));
        sp.insert(make_pair("WEST BENGAL", 91276115));
        sp.insert(make_pair("BIHAR", 104099452));
        sp.insert(make_pair("MAHARASHTRA", 112374333));
        sp.insert(make_pair("TAMIL NADU", 72147030));
        sp.insert(make_pair("MADHYA PRADESH", 72626809));
    }

    void display();
    void search();
    void add();
    void update();
};

void MAP ::add()

{
    string s;
    cout << "Enter the state name - ";
    cin.ignore(1000, '\n');
    getline(cin, s);
    for_each(s.begin(), s.end(),[](char &c)
             { c = ::toupper(c); });

    for (it = sp.begin(); it != sp.end(); ++it)
    {
        if (it->first == s)
        {
            cout << "State name already exists" << endl;
            return;
        }
    }
    int pop;
    while (true)
    {
        cout << "Enter the population - ";
        cin >> pop;
        if (cin.fail() || pop <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input " << endl;
        }
        else
            break;
    }

    sp.insert(make_pair(s, pop));
}

void MAP ::display()
{
    for (it = sp.begin(); it != sp.end(); ++it)
    {
        cout << "State - " << setw(20) << setiosflags(ios::left) << it->first;
        cout << "Population - " << setw(15) << it->second;
        cout << endl;
    }
    cout << resetiosflags(ios ::left);
    cout << endl;
}

void MAP ::update()
{
    string s;
    int pop;
    cout << "Enter the  state name" << endl;
    cin.ignore(1000, '\n');

    getline(cin, s);

    for_each(s.begin(), s.end(), [](char &c)
             { c = ::toupper(c); });

    for (it = sp.begin(); it != sp.end(); ++it)
    {
        if (it->first == s)
        {
            while (true)
            {
                cout << "Enter the population -";
                cin >> pop;
                if (cin.fail() || pop <= 0)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Enter valid input" << endl;
                }
                else
                    break;
            }

            sp[s] = pop;
            return;
        }
    }
    cout << "No state information has been added" << endl;
}

void MAP ::search()
{
    string s;

    cout << "Enter the state name" << endl;
    cin.ignore(1000, '\n');
    getline(cin, s);
    for_each(s.begin(), s.end(), [](char &c)
             { c = ::toupper(c); });

    bool found = false;
    for (it = sp.begin(); it != sp.end(); ++it)
    {
        string str = it->first.substr(0, s.length());
        if (str == s)
        {
            found = true;
            cout << it->first << " 's population is " << it->second << endl;
        }
    }
    if (!found)
    {
        cout << "No such state data has been added" << endl;
        return;
    }
}

int main()
{
    MAP m;
    while (true)
    {

        cout << "\n------------MENU-----------\n"
             << "1)Add a state\n"
             << "2)Update\n"
             << "3)Display all\n"
             << "4)Search\n"
             << "0 - End\n";

        int opt;
        cout << "Enter your choice" << endl;

        cin >> opt;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        if (opt == 1)
        {
            m.add();
        }
        else if (opt == 2)
        {
            m.update();
        }
        else if (opt == 3)
        {
            m.display();
        }
        else if (opt == 4)
        {
            m.search();
        }

        else if (opt == 0)
        {
            cout << "Program terminated" << endl;
            break;
        }
        else
        {
            cout << "Invlaid choice" << endl;
        }
    }
}
