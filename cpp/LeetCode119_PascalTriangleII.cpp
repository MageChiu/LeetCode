#include "mychiu.h"

#include <vector>


using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> d[2];
        int f = 0;
        d[f].push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            d[!f].resize(i+1);
            d[!f][0] = 1;
            for (int j = 1; j < i; j++) {
                d[!f][j] = d[f][j-1] + d[f][j];
            }
            d[!f][i] = 1;
            f = !f;
        }
        return d[f];
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    for (int i = 0; i < 10; i++) {
        vector<int> ret = so.getRow(i);
        Common::print_data(ret);
    }
    return 0;
}
