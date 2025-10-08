#ifndef _XYZ_EMPLOYEE_INTERFACE_H
#define _XYZ_EMPLOYEE_INTERFACE_H

#include <iostream>
#include <string>

using namespace std;

class xyzEmployeeInterface
{
private:
    /* data */
public:
    xyzEmployeeInterface(/* args */);
    ~xyzEmployeeInterface();
    virtual void addFullTimeEmployee();
    virtual void addContractorEmployee();
    virtual void addInternEmployee();
    virtual void removeFullTimeEmployee();
    virtual void removeContractorEmployee();
    virtual void removeInternEmployee();
    virtual void searchEmployee();
    virtual void convertInternToFullTimeEmployee();
    virtual void printFullTimeEmployeeSummary();
    virtual void printContractorEmployeeSummary();
    virtual void printInternEmployeeSummary();
    virtual void printAllEmployeeSummary();
    virtual void activeEmployeeSummary();
    virtual void inActiveEmployeeSummary();
    virtual void resignedEmployeeSummary();

};
#endif //_XYZ_EMPLOYEE_INTERFACE_H