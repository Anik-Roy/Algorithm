/* 5 3
   0 2
   1 2
   1 2
   0 3
   Monjur Back Again BFS
*/
#include<bits/stdc++.h>
using namespace std;
int bfs(int,int);
int edges[100][1000];
int N,E;
int a,b;
int main()
{
    scanf("%d%d",&N,&E);
        //int a,b;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        edges[i][j]=-1;
    for(int i=0; i<E; i++)
    {
        scanf("%d%d",&a,&b);
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int start,end;
    scanf("%d%d",&start,&end);
    int x=bfs(start,end);
    if(x==1)
    {
        printf("It is possible to visit");
    }
    else
        printf("It is not possible");
}
int bfs(int start,int end)
{
    int visited[100];
    for(int i=a; i<100; i++)
        visited[i]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(visited[cur]==1)
            continue;
        visited[cur]=1;
        for(int i=0; i<N; i++)
            if(edges[cur][i]==1 && visited[i]==0)
                q.push(i);
    }
    return visited[end];
}


