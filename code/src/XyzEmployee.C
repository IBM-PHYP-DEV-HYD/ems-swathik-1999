#include "XyzEmployee.H"

xyzEmployee::xyzEmployee(){

}

xyzEmployee::xyzEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam):mName(nameParam),mEmpID(empIDParam),mGender(genderParam),
            mDesignationType(typeParam),mDesignationStatus(statusParam),mDateOfBirth(dobParam),
            mDateOfJoining(dojParam),mDateOfLeaving(dolParam)            
{
}

const std::string xyzEmployee::getEmpId()
{
    return this->mEmpID;
}

const std::string xyzEmployee::getEmpName()
{
    return this->mName;
}

const ems::EmpType xyzEmployee::getDesignationType()
{
    return this->mDesignationType;
}

const ems::EmpStatus xyzEmployee::getDesignationStatus()
{
    return this->mDesignationStatus;
}

const std::string xyzEmployee::getDateOfBirth()
{
    return this->mDateOfBirth;
}

const std::string xyzEmployee::getDateOfJoining()
{
    return this->mDateOfJoining;
}

const std::string xyzEmployee::getDateOfLeaving()
{
    return this->mDateOfLeaving;
}

const ems::EmpGender xyzEmployee::getGender()
{
    return this->mGender;
}

void xyzEmployee::setEmpID(std::string empIDParam)
{
    this->mEmpID = empIDParam;
}

void xyzEmployee::setEmpName(std::string nameParam)
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

void xyzEmployee::setDateOfBirth(std::string dobParam)
{
    this->mDateOfBirth = dobParam;
}

void xyzEmployee::setDateOfJoining(std::string dojParam)
{
    this->mDateOfJoining = dojParam;
}

void xyzEmployee::setDateOfLeaving(std::string dolParam)
{
    this->mDateOfLeaving = dolParam;
}

void xyzEmployee::setGender(ems::EmpGender genderParam)
{
    this->mGender = genderParam;
}

xyzEmployee::~xyzEmployee()
{
    
}

const ems::College xyzEmployee::getCollege() {
    return ems::College();
}

void xyzEmployee::setCollege(ems::College) {
}

const ems::Branch xyzEmployee::getBranch() {
    return ems::Branch();
}

void xyzEmployee::setBranch(ems::Branch) {
    // do nothing
}

const ems::Agency xyzEmployee::getAgencyName() {
    return ems::Agency();
}

void xyzEmployee::setAgencyName(ems::Agency) {
}

const ems::Location xyzEmployee::getAgencyLocation() {
    return ems::Location();
}

void xyzEmployee::setAgencyLocation(ems::Location) {
}

const int xyzEmployee::getTotalNoofLeaves() {
    return 0;
}

const int xyzEmployee::getNoofLeavesAvailed() {
    return 0;
}

void xyzEmployee::setNoofLeavesAvailed(unsigned int) {
}

void xyzEmployee::addNoOfleavestoFullTimeEmployees(int) {
}

const void xyzEmployee::printEmployeeDetails(bool printAllParm) {
    
}

const void xyzEmployee::printSingleEmployeeDetails() {
    
}
