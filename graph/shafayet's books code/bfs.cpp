#include <bits/stdc++.h>
using namespace std;

#define maxi 10000
#define inf 1000000

vector <int> store[maxi];
vector <int> par(10000);
vector <int> path;

void bfs_path(int source, int destination)
{
    if(source == destination) {
        path.push_back(source);
    }
    else {
        path.push_back(destination);
        bfs_path(source, par[destination]);
    }
}
int bfs(int source, int destination)
{
    queue <int> q;
    int level[maxi];
    for(int i = 0; i < maxi; i++)   level[i] = inf;
    q.push(source);
    level[source] = 0;
    par[source] = source;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < store[cur].size(); i++) {
            if(level[store[cur][i]] == inf){
                level[store[cur][i]] = level[cur]+1;
                par[store[cur][i]] = cur;
                q.push(store[cur][i]);
            }
        }
    }
    return level[destination];
}
int main()
{
    int n, e;
    cin >> n >> e;
    for(int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        store[u].push_back(v);
        store[v].push_back(u);
    }
    int source, destination;
    cin >> source >> destination;
    int res = bfs(source, destination);
    bfs_path(source, destination);
    cout << res << endl;

    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    return 0;
}
