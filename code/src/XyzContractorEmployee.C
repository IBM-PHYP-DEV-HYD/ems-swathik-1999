#include "Utilities.H"
#include "XyzContractorEmployee.H"

xyzContractorEmployee::xyzContractorEmployee(){
    
}

xyzContractorEmployee::xyzContractorEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
        ems::Agency agencyParam,ems::Location locationParam):xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam),mAgencyName(agencyParam),mAgencyLocation(locationParam)
{}

xyzContractorEmployee::~xyzContractorEmployee(){

}

const ems::Agency xyzContractorEmployee::getAgencyName()
{
    return this->mAgencyName;
}

const ems::Location xyzContractorEmployee::getAgencyLocation()
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

const void xyzContractorEmployee::fillEmployeeTypeDetails(EmployeeInfoRecord *empInfoParam)
{
    empInfoParam->setEmpName(this->getEmpName());
    empInfoParam->setEmpId(this->getEmpId());
    empInfoParam->setEmpType(ems::empType[this->getDesignationType()]);
    empInfoParam->setEmpStatus(ems::empStatus[this->getDesignationStatus()]);
    empInfoParam->setEmpGender(ems::empGender[this->getGender()]);
    empInfoParam->setDOB(this->getDateOfBirth());
    empInfoParam->setDOJ(this->getDateOfJoining());
    empInfoParam->setDOL(this->getDateOfLeaving());
    empInfoParam->setAgency(ems::empAgency[this->getAgencyName()]);
    empInfoParam->setLocation(ems::empLocation[this->getAgencyLocation()]);
}