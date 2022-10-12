#include<bits/stdc++.h>
using namespace std;
void bub(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
void sel(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<v.size();i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[min_index])
            {
                min_index=j;
            }
        }
        swap(v[i],v[min_index]);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
void close_to_zero(vector<int>v)
{
    int mini=INT_MAX;
    int index=0;
    for(int i=0;i<v.size();i++)
    {
        int a=abs(v[i]);
        if(a<mini)
        {
            mini=a;
            index=i;
        }
    }
    cout<<mini;
   
    // int i=0,j=v.size()-1;
}
void query()
{
    vector<vector<int>>v={{1,1},{2,2},{3,2},{4,3},{5,5}};
    vector<vector<int>>queries={{1,5,2},{2,4,1}};
    vector<int>ans;
    for(auto it:queries)
    {
        int start=it[0];
        int end=it[1];
        int val=it[2];
        int count=0;
        for(auto el:v)
        {
            if(el[0]>=start and el[0]<=end)
            {
                if(el[1]>val)
                {
                    count++;
                }
            }
        }
        ans.push_back(count);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
// struct Node{
//     int data;
//     Node* next;
//     Node(int v)
//     {
//         data=v;
//         next=NULL;
//     }
// };
// Node* createnode(int v,Node* start)
// {
//     Node* temp=new Node(v);
//     temp->next=NULL;
//     Node* p=start;
//     if(start==NULL)
//     {
//         start=temp;
//         start->next=NULL;
//     }
//     else{
//         while(p->next!=NULL)
//         {
//             p=p->next;
//         }
//         p->next=temp;
//     }
//     return start;
// }
// Node* sorting(Node* head)
// {
//     Node* dummy=new Node(0);
//     dummy->next=head;
//     Node* cur=head;
//     // int size=0;
//     while()
//     return dummy->next;
// }
struct Node{
    int data;
    Node* left,*right;
    Node(int v)
    {
        data=v;
        left=NULL;
        right=NULL;
    }
};
vector<int>l;
void left_help(Node* root,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(l.size()==level)
    {
        l.push_back(root->data);
    }
    
    left_help(root->right,level+1);
    left_help(root->left,level+1);
}
void left(Node* root)
{
    int level=0;
    left_help(root,level);
    for(auto it:l)
    {
        cout<<it<<" ";
    }

}
bool check_help(Node* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<min or root->data>max)
    {
        return false;
    }
    return check_help(root->left,min,root->data-1) and check_help(root->right,root->data+1,max);
}
void check(Node* root)
{
    cout<<check_help(root,INT_MIN,INT_MAX);
}
void topping_check(Node* root)
{
    if(root==NULL)
    return ;
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        auto node=q.front().first;
        int line=q.front().second;
        q.pop();
        m[line]=node->data;
        if(node->left)
        {
            q.push({node->left,line-1});
        }
        if(node->right)
        {
            q.push({node->right,line+1});
        }

    }
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

}
void top_view(Node* root)
{
    if(root==NULL)
    return ;
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        auto node=q.front().first;
        int line=q.front().second;
        if(m.find(line)==m.end())
        {
            m[line]=node->data;
        }
        q.pop();
        if(node->left)
        {
            q.push({node->left,line-1});
        }
        if(node->right)
        {
            q.push({node->right,line+1});
        }
    }
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<" "<<endl;
    }
}
int main()
{
    Node * root = new Node(7);
    root -> left = new Node(5);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(6);
    root -> right = new Node(10);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(15);
    // topping_check(root);
    top_view(root);
}
class topstack{
    int data;
    topstack* next;
    topstack(int a)
    {
        data=a;
        next=NULL;
    }
};
