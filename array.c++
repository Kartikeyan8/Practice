#include<bits/stdc++.h>
using namespace std;
void set_zero(vector<vector<int>>&v)
{
    vector<int>row(v.size(),-1);
    vector<int>col(v[0].size(),-1);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==0)
            {
                row[i]=0;
                col[j]=0;
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(row[i]==0||col[j]==0)
            {
                v[i][j]=0;
            }
        }
    }
    for(auto it:v)
    {
        
        {
            for(auto it1:it)
            {
                cout<<it1<<" ";
            }
            cout<<endl;
        }
    }
}
void twosum()
{
    vector<int>v={2,7,11,15};
    int low=0,high=v.size()-1;
    bool flag=false;
    int target=13;
    while(!flag)
    {
        if(v[low]+v[high]==target)
        {
            cout<<low<<" "<<high<<endl;
            flag=true;
        }
        else if(v[low]+v[high]<target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    v.clear();
    v[0]=low;
    v[1]=high;
    
}

void islepar(vector<vector<int>>&v)
{
    int cnt=0;
    int m=v.size();
    int n=v[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==1)
            {
            if(i-1<0) ++cnt;
            if(i+1==m) ++cnt;
            if(j-1<0)   ++cnt;
            if(j+1==n) ++cnt;
            if(i-1>=0 and v[i-1][j]==0) ++cnt;
            if(i+1<m and v[i+1][j]==0) ++cnt;
            if(j-1>=0 and v[i][j-1]==0) ++cnt;
            if(j+1<n and v[i][j+1]==0) ++cnt;
            }
            }

        }
        cout<<cnt<<endl;
        }
void part()
{
    vector<int>v={1,4,3,2};
    int sum=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
}
int dfs(vector<vector<int>>&v,int i,int j,int m,int n,vector<vector<int>>&dp)
{
    if(i>=m||j>=n)
    {
        return 1e2;
    }
    if(i==m-1 and j==n-1)
        return v[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=v[i][j]+min(dfs(v,i+1,j,m,n,dp),dfs(v,i,j+1,m,n,dp));    
    
    
    
}
void minpathsum()
{
    vector<vector<int>>v={{1,2,3},{4,5,6}};
    vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),-1));
    cout<<dfs(v,0,0,v.size(),v[0].size(),dp);
}
void minsum()
{
    vector<int>v={9,4,1,7};
    int k=2;
    int n=v.size();
    sort(v.begin(),v.end());
    int ans=INT_MAX;
    int p=k-1;
    for(int i=p;i<n;i++)
    {
        int t=v[i]-v[i-k+1];
        ans=min(ans,t);
    }
    cout<<ans;
}
void mincostcandy()
{
    vector<int>v={6,5,7,9,2,2};
    sort(v.begin(),v.end(),greater<int>());
    // 9,7,6,5,2,2
    int cost=0;
    int buy=1;
    for(int i=0;i<v.size();i++)
    {
        if(buy%3)
        {
            cout<<v[i]<<" ";
            buy++;
            cost+=v[i];
        }
        else
        buy=1;
            
        
        
    }
    cout<<cost;
}

void minabdif()
{
    vector<int>v={3,2,1,9};
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    // 1,2,3,9
    int mini=v[1]-v[0];
    for(int i=0;i<v.size()-1;i++)
    {
        mini=min(mini,v[i+1]-v[i]);
    }
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i+1]-v[i]==mini)

        {
            ans.push_back({v[i],v[i+1]});
        }
    }
    
    
for(auto it:ans)
{
    for(auto it1:it)
    {
        cout<<it1<<" ";
    }
    cout<<endl;
}

}     
        
    
    
    


    
    
void maximal_square(vector<vector<char>>&v)
{
    vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),0));
    int row=v.size();
    int col=v[0].size();
    int large=0;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(v[i-1][j-1]==1)
            {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
            if(dp[i][j]>large)
                large=dp[i][j];
        }
    }
    cout<<large<<endl;
}

