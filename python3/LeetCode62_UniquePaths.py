#!/bin/env python3

import math

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return math.comb(m+n-2, m-1)


if __name__ == "__main__":
    so = Solution()
    print(so.uniquePaths(51, 9))