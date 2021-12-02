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
// Tested in first submission
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
  this->trans_id = this->assigned_trans_id;
  this->assigned_trans_id++;

  this->p_next = nullptr;

  this->acb = 0;
  this->acb_per_share = 0;
  this->share_balance = 0;
  this->cgl = 0;
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
  // 2010 < 2021 return true
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
// Testing this function
History::History()
{
  this->p_head = nullptr;
}
// Destructor
// TASK 3
// Testing this function
History::~History()
{
  Transaction *p_temp{p_head};

  while (p_head != nullptr)
  {
    while (p_head->get_next() != nullptr)
    {
      p_temp = p_temp->get_next();
      p_head = p_temp;
    }
  }
  delete p_temp;
  p_temp = nullptr;
}

// read_history(...): Read the transaction history from file.
// TASK 4
// Testing this function
void History::read_history()
{
  // Transaction::Transaction(std::string ticker_symbol, unsigned int day_date,
  //   unsigned int month_date, unsigned year_date,
  //   bool buy_sell_trans, unsigned int number_shares,
  //   double trans_amount)

  ece150::open_file();
  // Transaction::Transaction(std::string ticker_symbol, unsigned int day_date,
  //                          unsigned int month_date, unsigned year_date,
  //                          bool buy_sell_trans, unsigned int number_shares,
  //                          double trans_amount)
  while (ece150::next_trans_entry() == true)
  {
    // ece150::next_trans_entry();
    Transaction *p_new_trans{new Transaction{ece150::get_trans_symbol(), ece150::get_trans_day(),
                                             ece150::get_trans_month(), ece150::get_trans_year(),
                                             ece150::get_trans_type(), ece150::get_trans_shares(), ece150::get_trans_amount()}};
    History::insert(p_new_trans);
  }
  ece150::close_file();
}

// insert(...): Insert transaction into linked list.
// TASK 5
// Testing this function
void History::insert(Transaction *p_new_trans)
{
  // execute on first call now
  if (this->p_head == nullptr)
  {
    this->p_head = p_new_trans; // point to transaction to insert
  }
  else
  {
    Transaction *p_next{p_head};

    while (p_next->get_next() != nullptr)
    {
      p_next = p_next->get_next();
    }
    p_next->set_next(p_new_trans);
  }
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//
void History::sort_by_date()
{
  {
    // std::cout << "Initializing Pointers..." << std::endl;
    Transaction *p_front{nullptr};
    Transaction *p_head_new{nullptr};
    // std::cout << "Initialized Pointers..." << std::endl;
    // Case not addressed at front

    // std::cout << "Entering While Loop" << std::endl;
    while (p_head != nullptr)
    {
      // std::cout << "Entered While Loop" << std::endl;
      // Isolate node
      p_front = p_head;
      p_head = p_head->get_next();
      p_front->set_next(nullptr);
      // std::cout << "Isolated node" << std::endl;
      // Insert first node into sorting list
      if (p_head_new == nullptr)
      {
        // std::cout << "First Node added into sorting list" << std::endl;
        p_head_new = p_front;
        p_front = nullptr;
      }

      // Insert later nodes into sorting lists
      else
      {
        // std::cout << "Adding later nodes into sorting list" << std::endl;
        if (*p_front < *p_head_new)
        {
          // std::cout << "If adding to front of list" << std::endl;
          p_front->set_next(p_head_new);
          p_head_new = p_front;
          // p_front -> (p_head_new)
          // p_head_new = p_front
          // p_head new = p_front --> p_head_new
        }
        else
        {
          // std::cout << "If adding to middle of list" << std::endl;
          Transaction *p_traverse{p_head_new};
          // std::cout << "Created p_traverse pointer" << std::endl;
          while (p_traverse->get_next() != nullptr)
          {
            // std::cout << "Came here" << std::endl;
            if ((*(p_traverse->get_next()) < *(p_front)))
            {
              // std::cout << "Going through linked list" << std::endl;
              p_traverse = p_traverse->get_next();
              // std::cout << "Gone through linked list" << std::endl;
            }
          }
          p_front->set_next(p_traverse->get_next());
          p_traverse->set_next(p_front);
          p_front = nullptr;
          p_traverse = nullptr;
        }
      }
    }
    p_head = nullptr;
    p_front = nullptr;
    p_head = p_head_new;
    p_head_new = nullptr;
  }
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl()
{
  Transaction *p_traverse{p_head};
  double balance{};
  double tot_shares{};
  double share_balance{};
  double acb_per_share{};
  double prev_acb_per_share{};
  double prev_share_balance{};
  double prev_balance{};

  while (p_traverse != nullptr) // while you havent gone through the entire list
  {

    if (p_traverse->get_trans_type() == true)
    {
      balance += p_traverse->get_amount();
      p_traverse->set_acb(balance);
      tot_shares += p_traverse->get_shares();
      p_traverse->set_share_balance(tot_shares);
      acb_per_share = p_traverse->get_acb() / p_traverse->get_share_balance();
      p_traverse->set_acb_per_share(acb_per_share);
    }
    else if (p_traverse->get_trans_type() == false)
    {
      // Subtract number of shares sold - (55*prev_acb_share)
      p_traverse->set_acb_per_share(prev_acb_per_share);
      double acb = p_traverse->get_acb_per_share();

      balance = prev_balance - (p_traverse->get_shares() * p_traverse->get_acb_per_share());
      p_traverse->set_acb(balance);

      tot_shares -= p_traverse->get_shares();
      p_traverse->set_share_balance(tot_shares);

      double CGL{p_traverse->get_amount() - (p_traverse->get_acb_per_share() * p_traverse->get_shares())};
      p_traverse->set_cgl(CGL);
    }
    prev_acb_per_share = p_traverse->get_acb_per_share();
    prev_balance = p_traverse->get_acb();
    prev_share_balance = p_traverse->get_share_balance();
    p_traverse = p_traverse->get_next();
  }
}

// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8
double History::compute_cgl(unsigned int year)
{
  Transaction *p_traverse{p_head};
  double prev_acb_share{};
  double CGL{};
  double prev_CGL{};
  while (p_traverse != nullptr)
  {
    if (p_traverse->get_year() == year)
    {
      if (p_traverse->get_trans_type() == false)
      {
        CGL += p_traverse->get_amount() - (prev_acb_share * p_traverse->get_shares());
      }
      prev_acb_share = p_traverse->get_acb_per_share();
    }
    p_traverse = p_traverse->get_next();
  }
  return CGL;
}

// print() Print the transaction history.
// TASK 9
// Testing this function
void History::print()
{
  std::cout << "========== BEGIN TRANSACTION HISTORY ============" << std::endl;
  Transaction *p_curr{p_head};

  while (p_curr->get_next() != nullptr)
  {
    p_curr->print();
    p_curr = p_curr->get_next();
  }

  std::cout << "========== END TRANSACTION HISTORY ============" << std::endl;
  p_curr = nullptr;
}

// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }