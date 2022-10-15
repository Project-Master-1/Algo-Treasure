#include <bits/stdc++.h> 
using namespace std;

int binarySearch(int arr[], int l, int r, int n)
{
    int mid = (l+r)/2;
    int notfound = -1;
    if(n==arr[mid])
    {
        return mid;
    }
    else if(arr[mid]>n)
    {
        return binarySearch(arr, l, mid-1, n);
    }
    else if (arr[mid]<n)
    {
        return binarySearch(arr, mid+1, r, n);
    }
    else
    {
        return notfound;
    }
}

int main()
{
    int a;
    cout<<"Enter the size of array:"<<endl;
    cin>>a;
    int array[a];
    cout<<"Enter the sorted array:"<<endl;
    for(int i =0;i<a;i++)
    {
        cin>>array[i];
    }
    int t;
    cout<<"Enter the element you want to search in the array: ";
    cin>>t;
    int res = binarySearch(array, 0, a-1, t);
    if(res == -1)
    {
        cout<<"Item not found"<<endl;
    }
    else
    {
        cout<<"item found at position : "<<res+1<<endl;
    }       
    return 0;
}
