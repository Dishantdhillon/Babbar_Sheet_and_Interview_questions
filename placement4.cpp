#include <bits/stdc++.h>
using namespace std;

int countKdivPairs(int A[], int n, int K)
{
	int freq[K] = { 0 };

	for (int i = 0; i < n; i++)
		++freq[A[i] % K];

	int sum = freq[0] * (freq[0] - 1) / 2;
	for (int i = 1; i <= K / 2 && i != (K - i); i++)
		sum += freq[i] * freq[K - i];
	if (K % 2 == 0)
		sum += (freq[K / 2] * (freq[K / 2] - 1) / 2);
	return sum;
}

int main()
{

	int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
	int K = 60;
	cout << countKdivPairs(arr, n, K);
	return 0;
}
