#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

#define maximum 1000000

vector <int> edges[maximum];
vector <string> color(120, "white");

bool bfs(int source)
{
	queue <int> q;
	q.push(source);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		int sz = edges[cur].size();
		for(int i = 0; i < sz; i++) {
			if(color[edges[cur][i]] == "white") {
				if(color[cur] == "red") 
					color[edges[cur][i]] = "blue";
				else 
					color[edges[cur][i]] == "red";
				q.push(edges[cur][i]);
			}
			if(color[edges[cur][i]] == color[cur])
				return false; 
		}
	}
	return true;
}
int main()
{
	int n, e, u, v;
	cin >> n >> e;
	for(int i = 1; i <= e; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	color[1] = "red";
	bool res = bfs(1);
	if(res)
		cout << "Bicolorable" << endl;
	else 
		cout << "Not bicolorable" << endl;
	return 0;
}

