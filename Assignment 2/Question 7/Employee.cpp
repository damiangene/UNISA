#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

int main(){
    
    Employee bob(25110, 2350, 2400, 0.08);

    cout << std::fixed << std::setprecision(2);

    cout << "Basic Salary: \t\tR " << bob.getSalary() << endl;
    cout << "Pension Amount: \tR " << bob.getPension() << endl;
    cout << "Medical Aid Amount: \tR " << bob.getMedicalAid() << endl;
    cout << "%Tax Paid: \t\t" << bob.getTaxPercentage() << "%" << endl;

    cout << endl;

    cout << "Salary Deduction: \tR " << bob.calcDeductions() << endl;
    cout << "Payable Tax: \t\tR " << bob.calcTax() << endl;
    cout << "Net Salary: \t\tR " << bob.calcGrossPay() - bob.calcTax() - bob.calcDeductions() << endl;

    return 0;
}