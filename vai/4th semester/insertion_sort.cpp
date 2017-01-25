#include<iostream>
using namespace std;
int main()
{
	int arr[20], n, temp, i, j;
	cout<<"Enter The number of Element:"<<endl;
	cin>>n;
	cout<<"\nEnter Elements:"<<endl;
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	for(i=1; i<n; i++)
	{
		temp = arr[i];
		j = i-1;
		while(temp<arr[j] && j>=0)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
	cout<<"After Sorting"<<endl;
	for(i=0; i<n; i++)
		cout<<arr[i]<<endl;

}
