#include <bits/stdc++.h>
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = -1, right = -1, ind = 0;
        while(ind < n-1) {
            if(arr[ind] <= arr[ind+1]) ind++;
            else break;
        }
        left = ind;
        if(left == n-1) return 0;

        ind = n-1;

        while(ind >= 0) {
            if(arr[ind] >= arr[ind-1]) ind--;
            else break;
        }
        right = ind;
        if(left == -1 && right == -1) return n-1;

        //initializing a bigger size of POSSIBLE SUBARRAY
        int ans = min(n - 1 - left, right);

        int i = 0, j = right;
        //optimizing the subarray size
        while(i <= left) {
            while(j < n && arr[i] > arr[j]) j++;
            ans = min(ans, j - i - 1);
            i++;
        }

        return ans;
    }
};