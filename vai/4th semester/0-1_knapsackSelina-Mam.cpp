#include<iostream>
#include <cstdlib>
#include<cstdio>
#include <cstring>
using namespace std;

int n,CAP,dp[100][100], weight[100],cost[100];

int func(int i, int w)
{
    if(i == n+1)
    {
        return 0;
    }
    if (dp[i][w] != -1)
        return dp[i][w];

    int profit1 = 0, profit2 = 0;
    if(w + weight[i] <= CAP)
    {
        profit1 = cost[i]+func(i+1, w+weight[i]);
    }
    profit2 = func(i+1, w);
    dp[i][w] = max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout<<"Enter Size & Capacity: "<<endl;
    cin>>n>>CAP;
    cout<<"Enter Weight & Cost: "<<endl;
    for(int i =1; i<=n;i++)
    {
        cin>>weight[i]>>cost[i];
    }
    cout<<"(0, 0)Knapsack: "<<func(0,0)<<endl;
    cout<<"(0, 1)Knapsack: "<<func(0,1)<<endl;
    //cout<<"Weight:"<<weight<<endl;

    return 0;
}
