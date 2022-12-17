// Write C++ program using STL for sorting and searching user defined records such as Item records (Item code, name, cost, quantity etc) using vector container.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class record
{
    string name;
    int itemCode, quantity;
    float cost;

public:
    record()
    {
        name = "NONAME";
        itemCode = 0;
        quantity = 0;
        cost = 0.0;
    }
    void putData(string n, int i, int q, float c)
    {
        name = n;
        itemCode = i;
        quantity = q;
        cost = c;
    }
    int getcode()
    {
        return itemCode;
    }

    void display()
    {
        cout << name << "\t  " << itemCode << "\t\t\t   " << quantity << "\t\t\t " << cost << "\n";
    }
};
bool comparator(record &x, record &y)
{
    return x.getcode() < y.getcode();
}
int main()
{
    vector<record> vec;
    int ch, len;
    string name;
    int itemCode, quantity;
    float cost;
    record rec;

    //New vector to store the itemcode
    vector<int> code;
    vector<int> :: iterator c;  //Iterator for above vector

    do
    {
        cout << "1. Enter record\n";
        cout << "2. Search a record\n";
        cout << "3. Sort records\n";
        cout << "4. Display all records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter Name: ";
            cin >> name;
            while (true)
            {
                bool b1 = false;

                cout << "Enter item code: ";
                if (cin >> itemCode)
                {
                    for(c = code.begin(); c != code.end(); c++ )
                    {
                        if(*c == itemCode)  //If code is not unique it will break loop by taking boolean value as true
                        {
                            b1 = true;
                            break;
                        }
                    }

                    if(b1)
                    {
                        cout << "\nEnter unique code!!" << endl;
                    }
                    else
                    {   
                        //IF item code is found to be unique then this will be pushed back in new vector
                        code.push_back(itemCode);
                        break;
                    }
                }
                else
                {
                    cout << "Enter an integer value" << endl;
                    cout << "Enter item code: ";
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                
            }
            while (true)
            {
                cout << "Enter quantity: ";
                while (!(cin >> quantity))
                {
                    cout << "Enter an integer value" << endl;
                    cout << "Enter quantity: ";
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                if (quantity < 0)
                {
                    cout << "Quantity cannot be negative" << endl;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "Enter cost: ";
                while (!(cin >> cost))
                {
                    cout << "Enter an float value" << endl;
                    cout << "Enter cost: ";
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
                if (cost < 0)
                {
                    cout << "Cost cannot be negative" << endl;
                }
                else
                {
                    break;
                }
            }
            rec.putData(name, itemCode, quantity, cost);
            vec.push_back(rec);
            cout << "Record Added\n";
            break;
        }
        case 2:
        {
            cout << "Enter item code to be searched: ";
            cin >> itemCode;
            bool f1 = false;
            for (auto it = vec.begin(); it != vec.end(); ++it)
            {
                if (itemCode == it->getcode())
                {
                    cout << "Name\titem code\t\tquantity\t\tcost\n";
                    it->display();
                    f1 = true;
                }
            }
            if (!f1)
            {
                cout << "Record not Found\n";
            }
            break;
        }
        case 3:
        {
            len = vec.size();
            if (len == 0)
            {
                cout << "No Records Available\n";
                break;
            }
            sort(vec.begin(), vec.end(), &comparator);
            cout << "All the records are sorted\n";
            break;
        }
        case 4:
        {
            len = vec.size();
            if (len == 0)
            {
                cout << "No Records\n";
                break;
            }
            cout << "Name\titem code\t\tquantity\t\tcost\n";
            for (auto it = vec.begin(); it != vec.end(); it++)
            {
                it->display();
            }
            break;
        }

        case 5:
        {
            cout << "Good Bye\n";
            break;
        }
        default:
        {
            cout << "Invalid Input";
        }
        }
    } while (ch != 5);
    return 0;
}
