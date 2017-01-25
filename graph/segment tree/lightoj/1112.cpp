#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long int ll;

ll ara[MAX];
ll tree[MAX*3];

void init(ll node, ll b, ll e)
{
    if(b == e) {
        tree[node] = ara[b];
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left]+tree[right];
}

void update(ll node, ll b, ll e, ll i, ll new_value, ll id)
{
    if(i < b || i > e)
        return;
    if(b >= i && e <= i) {
        if(id == 1)
            tree[node] = new_value;
        else if(id == 2)
            tree[node] += new_value;
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, new_value, id);
    update(right, mid+1, e, i, new_value, id);
    tree[node] = tree[left]+tree[right];
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(b > j || e < i)
        return 0;
    if(b >= i && e <= j)
        return tree[node];
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}
int main()
{
    ll t, n, q;
    scanf("%lld", &t);

    for(ll cs = 1; cs <= t; cs++) {
        memset(ara, 0, sizeof(ara));
        memset(tree, 0, sizeof(tree));

        scanf("%lld %lld", &n, &q);

        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
        init(1, 1, n);
        printf("Case %lld:\n", cs);

        for(ll i = 1; i <= q; i++) {
            ll type;
            scanf("%lld", &type);
            if(type == 1) {
                ll u;
                scanf("%lld", &u);
                printf("%lld\n", ara[u+1]);
                ara[u+1] = 0;
                update(1, 1, n, u+1, 0, 1);
            }
            if(type == 2) {
                ll u, v;
                scanf("%lld %lld", &u, &v);
                ara[u+1] += v;
                update(1, 1, n, u+1, v, 2);
            }
            if(type == 3) {
                ll u, v;
                scanf("%lld %lld", &u, &v);
                ll res = query(1, 1, n, u+1, v+1);
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}
