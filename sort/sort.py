
from typing import List

DATA = [89, 34, 23, 78, 67, 100, 66, 29, 79, 55, 78, 88, 92, 96, 96, 23]
SORTED = sorted(DATA)

def bubble(arr: List[int]):
    for lens_idx in range(len(arr) - 1, 0, -1):
        for idx in range(lens_idx):
            if arr[idx] > arr[idx + 1]:
                arr[idx], arr[idx + 1] = arr[idx+1], arr[idx]

    return arr
# print(bubble(DATA) == SORTED)

def insertion(arr: List[int]):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while (j >= 0 and arr[j] > key):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    
    return arr
# print(insertion(DATA) == SORTED)

def selection(arr: List[int]):
    for i in range(len(arr)):
        mini = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[mini]:
                mini = j
        
        arr[i], arr[mini] = arr[mini], arr[i]

    return arr
# print(selection(DATA) == SORTED)

def merge(arr: List[int]):
    new_arr = [0] * len(arr)

    def helper(left, right):
        if left >= right:
            return
        mid = (right + left) // 2
        helper(left, mid)
        helper(mid+1, right)
        
        idx = left
        i, j = left, mid + 1
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                new_arr[idx] = arr[i]
                i += 1
            else:
                new_arr[idx] = arr[j]
                j += 1
            idx += 1
        
        while i <= mid:
            new_arr[idx] = arr[i]
            i += 1
            idx += 1
        while j <= right:
            new_arr[idx] = arr[j]
            j += 1
            idx += 1
        
        arr[left: right+1] = new_arr[left: right+1]
    
    helper(0, len(arr) - 1)
    return arr
# print(merge(DATA) == SORTED)

def quick_sort(arr: List[int]):
    def find_pivot(left, right):
        pivot = (left + right) // 2
        if arr[left] <= arr[right]:
            if arr[pivot] <= arr[right]:
                return pivot if arr[left] <= arr[pivot] else left
            return right
        if arr[pivot] <= arr[right]:
            return right
        return pivot if arr[left] >= arr[pivot] else left
    
    def helper(left, right):
        if right <= left:
            return 
        pivot = find_pivot(left, right)

        p_val = arr[pivot]
        arr[pivot], arr[right] = arr[right], arr[pivot]
        curr_idx = left
        for idx in range(left, right):
            if arr[idx] <= p_val:
                arr[curr_idx], arr[idx] = arr[idx], arr[curr_idx]
                curr_idx += 1
        arr[curr_idx], arr[right] = arr[right], arr[curr_idx]
        helper(left, curr_idx-1)
        helper(curr_idx+1, right)
    
    helper(0, len(arr) - 1)
    return arr
print(quick_sort(DATA) == SORTED)