/*
    Insert N & E:
    5 3
    Please insert a & b:
    0 2
    1 2
    1 2
    Insert Start & End value:
    0 3
*/
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int bfs(int, int);
int edges[100][1000];
int N, E;
int a, b;
int main()
{
    cout<<"Insert N & E: "<<endl;
    cin>>N>>E;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        edges[i][j] = -1;

    cout<<"Please insert a & b: "<<endl;
    for(int i=0; i<E; i++)
    {
        cin>>a>> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    int start, end;
    cout<<"Insert Start & End value: "<<endl;
    cin>>start>>end;
    int x=bfs(start,end);
    if(x==1)
    {
        cout<<"It is possible to visit"<<endl;
    }
    else
        cout<<"It is not possible to visit"<<endl;
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
        int cur = q.front();
        q.pop();
        if(visited[cur] == 1)
            continue;
        visited[cur] = 1;
        for(int i=0; i<N; i++)
            if(edges[cur][i] == 1 && visited[i] == 0)
                q.push(i);
    }
    return visited[end];
}
