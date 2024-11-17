#include<iostream>
using namespace std;

int largestElement(int arr[],int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<"Largest Element : "<<largest<<endl;
    return largest;
}

int SecondlargestElement(int arr[],int n){
    int largest = arr[0];
    int S_largest = -1;
    for(int i=1 ; i<n ; i++){
        if(arr[i]>largest){
            S_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>S_largest){
            S_largest = arr[i];
        }
    }
    cout<<"Second Largest Element : "<<S_largest<<endl;
    return S_largest;
}

int IsSorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            cout<<"The array is not sorted"<<endl;
            return false;
        }
    }
    cout<<"The array is sorted"<<endl;
    return true;
}

int DuplicateElems(int arr[],int n){
    int i = 0;
    for(int j=1 ; j<n ; j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    cout<<"The original array without duplicate elements :";
    for(int i=0 ; i<arr[i] ; i++){
        cout<<" "<<arr[i];
    }
    return i+1;
}

int main(){
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    largestElement(arr,n);
    SecondlargestElement(arr,n);
    IsSorted(arr,n);
    DuplicateElems(arr,n);
    return 0;
}