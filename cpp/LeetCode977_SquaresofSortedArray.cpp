#include "mychiu.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = 0;
        int n = A.size() -1;
        for (int i = 1; i <= n; i++) {
            if (abs(A[i]) < abs(A[k])) {
                k = i;
            }
        }
        int i = k -1;
        int j = k + 1;
        vector<int> res;
        res.reserve(n + 1);
        res.push_back(A[k] * A[k]);
        while(i>=0 && j <=n) {
            if (-A[i] < A[j]) {
                res.push_back(A[i] * A[i]);
                i--;
            } else {
                res.push_back(A[j] * A[j]);
                j++;
            }
        }
        while (i>=0) {
            res.push_back(A[i] * A[i]);
            i--;
        }
        while (j <= n) {
            res.push_back(A[j] * A[j]);
            j++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> test = {-4,-1,0,3,10};
    test = {-7,-3,2,3,11};
    Solution so;
    vector<int> ret = so.sortedSquares(test);
    Common::print_data(ret);
    return 0;
}
