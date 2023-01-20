#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void bubble_sort(vector<int> &arr) {
    for (int i = arr.size() - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[i])
                swap(arr[j], arr[i]);
        }
    }
    return ;
}

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int min_i = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_i])
                min_i = j;
        }
        swap(arr[i], arr[min_i]);
    }
}


void merge_sort(vector<int> &arr) {
    vector<int> new_arr = arr;
    function<void(int, int)> helper = [&](int left, int right) {
        if (left >= right)
            return;
        int mid = (right - left) / 2 + left;
        helper(left, mid);
        helper(mid+1, right);

        int idx = left, i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                new_arr[idx] = arr[i];
                i++;
            } else {
                new_arr[idx] = arr[j];
                j++;
            }
            idx++;
        }
        while (i <= mid) {
            new_arr[idx] = arr[i];
            i++, idx++;
        }
        while (j <= right) {
            new_arr[idx] = arr[j];
            j++, idx++;
        }
        for (i = left; i <= right; ++i) 
            arr[i] = new_arr[i];
    };
    helper(0, arr.size()-1);
}

void quick_sort(vector<int> &arr) {
    auto find_pivot = [&](int left, int right) {
        int pivot = (right - left) / 2 + left;
        if (arr[left] <= arr[right]) {
            if (arr[pivot] <= arr[right])
                return arr[left] <= arr[pivot] ? pivot: left;
            return right;
        } 
        if (arr[pivot] <= arr[right])
            return right;
        return arr[left] >= arr[pivot] ? pivot: left;
    };
    function<void(int, int)> helper = [&](int left, int right) {
        if (right <= left)
            return;
        int pivot = find_pivot(left, right);

        int p_val = arr[pivot], curr_idx = left;
        swap(arr[pivot], arr[right]);
        for (int idx = left; idx < right; ++idx) {
            if (arr[idx] <= p_val) {
                swap(arr[curr_idx++], arr[idx]);
            }
        }
        swap(arr[curr_idx], arr[right]);
        helper(left, curr_idx - 1);
        helper(curr_idx+1, right);
    };
    helper(0, arr.size()-1);
}

int main() {
    vector<int> DATA = {89, 34, 23, 78, 67, 100, 66, 29, 79, 55, 78, 88, 92, 96, 96, 23};
    vector<int> DATA2 = DATA;
    // bubble_sort(DATA);
    // insertion_sort(DATA);
    // selection_sort(DATA);
    // merge_sort(DATA);
    quick_sort(DATA);
    sort(DATA2.begin(), DATA2.end());
    bool flag = true;
    for (int i = 0; i < DATA.size(); ++i) {
        if (DATA[i] != DATA2[i]) {
            flag = false;
            break;
        }
    }
    flag ? cout<<"true": cout<<"false";
    return 0;
}
