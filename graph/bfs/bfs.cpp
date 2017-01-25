/*
    We numbering the vertices from 0;
*/

#include <iostream>
#include <queue>
using namespace std;

int v, e;
int edges[100][1000];
int bfs(int start, int end1)
{
    queue <int> q;
    int visited[v+10];
    for(int i = 0; i < v+10; i++) {
        visited[i] = 0;
    }
    q.push(start);
    int cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(visited[cur] == 1)
            continue;
        visited[cur] = 1;
        for(int i = 0; i <= v; i++) {
            if(edges[cur][i] == 1 && visited[i] == 0) {
                q.push(i);
            }
        }
    }
    return visited[end1];
}
int main()
{
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    for(int i = 0; i <= e; i++) {
        for(int j = 0; j <= e; j++) {
            edges[i][j] = 0;
        }
    }
    int a, b;
    cout << "Enter connected vertices: " << endl;
    for(int i = 1; i <= e; i++) {
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    for(int i = 0; i <= v; i++) {
        for(int j = 0; j <= v; j++) {
            cout << edges[i][j] << ' ';
        }
        cout << endl;
    }

    int start, end1;
    cout << "Enter start & end nodes value you want to traverse: ";
    cin >> start >> end1;

    int x = bfs(start, end1);
    if(x == 1)  cout << "You can traverse those nodes" << endl;
    else    cout << "You can not traverse those nodes" << endl;

    return 0;
}
