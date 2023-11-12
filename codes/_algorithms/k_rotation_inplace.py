def reverse_array(arr, start, end):
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1

def rotate_array_inplace(arr, k):
    n = len(arr)
    k = k % n

    print("Original array:", arr)

    reverse_array(arr, 0, n - 1)
    print("After reversing entire array:", arr)

    reverse_array(arr, 0, k - 1)
    print("After reversing subarray before rotation point:", arr)

    reverse_array(arr, k, n - 1)
    print("After reversing subarray after rotation point:", arr)

arr = [5, 6, 7, 1, 2, 3, 4]
rotate_array_inplace(arr, 4)
print("Final rotated array:", arr)
