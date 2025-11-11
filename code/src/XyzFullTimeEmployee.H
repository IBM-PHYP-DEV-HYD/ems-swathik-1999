#ifndef _XYZ_FULL_TIME_EMPLOYEE_H
#define _XYZ_FULL_TIME_EMPLOYEE_H

#include "XyzEmployee.H"

class xyzFullTimeEmployee:public xyzEmployee
{
private:
    unsigned int mTotalNoofLeaves = 22;
    unsigned int mNoofLeavesAvailed;
public:
    xyzFullTimeEmployee();
    xyzFullTimeEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
            int leavesAvailedParam);
    ~xyzFullTimeEmployee();
    const int getTotalNoofLeaves();
    const int getNoofLeavesAvailed();
    void setNoofLeavesAvailed(unsigned int leavesAvailedParam);
    void const printEmployeeDetails(bool printAllParm);
    void addNoOfleavestoFullTimeEmployees(int noOfleavesParam);
    const void printSingleEmployeeDetails();
};


#endif //_XYZ_FULL_TIME_EMPLOYEE_H