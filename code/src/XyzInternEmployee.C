#include "Utilities.H"
#include "XyzInternEmployee.H"

xyzInternEmployee::xyzInternEmployee(){}

xyzInternEmployee::xyzInternEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
            ems::College collegeParam,ems::Branch branchParam)
            :xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam),
            mCollege(collegeParam),mBranch(branchParam)
{

}

void xyzInternEmployee::setCollege(ems::College collegeParam)
{
    this->mCollege=collegeParam;
}
void xyzInternEmployee::setBranch(ems::Branch branchParam)
{
    this->mBranch=branchParam;
}

const ems::Branch xyzInternEmployee::getBranch()
{
    return this->mBranch;
}

const ems::College xyzInternEmployee::getCollege()
{
    return this->mCollege;
}

const void xyzInternEmployee::fillEmployeeTypeDetails(EmployeeInfoRecord *empInfoParam)
{
    empInfoParam->setEmpName(this->getEmpName());
    empInfoParam->setEmpId(this->getEmpId());
    empInfoParam->setEmpType(ems::empType[this->getDesignationType()]);
    empInfoParam->setEmpStatus(ems::empStatus[this->getDesignationStatus()]);
    empInfoParam->setEmpGender(ems::empGender[this->getGender()]);
    empInfoParam->setDOB(this->getDateOfBirth());
    empInfoParam->setDOJ(this->getDateOfJoining());
    empInfoParam->setDOL(this->getDateOfLeaving());
    empInfoParam->setCollege(ems::empCollege[this->getCollege()]);
    empInfoParam->setBranch(ems::empBranch[this->getBranch()]);
}