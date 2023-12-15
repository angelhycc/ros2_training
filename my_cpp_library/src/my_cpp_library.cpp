#include "library_header.h"

bool SavingsAccount::deposit(const float &amount) {
  balance_ += amount;
  // Amount deposited successfully
  return true;
}

bool SavingsAccount::withdraw(const float &amount) {
  if (amount <= balance_) {
    balance_ -= amount;
    return true;
  } else {
    // Insufficient balance
    return false;
  }
}

std::string SavingsAccount::get_name() { return account_name_; }

int SavingsAccount::get_account_number() { return account_nr_; }

float SavingsAccount::get_balance() { return balance_; }