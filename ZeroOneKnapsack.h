/*Knapsack Problem*/

wt[] = {10, 20, 30};
val[] = {60, 100, 120};
W = 50;

int ZeroOneKnapsack(int W, int wt[], int val[], int n)
{
	int i, w;
	int k[n+1][W+1];
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
			{
				k[i][w] = 0;//we care about i = 1 and further;
			}

			else if (wt[i - 1] <= W)//discarding weights greater than 50
			{
				k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]); //adding values in val[] if their corresponding weights add up to <= 50
			}

			else
			{
				k[i][w] = k[i - 1][w];
			}
		}
	}
	return k[n][W];
}