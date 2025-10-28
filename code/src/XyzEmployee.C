#include "XyzEmployee.H"

xyzEmployee::xyzEmployee(){

}

xyzEmployee::xyzEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam):mName(nameParam),mEmpID(empIDParam),mGender(genderParam),
            mDesignationType(typeParam),mDesignationStatus(statusParam),mDateOfBirth(dobParam),
            mDateOfJoining(dojParam),mDateOfLeaving(dolParam)            
{
}

string xyzEmployee::getEmpId()
{
    return this->mEmpID;
}

string xyzEmployee::getEmpName()
{
    return this->mName;
}

ems::EmpType xyzEmployee::getDesignationType()
{
    return this->mDesignationType;
}

ems::EmpStatus xyzEmployee::getDesignationStatus()
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

ems::EmpGender xyzEmployee::getGender()
{
    return this->mGender;
}

void xyzEmployee::setEmpID(string empIDParam)
{
    this->mEmpID = empIDParam;
}

void xyzEmployee::setEmpName(string nameParam)
{
    this->mName = nameParam;
}

void xyzEmployee::setDesignationType(ems::EmpType typeParam)
{
    this->mDesignationType = typeParam;
}

void xyzEmployee::setDesignationStatus(ems::EmpStatus statusParam)
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

void xyzEmployee::setGender(ems::EmpGender genderParam)
{
    this->mGender = genderParam;
}

void xyzEmployee::fillEmployeeDetails(EmployeeInfo &empInfoParam)
{
    empInfoParam.mEmpName = this->getEmpName();
    empInfoParam.mEmpId = this->getEmpId();
    empInfoParam.mEmpDesignationType = ems::empType[this->getDesignationType()];
    empInfoParam.mEmpDesignationStatus = ems::empStatus[this->getDesignationStatus()];
    empInfoParam.mEmpGender = ems::empGender[this->getGender()];
    empInfoParam.mDateOfBirth = this->getDateOfBirth();
    empInfoParam.mDateOfJoining = this->getDateOfJoining();
    empInfoParam.mDateOfLeaving = this->getDateOfLeaving();
}

xyzEmployee::~xyzEmployee()
{
    
}

ems::College xyzEmployee::getCollege() {
    return ems::College();
}

void xyzEmployee::setCollege(ems::College) {
}

ems::Branch xyzEmployee::getBranch() {
    return ems::Branch();
}

void xyzEmployee::setBranch(ems::Branch) {
    // do nothing
}

ems::Agency xyzEmployee::getAgencyName() {
    return ems::Agency();
}

void xyzEmployee::setAgencyName(ems::Agency) {
}

ems::Location xyzEmployee::getAgencyLocation() {
    return ems::Location();
}

void xyzEmployee::setAgencyLocation(ems::Location) {
}

int xyzEmployee::getTotalNoofLeaves() {
    return 0;
}

int xyzEmployee::getNoofLeavesAvailed() {
    return 0;
}

void xyzEmployee::setNoofLeavesAvailed(unsigned int) {
}

void xyzEmployee::addNoOfleavestoFullTimeEmployees(int) {
}

void xyzEmployee::fillEmployeeTypeDetails(EmployeeInfo &empInfoParam) {
    
}
