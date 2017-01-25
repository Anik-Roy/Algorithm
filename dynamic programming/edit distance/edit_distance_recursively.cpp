#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
   return min(min(x, y), z);
}

int edit_dis(string s1, string s2, int m, int n)
{
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    if(s1[m-1] == s2[n-1])
        return edit_dis(s1, s2, m-1, n-1);
    return 1 + min ( edit_dis(s1, s2, m, n-1),    // Insert
                     edit_dis(s1,  s2, m-1, n),   // Remove
                     edit_dis(s1,  s2, m-1, n-1) // Replace
                   );
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int res = edit_dis(s1, s2, s1.length(), s2.length());
    cout << res << endl;
    return 0;
}
