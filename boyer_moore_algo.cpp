#include<bits/stdc++.h>
using namespace std;

void bad_character_heuristic(string pattern, int bad_char[]) {
    int pat = pattern.length();
    for(int i=0; i<256; i++) {
        bad_char[i] = -1;
    }
    for(int i=0; i<pat; i++) {
        bad_char[(int) pattern[i]] = i;
    }
}

void search(string text, string pattern) {
    int pat = pattern.length();
    int txt = text.length();
    int bad_char[256];
    bad_character_heuristic(pattern, bad_char);
    int s = 0;
    while(s <= txt-pat) {
        int j = pat - 1;
        while(j >=0 && pattern[j] == text[s + j]) {
            j--;
        }
        if(j < 0) {
            cout << "Pattern found at shift " << s << endl;
            s = s + ((s+pat) < txt ? pat - bad_char[text[s+pat]] : 1);
        }
        else {
            s = s + max(1, j - bad_char[text[s+j]]);
        }
    }
}

int main() {
    string pattern, text;
    cin >> text;
    cin >> pattern;
    search(text, pattern);
    return 0;
}
