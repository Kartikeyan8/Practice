#include<bits/stdc++.h>
using namespace std;
// class Node{
//    public:
//     Node* front=NULL;
//     Node* rear=NULL;
//     int data;
//     Node* next;
//     Node(int v)
//     {
//         data=v;
//         next=NULL;
//     }
// };
// class Queue{
//     public:
//     int size=0;
//     void enqueue(int v)
//     {
        
//         Node* temp=new Node(v);
//         if(temp==NULL)
//         {
//             cout<<"full";
//         }
//         else {
//             if(front==NULL)
//             {
//                 front=rear=temp;
//             }
//             else {
//                 rear->next=temp;
//                 rear=temp;
//             }
//         }
//         size++;
//     }
//     bool isempty()
//     {
//         if(front==NULL)
//         {
//             return true;

//         }
//         else {
//             return false;
//         }
//     }
//     void peek()
//     {
//         if(q.empty())
//         {
//             cout<<"empty";
//         }
//         else {
//             cout<<q.front()->data;
//         }
//     }
// };
struct Node{
    int data;
    Node* next;
    Node(int v)
    {
        data=v;
        next=NULL;
    }

};
Node* cycle_remove(Node* head)
{
    if(head==NULL)
    {
        return head;
    }
    Node* slow=head,*fast=head;
    Node* cur=head;
    bool flag=false;
    while(fast && fast->next )
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            {
                flag=true;
                break;
            }
    }
    if(flag)
    {
        slow=head;
        if(slow==fast)
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
        else{
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }    
        
    }
    fast->next=NULL;
    cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    
    return head;
}
void reorder_list(Node* head)
{
    Node* cur=head;
    int size=0;
    stack<Node* >s;
    while(cur->next)
    {
        
        size++;
        s.push(cur);
        cur=cur->next;
    }
    cur=head;
    for(int i=0;i<size/2;i++)
    {
        auto temp=s.top();
        s.pop();
        temp->next=cur->next;
        cur->next=temp;
        cur=cur->next->next;

    }
    cur->next=NULL;
    cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }

}
// Node* merge_list(Node* head1,Node* head2)
// {
//     Node* temp=new Node(0);
//     Node* tail=temp;
//     while(head1!=NULL and head2!=NULL)
//     {
//         if(head1->val>=head2->val)
//         {
//             tail->next=head2;
//             head2=head->next;
//         }
//         else {
//             tail->next=head1;
//             head1=head1->next;
//         }
//         tail=tail->next;
//     }
    
//     return temp->next;
// }
// void merge_list_main()
// {
//     vector<vector<Node*>>v={{1,2,3},{4,5,6},{7,8,9}};
//     Node* dummy=new Node(0);
//     Node* cur=dummy;
//     for(auto it:v)
//     {
//         cur=merge_list(cur,it);
//     }
//     cur=dummy->next;
//     while(cur!=NULL)
//     {
//         cout<<cur->data<<" ";
//         cur=cur->next;
//     }
// }
Node* reverse(Node* head)
{
    if(!head or !head->next)
    {
        return head;
    }
    auto temp=reverse(head->next);
    head->next->next=head;

    head->next=NULL;
    return temp;
}
void print(Node* head)
{
    Node* cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}
// struct stacknode{
//     int data;
//     stacknode* next;
//     stacknode(int d)
//     {
//         data=d;
//         next=NULL;
//     }
// };
// struct topstack{
//     stacknode* top;
//     int size;
//     topstack()
//     {
//         top=NULL;
//         size=0;
//     }
    
//     void push(int data)
//     {
//         stacknode* temp=new stacknode(data);
//         temp->next=top;
//         top=temp;
//         size++;
//     }
   
//     void pop()
//     {
//         if(size==0)
//         {
//             cout<<"err";
//             return;
//         }        
//         stacknode* temp=top;
//         top=top->next;
//         delete temp;
//         size--;
//         return;
//     }
//     void print()
//     {
//         stacknode* cur=top;
//         while(cur!=NULL)
//         {
//             cout<<cur->data<<" ";
//             cur=cur->next;
//         }
//     }
// };
// class queuenode{
//     int data;
//     queuenode* next;
//     queuenode* front=NULL,*rear=NULL;
//     queuenode(int a)
//     {
//         next=NULL;
//         data=a;
//     }
// };
// class queues{
//     queuenode* front
// }
void delete_node(Node* head)
{
    Node* cur=head;
    int k=0;
    while(k>0)
    {
        cur=cur->next;
        k--;
    }
    Node* temp=cur->next;
    cur->next=temp->next;
    delete temp;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
void swapping(Node* head)
{
    Node* cur=head;
    int x=1;
    int y=3;
    Node* prevx=NULL,*prevy=NULL;
    Node* curx=head,*cury=head;
    while(curx!=NULL and curx->data!=x)
    {
        prevx=curx;
        curx=curx->next;
    }
    while(cury!=NULL and cury->data!=y)
    {
        prevy=cury;
        cury=cury->next;
    }
    prevx->next=cury;
    prevy->next=curx;

    Node* temp=cury->next;
    cury->next=curx->next;
    curx->next=temp;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

    
}
void odd_even(Node* head)
{
    Node* cur=head;
    Node* even_head=new Node(0),*even_tail=even_head;
    int c=1;
    Node* odd_head=new Node(0),*odd_tail=odd_head;
    while(cur!=NULL)
    {
        if(c==1)
        {
            odd_tail->next=cur;
            odd_tail=odd_tail->next;
        }
        else{
            even_tail->next=cur;
            even_tail=even_tail->next;
        }
        c=1-c;
        cur=cur->next;
    }
    odd_tail->next=even_head->next;
    even_tail->next=NULL;
    while(odd_head)
    {
        cout<<odd_head->data<<" ";
        odd_head=odd_head->next;
    }
}
// class doubnode{
//     public:
//     int data;
//     doubnode* next;
//     doubnode* prev;
//     doubnode(int d)
//     {
//         data=d;
//         next=NULL;
//         prev=NULL;
//     }
// };
// void insert(doubnode* &head,int val)
// {
//     doubnode* temp=new doubnode(val);
//     if(head==NULL)
//     {
//         head=temp;
//         return;
//     }
//     doubnode* cur=head;
//     while(cur->next)
//     {
//         cur=cur->next;
//     }
//     cur->next=temp;
//     temp->prev=cur;

// }
// void disp(doubnode* head)
// {
//     doubnode* cur=head;
//     while(cur->next)
//     {
        
//         cur=cur->next;
//     }
//     while(cur!=NULL)
//     {
//         cout<<cur->data<<" ";
//         cur=cur->prev;
//     }
//         // head=head->next;
    
// }
Node* r1everse(Node* head)
{

    auto temp=head;
    Node* cur=head;
    Node* prev=NULL;

    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
   
   return prev;
    
}
void r1otate(Node* head)
{
    Node* cur=head;
    int k=2;
    int len=1;
    while(cur->next)
    {
        len++;
        cur=cur->next;
    }
    
    k=k%len;
    k=len-k;
    cur->next=head;
    while(k--)
    {
        cur=cur->next;
    }
    head=cur->next;
    cur->next=NULL;
    
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main()
{
    Node* head=new Node(0);
    head->next=new Node(1);
    head->next->next=new Node(2);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(4);
    r1otate(head);
   
//    delete_node(head);
//    odd_even(head);
    
    
}