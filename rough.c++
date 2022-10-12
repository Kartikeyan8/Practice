// #include<bits/stdc++.h>
// using namespace std;
// void k_neg()
// {
//     int k=3;
//     vector<int>v={0,-1,2,3};
//     sort(v.begin(),v.end());
//     for(int i=0;v[i]<0;i++)
//     {
//         v[i]=-v[i];
//         cout<<k<<endl;
//         k--;
//     }
//     int sum=accumulate(v.begin(),v.end(),0);
//     int ans=sum-(k%2)*2;
//     cout<<ans<<endl;
// }
// void add_binary()
// {
//     vector<int>a={1,0,1,1};
//     vector<int>b={1,0,1,1};
//     int carry=0;
//     int sum=0;
//     int m=a.size()-1;
//     int n=b.size()-1;
//     string res="";
//     // vector<int>res(a.size(),0);
//     while(m>=0 or n>=0)
//     {
//         int sum=carry;
//         if(m>=0)
//         {
//             sum+=a[m--];
            
//         }
//         if(n>=0)
//         {
//             sum+=b[n];
//             n--;
//         }
//         carry=sum>1?1:0;
//         res+=to_string(sum%2);
//     }
//     if(carry==1)
//     {
//         res.append("1");
//     }
//     reverse(res.begin(),res.end());
//     cout<<res<<endl;
// }
// void odd()
// {
//     vector<int>v={2,2,3,2,3,2,5,5,5,5,2};
//     int ans=0;
//     for(int i=0;i<v.size();i++)
//     {
//         ans^=v[i];
//     }
//     cout<<ans<<endl;
// }
// void counting_bits()
// {
//     int n=5;
//     vector<int>res(n+1,0);
//     for(int i=0;i<=n;i++)
//     {
//         int sum=0;
//         int temp=i;
//         while(temp>0)
//         {
//             sum+=temp%2;
//             temp/=2;
//         }
//         cout<<sum<<endl;
//     }

// }
// void rotate()
// {
//     vector<vector<int>>v={
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };
//     for(int i=0;i<v.size();i++)
//     {
//         for(int j=i+1;j<v.size();j++)
//         {
//             swap(v[i][j],v[j][i]);
//         }
//     }
//     for(int i=0;i<v.size();i++)
//     {
//         reverse(v[i].begin(),v[i].end());
//     }
//     for(auto it:v)
//     {
//         for(auto it1:it)
//         {
//             cout<<it1<<" ";
//         }
//         cout<<endl;
//     }
// }

// void dfs(vector<vector<int>>&v,int i,int j,int color)
// {
//     if(i>v.size()-1 or j>v[0].size()-1 or i<0 or j<0)
//     {
//         return;
//     }
//     if(v[i][j]==color)
//     {
//         return;
//     }
//     v[i][j]=2;
//     dfs(v,i+1,j,color);
//     dfs(v,i-1,j,color);
//     dfs(v,i,j+1,color);
//     dfs(v,i,j-1,color);
// }
// void floodfill(){
//     vector<vector<int>>v={{1,1,1},{1,1,0},{1,0,1}};
//     int sr=1,sc=1;
//     int color=2;
//     // color(v,sr,sc,color);
//     dfs(v,sr,sc,color);
//     for(auto it:v)
//     {
//         for(auto it1:it)
//         {
//             cout<<it1<<" ";
//         }
//         cout<<endl;
//     }
// }
// int count=0;
// int solver(vector<vector<int>>& v, vector<vector<int>>& dp, int r, int c, int &m, int &n){

//     if(r < 0 or c < 0 or r >= m or c >= n) return 1;
//     if(v[r][c]==0) return 1;
//     if(dp[r][c]) return 0;
//     dp[r][c]+=1;
//     return solver(v,dp,r+1,c,m,n)+solver(v,dp,r-1,c,m,n)+solver(v,dp,r,c+1,m,n)+solver(v,dp,r,c-1,m,n);
// }
// void island_per()
// {
//     vector<vector<int>>v={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    
//     int m=v.size();
//     int n=v[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(v[i][j] != 0) 
// 					cout<<solver(v, dp, i ,j, m, n);
//         }
//     }
//     for(auto it:dp)
//     {
//         for(auto it1:it)
//         {
//             cout<<it1<<" ";
//         }
//         cout<<endl;
//     }
// }
// void ana()
// {
//     vector<string >s={"act","cat","tac","god","dog"};
//     map<string,vector<string>>m;
//     for(auto it:s)
//     {
//         auto temp=it;
//         sort(temp.begin(),temp.end());
//         m[temp].push_back(it);
//     }
//     for(auto it:m)
//     {
//        cout<<it.first<<" ";
//        for(auto it1:it.second)
//        {
//            cout<<it1<<" ";
//        }
//     }
// }
// void nge()
// {
//     vector<int>v={6,4,1,2,5,4};
//     int n=v.size();
//     stack<int>s;
//     vector<int>res(n,-1);
//     for(int i=0;i<n;i++)
//     {
//         int k=-1;
//         for(int j=i;j<i+n;j++)
//         {
//             if(v[i]<v[j%n])
//             {
//                 res[i]=v[j%n];
//                 k=1;
//                 break;
//             }
//         }
//     }
//     for(auto it:res)
//     {
//         cout<<it<<" ";
//     }
// }
// // void nse()
// // {
// //     vector<int>v={6,4,1,2,5,4};
// //     int n=v.size();
// //     // stack<int>s;
// //     vector<int>res(n,-1);
// //     for(int i=0;i<n;i++)
// //     {
// //         int k=-1;
// //         for(int j=i;j<i+n;j++)
// //         {
// //             if(v[i]>v[j%n])
// //             {
// //                 res[i]=v[j%n];
// //                 k=1;
// //                 break;

