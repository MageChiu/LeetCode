#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string s = "11";
        int j = 0;

        for (int i = 3; i <= n; i++) {
            stringstream ss;
            char ch = s[0];
            int k = 1;
            for (int j = 1; j < s.size(); j++) {
                if (ch == s[j]) {
                    k++;
                } else {
                    // ss.clear();
                    ss << k << ch;
                    ch = s[j];
                    k = 1;
                }
            }
            // ss.clear();
            ss << k << ch;
            ch = s[j];
            k = 1;
            ss >> s;
        }
        return s;

    }
};


int main(int argc, char const *argv[])
{
    /* code */
    stringstream ss;
    for (int i = 0; i < 10; i++) {
        ss.clear();
        ss << i;
        string tmp;
        ss >> tmp;
        cout << "i= " << i << ". tmp = " << tmp << endl;
    }
    Solution so;
    for (int i = 1 ; i <= 10; i++) {
        cout << "i = " << i << ", res = [" << so.countAndSay(i) << "]" << endl;
    }
    return 0;
}

