#include <bits/stdc++.h> 
using namespace std; 

struct Sack { 
	float weight; 
	int profit;
}; 

// Node in State Space Tree
struct Node { 
	int level, profit, bound; 
	float weight;
}; 

// Comparison Function to sort Sacks based on profit per unit
bool compare(Sack a, Sack b) { 
	return ((double) a.profit / a.weight) > ((double) b.profit / b.weight); 
} 

// Returns bound of profit in subtree rooted with u. 
// This function mainly uses Greedy solution to find 
// an upper bound on maximum profit. 
int bound(Node u, int numberOfSacks, int knapsackCapacity, Sack sacks[]) { 
	// if weight overcomes the knapsack capacity, return 
	// 0 as expected bound 
	if (u.weight >= W) 
		return 0; 

	// initialize bound on profit by current profit 
	int profit_bound = u.profit; 

	// start including items from index 1 more to current 
	// item index 
	int j = u.level + 1; 
	int totweight = u.weight; 

	// checking index condition and knapsack capacity 
	// condition 
	while ((j < numberOfSacks) && (totweight + sacks[j].weight <= knapsackCapacity)) { 
		totweight += sacks[j].weight; 
		profit_bound += sacks[j].value; 
		j++; 
	} 

	// If k is not n, include last item partially for 
	// upper bound on profit 
	if (j < numberOfSacks) 
		profit_bound += (knapsackCapacity - totweight) * sacks[j].value / sacks[j].weight; 

	return profit_bound; 
} 

int solve(int knapsackCapacity, Sack sacks[], int numberOfSacks) { 
	sort(sacks, sacks+numberOfSacks, compare); 

	// make a queue for traversing the node 
	queue<Node> Q; 
	Node u, v; 

	// dummy node at starting 
	u.level = -1; 
	u.profit = u.weight = 0; 
	Q.push(u); 

	// One by one extract an item from decision tree 
	// compute profit of all children of extracted item 
	// and keep saving maxProfit 
	int maxProfit = 0; 
	while (!Q.empty()) { 
		// Dequeue a node 
		u = Q.front(); 
		Q.pop(); 

		// If it is starting node, assign level 0 
		if (u.level == -1) 
			v.level = 0; 

		// If there is nothing on next level 
		if (u.level == n-1) 
			continue; 

		// Else if not last node, then increment level, 
		// and compute profit of children nodes. 
		v.level = u.level + 1; 

		// Taking current level's item add current 
		// level's weight and value to node u's 
		// weight and value 
		v.weight = u.weight + arr[v.level].weight; 
		v.profit = u.profit + arr[v.level].value; 

		// If cumulated weight is less than W and 
		// profit is greater than previous profit, 
		// update maxprofit 
		if (v.weight <= W && v.profit > maxProfit) 
			maxProfit = v.profit; 

		// Get the upper bound on profit to decide 
		// whether to add v to Q or not. 
		v.bound = bound(v, numberOfSacks, knapsackCapacity, sacks); 

		// If bound value is greater than profit, 
		// then only push into queue for further 
		// consideration 
		if (v.bound > maxProfit) 
			Q.push(v); 

		// Do the same thing, but Without taking 
		// the item in knapsack 
		v.weight = u.weight; 
		v.profit = u.profit; 
		v.bound = bound(v, numberOfSacks, knapsackCapacity, sacks); 
		if (v.bound > maxProfit) 
			Q.push(v); 
	} 

	return maxProfit; 
} 

int main() { 
	int knapsackCapacity, numberOfSacks;
	cout << "Enter Knapsack Capacity:" << endl;
	cin >> knapsackCapacity;
	cout << "Enter Number of Sacks:" << endl;
	cin >> numberOfSacks;

	Sack sacks[numberOfSacks];
	cout << "Enter Details of " << numberOfSacks << " Sacks in Consecutive Lines:" << endl << "Weight Profit" << endl;
	for(int i=0; i<numberOfSacks; i++) cin >> sacks[i].weight >> sacks[i].profit;

	// int W = 10; 
	// Sack arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, 
	// 			{5, 95}, {3, 30}}; 

	cout << "Maximum Achievable Profit:" << solve(knapsackCapacity, sacks, numberOfSacks) << endl; 

	return 0; 
} 