#include <iostream>
#include <stdexcept>

#include "database.h"

namespace Records
{
  Database::Database()
  {
    mNextSlot = 0;
    mNextEmployeeNumber = kFirstEmployeeNumber;
  }

  Database::~Database()
  {
  }

  Employee& Database::addEmployee(std::string inFirstName, std::string inLastName)
  {
    if (mNextSlot >= kMaxEmployees)
    {
      std::cerr << "There is no more room to add new employee!" << '\n';
      throw std::exception();
    }

    Employee& theEmployee = mEmployees[mNextSlot++];
    theEmployee.setFirstName(inFirstName);
    theEmployee.setLastName(inLastName);
    theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
    theEmployee.hire();

    return theEmployee;
  }

  Employee& Database::getEmployee(int inEmployeeNumber)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mEmployees[i].getEmployeeNumber() == inEmployeeNumber) {
        return mEmployees[i];
      }
    }
    std::cerr << "No employee with employee number " << inEmployeeNumber << '\n';
    throw std::exception();
  }

  Employee& Database::getEmployee(std::string inFirstName, std::string inLastName)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mEmployees[i].getFirstName() == inFirstName && mEmployees[i].getLastName() == inLastName) {
        return mEmployees[i];
      }
    }
    std::cerr << "No match with name " << inFirstName << " " << inLastName << '\n';
    throw std::exception();
  }

  void Database::displayAll()
  {
    for (int i = 0; i < mNextSlot; ++i) {
      mEmployees[i].display();
    }
  }

  void Database::displayCurrent()
  {
    for (int i = 0; i < mNextSlot; ++i) {
      if (mEmployees[i].getIsHired()) {
        mEmployees[i].display();
      }
    }
  }

  void Database::displayFormer()
  {
    for (int i = 0; i < mNextSlot; ++i) {
      if (!mEmployees[i].getIsHired()) {
        mEmployees[i].display();
      }
    }
  }
}