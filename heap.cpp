#include <iostream>
#include <vector>
#include <functional>

void swim_down(std::vector<int>& arr, int i, std::function<bool(int, int)> comp) {
  int size = arr.size();
  while (true) {
    int left_c = 2*i + 1;
    int right_c = 2*i + 2;
    int candidate = i;

    if (left_c < size && comp(arr[left_c], arr[candidate]))
      candidate = left_c;
    if (right_c < size && comp(arr[right_c], arr[candidate]))
      candidate = right_c;

    if (candidate == i) break;
    std::swap(arr[i], arr[candidate]);
    i = candidate;
  }
}

void swim_up(std::vector<int>& arr, int i, std::function<bool(int, int)> comp) {
  // integer division floors toward zero, so (i-1)/2 gives the parent index
  int parent = (i - 1) / 2;
  while (comp(arr[i], arr[parent])) {
    std::swap(arr[i], arr[parent]);
    i = parent;
    parent = (i - 1) / 2;
  }
}

void make_heap(std::vector<int>& arr, std::function<bool(int, int)> comp) {
  int size = arr.size();
  // start from the last non-leaf node and swim each down
  for (int i = size / 2 - 1; i >= 0; i--) {
    swim_down(arr, i, comp);
  }
}

void insert(std::vector<int>& arr, int value, std::function<bool(int, int)> comp) {
  // add to last empty slot, then swim it up
  arr.push_back(value);
  int i = arr.size() - 1;
  swim_up(arr, i, comp);
}

int extract(std::vector<int>& arr, std::function<bool(int, int)> comp) {
  // remove root, replace with last element, swim the new root down
  int root = arr[0];
  arr[0] = arr.back();
  arr.pop_back();
  swim_down(arr, 0, comp);
  return root;
}

void print_vector(std::vector<int>& arr) {
  for (auto i: arr) {
    std::cout << i << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::function<bool(int, int)> comp = std::greater<int>{};
  std::vector<int> arr = {5,64,7,1,2,3,5,45,6,-1};
  make_heap(arr, comp);
  print_vector(arr);
  int ext = extract(arr, comp);
  std::cout << ext << "\n";
  insert(arr, -200, comp);
  insert(arr, 30, comp);
  insert(arr, -300, comp);
  print_vector(arr);
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  ext = extract(arr, comp);
  std::cout << ext << "\n";
  print_vector(arr);
  return 0;
}









