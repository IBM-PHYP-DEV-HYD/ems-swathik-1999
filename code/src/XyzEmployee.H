#ifndef _XYZ_EMPLOYEE_H_
#define _XYZ_EMPLOYEE_H_

#include "Utilities.H"
#include "XyzEmployeeInterface.H"


class xyzEmployee:public xyzEmployeeInterface
{
private:
    std::string mName;
    std::string mEmpID;
    ems::EmpGender mGender;
    ems::EmpType mDesignationType;
    ems::EmpStatus mDesignationStatus;
    std::string mDateOfBirth;
    std::string mDateOfJoining;
    std::string mDateOfLeaving;

public:
    xyzEmployee();
    xyzEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam);
    virtual ~xyzEmployee();
    const std::string getEmpName();
    const std::string getEmpId();
    const ems::EmpType getDesignationType();
    const ems::EmpStatus getDesignationStatus();
    const std::string getDateOfBirth();
    const std::string getDateOfJoining();
    const std::string getDateOfLeaving();
    const ems::EmpGender getGender();
    void setEmpName(std::string nameParam);
    void setEmpID(std::string empIDParam);
    void setDesignationType(ems::EmpType typeParam);
    void setDesignationStatus(ems::EmpStatus  statusParam);
    void setDateOfBirth(std::string dobParam);
    void setDateOfJoining(std::string dojParam);
    void setDateOfLeaving(std::string dolParam);
    void setGender(ems::EmpGender genderParam);
    virtual const ems::Agency getAgencyName();
    virtual const ems::Location getAgencyLocation();
    virtual void setAgencyName(ems::Agency agencyName);
    virtual void setAgencyLocation(ems::Location agencyLocation);
    virtual void setCollege(ems::College collegeParam);
    virtual void setBranch(ems::Branch branchParam);
    virtual const ems::College getCollege();
    virtual const ems::Branch getBranch();
    virtual const int getTotalNoofLeaves();
    virtual const int getNoofLeavesAvailed();
    virtual void setNoofLeavesAvailed(unsigned int leavesAvailedParam);
    virtual void addNoOfleavestoFullTimeEmployees(int noOfLeavesParam);
    virtual const void printEmployeeDetails(bool printAllParm);
    virtual const void printSingleEmployeeDetails();
};

#endif  // _XYZ_EMPLOYEE_H_
