#include<bits/stdc++.h>
using namespace std;

// vector<int> generateRow(int row){
//     long long ans = 1;
//     vector<int> ansRow;
//     ansRow.push_back(1);
//     for(int col=1 ; col<row ; col++){
//         ans = ans * (row-col);
//         ans = ans / (col);
//         ansRow.push_back(ans);
//     }

//     return ansRow;
// }

// vector<vector<int>> pascalTriangle(int N){
//     vector<vector<int>> ans;
//     for(int i=1 ; i<=N ; i++){
//         vector<int> temp = generateRow(i);
//         ans.push_back(temp);
//     }
//     return ans;
// }

// vector<int> majorityElement(vector<int> v){
//     int cnt1 = 0;
//     int cnt2 = 0;
//     int el1 = INT_MIN;
//     int el2 = INT_MIN;
//     for(int i=0 ; i<v.size() ; i++){
//         if(cnt1==0 && el2!=v[i]){
//             cnt1 = 1;
//             el1 = v[i];
//         }
//         else if(cnt2==0 && el1!=v[i]){
//             cnt2 = 1;
//             el2 = v[i];
//         }
//         else if(v[i]==el1) cnt1++;
//         else if(v[i]==el2) cnt2++;
//         else{
//             cnt1--,cnt2--;
//         }
//     }
//     vector<int> ls;
//     cnt1 = 0 , cnt2 = 0;
//     for(int i = 0 ; i<v.size() ; i++){
//         if(el1==v[i]) cnt1++;
//         if(el2==v[i]) cnt2++;
//     }
//     int mini = (int)(v.size()/3);
//     if(cnt1>=mini) ls.push_back(el1);
//     if(cnt2>=mini) ls.push_back(el2);
//     return ls; 
// }

