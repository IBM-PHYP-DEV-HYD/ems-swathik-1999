#ifndef _XYZ_CONTRACTOR_EMPLOYEE_H_
#define _XYZ_CONTRACTOR_EMPLOYEE_H_

#include "XyzEmployee.H"

class xyzContractorEmployee:public xyzEmployee
{
private:
    string mAgencyName;
    string mAgencyLocation;
public:
    xyzContractorEmployee();
    xyzContractorEmployee(string empIDParam,string nameParam,\
            string typeParam,string statusParam, \
            string genderParam,string dobParam,\
            string dojParam,string dolParam,\
        string agencyParam,string locationParam);
    ~xyzContractorEmployee();
    string getAgencyName();
    string getAgencyLocation();
    void setAgencyName(string agencyName);
    void setAgencyLocation(string agencyLocation);
    void printContractorEmpSummary();
};


#endif //_XYZ_CONTRACTOR_EMPLOYEE_H_