#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    int mid;
    while(low <= high) {
        mid = (low + high)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] >= nums[low]){
            if(target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(target <= nums[high] && target >= nums[mid]) {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;
    cout << search(v, target);
}
