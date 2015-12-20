/*PERMUTATION SEQEUENCE*/
/*https://leetcode.com/problems/permutation-sequence/*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 

class Solution {
public:
    int factorial(int n) {
        if (n > 12) {
            // this overflows in int. So, its definitely greater than k
            // which is all we care about. So, we return INT_MAX which
            // is also greater than k.
            return INT_MAX;
        }
        // Can also store these values. But this is just < 12 iteration, so meh!
        int fact = 1;
        for (int i = 2; i <= n; i++) fact *= i;
        return fact;
    }

    string getPermutation(int k, vector<int> &candidateSet) {
        int n = candidateSet.size();
        if (n == 0) {
        return "";
        }
        if (k > factorial(n)) return ""; // invalid. Should never reach here.

        int f = factorial(n - 1);
        int pos = k / f;
        k %= f;
        string ch = to_string(candidateSet[pos]);
        // now remove the character ch from candidateSet. 
        candidateSet.erase(candidateSet.begin() + pos);
        return ch + getPermutation(k, candidateSet);
    }
    
    string getPermutation(int n, int k) {
        vector<int> candidateSet; 
        for (int i = 1; i <= n; i++) candidateSet.push_back(i);
        return getPermutation(k - 1, candidateSet);
    }
};

int main(int argc, char const *argv[]){
	
	return 0;
}