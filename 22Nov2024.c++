//1. Time Complexity - O(rows*rows*cols)
//   Space Complexity - O(cols)
#include<bits/stdc++.h>
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxRows = 0;

        for(auto currRow: matrix) {
            vector<int> invertedRow(cols);

            for(int i = 0; i < cols; i++) {
                invertedRow[i] = 1 - currRow[i];
            }
            int count = 0;
            for(auto row: matrix) {
                if(row == currRow || row == invertedRow) {
                    count++;
                }
            }
            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};

//2. Time Complexity - O(rows*cols)
//   Space Complexity - O(rows*cols)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int r = matrix.size(), c = matrix[0].size();
        unordered_map<bitset<300>, int, hash<bitset<300>>> mp;
        mp.reserve(r);

        for (int i = 0; i < r; i++) {
            bitset<300> pattern;
            bool term0=matrix[i][0];
            for (int j = 0; j < c; j++) 
                pattern[j] = matrix[i][j]^term0;
            mp[pattern]++;
        }

        int max_rows = 0;
        for (auto& [key, count] : mp)
            max_rows = max(max_rows, count);

        return max_rows;
    }
};