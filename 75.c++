#include<bits/stdc++.h>
using namespace std;
 void mult()
{
    string s="12";
    string t="12";
    int m=s.length();
    int n=t.length();
    vector<int>v(m+n,0);
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            v[i+j+1]=(s[i]-'0')*(t[j]-'0')+v[i+j+1];
            v[i+j]+=v[i+j+1]/10;
            v[i+j+1]%=10;
        }

    }
    string res="";
    int i=0;
    while(v[i]==0 and i<m+n)
    {
        i++;
    }
    while(i<m+n)
    {
        res.push_back(v[i++] + '0');

    }
    cout<<res;
}
void add()
{
    string s="312";
    string t="312";
    int m=s.length();
    int n=t.length();
    vector<int>v(m+n,0);
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            v[i+j+1]=(s[i]-'0')+(t[j]-'0')+v[i+j+1];
            v[i+j]+=v[i+j+1]/10;
            v[i+j+1]%=10;
        }
    }
    for(int i=m+n-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
}
bool ok(string &s,string &t)
{
    int i=0, j=0;
    while(i<s.size() and j<t.size())
    {
        int cnt1=1,cnt2=1;
        if(s[i]!=t[j])
            return false;
        while(i+1<s.size() and s[i]==s[i+1]) cnt1++,i++;
        while(j+1<t.size() and t[j]==t[j+1]) cnt2++,j++;

        if(cnt1!=cnt2)
        {
            if(cnt1>cnt2)
            return false;
            if(cnt2<3)
            return false;
        }
        i++;
        j++;
    }
    if(i==s.size() and j==t.size())
    return true;
    return false;
}
void expressive()
{
    string s="zzzzzyyyyy";
    vector<string>words={"zzyy","zy","zyy"};
    int ans=0;
        for(int i=0;i<words.size();i++){
            if(ok(words[i],s))
                ans++;
        }
    cout<<ans;
    
   
    
}
vector<int>v;
void nummy(int number,int x,int k)
{
    if(k==0)
        {
            v.push_back(number);
            return;
        }
    for(int i=(x+1);i<=9;i++)
    {
        
        nummy(number*10+i,i,k-1);
        
        
    }
}
void sum3()
{
    vector<int>v={-1,0,1,2,-1,-4};
    int n=v.size();
    int sum=0;
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++)
    {
        if(i==0 or v[i]!=v[i-1])
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {sum=v[i]+v[j]+v[k];
            if(sum==0)
            {
                ans.push_back({v[i],v[j],v[k]});
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
     for(auto it:ans)
    {
       cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
   
}
void task()
{
    vector<char>v={'A','A','A','B','B','B'};
    int n=2;
    map<char,int>m;
    for(auto it:v)
    {
        m[it]++;
    }
    priority_queue<int>pq;
    for(auto it:m)
        pq.push(it.second);
    int res=0;
    while(!pq.empty())
    {
        int time=0;
        vector<int>temp;
        for(int i=0;i<n+1;i++)
        {
            if(!pq.empty())
            {
                temp.push_back(pq.top()-1);
                pq.pop();
                time++;
            }
        }
        for(auto it:temp)
        {
            if(it)
            {
                pq.push(it);
            }
        }
        res+=pq.empty()?time:n+1;

    }    
    cout<<res;
}
void pal(string s )
{
    int left=0;
    int count=0;
    int right=s.length()-1;
    for(int i=0;i<s.size();i++)
    {
        left=i;
        right=s.length()-1-i;
        while(left<right)
        if(s[left]==s[right])
            break;
        else{
            right--;
        }
        if(left==right)
        {
            
            break;

        }
        else{
            for(int j=right;j<s.size()-left-1;j++)
            {
                swap(s[j],s[j+1]);
                count++;
            }
        }
        

            // ananbkj
            
    }
    cout<<count<<endl;
}
void search()
{
    vector<vector<int>>v={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int target=13;
    int left=0;
    int right=v.size()-1;
    int i=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i][v.size()-1]>target)
            break;
    }
    while(left<right)
    {
        int mid=left+right/2;
        if(v[i][mid]>target)
        {
            right=mid-1;
        }
        else if(v[i][mid]<target)
        {
            left=mid+1;
        }
        else
        {
            cout<<"found at "<<" row "<<i<<" col "<<mid;
            break;
        }

        }
    }

    
void longest_pal()
{
    vector<string >words={"ab","ty","aa","aa","yt","lc","cl","ab"};
    int n=words.size();
    int ans=0;
    map<string,int>m;
    for(auto it:words)
    {
        string t=it;
        reverse(t.begin(),t.end());
        if(m.find(t)!=m.end())
        {
            ans+=4;
            m[t]--;
            cout<<t<<endl;
            if(m[t]==0)
                m.erase(t);
        }
        else{
            m[it]++;
        }
    }
    for(auto it:m)
    {
        if(it.first[0]==it.first[1])
            {
                ans+=2;
                break;
            }
    }

    
    cout<<ans;
}
void rotten()
{
    vector<vector<int>>v={{2,1,1},{1,1,0},{0,1,1}};
    queue<pair<int,int>>q;
    int rot=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            if(v[i][j]==2)
            {
                q.push({i,j});
            }
            if(v[i][j]!=0)
            {
                rot++;
            }
        }
    }
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int days=0;
    int cnt=0;
    while(!q.empty())
    {
        int k=q.size();
        cnt+=k;
        while(k--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=v.size() or ny<0 or ny>=v[0].size() or v[nx][ny]!=1)
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

    if(rot==cnt)
    {
        cout<<days;
    }
}
void next_perm()
{
    vector<int>v={1,1,5};
    int breakpoint=-1;
    int n=v.size();
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]>v[i-1])
        {
            breakpoint=i-1;
            break;
        }
    }
    if(breakpoint==-1)
    {
        reverse(v.begin(),v.end());
        
    }
    for(int i=n-1;i>=0;i--)
    {
        if(v[i]>v[breakpoint])
        {
            swap(v[i],v[breakpoint]);
            break;
        }
    }
    int point=breakpoint+1;
    sort(v.begin()+point,v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
bool static cmp(string x,string y)
{
    string s1=x.append(y);
    string s2=y.append(x);
    return s1>s2?true:false;
}
void formlarge()
{
    vector<string>v={"64","564","548","60"};
    sort(v.begin(),v.end(),cmp);
    for(auto it:v)
    {
        cout<<it<<endl;
    }
}
int change(vector<int>&v,vector<vector<int>>&dp,int amount,int i)
{
    
        if(amount==0)
            return 0;
        if(i>=v.size() or amount<0)
            return 1e9;
            if(dp[i][amount]!=-1)
        return dp[i][amount];
    int take=1+change(v,dp,amount-v[i],i);
    int nottake=change(v,dp,amount,i+1);
    return dp[i][amount]=min(take,nottake);        

}
void coin_change()
{
    vector<int>v={1,2,5};
    int amount=11;
    vector<vector<int>>dp(v.size()+1,vector<int>(amount+1,-1));
    cout<<change(v,dp,amount,0);
    for(auto it:dp)
    {
        for(auto it:it)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
bool isub(vector<int>&v,vector<vector<int>>&dp,int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0 and sum!=0)
        return false;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(v[n-1]<=sum)
    {
        dp[n][sum]=isub(v,dp,n-1,sum) or isub(v,dp,n-1,sum-v[n-1]);
        return dp[n][sum];
    }
    return dp[n][sum]=isub(v,dp,n-1,sum);    

}
void partsum()
{
    vector<int>v={1,7,2,2};
    int n=v.size();
    int sum=0;
    for(auto &it:v)
        sum+=it;
    if(sum & 1)
    {    cout<<"false";
        return;
    }
    
    vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
    cout<<isub(v,dp,n,sum/2);

}
void sum3close()
{
    vector<int>v={-1,2,1,-4};
    int target=1;
    int res=v[0]+v[1]+v[v.size()-1];
    sort(v.begin(),v.end());
    int l,r;
    for(int i=0;i<v.size()-1;i++)
    {
        l=i+1;
        r=v.size()-1;
        while(l<r)
        {
            int sum=v[i]+v[l]+v[r];
            if(sum>target)
            {
                r--;
            }
            else{
                l++;
            }
            if(abs(sum-target)<abs(res-target))
                res=sum;
        }
    }
    cout<<res;
    // -4,-1,1,2
}
void minwindowsub()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    int start=0;
    int end=0;
    string res=" ";
    int counter=t.size();
    vector<int>freq(256,0);
    for(auto &it:t)
        freq[it]++;
    int mini=INT_MAX;
    int head=start;   
    while(end<s.size())
    {
        if(freq[s[end++]]-- >0) counter--;
        while(counter==0)
        {
            if(end-start<mini)
            {
                mini=end-(head=start);
            }
            if(freq[s[start++]]++ ==0 )
                counter++;
        }
    }
    cout<<s.substr(head,mini);
}
void search2()
{
    vector<int>v={4,5,6,7,0,1,2};
    int target=0;
    int left=0;
    int right=v.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(v[mid]==target)
        {
            cout<<mid<<endl;
            break;
        }
        if(v[mid]>=left)
        {
            if(v[mid]<target or v[left] > target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }

        }
        else{
            if(v[mid]>target or v[right]<target)
            {
                right=mid-1;

            }
            else 
            {
                left=mid+1;
            }
        }
    }
}
void prime()
{
    int n=100;
    vector<bool>v(n+1,false);
    v[0]=true;
    for(int i=2;i<=n;i++)
    {
        for(int j=i*i;j<=n;j+=i)
        {
            v[j]=true;
        }
        }
    
    for(int i=0;i<=n;i++)
    {
        if(v[i]==false)
            cout<<i<<" ";
    }
    }
