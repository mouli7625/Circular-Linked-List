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
     ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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
void deleteNode(Node* &tail, int value) {
    if(tail == NULL) 
	{
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
	{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) 
		{
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        if(curr == prev) 
		{
            tail = NULL;
        }
        else if(tail == curr ) 
		{
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

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
    //insertion
    insert(tail, 5,3);
    insert(tail, 3,2);
    insert(tail,3,1);
     insert(tail,2,10);
    print(tail);
    //deletion
    deleteNode(tail, 1);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 2);
    print(tail);
    deleteNode(tail, 10);
    print(tail);
    return 0;
}
