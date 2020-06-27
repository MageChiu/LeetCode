/*****************************************************
* 	 Filename: 	 LeetCodeM16_18_PatternMatchingLCCI.cpp
* 	 Author: 	 zhaopeng
* 	 Description: 	16.18. Pattern Matching LCCI 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-22T00:51:45.022Z+08:00
* 	 Modified: 	 2020-06-22T00:51:45.022Z+08:00
* 	 Compiler: 	 g++
*****************************************************/


#include "mychiu.h"
#include <string>


using namespace std;


class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if (pattern.empty()) {
            if (value.empty()) {
                return true;
            } else {
                return false;
            }
        }
        if (pattern.size() == 1) {
            return true;
        }
        int cnt_a = 0;
        int cnt_b = 0;
        for (int i = 0;i < pattern.size(); i++) {
            if (pattern[i] == 'a') {
                cnt_a++;
            } else {
                cnt_b++;
            }
        }
        vector<int> cnt_v = {0};
        for (int i = 0; i< value.size(); i++) {
            cnt_v[value[i]- 'a']++;
        }
        int i =0;
        int j = 0;
        while(i < pattern.size() && j < value.size()) {
            
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

