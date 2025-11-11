#ifndef _XYZ_EMPLOYEE_INTERFACE_H
#define _XYZ_EMPLOYEE_INTERFACE_H

#include <iostream>
#include <string>
#include "Utilities.H"
#include "EmployeeInfoRecord.H"


class xyzEmployeeInterface
{
public:
    xyzEmployeeInterface(){}
    virtual ~xyzEmployeeInterface() = default;
    
    virtual const void fillEmployeeTypeDetails(EmployeeInfoRecord *empInfoParam) = 0;
    virtual const std::string getEmpName() = 0;
    virtual const std::string getEmpId() = 0;
    virtual const ems::EmpType getDesignationType() = 0;
    virtual const ems::EmpStatus getDesignationStatus() = 0;
    virtual const std::string getDateOfBirth() = 0;
    virtual const std::string getDateOfJoining() = 0;
    virtual const std::string getDateOfLeaving() = 0;
    virtual const ems::EmpGender getGender() = 0;
    virtual void setEmpName(std::string nameParam) = 0;
    virtual void setEmpID(std::string empIDParam) = 0;
    virtual void setDesignationType(ems::EmpType typeParam) = 0;
    virtual void setDesignationStatus(ems::EmpStatus statusParam) = 0;
    virtual void setDateOfBirth(std::string dobParam) = 0;
    virtual void setDateOfJoining(std::string dojParam) = 0;
    virtual void setDateOfLeaving(std::string dolParam) = 0;
    virtual void setGender(ems::EmpGender genderParam) = 0;
    virtual const ems::Agency getAgencyName() = 0;
    virtual const ems::Location getAgencyLocation() = 0;
    virtual void setAgencyName(ems::Agency agencyName) = 0;
    virtual void setAgencyLocation(ems::Location agencyLocation) = 0;
    virtual void setCollege(ems::College collegeParam) = 0;
    virtual void setBranch(ems::Branch branchParam) = 0;
    virtual const ems::College getCollege() = 0;
    virtual const ems::Branch getBranch() = 0;
    virtual const int getTotalNoofLeaves() = 0;
    virtual const int getNoofLeavesAvailed() = 0;
    virtual void setNoofLeavesAvailed(unsigned int leavesAvailedParam) = 0;
    virtual void addNoOfleavestoFullTimeEmployees(int noOfLeavesParam) = 0;
};
#endif //_XYZ_EMPLOYEE_INTERFACE_H