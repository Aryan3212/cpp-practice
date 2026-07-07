#include<iostream>
int DEBUG = 0;
int equal_range(int x, int nums[]) {
    /*
        Difference between lower_bound and upper_bound of x. i.e. how many x's exist
    */
    return -1;
}
int upper_bound (int x, int nums[], int n) {
    /*
        What is the __latest__ position of the number that x < all numbers after it;
        Where can I insert x, so that all following numbers after are greater than it;
        mostly same as upper_bound but:
            if mid == x and l < r:
                there is more to the right to check as all elems before are less than x
                l = mid + 1

            return mid + 1 // mid is the index before the upper bound
    */
    int l = 0;
    int r = n - 1;
    int mid = l + (r - l) / 2;
    while (l <= r) {
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
        } else if (nums[mid] <= x) {
            l = mid + 1;
        }
    }
    return mid;
}
int lower_bound (int x, int nums[], int n) {
    /*
        What is the __earliest__ position of the number that x <= all numbers after it;
        Where can I insert x, so that all following numbers after are equal to or greater that it;
        invariants:
            if mid > x and l < r: 
                all right side is sure to be greater than x;
                left side needs to be checked;
                so r = mid - 1;
            if mid < x and l < r: 
                all left side is sure to be less than x;
                right side needs to be checked;
                so l = mid - 1;
            if mid == x:
                we found x, if l < r: then we still have to find the lower bound,
                and it should be on the left side. because all elems are >= x after.
                so r = mid - 1
                if ! l < r: then we already found the lower bound
            
            return mid - 1
    */
    int l = 0;
    int r = n - 1;
    int mid = l + (r - l) / 2;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (DEBUG) {
        std::cout << "l=" << l
          << " r=" << r
          << " mid=" << mid
          << '\n';
          std::cout << "nums[mid]=" << nums[mid] << '\n';
          std::cout << "------------------------\n";
        }
        if (nums[mid] >= x) {
            r = mid - 1;
        } else if (nums[mid] < x) {
            l = mid + 1;
        }

    }
    return mid;
}

int binary_search(int x, int nums[], int n) {
    int l = 0;
    int r = n - 1;
    int mid = l + (r - l) / 2;
    // 6
    while (l <= r) {
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
    // cases:
    // lower bound(100), lower_bound(-200), lb(1), lb(7), lb(4)
    //            0 1 2 3 4  5 6 7 8 9 10 11 12
    int nums1[] = {1,2,3,4,4,4,4,4,4,4,5,6,7};
    // lb(4), ub(4)
    int nums2[] = {1,2,3,5,6,7};
    // lb(1), ub(1)
    int nums3[] = {2,3,4,5,6,7};
    // lb(7), ub(7)
    int nums4[] = {-11,-12,33,44,52,61};
    int query;
    DEBUG = 1;
    while(true) {
        std::cout << "Enter a query: ";
        std::cin >> query;
        std::cout << "\n";
        std::cout << "----- BINARY SEARCH -------\n";
        std::cout << binary_search(query, nums1, 13) << std::endl;
        // std::cout << "----- LOWER BOUND -------\n";
        // std::cout << lower_bound(query, nums1, 13)<< std::endl;
        // std::cout << "----- UPPER BOUND -------\n";
        // std::cout << upper_bound(query, nums1, 13)<< std::endl;
    }
    return 0;
}