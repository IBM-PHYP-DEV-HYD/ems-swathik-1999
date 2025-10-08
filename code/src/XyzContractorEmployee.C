#include "Utilities.H"
#include "XyzContractorEmployee.H"

xyzContractorEmployee::xyzContractorEmployee(){
    
}

xyzContractorEmployee::xyzContractorEmployee(string empIDParam,string nameParam,
            string typeParam,string statusParam,
            string genderParam,string dobParam,
            string dojParam,string dolParam,
        string agencyParam,string locationParam):xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam),mAgencyName(agencyParam),mAgencyLocation(locationParam)
{}

string xyzContractorEmployee::getAgencyName()
{
    return this->mAgencyName;
}

string xyzContractorEmployee::getAgencyLocation()
{
    return this->mAgencyLocation;
}

void xyzContractorEmployee::setAgencyName(string agencyNameParam)
{
    this->mAgencyName = agencyNameParam;
}

void xyzContractorEmployee::setAgencyLocation(string agencyLocationParam)
{
    this->mAgencyLocation = agencyLocationParam;
}