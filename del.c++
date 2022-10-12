#include<bits/stdc++.h>
using namespace std;
// void sub(vector<int>v)
// {
//     int pos=0;
//     int i=0,j=0; 
//     int lastneg=0;
//     int neg=0;
//     for(int i=0;i<v.size();i++)
//     {
//         if(v[i]==0)
//         {
//             pos=0;
//             neg=0;
//             lastneg=-1;
//             j=i+1;
//         }
//         else if(v[i]>0)
//         {
//             pos++;
//         }
//         else{
//             neg++;
//             if(lastneg==-1 and neg%2==1)
//             {
//                 lastneg=i+1;    
//             }
//             if(neg%2==0)
//             {
//                 ans=max(j-i+1,ans);
//             }
//             else if(lastneg!=-1)
//             {
//                 ans=max(ans,i-lastneg+1);
//             }
//         }
//     }
// }
void ug(int n)
{
    int i=0,j=0,k=0;
    int ans=0;
    for(int it=0;it<n;it++)
    {
        int num=min(2*i,3*j,5*k);
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
}
int main()
{
    vector<int>v={1,-2,-3,4};
    ug(10);
    // sub(v);
}