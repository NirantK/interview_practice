"""
Problem Description

Given an integer array A of size N.

You can pick B elements from either left or right end of the array A to get maximum sum.

Find and return this maximum possible sum.

NOTE: Suppose B = 4 and array A contains 10 elements then

You can pick first four elements or can pick last four elements or can pick 1 from front and 3 from back etc . you need to return the maximum possible sum of elements you can pick.
"""

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        if B == 0:
            return 0
        n = len(A)
        max_val = sum(A[:B])
        for i in range(B+1):
            # print("i", i, "val 1", sum(A[:B-i]), "val 2", sum(A[n-i:]))
            total = sum(A[:B-i]) + sum(A[n-i:])
            # print(total)
            max_val = max(max_val, total)
        return max_val

s = Solution()
ans = s.solve([1, 2, 3, 4, 5], 2)
assert ans == 9
assert s.solve([1, 2, 3, 4, 5], 3) == 12
assert s.solve([1, 2, 3, 4, 5], 4) == 14
assert s.solve([5, -2, 3 , 1, 2], 3) == 8
assert s.solve([ -969, -948, 350, 150, -59, 724, 966, 430, 107, -809, -993, 337, 457, -713, 753, -617, -55, -91, -791, 758, -779, -412, -578, -54, 506, 30, -587, 168, -100, -409, -238, 655, 410, -641, 624, -463, 548, -517, 595, -959, 602, -650, -709, -164, 374, 20, -404, -979, 348, 199, 668, -516, -719, -266, -947, 999, -582, 938, -100, 788, -873, -533, 728, -107, -352, -517, 807, -579, -690, -383, -187, 514, -691, 616, -65, 451, -400, 249, -481, 556, -202, -697, -776, 8, 844, -391, -11, -298, 195, -515, 93, -657, -477, 587], 81) == -5453