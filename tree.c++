#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int v)
    {
        data=v;
        left=right=NULL;
    }
};
int depth(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int maxleft=depth(head->left);
    int maxright=depth(head->right);
    if(maxleft>maxright)
    {
        return maxleft+1;
    }
    else {
        return maxright+1;
    }
}
Node* invert(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    temp->right=invert(head->left);
    temp->left=invert(head->right);
    return temp;
}
void level_order(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        
        int size=q.size();
        // cout<<node->data<<" ";
        
        for(int i=0;i<size;i++)
        {
            auto node=q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
        cout<<endl;
        
   
    }
}
vector<int>v;
int max_path_sum(Node* root,int &maxi)
{
    if(root==NULL)
        return 0;
    int left=max(0,max_path_sum(root->left,maxi));
    int right=max(0,max_path_sum(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    v.push_back(maxi);
    return max(max(left,right)+root->data,root->data);            
}
    // int maxsum(TreeNode* root,int &maxi)
    // {
    //     if(root==NULL)
    //         return 0;
    //     int left=maxsum(root->left,maxi);
    //     int right=maxsum(root->right,maxi);
    //     maxi=max({maxi,left+right+root->val,left+root->val,right+root->val,root->val,});
    //     return max(max(left,right)+root->val,root->val);       
    // }




void cousins(Node* root)
{
    int level=1;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            auto node=q.front().first;
            int line=q.front().second;
            q.pop();
            cout<<node->data<<" ";
            if(node->left!=NULL)
            {
                q.push({node->left,line+1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        cout<<endl;
        level++;
    }
}
void two_sum(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    queue<Node*>q;
    q.push(head);
    int k=16;
    unordered_set<int>s;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        if(s.find(node->data)!=s.end())
        {
            cout<<"found";
            break;
        }
        s.insert(k-node->data);
        if(node->left)
        {
            q.push(node->left);
        }
        if(node->right)
        {
            q.push(node->right);
        }

    }
}
void zigzag(Node* root)
{
    queue<Node* >q;
    q.push(root);
    bool flag=true;
    vector<vector<int>>res;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++)
        {
            auto node=q.front();
            q.pop();
            int ind=(flag)?i:size-i-1;
            temp[ind]=node->data;
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            
        }
        flag=!flag;
        res.push_back(temp);
    }
    for(auto it:res)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    Node* head=new Node(-10);
    head->left=new Node(9);
    head->right=new Node(20);
    head->right->left=new Node(15);
    head->right->right=new Node(2);

    zigzag(head);
    
}