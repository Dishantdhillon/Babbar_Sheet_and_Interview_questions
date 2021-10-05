#include<bits/stdc++.h>
using namespace std;

bool search2d(vector<vector<char> > grid, string word, int row, int col) {
    int R = grid.size();
    int C = grid[0].size();
    int len = word.length();
    if(grid[row][col] != word[0]) {
        return false;
    }
    int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int dir=0; dir<8; dir++) {
        int k, rd = row + x[dir], cd = col + y[dir];
        for(k=1; k<len; k++) {
            if(rd>=R || rd<0 || cd>=C || cd<0) {
                break;
            }
            if(grid[rd][cd] != word[k]) {
                break;
            }
            rd = rd + x[dir];
            cd = cd + y[dir];
        }
        if(k == len) {
            return true;
        }
    }
    return false;
}

vector<vector<int> > searchWord(vector<vector<char> >grid, string word) {
	vector<vector<int> > output;
	for(int row = 0; row < grid.size(); row++) {
	    for(int col = 0; col < grid[0].size(); col++) {
	        if(search2d(grid, word, row, col)) {
	            output.push_back({row, col});
	        }
	    }
	}
	return output;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m, 'x'));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    string word;
    cin >> word;
    vector<vector<int> > output = searchWord(grid, word);
    for(int i=0; i<output.size(); i++) {
        for(int j=0; j<output[0].size(); j++) {
            cout << output[i][j];
        }
    }
}
