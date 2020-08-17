// C++ program to
// sort array using
// pancake sort
#include <bits/stdc++.h>
using namespace std;

/* Reverses arr[0..i] */
void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

void rotateRight(int arr[], int start, int end)
{
    int endOrigin = arr[end];
    start++;

    while (start <= end)
    {
        arr[start] = arr[start-1];
        start++;
    }
    arr[start] = endOrigin;
}


void rotateLeft(int arr[], int start, int end)
{
    int startOrigin = arr[start];
    end--;

    while (end >= start)
    {
        arr[end] = arr[end+1];
        end--;
    }
    arr[end] = startOrigin;
}

// Returns index of the
// maximum element in
// arr[0..n-1]
int findMax(int arr[], int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

int pancakeSort(int *arr, int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        int mi = findMax(arr, curr_size);
        if (mi != curr_size - 1)
        {
            flip(arr, mi);
            flip(arr, curr_size - 1);
        }
    }
}

// A utility function to print
// n array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// Driver program to test above function
int main()
{
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    pancakeSort(arr, n);

    cout << "Sorted Array " << endl;
    printArray(arr, n);

    return 0;
}

//This code is contributed by rathbhupendra
