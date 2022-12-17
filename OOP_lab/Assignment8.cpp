
/*
Write a function template for selection sort that inputs, sorts and outputs an integer array 
and a float array.*/

#include<iostream>
#define size 100
using namespace std;
bool go=true;
int n;
char c;
template<class T>
void selection_sort (T Arr[])
{
    T num;
    for(int i = 0; i < n-1; i++) //Outer for loop to traverse through the array.
    {
        int min=i;              // Setting first element as  minimum . 
        for (int j = i+1; j <n;j++)//Inner for loop to find element smallest in the array and swapping it 
        {                          // with min 
            if(Arr[j] < Arr[min])
            {
                min=j;
            }
        };
        if(min!=i)
        {
            num=Arr[i];
            Arr[i]=Arr[min];;
            Arr[min]=num;
        };
    }
    cout<<"The sorted list is : ";
    int x;
    for (x=0; x < n; x++)// Printing the array in sorted order.
        cout << Arr[x] << " ";
    cout << endl;

}
int main()
{
int arr_1[size];//defining array as int type
float arr_2[size];//defining array as float type

int choice;//To take input for operation to be executed.
int i;
char ans;
do
    {
		while(go)
		{
			try
			{
				cout<<"\nEnter total no of elements : ";
    			if ((cin>>n))
				{
					cin.get(c);
					if(c!='\n')
					{
					throw 0;
					cin.clear();
					}
				
				else
				{
				  go=false;
				}
				}
				else
				{throw 1;
				}
			}
			catch(...)
			{
				cout<<"Enter number";
				cin.clear();
				cin.ignore(100000000,'\n');
				
			}
		}
			go=true;
    	cout<<"1)to sort integer elements";
    	cout<<"\n2)to sort float elements\n3).Exit\n";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1 : 
   					 
    				for(i=0;i<n;i++)
    				{
						bool goo=true;
						while (goo)
						{
							try
							{
								cout<<"\nEnter "<<i<<"th element : \n";
							if((cin>>arr_1[i]))
							{
								cin.get(c);
								if(c!='\n')
								{
								throw arr_1[i];
								cin.clear();
								}
								else
								{goo=false;}
							}
							else{
								throw 1;
							}
							}
							catch(...)
							{
								cout<<"Input should be an integer";
								cin.clear();
								cin.ignore(100000000,'\n');
							}
						}
					}
    				selection_sort<int>(arr_1);
    				
    				break;
    		case 2 :
			for(int i=0;i<n;i++)
			{
							cout<<"\nEnter "<<i<<"th element : \n";
							cin>>arr_2[i];
			}
    				selection_sort<float>(arr_2);
    				break;
    			
    		case 3: exit(0);
    		default : cout<<"\nIncorrect choice \n";
    	}
    	cout<<"\nWant to continue ? \n";
    	cin>>ans;
	}while(ans=='y');
return 0;
}
