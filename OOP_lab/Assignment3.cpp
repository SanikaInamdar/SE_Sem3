
// Imagine a publishing company which does marketing for book and audio cassette versions.
// Create a class publication that stores the title (a string) and price (type float) of publications.
// From this class derive two classes: book which adds a page count (type int) and tape which adds a
// playing time in minutes (type float). Write a program that instantiates the book and tape class, allows
// user to enter data and displays the data members. If an expection is caught, replace all the data member
// values with zero values.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class publication
{
protected:
    string title;
    float price;

public:
    publication() // Default Constructor which set the values to Zero
    {
        title = "";
        price = 0;
    }
};

class book : public publication{ // book class is public inherited by class publication
protected:
    int page_count;

public:
    book()
    {
        page_count = 0;
        book_count++;
    }

    static int book_count;
    
    void set_book_details()
    {
        while (1)
        {
            try
            {
                cout << "Enter Title of Book : ";
                cin.ignore();
                getline(cin, title);
                if (!(title.length()))
                {
                    throw title;
                }

                cout << "Enter Price of Book : ";
                if (!(cin >> price) || price < 0)
                {
                    price = 0;
                    throw price;
                }

                cout << "Enter Total Pages of Book : ";
                if (!(cin >> page_count) || page_count < 0)
                {
                    page_count = 0;
                    throw page_count;
                }

                cout << "\nBook Details are Saved Successfully." << endl;
                break;
            }

            catch (string t)
            {
                cout << "\nYou Entered a invalid Title of Book and All the Details are set Zero." << endl;
                break;
            }

            catch (float p)
            {
                cout << "\nYou Entered a invalid Price of Book and All the Details are set Zero." << endl;
                title = "";
                price = 0;
                break;
            }

            catch (int p_c)
            {
                cout << "\nYou Entered a invalid Pages of Book and All the Details are set Zero." << endl;
                title = "";
                price = 0;
                page_count = 0;
                break;
            }
        }
    }

    string get_book_title()
    {
        return title;
    }

    void get_book_details()
    { // Prints the Details of book
        cout << "\nDetails of Book is : " << endl;
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Page Count : " << page_count << endl;
    }

    static int get_book_count() // Static Member Function
    {
        return book_count;
    }
};

class tape : public publication{ // tape class is public inherited by class publication
protected:
    float playing_time;

public:
    static int tape_count;
    tape()
    {
        playing_time = 0;
        tape_count++;
    }

    void set_tape_details()
    {
        while (1)
        {
            try
            {
                cout << "Enter Title of Tape : ";
                cin.ignore();
                getline(cin, title);
                if (!(title.length()))
                {
                    throw title;
                }

                cout << "Enter Price of Tape : ";
                if (!(cin >> price) || price < 0)
                {
                    price = 0;
                    throw price;
                }

                cout << "Enter Playing Time of Tape in Minutes : ";
                if (!(cin >> playing_time) || playing_time < 0)
                {
                    playing_time = 0;
                    throw 1;
                }

                cout << "\nTape Details are Saved Successfully." << endl;
                break;
            }

            catch (string t)
            {
                cout << "\nYou Entered a invalid Title of Tape and All the Details are set Zero." << endl;
                break;
            }

            catch (float p)
            {
                cout << "\nYou Entered a invalid Price of Tape and All the Details are set Zero." << endl;
                title = "";
                price = 0;
                break;
            }

            catch (int p_t)
            {
                cout << "\nYou Entered a invalid Playing Time of Tape and All the Details are set Zero." << endl;
                title = "";
                price = 0;
                playing_time = 0;
                break;
            }
        }
    }

    string get_tape_title()
    {
        return title;
    }

    void get_tape_details()
    { // Prints the Details of Tape
        cout << "\nDetails of Tape is : " << endl;
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Playing Time : " << playing_time << endl;
    }

    static int get_tape_count() // Static Member Function
    {
        return tape_count;
    }
};

int book::book_count; // Declaring book_count(static data member) as Global Variable
int tape::tape_count; // Declaring tape_count(static data member) as Global Variable

