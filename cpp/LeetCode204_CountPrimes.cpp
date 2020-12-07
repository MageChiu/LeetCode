#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        } else if (n == 2) {
            return 0;
        } else if (n == 3) {
            return 1;
        }
        vector<int> dd(n+1, 0);
        int cnt = 0;
        for(int i = 2; i * i < n; i++) {
            if (dd[i] != 0) {
                continue;
            }
            for (int j = 2 * i; j < n; j+=i) {
                dd[j] = 1;
            }
        }
        
        for (int i = 2; i < n; i++) {
            if (dd[i] == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    int t = 999983;
    cout << so.countPrimes(t) << endl;
    /* code */
    return 0;
}


