
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
    return new_arr
# print(merge(DATA) == SORTED)

def quick(arr: List[int]):
    pass