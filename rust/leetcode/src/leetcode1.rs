use std::collections::HashMap;
use std::vec;

pub struct Solution {

}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut data = HashMap::new();
        let mut vec = Vec::new();
        let n: i32 = nums.len();
        let i: i32 = 0;
        while i < n {
            
            let mut num = nums.get(i).unwrap();
            if data.contains_key(num) {
                let tmp: i32 = data.get_mut(num);
                return vec![tmp, i];
            } else {
                data.insert(target - num, i);
            }
            i += 1;
        }


        return vec;

    }
}