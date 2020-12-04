#include<iostream>
#include<stdio.h>
using namespace std;
int* merge(int* a, int* b, int n, int m) {
	int* c = new int[30];
	int i = 0, j = 0, k = 0;
	for (k = 0; k < n + m; k++) {
		if (i > n - 1) {
			int t = b[j];
			c[k] = t;
			j++;
		}
		else if (j > m - 1) {
			int t = a[i];
			c[k] = t;
			i++;
		}
		else if (a[i] < b[j]) {
			int t = a[i];
			c[k] = t;
			i++;
		}
		else {
			int t = b[j];
			c[k] = t;
			j++;
		}
	}
	return c;
}
int main() {
	int n, m;
	scanf_s("%d%d", &n, &m);
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		scanf_s("%d", &a[i]);
	int* b = new int[m];
	for (int i = 0; i < m; ++i)
		scanf_s("%d", b + i);
	int* res = merge(a, b, n, m);
	for (int i = 0; i < n + m; ++i) printf("%d ", res[i]);
}