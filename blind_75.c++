#include<bits/stdc++.h>
using namespace std;
// void bsell()
// {
//     vector<int>v={7,1,5,3,6,4};
//     int profit=0;
//     int curr=v[0];

//     for(int i=1;i<v.size();i++)
//     {
//         if(curr>v[i])
//         {
//             curr=v[i];
//             continue;
//         }
//         else{
//             profit=max(profit,-curr+v[i]);
//         }
//     }
//     cout<<profit<<endl;
// }
void max_s()
{
    vector<int>v={-2,1,-3,4,-1,2,1,-5,4};
    int curr=0;
    int sub=INT_MIN;
    
    for(int i=0;i<v.size();i++)
    {
        curr=curr+v[i];
        if(curr>sub)
        {
            sub=curr;
        }
        if(curr<0)
        {
            curr=0;
        }

    }
    cout<<sub<<endl;
}
void three()
{
    vector<int>v={-1,0,1,2,-1,-4};
    int sum=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(i==0 or v[i]!=v[i-1])
        {
            int j=i+1;
            int k=v.size()-1;
            while(j<k)
            {
              sum=v[i]+v[j]+v[k];
              if(sum==0)
              {
                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                while(j<k and v[j]==v[j+1])
                {
                    j++;
                }
                while(j<k and v[k]==v[k-1])
                {
                    k--;
                }
                j++;
                k--;
              }  
              else if(sum>0)
              {
                k--;
              }
              else
                {
                    j++;
                }
            }
        }
    }
}
void container()
{
    vector<int>v={1,8,6,2,5,4,8,3,7};
    int water=0;
    int left=0,right=v.size()-1;
    int ans=1;
    while(left<right)
    {
        int var=min(v[left],v[right]);
        int area=var*(right-left);
        ans=max(ans,area);
        if(v[left]<v[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout<<ans<<endl;
}
void except_self()
{
    vector<int>v={1,2,3,4};
    int cul=1,curr=1;
    vector<int>ans(v.size(),1);
    for(int i=0;i<v.size()-1;i++)
    {
        cul=cul*v[i];
        ans[i+1]*=cul;
    }
    for(int i=v.size()-1;i>0;i--)
    {
        curr=curr*v[i];
        ans[i-1]*=curr;
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
void decode()
{
    string s="232";
    int count=0,count1=1,count2=1;
    for(int i=1;i<s.size();i++)
    {
        int d=s[i]-'0';
        int dd=(s[i-1]-'0')*10+d;
        if(d>0)
        {
            count+=count1;
        }
        if(dd>9 and dd<=26)
        {
            count+=count2;
        }
        count1=count2;
        count2=count;
    }
    cout<<count<<endl;
}
int common(string &s1,string &s2,int m,int n,vector<vector<int>>&dp)
{
    if(m<0 or n<0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(s1[m]==s2[n])
    {
        return dp[m][n]=1+common(s1,s2,m-1,n-1,dp);
    }
    else{
        return dp[m][n]=max(common(s1,s2,m-1,n,dp),common(s1,s2,m,n-1,dp));
    }
}
void lcs()
{
     string s1= "acbbad";
    string s2= "caed";
    vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
    int m=s1.size();
    int n=s2.size();
    cout<<common(s1,s2,m-1,n-1,dp);
}
void comb_sum_help(vector<int>&v,int i,vector<int>&ds,int target,vector<vector<int>>&res)
{
    if(i==v.size())
    {
        if(target==0)
        {
            res.push_back(ds);
            
        }
        return;
    }
    if(target>=v[i])
    {
        ds.push_back(v[i]);
        comb_sum_help(v,i,ds,target-v[i],res);
        ds.pop_back();
    }
    comb_sum_help(v,i+1,ds,target,res);
}
void comb_sum()
{
    vector<int>v={2,3,6,7};
    int target=7;
    vector<vector<int>>res;
    vector<int>ds;
    comb_sum_help(v,0,ds,target,res);
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void coin2_help(vector<int>&v,int target,int i,vector<vector<int>>&res,vector<int>&path)

{
    if(i==v.size())
    {
        if(target==0)
        {
            res.push_back(path);
        }
        return;
    }
    if(target>=v[i])
    {
        path.push_back(v[i]);
        coin2_help(v,target-v[i],i,res,path);
        path.pop_back();
    }
    coin2_help(v,target,i+1,res,path);
}
void coin2()
{
    vector<int>v={1,2,3};
    int target=4;
    vector<vector<int>>res;
    vector<int>path;
    coin2_help(v,target,0,res,path);
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void climb()
{
    int n=9;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(auto it:dp)
    {
        cout<<it<<" ";
    }
}
void lis()
{
    vector<int>v={0,1,0,3,2,3};
    vector<int>dp(v.size(),1);
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j] and dp[i]<dp[j]+1)
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
void isl_dfs(vector<vector<int>>&v,int i,int j)
{
    if(i>=v.size() or j>=v[0].size() or i<0 or j<0 or v[i][j]!=1)
    {
        return;
    }
    v[i][j]=8;
    isl_dfs(v,i-1,j);
    isl_dfs(v,i,j-1);
    isl_dfs(v,i+1,j);
    isl_dfs(v,i,j+1);
}
void isl()
{
    vector<vector<int>>v={{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    int is=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==1)
            {
                isl_dfs(v,i,j);
                is+=1;
            }
        }
    }
    cout<<is<<endl;
    for(auto it:v)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void consec_sub()
{
    vector<int>v={1, 9, 3, 10, 4, 20, 2};
    unordered_set<int>s;
    int len=0;
    for(auto it:v)
    {
        s.insert(it);
    }
    for(int i=0;i<v.size();i++)
    {
        if(s.find(v[i]-1)==s.end())
        {
            int j=v[i];
            while(s.find(j)!=s.end())
            {
                j++;
            }
            len=max(len,j-v[i]);
        }
    }
    cout<<len<<endl;
}
bool coursecycle(vector<vector<int>>&adj,int i,vector<int>&vis)
{
    if(vis[i]==2)
    {
        return true;
    }
    vis[i]=2;
    for(int it=0;it<adj[i].size();it++)
    {
        if(vis[it]!=1)
        {
            if(coursecycle(adj,it,vis))
            {
                return true;
            }
        }
    }
    vis[i]=1;
    return false;

}
void schedule()
{
    int num_c=2;
    vector<vector<int>>pre_req={{1,0},{0,1}};
    vector<vector<int>>adj(num_c);
    int p=0;
    for(int i=0;i<pre_req.size();i++)
    {
        adj[pre_req[i][0]].push_back(pre_req[i][1]);
    }
    vector<int>vis(num_c,0);
    for(int i=0;i<adj.size();i++)
    {
        if(vis[i]==0)
        {
            if(coursecycle(adj,i,vis))
            {
                p=1;
                break;
                // cout<<"cycle"<<endl;
                
            }
        }
    }
    if(p)
    {
        cout<<"cycle"<<endl;
    }
    else
    {
        cout<<"no cycle"<<endl;
    }

}
void jump()
{
    vector<int>v={2,3,1,0,0,4};
    int reach=0;
    for(int i=0;i<v.size();i++)
    {
        if(reach<i)
        {   cout<<"impossible"<<endl;
            break;
       
        }
        reach=max(i+v[i],reach);
    }
    cout<<"reach"<<endl;
}
void jump2()
    {
        vector<int>v={2,3,1,0,0,4};
        int reach=0;
        int num=0;
        int max_reach=0;
        int curreach=0;
        for(int i=0;i<v.size();i++)
        {
            if(i+v[i]>curreach)
            {
                curreach=i+v[i];
            }
            if(i==max_reach)
            {
                num+=1;
                max_reach=curreach;
            }
        }
    }

void jump3()
{
    vector<int>v={3,0,2,1,2};
    int start=2;
    queue<int>q;
    
    q.push(start);
    vector<bool>visit(v.size(),false);
    int p=0;
    while(!q.empty())
    {
        auto i=q.front();
        q.pop();
        auto front=i+v[i];
        auto rear=i-v[i];
        visit[i]=true;
        if(v[i]==0)
        {
            p=1;
            break;
        }
        if(front>=0 and front<v.size() and !visit[front])
        {
            q.push(front);
        }
        if(rear>=0 and rear<v.size() and !visit[rear])
        {
            q.push(rear);
        }
        
    }
    if(p)
    {
        cout<<"possible"<<endl;
    }
    else
    {
        cout<<"impossible"<<endl;
    }
}
int unique_help(int i,int j,int m,int n,vector<vector<int>>&v,vector<vector<int>>&dp)
{
    if(i==m-1 and j==n-1)
        return 1;
    if(v[i][j]==1)
    {
        return 0;
    }
    if(i>=m or j>=n)
        return 0;
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i!=m-1 and j!=n-1)
        return dp[i][j]=unique_help(i+1,j,m,n,v,dp) + unique_help(i,j+1,m,n,v,dp);
    return 0;    
}
void unique_ways()
{
    
    vector<vector<int>>v={{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>>dp(v.size()+1,vector<int>(v[0].size()+1,-1));
    unique_help(0,0,v.size(),v[0].size(),v,dp);
    for(auto it:dp)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void rob()
{
    vector<int>v={2,7,9,3,1};
    vector<int>dp(v.size()+1,0);
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<v.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+v[i]);
    }
}
int rob_helper(vector<int>v,int start,int end)
{
    vector<int>dp(v.size()+1,0);
    dp[start]=v[start];
    dp[start+1]=max(v[start],v[start+1]);
    for(int i=start+2;i<v.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+v[i]);
    }
    return dp[v.size()-1];
}
void rob2()
{
    vector<int>v={1,2,3,1};
    int x=rob_helper(v,0,v.size()-1);
    int y=rob_helper(v,1,v.size());
    cout<<max(  x,y  )<<endl;
}
void sum_int()
{
    int a=2;
    int b=7;
    auto c=a^b;
    cout<<c<<endl;
}
void count_bit()
{
    int n=3;
    vector<int>ans(n+1,0);
    for(int i=0;i<=n;i++)
    {
        int a=i;
        while(a)
        {

        }
    }
}
void repeat_miss()
{
    vector<int>v={3,1,2,5,4,6,7,5};
    sort(v.begin(),v.end());
    int miss=0;
    int repeat=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[i-1]==0)
        {
            repeat=v[i];
        }
        if(v[i]-v[i-1]>1)
        {
            miss=v[i]-1;
        }
    }
    pair<int,int>p;
    p.first=repeat;
    p.second=miss;
    cout<<p.first<<" "<<p.second<<endl;
}
void char_replace()
{
    string s="AABABBA";
    int k=1;
    int start=0;
    int end=0;
    int max_freq=0;
    // int wind_size=0;
    vector<int>freq(26,0);
    int max_length=0;
    while(end<s.size())
    {
        freq[s[end]-'A']++;
       max_freq=max(max_freq,freq[s[end]-'A']); 
        int wind_size=end-start+1;
        if(wind_size-max_freq<=k)
        {
            max_length=max(max_length,wind_size);
        }
        else{
            freq[s[start]-'A']--;
            start+=1;
        }
        end+=1;
    }
    cout<<max_length<<endl;
}
void long_sub()
{
    string s="pwwkew";
    map<char,int>m;
    int start=0,end=0;
    int max_length=0;
    while(end<s.size())
    {
        m[s[end]]++;
        if(m.size()==end-start+1)
            max_length=max(max_length,end-start+1);
        else 
        {
            while(m.size()<end-start+1)
        {       m[s[start]]--;
                if(m[s[start]]==0)
                {
                    m.erase(s[start]);

                }
                start++;
        }
        }
        end++;
    }
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<max_length<<endl;
}
void valid_p()
{
    string s="(){}[]";
    stack<char>st;
for(auto it:s)
{
    if(it=='(' or it=='{' or it=='[')
    {
        st.push(it);
    }
    else if(it==')')
    {
        if(st.top()=='(')
        {
            st.pop();
        }
        else
        {
            cout<<"not valid"<<endl;
            return;
        }
    }
    else if(it=='}')
    {
        if(st.top()=='{')
        {
            st.pop();
        }
        else
        {
            cout<<"not valid"<<endl;
            return;
        }
    }
    else if(it==']')
    {
        if(st.top()=='[')
        {
            st.pop();
        }
        else
        {
            cout<<"not valid"<<endl;
            return;
        }
    }
}
cout<<"valid"<<endl;

}
void long_pal()
{
    string s="lkbabababad";
    int start=0;
    int len=0;
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    for(int i=0;i<s.size();i++)
    {
        dp[i][i]=1;
        start=i;
        len=1;
    }
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            start=i;
            len=2;
        }
    }
    for(int i=3;i<s.size();i++)
    {
        for(int j=0;j<s.size()-i;j++)
        {
            int k=i+j-1;
            if(dp[j+1][k-1]==1 and s[j]==s[k])
            {
                dp[j][k]=1;
                start=j;
                len=max(len,i);
            }
        }
    }
    for(auto it:dp)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    cout<<s.substr(start,len)<<endl;

}
bool isPalindrome(string s) {

        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;

}
// void merge_list()
// {
//     if(!l1)
//     {
//         return l2;

//     }
//     if(!l2)
//     return l1;
//     if(l1->val>=l2->val)
//     {
//         head=l2;
//         head->next=merge_list(l1,l2->next);
//     }
//     if(l1->val<l2->val)
//     {
//         head=l1;
//         head->next=merge_list(l1->next,l2);
//     }
// }
// void merge_list()
// {
//     vector<vector<int>>v={{1,4,5},{1,3,4},{2,6}};
//     priority_queue<int,vector<int>,greater<int>>q;
//     for(auto it:v)
//     {
//         for(auto it1:it)
//         {
//             q.push(it1);
//         }
//     }
//     ListNode* head=new ListNode(),*temp=head;
//     while(!q.empty())
//     {
//         ListNode* t=new ListNode(q.top());
//         temp->next=t;
//         temp=temp->next;
//         q.pop();
        
//     }


//     for(int i=0;i<v.size();i++)
//     {
//         for(int j=0;j<v[i].size();j++)
//         {
//             cout<<q.top()<<" ";
//             q.pop();
//         }
//         cout<<endl;
//     }
// }
void merge_intervals()
{
    vector<vector<int>>v={{1,5},{8,9}};
    vector<vector<int>>res;
    vector<int>in={6,7};
    v.push_back(in);
    sort(v.begin(),v.end());
    for(auto it:v)
    {
        if(res.empty() or res.back()[1]<it[0])
        {
            res.push_back(it);
        }
        else{
            res.back()[1]=max(res.back()[1],it[1]);
        }
    }
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
bool static cmp(vector<int>a,vector<int>b)
{
    return a[1]<b[1];    
}
void min_remove()
{
    vector<vector<int>>v={{1,100},{11,22},{1,11},{2,12}};
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    vector<vector<int>>res;
    for(auto it:v)
    {
        if(res.empty() or (res.back()[0]<it[0] and res.back()[1]<it[1]))
        {
            res.push_back(it);
        }
       
        else
            ans++;
            
    }
    cout<<ans<<endl;
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void kahn()
{
    int n=6;
    vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);
    vector<int>indegree(n,0);
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    for(auto it:topo)
    {
        cout<<it<<" ";
    }
}
void find_topo_dfs(vector<int>adj[],vector<bool>&vis,int i,stack<int>st)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            find_topo_dfs(adj,vis,it,st);
        }
    }

    st.push(i);
}
void topo_dfs()
{
    int n=6;
    vector<int> adj[6];
    stack<int>st;
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            find_topo_dfs(adj,vis,i,st);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
void stock2_with_fee()
{
    vector<int>v={1,3,2,8,4,9};
    int profit=0;
    int first=v[0];
    int fee=2;
    for(int i=1;i<v.size();i++)
    {
        profit=max(profit,v[i]-first-fee);
        first=min(first,v[i]-profit);
    }
    cout<<profit;
}
void stock2()
{
    vector<int>v={7,1,5,3,6,4};
    int profit=0;
    int first=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>first)
        {
            profit=profit+v[i]-first;
            first=v[i];
        }
        else
        {
            first=v[i];
        }
    }
    cout<<profit;
}
void stock4()
{
    vector<int>v={1,2,5};
    int k=1;
    vector<vector<int>>dp(k+1,vector<int>(v.size(),0));
    for(int i=0;i<v.size();i++)
    {
        
    }
}
static bool comp(string &a,string &b)
{
    return a.size()<b.size();
}
void ques()
{
    vector<string>s={"a","b","ba","bca","bda","bdca"};
    sort(s.begin(),s.end(),comp);
    unordered_map<string,int>m;
    for(auto it:s)

    {
        cout<<it<<" "<<endl;
            for(int i=0;i<it.size();i++)
        {
            string temp=it.substr(0,i)+it.substr(i+1);
            if(m.find(temp)==m.end())
             {
                    m[it]=max(m[it],1);
                }
                else{
                    m[it]=max(m[it],m[temp]+1);
                }

        }
    }
        for(auto it:m)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
}
// void job_seq()
// {
//     vector<int>start={1,2,3,3};
//     vector<int>end={3,4,5,6};
//     vector<int>profit={50,10,40,70};
//     int profit=0;
//     vector<int>store(end.size(),-1);
// }
void path_with_max_prob()
{
    int n=3;
    vector<vector<int>>edges={{0,1},{1,2},{0,2}};
    vector<double>suc_prob={0.5,0.5,0.2};
    int src=0;
    int dst=2;
    
    vector<pair<int,double>>adj[n];
    for(auto it:edges)
    {
        adj[it[0]].push_back({it[1],suc_prob[it[0]]});
        adj[it[1]].push_back({it[0],suc_prob[it[0]]});
    }
    priority_queue < pair <double, int>>q;
    q.push({1,src});
    vector<double>res(n,0);
    while(!q.empty())
    {
        double curprob=q.top().first;
        auto cur=q.top().second;
        q.pop();
        for(auto it:adj[cur])
        {
            int neighbour=it.first;
            auto neighbourprob=it.second;
            if(res[it.first]<neighbourprob*curprob)
            {
                res[it.first]=neighbourprob*curprob;
                q.push({res[it.first],it.first});
            }
        }
    }
    cout<<res[dst];
}
void longest_pal()
{
    vector<string >v={"lc","cl","gg"};
    map<string,int>m;
    int ans=0;
    for(auto &it:v)
    {
        string temp=it;
        sort(temp.begin(),temp.end());
        if(m.find(temp)==m.end())
        {
            m[temp]++;
        }
        else{
            ans+=4;
            m[temp]--;
        }
    }
    for(auto it:v)
    {
        if(it[0]==it[1])
        {
            ans+=2;
            break;
        }
    }
    cout<<ans;
}
void network_delay()
{
    vector<vector<int>>times={{2,1,1},{2,3,1},{3,4,1}};
    int n=4;
    int src=2;
    vector<pair<int,int>>adj[n];
    for(auto it:times)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,int>>q;
    q.push({src,0});
    vector<int>res(n,INT_MAX);
    while(!q.empty())
    {
        auto size=q.size();
        while(size--)
        {
            int cur=q.front().first;
            int dist=q.front().second;
            q.pop();
            for(auto it:adj[cur])
            {
                int neighbour=it.first;
                int neighbourdist=it.second;
                
                if(res[neighbour]>dist+neighbourdist)
                {
                    res[neighbour]=dist+neighbourdist;
                    q.push({neighbour,res[neighbour]});
                }
            }
        }
    
    }
    for(auto it:res)
    {
        cout<<it<<" ";
    }
}
class a
{
    public:
    a()
    {
        cout<<"a";
    }
};
class B:public a
{
    public:
    B()
    {
        cout<<"b";
    }
};
void charge()
{
    vector<int>v={4,3,5};
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        int a=v[i];
        for(int j=0;j<v.size();j++)
        {
            int b=v[j];
            sum+=abs(a-b);
        }
    }
    cout<<sum;
}