// vector<vector<int>> triplet(int n,vector<int> &num){
//     vector<vector<int>> ans;
//     sort(num.begin(),num.end());
//     for(int i=0 ;i<n ; i++){
//         if(i>0 && num[i]==num[i-1]) continue;
//         int j = i+1;
//         int k = n-1;
//         while(j<k){
//             int sum = num[i]+num[j]+num[k];
//             if(sum<0){
//                 j++;
//             }       
//             else if(sum>0){
//                 k--;
//             } 
//             else{
//                 vector<int> temp = {num[i],num[j],num[k]};
//                 ans.push_back(temp);
//                 j++;
//                 k--;
//                 while(j<k && num[j]==num[j-1]) j++;
//                 while (j<k && num[k]==num[k+1]) k--;
//             }
//         }
//     }
//     return ans;
// }

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     vector<vector<int>> ans;
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < n; i++) {
//         if (i > 0 && nums[i] == nums[i - 1]) continue;
//         for (int j = i + 1; j < n; j++) {
//             if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//             int k = j + 1;
//             int l = n - 1;
//             while (k < l) {
//                 long long sum = nums[i];
//                 sum += nums[j];
//                 sum += nums[k];
//                 sum += nums[l];
//                 if (sum == target) {
//                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                     ans.push_back(temp);
//                     k++; l--;
//                     while (k < l && nums[k] == nums[k - 1]) k++;
//                     while (k < l && nums[l] == nums[l + 1]) l--;
//                 }
//                 else if (sum < target) k++;
//                 else l--;
//             }
//         }
//     }
//     return ans;
// }

// int subArrayWithSumK(vector<int> a,int k){
//     int xr = 0;
//     map<int,int> mpp;
//     mpp[xr]++;
//     int cnt=0;
//     for(int i=0;i<a.size();i++){
//         xr=xr^a[i];
//         int x=xr^k;
//         cnt+=mpp[x];
//         mpp[xr]++;
//     }
//     return cnt;
// }

// vector<vector<int>> mergeOverlappingintervals(vector<vector<int>> &arr){
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     vector<vector<int>> ans;
//     for(int i=0 ; i<n ; i++){
//         if(ans.empty() || arr[i][0]>ans.back()[1]){
//             ans.push_back(arr[i]);
//         }
//         else{
//             ans.back()[1]=max(ans.back()[1],arr[i][1]);
//         }
//     }
//     return ans;
// }


// void swapifGreater(long long arr1[],long long arr2[],int ind1,int ind2){
//     if(arr1[ind1]>arr2[ind2]){
//         swap(arr1[ind1],arr2[ind2]);
//     }
// }

// void merge(long long arr1[],long long arr2[],int n,int m){
//     int len = n+m;
//     int gap = (len/2) + (len%2);
//     while(gap>0){
//         int left =0;
//         int right = left+gap;
//         while(right<len){
//             if(left<n && right>=n){
//                 swapifGreater(arr1,arr2,left,right-n);
//             }
//             else if(left>=n){
//                 swapifGreater(arr2,arr2,left-n,right-n);
//             }
//             else{
//                 swapifGreater(arr1,arr1,left,right);
//             }
//             left++,right++;
//         }
//         if(gap==1) break;
//         gap = (gap/2)+(gap%2);
//     }
// }

// vector<int> findMissingReapeatingNumbers(vector<int>a){
//     long long n = a.size();
//     long long SN = (n * (n+1))/2;
//     long long S2N = (n * (n+1) * (2*n+1))/6;
//     long long S=0,S2=0;
//     for(int i=0 ; i<n ;i++){
//         S += a[i];
//         S2 += (long long)a[i] * (long long)a[i];
//     }
//     long long val1 = S - SN;
//     long long val2 = S2 - S2N;
//     val2 = val2 / val1;
//     long long x = (val1+val2)/2;
//     long long y = x - val1;
//     return {(int)x,(int)y};
// }

// int merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; 
//     int left = low;     
//     int right = mid + 1;
//     int cnt = 0;
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             cnt += (mid - left + 1); 
//             right++;
//         }
//     }
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
//     return cnt;
// }

// int mergeSort(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(arr, low, mid);  
//     cnt += mergeSort(arr, mid + 1, high);
//     cnt += merge(arr, low, mid, high);
//     return cnt;
// }

// int numberOfInversions(vector<int>&a, int n) {
//     return mergeSort(a, 0, n - 1);
// }

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; 
//     int left = low;     
//     int right = mid + 1;  
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// int countPairs(vector<int> &arr, int low, int mid, int high) {
//     int right = mid + 1;
//     int cnt = 0;
//     for (int i = low; i <= mid; i++) {
//         while (right <= high && arr[i] > 2 * arr[right]) right++;
//         cnt += (right - (mid + 1));
//     }
//     return cnt;
// }

// int mergeSort(vector<int> &arr, int low, int high) {
//     int cnt = 0;
//     if (low >= high) return cnt;
//     int mid = (low + high) / 2 ;
//     cnt += mergeSort(arr, low, mid);  
//     cnt += mergeSort(arr, mid + 1, high);
//     cnt += countPairs(arr, low, mid, high);
//     merge(arr, low, mid, high);  
//     return cnt;
// }

// int team(vector <int> & skill, int n)
// {
//     return mergeSort(skill, 0, n - 1);
// }

int maxProductSubArray(vector<int> &arr){
    int n=arr.size();
    int pre = 1;
    int suff = 1;
    int ans = INT_MIN;
    for(int i=0 ; i<n ; i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre *= arr[i];
        suff *= arr[n-i-1];
        ans = max(ans,max(pre,suff));
    }
    return ans;
}

int main(){
    // int N;
    // cout<<"Enter the no. of elements : ";
    // cin>>N;
    // vector<vector<int>> ans = pascalTriangle(N);
    // for (auto it : ans) {
    //     for (auto ele : it) {
    //         cout << ele << " ";
    //     }
    //     cout << " "<<endl;
    // }
    // vector<int> arr = {11, 33, 33, 11, 33, 11};
    // vector<int> ans = majorityElement(arr);
    // cout << "The majority elements are: ";
    // for (auto it : ans)
    //     cout << it << " ";
    // cout << "\n";
    // vector<int> num = { -1, 0, 1, 2, -1, -4};
    // int n = num.size();
    // vector<vector<int>> ans = triplet(n, num);
    // for (auto it : ans) {
    //     cout << "[";
    //     for (auto i : it) {
    //         cout << i << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << "\n";
    // vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    // int target = 9;
    // vector<vector<int>> ans = fourSum(nums, target);
    // cout << "The quadruplets are: \n";
    // for (auto it : ans) {
    //     cout << "[";
    //     for (auto ele : it) {
    //         cout << ele << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << "\n";
    // vector<int> a = {4, 2, 2, 6, 4};
    // int k = 6;
    // int ans = subArrayWithSumK(a, k);
    // cout << "The number of subarrays with XOR k is: "<< ans << "\n";
    // vector<vector<int>> arr = {{1, 3},{2, 4},{9, 11} ,{8, 10}, {2, 6}, {15, 18}, {16, 17}};
    // vector<vector<int>> ans = mergeOverlappingintervals(arr);
    // cout << "The merged intervals are: " << "\n";
    // for (auto it : ans) {
    //     cout << "[" << it[0] << ", " << it[1] << "] ";
    // }
    // cout << endl;
    // long long arr1[] = {1, 4, 8, 10};
    // long long arr2[] = {2, 3, 9};
    // int n = 4, m = 3;
    // merge(arr1, arr2, n, m);
    // cout << "The merged arrays are: " << "\n";
    // cout << "arr1[] = ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr1[i] << " ";
    // }
    // cout << "\narr2[] = ";
    // for (int i = 0; i < m; i++) {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;
    // vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    // vector<int> ans = findMissingReapeatingNumbers(a);
    // cout << "The repeating and missing numbers are: {"
    //      << ans[0] << ", " << ans[1] << "}\n";
    // vector<int> a = {5, 4, 3, 2, 1};
    // int n = 5;
    // int cnt = numberOfInversions(a, n);
    // cout << "The number of inversions are: "
    //      << cnt << endl;
    // vector<int> a = {4, 1, 2, 3, 1};
    // int n = 5;
    // int cnt = team(a, n);
    // cout << "The number of reverse pair is: "
    //      << cnt << endl;
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}