bool compare(string a,string b,map<char,int>&m)
{
    // wor,wol
    int i=0;
    while(i<a.size() and a[i]==b[i])
    {
        i++;
    }
    if(i==a.size() or i==b.size())
        return false;
    return m[a[i]]>m[b[i]];
}
void alien_language()
{
    string order="hlabcdefgijkmnopqrstuvwxyz";
    vector<string>words={"hello","leetcode"};
    map<char,int>m;
    for(int i=0;i<=26;i++)
    {
        m[order[i]]=i;
    }
    
    for(int i=0;i<words.size()-1;i++)
    {
        if(compare(words[i],words[i+1],m))
        {
            cout<<"false";
            return;
        }
    }
    
    

}
// void insert_interval()
// {
//     vector<vector<int>>v={{2,5},{6,9}};
//     vector<int>nil={1,4};
//     vector<vector<int>>ans;
//     for(int i=0;i<v.size();i++)
//     {
//         if(ans.empty() or v[i][0]>nil[0])
//         {
//             vector<int>temp;
//             ans.push_back()
//         }
//         else{
//             vector<int>temp={v[i][0]};
//             if(v[i][1]>nil[1])
//                 temp.push_back(v[i][1]);
//             else
//                 temp.push_back(nil[1]);
//             ans.push_back(temp);    
//         }
//     }
//     for(auto &it:ans)
//     {
//         for(auto &it1:it)
//             cout<<it1<<" ";
//         cout<<endl;
//     }
// }
bool static comp2(vector<int>a,vector<int>b)
{
    return a[2]>b[2];
}
void job_sq()
{
    int start_time[]={1,2,3,4};
    int end_time[]={4,1,2,2};
    int profit[]={20,10,40,30};
    vector<vector<int>>adj;
    for(int i=0;i<4;i++)
    {
        adj.push_back({start_time[i],end_time[i],profit[i]});
    }
    sort(adj.begin(),adj.end(),comp2);
   
    int n=adj.size();
    vector<int>store(n,-1);
    int max_profit=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=adj[i][1];j>0;j--)
        {
            if(store[j]==-1)
            {
                store[j]=i;
                count++;
                max_profit+=adj[i][2];
                cout<<"count "<<j<<" max profit  "<<max_profit<<endl;
                break;
            }
        }
    }
    cout<<max_profit<<endl;