void max_rating_sum()
{
   vector<int>v={20,4,3,1,9};
   int k=4;
   long sum=0;
   priority_queue<int>q;
   for(auto it:v)
   {
    q.push(it);
   }

   while(k--)
   {
        
   }
   cout<<sum;
}
int binary(vector<int>v,int l,int r)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==mid)
        {
            return mid;
        }
        else if(v[mid]>mid)
        {
            return binary(v,l,mid-1);
        }
        else{
            return binary(v,mid+1,r);
        }
    }
    return -1;
}
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail; // head and tail of the LinkedList

void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

void InsertatLast(int value) // Function for creating a LinkedList
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}
void seg()
{
    ListNode* oddhead=new ListNode(-1),*oddtail=oddhead;
    ListNode* evenhead=new ListNode(-1),*eventail=evenhead;
    ListNode* cur=head,*temp;
    while(cur!=NULL)
    {
        temp=cur;
        cur=cur->next;
        temp->next=NULL;
        if(temp->val%2==0)
        {
            eventail->next=temp;
            eventail=temp;
        }
        else{
            oddtail->next=temp;
            oddtail=temp;
        }
        
    }
    eventail->next=oddhead->next;
    auto node=evenhead->next;
    while(node)
    {
        cout<<node->val<<" ";
        node=node->next;
    }
}

