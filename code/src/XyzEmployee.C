#include "Utilities.H"
#include "XyzEmployee.H"

xyzEmployee::xyzEmployee(){

}

xyzEmployee::xyzEmployee(string empIDParam,string nameParam,
            string typeParam,string statusParam,
            string genderParam,string dobParam,
            string dojParam,string dolParam)
{
    setName(nameParam);
    setEmpID(empIDParam);
    setDesignationStatus(statusParam);
    setDesignationType(typeParam);
    setGender(genderParam);
    setDateOfBirth(dobParam);
    setDateOfJoining(dojParam);
    setDateOfLeaving(dolParam);
}

string xyzEmployee::getEmpID()
{
    return this->mEmpID;
}

string xyzEmployee::getName()
{
    return this->mName;
}

string xyzEmployee::getDesignationType()
{
    return this->mDesignationType;
}

string xyzEmployee::getDesignationStatus()
{
    return this->mDesignationStatus;
}

string xyzEmployee::getDateOfBirth()
{
    return this->mDateOfBirth;
}

string xyzEmployee::getDateOfJoining()
{
    return this->mDateOfJoining;
}

string xyzEmployee::getDateOfLeaving()
{
    return this->mDateOfLeaving;
}

string xyzEmployee::getGender()
{
    return this->mGender;
}

void xyzEmployee::setEmpID(string empIDParam)
{
    this->mEmpID = empIDParam;
}

void xyzEmployee::setName(string nameParam)
{
    this->mName = nameParam;
}

void xyzEmployee::setDesignationType(string typeParam)
{
    this->mDesignationType = typeParam;
}

void xyzEmployee::setDesignationStatus(string statusParam)
{
    this->mDesignationStatus = statusParam;
}

void xyzEmployee::setDateOfBirth(string dobParam)
{
    this->mDateOfBirth = dobParam;
}

void xyzEmployee::setDateOfJoining(string dojParam)
{
    this->mDateOfJoining = dojParam;
}

void xyzEmployee::setDateOfLeaving(string dolParam)
{
    this->mDateOfLeaving = dolParam;
}

void xyzEmployee::setGender(string genderParam)
{
    this->mGender = genderParam;
}
