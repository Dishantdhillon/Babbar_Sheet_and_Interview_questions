#include<iostream>
using namespace std;

class pair {
	public:
        int min;
        int max;
};

pair* get_min_max(int arr[], int n) {
    pair* min_max;
	min_max = new pair;
    min_max->min = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] < min_max->min) {
            min_max->min = arr[i];
        }
    }
    min_max->max = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] > min_max->max) {
            min_max->max = arr[i];
        }
    }
    return min_max;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    pair* min_max = new pair;
    min_max = get_min_max(arr, n);
    cout << "Minimum Element is " << min_max->min << endl; 
    cout << "Maximum Element is " << min_max->max;
    return 0;
}