// //             }
// //         }
// //     }
// //     for(auto it:res)
// //     {
// //         cout<<it<<" ";
// //     }

// // }
// void range2()
// {
//     vector<int>v={1,4,6};
//     int k=3;
//     int n=v.size();
//     int ans=v[n-1]-v[0];
//     for(int i=0;i<n-1;i++)
//     {
//         int maxx=max(v[i]+k,v[n-1]-k);
//         int minn=min(v[0]+k,v[i+1]-k);
//         ans=min(maxx-minn,ans);
//     }
//     cout<<ans;

// }
// void mult()
// {
//     string s1="12";
//     string s2="13";
//     vector<int>v(s1.size()+s2.size(),0);
//     int m=s1.size()-1;
//     int n=s2.size()-1;
//     for(int i=m;i>=0;i--)
//     {
//         for(int j=n;j>=0;j--)
//         {
//             v[i+j+1]=(s1[i]-'0')*(s2[j]-'0')+v[i+j+1];
//             v[i+j]=v[i+j+1]/10;
//             v[i+j+1]=v[i+j+1]%10;
//         }
//     }
//     int i=0;
//     while(i<v.size() and v[i]==0)
//     {
//         i++;
//     }
//     string ans="";
//     for(int it=i;it<v.size();it++)
//     {
//         ans+=v[it]+'0';
//     }
//     cout<<ans;
    
// }
    
//  void rain_()
//  {
//     vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
//     int n=height.size();
//     int left[n];
//     left[0]=0;
//     int right[n];
//     for(int i=1;i<n;i++)
//     {
//         left[i]=max(left[i-1],height[i]);
//     }
//     right[n-1]=height[n-1];
//     for(int i=n-2;i>=0;i--)
//     {
//         right[i]=max(right[i+1],height[i]);
//     }
//     int water=0;
//     for(int i=1;i<n-1;i++)
//     {
//         int var=min(left[i-1],right[i+1]);
//         if(var>height[i])
//         {
//             water+=var-height[i];
//         }
//     }
//     cout<<water;
//  }
//  void prodless()
//  {
//     vector<int>v={10,5,2,6};
//     int k=100;
//     int left=0,right=0,prod=1,n=v.size(),result=0;
//     while(right<v.size())
//     {
//         prod=prod*v[right];
//         while(prod>=k)
//         {
//             prod=prod/v[left];
//             left++;    
//         }
//         result+=right-left+1;
//         right++;
//     }
//     cout<<result;
//  }
//  void max_prod_sub()
//  {
//     vector<int>v={1,2,-3,0,-4,-5};
//     int maxx=1;
//     int mini=1;
//     int ans=0;
//     for(int i=0;i<v.size();i++)
//     {
//         if(v[i]<0)
//         {
//             swap(maxx,mini);
//         }
//         maxx=max(maxx*v[i],v[i]);
//         mini=min(mini*v[i],v[i]);
//         ans=max(maxx,ans);
//     }
//     cout<<ans;
//  }
//  void withmost()
//  {
//     vector<int>v={1,8,6,2,5,4,8,3,7};
//     int left=0,right=v.size()-1;
//     int water=0;
//     while(left<right)
//     {
//         int var=min(v[left],v[right]);
//         int length=right-left;
//         int area=var*length;
//         water=max(area,water);
        

//         if(v[left]<v[right])
//         {
//             left++;
//         }
//         else{
//             right--;
//         }
//     }
//     cout<<water;
//  }
//  void bin()
//  {
//     int n=14;
//     vector<int> temp;
//     while(n)
//     {
//         temp.push_back(n%2);
//         n=n/2;
//     }
//     reverse(temp.begin(),temp.end());
//     for(auto it:temp)
//     {
//         cout<<it;
//     }
//  }
//  void word()
//  {
//     string s="kart isttt best";
//     int j=0;
//     int n=s.size();
//     int i=0;
//     int maxstart=0;
//     int maxlength=0;
//     while(i<=n)
//     {
//         if(s[i]!=' ' and i<n)
//         {
//             i++;
//         }
//         else{
//             int curlength=i-j;
//             if(curlength>maxlength)
//             {
//                 maxlength=curlength;
//                 maxstart=j;
//             }
            
