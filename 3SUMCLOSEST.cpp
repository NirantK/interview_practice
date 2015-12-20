/*3SUMCLOSEST*/
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
// vector<int> reallyIntersect(const vector<int> &A, const vector<int> &B){
// 	return 0;
// }

int threeSumClosest(vi num, int target){
	if (num.size()<3)
		return 0;
	sort(num.begin(), num.end());
	int closest = num[0] + num[1] + num[2];
	int diff = target - closest;
	diff = (diff < 0) ? - diff : diff;
	int sz = num.size();
	for (int i = 0; i < sz-2; ++i){
		int a = num[i];
		int start = i+1;
		int end = sz-1;
		while(start < end){
			int sum = num[i] + num[start] + num[end];
            int newDiff = sum - target;
            newDiff = (newDiff < 0) ? - newDiff : newDiff;
            if (newDiff < diff) {
                diff = newDiff;
                closest = sum;
            }
            if (sum < target)
            	++start;
            else
            	--end;
		}		
	}
	return closest;
}

int main(int argc, char const *argv[]){
	vector<int> A = {-1 ,0, 1, 2, -1, -4};
	printf("%d", threeSumClosest(A, 0));
	// vvi::iterator row;
	// vector<int>::iterator col;
	// for (row = answer.begin(); row != answer.end(); ++row){
	// 	for(col = row->begin(); col != row->end(); ++col){
	// 		printf("%d ", *col);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}