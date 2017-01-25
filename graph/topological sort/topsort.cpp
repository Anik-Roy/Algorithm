#include <bits/stdc++.h>
using namespace std;

#define maxi 10000

vector <int> edges[maxi];
int ind[maxi];

vector <int> top_sort(int n)
{
    queue <int> q;

    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0)
            q.push(i);
    }
    vector <int> ts;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ts.push_back(cur);

        for(int i = 0; i < edges[cur].size(); i++) {
            ind[edges[cur][i]]--;
            if(ind[edges[cur][i]] == 0)
                q.push(edges[cur][i]);
        }
    }
    return ts;
}
int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        edges[u].push_back(v);
        ind[v]++;
    }
    vector <int> top_s = top_sort(n);

    cout << top_s[0];
    for(int i = 1; i < top_s.size(); i++)
        cout << " " << top_s[i];
    cout << endl;
    return 0;
}
