#include<iostream>
using namespace std;
string s1,s2;
int dp[6][6];
int lcs(int m,int n)
{
    for(int i=0; i<=m; i++) dp[i][0]=0;
    for(int j=0; j<=n; j++) dp[0][j]=0;

    for(int i=1; i<=m; i++)
    {
        for(int  j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[m][n];
}
int main()
{
    cin>>s1>>s2;
    int a=s1.size();
    int b=s2.size();
    int ans=lcs(a,b);
    cout<<ans<<endl;
}

