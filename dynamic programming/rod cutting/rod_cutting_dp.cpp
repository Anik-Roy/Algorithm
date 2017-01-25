#include <iostream>
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b)? a:b;
}

int cut_rod(int price[], int n)
{
    int val[n+1];
    val[0] = 0;
    int i, j;

    for(i = 1; i <= n; i++) {
        int max_val = -10000;
        for(j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + val[i - j - 1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main()
{
    //int ara[] = {1, 5, 8, 9, 10, 17, 17, 20};
    //int size1 = sizeof(ara[0]); // sizeof(ara[0]
    int n;
    printf("Enter rod size: ");
    scanf("%d", &n);
    int ara[n];
    printf("Enter prices of piece rod through 1 to %d\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
    }
    printf("Maximum obtainable value: %d\n", cut_rod(ara, n));
    return 0;
}
