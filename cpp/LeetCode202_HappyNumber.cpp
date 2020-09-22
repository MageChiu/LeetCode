#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
    }
};

int test_work(int n) {
    int k = n;
    int ret = 0;
    while (k > 0) {
        int m = k % 10;
        k /= 10;
        ret += m * m;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    for (int i = 0; i< 10; i++) {
        set<int> tmp;
        int k = i;
        // tmp.insert(k)
        while (tmp.find(k) != tmp.end()) {
            tmp.insert(k);
            k = test_work(k);
        }
        cout << "k=" << k << endl;
    }
    return 0;
}
