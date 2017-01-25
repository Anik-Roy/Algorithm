#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
int ara[MAX];
int tree[MAX*3];

void init(int node, int b, int e)
{
    if(b == e) {
        tree[node] = ara[b];
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    if(tree[left] < tree[right]) {
        tree[node] = tree[left];
    }
    else
        tree[node] = tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(b > j || e < i)
        return 1e9;
    if(b >= i && e <= j)
        return tree[node];
    int left = 2*node;
    int right = 2*node+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    if(p1 < p2)
        return p1;
    else
        return p2;
}

int main()
{
    int t, n, q, cs;
    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++) {
        memset(ara, 0, sizeof(ara));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &ara[i]);
        init(1, 1, n);
        printf("Case %d:\n", cs);
        for(int i = 1; i <= q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int res = query(1, 1, n, u, v);
            printf("%d\n", res);
        }
    }
    return 0;
}
