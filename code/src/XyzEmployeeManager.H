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
    void addNewEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam,int noOfLeavesParam, ems::Agency agencyParam,
            ems::Location locationParam,ems::College collegeParam,ems::Branch branchParam);
    void removeEmployee(string empIDParam);
    void printResignedEmployeeSummary();
    void printAllEmployeeSummary();
    void printEmpSumByType(int empTypeParam);
    void printEmpSumByGender(int empGenderParam);
    void printEmpSumByStatus(int empStatusParam);
    void searchEmployeewithName(string empNameParam);
    void searchEmployeewithID(string empIDparam);
    void convertInternToFullTimeEmployee(string empIdParam, xyzRandomGenerator randomobjParam);
    void addNoOfLeavestoallFullTimeEmployees(int noOfLeavesParam);
    void addRandomEmployee(xyzRandomGenerator randObjParam);
    void checkFunc();
};



#endif  // _XYZ_EMPLOYEE_MANAGER_H_