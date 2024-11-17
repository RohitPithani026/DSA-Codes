#include <bits/stdc++.h>
using namespace std;

// Iterative Implementation
// int binarySearch(int arr[],int n,int target){
//     int low = 0;
//     int high = n-1;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid]==target) return mid;
//         else if(target>arr[mid]) low = mid + 1;
//         else high = mid - 1;
//         return mid;
//     } 
//     return -1;
// }

//Recursive Implementation
// int binarySearch(vector<int>& nums, int low, int high, int target) {
//     if (low > high) return -1;
//     int mid = (low + high) / 2;
//     if (nums[mid] == target) return mid;
//     else if (target > nums[mid])
//         return binarySearch(nums, mid + 1, high, target);
//     return binarySearch(nums, low, mid - 1, target);
// }

// int search(vector<int>& nums, int target) {
//     return binarySearch(nums, 0, nums.size() - 1, target);
// }

// int lowerBound(vector<int>&arr,int n,int target){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid]>=target){
//             ans=mid;
//             high = mid-1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int higherBound(vector<int> &arr,int n,int target){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid]>target){
//             ans = mid;
//             high = mid -1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int findFloor(int arr[], int n, int x) {
// 	int low = 0, high = n - 1;
// 	int ans = -1;

// 	while (low <= high) {
// 		int mid = (low + high) / 2;
// 		if (arr[mid] <= x) {
// 			ans = arr[mid];
// 			low = mid + 1;
// 		}
// 		else {
// 			high = mid - 1; 
// 		}
// 	}
// 	return ans;
// }
// int findCeil(int arr[], int n, int x) {
// 	int low = 0, high = n - 1;
// 	int ans = -1;

// 	while (low <= high) {
// 		int mid = (low + high) / 2;
// 		if (arr[mid] >= x) {
// 			ans = arr[mid];
// 			high = mid - 1;
// 		}
// 		else {
// 			low = mid + 1;
// 		}
// 	}
// 	return ans;
// }
// pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
// 	int f = findFloor(arr, n, x);
// 	int c = findCeil(arr, n, x);
// 	return make_pair(f, c);
// }

// int firstOccurrence(vector<int> &arr, int n, int k) {
//     int low = 0, high = n - 1;
//     int first = -1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (arr[mid] == k) {
//             first = mid;
//             high = mid - 1;
//         }
//         else if (arr[mid] < k) {
//             low = mid + 1; 
//         }
//         else {
//             high = mid - 1; 
//         }
//     }
//     return first;
// }
// int lastOccurrence(vector<int> &arr, int n, int k) {
//     int low = 0, high = n - 1;
//     int last = -1;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (arr[mid] == k) {
//             last = mid;
//             low = mid + 1;
//         }
//         else if (arr[mid] < k) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1; 
//         }
//     }
//     return last;
// }
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
//     int first = firstOccurrence(arr, n, k);
//     if (first == -1) return { -1, -1};
//     int last = lastOccurrence(arr, n, k);
//     return {first, last};
// }
// int count(vector<int>& arr, int n, int x) {
//     pair<int, int> ans = firstAndLastPosition(arr, n, x);
//     if (ans.first == -1) return 0;
//     return (ans.second - ans.first + 1);
// }

// int search(vector<int> &arr,int n,int k){
//     int low = 0 ; int high = n-1;
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(arr[mid]==k) return mid;
//         if(arr[low]<=arr[mid]){
//             if(arr[low]<=k && k <= arr[mid]){
//                 high = mid -1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         else{
//             if(arr[mid]<=k && k <= arr[high]){
//                 low  = mid+1;
//             }
//             else{
//                 high = mid -1;
//             }
//         }
//     }
//     return -1;
// }

// bool searchInRotatedArrayII(vector<int> &arr,int n,int k){
//     int low = 0 ; int high = n-1;
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(arr[mid]==k) return true;
//         if(arr[low]==arr[mid] && arr[mid]==arr[high]){
//             low = low + 1;
//             high = high - 1;
//             continue;
//         }
//         if(arr[low]<=arr[mid]){
//             if(arr[low]<=k && k <= arr[mid]){
//                 high = mid -1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         else{
//             if(arr[mid]<=k && k <= arr[high]){
//                 low  = mid+1;
//             }
//             else{
//                 high = mid -1;
//             }
//         }
//     }
//     return false;
// }

