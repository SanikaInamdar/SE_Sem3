#include<iostream>
using namespace std;

void check(){
    int ar[10];
    int *n;
    for(int i=0;i<10;i++)
    {
        cout<<"Enter array number at ["<<i<<"] = ";cin>>ar[i];
    }
    n=ar;
    int num;
    cout<<"Enter the number to get it checked"<<endl;
    cin>>num;
    bool f=false;
    for(int i=0;i<10;i++)
    {

        if (*(n+i)==num){f=true;break;}
    }
    if (f)cout<<"It is Present in the array"<<endl;
    else cout<<"It is Not Present in the array"<<endl;
}

int main(){
    check();
    return 0;
}