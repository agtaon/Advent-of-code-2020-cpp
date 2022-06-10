#include <iostream>

  int main() {
      int expense_report[200];
      for (int k=0; k<200; k++) {
          int input;
          std::cin >> input;
          expense_report[k] = input;
      }

      int value1, value2;

      for (int i=0; i<200; i++) {
        for (int j=i; j<200; j++) {
            if (expense_report[i] + expense_report[j] == 2020) {
                value1 = expense_report[i], value2 = expense_report[j];

            }

        }

      }
      std::cout << value1 * value2;
  }