// int findMin(vector<int> &arr){
//     int low = 0 ; int high = arr.size()-1; int ans = INT_MAX;
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(arr[low]<=arr[high]){
//             ans = min(ans , arr[low]);
//             break;
//         }
//         if(arr[low]<=arr[mid]){
//             ans = min(ans,arr[low]);
//             low = mid+1;
//         }
//         else{
//             ans = min(ans,arr[mid]);
//             high = mid -1;
//         }
//     }        
//     return ans;  
// }

// int findKRotation(vector<int> &arr){
//     int low = 0 ; int high = arr.size()-1; int ans = INT_MAX;
//     int index = -1; 
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(arr[low]<=arr[high]){
//             if(arr[low]<ans){
//                 index = low;
//                 ans = arr[low];
//             }
//             break;
//         }
//         if(arr[low]<=arr[mid]){
//             if(arr[low]<ans){
//                 index = low;
//                 ans = arr[low];
//             }
//             low = mid+1;
//         }
//         else{
//             high= mid -1;
//             if(arr[mid]<ans){
//                 index = mid;
//                 ans = arr[high];
//             }
//         }
//     }        
//     return index;  
// }

// int singleNonDuplicate(vector<int>& arr) {
//     int n = arr.size(); 
//     if (n == 1) return arr[0];
//     if (arr[0] != arr[1]) return arr[0];
//     if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
//     int low = 1, high = n - 2;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
//             return arr[mid];
//         }
//         if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

// int findPeakElement(vector<int> &arr){
//     int n = arr.size();
//     if(n==1) return 0;
//     if(arr[0]>arr[1]) return 0;
//     if(arr[n-1]>arr[n-2]) return n-1;
//     int low = 1;
//     int high = n-2;

//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
//             return mid;
//         }
//         else if(arr[mid]>arr[mid-1]){
//             low = mid+1;
//         }
//         else high = mid-1;
//     }
//     return -1;
// }

// int floorSqrt(int n){
//     int low = 1 , high = n;
//     while(low<=high){
//         long long mid = (low + high)/2;
//         long long val = mid * mid;
//         if(val<=(long long)(n)){
//             low = mid+1;
//         }
//         else{
//             high = mid -1;
//         }
//     }
//     return high;
// }

// int func(int mid, int n, int m) {
//     long long ans = 1;
//     for (int i = 1; i <= n; i++) {
//         ans = ans * mid;
//         if (ans > m) return 2;
//     }
//     if (ans == m) return 1;
//     return 0;
// }
// int NthRoot(int n, int m) {
//     int low = 1, high = m;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int midN = func(mid, n, m);
//         if (midN == 1) {
//             return mid;
//         }
//         else if (midN == 0) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }

// int findMax(vector<int> &v) {
//     int maxi = INT_MIN;
//     int n = v.size();
//     for (int i = 0; i < n; i++) {
//         maxi = max(maxi, v[i]);
//     }
//     return maxi;
// }
// int calculateTotalHours(vector<int> &v, int hourly) {
//     int totalH = 0;
//     int n = v.size();
//     for (int i = 0; i < n; i++) {
//         totalH += ceil((double)(v[i]) / (double)(hourly));
//     }
//     return totalH;
// }
// int minimumRateToEatBananas(vector<int> v, int h) {
//     int low = 1, high = findMax(v);
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int totalH = calculateTotalHours(v, mid);
//         if (totalH <= h) {
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1;
//         }
//     }
//     return low;
// }

// bool possible(vector<int> &arr,int day,int m,int k){
//     int n = arr.size();
//     int cnt = 0;
//     int noOfB = 0;
//     for(int i=0 ; i<n ; i++){
//         if(arr[i]<=day){
//             cnt++;
//         }
//         else{
//             noOfB += (cnt/k);
//             cnt = 0;
//         }
//     }
//     noOfB += (cnt/k);
//     return noOfB>=m;
// }
// int roseGarden(vector<int>arr,int k,int m){
//     long long val = m*1ll*k*1ll;
//     int n = arr.size();
//     if(val>n) return -1;
//     int mini = INT_MAX,maxi = INT_MIN;
//     for(int i=0;i<n;i++){
//         mini = min(mini,arr[i]);
//         maxi = max(maxi,arr[i]);
//     }
//     int low = mini , high = maxi;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(possible(arr,mid,m,k)){
//             high = mid-1;
//         }
//         else low = mid + 1;
//     }
//     return low;
// }

// int sumByD(vector<int>&arr,int div){
//     int sum = 0;
//     int n =arr.size();
//     for(int i=0;i<n;i++){
//         sum = sum + ceil((double)(arr[i])/(double)(div));
//     }
//     return sum;
// }
// int smallestDivisor(vector<int>&arr,int limit){
//     int n = arr.size();
//     if(n>limit) return -1;
//     int low = 1, high = *max_element(arr.begin(),arr.end());
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(sumByD(arr,mid)<=limit){
//             high = mid -1;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return low;
// }

// int findDays(vector<int>&weights,int cap){
//     int days = 1;
//     int load = 0;
//     int n = weights.size();
//     for(int i=0;i<n;i++){
//         if(load + weights[i]>cap){
//             days += 1;
//             load = weights[i];
//         }
//         else{
//             load+=weights[i];
//         }
//     }
//     return days;
// }
// int leastWeightCapacity(vector<int>&weights,int d){
//     int low = *max_element(weights.begin(),weights.end());
//     int high = accumulate(weights.begin(),weights.end(),0);
//     while(low<=high){
//         int mid = (low + high)/2;
//         int numberOfDays = findDays(weights,mid);
//         if(numberOfDays<=d){
//             high = mid-1;
//         }
//         else{
//             low = mid +1;
//         }
//     }
//     return low;
// }

// int missingK(vector<int>vec,int n,int k){
//     int low = 0 , high = n-1;
//     while(low<=high){
//         int mid = (low + high)/2;
//         int missing = vec[mid] - (mid+1);
//         if(missing<k){
//             low = mid+1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }
//     return k+high+1;
// }

// bool canWePlace(vector<int>&stalls,int dist,int cows){
//     int cntCows = 1 , last = stalls[0];
//     for(int i = 1 ; i< stalls.size() ; i++){
//         if(stalls[i] - last >= dist){
//             cntCows++;
//             last = stalls[i];
//         }
//         if(cntCows>=cows) return true;
//     }
//     return false;
// }
// int aggressiveCows(vector<int>&stalls,int k){
//     sort(stalls.begin(),stalls.end());
//     int n = stalls.size();
//     int low =1 , high = stalls[n-1]-stalls[0];
//     while(low<=high){
//         int mid = (low +high)/2;
//         if(canWePlace(stalls,mid,k)==true){
//             low = mid +1;
//         }
//         else{
//             high = mid -1;
//         }
//     }
//     return high;
// }

// int countStudents(vector<int> &arr, int pages) {
//     int n = arr.size(); 
//     int students = 1;
//     long long pagesStudent = 0;
//     for (int i = 0; i < n; i++) {
//         if (pagesStudent + arr[i] <= pages) {
//             pagesStudent += arr[i];
//         }
//         else {
//             students++;
//             pagesStudent = arr[i];
//         }
//     }
//     return students;
// }
// int findPages(vector<int>& arr, int n, int m) {
//     if (m > n) return -1;
//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int students = countStudents(arr, mid);
//         if (students > m) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return low;
// }

// int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
//     int n = arr.size(); 
//     int cnt = 0;
//     for (int i = 1; i < n; i++) {
//         int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
//         if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
//             numberInBetween--;
//         }
//         cnt += numberInBetween;
//     }
//     return cnt;
// }
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); 
//     long double low = 0;
//     long double high = 0;
//     for (int i = 0; i < n - 1; i++) {
//         high = max(high, (long double)(arr[i + 1] - arr[i]));
//     }
//     long double diff = 1e-6 ;
//     while (high - low > diff) {
//         long double mid = (low + high) / (2.0);
//         int cnt = numberOfGasStationsRequired(mid, arr);
//         if (cnt > k) {
//             low = mid;
//         }
//         else {
//             high = mid;
//         }
//     }
//     return high;
// }

// double median(vector<int>&a,vector<int>&b){
//     int n1 = a.size();
//     int n2 = b.size();
//     if(n1>n2) return median(b,a);
//     int low = 0;
//     int high = n1;
//     int left = (n1+n2+1)/2;
//     int n = n1+n2;
//     while(low<=high){
//         int mid1 = (low+high)>>1;
//         int mid2 = left - mid1;
//         int l1 = INT_MIN, l2 = INT_MIN;
//         int r1 = INT_MAX , r2 = INT_MAX;
//         if(mid1<n1) r1 = a[mid1];
//         if(mid2<n2) r2 = b[mid2];
//         if(mid1 - 1 >= 0) l1 = a[mid1-1];
//         if(mid2 -1 >= 0) l2 = b[mid2-1];
//         if(l1<=r2 && l2<=r1){
//             if(n%2==1) return max(l1,l2);
//             return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
//         }
//         else if(l1>r2) high = mid1 -1;
//         else low = mid1+1;
//     }
//     return 0;
// }

// int KthElement(vector<int> &a,vector<int> &b,int n1,int n2,int k){
//     if(n1>n2) return KthElement(b,a,n2,n1,k);
//     int low = max(k-n2,0) , high = min(k,n1);
//     int left = k;
//     int n = n1+n2;
//     while(low<=high){
//         int mid1 = (low+high)>>1;
//         int mid2 = left - mid1;
//         int l1 = INT_MIN , l2 = INT_MIN;
//         int r1 = INT_MAX , r2 = INT_MAX;
//         if(mid1 < n1) r1 = a[mid1];
//         if(mid2 < n2) r2 = b[mid2];
//         if(mid1 - 1 >= 0) l1 = a[mid1-1];
//         if(mid2 - 1 >= 0) l2 = b[mid2-1];
//         if(l1<=r2 && l2<=r1){
//             return max(l1,l2);
//         }
//         else if(l1>r2) high = mid1-1;
//         else low  = mid1+1;
//     }
//     return 0;
// }

// int lowerBound(vector<int>arr,int n,int target){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(arr[mid]>=target){
//             ans=mid;
//             high = mid-1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }
// int rowWithMax1s(vector<vector<int>>&matrix,int n,int m){
//     int cnt_max = 0;
//     int index = -1;
//     for(int  i=0 ; i<n ; i++){
//         int cnt_ones = m-lowerBound(matrix[i],m,1);
//         if(cnt_ones>cnt_max){
//             cnt_max = cnt_ones;
//             index = i;
//         }
//     }
//     return index;
// }

// bool searchMatrix(vector<vector<int>>&mat,int target){
//     int n = mat.size();
//     int m = mat[0].size();
//     int low = 0;
//     int high = n * m - 1;
//     while(low<=high){
//         int mid = (low+high)/2;
//         int row = mid/m;
//         int col = mid%m;
//         if(mat[row][col]==target) return true;
//         else if(mat[row][col]<target) low =mid+1;
//         else high = mid - 1;
//     }
//     return false;
// }

// bool searchElement(vector<vector<int>>&mat,int target){
//     int n = mat.size();
//     int m = mat[0].size();
//     int row = 0 , col = m-1;
//     while(row<n && col >= 0){
//         if(mat[row][col]==target) return true;
//         else if(mat[row][col]<target) row++;
//         else col--;
//     }
//     return false;
// }

// int findMaxIndex(vector<vector<int>>&mat,int n,int m,int col){
//     int maxValue = -1;
//     int index = -1;
//     for(int i=0 ; i<n ; i++){
//         if(mat[i][col]>maxValue){
//             maxValue = mat[i][col];
//             index = i;
//         }
//     }
//     return index;
// }
// pair<int,int> findPeakGrid(vector<vector<int>>&mat){
//     int n = mat.size();
//     int m = mat[0].size();
//     int low = 0;
//     int high = m-1;
//     while(low<=high){
//         int mid = (low +high)/2;
//         int maxRowIndex = findMaxIndex(mat,n,m,mid);
//         int left = mid-1 >= 0 ? mat[maxRowIndex][mid-1] : -1 ;
//         int right = mid +1 < n ? mat[maxRowIndex][mid+1] : -1;
//         if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
//             cout<<"The Peak Element is : "<<mat[maxRowIndex][mid];
//             return {maxRowIndex,mid};
//         }
//         else if(mat[maxRowIndex][mid]<left){
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     cout<<"The Peak Element is : "<<mat[-1][-1];
//     return {-1,-1};
// }

// int upperBound(vector<int> &matrix,int n,int x){
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(matrix[mid]>x){
//             ans = mid;
//             high = mid -1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }
// int countSmallEqual(vector<vector<int>>&matrix,int n,int m,int x){
//     int cnt = 0;
//     for(int i=0 ; i<n ; i++){
//         cnt += upperBound(matrix[i],n,x);
//     }
//     return cnt;
// }
// int median(vector<vector<int>>&matrix,int n,int m){
//     int low = INT_MAX;
//     int high = INT_MIN;
//     n = matrix.size();
//     m = matrix[0].size();
//     for(int i=0 ; i<n ; i++){
//         low = min(low,matrix[i][0]);
//         high = max(high,matrix[i][m-1]);
//     }
//     int req = (n*m)/2;
//     while(low<=high){
//         int mid = (low+high)/2;
//         int smallEqual = countSmallEqual(matrix,n,m,mid);
//         if(smallEqual <= req) low = mid + 1;
//         else high = mid - 1;
//     }
//     return low;
// }

int main(){
    // vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    // int target = 6;
    // int ind = search(a, target);
    // int ind = binarySearch(arr,n,target);
    // if (ind == -1) cout << "The target is not present." << endl;
    // else cout << "The target is at index: "<< ind << endl;
    // if (ind == -1) cout << "The target is not present." << endl;
    // else cout << "The target is at index: "<< ind << endl;
    // vector<int> arr = {3, 5, 8, 9, 15, 19};
    // int n = 6, x = 5;
    // int ind = lowerBound(arr, n, target);
    // cout << "The lower bound is the index: " << ind << "\n";
    // int ind = higherBound(arr, n, target);
    // cout << "The lower bound is the index: " << ind << "\n";
    // pair<int, int> ans = getFloorAndCeil(arr, n, x);
	// cout << "The floor and ceil are: " << ans.first<< " " << ans.second << endl;
	// vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    // int n = 8, k = 8;
    // pair<int,int> answer = firstAndLastPosition(arr,n,k);
    // cout<<"The first and last occurance is : "<<answer.first<<" "<<answer.second<<endl;
    // int ans = count(arr, n, k);
    // cout << "The number of occurrences is: "<< ans << "\n";
    // vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    // int n = 9, k = 1;
    // int ans = search(arr, n, k);
    // if (ans == -1)
    //     cout << "Target is not present.\n";
    // else
    //     cout << "The index is: " << ans << "\n";
    // vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    // int k = 3 ; int n = arr.size();
    // bool ans = searchInRotatedArrayII(arr, n, k);
    // if (!ans) cout << "Target is not present.\n";
    // else cout << "Target is present in the array.\n";
    // vector<int> arr = {3,4,5,1,2};
    // int ans = findMin(arr);
    // cout << "The minimum element is: " << ans << "\n";
    // vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    // int ans = findKRotation(arr);
    // cout << "The array is rotated " << ans << " times.\n";
    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    // int ans = singleNonDuplicate(arr);
    // cout << "The single element is: " << ans << "\n";
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    // int ans = findPeakElement(arr);
    // cout << "The peak is at index: " << ans << "\n";
    // int n = 18;
    // int ans = floorSqrt(n);
    // cout << "The floor of square root of " << n << " is : " << ans << "\n";
    // int n = 3, m = 27;
    // int ans = NthRoot(n, m);
    // cout << "The answer is: " << ans << "\n";
    // vector<int> v = {7, 15, 6, 3};
    // int h = 8;
    // int ans = minimumRateToEatBananas(v, h);
    // cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    // vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    // int k = 3;
    // int m = 2;
    // int ans = roseGarden(arr, k, m);
    // if (ans == -1)
    //     cout << "We cannot make m bouquets.\n";
    // else
    //     cout << "We can make bouquets on day " << ans << "\n";
    // vector<int> arr = {1, 2, 3, 4, 5};
    // int limit = 8;
    // int ans = smallestDivisor(arr, limit);
    // cout << "The minimum divisor is: " << ans << "\n";
    // vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    // int d = 5;
    // int ans = leastWeightCapacity(weights, d);
    // cout << "The minimum capacity should be: " << ans << "\n";
    // vector<int> vec = {4, 7, 9, 10};
    // int n = 4, k = 4;
    // int ans = missingK(vec, n, k);
    // cout << "The missing number is: " << ans << "\n";
    // vector<int> stalls = {0, 3, 4, 7, 10, 9};
    // int k = 4;
    // int ans = aggressiveCows(stalls, k);
    // cout << "The maximum possible minimum distance is: " << ans << "\n";
    // vector<int> arr = {25, 46, 28, 49, 24};
    // int n = 5;
    // int m = 4;
    // int ans = findPages(arr, n, m);
    // cout << "The answer is: " << ans << "\n";
    // vector<int> arr = {1, 2, 3, 4, 5};
    // int k = 4;
    // long double ans = minimiseMaxDistance(arr, k);
    // cout << "The answer is: " << ans << "\n";
    // vector<int> a = {1, 4, 7, 10, 12};
    // vector<int> b = {2, 3, 6, 15};
    // cout << "The median of two sorted array is " << fixed << setprecision(1) << median(a, b) << '\n';
    // vector<int> a = {2,3,6,7,9};
    // vector<int> b = {1,4,8,10};
    // int n1 = a.size();
    // int n2 = b.size();
    // int k = 5;
    // cout<<"The element at the kth position in the final sorted array is "
    // <<KthElement(a,b,n1,n2,k);
    // vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    // int n = 3, m = 3;
    // cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    // vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
    //     {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
    //     {18, 21, 23, 26, 30}
    // };
    // searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
    
    // cout<<"The Peak ELement is : "<<
    // findPeakGrid(mat);
    //int n = 3, m = 3;
    //vector<vector<int>> arr = {{1, 3, 8},
    //                         {2, 3, 4},
    //                         {1, 2, 5}};
    //cout <<"The median of the row-wise sorted matrix is: "<<median(arr,n,m)<<endl;
    //return 0;
}