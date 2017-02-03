#include <bits/stdc++.h>
using namespace std;

#define MAX 1000010
int ara[MAX];

struct info {
    long long prop, sum;
} tree[MAX*3];

//void init(int node, int b, int e)
//{
//    if(b == e) {
//        tree[node].sum = ara[b];
//        return;
//    }
//    int left = node << 1;
//    int right = (node << 1)+1;
//    int mid = (b+e) >> 1;
//
//    init(left, b, mid);
//    init(right, mid+1, e);
//
//    tree[node].sum = tree[left].sum + tree[right].sum;
//}

void update(int node, int b, int e, int i, int j, long long value)
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

long long query(int node, int b, int e, int i, int j, long long carry)
{
    if(b > j || e < i)
        return 0;
    if(b >= i && e <= j) {
        return tree[node].sum + carry*(e-b+1);
    }

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;

    long long p1 = query(left, b, mid, i, j, carry+tree[node].prop);
    long long p2 = query(right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    int t, n, q, choice;
    cin >> t;
    //cout << tree[5].sum << " " << tree[5].prop << endl;
    while(t--) {
        //memset(ara, 0, sizeof(ara));
        memset(tree, 0, sizeof(tree));

        cin >> n >> q;
        //for(int i = 1; i <= n; i++)
          //  ara[i] = 0;
        //init(1, 1, n);
        for(int i = 1; i <= q; i++) {
            cin >> choice;
            if(choice == 0) {
                int u, v, value;
                cin >> u >> v >> value;
                update(1, 1, n, u, v, value);
            }
            else {
                int u, v;
                cin >> u >> v;
                long long res = query(1, 1, n, u, v, 0);
                cout << res << endl;
            }
        }
    }
    return 0;
}