void longest_pal(string s)
{
    vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        int start=0,len=0;
    for(int i=0;i<s.size();i++)
    {
        dp[i][i]=1;
        len=1;

        
    }
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            
            len=2;
        }
    }

    for(int i=3;i<=s.size();i++)
    {
        for(int j=0;j<=s.size()-i;j++)
        {
            int k=i+j-1;
            if(s[j]==s[k] and dp[j+1][k-1])
            {
                dp[j][k]=1;
                start=j;
                len=max(len,i);
            }
        }
    }
    cout<<start<<" "<<len<<endl;
}
    int lcs(string &s,string &t,vector<vector<int>>&dp,int m,int n)
    {
        if(m==0 or n==0)
        {
            return 0;
        }
        
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        if(s[m-1]==t[n-1])
        {
            return dp[m][n]=1+lcs(s,t,dp,m-1,n-1);
        }
        else return dp[m][n]= max(lcs(s,t,dp,m-1,n),lcs(s,t,dp,m,n-1));
    }
void lcp(string t)
{
    string s=t;
    reverse(s.begin(),s.end());
    vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
    cout<<lcs(t,s,dp,s.size(),s.size());
}
void lis()
{
    vector<int>v={10,9,9,1,2,3,7,101,18};
    vector<int>dp(v.size(),1);
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j] and dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    for(auto it:dp)
    {
        cout<<it<<" ";
    }
}
void wiggle()
{
    vector<int>v={1,7,4,9,2,5};
    
    // vector<int>posdp(v.size(),0);
    int inc=1;
    int dec=1;
    for(int i=1;i<v.size();i++)
    {
        // 1,4,3,5
        if(v[i]>v[i-1])
        {
            inc=dec+1;
        }
        else if(v[i]<v[i-1])
        {
            dec=inc+1;
        }
    }
    
    cout<<inc<<" "<<dec<<endl;
}
bool isturb(vector<int>v,int end)
{
    return ((v[end]>v[end+1] and v[end-1]<v[end]) or (v[end]<v[end+1] and v[end-1]>v[end]));
}
int turbu()
{
    vector<int>v={9,4,2,10,7,1,9};
    if(v.size()<2)
    return v.size();
    int maxx=1;
    int start=0;
    int end=0;
    int n=v.size(); 
    while(start+1<n)
    {
        if(v[start]==v[start+1])
        {
            start++;
            continue;
        }
        end=start+1;
    while(end+1<n and isturb(v,end))
    {
        end++;
    }
    maxx=max(end-start+1,maxx);
    start=end;

    }
    cout<<maxx;

    return maxx;
    // cout<<max(inc,dec)<<" "<<max(inc2,dec2)<<endl;
}
    // int sumRegion(int row1, int col1, int row2, int col2) {
    //    bool b=(3>2?true:false);
    //    cout<<b;
    // }
    int sub(string s,string t,int m,int n, vector<vector<int>>&dp)
    {
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(m==0 or n==0)
        {
            return 0;
        }
        if(s[m-1]==t[n-1])
        {
            return dp[m][n]=1+sub(s,t,m-1,n-1,dp);
        }
        return dp[m][n]=sub(s,t,m,n-1,dp);

    }
    void issubbb(string s,string t)
    {
        int m=s.size()>t.size()?t.size():s.size();
        int n=s.size()>t.size()?s.size():t.size();
         vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        cout<<sub(s,t,m,n,dp);
    }
    
int main()
{
    string s="abc";
    string t="anbjjc";

    issubbb(s,t);
    // sumRegion(0,0,0,0);
    // turbu();
    // wiggle();
    // lis();
    // string s="geeksforgee";
    // lcp(s);

    // longest_pal(s);
    // vector<vector<char>>v={{"1","0","1","0","0"},
    //                        {"1","0","1","1","1"},
    //                        {"1","1","1","1","1"},
    //                        {"1","0","0","1","0"}};
    // maximal_square(v);
    // minabdif();
    // mincostcandy();
    // minsum();
    //  minpathsum();
    // part();
    // vector<vector<int>>v={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    // islepar(v);
    // twosum();
    // vector<vector<int>>v={{1,0,1},{0,0,0},{1,0,1}};
    // set_zero(v);
}