

# values in arr are unique
# return index if found else -1
def Binary_Search_1(arr: list, target: int):
    left, right = 0, len(arr)

    while left < right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    return -1

# There are duplicate values in arr
# Find the most left one
def Binary_search_2(arr: list, target: int):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    
    return -1 if arr[left] != target else left