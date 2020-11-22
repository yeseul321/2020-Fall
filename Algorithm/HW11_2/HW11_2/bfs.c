#include <stdio.h>
#include <stdlib.h>
#define W 9
#define Queue_Head = 1;

typedef struct Node {
	int level;
	int profit;
	int Weight;
}Node;

typedef struct Node_Chain {
	Node n;
	float bound;
}Node_chain;


int p[6] = { 0,20,30,35,12,3 };//pay of each object
int w[6] = { 0,2,5,7,3,1 };//weight of each object

Node Queue[999];
Node_chain Root_Queue[999]; //노드체인형변수 선언

int Queue_Tail = 1;
int Root_Queue_Tail = 1;

//Queue of Node
void Queue_Del() {
	Queue[Queue_Tail].Weight = 0;
}
Node Queue_Pop() {
	return Queue[--Queue_Tail];
}
void Queue_init() {
	Queue_Tail = 1;
}
void Queue_Insert(Node n) {
	Queue[Queue_Tail].Weight = n.Weight;
	Queue[Queue_Tail].level = n.level;
	Queue[Queue_Tail].profit = n.profit;
	Queue_Tail++;
}
//Root of Search
void Root_Queue_Insert(Node n, float bound) {
	Root_Queue[Root_Queue_Tail].n.Weight = n.Weight;
	Root_Queue[Root_Queue_Tail].n.level = n.level;
	Root_Queue[Root_Queue_Tail].n.profit = n.profit;
	Root_Queue[Root_Queue_Tail].bound = bound;
	Root_Queue_Tail++;
}
Node Root_Queue_Pop() {
	return Root_Queue[--Root_Queue_Tail].n;
}
void Root_Queue_init() {
	Root_Queue_Tail = 1;
}

//calculate bound
float Bound(Node n) {
	int j, k;
	int total_Weight;
	float result;
	if (n.Weight >= W) {
		return 0;
	}
	else {
		result = n.profit;
		j = n.level + 1;
		total_Weight = n.Weight;
		while ((j < 6) && ((total_Weight + w[j]) <= W)) {
			total_Weight += w[j];
			result += p[j];
			j++;
		}
		k = j;
		if (k < 6)
			result += (W - total_Weight)*p[k] / w[k];
	}
	return result;
}
//Breadth first knapsack
int Bound_Breadth_Knapsack() {
	Node u, v;
	Queue_init();
	v.level = 0;
	v.profit = 0;
	v.Weight = 0;
	u.level = 0;
	u.profit = 0;
	u.Weight = 0;
	int Max_profit = 0;
	int i = 0;
	Queue_Insert(v);
	while (!(Queue_Tail <= 1)) {
		v = Queue_Pop();
		Root_Queue_Insert(v, Bound(v));
		u.level = v.level + 1;
		u.profit = v.profit + p[u.level];
		u.Weight = v.Weight + w[u.level];
		if ((u.Weight <= W) && (u.profit > Max_profit)) {
			Max_profit = u.profit;
		}
		if (Bound(u) > Max_profit) Queue_Insert(u);
		u.Weight = v.Weight;
		u.profit = v.profit;
		if (Bound(u) > Max_profit) Queue_Insert(u);
	}
	return Max_profit;
}

int main(void) {
	int i;
	int Max;
	Max = Bound_Breadth_Knapsack();
	for (i = 1; i < Root_Queue_Tail; i++) {
		printf("level:%d      profit :%d       Weight : %d      Bound: %.1f\n",
			Root_Queue[i].n.level, Root_Queue[i].n.profit, Root_Queue[i].n.Weight, Root_Queue[i].bound);
	}
	printf("\n max : %d", Max);
}