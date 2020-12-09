#include "mychiu.h"
#include <iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n_5 = 0;
        int n_10 = 0;
        int n_20 = 0;
        for (int i =0; i < bills.size(); i++) {
            switch (bills[i])
            {
            case 5:
                /* code */
                {
                    n_5++;
                    break;  
                }
            case 10:
                {
                    if(n_5 >= 1) {
                        n_10++;
                        n_5--;
                    } else {
                        return false;
                    }
                    break;
                }
            case 20:
                {
                    int k = 15;
                    if (n_10 >= 1) {
                        n_10--;
                        k-= 10;
                    }
                    while (n_5 >= 1 && k>0)
                    {
                        k-= 5;
                        n_5--;
                    }
                    if (k != 0) {
                        return false;
                    } else {
                        n_20++;
                    }
                    break;
                }
            default:
                return false;
                break;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    Solution so;
    vector<int> test_data;
    // test_data = {5,5,5,10,20};  // true
    // cout << so.lemonadeChange(test_data) << endl;

    // test_data = {10,10};    // false
    // cout << so.lemonadeChange(test_data) << endl;

    // test_data = {5,5,10,10,20}; //false
    // cout << so.lemonadeChange(test_data) << endl;

    test_data = {5,5,5,10,5,20,5,10,5,20};  // true
    cout << so.lemonadeChange(test_data) << endl;
    return 0;
}
