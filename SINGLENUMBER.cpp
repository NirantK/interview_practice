/*SINGLENUMBER*/
#include <cstdio>
#include <vector>
using namespace std;
int singleNumber(const vector<int> &nums) {
	int result = nums[0];
    for(int i = 1; i<nums.size(); ++i){
        printf("Before XOR: %d, ", result);
        result = result ^ nums[i];
        printf("After XOR with %d: %d\n", nums[i], result);
    }
    return result;
}

int main(int argc, char const *argv[]){
	vector<int> A = {5, 11, 5};
	printf("Final Answer:%d\n", singleNumber(A));
	return 0;
}