def insertion_sort(arr):
    for i in range(len(arr)):
        newNum = arr[i]
        j = i -1
        while(j>=0 and arr[j]> newNum):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = newNum        
    return arr

res = insertion_sort([4, 3, 2, 10, 12, 1, 5, 6])
print(res)