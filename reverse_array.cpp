#include <iostream>
using namespace std;

void swap(int &a, int &b){
	b = a + b;
	a = b - a;
	b = b - a;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++){
    	if(i == n/2){
    		break;
		}
		else{
			swap(a[i], a[n-i-1]);
		}
	}
	for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
