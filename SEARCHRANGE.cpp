#include <vector>
using namespace std;
vector<int> searchRange(const vector<int> &A, int B) {
	int  l = 0, r = A.size()-1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(A[mid]>=B) r = mid - 1; //keep discarding the right half 
		//till you find the left most B
		else l = mid + 1;
	}
	int left = l;
	l = 0;
	r = A.size()-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(A[mid]>B) r = mid -1;  //discard till you are just bigger than
		//the right most B
		else l = mid+1;
	}
	int right = r;
	printf("left: %d, right: %d\n", left, right);
	if(A[left]!=B || A[right]!=B)
		left = - 1, right = -1;
	// why did this happen? 
	// if the element is not at the index, we change left to one element
	vector<int> v = vector<int> (left, right);
	// v[0] = left;
	// v[1] = right;
	return v;
}

int main(int argc, char const *argv[])
{
	vector <int> v = {5, 7, 7, 8, 8, 10};
	// vector <int> v = {1};
	std::vector <int> ret = searchRange(v, 8);
	printf("[%d, %d]\n", ret[0], ret[1]);
	return 0;
}