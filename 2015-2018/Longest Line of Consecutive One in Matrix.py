# Longest Line of Consecutive One in Matrix
# Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

# Example:
# Input:
# [[0,1,1,0],
#  [0,1,1,0],
#  [0,0,0,1]]
# Output: 3
# Hint: The number of elements in the given matrix will not exceed 10,000.
# from LeetCode Contest 29

class Solution(object):

    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        n = len(M)
        if n == 0:
            return 0
        m = len(M[0])
        if m == 0:
            return 0

        row = [[False] * m for _ in xrange(n)]
        col = [[False] * m for _ in xrange(n)]
        dia = [[False] * m for _ in xrange(n)]
        ant = [[False] * m for _ in xrange(n)]
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                if M[i][j] == 0:
                    continue
                if not row[i][j]:
                    k = j
                    while k < m and M[i][k] == 1:
                        row[i][k] = True
                        k += 1
                    ans = max(ans, k-j)
                if not col[i][j]:
                    k = i
                    while k < n and M[k][j] == 1:
                        col[k][j] = True
                        k += 1
                    ans = max(ans, k-i)
                if not dia[i][j]:
                    k, t = i, j
                    while k < n and t < m and M[k][t] == 1:
                        dia[k][t] = True
                        k += 1
                        t += 1
                    ans = max(ans, k-i)
                if not ant[i][j]:
                    k, t = i, j
                    while k < n and t >= 0 and M[k][t] == 1:
                        ant[k][t] = True
                        k += 1
                        t -= 1
                    ans = max(ans, k-i)
        return ans

