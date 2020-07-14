
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        } else if (triangle.size() == 1) {
            return triangle[0][0];
        }
        int n = triangle.back().size();
        vector<int> data;
        data.resize(n+1);
        for (int i = 0; i < triangle.size(); i++) {
            int k = triangle[i].size() - 1;
            for(int j = k; j >= 0; j--) {
                if (j == 0) {
                    data[j] = data[j] + triangle[i][j];
                }
                else if (j == k) {
                    data[j] = data[j-1] + triangle[i][j];
                } else {
                    data[j] = min(data[j-1], data[j]) + triangle[i][j];
                }
            }
        }
        int ret = data[0];
        for (int i = 1; i <n; i++) {
            ret = min(ret, data[i]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> test = {
             {2},
            {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution so;
    int ret = so.minimumTotal(test);
    cout << ret << endl;
    return 0;
}

