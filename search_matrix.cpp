#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0]) {
            return 0;
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == target) {
                    return 1;
                }
                if(matrix[i][j] > target) {
                    break;
                }
            }
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0]) {
            return 0;
        }
        int i=0, j=n-1;
        while(i<n && j>=0) {
            if(matrix[i][j] == target) {
                return 1;
            }
            if(matrix[i][j] < target) {
            	i++;
            }
            else {
            	j--;
			}
        }
        return 0;
    }
};

int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<int> > matrix(m);
    int target;
    for(int i=0; i<m; i++) {
        matrix[i].assign(n, 0);
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    cin >> target;
    Solution obj;
    cout << obj.searchMatrix(matrix, target);
    return 0;
}
