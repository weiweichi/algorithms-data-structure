#include <vector>
#include <string>
#include <iostream>
using namespace std;

class max_heap {
public:
    max_heap() {}
    max_heap(vector<int> &arr) {
        this->arr = arr;
        heapify();
    }

    void heapify() {
        vector<int> &arr = this->arr;
        for (int i = arr.size() / 2 - 1; i >= 0; --i)
            _sift(arr, i);
    }

    void _sift(vector<int> &arr, int idx) {
        int n = arr.size();
        while (1) {
            int child = idx * 2 + 1;
            if (child >= n)
                break;
            if (child + 1 < n && arr[child] < arr[child + 1])
                child++;
            if (arr[idx] < arr[child]) {
                swap(arr[idx], arr[child]);
                idx = child;
            } else {
                break;
            }
        }
    }

    void push(int value) {
        vector<int> &arr = this->arr;
        int idx = arr.size();
        arr.push_back(value);
        while (idx) {
            if (arr[(idx - 1) / 2] >= value)
                break;
            arr[idx] = arr[(idx - 1) / 2];
            idx = (idx - 1) / 2;
        }
        arr[idx] = value;
    }

    int pop() {
        vector<int> &arr = this->arr;
        int maxi = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        _sift(arr, 0);
        return maxi;
    }

    bool empty() {
        return this->arr.empty();
    }

    string print() {
        string res = "[";
        for (auto v: this->arr)
            res += to_string(v) + ", ";
        res.pop_back();
        res.pop_back();
        res += "]";
        return res;
    }

private:
    vector<int> arr;
};
int main() {
    max_heap m = max_heap();
    m.heapify();
    m.print();
}