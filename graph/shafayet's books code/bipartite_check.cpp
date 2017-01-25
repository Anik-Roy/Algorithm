#include <bits/stdc++.h>
using namespace std;

#define maxi 10000
#define white 0
#define red 1
#define black 2

vector <int> store[maxi];

bool bipartite_check()
{
    queue <int> q;
    q.push(1);
    int color[maxi] = {white};

    color[1] = red;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < store[cur].size(); i++) {
            if(color[store[cur][i]] == white) {
                if(color[cur] == red)
                    color[store[cur][i]] = black;
                else
                    color[store[cur][i]] = red;
                q.push(store[cur][i]);
            }
            else if(color[store[cur][i]] == color[cur])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        store[u].push_back(v);
        store[v].push_back(u);
    }

    bool ans = bipartite_check();
    if(ans == true)
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
    return 0;
}
