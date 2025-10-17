#include "Utilities.H"
#include "XyzInternEmployee.H"

xyzInternEmployee::xyzInternEmployee(){}

xyzInternEmployee::xyzInternEmployee(string empIDParam,string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam,
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

ems::Branch xyzInternEmployee::getBranch()
{
    return this->mBranch;
}

ems::College xyzInternEmployee::getCollege()
{
    return this->mCollege;
}

void xyzInternEmployee::fillEmployeeTypeDetails(EmployeeInfo &empInfoParam)
{
    empInfoParam.mCollege = ems::empCollege[this->getCollege()];
    empInfoParam.mCollegeBranch = ems::empBranch[this->getBranch()];
}