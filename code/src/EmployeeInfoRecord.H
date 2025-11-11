#ifndef _EMPLOYEE_INFO_H_
#define _EMPLOYEE_INFO_H_

#include "Utilities.H"

class EmployeeInfoRecord
{
private:
    bool mPrintAll;
    std::string mEmpName;
    std::string mEmpId;
    std::string mEmpDesignationType;
    std::string mEmpDesignationStatus;
    std::string mEmpGender;
    std::string mDateOfBirth;
    std::string mDateOfJoining;
    std::string mDateOfLeaving;
    std::string mCollege;
    std::string mCollegeBranch;
    std::string mAgencyName;
    std::string mAgencyLocation;
    int mNoOfLeaves;
    int mTotalNoOfLeaves;

public:
    EmployeeInfoRecord();
    ~EmployeeInfoRecord();
    void printEmployeeInfoRecord();
    void printEmployeeDetails();
    void clearEmployeeInfoRecord();
    bool getPrintVal();
    void setPrintVal(bool valParm);
    const std::string getEmpName();
    void setEmpName(std::string empNameParm);
    const std::string getEmpId();
    void setEmpId(std::string empIdParm);
    const std::string getEmpStatus();
    void setEmpStatus(std::string empStatusParm);
    const std::string getEmpType();
    void setEmpType(std::string empTypeParm);
    const std::string getEmpGender();
    void setEmpGender(std::string empGenderParm);
    const std::string getDOB();
    void setDOB(std::string dobParm);
    const std::string getDOJ();
    void setDOJ(std::string dojParm);
    const std::string getDOL();
    void setDOL(std::string dolParm);
    const std::string getCollege();
    void setCollege(std::string collegeParm);
    const std::string getBranch();
    void setBranch(std::string branchParm);
    const std::string getAgency();
    void setAgency(std::string agencyParm);
    const std::string getLocation();
    void setLocation(std::string locationParm);
    const int getNoOfLeaves();
    void setNoOfLeaves(int leaveParm);
    const int getTotalLeaves();
    void setTotalLeaves(int totalParm);
};

#endif //_EMPLOYEE_INFO_H_