#include <vector>
using namespace std;

// The element in arr is unique.
int bs_1(vector<int> & arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return -1;
}

// not unique
int bs_2(vector<int> & arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return arr[left] == target? left: -1;
}

int main() {
    return 0;
}