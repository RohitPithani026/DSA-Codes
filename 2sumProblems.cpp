#include<bits/stdc++.h>
using namespace std;

// string twoSum(int n, vector<int> &arr, int target){
//     sort(arr.begin(),arr.end());
//     int left = 0;
//     int right = n-1;
//     while(left<right){
//         int sum = arr[left] + arr[right];
//         if(sum == target){
//             return "YES";
//         }
//         else if(sum<target) left++;
//         else right--;
//     }
//     return "NO";
// }

// void sortArray(vector<int>& arr, int n){
//     int low = 0 , mid = 0 , high = n-1;
//     while(mid<=high){
//         if(arr[mid] == 0){
//             swap(arr[low],arr[mid]);
//             low++;
//             mid++;
//         }
//         else if(arr[mid] == 1){
//             mid++;
//         }
//         else{
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//     }
//     cout<<"The sorted array in 0's 1's and 2's is : ";
//     for(int i=0 ; i<n ; i++){
//         cout<<arr[i];
//     }
// }

// int majorityElem(int arr[],int n){
//     int cnt = 0;
//     int el;
//     for(int i=0 ; i<n ; i++){
//         if( cnt == 0 ) {
//             cnt=1;
//             el=arr[i];
//         }
//         else if(arr[i]==el){
//             cnt++;
//         }
//         else {
//             cnt--;
//         }
//     }
//     int cnt1=0;
//     for(int i=0 ; i<n ; i++){
//         if(arr[i]==el) cnt1++;
//     }
//     if(cnt1>arr[n/2]){
//         cout<<"The element is : "<<el<<endl;
//         return el;
//     }
//     return -1;
// }

// long long maxSubarraySum(int arr[],int n){
//     long long maxi = LONG_MIN;
//     long long sum = 0 ;
//     for(int i=0 ; i<n ; i++){
//         sum+=arr[i];
//         if(sum>maxi){
//             maxi=sum;
//         }
//         if(sum<0){
//             sum=0;
//         }
//     }
//     cout<<"The maximum subarray sum is : "<<maxi<<endl;
//     return maxi;
// }

// int maximumProfit(int arr[],int n){
//     int mini = arr[0];
//     int maxProfit = 0;
//     for(int i=0 ; i<n ; i++){
//         int cost = arr[i] - mini;
//         maxProfit = max(maxProfit,cost);
//         mini = min(mini,arr[i]);
//     }
//     cout<<"The Max Profit Gain is : "<<maxProfit<<endl;
//     return maxProfit;
// }

// vector<int> RearrangebySign(vector<int>A){    
//   int n = A.size();
//   vector<int> ans(n,0);
//   int posIndex = 0, negIndex = 1;
//   for(int i = 0;i<n;i++){
//       if(A[i]<0){
//           ans[negIndex] = A[i];
//           negIndex+=2;
//       }
//       else{
//           ans[posIndex] = A[i];
//           posIndex+=2;
//       }
//   }
//   return ans;   
// }
 
// vector<int> nextGreaterPermutation(vector<int> &A) {
//     int n = A.size(); 
//     int ind = -1; 
//     for (int i = n - 2; i >= 0; i--) {
//         if (A[i] < A[i + 1]) {
//             ind = i;
//             break;
//         }
//     }
//     if (ind == -1) {
//         reverse(A.begin(), A.end());
//         return A;
//     }
//     for (int i = n - 1; i > ind; i--) {
//         if (A[i] > A[ind]) {
//             swap(A[i], A[ind]);
//             break;
//         }
//     }
//     reverse(A.begin() + ind + 1, A.end());
//     return A;
// }

// vector<int> superiorElement(int arr[],int n){
//     vector<int> ans;
//     int max = arr[n-1];
//     ans.push_back(arr[n-1]);
//     for(int i=n-2; i>=0 ; i--){
//         if(arr[i]>max){
//             ans.push_back(arr[i]);
//             max=arr[i];
//         }
//     }
//     return ans;
// }

