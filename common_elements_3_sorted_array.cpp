// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:   
        
        vector <int> commonElementsBetweenTwo(int arr[], int brr[], int n, int m) {
            int i = 0, j = 0, l = 0, p = INT_MIN;
            int k = n < m ? n : m;
            vector <int> crr;
            while(i < n && j < m){
                if(arr[i] < brr[j]){
                    i++;
                }
                else if(arr[i] > brr[j]) {
                    j++;
                }
                else {
                    if(p != arr[i]){
                        crr.push_back(arr[i]);
                        i++;
                        j++;
                    }
                    else {
                        i++;
                        j++;
                    }
                    p = arr[i-1];
                }
            }
            return crr;
        }
        
        vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector <int> Crr = commonElementsBetweenTwo(A, B, n1, n2);
            int drr[Crr.size()];
            for(int i=0; i<Crr.size(); i++) {
                drr[i] = Crr[i];
            }
            return commonElementsBetweenTwo(drr, C, Crr.size(), n3);
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends