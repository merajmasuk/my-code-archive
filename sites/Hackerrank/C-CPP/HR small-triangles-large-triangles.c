#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int a[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[l+i];
    for (int j = 0; j < n2; j++) R[j] = a[m+j+1];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k] = L[i], i++;
        else              a[k] = R[j], j++;
        k++;
    }

    while (i < n1) a[k] = L[i], i++, k++;
    while (j < n2) a[k] = R[j], j++, k++;
}

void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l  , m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
