#include<iostream>
using namespace std;
string s1,s2;
int cache[55][55];
int LCS(int m , int n)
{
    if(m==0||n==0) return 0;
    if(cache[m][n]!= -1) return cache [m][n];
    int rv = 0;
    if(s1[m-1]==s2[n-1])
        rv=LCS(m-1,n-1)+1;
    else
    {
        rv = max(rv,LCS(m-1,n));
        rv = max(rv,LCS(m,n-1));
    }
    cache [m][n]= rv;
    return rv;
}

int main()
{
    for(int i=0; i<55; i++)
        for(int j=0; j<55; j++)
            cache [i][j]=-1;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<LCS(m,n)<<endl;
}

