#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Could not solve this on my own. Had to see the answer. Need to persist more*/


/*INTERVIEWBIT SOLUTION

int pow(int x, int n, int p) {
            if (n == 0) return 1 % p;

            long long ans = 1, base = x;
            while (n > 0) {
                // We need (base ** n) % p. 
                // Now there are 2 cases. 
                // 1) n is even. Then we can make base = base^2 and n = n / 2.
                // 2) n is odd. So we need base * base^(n-1) 
                if (n % 2 == 1) {
                    ans = (ans * base) % p;
                    n--;
                } else {
                    base = (base * base) % p;
                    n /= 2;
                }
            }
            if (ans < 0) ans = (ans + p) % p;
            return ans;
        }*/
            1

int main(void) {
	printf("%d\n", powermod(2,3,3)==2);
	printf("%d\n", powermod(-1,1,20));
	printf("%d\n", powermod(0,0,1)==0);
	// printf("%d\n", pow(71045970,  41535484, 64735492)==20805472);
}