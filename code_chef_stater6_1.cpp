#include<bits/stdc++.h>
using namespace std;

class stats {
	public:
	    int run;
	    int wic;
	    int cat;
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        stats a, b;
        cin >> a.run >> a.wic >> a.cat;
        cin >> b.run >> b.wic >> b.cat;
        int count1 = 0, count2 = 0;
        if(a.run > b.run) {
            count1++;
        }
        else {
            count2++;
        }
        if(a.wic > b.wic) {
            count1++;
        }
        else {
            count2++;
        }
        if(a.cat > b.cat) {
            count1++;
        }
        else {
            count2++;
        }
        if(count1 > count2) {
        	cout << "A" << endl;
		}
		else {
			cout << "B" << endl;
		}
    }
    return 0;
}
