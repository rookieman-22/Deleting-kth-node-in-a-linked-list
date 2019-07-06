#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
node *insert(node *head,int x)
{
    node *temp=new node[4];
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
        return head;
    }
    else
    {
        node *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
        return head;
    }
}
void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
}
node* delete1(node *head,int pos)
{
    node *temp=head;
    if(pos==1)
    {
        head=temp->next;
        free(temp);
        return head;
    }
    else{
        node* temp1=head;
        for(int i=0;i<pos-1;i++)
        {
            temp1=temp1->next;
        }
        while(temp->next!=temp1)
        {
            temp=temp->next;
        }
        temp->next=temp1->next;
        free(temp1);
        return head;
    }
}
int main()
{
    head=NULL;int pos;
    head=insert(head,5);
    head=insert(head,6);
    head=insert(head,4);
    head=insert(head,12);
    head=insert(head,11);
    head=insert(head,0);
    head=insert(head,-1);
    print(head);
    cout<<"Enter the position at which you want to delete: ";
    cin>>pos;
    head=delete1(head,pos);
    print(head);


}
