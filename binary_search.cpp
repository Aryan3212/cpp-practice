#include<iostream>
int DEBUG = 0;
// [0]
// [1]
// [2]
// [1,2]
// [6,7,8]
// [9,10,15,15,16]
// 0 [1,1,1,1,2,2,2,3,3,3,4] 10
// 5, 2, l = 5
// 5..10, 7=3, r = 7
// 5..7, 6=2, l=6 + 1
// 7..7, 6=2, l=6 
// l == r, l <=x, r>x
// <x and all items to right are >=x.
// 12 invariant: index/pos where
// lb:all numbers left < x for sure no numbers can be equal to x
// all numbers right >= x, no numbers should be less than x
// ub:all numbers left <= x, can be less than or equal to x
// all numbers right > x, for sure all numbers should be greater than x

int upper_bound (int x, int nums[], int n) {
    /*
        What is the __latest__ position of the number that x < all numbers after it;
        Where can I insert x, so that all following numbers after are greater than it and all elems
        are <=.
    */
    int l = 0;
    int r = n;
    int mid = l + (r - l) / 2;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (DEBUG) {
            std::cout << "l=" << l
            << " r=" << r
            << " mid=" << mid
            << '\n';
            std::cout << "nums[mid]=" << nums[mid] << '\n';
            std::cout << "------------------------\n";
        }
        if (nums[mid] > x) {
            r = mid;
        } else if (nums[mid] <= x) {
            l = mid + 1;
        }
    }
    return l;
}
int lower_bound (int x, int nums[], int n) {
    int l = 0;
    int r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (DEBUG) {
        std::cout << "l=" << l
          << " r=" << r
          << " mid=" << mid
          << '\n';
          std::cout << "nums[mid]=" << nums[mid] << '\n';
          std::cout << "------------------------\n";
        }
        if (nums[mid] >= x) {
            r = mid;
        } else if (nums[mid] < x) {
            l = mid + 1;
        }

    }
    return l;
}
pair<int,int> equal_range(int x, int nums[], int n) {
    return {lower_bound(x, nums, n), upper_bound(x, nums, n)};
 }

int binary_search(int x, int nums[], int n) {
    int l = 0;
    int r = n - 1;
    int mid = l + (r - l) / 2;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (DEBUG) {
        std::cout << "l=" << l
          << " r=" << r
          << " mid=" << mid
          << '\n';
          std::cout << "nums[mid]=" << nums[mid] << '\n';
          std::cout << "------------------------\n";
        }
        if (nums[mid] > x) {
            r = mid - 1;
        } else if (nums[mid] < x) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int nums1[] = {1,2,3,4,4,4,4,4,4,4,5,6,7};
    int nums2[] = {-3, -3, -2, /*3*/0, 1,/*5*/6, /*6*/7, 
        /* 7 */40, 40, 40,
        /*10*/40, /*11*/41,51,
        /*13*/52,52,52,52,53,/*18*/54,54,54,54,54};
    int query;
    DEBUG = 1;
    while(true) {
        std::cout << "Enter a query: ";
        std::cin >> query;
        std::cout << "\n";
        std::cout << "----- BINARY SEARCH -------\n";
        // std::cout << binary_search(query, nums1, 13) << std::endl;
        // std::cout << binary_search(query, nums2, sizeof(nums2)/sizeof(nums2[0])) << std::endl;
        // std::cout << "----- LOWER BOUND -------\n";
        std::cout << lower_bound(query, nums2, sizeof(nums2)/sizeof(nums2[0]))<< std::endl;
        // std::cout << "----- UPPER BOUND -------\n";
        std::cout << upper_bound(query, nums2, sizeof(nums2)/sizeof(nums2[0]))<< std::endl;
    }
    return 0;
}