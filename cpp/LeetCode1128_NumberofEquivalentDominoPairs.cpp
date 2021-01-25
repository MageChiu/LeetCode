#include <vector>
#include <map>
#include "mychiu.h"
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        auto getNumber = [](const vector<int> &num) -> int {
            int a = num[0];
            int b = num[1];
            if (a > b) {
                a = num[1];
                b = num[0];
            }
            return a * 10 + b;
        };
        vector<int> dd(100, 0);
        for (int i = 0; i < dominoes.size(); i++) {
            int c = getNumber(dominoes[i]);
            dd[c]++;
        }
        auto getCount = [](int num) -> int {
            if(num < 2) {
                return 0;
            }
            return (num - 1) * num / 2;
        };
        int ret = 0;
        for (int i= 11; i < 100; i++) {
            ret += getCount(dd[i]);
        }
        return ret;
    }
    
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



