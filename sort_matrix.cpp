#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > sortedMatrix(int n, vector<vector<int> > Mat) {
    vector<int> result;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            result.push_back(Mat[i][j]);
        }
    }
    int k = 0;
    sort(result.begin(), result.end());
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Mat[i][j] = result[k++];
        }
    }
    return Mat;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > Mat(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> Mat[i][j];
        }
    }
    Mat = sortedMatrix(n, Mat);
    for(int i=0; i<n; i++) {
    	cout << "\n";
        for(int j=0; j<n; j++) {
            cout << Mat[i][j] << " ";
        }
    }
    return 0;
}
