#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define maximum 10000
vector <int> edges[maximum];
vector <int> cost[maximum]; // parallel vector to store cost

int main()
{
    int N, E;
    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        if(x == y)
            edges[x].push_back(y);
        else {
            edges[x].push_back(y);
            edges[y].push_back(x);
            cost[x].push_back(1);
            cost[y].push_back(1);
        }
    }
    for(int i = 1; i <= N; i++) {
        int sz = edges[i].size();
        printf("The connected vertices from %d are: ", i);
        for(int j = 0; j < sz; j++) {
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
    return 0;
}