int count1(vector<int>v,int i, int target, vector<vector<int
>>& dp)
{
    if(i==0)
    {        
        return (target%v[0]==0);
        
    }
    if(dp[i][target]!=-1)
    {
        return dp[i][target];
    }
    int taken=0;
    if(v[i]<=target)
    {
        taken=count1(v,i,target-v[i],dp);
    }
    int nottaken=count1(v,i-1,target,dp);
    return dp[i][target]=taken+nottaken;
}

void count12()
{
    vector<int>v={1,2,3};
    int target=4;
    vector<int>path;
    vector<vector<int>>res;
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
    cout<<count1(v,v.size()-1,target,dp);
}
// int mincoin1(vector<int>v,int i, int target, vector<vector<int
// >>& dp)
// {

// }
// void mincoin()
// {
//     vector<int>v={2,4,6};
//     int target=8;
//     vector<int>path;
//     vector<vector<int>>res;
//     vector<vector<int>>dp(v.size()+1,vector<int>(target+1,-1));
//     cout<<mincoin1(v,v.size()-1,target,dp);
// }
void allpermhelp(vector<int>v,vector<vector<int>>&res,int i)
{
    if(i==v.size())
    {
        res.push_back(v);
        return;
    }
    for(int it=i;it<v.size();it++)
    {
        swap(v[it],v[i]);
        allpermhelp(v,res,it+1);
        swap(v[it],v[i]);
    }
}
void allperm()
{
    vector<int>v={1,2,3};
    vector<int>path;
    vector<vector<int>>res;
    allpermhelp(v,res,0);
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void helpsum(vector<int>v,vector<int>&ans,int i,int sum)
{
    if(i==v.size())
    {
        ans.push_back(sum);
        return;
    }
    helpsum(v,ans,i+1,sum+v[i]);
    helpsum(v,ans,i+1,sum);
}
void subsum()

{
        vector<int>v={1,2,3};
    
    vector<int>ans;
    helpsum(v,ans,0,0);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
 
}
void count_reverse_pair()
{
    vector<int>v={1,3,2,3,1};
    int n=v.size();    
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]>2*v[j])
            {
                p.push_back({v[i],v[j]});
            }
        }
    }
    for(auto it:p)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
