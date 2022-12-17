/*
File handling assignment::
Write C++ program that creates an output file,writes information to it , and closes the file
and open it again as an input file and read the information from
*/

#include <iostream>
#include <fstream>
using namespace std;

string cs = "#";

class file
{
    string s1, line, ap;

public:
    void read_file(string name)
    {
        ifstream read;            // Creating the object for input stream
        read.open(name, ios::in); // Opening the file in read mode
        if (read.is_open())       // Chech whether file is opened or not
        {
            cout << "File is opened" << endl;
        }
        else
        {
            cout << "Error while opening the file." << endl;
        }

        // string s1;
        cout << "\n**Data in the files**" << endl;
        while (!read.eof())
        {
            getline(read, s1);
            cout << s1 << endl;
        }
        read.close();
    }

    void write_file(string name)
    {
        ofstream write;             // Creating the object of output class
        write.open(name, ios::out); // Opening the file in write mode
        if (write.is_open())        // Chech whether file is opened or not
        {
            cout << "\nFile is opened!!" << endl;
        }
        else
        {
            cout << "\nError in opening the file" << endl;
        }
        string line;
        cout << "\nAdd # at the end of the written data to write in the file" << endl;
        cout << "\n****Enter your data****" << endl;
        cin.ignore();
        cout << "\n" << endl;
        while (true)
        {
            getline(cin, line);
            if (cs.compare(0, 2, line) == 0)
            {
                break;
            }
            write << line << endl;
        }
        /*getline(cin, line, '~');
        write << line << endl;*/
        write.close();
    }

    void append_file(string name)
    {
        fstream app;              // Creating the of fstream class, which carries both input and output function
        app.open(name, ios::app); // Opening the file in appended mode
        if (app.is_open())        // Chech whether file is opened or not
        {
            cout << "\nFile is opened!!" << endl;
        }
        else
        {
            cout << "\nError in opening the file" << endl;
        }
        string ap;
        cout << "\nAdd # at the end of the written data to append in the file" << endl;
        cout << "\n****Enter your data****" << endl;
        cin.ignore();
        cout << "\n";
        while (true)
        {
            getline(cin, ap);
            if (cs.compare(0, 2, ap) == 0)
            {
                break;
            }
            app << ap << endl;
        }
        app.close();
    }
};

int main()
{
    bool b1 = false;
    int choice;
    file f1;
    bool success = false;
    int option;
    string name;
    while (true)
    {
        cout << "\n1.To create and open file \n2.To open the file which is already created.\n3.To exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the name of the file: ";
            cin.ignore();
            getline(cin, name);
            ofstream fout(name); // Creating a file.
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter the name of the file: ";
            cin.ignore();
            getline(cin, name);
            break;
        }
        else if(choice == 3)
        {
            cout << "ThankYou!!!" << endl;
            break;
        }
        else
        {
            cout << "Enter the write choice" << endl;
        }
    }

    fstream file1(name); // It will check whether the file is opened or not

    if (file1.is_open())
    {
        cout << "Your file is opened is successfully" << endl;
        success = true;
    }
    else
    {
        string input;
        cout << "the file does noe exist" << endl;
        cout<<"do you want to create a new file"<<endl;
        cin>>input;
        if(input=="yes"){
            cout << "Enter the name of the file: ";
            cin.ignore();
            getline(cin, name);
            ofstream fout(name); // Creating a file.
            while (true)
        {
            cout << "\n1.Read \n2.Write \n3.Append. \n4.To exit the operations " << endl;
            cout << "\nEnter the option: ";
            cin >> option;
            
            switch (option)
            {
            case 1:
                f1.read_file(name);
                break;
            case 2:
                f1.write_file(name);
                break;
            case 3:
                f1.append_file(name);
                break;
            case 4:
                b1 = true;
            default:
                break;
            }
            if(b1)
            {
                cout << "Program exited successfully" << endl;
                break;
            }
            
        }
            

        }
    }

    if (success)
    {
        while (true)
        {
            cout << "\n1.Read \n2.Write \n3.Append. \n4.To exit the operations " << endl;
            cout << "\nEnter the option: ";
            cin >> option;
            
            switch (option)
            {
            case 1:
                f1.read_file(name);
                break;
            case 2:
                f1.write_file(name);
                break;
            case 3:
                f1.append_file(name);
                break;
            case 4:
                b1 = true;
            default:
                break;
            }
            if(b1)
            {
                cout << "Program exited successfully" << endl;
                break;
            }
            
        }
    }
else
{
    cout << "ThankYou!!!!" << endl;
}

    return 0;
}
