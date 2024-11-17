#include<iostream>
using namespace std;

void inserionSort(int arr[],int n){
    for(int i=0 ; i<=n-1 ; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    inserionSort(arr,n);
    for(int i=0 ; i<n ; i++){
        cout<<"The sorted array is : "<<arr[i]<<endl;
    }
    return 0;
}