/*3SUM*/
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

vvi threeSum(vi num){
	vvi result;
	if (num.size()<3)
		return result;
	sort(num.begin(), num.end());
	// int s = num[0] + num[1] + num[2];
	// int diff = target - s;
	// diff = (diff < 0) ? - diff : diff;
	int sz = num.size();
	for (int i = 0; i < sz-2; ++i){
		int a = num[i];
		int start = i+1;
		int end = sz-1;
		while(start < end){
			int b = num[start];
			int c = num[end];
			int s = a + b + c;
			if(s==0){
				vi temporary;
				temporary.push_back(a);
				temporary.push_back(b);
				temporary.push_back(c);
				// tr(temporary, it){
				// 	printf("%d\n", *it);
				// }
				result.push_back(temporary);
				// printf("b= %d, num[start]=%d, start=%d\n", b, num[start], start);

				// --end;
				// ++start;

				while(++start < sz && num[start]==num[start-1]){
				// printf("b= %d, num[start]=%d, start=%d\n", b, num[start], start);
					// ++start;
				}
				while(--end >=0 && num[end]==num[end+1]){
					// --end;
					// printf("c= %d\n", c);
				}
			}
			else if(s > 0)
				--end;
			else
				++start;
		}
		while (i+1 < num.size() && num[i] == num[i+1])
	        i++;
	}
	return result;
}

int main(int argc, char const *argv[]){
	vector<int> A = {-1 ,0, 1, 2, -1, -4};
	vvi answer  = threeSum(A);
	vvi::iterator row;
	vector<int>::iterator col;
	for (row = answer.begin(); row != answer.end(); ++row){
		for(col = row->begin(); col != row->end(); ++col){
			printf("%d ", *col);
		}
		printf("\n");
	}
	return 0;
}