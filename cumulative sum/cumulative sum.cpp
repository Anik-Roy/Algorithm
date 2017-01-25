#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ara[] = {0, 10, 12, 13, -45, 60, 70, 80, 100}; // assume array element are store from index 1.

    int sum[10] = {0};

    for(int i = 1; i < 9; i++)
        sum[i] = sum[i-1]+ara[i];

    int a, b;
    printf("Enter a & b(a<=b): \n");
    while(scanf("%d %d", &a, &b) == 2) {
        cout << sum[b]-sum[a-1] << endl;
    }
    return 0;
}
