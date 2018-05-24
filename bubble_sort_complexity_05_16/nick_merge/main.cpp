#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *A, int lo, int mid, int hi) {
	int i = lo;
	int j = mid + 1;
	int k = lo;
	int B[100];


	while (i <= mid && j <= hi) {
		if (A[i] <= A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}


		k++;
	}

	if (i>mid) {
		while (j <= hi) {
			B[k] = A[j];
			k++;
			j++;
		}
	}

	else {
		while (i <= mid) {
			B[k] = A[i];
			k++;
			i++;
		}
	}

	while (lo <= k) {
		A[lo] = B[lo];
		lo++;
	}

}

void MS(int *A, int lo, int hi) {
	int mid = (hi + lo) / 2;
	if (lo<hi) {
		MS(A, lo, mid);
		MS(A, mid + 1, hi);
		merge(A, lo, mid, hi);
	}
}


int main() {

	int A[100] = { 10,20,30,48,50,6,70,5,15,25 };
	int n = 10;
	MS(A, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%i\n", A[i]);
	}


}