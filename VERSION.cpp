/*VERSION*/
/*UNSOLVED*/
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
typedef vector<unsigned long long> vi; 
typedef vector<vi> vvi; 
// typedef pair<int,int> ii; 
#define all(c) (c).begin(),(c).end() 
#define tr(container, it) for( auto it = container.begin(); it != container.end(); it++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
vi split(const string &s, char delim){
	stringstream ss(s);
	string item;
	unsigned long long t = 0;
	vi temporary;
	while(getline(ss, item, delim)){
		// printf("%s\n", item);
		stringstream ss_item(item);
		ss_item >> t;
		temporary.push_back(t);
	}
	return temporary;
}

vi largeNumbers(const string &a, const string &b){
	int sizeA = a.size();
	int sizeB = b.size();
	int i;
	for (i= 0; i < min(sizeA, sizeB); ++i){
		if(a[i]!=b[i]){
			return -1;
		}
	}
}


int compareVersion(std::string A, std::string B){

	vi v1 = split(A, '.');
	vi v2 = split(B, '.');
	vi d1 = v1;
	vi d2 = v2;
	int n1 = d1.size();
	int n2 = d2.size();
	 
	for (int i=0;i<min(n1,n2);i++){
		printf("%d\t%d", d1[i], d2[i]);
		if (d1[i]>d2[i]){ return 1;}
		if (d1[i]<d2[i]){ return -1;}
	}
	
	if (n1<n2){
		for (int i=n1;i<n2;i++){
			if (d2[i]!=0){
				printf("%d\t",d2[i] );
				return -1;
			}
		}
		return 0;
	}
	if (n1>n2){
		for (int i=n2;i<n1;i++){
			if (d1[i]!=0){
				return 1;
			}
		}
		return 0;
	}
	if (n1==n2){
		return 0;
	}
	return 0;

} 

int main(int argc, char const *argv[]){
	printf("\nOutput:%d Expected:-1",compareVersion("444444444444444444444444", "4444444444444444444444444"));
	// printf("\nOutput:%d Expected:1",compareVersion("2.0", "1.0"));
	// printf("\nOutput:%d Expected:-1",compareVersion("1.1", "1.2"));
	// printf("\nOutput:%d Expected:0",lengthOfLastWord(""));

	return 0;
}