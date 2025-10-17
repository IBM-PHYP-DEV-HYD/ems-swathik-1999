#ifndef _XYZ_CONTRACTOR_EMPLOYEE_H_
#define _XYZ_CONTRACTOR_EMPLOYEE_H_

#include "XyzEmployee.H"
#include "Utilities.H"
#include "EmployeeInfo.H"

class xyzContractorEmployee:public xyzEmployee
{
private:
    ems::Agency mAgencyName;
    ems::Location mAgencyLocation;
public:
    xyzContractorEmployee();
    xyzContractorEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam,
        ems::Agency agencyParam,ems::Location locationParam);
    ~xyzContractorEmployee();
    ems::Agency getAgencyName();
    ems::Location getAgencyLocation();
    void setAgencyName(ems::Agency agencyName);
    void setAgencyLocation(ems::Location agencyLocation);
    void fillEmployeeTypeDetails(EmployeeInfo &empInfoParam);
};


#endif //_XYZ_CONTRACTOR_EMPLOYEE_H_