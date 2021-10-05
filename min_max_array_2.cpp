#include<iostream>
using namespace std;

class pair {
    public:
        int min;
        int max;
};

pair* get_min_max(int arr[],int low, int high){
    pair* min_max, mml, mmr;
    min_max = new pair;
    if(n == 1){
        min_max->min = arr[0];
        min_max->max = arr[0];
        return min_max;
    }
    if(n == 2){
        if(arr[0] > arr[1]){
            min_max->min = arr[1];
            min_max->max = arr[0];
        }
        else{
            min_max->min = arr[0];
            min_max->max = arr[1];
        }
        return min_max;
    }
    int mid = (low + high)/2;
    mml = get_min_max(arr, low, mid);
    mmr = get_min_max(arr, mid+1, high);
    if(mml->min  < mmr->min){
        min_max->min = mml->min;
    }
    else{
        min_max->min = mmr->min;
    }
    if(mml->max > mmr->max){
        min_max->max = mml->max;
    }
    else{
        min_max->max = mmr->max;
    }
    return min_max;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    pair* output = new pair;
    output = get_min_max(arr, 0,n-1);
    cout << "Minimum Element is " << output->min << endl;
    cout << "Maximum Element is " << output->max; 
    return 0;
}