// int longestConsecutiveElem(int arr[],int n){
//     if(n==0) return 0;
//     int longest = 1;
//     unordered_set<int> st;
//     for(int i=0 ; i<n ; i++){
//         st.insert(arr[i]);
//     }
//     for(auto it:st){
//         if(st.find(it-1)==st.end()){
//             int cnt = 1;
//             int x = it;
//             while(st.find(x+1) != st.end()){
//                 x=x+1;
//                 cnt = cnt + 1;
//             }
//             longest = max(longest,cnt);
//         }
//     }
//     cout<<"The longest element is : "<<longest<<endl;
//     return longest;
// }

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix,int n,int m){
//     int col0=1;
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<m ; j++){
//             if(matrix[i][j]==0){
//                 matrix[i][0] = 0;
//                 if(j != 0){
//                 matrix[0][j] = 0;
//             }
//             else col0 = 0;
//             }
            
//         }  
//     }
//     for(int i = 1; i<n ; i++){
//         for(int j=1 ; j<m ; j++){
//             if(matrix[i][j] != 0){
//                 if(matrix[i][0] == 0 || matrix[0][j] == 0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }
//     if(matrix[0][0] == 0){
//         for(int j=0 ; j<m ; j++){
//             matrix[0][j]=0;
//         }
//     }
//     if(col0==0){
//         for(int i=0 ; i<n ; i++){
//             matrix[i][0] = 0;
//         }
//     }
//     return matrix;
// } 

// void rotateMatrix(vector < vector < int >> & matrix) {
//     int n = matrix.size();
//     for (int i = 0; i < n; i++) {
//     for (int j = 0; j < i; j++) {
//         swap(matrix[i][j], matrix[j][i]);
//     }
//     }
//     for (int i = 0; i < n; i++) {
//     reverse(matrix[i].begin(), matrix[i].end());
//     }
// }

// vector<int> spiralMatrix(vector<vector<int>>&mat){
//     int n = mat.size();
//     int m = mat[0].size();
//     int left = 0 , right = m-1;
//     int top = 0 , bottom = n-1;
//     vector<int> ans;
//     while(top <= bottom && left <= right){
//         for(int i=left ; i<=right ; i++){
//             ans.push_back(mat[top][i]);
//         }
//         top++;
//         for(int i=top ; i<=bottom ; i++){
//             ans.push_back(mat[i][right]);
//         }
//         right--;
//         if(top<=bottom){
//             for(int i=right ; i>=left ; i--){
//             ans.push_back(mat[bottom][i]);
//             }
//             bottom--;
//         }
//         if(left<=right){
//             for(int i=bottom ; i>=top ; i--){
//                 ans.push_back(mat[i][left]);
//             }
//             left++;
//         }
//     }
//     return ans;
// }

int findAllSubarrayWithGivenSum(vector<int>&arr,int k){
    int preSum=0, cnt=0;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0 ; i<arr.size() ; i++){
        preSum+=arr[i];
        int remove=preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}

int main(){
    // int n = 11;
    // vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
    // int target;
    // cout<<"Enter the target value : ";
    // cin>>target;
    // string ans = twoSum(n,arr,target);
    // cout << "This is the answer for variant 1: " << ans << endl;
    // sortArray(arr, n);
    // int  n;
    // cout<<"Enter the no. of elements : ";
    // cin>>n;
    // int arr[n];
    // for(int i=0; i<n ; i++){
    //     cin>>arr[i];
    // }
    // majorityElem(arr,n);
    // maxSubarraySum(arr,n);
    // maximumProfit(arr,n);
    // int ans=rearrangebysign(arr,n);
    // vector<int> A = {1,2,-4,-5};
    // vector<int> ans = RearrangebySign(A);
    //  for (int i = 0; i < ans.size(); i++) {
    //      cout << ans[i] << " ";
    // }
    // vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    // vector<int> ans = nextGreaterPermutation(A);

    // cout << "The next permutation is: [";
    // for (auto it : ans) {
    //     cout << it << " ";
    // }
    // cout << "]";
    // vector<int> ans = superiorElement(arr,n);
    // for(int i=ans.size()-1 ; i>=0 ; i--){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    // longestConsecutiveElem(arr,n);
    // vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    // int n = matrix.size();
    // int m = matrix[0].size();
    // vector<vector<int>> ans = zeroMatrix(matrix,n,m);
    // cout<<"The final matrix is : ";
    // for(auto it : ans){
    //     for(auto ele : it){
    //         cout<<ele<<" ";
    //     }
    //     cout<<" ";
    // }
    // vector < vector < int >> mat;
    // mat =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // rotateMatrix(mat);
    // cout << "Rotated Image" << endl;
    // for (int i = 0; i < mat.size(); i++) {
    // for (int j = 0; j < mat[0].size(); j++) {
    //     cout << mat[i][j] << " ";
    // }
    // cout << " "<<endl;
    // }
    // vector<vector<int>> mat {{1, 2, 3, 4},
    //                         {5, 6, 7, 8},
    // 	                    {9, 10, 11, 12},
    // 		                {13, 14, 15, 16}};
		                     
    // vector<int> ans = spiralMatrix(mat);
    // for(int i = 0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    vector arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarrayWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
return 0;
}