// C++ program to fin maximum cash flow among a set of persons
#include<bits/stdc++.h>
using namespace std;
#define K 100
#define L 100

// Number of persons (or vertices in the graph)

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[], int N)
{
	int minInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[], int N)
{
	int maxInd = 0;
	for (int i=1; i<L; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
	return (x<y)? x: y;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[], int *count, int N)
{
	// Find the indexes of minimum and maximum values in amount[]
	// amount[mxCredit] indicates the maximum amount to be given
	//				 (or credited) to any person .
	// And amount[mxDebit] indicates the maximum amount to be taken
	//				 (or debited) from any person.
	// So if there is a positive value in amount[], then there must
	// be a negative value
	int mxCredit = getMax(amount, N), mxDebit = getMin(amount, N);

	// If both amounts are 0, then all amounts are settled
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	// Find the minimum of two amounts
	int min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	// If minimum is the maximum amount to be
	*count = *count + 1;

	// Recur for the amount array. Note that it is guaranteed that
	// the recursion would terminate as either amount[mxCredit]
	// or amount[mxDebit] becomes 0
	minCashFlowRec(amount, count, N);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
int minCashFlow(int graph[K][L], int N)
{
	// Create an array amount[], initialize all value in it as 0.
	int amount[N] = {0};

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int p=0; p<K; p++)
	for (int i=0; i<L; i++)
		amount[p] += (graph[i][p] - graph[p][i]);
	int count = 0;
	minCashFlowRec(amount, &count, N);
	return count;
}

// Driver program to test above function
int main()
{
	// graph[i][j] indicates the amount that person i needs to
	// pay person j
	int n;
	cin >> n;
	int len, rec;
	double amt;
	string curr;
	map<int, int> mp;
	int graph[K][L] = {0};
	while(n--) {
		cin >> len >> rec >> amt >> curr;
		if(curr == "Rupees") {
			amt = amt * 0.013;
		}
		if(curr == "Euro") {
			amt = amt * 1.18;
		}
		if(mp.find(len) != mp.end()) {
            mp.insert({ len, 0 });
		}
		if(mp.find(rec) != mp.end()) {
            mp.insert({ rec, 0 });
    	}
		graph[len][rec] = amt;
	}
	// Print the solution
	int k=mp.size();
	cout << minCashFlow(graph, k) << endl;
	return 0;
}
