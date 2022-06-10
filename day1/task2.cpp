#include <iostream>

  int main() {
      int expense_report[200];
      for (int k=0; k<200; k++) {
          int input;
          std::cin >> input;
          expense_report[k] = input;
      }

      int value1, value2, value3;

      for (int i=0; i<200; i++) {
        for (int j=i; j<200; j++) {
                for (int m=j; m<200; m++) {
                    if (expense_report[i] + expense_report[j] + expense_report[m] == 2020) {
                        value1 = expense_report[i], value2 = expense_report[j], value3 = expense_report[m];

                        }

                    }


        }

      }
      std::cout << value1 * value2 * value3;
  }
