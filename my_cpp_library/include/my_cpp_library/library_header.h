
#include <iostream>

class SavingsAccount {

public:
  SavingsAccount() = default;
  SavingsAccount(const std::string &name, const int &num)
      : account_name_(name), account_nr_(num) {}
    
  // deposit amount in the account
  bool deposit(const float &amount);

  // withdraw the amount from the account
  bool withdraw(const float &amount);

  // return account name
  std::string get_name();

  // return account number
  int get_account_number();

  // return account balance
  float get_balance();

private:
  std::string account_name_ = "Undefined";
  float balance_ = 0;
  int account_nr_ = 0;
};