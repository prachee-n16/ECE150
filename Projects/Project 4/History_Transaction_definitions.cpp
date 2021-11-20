#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//Tested in first submission
Transaction::Transaction(std::string ticker_symbol, unsigned int day_date,
                         unsigned int month_date, unsigned year_date,
                         bool buy_sell_trans, unsigned int number_shares,
                         double trans_amount)
{
  this->symbol = ticker_symbol;
  this->day = day_date;
  this->month = month_date;
  this->year = year_date;
  this->shares = number_shares;
  this->amount = trans_amount;

  if (buy_sell_trans == true)
  {
    this->trans_type = "Buy";
  }
  else if (buy_sell_trans == false)
  {
    this->trans_type = "Sell";
  }
  this->trans_id = assigned_trans_id;
  assigned_trans_id++;
}

// Destructor
// TASK 1
Transaction::~Transaction()
{
}

// Overloaded < operator.
// TASK 2
bool Transaction::operator<(Transaction const &other)
{
  //2010 < 2021 return true
  if (this->year < other.year)
  {
    return true;
  }
  else if (this->year == other.year && this->month < other.month)
  {
    return true;
  }
  else if (this->year == other.year && this->month == other.month && this->day < other.day)
  {
    return true;
  }
  return false;
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true : false; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb(double acb_value) { acb = acb_value; }
void Transaction::set_acb_per_share(double acb_share_value) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance(unsigned int bal) { share_balance = bal; }
void Transaction::set_cgl(double value) { cgl = value; }
void Transaction::set_next(Transaction *p_new_next) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print()
{
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
            << std::setw(4) << get_symbol() << " "
            << std::setw(4) << get_day() << " "
            << std::setw(4) << get_month() << " "
            << std::setw(4) << get_year() << " ";

  if (get_trans_type())
  {
    std::cout << "  Buy  ";
  }
  else
  {
    std::cout << "  Sell ";
  }

  std::cout << std::setw(4) << get_shares() << " "
            << std::setw(10) << get_amount() << " "
            << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
            << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
            << std::setw(10) << std::setprecision(3) << get_cgl()
            << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 3
//Testing this function
History::History()
{
  p_head = nullptr;
}
// Destructor
// TASK 3
//Testing this function
History::~History() {}

// read_history(...): Read the transaction history from file.
// TASK 4
//Testing this function
void History::read_history()
{
}

// insert(...): Insert transaction into linked list.
// TASK 5
//Testing this function
void History::insert(Transaction *p_new_trans)
{
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//
void History::sort_by_date()
{
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl() {}

// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8
double History::compute_cgl(unsigned int year) { return 0; }

// print() Print the transaction history.
//TASK 9
//Testing this function
void History::print() {}

// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }