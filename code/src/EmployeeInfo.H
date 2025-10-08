#ifndef _EMPLOYEE_INFO_H_
#define _EMPLOYEE_INFO_H_

#include "Utilities.H"

class EmployeeInfo
{
public:
    EmployeeInfo();
    string mEmpName;
    string mEmpId;
    string mEmpDesignationType;
    string mEmpDesignationStatus;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;
    string mCollege;
    string mCollegeBranch;
    string mAgencyName;
    string mAgencyLocation;
    string mNoOfLeaves;
};

EmployeeInfo::EmployeeInfo(){}


#endif // _EMPLOYEE_INFO_H_