#!/bin/env python3

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    LeetCode290_WordPattern.py                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Charles Chiu <charles.r.chiu@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 00:47:24 by Charles Chi       #+#    #+#              #
#    Updated: 2020/12/16 00:47:24 by Charles Chi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #





class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        str_arr = s.split(' ')
        dd = {}
        dt = {}
        if len(pattern) != len(str_arr):
            return False
        for i in range(0, len(pattern)):
            ch = pattern[i]
            key = str_arr[i]
            if ch not in dd:
                dd[ch] = key
            else:
                if dd[ch] != key:
                    return False
            if key not in dt:
                dt[key] = ch
            else:
                if dt[key] != ch:
                    return False
        return True

if __name__ == "__main__":
    so = Solution()
    test_dd = [
        {
            "input": {
                "pattern": "abba",
                "s": "dog cat cat dog"
            },
            "output": True
        },
        {
            "input": {
                "pattern": "abba",
                "s": "dog dog dog dog"
            },
            "output": False
        },
        {
            "input": {
                "pattern": "abba",
                "s": "dog cat dog fish"
            },
            "output": False
        },
        {
            "input": {
                "pattern": "aaa",
                "s": "aa aa aa aa"
            },
            "output": False
        },
    ]
    cnt = 0
    for dd in test_dd:
        ret = so.wordPattern(dd["input"]["pattern"], dd["input"]["s"])
        if ret != dd["output"]:
            print("test error, input:{0}, expected:{1}, acutal:{2}".format(dd["input"], dd["output"], ret))
        else:
            cnt += 1
    print("test [{0}] case [{1}] ok".format(len(test_dd), cnt))
    