#include <bits/stdc++.h>
using namespace std;

long long int merge(long long int input[], int left, int mid, int right){
	int i, j, k;
	long long int inversionCount = 0;
    long long int output[right];

	i = left;
	j = mid;
	k = left;

	while ((i <= mid - 1) && (j <= right)) {
		if (input[i] <= input[j])
			output[k++] = input[i++];
		else {
			output[k++] = input[j++];
			inversionCount += (mid - i);
		}
	}

	while (i <= mid - 1)
		output[k++] = input[i++];

	while (j <= right)
		output[k++] = input[j++];

	for (i = left; i <= right; i++)
		input[i] = output[i];

	return inversionCount;
}

long long int mergeSort(long long int input[], int left, int right){
	int mid;
	long long int inversionCount = 0;

	if (right > left) {
		mid = left+(right-left)/2;

		inversionCount = mergeSort(input, left, mid);
		inversionCount += mergeSort(input, mid + 1, right);

		inversionCount += merge(input, left, mid + 1, right);
	}
	return inversionCount;
}

int main(){
	int t, n;
	long long int input[200100], inversionCount;

    cin >> t;
	while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> input[i];
        inversionCount = mergeSort(input, 0, n-1);
        cout << inversionCount << endl;
    }

	return 0;
}


