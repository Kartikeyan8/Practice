#include<bits/stdc++.h>
using namespace std;
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
int coin2(vector<int>&v,int target,int i,vector<vector<int>>&dp)
{
    if(target==0)
        return 1;
    if(i==0)
        if(target%v[i]==0)
            return 1;
        else
            return 0;
    if(dp[i][target]!=-1)
        return dp[i][target];
    int dont=coin2(v,target,i-1,dp);
    int take=0;
    if(v[i]<=target)
    {
         take=coin2(v,target-v[i],i,dp);
    }
    return dp[i][target]=dont+take;

}
void coinchange2()
{
    vector<int>v={3};
    int target=5;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    int ans=coin2(v,target,v.size()-1,dp);
    cout<<ans;
}
void comb1(int i,vector<int>&v,int target,vector<int>&path,vector<vector<int>>&res)
{
    if(i==v.size())
    {
        if(target==0)
            res.push_back(path);
        return;    
    }
        
    if(target>=v[i])
    {
        path.push_back(v[i]);
        comb1(i,v,target-v[i],path,res);
        path.pop_back();
    }
    comb1(i+1,v,target,path,res);    

}
void comb()
{
    vector<int>v={2,3,6,7};
    int target=7;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    vector<int>path;
    vector<vector<int>>res;
    comb1(0,v,target,path,res);
    for(auto x:res)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}
void comb22(int i,vector<int>&v,int target,vector<int>&path,vector<vector<int>>&res)
{
        if(target==0)
        {
            res.push_back(path);
            return;
        }
    for(int it=i;it<v.size();it++)
    {
        if(it>i and v[it]==v[it-1])
            continue;
        if(v[it]>target)
            break;
        path.push_back(v[it]);
        comb22(it+1,v,target-v[it],path,res);
        path.pop_back();    
    }       
    
}
void comb2()
{
    vector<int>v={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    vector<int>path;
    vector<vector<int>>res;
    sort(v.begin(),v.end());
    comb22(0,v,target,path,res);
    for(auto x:res)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}
void comb3()
{
       vector<vector<int>> res;
        vector<int>ds;
        // combo(res,ds,k,n,1);
}
void comb44(int i,vector<int>&v,int target,vector<int>&path,vector<vector<int>>&res)
{
    
    if(i==v.size())
    {
        if(target==0)
            res.push_back(path);
        return;    
    }
    
    if(target>=v[i])
    {
        path.push_back(v[i]);
        comb44(i,v,target-v[i],path,res);
        path.pop_back();
    }
    comb44(i+1,v,target,path,res);


}
void combo4()
{
    vector<int>v={1,2,3};
    int target=4;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    vector<int>path;
    vector<vector<int>>res;
    sort(v.begin(),v.end());
    comb44(0,v,target,path,res);
    reverse(v.begin(),v.end());
    comb44(0,v,target,path,res);
    set<vector<int>>s;
    for(auto it:res)
    {
        s.insert(it);
    }
    for(auto it:s)
    {
        for(auto y:it)
            cout<<y<<" ";
        cout<<endl;
    }
}
int res=0;
int call(vector<int>&v,int target,int i,vector<vector<int>>&dp)
{
    if(i<0)
        return 0; 
    if(dp[i][target]!=-1)
        return dp[i][target];
    if(target==0)
        return 1;
       
    int ans=0;    
    if(v[i]<=target)
    {
        ans=call(v,target-v[i],v.size()-1,dp)+call(v,target,i-1,dp);
    }
    else{
        ans=call(v,target,i-1,dp);
    }
    return dp[i][target]=ans;   

}
void realcomb4()
{
    vector<int>v={1,2,3};
    int target=4;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    cout<<call(v,target,v.size()-1,dp);
}
void block_sum(vector<vector<int>>&v,int k)
{
    
    int row=v.size();
    int col=v[0].size();
    vector<vector<int>>ans(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int sum=0;
            for(int l=( i-k<0 ? 0:i-k );l<=( i+k>row-1 ? row-1:i+k) ;l++)
            {
            for(int m=( j-k<0 ? 0:j-k);m<=( j+k>col-1 ? col-1:j+k );m++)
            {
                sum+=v[l][m];
            }
            }
            ans[i][j]=sum;
        }
    }
    for(auto it:ans)
    {
        for(auto y:it)
            cout<<y<<" ";
        cout<<endl;
    }
}
void matrix_block_sum()
{
    vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9}};
    int k=1;
    
    block_sum(v,k);
    
}
int inte(int n,vector<int>&dp)


{
    if(n<2)
        return 1;
    if(n==2)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    int take=1;
    int nottake=1;
    int temp=-1;
    for(int i=1;i<n;i++)
    {
        take=i*inte(n-i,dp);
        nottake=i*(n-i);
        temp=max(temp,max(take,nottake));
    }
    return dp[n]=temp;     

}
void integer_block()
{
    int n=10;
    vector<int>dp(n+1,-1);
    cout<<inte(n,dp);
    
    
    
}
void perfect(int i,int n,vector<int>&dp)
{

}
void perfect_square()
{

    int n=13;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);  
            }
            
        }
        for(auto it:dp)
            cout<<it<<" ";

}
void prime(int n)
{
    vector<bool>prime(n,false);
    
    for(int i=2;i<=sqrt(n);i++)
    {
        if(prime[i]==false)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    for(auto it:prime)
        cout<<it<<" ";
    
    
}
void replacel()
{
    vector<int>v={17,3,5,14,6,1};
    int n=v.size();
    vector<int>dp(n,INT_MIN);
    for(int i=0;i<n;i++)
    {
        
        for(int j=i+1;j<n-i;i++)
        {
            int el=*max_element(v.begin()+i+1,v.end());
            
            cout<<el<<" ";

            
        }
    }
    v.push_back(-1);
    
    
}
bool issub(vector<int>&v,vector<vector<int>>&dp,int i,int sum)
{
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(i==0 and sum!=0)
        return false;
    if(sum==0)
        return true;
    if(sum<v[i])
        return issub(v,dp,i-1,sum);    
    return dp[i][sum]=issub(v,dp,i-1,sum-v[i]) or issub(v,dp,i-1,sum);    
}
void equal()
{
    vector<int>v={11,3,8,5,2};
    int n=v.size();
    int sum=0;
    for(auto &it:v)
        sum+=it;
    if(sum%2==1){
        cout<<"NO"<<endl;
        return;
    }
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        cout<< issub(v,dp,n,sum/2);
}
int square(int n)
{
    int sum=0;
    // 11
    while(n)
    {
        int rem=n%10; //1
        sum+=rem*rem;
        
        n/=10;

    }
    return sum;
}
bool happy()
{
    int n=2;
    set<int>s;
    while(1)
    {
        n=square(n);
        if(n==1)
            return true;
        if(s.find(n)!=s.end())
        {
            return false;
        }
        s.insert(n);
    }
    
}
int main()
{
    cout<<happy();
    // equal();
    // replacel();
    // prime(10);
    // perfect_square();
    // integer_block();
    // coinchange();
    // coinchange2();
    // comb();
    // comb2();
    // comb3();
    // combo4();
    // realcomb4();
    // matrix_block_sum();
}