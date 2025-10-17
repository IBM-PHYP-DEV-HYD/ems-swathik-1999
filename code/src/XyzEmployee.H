#ifndef _XYZ_EMPLOYEE_H_
#define _XYZ_EMPLOYEE_H_

#include "Utilities.H"
#include "XyzEmployeeInterface.H"


using namespace std;

class xyzEmployee:public xyzEmployeeInterface
{
private:
    string mName;
    string mEmpID;
    ems::EmpGender mGender;
    ems::EmpType mDesignationType;
    ems::EmpStatus mDesignationStatus;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;

public:
    xyzEmployee();
    xyzEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam);
    virtual ~xyzEmployee();
    string getEmpName();
    string getEmpId();
    ems::EmpType getDesignationType();
    ems::EmpStatus getDesignationStatus();
    string getDateOfBirth();
    string getDateOfJoining();
    string getDateOfLeaving();
    ems::EmpGender getGender();
    void setEmpName(string nameParam);
    void setEmpID(string empIDParam);
    void setDesignationType(ems::EmpType typeParam);
    void setDesignationStatus(ems::EmpStatus  statusParam);
    void setDateOfBirth(string dobParam);
    void setDateOfJoining(string dojParam);
    void setDateOfLeaving(string dolParam);
    void setGender(ems::EmpGender genderParam);
    virtual ems::Agency getAgencyName();
    virtual ems::Location getAgencyLocation();
    virtual void setAgencyName(ems::Agency agencyName);
    virtual void setAgencyLocation(ems::Location agencyLocation);
    virtual void setCollege(ems::College collegeParam);
    virtual void setBranch(ems::Branch branchParam);
    virtual ems::College getCollege();
    virtual ems::Branch getBranch();
    virtual int getTotalNoofLeaves();
    virtual int getNoofLeavesAvailed();
    virtual void setNoofLeavesAvailed(unsigned int leavesAvailedParam);
    virtual void addNoOfleavestoFullTimeEmployees(int noOfLeavesParam);
    virtual void fillEmployeeTypeDetails(EmployeeInfo &empInfoParam);
    void fillEmployeeDetails(EmployeeInfo &empInfoParam);    
};

#endif  // _XYZ_EMPLOYEE_H_