//    for(int i=0;i<4;i++)
//    {
//         cout<<adj[i][0]<<" "<<adj[i][1]<<" "<<adj[i][2]<<endl;
//    }
   
}
void basic_cal()
{
    string s="2*2";
stack<int> st;
        int temp=0, ans=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])) temp=temp*10+(s[i]-'0');
            if(!isdigit(s[i]) && !isspace(s[i]) or i == s.size()-1){
                if(sign == '+') st.push(temp);
                else if(sign == '-') st.push(-temp);
                else{
                    int num = st.top();
                    st.pop();
                    if(sign == '*') num *= temp;
                    else num /= temp;
                    st.push(num);
                }
                temp = 0;
                sign = s[i];
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
   
    cout<<ans<<endl;
}
void comb(vector<int>&v,vector<vector<int>>&ans,int i)
{
    if(i==v.size())
        {
                ans.push_back(v);
                return;
        }
    for(int j=i;j<v.size();j++)
    {
        swap(v[i],v[j]);
        comb(v,ans,i+1);
        swap(v[i],v[j]);
    }    
}
void per()
{
    int n=3;
    int k=3;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
    }
    vector<vector<int>>ans;
    comb(v,ans,0);
    string res="";
    // sort(ans.begin(),ans.end());
    for(int i=0;i<ans[0].size();i++)
    {
        res+=to_string(ans[k][i]);
    }
    cout<<res<<endl;
}
void gas_station()
{
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    int totgas=0,totcost=0,sum=0,start=1;
    for(int i=0;i<gas.size();i++)
    {
        totgas+=gas[i];
        totcost+=cost[i];
        sum=sum+gas[i]-cost[i];
        if(sum<0)
        {
            sum=0;
            start=i+1;
        }
    }
    cout<<start<<endl;
}
void find(vector<vector<int>>&v,int i,int j)
{
    if(i>v.size()-1 or j>v.size()-1 or i<0 or j<0 or v[i][j]!=1)
        return;

    v[i][j]=9;
    find(v,i+1,j);
    find(v,i,j+1);
    find(v,i-1,j);
    find(v,i,j-1);
    
}
void isconnected()
{
    vector<vector<int>>v={{1,0,0},{0,1,0},{0,0,1}};
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]==1)
            {
               find(v,i,j);
                count++;
               
            }
        }
    }
    for(auto it:v)
    {
        for(auto it1:it)
            cout<<it1<<" ";
        cout<<endl;
    }
    cout<<count<<endl;
}
int hist(vector<int>&v)
{
    vector<int>left(v.size(),0);
    vector<int>right(v.size(),0);
    stack<int>s;
    for(int i=0;i<v.size();i++)
    {
        while(!s.empty() and left[s.top()>=v[i]])
        {
            s.pop();
        }
        if(s.empty())
            left[i]=i;
            else
            left[i]=s.top()+1;
        s.push(i);
    }
    while(!s.empty())
    {
        s.pop();
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        while(!s.empty() and right[s.top()>=v[i]])
        {
            s.pop();
        }
        if(s.empty())
            right[i]=i;
            else
            right[i]=s.top()+1;
        s.push(i);
    }
    int max_area=0;
    for(int i=0;i<v.size();i++)
    {
        
        max_area=max(max_area,(right[i]-left[i])*v[i]);
    }
    return max_area;

}
void largest_rectangle_area()
{
    vector<vector<int>>v={
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
    int max_area=0;
    // vector<int>varow(v.size(),0);
    int curmax=hist(v[0]);
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            v[i][j] += v[i - 1][j];
        }
        max_area=max(max_area,hist(v[i]));
    }
    cout<<max_area<<endl;
    


}
    string bestHand(vector<int>& ranks, vector<char>& suits) {
    map<char,int>m;
    for(auto it:suits)
    {
        m[it]++;
    }
    for(auto it:m)
    {
        if(it.second>=5)
            return "Flush";
    }
    vector<int>rank(14,0);
    int maxi=0;
    for(auto it:ranks)
    {
        m[it]++;
        if(m[it]>=maxi)
        {
            maxi=max(maxi,m[it]);
        }
    }
    if(maxi>=3)
        return "Three of a Kind";
    else if(maxi==2)
        return "Pair";
    
    else
        return "High Card";
    }
    


