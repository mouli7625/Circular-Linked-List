#include<iostream>
#include<map>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
void insert(Node* &tail, int ele ,int d)
{
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else
    {
        Node* curr=tail;
        while ((curr->data!=ele))
        {
            curr=curr->next;
        }
         Node* temp=new Node(d);
         temp->next=curr->next;
         curr->next=temp;
    }
}
void print(Node* tail)
{
        Node* temp=tail;
         if(tail == NULL) 
		 {
        cout << "List is Empty "<< endl;
        }
        do
        {
            cout<<tail->data<<" ";
            tail=tail->next;
            /* code */
        }while(tail!=temp);
        cout << endl; 
}
int main()
{
    Node* tail=NULL;
    insert(tail, 5,3);
    insert(tail, 3,2);
    insert(tail,3,1);
     insert(tail,2,10);
    print(tail);
    return 0;
}
