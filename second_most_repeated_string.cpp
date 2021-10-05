#include<bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n) {
    string output;
    unordered_map<string, int> map;
    for(int i=0; i<n; i++) {
        map[arr[i]]++;
    }
    int first_max = INT_MIN, second_max = INT_MIN;
    for(auto it=map.begin(); it != map.end(); it++) {
        if(it->second > first_max) {
            second_max = first_max;
            first_max = it->second;
        }
        else if(it->second > second_max && it->second != first_max){
            second_max = it->second;
        }
    }
    for(auto it=map.begin(); it != map.end(); it++) {
        if(it->second == second_max) {
            return it->first;
        }
    }
}

int main() {
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    return 0;
}