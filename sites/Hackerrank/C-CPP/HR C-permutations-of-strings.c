
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap (char *s, char *t){
    char *temp = s;
    s = t, t = temp;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/

	if (n == 1) return 0;

	for (int i = 0; i < n; i++) {
        next_permutation(n-1, s);
        if (n%2 == 1) swap(s[0], s[n-1]);
        else          swap(s[i], s[n-1]);
	}
}


int main (){
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
