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
    xyzFullTimeEmployee(string empIDParam,string nameParam,\
            string typeParam,string statusParam, \
            string genderParam,string dobParam,\
            string dojParam,string dolParam,\
            int leavesAvailedParam);
    ~xyzFullTimeEmployee();
    int getTotalNoofLeaves();
    int getNoofLeavesAvailed();
    void setNoofLeavesAvailed(unsigned int leavesAvailedParam);
    void printFullTimeEmpSummary();
};


#endif //_XYZ_FULL_TIME_EMPLOYEE_H