// void tasty_dishes()
// {
//     vector<int>size={10,7,8,11,1};
//     int m=2;
//     vector<int>taste={3,5,1,6,9};
//     vector<pair<int,int>>p;
//     for(int i=0;i<size.size();i++)
//     {
//         p.push_back({taste[i],size[i]});
//     }
//     int max_taste=0;
//     for(int i=0;i<size;i++)
//     {

//     }
// }
void chock_dist()
{
    vector<int>v={12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m=7;
    int j=m;
    int min_diff=INT_MAX;
    sort(v.begin(),v.end());
    for(int i=0;i+m-1<v.size();i++)
    {
          
      min_diff=min(min_diff,v[i+m-1]-v[i]);
        
        
    }
    cout<<min_diff;
}
bool prev_true(int i,vector<bool>&vis)
{
    for(int j=1;j<=i;j++)
    {
        if(vis[j]==false)
        {
            return false;
        }
    }
    return true;
}
void lightcheck()
{
    vector<int>v={4,1,2,3};
    int n=v.size();
    int times_blue=0;
    int i=0;
    vector<bool>vis(n+1,false);
    while(i<n)
    {
        vis[v[i]]=true;
        if(prev_true(v[i],vis))
        {
            cout<<i<<" ";
            times_blue++;
        }
        i++;
    }
    
}
void smallest_sub()
{
    string a="ADOBECODEBANC";
    string t="ABC";
   map<char,int>m;
   int n=0;
   for(auto it:t)
   {
    if(m[it]==0)
        n++;
       m[it]++;
   }
   int i=0;
   int j=0;
   int count=0;
   int min_len=INT_MAX;
   while(i<j and j<a.size())
   {
        if(count<n)
        {
            if(m[a[j]]==0) count++;
            m[a[j]]++;
            j++;
        }
        if(count==n)
        {
            min_len=min(min_len,j-i);
            if(m[a[i]]==1) count--;
            m[a[i]]--;
            i++;
        }
   }
   while(count==n)
   {
        min_len=min(min_len,j-i);
        if(m[a[i]]==1) count--;
        m[a[i]]--;
        i++;
   }
    cout<<min_len;
}
void all_permhelp(vector<int>v,int i,vector<vector<int>>&res,vector<int>&path)
{
    res.push_back(path);
    for(int it=i;it<v.size();it++)
    {
        if(it!=i and v[it]==v[it-1])
        {
            continue;
        }
        path.push_back(v[it]);
        all_permhelp(v,it+1,res,path);
        path.pop_back();
    }
}
void all_perm()
{
    vector<int>v={1,2,2};
    vector<vector<int>>res;
    vector<int>path;
    all_permhelp(v,0,res,path);
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
struct TreeNode{
    int data;
    TreeNode*left,*right;
};
TreeNode* newnode(int data)
{
    TreeNode* temp=new TreeNode;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void create_factor_tree(struct TreeNode **root,int val )
{
    *root=newnode(val);
    for(int i=2;i<val/2;i++)
    {
        if(val% i !=0)
        continue;
        create_factor_tree(&(*root)->left,i);
        create_factor_tree(&(*root)->right,val/i);
         return;
    }    
}
void printlevel(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        cout<<node->data<<" ";
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
int rob_help3(vector<int>v,vector<int>&dp,int start,int end)
{
    dp[start]=v[start];
    dp[start+1]=max(dp[start],v[start+1]);
    for(int i=start+2;i<end;i++)
    {
        dp[i]=max(dp[i-2]+v[i],dp[i-1]);
    }
    return dp[end-1];
}
void house_rob2()
{
    vector<int>v={1,2,3};
    vector<int>dp(v.size(),0);
    int x=rob_help3(v,dp,0,v.size()-1);
    int y=rob_help3(v,dp,1,v.size());
    cout<<max(x,y);
}
void similar_string()
{
    vector<string>v={"oof","of","avc","vac","pop"};
    int ans=0;
    int n=v.size();
    map<string,int>m;
    for(int i=0;i<n;i++)
    {
        vector<int>freq(28,0);
        for(auto it:v[i])
        {
            freq[it-'a']++;
        }
        string ss="";
        for(int j=0;j<26;j++)
        {
            if(freq[j])
            {
                ss+='a'+j;
            }
        }
        ans+=m[ss];
        m[ss]++;
    }
   for(auto it:m)
   {
       cout<<it.first<<" "<<it.second<<endl;
   }
}
    #define CLEARBIT(a, pos) (a &= ~(1 << pos) )
void bits()
{
    // int a=12;
    // int b=13;
    // int c=a^b;
    // int d=c^b;
    // cout<<a<<" "<<b<<" "<<c<<" "<<" "<<d;
   int a=8;
//    int b=(a &= ~(1 << 1));
    int b=16;
    if (!(b&(b-1)))
        cout<<"yes";
    
}
void subsethelp(vector<int>v,int i,int n,vector<vector<int>>&res,vector<int>&path)
{
    res.push_back(path);
    for(int it=i;it<n;it++)
    {
        if(v[it]==v[it-1] and it!=i)
            continue;
        path.push_back(v[it]);
        subsethelp(v,it+1,n,res,path);
        path.pop_back();
    }
    
    
}
void sub_set()
{
    vector<int>v={1,2,2};
    int n=v.size();
    vector<vector<int>>res;
    vector<int>path;
    subsethelp(v,0,n,res,path);
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void find_num()
{
    vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9}};
    int num=4;
    int row=mat.size();
    int col=mat[0].size();
    int i=0;
    int j=col-1;
    while(i<row and j>=0)
    {
        if(mat[i][j]<num)
        {
            i++;
        }
        else if(mat[i][j]>num)
        {
            j--;
        }
        else if(mat[i][j]==num)
        {
            cout<<i<<" "<<j;
            return;
        }
    }

}
void easy_dest()
{
    vector<vector<string>>v={{"london","new york"},{"new york","taipei"},{"taipei","kart"}};
    map<string,int>m;
    for(auto it:v)
    {
        m[it[0]]+=1;
    }
    for(auto it:v)
    {
        if(m[it[1]]==0)
        {
           cout<<it[1];
        }
    }
}
void rotten_oranges()
{
    vector<vector<int>>v={{0,1,2},{0,1,2},{2,1,1}};
    queue<pair<int,int>>q;
    int rot=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==2)
                q.push({i,j});
            if(v[i][j]!=0)
            {
                rot++;
            }
        }
    }
    int days=0;
    int cnt=0;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty())
    {
       int k=q.size();
       cnt+=k;
       while(k--)
       {
        auto x=q.front().first;
        auto y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 or ny<0 or nx>=v.size() or ny>=v[0].size() or v[nx][ny]!=1)
                continue;
            v[nx][ny]=2;
            q.push({nx,ny});
            }    
            
            
        
        }
        if(!q.empty())
        {
            days++;
        }
       }
       cout<<days;
    }
