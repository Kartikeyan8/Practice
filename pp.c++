#include<bits/stdc++.h>
using namespace std;
void ug(int n)
{
    int i=0,j=0,k=0;
    vector<int> res(1,1);
    while(res.size()<n)
    {
        res.push_back(min({2*res[i],3*res[j],5*res[k]}));
        if(res.back()==2*res[i])
        {
            i++;
        }
         if(res.back()==3*res[j])
        {
            j++;
        }
        if(res.back()==5*res[k])
        {
            k++;
        }
    }
    cout<<res.back();
}
void sliced(vector<int>v)
{
    vector<int>dp(v.size(),0);
    int cnt=0;
    
    for(int i=2;i<v.size();i++)
    {
        if(v[i]-v[i-1]==v[i-1]-v[i-2])
        {
            dp[i]=dp[i-1]+1;
        }
        cnt+=dp[i];
    }
    cout<<cnt;
}
bool contain(string a)
{
    vector<string>s={"my","kart"};
    for(auto it:s)
    {
        if(a==it)
            return true;
    }
    return false;
}
map<int,bool>m;
set<string>dic;
bool wordbreak(string s,int pos)

{
    if(pos==s.size())
        return true;
    if(m.count(pos))
        return m[pos];            
    
    for(int i=pos;i<s.size();i++)
    {
        if(dic.count(s.substr(pos,i-pos+1)) and wordbreak(s,i+1))
            return m[pos]= true;
        
    }   
    return m[pos]=false; 
}
int trap(vector<int>v)
{
    vector<int>left(v.size(),0);
    vector<int>right(v.size(),0);
    left[0]=v[0];
    for(int i=1;i<v.size();i++)
    {
        left[i]=max(left[i-1],v[i]);
    }
    right[v.size()-1]=v[v.size()-1];
    for(int i=v.size()-2;i>=0;i--)
    {
        right[i]=max(right[i+1],v[i]);
    }
    int water=0;
    for(int i=1;i<v.size()-1;i++)
    {
        int var=min(left[i-1],right[i+1]);
        if(var>v[i])
        {
            water+=var-v[i];
        }
    }
    return water;
}
int find(vector<vector<int>>&v,int i,int j,vector<vector<int>>&dp)

{
    if(j<0 or j>=v[0].size())
    {
        return INT_MAX;
    }
    if(i==0)
        return v[0][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int down=v[i][j]+find(v,i-1,j,dp);
    int right=v[i][j]+find(v,i-1,j+1,dp);
    int left=v[i][j]+find(v,i-1,j-1,dp);
    return dp[i][j]=min(min(down,right),left);    
}
int minpathsum(vector<vector<int>>&v)
{
    int row=v.size();
    int col=v[0].size();
    int mini=INT_MAX;
    vector<vector<int>> dp(row, vector<int>(col,-1));
    for(int i=0;i<col;i++)
    {
        mini=min(mini,find(v,row-1,col,dp));
    }
    
    return mini;
}
int dp[101][101];
int unique(int i,int j,int m,int n)
{
    if(i==m-1 and j==n-1)
    return 1;
    if(i>=m || j>=n)        
        return 0;  
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=unique(i+1,j,m,n)+unique(i,j+1,m,n);

}
void unique_path(int m,int n)
{
    cout<<unique(0,0,m,n);
}
int u2(vector<vector<int>>&v,int i,int j,int m,int n)
{
    if(v[i][j]==1)
        return 0;
    if(i==m-1 and j==n-1)        
        return 1;

    
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i!=m-1 and j!=n-1)
        return dp[i][j]=u2(v,i+1,j,m,n)+u2(v,i,j+1,m,n);
     
    if(i==m-1)
    {
        return dp[i][j]=u2(v,i,j+1,m,n);
    }
    if(j==n-1)
    {
        return dp[i][j]=u2(v,i+1,j,m,n);
    }
    return 0;
}
void unique_path2(vector<vector<int>>&v)
{
    cout<<u2(v,0,0,v.size(),v[0].size());
}
int mini(vector<int>&v)

{
    int cursum=0;
    int max_sum=INT_MAX;
    for(auto it:v)
    {
        cursum+=it;
        max_sum=min(max_sum,cursum);
        if(cursum>0)
        {
            cursum=0;
        }
    }
    return max_sum;
}
int maxi(vector<int>&v)
{
    int cursum=0;
    int max_sum=INT_MIN;
    for(auto it:v)
    {
        cursum+=it;
        max_sum=max(max_sum,cursum);
        if(cursum<0)
        {
            cursum=0;
        }
    }
    return max_sum;
}
void circ_sum(vector<int>v)
{
    int x=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>0)
        {
            x=0;
            break;
        }
    }
    if(x)
         cout<<*max_element(v.begin(),v.end());
    // case -2
    int arr_sum=accumulate(v.begin(),v.end(),0);
    int sum2=arr_sum-mini(v);
    int sum1=maxi(v);
    cout<<max(sum1,sum2);
    


}
int coin(vector<int>&v,int target,int i,vector<vector<int>>&dp)
{
    if(target==0)
        return 0;
        if(i>=v.size() or target<0)
        return 1e9;
    if(dp[i][target]!=-1)
        return dp[i][target];
    
    
    int take=1+ coin(v,target-v[i],i,dp);
    int dont=coin(v,target,i+1,dp);
    return dp[i][target]=min(take,dont);    
}
int coinchange()
{
    vector<int>v={1,2,5};
    int target=11;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    auto ans=coin(v,target,0,dp);
    if(ans==1e9)
        return -1;
    return ans;
}
void coinchange2()
{
    vector<int>v={1,2,5};
    int target=5;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
}
int main()
{
    // coinchange();
    coinchange2();

    // vector<int>v={1,-2,3,-2};
    // circ_sum(v);
    // memset(dp,-1,sizeof(dp));
    // vector<vector<int>>v={{0,0,0},{0,1,0},{0,0,0}};
    // unique_path2(v);
    // unique_path(3,7);
    
        // cout<<wordbreak("t",0);
    // vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9}};
    // cout<<minpathsum(v);       
    // vector<int>v={0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<trap(v);
    // vector<int>v={1,2,3,4};
    // sliced(v);
    // ug(10);
}