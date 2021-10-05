#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMinimumDifference(vector<string> a, vector<string> b) {
        vector<int> res;
        for(int i = 0; i < a.size(); i++) {
            res.push_back(getDifference(a[i], b[i]));
        }
        return res;
    }
    int getDifference(string a, string b) {
        vector<int> cnt(26, 0);
        int r = 0;
        if (a.size() != b.size())
            return -1;
        else {
            for (auto &c : a)
                cnt[c-'a']++;
            for (auto &c : b) {
                cnt[c-'a']--;
                if (cnt[c-'a']<0)
                    r++;
            }
            return r;
        }
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;
    vector<int> v = ob.getMinimumDifference(s1, s2);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}