int strings_and_password()
{
    string old_pas="abc123";
    string new_pas="abc153";
    if(old_pas.size()<new_pas.size())
    {
        return new_pas.size()-old_pas.size();
    }
    else{
    map<char,int>new_map;
    for(auto it:new_pas)
    {
        new_map[it]++;
    }
    int cnt=0;
    map<char,int>old_map;
    for(auto it:old_pas)
    {
        old_map[it]++;
    }

    for(auto it:old_map)
    {
        cout<<it.first<<" "<<it.second<<endl;
        if(new_map[it.first]==0)
        {
           
            cnt+=old_map[it.first];
        }
        else if(new_map[it.first]!=old_map[it.first])
        {
            
            cnt+=old_map[it.first]-new_map[it.first];
        }
    }
    for(auto it:new_map)
    {
        cout<<it.first<<" "<<it.second<<endl;
        if(old_map[it.first]==0)
        {
           
            cnt+=old_map[it.first];
        }
        else if(new_map[it.first]!=old_map[it.first])
        {
            
            cnt+=old_map[it.first]-new_map[it.first];
        }
    }
    
    return cnt;
    }
 
    
}
void longest_positive_array()
{
    // vector<int>v={1,-1,-1,-1,1,1,-1,1};
    vector<int>v={9,9,9,6,0,6,6,9};
    int tiring=0;
    int normal=0;
    int max_tiring=0;
    int max_normal=0;
    for(auto it:v)
    {
        if(it>8)
        {
            tiring+=1;
            max_tiring=max(max_tiring,tiring);
            normal=0;
        }
        else{
            normal+=1;
            max_normal=max(max_normal,normal);
            tiring=0;
        }
    }
    cout<<max_tiring<<" "<<max_normal;

    // int max_index=0;
    
    // int sum=0;
    // int ans=0;
    // for(auto it:v)
    // {
    //     sum+=it;
    //     if(sum<0)
    //     {
    //         sum=0;
    //     }
    //     if(sum>0)
    //     {
            
    //         ans=max(max_index,ans);
    //         max_index++;
    //     }
    // }
    
    
}
map<int,bool>m;
set<string>dic;
bool wordbreakhelp(string s,int pos)
{
    if(pos==s.size())
            return true;
        if(m.count(pos))
        {
            return m[pos];
        }
        for(int i=pos;i<s.size();i++)
        {
            if(dic.count(s.substr(pos,i-pos+1)))
            {
                if(wordbreakhelp(s,i+1))
                {
                    return m[pos]=true;
                }
            }
        }
        return m[pos]=false;
}
void wordbreak()
{
    vector<string>v={"leetc","ode","gg","app"};
    string s="leetcode";
    for(auto it:v)
    {
        dic.insert(it);
    }
    bool t=wordbreakhelp(s,0);
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    
}
int lpshelp(string s,string t,int m,int n,vector<vector<int>>&dp)
{
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(m<=0 or n<=0)
    {
        return 0;
    }
    
    if(s[m-1]==t[n-1])
    {
        return dp[m-1][n-1]=1+lpshelp(s,t,m-1,n-1,dp);
    }
    else{
        return dp[m-1][n-1]=max(lpshelp(s,t,m-1,n,dp),lpshelp(s,t,m,n-1,dp));
    }
}

