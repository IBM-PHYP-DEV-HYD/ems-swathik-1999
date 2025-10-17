#include "Utilities.H"
#include "XyzContractorEmployee.H"

xyzContractorEmployee::xyzContractorEmployee(){
    
}

xyzContractorEmployee::xyzContractorEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam,
        ems::Agency agencyParam,ems::Location locationParam):xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam),mAgencyName(agencyParam),mAgencyLocation(locationParam)
{}

xyzContractorEmployee::~xyzContractorEmployee(){

}

ems::Agency xyzContractorEmployee::getAgencyName()
{
    return this->mAgencyName;
}

ems::Location xyzContractorEmployee::getAgencyLocation()
{
    return this->mAgencyLocation;
}

void xyzContractorEmployee::setAgencyName(ems::Agency agencyNameParam)
{
    this->mAgencyName = agencyNameParam;
}

void xyzContractorEmployee::setAgencyLocation(ems::Location agencyLocationParam)
{
    this->mAgencyLocation = agencyLocationParam;
}

void xyzContractorEmployee::fillEmployeeTypeDetails(EmployeeInfo &empInfoParam)
{
    empInfoParam.mAgencyName =  ems::empAgency[this->getAgencyName()];
    empInfoParam.mAgencyLocation = ems::empLocation[this->getAgencyLocation()];
}