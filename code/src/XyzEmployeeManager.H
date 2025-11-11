#ifndef _XYZ_EMPLOYEE_MANAGER_H_
#define _XYZ_EMPLOYEE_MANAGER_H_

#include "Utilities.H"

#include "Edll.H"
#include "XyzEmployeeInterface.H"
#include "XyzRandomGenerator.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"

class xyzEmployeeManager
{
private:
    Edll<xyzEmployeeInterface> *mActiveandInactiveEmpDeq;
    Edll<xyzEmployeeInterface> *mResignedEmpDeq;
    int mStaticEmpId;

public:
    xyzEmployeeManager();
    ~xyzEmployeeManager();
    void setStaticEmpID();
    int getStaticEmpID();
    int getsize();
    void addNewEmployee(std::string nameParam,ems::EmpType typeParam,ems::EmpGender genderParm,xyzRandomGenerator randObjParam);
    void removeEmployee(std::string empIDParam);
    void printAllEmployeeSummary();
    void printEmpSumByType(int empTypeParam);
    void printEmpSumByGender(int empGenderParam);
    void printEmpSumByStatus(int empStatusParam);
    void searchEmployeewithName(std::string empNameParam);
    void searchEmployeewithID(std::string empIDparam);
    void convertInternToFullTimeEmployee(std::string empIdParam, xyzRandomGenerator randomobjParam);
    void addNoOfLeavestoallFullTimeEmployees(int noOfLeavesParam);
    void addRandomEmployee(xyzRandomGenerator randObjParam);
    void printEmployeeInfoRecord();
    void checkFunc();
};



#endif  // _XYZ_EMPLOYEE_MANAGER_H_