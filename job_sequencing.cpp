#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

static bool JobCompare(Job s1, Job s2) {
    return s1.profit > s2.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr+n, JobCompare);
    int max_dead = arr[0].dead;
    for(int i=1; i<n; i++) {
        if(max_dead < arr[i].dead) {
            max_dead = arr[i].dead;
        }
    }
    int slot[max_dead] = {0};
    int count = 0, profit = 0, j;
    for(int i=0; i<n; i++) {
        j = arr[i].dead-1;
        while(slot[j] != 0) {
            j--;
            if(j < 0) {
                break;
            }
        }
        if(j > -1) {
            slot[j] = arr[i].profit;
            count++;
        }
    }
    for(int i=0; i<max_dead; i++) {
        profit += slot[i];
    }
    vector<int> v;
    v.push_back(count);
    v.push_back(profit);
    return v;
}

int main() {
    int n;
    cin >> n;
    Job arr[n];
    for(int i=0; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    vector<int> v =JobScheduling(arr, n);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
