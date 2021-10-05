#include<bits/stdc++.h>
using namespace std;

#define max 100000


int multiply(int res[], int x, int res_size) {
        int carry = 0;
        for(int i=0; i<res_size; i++) {
            int prod = res[i]*x + carry;
            res[i] = prod%10;
            carry = prod/10;
        }
        while(carry) {
            res[res_size] = carry%10;
            carry = carry/10;
            res_size++;
        }
        return res_size;
    }

    vector<int> factorial(int N){
        int res_size = 1, res[max];
        vector<int> vec;
        res[0] = 1;
        for(int x=2; x<=N; x++) {
            res_size = multiply(res, x, res_size);
        }
        for(int i=res_size-1; i>=0; i--) {
            vec.push_back(res[i]);
        }
        return vec;
    }

int main() {
    int n;
    cin >> n;
    vector<int> vec = factorial(n);
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i];
    }
    return 0;
}
