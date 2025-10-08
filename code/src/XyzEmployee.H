#ifndef _XYZ_EMPLOYEE_H_
#define _XYZ_EMPLOYEE_H_

#include <iostream>
#include <string>

using namespace std;

class xyzEmployee
{
private:
    string mName;
    string mEmpID;
    string mGender;
    string mDesignationType;
    string mDesignationStatus;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;

public:
    xyzEmployee();
    xyzEmployee(string empIDParam,string nameParam,
            string typeParam,string statusParam,
            string genderParam,string dobParam,
            string dojParam,string dolParam);
    ~xyzEmployee();
    string getName();
    string getEmpID();
    string getDesignationType();
    string getDesignationStatus();
    string getDateOfBirth();
    string getDateOfJoining();
    string getDateOfLeaving();
    string getGender();
    void setName(string nameParam);
    void setEmpID(string empIDParam);
    void setDesignationType(string typeParam);
    void setDesignationStatus(string statusParam);
    void setDateOfBirth(string dobParam);
    void setDateOfJoining(string dojParam);
    void setDateOfLeaving(string dolParam);
    void setGender(string genderParam);
    virtual void printFullTimeEmpDetails();
    virtual void printContractorEmpDetails();
    virtual void printInternEmpDetails();
};

#endif  // _XYZ_EMPLOYEE_H_
