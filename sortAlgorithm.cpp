#include <utility>
#include <vector>
#include <iostream>

using namespace std;

void print_vector(const vector<int>& nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


// O(n^2): bubble sort, selection sort, insertion sort
void bubble_sort(vector<int> nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < nums.size() - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
    cout << "The result of bubble sort:\n    ";
    print_vector(nums);
}

void selection_sort(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        swap(nums[i], nums[min_index]);
    }
    cout << "The result of selection sort:\n    ";
    print_vector(nums);
}

void insertion_sort(vector<int> nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int key = nums[i];      // the element to insert
        int j = i - 1;
        while (j >= 0 and nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
    cout << "The result of insertion sort:\n    ";
    print_vector(nums);
}

// O(nlog(n)): quick sort, heap sort, merge sort
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];

    int i = low;
    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }
    swap(nums[i], nums[high]);
    return i;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

void quick_sort(vector<int> nums) {
    quickSort(nums, 0, nums.size() - 1);
    cout << "The result of quick sort:\n    ";
    print_vector(nums);
}


void heapify(vector<int>& nums, int n, int curr) {
    int largest = curr, left = 2 * curr + 1, right = 2 * curr + 2;

    if (left < n and nums[left] > nums[largest]) {
        largest = left;
    }
    if (right < n and nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != curr) {
        swap(nums[largest], nums[curr]);
        heapify(nums, n, largest);
    }
}

void heap_sort(vector<int> nums) {
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        heapify(nums, nums.size(), i);
    }

    for (int i = nums.size() - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
    cout << "The result of heap sort:\n    ";
    print_vector(nums);
}

void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = left; i <= mid; ++i) {
        L[i - left] = nums[i];
    }
    for (int i = mid + 1; i <= right; ++i) {
        R[i - mid - 1] = nums[i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 and j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            ++i;
        }
        else {
            nums[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        nums[k] = L[i];
        ++k; ++i;
    }
    while (j < n2) {
        nums[k] = R[j];
        ++k; ++j;
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

void merge_sort(vector<int> nums) {
    mergeSort(nums, 0, nums.size() - 1);
    cout << "The result of merge sort:\n    ";
    print_vector(nums);
}


int main() {
    vector<int> nums {64, 34, 25, 12, 22, 11, 90};
    bubble_sort(nums);
    selection_sort(nums);
    insertion_sort(nums);
    quick_sort(nums);
    heap_sort(nums);
    merge_sort(nums);
}
