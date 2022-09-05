// #include <iostream>

// #include "database.h"

// using namespace Records;

// int main(int argc, char** argv) {
//     Database myDB;

//     Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
//     emp1.fire();

//     Employee& emp2 = myDB.addEmployee("Scott", "Kleper");
//     emp2.setSalary(100000);

//     Employee& emp3 = myDB.addEmployee("Nick", "Solter");
//     emp3.setSalary(100000);
//     emp3.promote();

//     std::cout << "all employees: " << '\n';
//     std::cout << "\n";
//     myDB.displayAll();

//     std::cout << "\n";
//     std::cout << "current employees: " << '\n';
//     std::cout << "\n";
//     myDB.displayCurrent();

//     std::cout << "\n";
//     std::cout << "former employees: " << '\n';
//     std::cout << "\n";
//     myDB.displayFormer();
// }