#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 10000
struct edge {
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e; // store all connected vertices and cost
vector <edge> ed; // store shortest path
vector <int> store;

int par[maxn];
int Rank[maxn];

int find_representative(int r)
{
    return (par[r] == r) ? r: par[r] = find_representative(par[r]);
}
int mst(int n)
{
    sort(e.begin(), e.end());
    int cnt = 0, s = 0;
    for(int i = 1; i <= n; i++)    par[i] = i, Rank[i] = 0;
    for(int i = 0; i < (int)e.size(); i++) {
        int u = find_representative(e[i].u);
        int v = find_representative(e[i].v);
        if(u != v) {
            edge get;
            get.u = u, get.v = v, get.w = e[i].w;

            ed.push_back(get);
            if(Rank[u] > Rank[v])
                par[v] = u;
            else
                par[u] = v;
            if(Rank[u] == Rank[v])
                Rank[v]++;
            cnt++;
            s += e[i].w;
            if(cnt == n-1)    break;
        }
    }
    return s;
}
int k = 0;
void mst_2(int n, int node1, int node2)
{
    //sort(e.begin(), e.end());
    int cnt = 0, s = 0;
    for(int i = 1; i <= n; i++)    par[i] = i, Rank[i] = 0;
    for(int i = 0; i < (int)e.size(); i++) {
        int u = find_representative(e[i].u);
        int v = find_representative(e[i].v);
        if(u != v) {
            edge get;
            get.u = u, get.v = v, get.w = e[i].w;
            if(get.u == node1 && get.v == node2)
                continue;
            if(Rank[u] > Rank[v])
                par[v] = u;
            else
                par[u] = v;
            if(Rank[u] == Rank[v])
                Rank[v]++;
            cnt++;
            s += e[i].w;
            //if(cnt == n-1)    break;
        }
    }
    k++;
    //cout << s << endl;
    store.push_back(s);
}
int main()
{
    int N, E;
    cin >> N >> E;

    for(int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edge get;
        get.u = u, get.v = v, get.w = w;
        e.push_back(get);
    }
    cout << "Minimum cost: " << mst(N) << endl;
    cout << "Minimum path for given tree: " << endl;
    cout << "Node  Node  Cost" << endl;
    for(int i = 0; i < (int)ed.size(); i++)
        cout << ed[i].u << "-------" << ed[i].v << "------" << ed[i].w << endl;

    for(int i = 0; i < (int)ed.size(); i++) {
        mst_2(N, ed[i].u, ed[i].v);
    }
    sort(store.begin(), store.end());
    cout << "Second MST: " << store[0] << endl;
    return 0;
}
