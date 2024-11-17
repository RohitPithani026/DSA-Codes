#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for( int i=0 ; i<=n-2 ; i++ ){
        int mini = i;
        for( int j=i ; j<=n-1 ; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    selectionSort(arr,n);
    for(int i = 0 ; i <n ; i++){
        cout<<"The sorted array is : "<<arr[i]<<endl;
    }
    return 0;
}