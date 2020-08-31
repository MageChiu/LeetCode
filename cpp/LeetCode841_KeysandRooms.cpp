/*
 * @Author: zhaopeng 
 * @Date: 2020-08-31 16:26:02 
 * @Last Modified by: zhaopeng
 * @Last Modified time: 2020-08-31 17:27:43
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> data(rooms.size(), 0);
        data[0] = 1;
        queue<int> footrint;

        int n = rooms.size();
        footrint.push(0);
        while (!footrint.empty()) {
            int k = footrint.front();
            footrint.pop();
            for (int j = 0; j < rooms[k].size(); j++) {
                if (data[rooms[k][j]] == 0) {
                    data[rooms[k][j]] = 1;
                    footrint.push(rooms[k][j]);
                }
            }
            data[k] = 2;    // 房间开过门了
        }
        for (int i = 0; i < n; i++) {
            if (data[i] == 0) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> test = {{1},{2},{3},{}};
    Solution so;
    test = {{1,3},{3,0,1},{2},{0}};
    cout << so.canVisitAllRooms(test) << endl;
    return 0;
}




