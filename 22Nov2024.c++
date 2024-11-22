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