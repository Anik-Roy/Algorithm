    #include <bits/stdc++.h>
    //#define N 1000
    using namespace std;
    int LIS( char *a, int N)
    {
        int dp[1001];
        for(int i = 0; i < N; i++)
        {
            dp[i] = 1;
            ///cout<<1<<endl;
        }
        for(int i = 0; i < N; i++)
        {
            ///cout<<1<<endl;
            for( int j = 0; j <i; j++)
            {
                ///cout<<2<<endl;
                if(a[i] < a[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    ///cout<<3<<endl;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < N; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
    int main ()
    {

        char arr[1000];
        int len;
        cout << "Please insert the length of array : ";
        cin >> len;
        cout << "\nPlease insert " << len << " character : ";
        for( int i = 0; i < len; i++)
            cin >> arr[i];
        cout << "\nThe Maximum decreasing is : " << LIS(arr,len)<< endl;
        return 0;
    }

