#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}
int lcs(string s1, string s2, int m, int n)
{
    int table[n+1][m+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) {
                table[i][j] = 0;
            }
            else if(s2[i-1] == s1[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else {
                table[i][j] = max(table[i][j-1], table[i-1][j]);
            }
        }
    }
    return table[n][m];
}
int main()
{
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        int n = s1.size();
        int m = s2.size();
        cout << lcs(s1, s2, n, m) << endl;
    }
    return 0;
}
