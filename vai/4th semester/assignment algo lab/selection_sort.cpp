#include<iostream>
using namespace std;

void selectSort(int arr[], int n)
{
    int pos_min,temp;

    for (int i=0; i < n-1; i++)
    {
        pos_min = i;

        for (int j=i+1; j < n; j++)
        {

            if (arr[j] < arr[pos_min])
                pos_min=j;
        }

        if (pos_min != i)
        {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}


int main()
{
    int arr[100],i,n;
    cout<<"Enter The number of Element:"<<endl;
    cin>>n;
    cout<<"\nEnter Elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    selectSort(arr,n);
    cout<<"After Sorting"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
