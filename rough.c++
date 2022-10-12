#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void snow()
{
    int a=5,b=6;
    int g=gcd(a,b);
    int ans=(5/gcd)+(6/gcd);
    

}
int main()
{
    snow();
}