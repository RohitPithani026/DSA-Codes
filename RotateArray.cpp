#include<iostream>
using namespace std;

// //Rotate array from Left to Right by one place 

int rotateArray(int arr[],int n){
    int temp = arr[0];
    for(int i=1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    cout<<"The array from left to right :";
    for(int i=0 ; i<n ; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return temp;
}

// //Rotate array from Right to left by one place

int rotateArray(int arr[],int n){
    int temp = arr[n-1];
    for(int i=n ; i>=0 ; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
    cout<<"The array from right to left :";
    for(int i=0 ; i<n ; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return temp;
}

// //Rotate Array by K places

int rotateArraybyK(int arr[],int n,int k){
    
    k = k%n-1;
    int temp[k];
    for(int i=0 ; i<k ; i++){
        temp[i] = arr[i];
    }
    for(int i=k ; i<n ; i++){
        arr[i-k] = arr[i];
    }
    for(int i=n-k ; i<n ; i++){
        arr[i] = temp[i-(n-k)];
    }
    
    return temp[k];
}

// //Move all Zeros elements at the end

int moveZeroElems(int arr[],int n){
    int j = -1;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1 ; i<n ; i++){
        if(arr[i]!=0){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    return arr[j];
}

// //Search an element using Linear search

int LinearSearch(int arr[],int num,int n){
    for(int i=0 ; i<n ; i++){
        if(arr[i]==num){
            cout<<"The number is : "<<arr[i]<<endl;
            return i;
            break;
        }
    }
    return -1;
}

//Missing Numbers

int missingNo(int arr[],int n){
    int xor1 = 0, xor2 = 0;
    int a = n-1;
    for(int i=0 ; i<a ; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;
    a = xor1 ^ xor2;
    cout<<"The Missing Number is : "<<a<<endl;
    return xor1 ^ xor2;
}

//Find maximum no. of consecutive number

int findMaxConsecutive(int arr[],int n){
    int max1 = 0;
    int cnt = 0;
    for (int  i = 0; i < n; i++){
        if(arr[i]==1){
            cnt++;
            max1 = max(max1,cnt);
        }
        else{
            cnt=0;
        }
    }
    cout<<"The Consecutive No. is : "<<max1<<endl;
    return max1;
}

//Find the number that appears once

int getSingleElem(int arr[],int n){
    int xorr = 0;
    for(int i=0 ; i<n ; i++){
        xorr = xorr ^ arr[i];
    }
    cout << "The single element is: " << xorr << endl;
    return xorr;
}

//Find the longest subarray with sum 

int longestSubarrayWithSum(int arr[],int n,int k){
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxlen = 0;
    while(right < n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right<n) sum += arr[right];
    }
    cout<<"The longest subarray is : "<<maxlen<<endl;
    return maxlen;
}

int main(){
    int n;
    cout<<"Enter the no. of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    // rotateArray(arr,n);
    // int k;
    // cout<<"Enter the Kth place : ";
    // cin>>k;
    // rotateArraybyK(arr,n,k);
    // for(int i=0 ; i<n ; i++){
    //     cout<<arr[i];
    // }
    // moveZeroElems(arr,n);
    // for(int i=0 ; i<n ; i++){
    //     cout<<arr[i];
    // }
    // int num;
    // cout<<"Enter the number to be searched on array : ";
    // cin>>num;
    // LinearSearch(arr,num,n);
    // missingNo(arr,n);
    // findMaxConsecutive(arr,n);
    // getSingleElem(arr,n);
    int k;
    cout<<"Enter the sum you want to find out : ";
    cin>>k;
    longestSubarrayWithSum(arr,n,k);
    return 0;
}