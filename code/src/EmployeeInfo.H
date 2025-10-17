#ifndef _EMPLOYEE_INFO_H_
#define _EMPLOYEE_INFO_H_

#include "Utilities.H"

class EmployeeInfo
{
public:
    EmployeeInfo();
    ~EmployeeInfo();
    bool mPrintAll;
    string mEmpName;
    string mEmpId;
    string mEmpDesignationType;
    string mEmpDesignationStatus;
    string mEmpGender;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;
    string mCollege;
    string mCollegeBranch;
    string mAgencyName;
    string mAgencyLocation;
    int mNoOfLeaves;
    int mTotalNoOfLeaves;
    void printEmployeeInfo();
    void clearEmployeeInfo();
};

#endif //_EMPLOYEE_INFO_H_