#ifndef _XYZ_INTERN_EMPLOYEE_H
#define _XYZ_INTERN_EMPLOYEE_H

#include "XyzEmployee.H"
#include "EmployeeInfo.H"

using namespace ems;

class xyzInternEmployee:public xyzEmployee {
    private:
        string mCollege;
        string mBranch;
    public:
        xyzInternEmployee();
        xyzInternEmployee(string empIDParam,string nameParam,\
            string typeParam,string statusParam, \
            string genderParam,string dobParam,\
            string dojParam,string dolParam,\
            string collegeParam,string branchParam);
        void setCollege(string collegeParam);
        void setBranch(string branchParam);
        string getCollege();
        string getBranch();
        void printInternEmpSummary(EmployeeInfo &empInfoParam);
};

#endif //_XYZ_INTERN_EMPLOYEE_H_