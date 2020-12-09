#include <iostream>
#include <map>
#include <tuple>
// #include <pair

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            return uniquePaths(n, m);
        }
        long ret = 1;
        int a = m -1 ;
        int b = n - 1;
        for (int i = 1; i <= a; i++) {
            if ((b+i)%i == 0) {
                ret *= ((b+i) / i);
            } else {
                ret *= (b+i);
                ret /= i;
            }
            
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    // map<tuple<int,int>, int> test_case;
    // Solution so;
    // make_pair<int,int>(7,3);
    // test_case[make_tuple(7,3)] = 28;
    // for(auto &v: test_case) {
    //     int s = so.uniquePaths(get<0>(v.first), get<1>(v.first));
    //     if (s != v.second) {
    //         cout << "test for " << v.first << "error, expected:" << v.second << ", but acutal is:" << s << endl;
    //     }
    // }
    map<pair<int,int>, int> test_case;
    test_case[make_pair<int,int>(7,3)] = 28;
    test_case[make_pair<int,int>(10,10)] = 48620;
    test_case[make_pair<int,int>(23,12)] = 193536720;
    test_case[make_pair<int,int>(51,9)] = 1916797311;
    for(auto &v : test_case) {
        int acutal = so.uniquePaths(v.first.first, v.first.second);
        if (acutal != v.second) {
            cout << "test for (" << v.first.first << "," << v.first.second << ") error, expected:" 
            << v.second << ", but acutal is:" << acutal << endl;
        }
    }
    return 0;
}



