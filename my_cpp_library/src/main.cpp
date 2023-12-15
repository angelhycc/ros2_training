#include "library_header.h"

int main() {
  SavingsAccount my_account("Holiday savings account", 555);
  std::string account_name = my_account.get_name();
  std::cout << "Account name: " << account_name << std::endl;

  return 0;
}