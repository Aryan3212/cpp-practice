#include <string.h>
#include<iostream>
#include <algorithm>
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
void pattern2_reverse(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      std::cout << " ";
    }
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
void pattern5_reverse(int n ) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << " ";
    }
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
void pattern8_hollow(int n ) {
  for (int i = 0; i <n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << " ";
    }
    for (int j = 0; j < n - i; j++) {
      if (i == 0 || j == 0 || j == n - i - 1) {
        std::cout << "*";
        if (j != n - i - 1) {
          std::cout << " ";
        }
      } else {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
}
void pattern8_hollow_rightsideup(int n ) {
  for (int i = 0; i <n; i++) {
    for (int j = 0; j < n-i - 1; j++) {
      std::cout << " ";
    }
    for (int j = 0; j <= i; j++) {
      if (i == n - 1  || j == 0 || j == i) {
        std::cout << "*";
        if (j != i) {
          std::cout << " ";
        }
      } else {
        std::cout << "  ";
      }
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
// 1    1 |4 1      1 |6
// 12  21 |2 12    21 |4
// 123321 |0 123  321 |2
//        |  12344321 
// 

void pattern12(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << (j+1);
    }
    for (int j = 0; j < 2 * (n - i - 1); j++) {
      std::cout << "-";
    }
    for (int j = i; j >= 0; j--) {
      std::cout << (j+1);
    }
    std::cout << "\n";
  }
}
void pattern12_symmetric(int n) {
  int columns = 2 * n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < columns; j++) {
      if (j <= i) {
        std::cout << j + 1;
      } else if (j >= columns - i - 1) {
        std::cout << columns - j;
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
void pattern13_naive(int n ) {
  int last = 0;
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = 1; j <=i; j++) {
      std::cout << last + j << " ";
    }
    last = last + j - 1;
    std::cout << "\n";
  }
}
void pattern13(int n ) {
  for (int i = 1; i <= n; i++) {
    // AKA the sum of row numbers till last row
    // this gives us the number we should start with in this row
    int triangleNumber = ((i - 1) * i)/2;
    for (int j = 1; j <=i; j++) {
      std::cout << triangleNumber + j << " ";
    }
    std::cout << "\n";
  }
}
void pattern13WithLetters(int n ) {
  for (int i = 1; i <= n; i++) {
    int triangleNumber = ((i - 1) * i)/2;
    for (int j = 1; j <=i; j++) {
      std::cout << char(triangleNumber + j + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern14(int n ) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=i; j++) {
      std::cout << char(j + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern15(int n ) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=n - i + 1; j++) {
      std::cout << char(j + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern16(int n ) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=i; j++) {
      std::cout << char(i + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern16_inverted(int n ) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=n - i + 1; j++) {
      std::cout << char(i + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern17(int n ) {
  for (int i = 1; i <= n; i++) {
    int spaces = n - i;
    for (int j = 1; j <= spaces; j++) {
      std::cout << "-";
    }
    for (int j = 1; j <=2 * i - 1; j++) {
      if (j <= i) {
        std::cout << char(j + 64) << " ";
      } else {
        std::cout << char(2 * i - j + 64) << " ";
      }
    }
    std::cout << "\n";
  }
}
void pattern18(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=i; j++) {
      std::cout << char(n - i + j + 64) << " ";
    }
    std::cout << "\n";
  }
}
void pattern19(int n) {
  int size = 2 * n; // size of the diamond in length
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      int leftSide, rightSide;
      if (i <= n) {
        leftSide = n - i + 1;
        rightSide = n + i - 1;
      } else {
        leftSide = i - n;
        rightSide = size - i + n;
      }
      if (j <= leftSide || j > rightSide) {
        std::cout << "*";
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
void pattern19_gridzero_based(int n) {
  int size = 2 * n; // size of the diamond in length
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int leftSide, rightSide;
      if (i < n) {
        leftSide = n - i;
        rightSide = n + i; // 5,6,7,8,9
      } else {
        leftSide = i - n + 1;
        rightSide = size - i + n - 1; // 9,8,7,6,5 // 10,5, 
      }
      if (j < leftSide || j >= rightSide) {
        std::cout << "*";
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
void pattern19_pointydiamond(int n) {
  int size = 2 * n; // size of the diamond in length
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size + 1; j++) {
      int leftSide, rightSide;
      if (i <= n) {
        leftSide = n - i + 1;
        rightSide = n + i;
      } else {
        leftSide = i - n;
        rightSide = size - i + n + 1;
      }
      if (j <= leftSide || j > rightSide) {
        std::cout << "*";
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
void pattern20_gridzero_based(int n) {
  int size = 2 * n - 1; // size of the diamond in length
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size + 1; j++) {
      int leftSide, rightSide;
      if (i < n) {
        leftSide = i;
        rightSide = 2 * n - i - 1; // 5,6,7,8,9
      } else {
        leftSide = 2 * n - i - 2;
        rightSide = i + 1; // 9,8,7,6,5 // 10,5, 
      }
      if (j <= leftSide || j >= rightSide) {
        std::cout << "*";
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
 
template<typename F>
void pattern17_practice_numbers_version(int n, F f) {
  for (int i = 0; i < n; i++) {
    int spaces = n - i - 1; // 3
    int letters =  2 * i + 1;
    for (int j = 0; j < spaces; j++) {
      std::cout << " ";
    }
    // 1, 121, 12321, 1234321
    for (int j = 1; j <= letters; j++) {
      int mid = i + 1;
      std::cout << f(mid - abs(mid - j)); // mid - distance from mid
    }
    std::cout << "\n";
  }
}
//    1     0 1
//   121    1 2
//  12321   2 3
// 1234321  3 4
void pattern17_practice_numbers_version(int n) {
    pattern17_practice_numbers_version(n, [](int x) {
        return x;
    });
}
template<typename F>
void pattern17_numreverse(int n, F f) {
  for (int i = 0; i < n; i++) {
    int spaces = n - i - 1; // 3
    int letters =  2 * i + 1;
    for (int j = 0; j < spaces; j++) {
      std::cout << " ";
    }
    // 1, 121, 12321, 1234321
    for (int j = 1; j <= letters; j++) {
      int mid = i + 1;
      std::cout << f(abs(mid - j) + 1); // distance from mid + 1(offset since we're printing 1)
    }
    std::cout << "\n";
  }
}
void pattern17_numreverse(int n) {
    pattern17_numreverse(n, [](int x) {
        return x;
    });
}

void pattern20(int n) {
  int size = 2 * n; // size of the diamond in length
  for (int i = 1; i < size; i++) {
    for (int j = 1; j <= size; j++) {
      int leftSide, rightSide;
      if (i <= n) {
        leftSide = i;
        rightSide = size - i;
      } else {
        leftSide = size - i;
        rightSide = i;
      }
      if (j <= leftSide || j > rightSide) {
        std::cout << "*";
      } else {
        std::cout << "-";
      }
    }
    std::cout << "\n";
  }
}
void pattern21(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == 1 || i == n) {
          std::cout << "*";
        } else if (j == 1 || j == n) {
          std::cout << "*";
        } else {
          std::cout << " ";          
        }
    }
    std::cout << "\n";
  }
}

void crazy_pattern22(int n) {
  for (int i = 1; i <= 2*n -1; i++) {
    int iValue;
    if (i <= n) iValue = n - i + 1;
    else iValue = i - n + 1;
    for (int j = 1; j <= 2*n -1 ; j++) {
      int jValue;
      if (j <= n) jValue = n - j + 1;
      else jValue = j - n + 1;
      if (iValue >= jValue) {
        std::cout << iValue;
      } else {
        std::cout << jValue;
      }
    }
    std::cout << "\n";
  }
}
void rhombus_pattern(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0;  j < i; j ++) {
      std::cout<< " ";
    }
    for (int j = 0; j < n; j ++) {
      std::cout<< "* ";
    }
    std::cout<< "\n\n";
  }
}

void diamond_pattern(int n) {
    int stars, spaces;
    for (int i = 0; i < 2*n - 1; i++) {
      if (i < n) {
        stars = i;
        spaces = n - i - 1;
      } else {
        stars = 2*(n - 1) - i;
        spaces = i - n + 1;
      }
      for (int j = 0;  j < spaces; j ++) {
        std::cout<< " ";
      }
      for (int j = 0; j <= stars; j ++) {
        std::cout<< "*";
        if (j != stars) std::cout<< " ";
      }
      std::cout<< "\n";
    }
  }
  void triangle_hollow_pattern(int n) {
    int stars, spaces;
    for (int i = 0; i < n; i++) {
      stars = i + 1;
      spaces = n - i - 1;
      for (int j = 0;  j < spaces; j ++) {
        std::cout<< " ";
      }
      for (int j = 0;  j < stars; j ++) {
        if (i == n - 1 || j == 0 || j == stars - 1) std::cout<< "*";
        else std::cout<< " ";
        if (j != stars - 1) std::cout << " ";
      }
      std::cout<< "\n";
    }
  }

  void pattern11_repeat(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0;  j <= i; j ++) {
        std::cout<< (j + i + 1) % 2;
      }
      std::cout<< "\n";
    }
  }
  void pattern12_repeat(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0;  j < 2*n; j ++) {
        if (j <= i) {
          std::cout << j + 1;  
        } else if (j >= 2*n - i - 1) {
          std::cout << 2 * n - j;
        } else {
          std::cout << " ";
        }
      }
      std::cout<< "\n";
    }
  }
  void pattern13_repeat(int n) {
    for (int i = 0; i < n; i++) {
      // triangle number sum of last i numbers
      int starting_number = (i * (i + 1)) / 2;
      for (int j = 0;  j <= i; j++) {
          std::cout << starting_number + j + 1 << " ";
      }
      std::cout<< "\n";
    }
  }
  void pattern21_repeat(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0;  j < n; j++) {
        if ( i == 0 || i == n - 1 || j == 0 || j == n -1) std::cout << "*";
        else std::cout << " ";
      } 
      std::cout<< "\n";
    }
  }
  void pattern22_repeat_my_soln(int n) {
    // map grid to a score, whichever score is higher according to the grid
    // co-ordinates gets printed, otherwise it's just a normal square with
    // 2 * n -1 side length
    // even with this solution problem is represented as the distance to the center
    // from any point so coordinate - center basically + 1 to offset if we say center is 0
    // but we output 1
    for (int i = 0; i < 2*n - 1; i++) {
      for (int j = 0;  j < 2*n - 1; j++) {
        int max_score, i_score, j_score;
        if(i < n) i_score = n - i;
        else i_score = i - n + 2;
        if(j < n) j_score = n - j;
        else j_score = j - n + 2;
        max_score = std::max(i_score, j_score);
        std::cout << max_score;
      } 
      std::cout<< "\n";
    }
  }

  
template <typename F>
void pattern18_p(int n, F f) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << f(n + j - i);
    }
    std::cout << "\n";
  }
}
void pattern18_p(int n) {
    return pattern18_p(n, [](int x) {
      return x;
    });
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
      // pattern10(num);
      // print_string("--------------------------------\n");
      // pattern11(num);
      print_string("--------------------------------\n");
      // pattern12_symmetric(num);
      // pattern13(num);
      // pattern13WithLetters(num);
      // pattern14(num);
      // print_string("--------------------------------\n");
      // pattern15(num);
      // pattern16(num);
      // pattern17(num);
      // pattern18(num);
      // pattern19(num);
      // print_string("--------------------------------\n");
      // pattern19_gridzero_based(num);
      // pattern20_gridzero_based(num);
      // pattern19_pointydiamond(num);
      // pattern20(num);
      // pattern21(num);
      // crazy_pattern22(num);
      // rhombus_pattern(num);
      // diamond_pattern(num);
      // pattern2_reverse(num);
      // pattern5_reverse(num);
      // pattern8_hollow(num);
      // pattern8_hollow_rightsideup(num);
      // triangle_hollow_pattern(num);
      // pattern11_repeat(num);
      // pattern12_repeat(num);
      // pattern13_repeat(num);
      // pattern21_repeat(num);
      // pattern22_repeat_my_soln(num);
      // pattern17_practice_numbers_version(num);
      // pattern17_practice_numbers_version(num, [](int x) {
      //   return static_cast<char>('A' + x - 1);
      // });
      pattern18_p(num, [](int x) {
        return static_cast<char>('A' + x - 1);
      });
      } else {
      std::cout << "Invalid input\n";
      break;
    }
  }
  return 0;
}
