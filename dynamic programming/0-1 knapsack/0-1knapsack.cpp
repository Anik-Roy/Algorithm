#include <bits/stdc++.h>
using namespace std;

bool comp(const pair <int, int> &a, const pair <int, int> &b)
{
    return a.first <b.first;
}

int sz, W, immediate;
int dp[1010][35];

int knapsack(vector < pair <int, int> > store, int sz, int W)
{
    int pos;
    int i, w;

    if(W > immediate)
        pos = immediate;
    else if(W < immediate)
        return dp[sz][W];
    else
        pos = 0;
    // build table in bottom up manner
    for(i = 0; i <= sz; i++) {
        for(w = pos; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(store[i-1].first <= w)
                dp[i][w] = max((store[i-1].second + dp[i-1][w-store[i-1].first]), dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    if(W > immediate)
        immediate = W;
    return dp[sz][W];
}
int main()
{
    vector < pair <int, int> > store;
    int t, n, price, weight, people;
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        int total = 0;
        store.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> price >> weight;
            store.push_back(make_pair(weight, price));
        }
        sort(store.begin(), store.end(), comp);
        sz = store.size();
        cin >> people;
        for(int i = 1; i <= people; i++) {
            cin >> W;
            if(i == 1)
                immediate = W;
            total += knapsack(store, sz, W);
        }
        cout << total << endl;
    }
    return 0;
}
