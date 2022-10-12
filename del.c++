#include<bits/stdc++.h>
using namespace std;

// int gdc(int a,int b)
// {
//     return b==0?a:gcd(b,a%b);
// }
// void xor_of_even_power()
// {
//     vector<int>v={5,3,2,1};
//     int n=v.size();
//     int q=0;
//     vector<vector<int>>query={{0,3},{1,1}};
//     vector<int>ans;
//     for(auto it:query)
//     {
//         int l=it[0];
//         int r=it[1];
//         int x=0;
//         // for(int i=l;i<=r;i++)
//         // {
//         //     if(v[i] and (!(v[i]&(v[i]-1))))
//         //     {
//         //         while()
//         //     }
            
//         // }

//     }


// }
// void swappable()
// {
//     vector<int>v={1,2,4,3,7,3,9,6};
//     vector<bool>swappable(v.size(),false);
//     for(int i=0;i<v.size();i++)
//     {
//         int cnt=0;
//         int val=v[i];
//         for(int j=0;j<v.size();j++)
//         {
//             if(v[j]<val)
//             {
//                 cnt++;
//             }
//         }
//         if(cnt>val/2)
//         {
//             swappable[i]=true;
//         }
//     }
//     bool flag=false;
//     for(int i=0;i<swappable.size()-1;i++)
//     {
//         if(swappable[i] and swappable[i+1] and v[i]>v[i+1])
//         {
//             while(i<swappable.size()-1 and swappable[i] and swappable[i+1] and v[i]>v[i+1])
//             {
//                 if(v[i]>v[i+1])
//                 {
//                     swap(v[i],v[i+1]);
//                 }
//                 i++;
//             }
            
//         }
//     }

    
//     for(auto it:v)
//     {
//         cout<<it<<" ";
//     }
// }
// // struct Node{
// //     Node* front=NULL,*rear=NULL;
// //     int data;
// //     Node* next;
// //     Node(int v)
// //     {
// //         data=v;
// //         next=NULL;
// //     }
// // };
// // struct queuenode{
// //     Node* front=NULL,*rear=NULL;
// //     int size=0;
// //     bool empty()
// //     {
// //         if(front==NULL)
// //         {
// //             return true;
// //         }
// //         else {
// //             return false;
// //         }
// //     }
// //     void enqueue(int v)
// //     {
// //         Node* temp=new Node(v);
// //         if(front==NULL)
// //         {
// //             front=rear=temp;
// //         }
// //         else {
// //             rear->next=temp;
// //             rear=temp;
// //         }
// //         size++;
// //     }
// //     void dequeue()
// //     {
// //         Node* temp=front;
// //         if(front==NULL)
// //         {
// //             return ;
// //         }
// //         else{
// //             front=front->next;
// //             delete temp;
// //         }
// //         size--;
// //     }
// //     int sizee()
// //     {
// //         return size;
// //     }
    
// // };
// // struct stacknode{
// //     int data;
// //     stacknode* next;
// //     stacknode(int v)
// //     {
// //         data=v;
// //         next=NULL;
// //     }
// // };
// // struct stacknodemain{
// //     int size=0;
// //     stacknode* top=NULL;
// //     void push(int v)
// //     {
// //         stacknode* temp=new stacknode(v);
// //         temp->next=top;
// //         top=temp;
// //         size++;
// //     }
// //     void pop()
// //     {
// //         if(top==NULL)
// //         {
// //             return;
// //         }
// //         else{
// //             stacknode* temp=top;
// //             top=top->next;
// //             delete temp;
// //         }
// //     }
// //     bool empty()
// //     {
// //         if(top==NULL)
// //         {
// //             return true;
// //         }
// //         else {
// //             return false;
// //         }
// //     }
    
// // };
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int v)
//     {
//         data=v;
//         next=NULL;

//     }
//     Node* front=NULL,*rear=NULL;
// };
// class queue{
//     public:
//     int size=0;
//     Node* front=NULL,* rear=NULL;
//     void push(int data)
//     {
//         Node* temp=new Node(data);
//         if(front==NULL)
//         {
//             front=rear=temp;
//         }
//         else{
//             rear->next=temp;
//             rear=temp;
//         }
//         size++;
//     }
//     void pop()
//     {
//         if(front==NULL)
//         {
//             cout<<"filled";
//             return;
//         }
//         else if(front==rear){
//             Node* temp=front;
//             front=rear=NULL;
//             delete temp;
//         }
//         else{
//             Node* temp=front;
//             front=front->next;
//             delete temp;
//         }
//         size--;
//     }
// };
class queuee{
    public:
    stack<int>in,out;
    void push(int data)
    {
        in.push(data);
    }
    void top()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            cout<<out.top();
        }
        else {
            cout<<out.top();

        }
    }
    void pop()
    {
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
               
            }
             out.pop();
        }
        else{
            out.pop();
        }
    }
    bool empty()
    {
        if(in.empty() and out.empty())
        {
            return true;
        }
        else {
            return false;
        }
    }
};
class stackee{
    public:
    queue<int>q;
    void push(int data)
    {
        int n=q.size();
        q.push(data);
        for(int i=0;i<n;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        q.pop();
    }
    void top()
    {
        cout<<q.front();
    }
};
int main()
{
    stackee s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.top();
    s.pop();
    s.top();
    // queuee q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.pop();
    // q.top();


}