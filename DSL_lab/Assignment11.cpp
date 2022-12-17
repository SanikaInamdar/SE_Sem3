#include <iostream>
#include <string>
 
using namespace std;
 
class Node{
    private:
    string job_name;
    Node *next;
 
    public:
    Node(string job_name){
        this->job_name = job_name;
        next = NULL;
    }
 
    friend class Queue;
};
 
class Queue{
    private:
    Node *front;
    Node *rear;
 
    public:
 
    Queue(){
        front = NULL;
        rear = NULL;
    }
 
    bool empty(){
        if (front == NULL)
        {
            return true;
        }else{
            return false;
        }
    }
 
    void enqueue(string job_name){
 
        Node * temp = new Node(job_name);
 
        if (empty() == true)
        {
            front = temp;
            rear = temp;
        }else{
            rear->next = temp;
            rear = temp;
        }
    }
 
    void dequeue(){
 
        if (empty() == false)
        {
            Node *temp = front;
            front = front->next;
            cout<<"Dequeueing successful....\n";
            delete(temp);
 
        }else{
            cout<<"The queue is empty...\n";
        }
    }
 
    void display(){
 
        if (empty() == false)
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout<<"Job : "<<temp->job_name<<endl;
                temp = temp->next;
            }    
        }else{
            cout<<"Queue is empty....\n";
        }    
    }
 
};
 
int main(){
   
    Queue q;
    string job;
    int choice;
 
   
    while (choice != 4)
    {
        cout<<"\n*****************Main Menu*****************\n";
        cout<<"1. Add a job to the queue\n2. Display the job queue\n3. Dequeue a job\n4. Exit\n";
        cout<<"*******************************************\n\n";
 
        cout<<"Enter your choice: ";
        cin>>choice;
 
        switch (choice)
        {
        case 1:
            cout<<"Enter the name of the job you want to add to queue: ";
            cin.ignore();
            getline(cin, job);
            q.enqueue(job);
            break;
       
        case 2:
            cout<<"The job queue is: \n";
            q.display();
            break;
 
        case 3:
            q.dequeue();
            break;
 
        case 4:
            cout<<"Thank you\nExiting.....\n";
            break;
 
        default:
            cout<<"Enter a valid choice from the menu...\n";
            q.display();
            break;
        }
    }
   
   
    return 0;
}
 