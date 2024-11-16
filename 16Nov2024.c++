#include <bits/stdc++.h>
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int l) {
        int n = nums.size();
        int i = 0, j = l-1;

        vector<int> ans;

        while(j < n) {
            int flag = 1;
            for(int k = i; k < j; k++) {
                if(nums[k] >= nums[k+1] || (nums[k] + 1) != nums[k+1]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) ans.push_back(-1);
            else ans.push_back(nums[j]);
            i++;
            j++;
        }

        return ans;
    }
};