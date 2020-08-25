#include <iostream>
#include "mychiu.h"
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int tmp = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (tmp > 0) {
                    ret = tmp;
                }
                tmp = 0;
            } else {
                tmp++;
            }
        }
        if (tmp > 0) {
            ret = tmp;
        }
        return ret;
    }
};


int main(int argc, const char *argv[])
{
    Solution so;
    string test="a  ";
    auto ret = so.lengthOfLastWord(test);
    cout << ret << endl;
    return 0;
}




