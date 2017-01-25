#include<iostream>
using namespace std;

int cache[100];

int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(cache[n] != -1)
        return cache[n];

    int ans = fib(n - 1) + fib(n - 2);
    cache[n] = ans;
    return ans;
}

int main()
{

    int i,n;
    cout<<"Enter a number:"<<endl;
    cin>>n;

    for(i = 0; i <= 100; ++i)
        cache[i] = -1;

    cout<<fib(n)<<endl;

    return 0;
}
