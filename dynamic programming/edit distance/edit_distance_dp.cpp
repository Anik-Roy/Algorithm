#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
int edit_dis(string s1, string s2, int m, int n)
{
    int dp[m+10][n+10];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            // if first string is empty, only option is to insert all characters of second string
            if(i == 0)
                dp[i][j] = j; // Min. operations = j;
            // if second string is empty, only option is to remove all characters of first string
            else if(j == 0)
                dp[i][j] = i;
            // if last characters are same, ignore last char
            // and recur from remaining
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            // if last characters are same, consider all possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]); // insert, remove, replace

        }
    }
    return dp[m][n];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int res = edit_dis(s1, s2, s1.length(), s2.length());
    cout << res << endl;
}
