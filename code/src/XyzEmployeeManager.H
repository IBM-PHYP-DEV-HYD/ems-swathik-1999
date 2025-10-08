#ifndef _XYZ_EMPLOYEE_MANAGER_H_
#define _XYZ_EMPLOYEE_MANAGER_H_

#include "Edll.H"

class xyzEmployeeManager
{
private:
    EDLL *mActiveandInactiveEmp;
    EDLL *mResignedEmp;
    Node *mFullTimeEmpNode;
    Node *mContractorEmpNode;
    Node *mInternEmpNode;

protected:
    int mFullTimeEmpCount;
    int mContractorEmpCount;
    int mInternEmpCount;

public:
    xyzEmployeeManager(/* args */);
    ~xyzEmployeeManager();
    EDLL<xyzEmployeeInterface*> getInactiveandActiveEmpDeque();
    EDLL<xyzEmployeeInterface*> getResignedEmpDeque();
    void addFullTimeEmployee();
    void addContractorEmployee();
    void addInternEmployee();
    void removeFullTimeEmployee();
    void removeContractorEmployee();
    void removeInternEmployee();
    void printResignedEmployee();
    void printAllEmployeeSummary();
    void searchEmployeewithName();
    void searchEmployeewithID();
    void convertInternToFullTimeEmployee();
    void addRandomEmployee();
    virtual void printFullTimeEmpSummary();
    virtual void printContractorEmpSummary();
    virtual void printInternEmpSummary();
    static int mIdNumber;
};



#endif  // _XYZ_EMPLOYEE_MANAGER_H_