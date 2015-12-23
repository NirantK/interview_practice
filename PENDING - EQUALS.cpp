/*COLORFUL*/
// https://www.interviewbit.com/courses/programming/topics/hashing/problems/colorful/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define pb push_back 
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++) 

vector<int> equal(vector<int> &A) {
	// sum all possible combinations, store in a hash map
	// check each value in hashmap for more than 1 sum
	// merge and sort these lexicographically and return the smallest
	vi answer;
	if(A.size()<4)
		return answer;


	vvi answers;
	unordered_map <int, vi> hashtable;
	for (int i = 0; i < A.size()-1; ++i){
		// answer.clear();
		for (int j = i+1; j < A.size(); ++j){
			int sum = A[i] + A[j];
			if(hashtable.find(sum)==hashtable.end()){
				vi temp = {i, j}; // i < j always
				hashtable[sum] = temp;
			}
			else{
				// printf("%d\n", sum);
				vi existing = hashtable[sum];
				int a = existing[0], b = existing[1];
				int c = i, d = j;
				if((a != c) && (b!=d) && (b!=c)){
					answer.pb(a);
					answer.pb(b);
					answer.pb(c);
					answer.pb(d);
					// printf("%d, %d, %d, %d\n", a, b, c, d);
				// answers.pb(answer);

				}
				// sort(answer.begin(), answer.end());
			}
		}
	}
	// sort(answers.begin(), answers.end());
	return answer;
}


int main(int argc, char const *argv[]){
	vi input = {3, 4, 7, 1, 2, 9, 8};
	vi answer = equal(input);
	tr(answer, it){
		printf("%d, ", *it);
	}
	printf("\n");
	input = {1,1,1,1,1};
	answer = equal(input);
	// tr(answer, it){
	// 	printf("%d, ", *it);
	// }
	// printf("%d",colorful(326));
	// unordered_map<int, int>  umap ;
	// umap.insert ( {{5,10},{3,6}, {456, 789}} );
	// for (auto& x: umap)
	//     std::cout << x.first << ": " << x.second << std::endl;

	// for ( unsigned i = 0; i < umap.bucket_count(); ++i) {
 //    	std::cout << "bucket #" << i << " contains:";
 //    	for ( auto local_it = umap.begin(i); local_it!= umap.end(i); ++local_it )
 //      		std::cout << " " << local_it->first << ":" << local_it->second;
	//     std::cout << std::endl;
 //  }
	return 0;
}