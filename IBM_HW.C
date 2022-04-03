// Candidate: Michael Ravich , ID: 320912546
#include <stdio.h> 
#include <limits.h>
#include <stdbool.h>



int divide(int dividend, int divisor) {
	int result = 0;
	// update sign to -1 if at least one of the inputs is negative
	int sign = ((dividend < 0) || (divisor < 0)) ? -1 : 1;
	// Update dividend & divisor to their positive values
	dividend = abs(dividend);
	divisor = abs(divisor);
	// while dividend number larger than divisor, keep subtracting them and update result
	while (dividend >= divisor) {
		dividend -= divisor;
		++result;
	}
	if (sign == -1) result = -result; // update appropriate sign for result
	return result;
} 
bool checkForWin(int N1, int N2, int N3, int N4)
{
	return (N1 == 5 || N2 == 5 || N3 == 5 || N4 == 5); // check if at least one of the digits is 5 
}
int lengthOfLongestSubstring(char str[])
{
	int n = strlen(str); // save length of str
	int res = 0; // length of longest substring without repeating characters
	for (int i = 0; i < n; i++) {
		bool visited[256] = { false }; //  In order to indicate whether we have already seen this character in the sub string

		for (int j = i; j < n; j++) {
			if (visited[str[j]] == true) // already seen this char so break
				break;
			else {
				res = (res > j - i + 1) ? (res) : (j - i + 1); // return max between  (res) and  (j - i + 1)
				visited[str[j]] = true;  // update visited char index
			}
		}
		visited[str[i]] = false; // clear char index for outer loop
	}
	return res;
}


void main()
{
	// First question 
	printf("***First question***\n");
	printf("Dividend: %d, Divisior: %d ", 10, 3);
	printf("\nResult: %d\n", divide(10, 3));

	// Second question
	printf("\n***Second question***\n");
	printf("input: 2, 4, 6, 8\n");
	if (checkForWin(2, 4, 6, 8))
		printf("output: yes\n");
	else
		printf("output: no\n");
		
	printf("input: 4, 5, 6, 7\n");
	if (checkForWin(4, 5, 6, 7))
		printf("yes\n");
	else
		printf("no\n");

	// Third question
	printf("\n***Third question***\n");
	printf("input: abcabcbb\n");
	printf("output: %d", lengthOfLongestSubstring("abcabcbb"));
}
