def merge(arr, start, mid, end):
    temp = [0] * (end - start + 1)
    i = start
    j = mid + 1
    k = 0
    while i <= mid and j <= end:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1
    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1
    while j <= end:
        temp[k] = arr[j]
        j += 1
        k += 1
    for i in range(start, end + 1):
        arr[i] = temp[i - start]

arr = [5, 8, 2, 6, 1, 9]
merge(arr, 0, 2, 5)

print("Merged Array:")
print(arr)
