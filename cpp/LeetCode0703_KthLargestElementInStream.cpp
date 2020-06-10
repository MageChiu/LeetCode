/*****************************************************
* 	 Filename: 	 LeetCode0703_KthLargestElementInStream.cpp
* 	 Author: 	 zhaopeng
* 	 Description:703. Kth Largest Element in a Stream 	 
* 	 Version: 	 1.0
* 	 Created: 	 2020-06-10T22:39:50.873Z+08:00
* 	 Modified: 	 2020-06-10T22:39:50.873Z+08:00
* 	 Compiler: 	 g++
*****************************************************/

#include <iostream>
#include <queue>

using namespace std;




class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int i =0;i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        c.push(val);
        if (c.size() > _k) {
            int tmp = c.top();
            c.pop();
            a.push(tmp);
        }
        return c.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > a; // 大顶堆
    priority_queue<int, vector<int>, greater<int> > c; // 小顶堆
    int _k;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main(int argc, char const *argv[])
{
    vector<int> nums = {4,5,8,2};
    int k = 3;
    vector<int> test = {3,5,10,9,4};
    // priority_queue<int, vector<int>, less<int> > a;
    // priority_queue<int, vector<int>, greater<int> > c;
    // for (int i =0; i < nums.size(); i++) {
    //     a.push(nums[i]);
    //     c.push(nums[i]);
    //     cout << "a.top=" << a.top() << endl;
    //     cout << "c.top=" << c.top() << endl; 
    // }
    KthLargest *tester = new KthLargest(k, nums);
    for (int i =0; i < test.size(); i++) {
        cout << "add:" << test[i] <<"," << tester->add(test[i]) << endl;
    }
    return 0;
}
