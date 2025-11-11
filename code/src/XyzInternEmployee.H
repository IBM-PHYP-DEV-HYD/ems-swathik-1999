#ifndef _XYZ_INTERN_EMPLOYEE_H
#define _XYZ_INTERN_EMPLOYEE_H

#include "XyzEmployee.H"
#include "Utilities.H"

using namespace ems;

class xyzInternEmployee:public xyzEmployee {
    private:
        ems::College mCollege;
        ems::Branch mBranch;
    public:
        xyzInternEmployee();
        xyzInternEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
            ems::College collegeParam,ems::Branch branchParam);
        void setCollege(ems::College collegeParam);
        void setBranch(ems::Branch branchParam);
        const ems::College getCollege();
        const ems::Branch getBranch();
        const void printEmployeeDetails(bool printAllParm);
        const void printSingleEmployeeDetails();
};

#endif //_XYZ_INTERN_EMPLOYEE_H_