#include <bits/stdc++.h>
using namespace std;

int merge(int input[], int output[], int left, int mid, int right){
	int i, j, k, inversionCount = 0;

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

int mergeSort(int input[], int output[], int left, int right){
	int mid, inversionCount = 0;
	if (right > left) {
		mid = left+(right-left)/2;

		inversionCount = mergeSort(input, output, left, mid);
		inversionCount += mergeSort(input, output, mid + 1, right);

		inversionCount += merge(input, output, left, mid + 1, right);
	}
	return inversionCount;
}

int main(){
	int n, input[100000], output[100000], inversionCount;

	cin >> n;
	for(int i=0; i<n; i++)
        cin >> input[i];

	inversionCount = mergeSort(input, output, 0, n-1);

	for(int i=0; i<n; i++)
        cout << output[i] << " ";
    cout << endl;


	cout << inversionCount << endl;
	return 0;
}


