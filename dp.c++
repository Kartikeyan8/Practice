#include<bits/stdc++.h>
using namespace std;
// void fib(int n)
// {
//     vector<int>dp(n+1,0);
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]*i;
//     }
//     for(auto it:dp)
//     {
//         cout<<it<<" ";
//     }
// }
// void tribonacci(int n) {
//         // if(n==0)
//         //     return 0;
//         // if(n==1)
//         //     return 1;
//         vector<int>dp(n+1,0);
//     dp[0]=0;
//     dp[1]=1;
//         dp[2]=1;
//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//     }
//         // return dp[n];
//     }
void max_prod_sub()
{
    vector<int>v={2,3,-2,4};
    int n=v.size();
int maxi=v[0],mini=v[0],ans=v[0];
for(int i=1;i<n;i++)
{
    if(v[i]<0)
    {
        swap(maxi,mini);
    }
    
        maxi=max(v[i],maxi*v[i]);
        mini=min(v[i],mini*v[i]);
        ans=max(maxi,ans);
    
}
cout<<ans;
    

}
void btts()
{
    vector<int>v={7,1,5,3,6,4};
    int first=v[0];
    int profit=0;
    for(int i=1;i<v.size();i++)
    {
        // 8,1
        if(v[i]<first)
        {
            first=v[i];
            continue;            
        }
        else{
            // 3,2
            profit=max(v[i]-first,profit);
        }
    }
    cout<<profit;
}
void btts2()
{
    vector<int>v={7,1,5,3,6,4};
    int n=v.size();
    int first=v[0];
    int profit=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]<first)
        {
            first=v[i];

        }else{
        profit=max(profit,profit+v[i]-first);
        first=v[i];
        
    }}
    cout<<profit;
}    
void sightseeing_pair()
{
    vector<int>v={5,9,2};
    
    int n=v.size();
    
    int pos=0;
    vector<int>dp(n+1,0);
    for(int i=1;i<n;i++)
    {
        // 8,1,5,2,6
        dp[i]=v[i]-1+ v[i-1];
        dp[i]=max(dp[i],dp[i-1]+v[i]-v[i-1]-1);    
        pos=max(pos,dp[i]); 
    }
    for(auto it:dp)
    {
        cout<<it<<" ";
    }
    
    // cout<<ans;
}
void length()
{
    vector<int>v={1,-2,-3,4};
    int pos=0;
    int neg=0;
    int ans=0;
    int j=0;
    int lastneg=-1;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            j=i+1;
            pos=0;
            neg=0;
            lastneg=-1;
        }
        else if(v[i]>0)
            pos++;
        else{
            neg++;
            if(lastneg==-1 and neg%2==1)
            {
                lastneg=i+1;    
            }}
        if(neg%2==0)
        {
            ans=max(ans,i-j+1);
        }
        else if(lastneg!=-1)
            ans=max(ans,i-lastneg+1);
        }
        cout<<ans;    
    }
    
    int prof(int i, int buy, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(i >= prices.size())
    {
        return 0;
    }
    if(dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    
    int profit = 0;
    if(buy == 1)
    {
        profit = max(-prices[i] +prof(i+1, 0, prices, dp), prof(i+1, 1, prices, dp));
    }
    else
    {
        profit = max(prices[i] + prof(i+2, 1, prices, dp), prof(i+1, 0, prices, dp));
    }
    return dp[i][buy] = profit;
}
    
void real_profit()
{
    vector<int>v={1,2,3,0,2};
    vector<vector<int>>dp(v.size()+10,vector<int>(10,-1));
    cout<<prof(0,1,v,dp);
}
void dele(vector<int>v)
{
    int n=v.size();
    map<int,int>m;
    for(auto it:v)
    {
        m[it]++;

    }
    vector<int>temp;
    vector<int>dp(n+1,0);
    for(auto it:m)
    {
        temp.push_back(it.first);
    }
    dp[0]=temp[0]*m[temp[0]];
    if(temp[0]==temp[1]-1)
    {
        dp[1]=max(dp[0],m[temp[1]]*temp[1]);
    }
    else{
        dp[1]=dp[0]+m[temp[1]]*temp[1];
    }
    for(int i=2;i<temp.size();i++)
    {
        if(temp[i]==temp[i-1]-1)
        {
            dp[i]=max(dp[i-1],m[temp[i]]*temp[i]);
        }
        else{
            dp[i]=dp[i-1]+m[temp[i]]*temp[i];
        }
    }
}
void jump2(vector<int>v)
{
    int mj=0;
    int curj=0;
    int reach=0;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(i>reach)
        {
            cout<<"impossible"<<endl;
        }
        reach=max(reach,i+v[i]);

    }
    cout<<reach;
}
void fee(vector<int>v,int fee)
{
    int profit=0;
    int first=v[0];
    for(int i=0;i<v.size();i++)
    {
        // 1,3,2,8,4,9
        profit=max(profit,v[i]-first-fee);
        first=min(first,v[i]-profit);
        
    }
    cout<<profit;
}
void decode(string s)
{
    int count1=1;
    int count2=1;
    for(int i=1;i<s.size();i++)
    {
        int count=0;
        int d=s[i]-'0';
        int dd=d*10+s[i-1]-'0';
        if(d>1)
            count+=count2;
        if(dd>9 and dd<=26)
        {
            count+=count1;
        }
        count1=count2;
        count2=count;    
    }
    cout<<count2;
}
void pascal(int n)
{
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        ans[i].resize(i+1);
        ans[i][0]=ans[i][i]=1;
        for(int j=0;j<ans[i].size();j++)
        {
            ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
        }
    }
    
}
int recur(vector<vector<int>>&v,vector<vector<int>>&dp,int m,int n,int i,int j)
{
    if(i==m-1 )
        return dp[i][j]=v[i][j];
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
    int ans1=v[i][j] + recur(v,dp,m,n,i+1,j);
    int ans2=v[i][j] + recur(v,dp,m,n,i+1,j+1);
    return dp[i][j]=min(ans1,ans2);
}
void triangle(vector<vector<int>>&v)
{
    int m=v.size();
    int n=v[m-1].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout<<recur(v,dp,m,n,0,0);
}
void ug(int n)
{
    int i=0,j=0,k=0;
    int num=0;
    for(int it=0;it<n;it++)
    {
        //  num=min(2*i,3*j,5*k);
        if(num==2*i)
        {
            i++;
        }
        else if(num==3*j)
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    cout<<i+j+k;
}

int catty(int n,vector<int>&dp)
{
    if(n<=1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=catty(i,dp)*catty(n-i-1,dp);
    }
    return dp[n]=res;
    

}
void cat(int n)
{
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++)
    {
        cout<<catty(i,dp)<<" ";
    }
}
int main()
{
    cat(19);
    // ug(10);
    // vector<int>v={1,3,2,8,4,9};
    // string s="12";
    // vector<vector<int>>v={{2},{3,4},{6,5,7},{4,1,8,3}};
    // triangle(v);
    // pascal(5);
    // decode(s);
    // fee(v,2);
    // jump2(v);
    //  dele(v);
    // real_profit();
    // length();
    // sightseeing_pair() ;
    // btts();
    // btts2();
    // max_prod_sub();
    // tribonacci(5);
    // fib(5);
}