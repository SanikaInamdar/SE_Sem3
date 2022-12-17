//! Author: Rohan Doshi 21126
//? Problem Statement:
/*
Write a C++ program to have a class that represents an integer vector and define following functions to perform vector operations :
1.Initialize the vector with zero
2.Overload the >> operator to accept the element of vector
3.Display the vector elements by overloading the << operator
4.Multiply the vector with an integer (i.e. 2*obj)
5.Implementation any other two operations related to vectors (Eg. Inserting element beyond vector size, etc.)
*/

#include <iostream>
using namespace std;

class Vector
{
private:
    int size;
    int c_Size; // required for push operataion to see if space is present or new space has to be allocated
    int *vector_array;

public:
    Vector(int);
    ~Vector();

    friend istream &operator>>(istream &input, Vector &obj)
    {
        input >> *(obj.vector_array);
        return input;
    }

    friend ostream &operator<<(ostream &output, Vector obj)
    {
        output << obj.vector_array;
        return output;
    }

    int &operator[](int limit)
    {
        if (limit >= size)
        {
            cout << "Array out of limit";
            exit(0);
        }
        return vector_array[limit];
    }

    float operator*(float p)
    {
        return p * (*vector_array);
    }

    void Space_Alloc(int x)
    {
        if (c_Size == size)
        {
            int temp[size];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = vector_array[i];
            }
            size++;
            c_Size++;
            delete[] vector_array;
            vector_array = new int[size];
            for (size_t i = 0; i < size - 1; i++)
            {
                vector_array[i] = temp[i];
            }
            vector_array[size - 1] = x;
        }
        else
        {
            vector_array[c_Size] = x;
            c_Size++;
        }
    }

    int show()
    {
        int temp = vector_array[c_Size - 1];
        vector_array[c_Size - 1] = 0;
        c_Size--;
        return temp;
    }
};

Vector::Vector(int size)
{
    this->size = size;
    this->c_Size = size;
    vector_array = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        vector_array[i] = 0;
    }
}

Vector::~Vector()
{
    delete[] vector_array;
}

int main()
{
    Vector v1(10);
    v1[1] = 10;
    cin >> v1[1] >> v1[2];
    cout << v1[1] << " " << v1[2] << endl;
    v1[2] = 2 * v1[2];
    cout << v1[2] << endl;
    // cout << v1[11];
    v1.Space_Alloc(10);
    cout << v1[10] << endl;
    cout << v1.show() << endl;
    v1.Space_Alloc(15);
    cout << v1[10] << endl;
    v1.Space_Alloc(12);
    cout << v1[11] << endl;
    return 0;
}