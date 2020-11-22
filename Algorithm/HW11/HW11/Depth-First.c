#include <stdio.h> 

//max 함수 선언. 두 수중 최대값을 리턴시키는 함수
int max(int a, int b) 
{
	return (a > b) ? a : b;
}

int included[5] = { 0, };

//W만큼의 용량을 받을 수 있는 배낭에 넣을 수 있는 최대 가치
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[6][10];

	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w) {
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			}

			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	int val[] = { 20, 30, 35, 12, 3};
	int wt[] = { 2, 5, 7, 3, 1 };
	int W = 9;
	int n = sizeof(val) / sizeof(val[0]);
	printf("\nmaxprofit : %d\n", knapSack(W, wt, val, n));
	return 0;
}