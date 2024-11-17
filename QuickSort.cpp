#include<bits/stdc++.h>
using namespace std;
int f(int arr[],int low ,int high);
void qs(int arr[],int low ,int high){
    if(low<high){
        int partition = f(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
    }
}

int f(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) 
            i++;
        while (arr[j] > pivot) 
            j--;
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

int main(){
     int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    int low = 0, high = n - 1; 
    qs(arr, low, high);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}