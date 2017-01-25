#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define maximum 10000
vector <int> edges[maximum];
vector <int> costs[maximum];
int indegree[maximum] = {0};
int connected[maximum] = {0};

int main()
{
    int N, E;
    scanf("%d %d", &N, &E);
    for(int i = 0; i < E; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        edges[x].push_back(y);
        costs[x].push_back(c);
        indegree[y] += 1;
        if(x == y)
            connected[x] += 1;
        else {
            connected[x] += 1;
            connected[y] += 1;
        }
    }

    for(int i = 1; i <= N; i++) {
        int sz = edges[i].size();
        printf("Total connected node with %d is %d\n", i, connected[i]);
        printf("Total indegree: %d\n", indegree[i]);
        printf("Total outdegree: %d\n", sz);
        printf("Edges and cost from %d are:\n", i);
        for(int j = 0; j < sz; j++) {
            printf("%d %d\n", edges[i][j], costs[i][j]);
        }
    }
    return 0;
}