//             i++;
//             j=i;
//         }
    
        
//     }
//     cout<<s.substr(maxstart,maxlength);
    
//  }
//  void remo()
//  {
//     vector<int>v={1,2,3,4,5,6,7};
//     int k=3;
//     int n=v.size();//7
//     reverse(v.begin()+n-k+1,v.end());
//     for(auto it:v)
//     {
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     reverse(v.begin(),v.begin()+n-k+1);
//      for(auto it:v)
//     {
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     reverse(v.begin(),v.end());
//     for(auto it:v)
//     {
//         cout<<it<<" ";
//     }
//  }
//  void nge2()
//  {
//     stack<pair<int,int>>s;
//     vector<int>v={4,5,2,10,8};
//     int ans=0;
//     vector<int>res(v.size(),-1);
//     s.push({v[0],0});
//     for(int i=1;i<v.size();i++)
//     {
//         while(!s.empty() and s.top().first<v[i])
//         {
//             res[s.top().second]=v[i];
//             s.pop();
//         }
//         s.push({v[i],i});
//     }
//     for(auto it:res)
//     {
//         cout<<it<<" ";
//     }
//  }
// int main()
// {
//     max_prod_sub();

// }

// // void long_pal()
// // {
// //     string s="abbac";
// //     vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
// //     int len=0;
// //     int start=0;
// //     for(int i=0;i<s.size();i++)
// //     {
// //         dp[i][i]=1;
// //         len=1;
// //         start=i;
// //     }
// //     for(int i=0;i<s.size()-1;i++)
// //     {
// //         if(s[i]==s[i+1])
// //         {
// //             dp[i][i+1]=1;
// //             len=2;
// //             start=i;
// //         }
// //     }
// //     for(int i=3;i<=s.size();i++)
// //     {
// //         for(int j=0;j<=s.size()-i;j++)
// //         {
// //             int k=i+j-1;
// //             if(s[j]==s[k] and dp[j+1][k-1]==1)
// //             {
// //                 dp[j][k]=1;
// //                 start=j;
// //                 len=max(len,i);
// //             }
// //         }
// //     }
// //     cout<<s.substr(start,len)<<endl;
// //     for(auto it:dp)
// //     {
// //         for(auto it1:it)
// //         {
// //             cout<<it1<<" ";
// //         }
// //         cout<<endl;
// //     }
// // }
#include <bits/stdc++.h>
using namespace std;
  
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};
  
// Function to find the maximum width of the tree
// using level order traversal
// int maxWidth(struct Node* root)
// {
//     if(root==NULL)
//     return 0;
//     queue<Node* >q;
//     q.push(root);
//     int result=0;
//     while(!q.empty())
//     {
//         int size=q.size();
//         result=max(result,size);

//         while(size--)
//         {
//             auto node=q.front();
//             q.pop();
//             if(node->left)
//             {
//                 q.push(node->left);
//             }
//             if(node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//     }
//     return result;
// } 
// int max_depth(Node* root)
// {
//     if(root==NULL)
//         return 0;
//     queue<Node* >q;
//     q.push(root);
//     vector<vector<int>>res;
//     while(!q.empty())
//     {
//         int size=q.size();
//         vector<int>temp;
//         while(size--)
//         {
//             auto node=q.front();
//             q.pop();
//             temp.push_back(node->data);
//             if(node->left)
//             {
//                 q.push(node->left);
//             }
//             if(node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//         res.push_back(temp);
//     }
//     return level;

// }
// Node* invert(Node* root)
// {
//    u
// }
// Driver code
void cheapest_fare()
{
    int n=3;
    vector<vector<int>>flights={{0,1,100},{1,2,100},{0,2,500}};
    int src=0;
    int dst=2;
    int k=1;
    vector<pair<int,int>>adj[n];
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int>res(n,INT_MAX);
    queue<pair<int,int>>q;
    q.push({0,src});
    k+=1;
    while(!q.empty() and k--)
    {
        int size=q.size();
        while(size--)
        {
            auto dist=q.front().first;
            auto dest=q.front().second;
            q.pop();
            for(auto it:adj[dest])
            {
                if(res[it.first]>dist+it.second)
                {
                    res[it.first]=dist+it.second;
                    q.push({dist+it.second,it.first});
                }
            }
        }
        
    }
    cout<<res[dst]<<endl;
    // for(auto it:adj)
    // {
    //     for(auto it1:it)
    //     {
    //         cout<<it1.first<<" "<<it1.second<<endl;
    //     }
        
    // }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
  
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
  
    // Function call
    // cout << "Maximum width is " << maxWidth(root) << endl;
    // invert(root);
    // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    // pq.push({5,2,3});
    // pq.push({1,2,4});
    // pq.push({1,2,5});
    // while(!pq.empty())
    // {
    //     auto it=pq.top();
    //     pq.pop();
    //     for(auto it1:it)
    //     {
    //         cout<<it1<<" ";
    //     }
    // }
    cheapest_fare();
    return 0;
}