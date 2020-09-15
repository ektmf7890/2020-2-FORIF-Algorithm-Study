def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        
        # i와 min_index에 있는 값을 교환
        (arr[i], arr[min_index]) = (arr[min_index], arr[i])
    
    return arr

arr = [9, 6, 7, 3, 5]
selection_sort(arr)
print(arr)