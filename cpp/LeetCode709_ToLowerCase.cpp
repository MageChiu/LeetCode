#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        string ret = string(str);
        int dur = 'A' - 'a';
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                ret[i] = (char)(str[i] - dur);
            }
        }
        return ret;
    }
};

int main()
{
    Solution so;
    cout << so.toLowerCase("Hello") << endl;
    return 0;
}