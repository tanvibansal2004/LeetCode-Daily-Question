#include<bits/stdc++.h>
class Solution {
public:
    vector<int> decrypt(vector<int>& codes, int k) {
        int n = codes.size();
        vector<int> ans(n, 0);
        if(k == 0) {
            return ans;
        }
        else if(k > 0) {
            for(int i = 0; i < n; i++) {
                for(int j = 1; j <= k; j++) {
                    ans[i] += codes[(i+j) % n];
                }
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                for(int j = k; j < 0; j++) {
                    ans[i] += codes[(i+j+n) % n];
                }
            }
        }
        return ans;
    }
};