#include<bits/stdc++.h>
using namespace std;

class Job{
	public:
    	int start, finish, profit;
};

int latestNonConflict(Job arr[], int n) {
	for(int j=n-1; j>=0; j--) {
		if(arr[j].finish <= arr[n-1].start) {
			return j;
		}
	}
	return -1;
}

int latestNonConflictBinarySearch(Job arr[], int n) {
	int low = 0, high = n-1;
	while(low <= high) {
		int mid = (low + high)/2;
		if(arr[mid].finish <= arr[n].start) {
			if(arr[mid+1].finish <= arr[n].start) {
				low = mid + 1;
			}
			else {
				return mid;
			}
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int maxProfitRec(Job arr[], int n) {
    if(n == 1) {
        return arr[n-1].profit;
    }
    int i = latestNonConflict(arr, n-1);
    int incl = arr[n-1].profit;
    int excl;
    if(i != -1) {
        incl = incl + maxProfitRec(arr, i+1);
    }
    else {
        excl = maxProfitRec(arr, n-1);
    }
    return max(incl, excl);
}

int maxProfit(Job arr[], int n) {
    if(n == 1) {
        return arr[0].profit;
    }
    int table[n];
    table[0] = arr[0].profit;
    for(int i=1; i<n; i++) {
        int incl = arr[i].profit;
        int j = latestNonConflictBinarySearch(arr, i);
        if(j != -1) {
            incl = incl + table[j];
        }
        table[i] = max(table[i-1], incl);
    }
    return table[n-1];
}

bool comparator(Job a, Job b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;
    Job arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    }
    sort(arr, arr+n, comparator);
    cout << maxProfit(arr, n);
    return 0;
}
