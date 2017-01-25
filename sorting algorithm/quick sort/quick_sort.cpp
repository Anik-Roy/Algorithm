#include <iostream>
#include <stdbool.h>
using namespace std;

int partition(int ara[], int left, int right)
{
    int pivot, i, j, temp;
    pivot = ara[right];
    i = left - 1;
    for(j = left; j <= right-1; j++) {
        if(ara[j] <= pivot) {
            i++;
            temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
    }
    temp = ara[i+1];
    ara[i+1] = ara[right];
    ara[right] = temp;
    return i+1;
}

int quick_sort(int ara[], int left, int right)
{
  int q;
  if(left < right) {
      q = partition(ara, left, right);
      quick_sort(ara, left, q-1);
      quick_sort(ara, q+1, right);
  }
  return 0;
}

int main()
{
    int n, ara[100];
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter array's element: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    int left = 0, right = n-1;
    quick_sort(ara, left, right);
    for(int i = 0; i < n; i++) {
        cout << ara[i] << endl;
    }
    return 0;
}
