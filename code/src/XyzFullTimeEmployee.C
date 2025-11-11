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

const void xyzFullTimeEmployee::printEmployeeDetails(bool printAllParm)
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
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << this->mTotalNoofLeaves;    
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << this->mNoofLeavesAvailed;
        if(printAllParm)
        {
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
            std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--" << std::endl;;
        }
    }
    if(!printAllParm)
    {
        std::cout << std::endl;
    }
}

const void xyzFullTimeEmployee::printSingleEmployeeDetails()
{
    std::cout << " Employee Name   : " << this->getEmpName()<< std::endl;
    std::cout << " Employee ID     : " << this->getEmpId()<< std::endl;
    std::cout << " Employee Type   : " << ems::empType[this->getDesignationType()]<< std::endl;
    std::cout << " Employee Status : " << ems::empStatus[this->getDesignationStatus()]<< std::endl;
    std::cout << " Gender          : " << ems::empGender[this->getGender()]<< std::endl;
    std::cout << " Date Of Birth   : " << this->getDateOfBirth()<< std::endl;
    std::cout << " Date Of Joining : " << this->getDateOfJoining()<< std::endl;
    std::cout << " Leaves left     : " << this->getNoofLeavesAvailed() << std::endl;
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