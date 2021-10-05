#include<bits/stdc++.h>
using namespace std;

void give_string(string str, int start, int end) {
    cout << end - start + 1 << endl;
	for(int i=start; i<=end; i++) {
        cout << str[i];
    }
}

void longest_palindrome(string str, int n) {
    if(n <= 1) {
        cout << n << endl << str;
        return;
    }
    int low, high, start = 0, max_length = 1;
    for(int i=1; i<n; i++) {
        low = i-1;
        high = i;
        while(str[low] == str[high] && low >=0 && high < n) {
            if(high-low+1 > max_length) {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
        low = i-1;
        high = i+1;
        while(str[low] == str[high] && low >= 0 && high < n) {
            if(high - low + 1 > max_length) {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
    }
    give_string(str, start, start+max_length-1);
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    longest_palindrome(str, n);
    return 0;
}
