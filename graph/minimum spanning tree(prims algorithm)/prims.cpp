#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair <int, int> PII;

vector <PII> edges[100];
int n, e, s;
int cost[100];
bool taken[100];

struct node {
    int u, cost;
    node() {} // default constructor
    node(int _u, int _cost) {
        u = _u;
        cost = _cost;
    }
    bool operator < (const node& p) const {
        return cost > p.cost;
    }

};


//bool operator<(node A, node B)
//{
//    // priority queue is a max heap.
//    // so we need to compare the cost
//    // in reverse order to get minimum
//    // cost vertex at top.
//    return A.cost > B.cost;
//}


priority_queue <node> pq;

int prim()
{
    for(int i = 0; i <= n; i++)
        cost[i] = INF;
    cost[s] = 0;
    pq.push(node(s, 0));
    int ans = 0;
    while(!pq.empty()) {
        node x = pq.top();
        pq.pop();

        if(taken[x.u]) {
            // already visited
            continue;
        }
        taken[x.u] = true;
        ans += x.cost;
        for(int i = 0; i < edges[x.u].size(); i++) {
            if(taken[edges[x.u][i].first])  continue;
            if(edges[x.u][i].second < cost[edges[x.u][i].first]) {
                // cost of current edge to v.first
                // is less than whatever we saw
                // so far
                pq.push(node(edges[x.u][i].first, edges[x.u][i].second));
                cost[edges[x.u][i].first] = edges[x.u][i].second;
            }
        }
    }
    return ans;
}

int main()
{
    cout << "Enter node and edges number: ";
    cin >> n >> e;
    cout << "Enter all connected nodes: " << endl;
    for(int i = 1; i <= e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back(make_pair(v, c));
        edges[v].push_back(make_pair(u, c));
    }
    cout << "Enter source node from which you want to start prim from: ";
    cin >> s;
    int ans = prim();
    cout << "Cost of MST: " << ans << endl;
    return 0;
}
