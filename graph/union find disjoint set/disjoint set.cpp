#include <bits/stdc++.h>
using namespace std;

#define maximum 10000

int par[maximum+10];
int Rank[maximum+10];
int Size[maximum+10];
int num_of_sets;

void make_set(int n)
{
    for(int i = 1; i <= n; i++)
        par[i] = i, Rank[i] = 0, Size[i] = 1;
}

int find_representative(int n)
{
    if(n == par[n])
        return n;
    return par[n] = find_representative(par[n]);
}

void make_union(int u, int v)
{
    num_of_sets--;
    if(Rank[u] > Rank[v])
        par[v] = u, Size[u] += Size[v];
    else
        par[u] = v, Size[v] += Size[u];
    if(Rank[u] == Rank[v])
        Rank[v]++;
}
int main()
{
    int n, e;
    cout << "Enter node and pair of friend numbers: " << endl;
    cin >> n >> e;
    num_of_sets = n;
    make_set(n);

    cout << "Enter all pair of friends: " << endl;

    for(int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;

        int u = find_representative(a);
        int v = find_representative(b);

        if(u != v) {
            make_union(u, v);
        }
    }
    cout << "Total number of set: " << num_of_sets << endl;
    for(int i = 1; i <= n; i++) { // This is to find the representative of a node
        cout << "Node: " <<  i << " Representative: " << find_representative(i) << endl;
        if(i == par[i])
            cout << "Set: " << i << " Size: " << Size[i] << endl;
    }
    return 0;
}
