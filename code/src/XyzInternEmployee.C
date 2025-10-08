#include "Utilities.H"
#include "XyzInternEmployee.H"

xyzInternEmployee::xyzInternEmployee()
{

}

xyzInternEmployee::xyzInternEmployee(string empIDParam,string nameParam,
            string typeParam,string statusParam,
            string genderParam,string dobParam,
            string dojParam,string dolParam,
            string collegeParam,string branchParam)
            :xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam),
            mCollege(collegeParam),mBranch(branchParam)
{

}

void xyzInternEmployee::setCollege(string collegeParam)
{
    this->mCollege=collegeParam;
}
void xyzInternEmployee::setBranch(string branchParam)
{
    this->mBranch=branchParam;
}

string xyzInternEmployee::getBranch()
{
    return this->mBranch;
}

string xyzInternEmployee::getCollege()
{
    return this->mCollege;
}

void xyzInternEmployee::printInternEmpSummary(EmployeeInfo &empInfoParam)
{
    empInfoParam.mCollege=this->getCollege();
    empInfoParam.mCollegeBranch=this->getBranch();
}