
#include <iostream>
#include <stdexcept>

#include "database.h"

using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main(int argc, char** argv)
{
  Database employeeDB;
  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
      case 1:
        doHire(employeeDB);
        break;
      case 2:
        doFire(employeeDB);
        break;
      case 3:
        doPromote(employeeDB);
        break;
      case 4:
        employeeDB.displayAll();
        break;
      case 5:
        employeeDB.displayCurrent();
        break;
      case 6:
        employeeDB.displayFormer();
        break;
      case 0:
        done = true;
        break;
      default:
        std::cerr << "Unknown command." << "\n";
    }
  }
  return 0;
}

int displayMenu()
{
  int selection;

  std::cout << '\n';
  std::cout << "Employee Database" << '\n';
  std::cout << "-----------------" << '\n';
  std::cout << "1) Hire a new employee" << '\n';
  std::cout << "2) Fire an employee" << '\n';
  std::cout << "3) Promote an employee" << '\n';
  std::cout << "4) List all employees" << '\n';
  std::cout << "5) List all current employees" << '\n';
  std::cout << "6) List all previous employees" << '\n';
  std::cout << "0) Quit" << '\n';
  std::cout << '\n';
  std::cout << "---> ";
  std::cin >> selection;
  return selection;
}

void doHire(Database& inDB)
{
  std::string firstName;
  std::string lastName;
  std::cout << "First name? ";
  std::cin >> firstName;
  std::cout << "Last name? ";
  std::cin >> lastName;
  try {
    inDB.addEmployee(firstName, lastName);
  } catch (std::exception ex) { 
    std::cerr << "Unable to add new employee!" << '\n';
  }
}

void doFire(Database& inDB)
{
  int employeeNumber;
  std::cout << "Employee number? ";
  std::cin >> employeeNumber;
  try {
    Employee& emp = inDB.getEmployee(employeeNumber);
    emp.fire();
    std::cout << "Employee " << employeeNumber << " has been terminated." << '\n';
  } catch (std::exception ex) {
    std::cerr << "Unable to terminate employee!" << '\n';
  }
}

void doPromote(Database& inDB)
{
  int employeeNumber;
  int raiseAmount;
  std::cout << "Employee number? ";
  std::cin >> employeeNumber;
  std::cout << "How much of a raise? ";
  std::cin >> raiseAmount;
  try {
    Employee& emp = inDB.getEmployee(employeeNumber);
    emp.promote(raiseAmount);
  } catch (std::exception ex) {
    std::cerr << "Unable to promote employee!" << '\n';
  }
}