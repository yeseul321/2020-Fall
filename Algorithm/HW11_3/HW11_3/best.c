#include<stdio.h>
#define PQ_SIZE 20
typedef struct {
	int level;
	int profit;
	int weight;
	int bound;
}node;
int W = 9, n = 5, w[5] = { 2, 5, 7, 3, 1 }, p[5] = { 20, 30, 35, 12, 3 }, maxprofit = 0;
node PQ[PQ_SIZE]; //각 노드들을 모아놓은 배열
node u, v;


void best_first(void)
{
	int i;
	int best_bound;
	for (i = 0; i < PQ_SIZE; ++i)
	{
		PQ[i].level = -1;
		PQ[i].profit = -1;
		PQ[i].weight = -1;
		PQ[i].bound = -1;
	}
	v.level = 0, v.profit = 0, v.weight = 0, v.bound = bound(v);
	insert(PQ, v);
	while (1)
	{
		u.level = v.level + 1;
		u.profit = v.profit + p[u.level - 1];
		u.weight = v.weight + w[u.level - 1];
		u.bound = bound(u);
		if ((u.weight <= W) && (u.profit >= maxprofit))
			maxprofit = u.profit;

		if (bound(u) >= maxprofit)
			insert(PQ, u);

		u.weight = v.weight;
		u.profit = v.profit;
		u.bound = bound(u);
		if (u.bound >= maxprofit)
			insert(PQ, u);
		i = 0;
		while (PQ[i].level != -1) {
			++i;
		}
		i -= 1;
		v.level = PQ[i].level;
		v.profit = PQ[i].profit;
		v.weight = PQ[i].weight;
		v.bound = PQ[i].bound;
		remove(PQ, i);
		if (v.level == 5)
			break;
	}
}
int bound(node q)
{
	int j, k, totweight, bound;
	if (q.weight > W)
		return 0;
	else
	{
		bound = q.profit;
		j = q.level;
		totweight = q.weight;
		while ((j <= n) && (totweight + w[j] <= W))
		{
			totweight = totweight + w[j];
			bound = bound + p[j];
			++j;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight)*p[k] / w[k];
		return bound;
	}
}
int insert(node PQ[], node q)
{
	int i;
	node temp;
	for (i = 0; i < PQ_SIZE; ++i)
	{
		if (PQ[i].level == -1) {
			PQ[i] = q;
			break;
		}
	}
	i = 1;
	while (PQ[i + 1].level != -1)
	{
		if (PQ[i].bound > PQ[i + 1].bound)
		{
			temp = PQ[i];
			PQ[i] = PQ[i + 1];
			PQ[i + 1] = temp;
		}
		++i;
	}
}
int remove(node PQ[], int i)
{
	printf("Visited NODE = level : %2d  profit : %2d  weight : %2d\n\n", PQ[i].level, PQ[i].profit, PQ[i].weight);
	PQ[i].level = -1;
	PQ[i].profit = -1;
	PQ[i].weight = -1;
	PQ[i].bound = -1;
}

int main(void)
{
	int i = 0;
	printf("< Best-First-Search Knapsack Problem >\n");
	printf("Visited NODE = level : %2d  profit : %2d  weight : %2d (ROOT NODE)\n\n", 0, 0, 0);
	best_first();
	printf("Max Profit : %d\n", maxprofit);
	return 0;
}