int main(){
    vector<book> vec_book;
    vector<tape> vec_tape;

    int choice,title_found = 0;
    string search_title;

    while (1)
    {
        cout<<"\n*******************************************************"<<endl;
        cout << "Total Number of Books : " << book::book_count << endl;
        cout << "Total Number of Tapes : " << tape::tape_count << endl;
        cout << "\n****** MENU ******" << endl;
        cout << "1.Add Book Or Tape" << endl;
        cout << "2.Delete Book Or Tape" << endl;
        cout << "3.Read Book Or Tape" << endl;
        cout << "4.Read All Books and Tapes" << endl;
        cout << "5.Exit Program" << endl;

        cout << "\nEnter Choice from Above menu : ";
        while (!(cin >> choice))
        {
            cout << "Enter a Integer." << endl;
            cout << "\nEnter Choice from Above menu : ";
            cin.clear();
            cin.ignore(1000000000, '\n');
        }

        if (choice == 1)
        {
            while (1)
            {
                cout<<"*******************************************************"<<endl;
                cout << "\nTotal Number of Books : " << book::book_count << endl;
                cout << "Total Number of Tapes : " << tape::tape_count << endl;
                cout << "\n****** MENU ******" << endl;
                cout << "1.Add Book" << endl;
                cout << "2.Add Tape" << endl;
                cout << "3.Exit" << endl;

                cout << "\nEnter Choice from Above menu : ";
                while (!(cin >> choice))
                {
                    cout << "Enter a Integer." << endl;
                    cout << "\nEnter Choice from Above menu : ";
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }

                if (choice == 1)
                {
                    book bk;
                    bk.set_book_details();
                    vec_book.push_back(bk);
                }

                else if (choice == 2)
                {
                    tape tp;
                    tp.set_tape_details();
                    vec_tape.push_back(tp);
                }

                else if (choice == 3)
                {
                    break;
                }

                else
                {
                    cout << "\nEnter a Choice in the Range 1 to 3" << endl;
                }
            }
        }

        else if (choice == 2)
        {
            if (book::book_count + tape::tape_count != 0)
            {
                while (1)
                {
                    cout<<"\n*******************************************************"<<endl;
                    cout << "\nTotal Number of Books : " << book::book_count  << endl;
                    cout << "Total Number of Tapes : " << tape::tape_count << endl;
                    cout << "\n****** MENU ******" << endl;
                    cout << "1.Delete Book" << endl;
                    cout << "2.Delete Tape" << endl;
                    cout << "3.Exit" << endl;

                    cout << "\nEnter Choice from Above menu : ";
                    while (!(cin >> choice))
                    {
                        cout << "Enter a Integer." << endl;
                        cout << "\nEnter Choice from Above menu : ";
                        cin.clear();
                        cin.ignore(1000000000, '\n');
                    }

                    if (choice == 1)
                    {
                        if (book::book_count != 0)
                        {
                            try
                            {
                                cout << "Enter Title of Book to be Deleted : ";
                                cin.ignore();
                                getline(cin, search_title);
                                if (!(search_title.length()))
                                {
                                    throw 0;
                                }
                            }
                            catch (int exp)
                            {
                                cout << "You Entered a invalid Title of Book." << endl;
                                break;
                            }
                            for (auto check_book = vec_book.begin(); check_book != vec_book.end(); check_book++)
                            {
                                if (search_title == check_book->get_book_title())
                                {
                                    vec_book.erase(check_book);
                                    cout<<"\n"<<search_title<<" Book Details are Deleted Successfully"<<endl;
                                    -- book::book_count;
                                    title_found = 1;
                                    break;
                                }
                            }

                            if(title_found){
                                title_found = 0;
                            }
                            else{
                                cout << "\nBook with Title " << search_title << " is not Present is Database." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nBooks are not yet Added in Database." << endl;
                        }
                    }

                    else if (choice == 2)
                    {
                        if (tape::tape_count != 0)
                        {
                            try
                            {
                                cout << "Enter Title of Tape to be Deleted : ";
                                cin.ignore();
                                getline(cin, search_title);
                                if (!(search_title.length()))
                                {
                                    throw 0;
                                }
                            }
                            catch (int exp)
                            {
                                cout << "You Entered a invalid Title of Tape." << endl;
                                break;
                            }
                            for (auto check_tape = vec_tape.begin(); check_tape != vec_tape.end(); check_tape++)
                            {
                                if (search_title == check_tape->get_tape_title())
                                {
                                    vec_tape.erase(check_tape);
                                    cout<<"\n"<<search_title<<" Tape Details are Deleted Successfully"<<endl;
                                    -- tape::tape_count;
                                    title_found = 1;
                                    break;
                                }
                            }
                            
                            if(title_found){
                                title_found = 0;
                            }
                            else{
                                cout << "\nTape with Title " << search_title << " is not Present is Database." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nTapes are not yet Added in Database." << endl;
                        }
                    }

                    else if (choice == 3)
                    {
                        break;
                    }

                    else
                    {
                        cout << "\nEnter a Choice in the Range 1 to 3" << endl;
                    }
                }
            }

            else
            {
                cout << "\nData is not yet Created in Database." << endl;
            }
        }

        else if (choice == 3)
        {
            if (book::book_count + tape::tape_count != 0)
            {
                while (1)
                {
                    cout<<"\n*******************************************************"<<endl;
                    cout << "\nTotal Number of Books : " << book::book_count << endl;
                    cout << "Total Number of Tapes : " << tape::tape_count << endl;
                    cout << "\n****** MENU ******" << endl;
                    cout << "1.Read Book" << endl;
                    cout << "2.Read Tape" << endl;
                    cout << "3.Exit" << endl;

                    cout << "\nEnter Choice from Above menu : ";
                    while (!(cin >> choice))
                    {
                        cout << "Enter a Integer." << endl;
                        cout << "\nEnter Choice from Above menu : ";
                        cin.clear();
                        cin.ignore(1000000000, '\n');
                    }

                    if (choice == 1)
                    {
                        if (book::book_count != 0)
                        {
                            try
                            {
                                cout << "Enter Title of Book to Read Details : ";
                                cin.ignore();
                                getline(cin, search_title);
                                if (!(search_title.length()))
                                {
                                    throw 0;
                                }
                            }
                            catch (int exp)
                            {
                                cout << "You Entered a invalid Title of Book." << endl;
                                break;
                            }

                            for (auto check_book = vec_book.begin(); check_book != vec_book.end(); check_book++)
                            {
                                if (search_title == check_book->get_book_title())
                                {
                                    check_book->get_book_details();                                
                                    title_found = 1;
                                    break;
                                }
                            }

                            if(title_found){
                                title_found = 0;
                            }
                            else{
                                cout << "\nBook with Title " << search_title << " is not Present is Database." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nBooks are not yet Added in Database." << endl;
                        }
                    }

                    else if (choice == 2)
                    {
                        if (tape::tape_count != 0)
                        {
                            try
                            {
                                cout << "Enter Title of Tape to Read Details : ";
                                cin.ignore();
                                getline(cin, search_title);
                                if (!(search_title.length()))
                                {
                                    throw 0;
                                }
                            }
                            catch (int exp)
                            {
                                cout << "You Entered a invalid Title of Tape." << endl;
                                break;
                            }
                            for (auto check_tape = vec_tape.begin(); check_tape != vec_tape.end(); check_tape++)
                            {
                                if (search_title == check_tape->get_tape_title())
                                {
                                    check_tape->get_tape_details();                                
                                    title_found = 1;
                                    break;
                                }
                            }

                            if(title_found){
                                title_found = 0;
                            }
                            else{
                                cout << "\nTape with Title " << search_title << " is not Present is Database." << endl;
                            }
                        }
                        else
                        {
                            cout << "\nTapes are not yet Added in Database." << endl;
                        }
                    }

                    else if (choice == 3)
                    {
                        break;
                    }

                    else
                    {
                        cout << "\nEnter a Choice in the Range 1 to 3" << endl;
                    }
                }
            }

            else
            {
                cout << "\nData is not yet Created in Database." << endl;
            }
        }

        else if (choice == 4)
        {
            cout<<"\n*******************************************************"<<endl;
            if (book::book_count + tape::tape_count != 0)
            {
                if (book::book_count != 0)
                {
                    cout << "\n*** Details of All Book ***" << endl;
                    for (auto display_book = vec_book.begin(); display_book != vec_book.end(); display_book++)
                    {
                        display_book->get_book_details();
                    }
                }
                else
                {
                    cout << "\nBooks are not yet Added in Database." << endl;
                }

                cout<<"\n*******************************************************"<<endl;
                if (tape::tape_count != 0)
                {
                    cout << "\n*** Details of All Tape ***" << endl;
                    for (auto display_tape = vec_tape.begin(); display_tape != vec_tape.end(); display_tape++)
                    {
                        display_tape->get_tape_details();
                    }
                }
                else
                {
                    cout << "\nTapes are not yet Added in Database." << endl;
                }
            }

            else
            {
                cout << "\nData is not yet Created in Database." << endl;
            }
    }

    else if (choice == 5)
    {
        cout << "\nThank You." << endl;
        break;
    }

    else
    {
        cout << "\nEnter a Choice in the Range 1 to 5" << endl;
    }
}

return 0;
}
