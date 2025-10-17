#ifndef _XYZ_EMPLOYEE_INTERFACE_H
#define _XYZ_EMPLOYEE_INTERFACE_H

#include <iostream>
#include <string>
#include "Utilities.H"
#include "EmployeeInfo.H"

using namespace std;

class xyzEmployeeInterface
{
public:
    xyzEmployeeInterface(){}
    virtual ~xyzEmployeeInterface() = default;
    
    virtual void fillEmployeeDetails(EmployeeInfo &empInfoParam) = 0;
    virtual void fillEmployeeTypeDetails(EmployeeInfo &empInfoParam) = 0;
    virtual string getEmpName() = 0;
    virtual string getEmpId() = 0;
    virtual ems::EmpType getDesignationType() = 0;
    virtual ems::EmpStatus getDesignationStatus() = 0;
    virtual string getDateOfBirth() = 0;
    virtual string getDateOfJoining() = 0;
    virtual string getDateOfLeaving() = 0;
    virtual ems::EmpGender getGender() = 0;
    virtual void setEmpName(string nameParam) = 0;
    virtual void setEmpID(string empIDParam) = 0;
    virtual void setDesignationType(ems::EmpType typeParam) = 0;
    virtual void setDesignationStatus(ems::EmpStatus statusParam) = 0;
    virtual void setDateOfBirth(string dobParam) = 0;
    virtual void setDateOfJoining(string dojParam) = 0;
    virtual void setDateOfLeaving(string dolParam) = 0;
    virtual void setGender(ems::EmpGender genderParam) = 0;
    virtual ems::Agency getAgencyName() = 0;
    virtual ems::Location getAgencyLocation() = 0;
    virtual void setAgencyName(ems::Agency agencyName) = 0;
    virtual void setAgencyLocation(ems::Location agencyLocation) = 0;
    virtual void setCollege(ems::College collegeParam) = 0;
    virtual void setBranch(ems::Branch branchParam) = 0;
    virtual ems::College getCollege() = 0;
    virtual ems::Branch getBranch() = 0;
    virtual int getTotalNoofLeaves() = 0;
    virtual int getNoofLeavesAvailed() = 0;
    virtual void setNoofLeavesAvailed(unsigned int leavesAvailedParam) = 0;
    virtual void addNoOfleavestoFullTimeEmployees(int noOfLeavesParam) = 0;
};
#endif //_XYZ_EMPLOYEE_INTERFACE_H