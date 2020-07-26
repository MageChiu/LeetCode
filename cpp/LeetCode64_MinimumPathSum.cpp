/*
 * @Author: zhaopeng 
 * @Date: 2020-07-23 18:21:41 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-07-23 18:52:28
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.front().size();
        vector<vector<int>> data;
        for (int i = 0; i < 2; i++) {
            vector<int> _d;
            _d.resize(n);
            for(int j = 0; j < n; j++) {
                _d[j] = 0;
            }
            data.push_back(_d);
        }
        int flag = 0;

        
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i > 0 && j > 0) {
                    data[flag][j] = grid[i][j] + (data[!flag][j] < data[flag][j-1] ?data[!flag][j] : data[flag][j-1]);
                } else if (i > 0 && j == 0) {
                    data[flag][j] = grid[i][j] + data[!flag][j];
                } else if ( i == 0 && j > 0) {
                    data[flag][j] = grid[i][j] + data[flag][j-1];
                } else {
                    data[flag][j] = grid[i][j];
                }
                
            }
            flag = !flag;
        }
        return data[!flag][n -1 ];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> test = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution so;
    cout << so.minPathSum(test) << endl;
    return 0;
}