void max_zero()
{
    vector<int>v={0,1,0,0,1,0,0,0};
    int cnt=0;
    int n=v.size();
    
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            int zero=0;
        while(v[i]==0)
        {
            zero++;
            i++;    
        }
        cnt=cnt+(zero*(zero+1))/2;
        }
        }
    cout<<cnt<<endl;
}
int i=0;
void find_comb(vector<int>&v,vector<vector<int>>&ans,int target,int index,vector<int>&path)
{
    if(index==v.size())
    {
        if(target==0)
        {
            ans.push_back(path);
            return ;
        }
    }
   
    if(v[index]<=target)
    {
        path.push_back(v[index]);
        find_comb(v,ans,target-v[index],index,path);
        path.pop_back();
    }
    
    find_comb(v,ans,target,index+1,path);
}
  void combo(int i,vector<vector<int>> &res,vector<int>&ds,vector<int>& cand, int target)
    {
        if(i==cand.size()){
            if(target==0)
                res.push_back(ds);
                return;
        }
        if(cand[i]<=target)
        {
            ds.push_back(cand[i]);
            combo(i,res,ds,cand,target-cand[i]);
            ds.pop_back();
        }
        combo(i+1,res,ds,cand,target);
}
void comb_sum()
{
    vector<int>v={2,3,6,7};
    int target=7;
    vector<vector<int>>ans;
    vector<int>path;
    find_comb(v,ans,target,0,path);
 
}
int main()
{
    comb_sum();
    // vector<int>v={6, 2, 5, 4, 5, 1, 6};
    // vector<int>ranks={10,10,2,12,9};
    // vector<char>suits={'a','a','a','a','a'};
    // cout<<bestHand(ranks,suits);
    // max_zero();
    //  largest_rectangle_area();
    // isconnected();
    // gas_station();
    // per();
    // basic_cal();
    // job_sq();
    // insert_interval();
    // alien_language();
    // prime();
    // search2();
    // minwindowsub();
    // sum3close();
    // partsum();
    // coin_change();
    // formlarge();
    // next_perm();
    // rotten();
    // del();
    // longest_pal();
    // search();
    // string s="aabcb";
    // // abacb,abcab
    // pal(s);
    // task();
    // sum3();
    // nummy(0,0,3);
    // set<int>s;
    // for(auto it:v)
    // {
    //     s.insert(it);
    // }
    // cout<<v.size()<<" "<<s.size();
    //  expressive();
    // add();
    // mult();
}