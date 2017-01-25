#include <iostream>
using namespace std;
int main()
{
    int a[100],n,i,j,temp;

    cout<<"Size of this array is"<<endl;
    cin>>n;

    cout<<"Enter the elements of the array"<<endl;

    for (i=0; i<n; i++)
        cin>>a[i];

    for (i=0 ; i<( n-1); i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                temp= a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    cout<<"Array after sorting:"<<endl;

    for ( i = 0 ; i < n ; i++ )
        cout<<a[i]<<endl;

    return 0;
}
