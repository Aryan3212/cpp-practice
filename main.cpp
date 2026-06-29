// #include <math.h>
// #include <string.h>
#include<iostream>
// #include<bits/stdc++.h> This is a header file that is only available on GNU GCC compiler.
// algorithms, containers, functions, iterators
// using namespace std;

void pattern1(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

void pattern2(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern3(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << j+1;
    }
    std::cout << "\n";
  }
}
void pattern4(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << i+1;
    }
    std::cout << "\n";
  }
}
// void pattern5(int n ) {
//   for (int i = n; i > 0; i--) {
//     for (int j = 0; j < i; j++) {
//       std::cout << "*";
//     }
//     std::cout << "\n";
//   }
// }
// void pattern6(int n ) {
//   for (int i = n; i > 0; i--) {
//     for (int j = 0; j < i; j++) {
//       std::cout << j + 1;
//     }
//     std::cout << "\n";
//   }
// }
void pattern5_idiomatic(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern6_idiomatic(int n ) {
  for (int i = 0; i <n; i++) {
    for (int j = 0; j < n - i; j++) {
      std::cout << j + 1;
    }
    std::cout << "\n";
  }
}
void pattern7(int n ) {
  for (int i = 0; i <n; i++) {
    for (int j1 = 0; j1 < n - i - 1; j1++) {
      std::cout << "-";
    }
    for (int j2 = 0; j2 < 2*(i + 1) - 1; j2++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern8(int n ) {
  for (int i = 0; i <n; i++) {
    for (int j1 = 0; j1 < i; j1++) {
      std::cout << "-";
    }
    for (int j2 = 0; j2 < 2*(n-i) - 1; j2++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern9(int n ) {
  for (int i = 0; i <2*n; i++) {
    int spaces;
    int stars;
    if (i >= n) {
      spaces = i - n;
      stars = 2 * (2 * n - i) - 1;
    }
    else{
      stars = 2 * i + 1;
      spaces = n - i - 1;
    }
    for (int j1 = 0; j1 < spaces; j1++) {
      std::cout << "-";
    }
    for (int j2 = 0; j2 < stars; j2++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern9_symmetric(int n ) {
  for (int i = 0; i <2*n - 1; i++) {
    int spaces;
    int stars;
    if (i >= n) {
      spaces = i - n + 1;
      stars = 2 * (2 * n - i - 1) - 1;
    }
    else{
      stars = 2 * i + 1;
      spaces = n - i - 1;
    }
    for (int j1 = 0; j1 < spaces; j1++) {
      std::cout << "-";
    }
    for (int j2 = 0; j2 < stars; j2++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern10(int n ) {
  for (int i = 0; i <2*n - 1; i++) {
    int stars;
    if (i >= n) {
      stars = 2 * n - 1 - i;
    }
    else{
      stars = i + 1;
    }
    for (int j2 = 0; j2 < stars; j2++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}
void pattern11(int n ) {
  int pattern_flag = 1;
  for (int i = 0; i < n; i++) {
    pattern_flag = (i) % 2; // 0, 1, 0 ,1 // 1,0,1,0
    for (int j = 0; j <= i; j++) {
      std::cout << (j+1 + pattern_flag) % 2;
    }
    std::cout << "\n";
  }
}
void print_string(std::string a){
  std::cout << a;
}
int input_int(std::string message){
  int a;
  std::cout << message;
  std::cin >> a;
  std::cout << "\n";
  return a;
}
int main() {
  int num;
  while (true) {
    num = input_int("Enter number: ");
    if (num > 0) {
      // pattern1(num);
      // pattern2(num);
      // pattern3(num);
      // pattern4(num);
      // pattern5(num);
      // pattern6(num);
      // pattern5_idiomatic(num);
      // pattern6_idiomatic(num);
      // print_string("--------------------------------\n");
      // pattern7(num);
      // pattern8(num);
      // print_string("--------------------------------\n");
      // pattern9(num);
      // pattern9_symmetric(num);
      pattern10(num);
      print_string("--------------------------------\n");
      pattern11(num);
        } else {
      std::cout << "Invalid input\n";
      break;
    }
  }
  return 0;
}
