#include <iostream>
using namespace std;

int Merge(int ara[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int c[100];
    while(i <= mid && j <= high) {
        if(ara[i] < ara[j]) {
            c[k++] = ara[i++];
        }
        else {
            c[k++] = ara[j++];
        }
    }
    while(i <= mid)
        c[k++] = ara[i++];
    while(j <= high)
        c[k++] = ara[j++];
    for(int p = low; p <= high; p++)
        ara[p] = c[p];
    return 0;
}

int MergeSort(int ara[], int low, int high)
{
    int mid;
    if(low < high) {
        /// Divide ara into subarray
        mid = (low + high) / 2;
        /// Sort the subarray
        MergeSort(ara, low, mid);
        MergeSort(ara, mid+1, high);
        /// Merge the distinct subarrays
        Merge(ara, low, mid, high);
    }
    return 0;
}

int main()
{
    int n, ara[100];
    cout << "Enter number of elements in array: ";
    cin >> n;
    for(int i = 0; i < n; i++)      cin >> ara[i];
    int low = 0, high = n-1;
    MergeSort(ara, low, high);
    for(int i = 0; i < n; i++)
        cout << ara[i] << endl;
    return 0;
}
