

————————

<!-- TOC -->autoauto- [1. Two Sum](#1-two-sum)auto- [002. Add Two Numbers](#002-add-two-numbers)auto- [22. Generate Parentheses](#22-generate-parentheses)auto- [41. First Missing Positive](#41-first-missing-positive)auto- [50. Pow(x, n)](#50-powx-n)auto- [371. Sum of Two Integers](#371-sum-of-two-integers)auto- [374. Guess Number Higher or Lower](#374-guess-number-higher-or-lower)auto- [412. Fizz Buzz](#412-fizz-buzz)auto- [461](#461)auto- [476 Number Complement](#476-number-complement)auto- [500. Keyboard Row](#500-keyboard-row)auto- [530. Minimum Absolute Difference in BST](#530-minimum-absolute-difference-in-bst)auto- [535. Encode and Decode TinyURL](#535-encode-and-decode-tinyurl)auto- [538. Convert BST to Greater Tree](#538-convert-bst-to-greater-tree)auto- [543. Diameter of Binary Tree](#543-diameter-of-binary-tree)auto- [557. Reverse Words in a String III](#557-reverse-words-in-a-string-iii)auto- [575 Distribute Candies](#575-distribute-candies)auto- [673. Number of Longest Increasing Subsequence](#673-number-of-longest-increasing-subsequence)auto- [674. Longest Continuous Increasing Subsequence](#674-longest-continuous-increasing-subsequence)auto- [697. Degree of an Array](#697-degree-of-an-array)auto- [728. Self Dividing Numbers](#728-self-dividing-numbers)auto- [724. Find Pivot Index](#724-find-pivot-index)auto- [733. Flood Fill](#733-flood-fill)auto- [744. Find Smallest Letter Greater Than Target](#744-find-smallest-letter-greater-than-target)auto- [744. Find Smallest Letter Greater Than Target](#744-find-smallest-letter-greater-than-target-1)auto- [747. Largest Number At Least Twice of Others](#747-largest-number-at-least-twice-of-others)auto- [760. Find Anagram Mappings](#760-find-anagram-mappings)auto- [762. Prime Number of Set Bits in Binary Representation](#762-prime-number-of-set-bits-in-binary-representation)autoauto<!-- /TOC -->
—————————


# 1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
```
Given nums = [2, 7, 11, 15], target = 9,
```
```
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

解法1：
通过map保存

# 002. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```


# 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

file: LeetCode022_GenerateParentheses.cpp

任何适合，从左起看过去，左括号的数目都一定大于等于右括号，最终二者是相等的。


# 41. First Missing Positive
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

FileName: LeetCode041_FirstMissingPositive.cpp

|    | 0 | 1 | 2 | 3 | 4 | 5 |
|:--:|:-:|:-:|:-:|:-:|:-:|:-:|
input| 9 | 7 |5  |4  |2  | 1 |
ret  |1  |1  |1  |1  |1  | 3 |
max_ | 9 |
min  | 8 |




# 50. Pow(x, n)
Implement pow(x, n).

file : ALG050_Pow.cpp


# 371. Sum of Two Integers 

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

file ： ALG371_SumofTwoIntegers.cpp


# 374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6

file ALG374_GuessNumberHigherorLower.cpp


# 412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
``` shell
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
```

> file: ALG412_FizzBuzz.cpp



# 461 

# 476 Number Complement

# 500. Keyboard Row

> file: ALG500_KeyboardRow.cpp

# 530. Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:
``` 
Input:

   1
    \
     3
    /
   2

Output:
1
``` 
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.

> file: ALG530_MinimumAbsoluteDifferenceBST.cpp

# 535. Encode and Decode TinyURL

> Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.



file : ALG535_EncodeAndDecodeTinyURL.cpp

# 538. Convert BST to Greater Tree


file : ALG538_ConvertBST2GreaterTree.cpp


# 543. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
```
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
```



> file: ALG543_DiameterofBinaryTree.cpp


# 557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
```
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

> file: ALG557_ReverseWordsinStringIII.cpp

# 575 Distribute Candies

Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
``` 
Input: candies = [1,1,2,2,3,3]
Output: 3
```
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
``` 
Input: candies = [1,1,2,3]
Output: 2
```
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

1. The length of the given array is in range [2, 10,000], and will be even.
2. The number in given array is in range [-100,000, 100,000].


> file:ALG575_DistributeCandies.cpp



# 673. Number of Longest Increasing Subsequence

> file : ALG673_NumberOfLongestIncreasingSubsequence.cpp

_________

# 674. Longest Continuous Increasing Subsequence


> file: ALG674_LongestContinuousIncreasingSubsequence.cpp

# 697. Degree of an Array
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
```
Input: [1, 2, 2, 3, 1]
Output: 2

Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
```
> file: ALG697_DegreeofArray.cpp

# 709. To Lower Case
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
> file: LeetCode709_ToLowerCase.cpp

# 728. Self Dividing Numbers


> file: ALG728_SelfDividingNumbers.cpp


# 724. Find Pivot Index


> file :ALG724_FindPivotIndex.cpp



# 733. Flood Fill
> file: ALG733_Flood_Fill.cpp

# 744. Find Smallest Letter Greater Than Target


# 744. Find Smallest Letter Greater Than Target
>file : ALG744_FindSmallestLetterGreaterThanTarget.cpp

# 747. Largest Number At Least Twice of Others
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
Note:
nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
>file: ALG747_LargestNumberAtLeastTwiceofOthers.cpp


# 760. Find Anagram Mappings

Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].

>file: ALG760_FindAnagramMappings.cpp




# 762. Prime Number of Set Bits in Binary Representation

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:
L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.

> file: ALG762_PrimeNumberSetBitsBinaryRepresentation.cpp


# 1021. Remove Outermost Parentheses
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.

 

Example 1:

Input: "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Note:

S.length <= 10000
S[i] is "(" or ")"
S is a valid parentheses string

file: LeetCode1021_RemoveOutermostParentheses.cpp



