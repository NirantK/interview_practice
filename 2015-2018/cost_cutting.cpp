#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int salary[3];
		scanf("%d", &salary[0]);
		scanf("%d", &salary[1]);
		scanf("%d", &salary[2]);
		sort(salary, salary + 3);
		printf("Case %d: %d\n", t + 1, salary[1]);
	}
	return 0;
}