void lps()
{
    string s="bbab";
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     lpshelp(s,t,n,n,dp);
   for(auto it:dp)
   {
       for(auto it1:it)
       {
           cout<<it1<<" ";
       }
       cout<<endl;
   }
   cout<<dp[n-1][n-1];
}
void perfect_square()
{
    int n=12;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j*j<=i;j++)
    {
        dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    
   }
    for(auto it:dp)
    {
         cout<<it<<" ";
    }
    
}
void netowrk_inform()
{
    vector<int>manager={2,2,-1,2,2,2};
    vector<int>informTime={0,0,1,0,0,0};
    int headid=2;
    int ans=0;
    vector<vector<int>>adj(manager.size());
    for(int i=0;i<manager.size();i++)

    {
        if(manager[i]>=0)
        {
            adj[manager[i]].push_back(i);
        }
        
    }
    
    queue<pair<int,int>>q;
    q.push({headid,0});
    while(!q.empty())
    {
        int person=q.front().first;
        int time=q.front().second;
        q.pop();
        ans=max(ans,time);
        for(int i=0;i<adj[person].size();i++)
        {
            q.push({adj[person][i],time+informTime[person]});
        }
    }
    
    cout<<ans;
}
void cata()
{
    int n=5;
    vector<int>dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    for(auto it:dp)
    {
        cout<<it<<" ";
    }
}
void calcu()
{
    int n=40;
    int d=13;
    string ans="";
    n=abs(n);
    d=abs(d);
    ans+=to_string(n/d);
    long long rem=n%d;
    if(!rem) return;
    else
        ans+=".";
    unordered_map<int,int>m;
    while(rem!=0)
    {
        if(m.find(rem)!=m.end())
        {
            ans.insert(m[rem],"(");
            ans+=")";
            break;
        }
        cout<<ans<<endl;
        m[rem]=ans.size();
        rem*=10;
        ans+=to_string(rem/d);
        rem=rem%d;
        
    }

}
void monk()
{
    vector<int>v={2,1,7,4,2};
    int sum=0;
    priority_queue<int>q;
    int k=3;
    for(auto it:v)
    {
        q.push(it);
    }
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    // while(k--)
    // {
    //     auto node=q.top();
    //     q.pop();
    //     sum+=node;
    //     int val=node/2;
    //     q.push(val);

       
    // }
    // cout<<sum;
}
void convert()
{
    string s="1100110";
    string ans="";
    int n=s.size();
    if(n%3==1)
    {
        s="00"+s;
    }
    else if(n%3==2)
    {
        s="0"+s;
    }
    for(int i=0;i<s.size();i+=3)
    {
        int temp=(s[i]-'0')*4+(s[i+1]-'0')*2+(s[i+2]-'0')*1;
        ans+=to_string(temp);
    }
    cout<<ans;
}
void oct_to_dec()
{
    string s="345";
    string ans="";
    int deci=0;
    for(int i=0;i<s.size();i++)
    {
        int temp=s[i]-'0';
        temp=temp*pow(8,s.size()-i-1);
        deci=deci+temp;
    }
    ans+=to_string(deci);
    cout<<ans;
}
void oct_to_bin()
{
    int n=345;
    string ans="";
    int rem=0;
    while(n)
    {
        rem=n%8;
        ans+=to_string(rem);
        n=n/8;
    }
        cout<<ans;
    
}
void sum_eql_to_k()
{
    vector<int>v={1,2,3};
    int k=3;
    map<int,int>m;
    vector<int>prefix(v.size(),0);
    prefix[0]=v[0];
    for(int i=1;i<v.size();i++)
    {
        prefix[i]=prefix[i-1]+v[i];
    }
    int res=0;
    for(int i=1;i<v.size();i++)
    {
        if(prefix[i]==k)
        {
            res++;
        }
        if(m.find(prefix[i]-k)!=m.end())
        {
            res+=m[prefix[i]-k];
        }
        m[prefix[i]]++;
    }
    cout<<res;
    
}
void min_pal()
{
    string s="aabcd";
    int count=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int left=i;
        int right=n-i-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                break;
            }
            else{
                right--;
            }
           
        }
        if(left==right)
        {
            return;
        }
        else{
            for(int j=right;j<n-i-1;j++)
            {
                swap(s[j],s[j+1]);
                count++;
            }
        }
        
    }
    cout<<count;
}
void bubble()
{
    vector<int>v={3,1,12,2,4};
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=0;j<v.size()-1-i;j++)
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}
void selection()
{
    vector<int>v={3,1,12,2,4};
    int mini;
    for(int i=0;i<v.size();i++)
    {
        mini=i;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]<v[mini])
            {
                mini=j;
            }
        }
        if(mini!=i)
        {
            swap(v[mini],v[i]);
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}
void insertion()
{
    vector<int>v={3,1,12,2,3,2,4};
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]>v[i])

            {
                swap(v[j],v[i]);
            }
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}
int max_3_help(int i,vector<int>v,vector<vector<int>>&dp,int sum)
{
    if(i==v.size())
    {
        if(sum==0)       
            return 0;
        return INT_MIN;
    }
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    int pick=v[i]+max_3_help(i+1,v,dp,(v[i]+sum)%3);
    int notpick=max_3_help(i+1,v,dp,sum);
    return dp[i][sum]=max(pick,notpick);
}
void max_3()
{
    vector<int>v={3,6,5,1,8};
    vector<vector<int>>dp(v.size(),vector<int>(3,-1));
    max_3_help(0,v,dp,0);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool prime(int num)
{
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
void count_primes()
{
    int count=0;
    int l=5,r=10;
    vector<bool>prime(r+1,false);

    for(int i=2;i*i<=r;i++)
    {
        if(prime[i]==false)
        {
            
            for(int j=i*i;j<=r;j+=i)
            {
                cout<<j<<" ";
                prime[j]=true;
            }
            cout<<endl;
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(prime[i]==false)
        {
            count++;
        }
    }


   
}
void kadane()
{
    vector<int>v={-2,1,-3,4,-1,2,1,-5,4};
    int curmax=0;
    int maxsofar=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        curmax=curmax+v[i];
        if(curmax<0)
        {
            curmax=0;
        }
        maxsofar=max(maxsofar,curmax);
    }
    cout<<maxsofar;
}
void dest()
{
    vector<vector<string>>v={{ "London", "New York" }, { "New York", "Tampa" }, { "Delhi", "London" }};
    map<string,int>m;
    for(auto it:v)
    {
       m[it[0]]++;
    }
    for(auto it:v)
    {
        if(m.find(it[1])==m.end())
        {
            cout<<it[1];
            return;
        }
    }

}
void consec_sum()
{
    int n=15;
    // int sum=0;
    vector<vector<int>>res;
    for(int i=1;i<n-1;i++)
    {
        vector<int>temp;
        int sum=0;
        int j=i;
        while(j<n-1 and sum<n)
        {
            sum+=j;
            temp.push_back(j);
            j++;
        }
        if(sum==n)
        {
            res.push_back(temp);
        }
    }
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void sort012()
{
    vector<int>v={2,1,0,1,0,2,0,1,0,0,2};
    int x=0,y=0,z=v.size()-1;
    while(y<=z)
    {
        if(v[y]==0)
        {
            swap(v[x],v[y]);
            x++;
            y++;
        }
        else if(v[y]==1)
        {
            y++;
        }
        else if(v[y]==2)
        {
            swap(v[y],v[z]);
            z--;
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    
}
int stockcoolhelp(int ind,vector<int>v,vector<vector<int>>&dp,int buy)
{
    if(ind>=v.size())
    {
        return 0;
    }
    if(dp[ind][buy]!=-1)
    {
        return dp[ind][buy];
    }
    int cooldown=stockcoolhelp(ind+1,v,dp,1);
    if(buy)
    {
        int b=-v[ind]+stockcoolhelp(ind+1,v,dp,0);
        dp[ind][buy]=max(b,cooldown);
        
    }
    else{
        int sell=v[ind]+stockcoolhelp(ind+2,v,dp,0);
        dp[ind][buy]=max(sell,cooldown);
    }
    return dp[ind][buy];
}
void stockcool()
{
    vector<int>v={1,2,3,0,2};
    vector<vector<int>>dp(v.size(),vector<int>(2,-1));
    cout<<stockcoolhelp(0,v,dp,1);
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
void search()
{
    vector<int>v={4,5,6,7,0,3,2};
    int target=3;
    int l=0,r=v.size()-1;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(v[m]==target)
        {
            cout<<m;
            return;
        }
       if(v[m]>=v[l])
       {
        if(v[l]>target or target >v[m])
        {
            l=m+1;
        }
        else{
            r=m-1;
        }
       }
       else{
        if(v[r]<target or target<v[m])
        {
            r=m-1;
        }
        else{
            l=m+1;
        }
       }
    }
}
// void longest_with()
// {
//     string s="abcabcbb";
//     int ans=0;
//     vector<int>freq();
// }

void _2place()
{
    string s="amazonamazon";
    string t="zonama";
    string res=s+t;
    auto p=res.find(t);
    if(p==3 or p==s.size()-3)
    {
        cout<<"true";
    }
}
 
// void stock1()
// {

// }
// {
//     vector<int>v={7,1,5,3,6,4};
//     int sum=0;
//     vector<int>dp(v.size(),0);
//     dp[0]=v[0];
//     for(int i=1;i<v.size()-1;i++)
//     {
//         if(v[i]<dp[i-1])
//         {
//             dp[i]=v[i];
//         }
//         else
//         {
//             dp[i]=dp[i-1];
//         }
//     }
//     for(auto it:dp)
//     {
//         cout<<it<<" ";
//     }
// }
void longest_unique()
{
    string s="abcabcdbb";
    int ans=0;
    int i=0,end=0;
    map<char,int>m;
    while(end<s.size())
    {
        m[s[end]]++;
        if(m.size()==end-i+1)
        {
            ans=max(ans,end-i+1);
        }
        else{
            while(m.size()<end-i+1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);

                }
                i++;
            }
        }
        end++;
    }
    cout<<ans;
}
void longest_repeat()
{
    string s="aababba";
    int k=1;
    vector<int>freq(26,0);
    int i=0,end=0;
    int ans=0;
    int maxfreq=0;
    while(end<s.size())
    {
        freq[s[end]-'a']++;
        maxfreq=max(maxfreq,freq[s[end]-'a']);
        if((end-i+1)-maxfreq>k)
        {
            freq[s[i]-'a']--;
            i++;
        }
        else{
            ans=max(ans,end-i+1);
        }
        end++;
    }
    cout<<ans;
}
void group_anagram()
{
    vector<string>v={"eat","tea","tan","ate","nat","bat"};
    map<string,vector<string>>m;
    for(auto it:v)
    {
        string temp=it;
        sort(temp.begin(),temp.end());
        m[temp].push_back(it);

    }
    for(auto it:m)
    {
        for(auto it1:it.second)
        {
            cout<<it1<<" ";
        }
        cout<<endl;}
}
void valid_parenthesis()
{
    string s="()[]{}";
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')

        {
            st.push(s[i]);
        }
        else if(s[i]==')' and st.top()=='(')
        {
            st.pop();
        }
        else if(s[i]=='}' and st.top()=='{')
        {
            st.pop();
        }
        else if(s[i]==']' and st.top()=='[')
        {
            st.pop();
        }
    }
    if(st.empty())
    {
        cout<<"true";
    }
}
void valid_pal()
{
    string s="A man , a plan, a canal: Panama       ";
    string temp="";
    for(int i=0;i<s.size();i++)
    {
        
        if(isupper(s[i]))
        {
            temp+=tolower(s[i]);
        }
        else if(islower(s[i])){
            temp+=s[i];
        }
        else{
            continue;
        }
        

    }
    string temp2=temp;
    reverse(temp.begin(),temp.end());
        
    // cout<<temp;
}
void longest_pal_sub()
{
    string s="abababad";
    int start=0,length=0;
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
    for(int i=0;i<s.size();i++)
    {
        dp[i][i]=1;
        start=i;
        length=1;
    }
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            start=i;
            length=2;
        }
    }
   
    int ans=0;
    for(int i=3;i<=s.size();i++)
    {
        for(int j=0;j<s.size()-i;j++)
        {
            int k=i+j-1;
            if(s[j]==s[k] and dp[j+1][k-1]==1)
            {
                dp[j][k]=1;
                start=j;
                length=max(length,i);
            }
            cout<<start<<" "<<length<<endl;
        }
        
    }
    cout<<s.substr(start,length);
    
}
void subset_string()
{
    string s="abc";
    vector<string>v;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            cout<<s.substr(i,j-i+1)<<endl;
        }
    }
}
int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
int findi()
{
    vector<int>v={23456,446,555,9988};
    vector<vector<int>>res(v.size(),vector<int>(v.size(),0));
    for(auto it:v)
    {
        int temp=it;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        while(temp)
        {
            int rem=temp%10;
            mini=min(mini,rem);
            maxi=max(maxi,rem);
            temp/=10;
        }
        int temp1=it;
        vector<int>ans;
        while(temp1)
        {
            int remi=temp1%10;
            temp1=temp1/10;
            if(remi!=mini and remi!=maxi)
            {
                ans.push_back(remi);
            }
            
        }
        res.push_back(ans);
         
    }
    for(auto it:res)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    int sum=0;
    vector<int>result;
    for(auto it:res)
    {
        int temp=0;
        for(auto it1:it)
        {
            temp=temp*10+it1;
        }
       
        result.push_back(reverseDigits(temp));
    }
    
    return accumulate(result.begin(),result.end(),0);
    
   
    //  cout<<sum;
   
}
void with_transc()
{
    vector<int>v={2,4,8,6,7};
    int k=2;
    int ans=0;
    vector<vector<int>>dp(k+1,vector<int>(v.size()+1,0));
    for(int i=1;i<=k;i++)
    {
        int max_diff=INT_MIN;
        for(int j=1;j<v.size();j++)
        {
            max_diff=max(max_diff,dp[i-1][j-1]-v[j-1]);
            dp[i][j]=max(max_diff+v[j],dp[i][j-1]);
            ans=max(ans,dp[i][j]);
        }
        

    }
    for(auto it:dp)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}
