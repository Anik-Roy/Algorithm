#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
int ara[MAX];

struct info {
    long long prop = 0, sum = 0;
} tree[MAX*3];

void init(int node, int b, int e)
{
    if(b == e) {
        tree[node].sum = ara[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1)+1;
    int mid = (b+e) >> 1;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, int value)
{
    if(b > j || e < i)
        return;
    if(b >= i && e <= j) {
        tree[node].sum += (e-b+1)*value;
        tree[node].prop += value;
        return;
    }

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;

    update(left, b, mid, i, j, value);
    update(right, mid+1, e, i, j, value);

    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry)
{
    if(b > j || e < i)
        return 0;
    if(b >= i && e <= j) {
        return tree[node].sum + carry*(e-b+1);
    }

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;

    int p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    int p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> ara[i];
    init(1, 1, n);
    int res = query(1, 1, n, 1, 3, 0);
    cout << res << endl;
    update(1, 1, n, 1, 3, 4);
    res = query(1, 1, n, 1, 3, 0);
    cout << res << endl;
    return 0;
}
