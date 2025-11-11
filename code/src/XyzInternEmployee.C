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

const void xyzInternEmployee::printEmployeeDetails(bool printAllParm)
{
    std::cout << "| "<< std::left << std::setw(24) << std::setfill(' ') << this->getEmpName();
    std::cout << "| "<< std::left << std::setw(12)<< std::setfill(' ') << this->getEmpId();
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empType[this->getDesignationType()];
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empStatus[this->getDesignationStatus()];
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empGender[this->getGender()];
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfBirth();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfJoining();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfLeaving().length() ? this->getDateOfLeaving() : "--";
    if(ems::empStatus[this->getDesignationStatus()] != "Resigned")
    {
        if(printAllParm)
        {
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
        }
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << ems::empCollege[this->getCollege()];
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << ems::empBranch[this->getBranch()] << std::endl;
    }
    if(!printAllParm)
    {
        std::cout << std::endl;
    }
}

const void xyzInternEmployee::printSingleEmployeeDetails()
{
    std::cout << " Employee Name   : " << this->getEmpName()<< std::endl;
    std::cout << " Employee ID     : " << this->getEmpId()<< std::endl;
    std::cout << " Employee Type   : " << ems::empType[this->getDesignationType()]<< std::endl;
    std::cout << " Employee Status : " << ems::empStatus[this->getDesignationStatus()]<< std::endl;
    std::cout << " Gender          : " << ems::empGender[this->getGender()]<< std::endl;
    std::cout << " Date Of Birth   : " << this->getDateOfBirth()<< std::endl;
    std::cout << " Date Of Joining : " << this->getDateOfJoining()<< std::endl;
    std::cout << " College         : " << ems::empCollege[this->getCollege()]<< std::endl;
    std::cout << " Branch          : " << ems::empBranch[this->getBranch()] << std::endl;
}