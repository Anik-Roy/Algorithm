#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>cost[1000];
int d[1000];
stack<int>q;
int dfs(int n,int dis){
    q.push(n);
    while(!q.empty()){
        int cur=q.top();
        for(int i=0;i<edge[cur].size();i++){
            int v=edge[cur][i];
            if(d[v]>d[cur]+cost[cur][i]){
                d[v]=d[cur]+cost[cur][i];
                dfs(edge[cur][i],dis);
            }
        }
        if(q.empty()!=0) break;
        q.pop();
    }
    return d[dis];
}
int main(){
    ///I always use scanf & printf
    int n,e;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    int start,end;
    while(scanf("%d%d",&start,&end)){
        for(int i=0;i<100;i++) d[i]=1e9;
        d[start]=0;
        cout<<dfs(start,end)<<endl;
    }
}

