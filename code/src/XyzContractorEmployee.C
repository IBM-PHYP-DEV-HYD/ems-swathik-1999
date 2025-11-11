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

const void xyzContractorEmployee::printEmployeeDetails(bool printAllParm)
{
    std::cout << "| "<< std::left << std::setw(24) << std::setfill(' ') << this->getEmpName();
    std::cout << "| "<< std::left << std::setw(12)<< std::setfill(' ') << this->getEmpId();
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empType[this->getDesignationType()];
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empStatus[this->getDesignationStatus()];
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << ems::empGender[this->getGender()];
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfBirth();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfJoining();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << this->getDateOfLeaving().length() ? this->getDateOfLeaving() : "--";
    if(printAllParm)
    {
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
    }
    std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << ems::empAgency[this->getAgencyName()];
    std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << ems::empLocation[this->getAgencyLocation()];
    if(!printAllParm)
    {
        std::cout << std::endl;
    }
    if(printAllParm)
    {
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--";
        std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << "--" << std::endl;;
    }
}

const void xyzContractorEmployee::printSingleEmployeeDetails()
{
    std::cout << " Employee Name   : " << this->getEmpName()<< std::endl;
    std::cout << " Employee ID     : " << this->getEmpId()<< std::endl;
    std::cout << " Employee Type   : " << ems::empType[this->getDesignationType()]<< std::endl;
    std::cout << " Employee Status : " << ems::empStatus[this->getDesignationStatus()]<< std::endl;
    std::cout << " Gender          : " << ems::empGender[this->getGender()]<< std::endl;
    std::cout << " Date Of Birth   : " << this->getDateOfBirth()<< std::endl;
    std::cout << " Date Of Joining : " << this->getDateOfJoining()<< std::endl;
    std::cout << " External Agency : " << ems::empAgency[this->getAgencyName()]<< std::endl;
    std::cout << " Agency Location : " << ems::empLocation[this->getAgencyLocation()];
}