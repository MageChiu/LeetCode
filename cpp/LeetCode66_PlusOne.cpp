#include <vector>
#include "mychiu.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> data;
        data.reserve(digits.size() + 1);
        int c = 1;
        for (int i = digits.size() - 1; i >=0 ; i--) {
            int k = digits[i] + c;
            data.push_back(k % 10);
            c = k / 10;
        }
        if (c > 0) {
            data.push_back(c);
        }
        reverse(data.begin(), data.end());
        return data;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
