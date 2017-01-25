#include <bits/stdc++.h>
using namespace std;

void init(int node, int b, int e, int ara[], int tree[])
{
    if(b == e) {
        tree[node] = ara[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left, b, mid, ara, tree);
    init(right, mid+1, e, ara, tree);

    tree[node] = tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j, int tree[])
{
    if(i > e || j < b) // outside of current node
        return 0;
    else if(b >= i && e <= j)
        return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j, tree);
    int p2 = query(right, mid+1, e, i, j, tree);

    return p1+p2;
}

void update(int node, int b, int e, int i, int new_value, int tree[])
{
    if(b > i || i > e) // out of current node
        return;
    if(b >= i && e <= i) {
        tree[node] = new_value;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, new_value, tree);
    update(right, mid+1, e, i, new_value, tree);
    tree[node] = tree[left]+tree[right];
}
int main()
{
    int n;
    cin >> n;

    int ara[n+10];
    int tree[n*3+10];

    for(int i = 1; i <= n; i++)
        cin >> ara[i];
    init(1, 1, n, ara, tree);

    int res = query(1, 1, n, 3, 7, tree);
    cout << res << endl;
    update(1, 1, n, 3, 10, tree);
    res = query(1, 1, n, 3, 7, tree);
    cout << res << endl;
    return 0;
}
