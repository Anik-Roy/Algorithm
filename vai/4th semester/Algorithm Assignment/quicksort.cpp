#include<iostream>
using namespace std;
int partition(int a[],int st,int en)
{
    int pivot=a[en];
    int i=st-1;
    for(int j=st;j<=en;j++)
    {
        if(a[j]<=pivot)
        {
           i++;
           swap(a[i],a[j]);
        }

    }
    return i;
}
void quick(int a[],int st,int en)
{
    if(en-st+1<=1)return;
    int p=partition(a,st,en);
    quick(a,st,p-1);
    quick(a,p+1,en);
}
int main()
{
    int n,i,arr[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quick(arr,0,n);
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
