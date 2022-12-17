#include <iostream>
#include <string.h>
using namespace std;
class student
{

	char *name,*address,*blood_grp;
	char *roll,*division,*telephone;
public:
	student()
	{
		this->name=new char;
		this->name="";
		this->address=new char;
		this->address="";
		this->blood_grp=new char;
		this->blood_grp="";
		this->roll=new char;
		this->roll="";
		this->division=new char;
		this->division="";
		this->telephone=new char;
		this->telephone="";


	}
	student(char *name,char *address,char *blood_grp,char *roll,char *division, char *telephone)
	{
		int length=strlen(name);
		this->name=new char[length];
		this->name=name;
		int length1=strlen(address);
		this->address=new char[length1];
		this->address=address;
		int length2=strlen(blood_grp);
		this->blood_grp=new char[length2];
		this->blood_grp=blood_grp;
		int length3=strlen(roll);
		this->roll=new char[length3];
		this->roll=roll;
		int length4=strlen(division);
		this->division=new char[length4];
		this->division=division;
		int length5=strlen(telephone);
		this->telephone=new char[length5];
		this->telephone=telephone;
	}
	student(student &obj)
	{

		this->name=obj.name;

		this->address=obj.address;

		this->blood_grp=obj.blood_grp;

		this->roll=obj.roll;

		this->division=obj.division;

		this->telephone=obj.telephone;

	}
	static string det;
	static void details()
	{
		cout<<"***********"<<det<<"*************"<<endl;
	}
    ~student()
	{
    	delete roll;
    	delete division;
    	delete name;
    	delete telephone;
    	delete blood_grp;
    	delete address;
    	cout<<"Thank you for deleting details"<<endl;

	}

	friend ostream &operator<<( ostream &output,  student &s1 );
	friend istream &operator>>( istream  &input, student &s1 );
	void getdata();
	friend class calper;
};

class calper
{
	int total;
	float marks,per;
public:
	 void percent(student &s2)
	 {
			cout<<"Enter your marks"<<endl;
			cin>>marks;
			cout<<"Enter total marks";
			cin>>total;
			try
			{
				if(total==0)
				{
					throw total;
				}
			}
			catch(int total)
			{
				cout<<"This value is not valid"<<endl;
			}
			per=(marks/total)*100;
			cout<<"Roll number "<<s2.roll<<" your percentage is "<<per<<endl;

	 }
};

 string student::det="Student details";

 ostream &operator<<( ostream &output,  student &s1 ){
	 output << "Blood Group is "<<s1.blood_grp << " ,Name is " << s1.name<<" ,Address is "<<s1.address<<" ,Roll number is  "<<s1.roll << " ,Telephone number is " << s1.telephone<<" ,Division is "<<s1.division;
		         return output;}

 istream &operator>>( istream  &input, student &s1 )
 	      {
 	            input>>s1.blood_grp>>s1.name>>s1.address>>s1.roll>>s1.telephone>>s1.division;
 	            return input;
 	      }
 inline void student::getdata()
 	 	 {
 		 	 cout<<"Enter name";
 		 	 name=new char;
 		 	 cin>>name;
 		 	 cout<<"Enter address";
 		 	 address=new char;
 		 	 cin>>address;
 		 	cout<<"Enter blood group";
 		 	 blood_grp=new char;
			 cin>>blood_grp;
			 cout<<"Enter roll number";
 		 	 roll=new char;
			 cin>>roll;
			 cout<<"Enter telephone number";
			 telephone=new char;
			 cin>>telephone;
			 cout<<"Enter division";
			 division=new char;
			 cin>>division;
 	 	 }


int main()
{
	student s1,s2;
	calper cc1;


	s2.getdata();
	student s3=s2;

	student::details();
	cout<<s1<<endl;
	cout<<s2<<endl;
	cc1.percent(s2);
	cout<<s3<<endl;
	s3.~student();



	return 0;
}


