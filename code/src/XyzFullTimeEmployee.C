#include "Utilities.H"
#include "XyzFullTimeEmployee.H"

void calculateLeavesAvailed(int leavesAvailedParam)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> yearDist(1, 22);
    leavesAvailedParam = yearDist(gen);
}

xyzFullTimeEmployee::xyzFullTimeEmployee()
{

}

xyzFullTimeEmployee::xyzFullTimeEmployee(std::string empIDParam,std::string nameParam,
            ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam,
            int leavesAvailedParam):xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam)
{
    calculateLeavesAvailed(leavesAvailedParam);
    this->mNoofLeavesAvailed = leavesAvailedParam;
}

xyzFullTimeEmployee::~xyzFullTimeEmployee(){}

const int xyzFullTimeEmployee::getTotalNoofLeaves()
{
    return this->mTotalNoofLeaves;
}

const int xyzFullTimeEmployee::getNoofLeavesAvailed()
{
    return this->mNoofLeavesAvailed;
}

void xyzFullTimeEmployee::setNoofLeavesAvailed(unsigned int leavesAvailedParam)
{
    this->mNoofLeavesAvailed = leavesAvailedParam;
}

const void xyzFullTimeEmployee::fillEmployeeTypeDetails(EmployeeInfoRecord *empinfoParam)
{
    empinfoParam->setEmpName(this->getEmpName());
    empinfoParam->setEmpId(this->getEmpId());
    empinfoParam->setEmpType(ems::empType[this->getDesignationType()]);
    empinfoParam->setEmpStatus(ems::empStatus[this->getDesignationStatus()]);
    empinfoParam->setEmpGender(ems::empGender[this->getGender()]);
    empinfoParam->setDOB(this->getDateOfBirth());
    empinfoParam->setDOJ(this->getDateOfJoining());
    empinfoParam->setDOL(this->getDateOfLeaving());
    empinfoParam->setTotalLeaves(this->getTotalNoofLeaves());
    empinfoParam->setNoOfLeaves(this->getNoofLeavesAvailed());
}

void xyzFullTimeEmployee::addNoOfleavestoFullTimeEmployees(int noOfLeavesParam)
{
    unsigned int sLeaves = this->mNoofLeavesAvailed;
    sLeaves += noOfLeavesParam;
    
    if(sLeaves > 22)
    {
        this->mNoofLeavesAvailed = 22;
    }
    else
    {
        this->mNoofLeavesAvailed = sLeaves;
    }
}