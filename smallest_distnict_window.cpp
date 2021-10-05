#include<bits/stdc++.h>
using namespace std;

string findSubString(string str) {
    int dist_count = 0;
    bool visited[256] = { false };
    int n = str.length();
    for(int i=0; i<n; i++) {
        if(visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
        
    int count = 0, start = 0, start_index = -1, min_length = INT_MAX;
    int curr_count[256] = { 0 };
    for(int j=0; j<n; j++) {
        curr_count[str[j]]++;
        if(curr_count[str[j]] == 1) {
            count++;
        }
        if(count == dist_count) {
            while(curr_count[str[start]] > 1) {
                if(curr_count[str[start]] > 1) {
                    curr_count[str[start]]--;
                }
                start++;
            }
            int len_window = j - start + 1;
            if(min_length > len_window) {
                min_length = len_window;
                start_index = start;
            }
        }
    }
    return str.substr(start_index, min_length);
}

int main() {
    string str;
    cin >> str;
    cout << findSubString(str);
    return 0;
}