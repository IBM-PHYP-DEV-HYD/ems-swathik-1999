#ifndef _XYZ_CONTRACTOR_EMPLOYEE_H_
#define _XYZ_CONTRACTOR_EMPLOYEE_H_

#include "XyzEmployee.H"
#include "Utilities.H"

class xyzContractorEmployee:public xyzEmployee
{
private:
    ems::Agency mAgencyName;
    ems::Location mAgencyLocation;
public:
    xyzContractorEmployee();
    xyzContractorEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
        ems::Agency agencyParam,ems::Location locationParam);
    ~xyzContractorEmployee();
    const ems::Agency getAgencyName();
    const ems::Location getAgencyLocation();
    void setAgencyName(ems::Agency agencyName);
    void setAgencyLocation(ems::Location agencyLocation);
    const void printEmployeeDetails(bool printAllParm);
    const void printSingleEmployeeDetails();
};


#endif //_XYZ_CONTRACTOR_EMPLOYEE_H_