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

int colorful(int A) {
	string copyA = to_string(A);
	// printf("%s", copyA.c_str());
	unordered_map <long long, bool> hashtable ;
	int len = copyA.size();
	for (int i = 0; i < len; ++i)
	{
		long long multiplication = 1;
		for (int j = i; j < len; ++j)
		{
			multiplication *= (long long)(copyA[j]-'0');
			// printf("%lld", (long long)(copyA[j]-'0'));
			if(hashtable.find(multiplication) != hashtable.end()) return 0;
            hashtable[multiplication] = true;
		}
		// printf("\n");

		// printf("%lld", (long long)(multiplication));

		// printf("\n");
	}
	return 1;
}


int main(int argc, char const *argv[]){
	printf("%d",colorful(326));
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