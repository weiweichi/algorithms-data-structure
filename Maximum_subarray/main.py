
arr = [7, -7, 8, 9, -10, 12, -1000, 11, -7]

# max subarray
def kadane(arr):
    assert len(arr), f"expected array length > 0, but got {len(arr)}"

    res = arr[0]
    curr = 0
    for val in arr:
        curr = max(val, curr + val)
        res = max(res, curr)
    return res
# print(kadane(arr))

# maximum subarray with length smaller or equal than k
def max_sum_subarray_with_lens_k(arr, k):
    curr = arr[0]
    res = arr[0]
    left = 0
    for right in range(1, len(arr)):
        val = arr[right]
        if val >= curr + val:
            curr = val
            left = right
        else:
            curr += val
        
        if right - left >= k:
            curr -= arr[left]
            left += 1
            while left < right:
                if curr - arr[left] >= curr:
                    curr -= arr[left]
                    left += 1
                else:
                    break
        
        res = max(res, curr)
    return res
# arr = [8, -7, 8, 9, -10, 12, -1000, 11, 10]
# print(max_sum_subarray_with_lens_k(arr, 5)) # res = 21
# arr = [3, -7, 8, 9, -10, 12, -1000, 11, 2]
# print(max_sum_subarray_with_lens_k(arr, 5)) # res = 19
# print(max_sum_subarray_with_lens_k(arr, 3)) # res = 17
# arr = [-1, 9, -4, 3, 1000, -100, -10000, -1]
# print(max_sum_subarray_with_lens_k(arr, 5)) # res = 1008
# print(max_sum_subarray_with_lens_k(arr, 3)) # res = 1003

def max_sum_circular_subarray(arr):
    sums = mini = maxi = curr_maxi = curr_mini = arr[0]
    
    for val in arr[1:]:
        curr_maxi = max(curr_maxi + val, val)
        maxi = max(maxi, curr_maxi)
        curr_mini = min(curr_mini + val, val)
        mini = min(mini, curr_mini)
        sums += val
    return maxi if sums == mini else max(maxi, sums - mini)
arr = [5,-3,5]
print(max_sum_circular_subarray(arr))