void pal(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
void d1elete()
{
    int count=0;
    float sum=0.0,j=1.0,i=2.0;
    while(i/j>0.001)
    {
        j=j+j;
        sum+=i/j;
        cout<<sum<<endl;
        count++;
    }
    cout<<count;
}
class emp{
    public:
    int id;
    string name;
    float sal;
};
void min_mult()
{
    vector<int>v={2,5,7};
    int start=3;
    int end=30;
    queue<pair<int,int>>q;
    q.push({start,0});
    while(!q.empty())
    {
        int node=q.front().first;
        int count=q.front().second;
        q.pop();
        for(auto it:v)
        {
            int num=node*it;
            q.push({num,count+1});
            if(num==end)
            {
                cout<<count+1;
                return;
            }
            
        }
    }
}
int recur(stack<int>s)
{
    if(s.size()==1)
    {
        return s.top();
    }
    int temp=s.top();
    s.pop();
    int ans=recur(s);
    s.push(temp);
    return ans;
}
void stack_recur()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    auto newstack=recur(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
void long_non_repeat()
{
    string s="abcabdd";
    map<char,int>m;
    int start=0,end=0;
    int ans=0;
    int index=0;
    while(end<s.size())
    {
        m[s[end]]++;
        if(m.size()==(end-start+1))
        {
            index=start;
            ans=max(ans,end-start+1);
            
        }
        else{
           while(m.size()<end-start+1)
            {       
                m[s[start]]--;
                if(m[s[start]]==0)
                {
                    m.erase(s[start]);

                }
                start++;
            }
            
        }
        end++;
        
    }
    cout<<s.substr(index,ans);
}
void left_right_game()
{
    string s="LRRLLL";    
    vector<int>ans;
    vector<int>size;
    int n1=s.size();
    int n=pow(2,n1);
    
    int start=0;
    
    int mid=n/2;
    int end=n;
    for(int i=0;i<s.size();i++)
    {
        mid=(start+end)/2;
        size.push_back(mid);
        if(s[i]=='L')
        {
            end=mid;
        }
        else{
            start=mid;
        }
        mid=(start+end)/2;       
    }
   vector<vector<int>>v;
    for(int i=0;i<size.size();i++)
    {
        v.push_back({size[i],i+1});
    }
    sort(v.begin(),v.end());
    for(auto it:v)
    {
        ans.push_back(it[1]);
    }
    
}
int main()
{  
   left_right_game();
    // d1elete();
    
}
    // max_rating_sum();
    // path_with_max_prob();
    
    // merge_intervals();    
    

    // count_bit();
    // sum_int();
