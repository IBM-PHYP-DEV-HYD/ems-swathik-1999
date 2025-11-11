#include "EmployeeInfoRecord.H"

EmployeeInfoRecord::EmployeeInfoRecord()
{
    mNoOfLeaves=0;
    mTotalNoOfLeaves=0;
}

EmployeeInfoRecord::~EmployeeInfoRecord()
{

}

void EmployeeInfoRecord::clearEmployeeInfoRecord()
{
    mEmpName.clear();
    mEmpId.clear();
    mEmpDesignationType.clear();
    mEmpDesignationStatus.clear();
    mEmpGender.clear();
    mDateOfBirth.clear();
    mDateOfJoining.clear();
    mDateOfLeaving.clear();
    mNoOfLeaves=0;
    mTotalNoOfLeaves=0;
    mAgencyName.clear();
    mAgencyLocation.clear();
    mCollege.clear();
    mCollegeBranch.clear();
}

bool EmployeeInfoRecord::getPrintVal()
{
    return this->mPrintAll;
}

void EmployeeInfoRecord::setPrintVal(bool valParm)
{
    this->mPrintAll = valParm;
}

const std::string EmployeeInfoRecord::getEmpName()
{
    return this->mEmpName;
}

void EmployeeInfoRecord::setEmpName(std::string empNameParm)
{
    this->mEmpName = empNameParm;
}

const std::string EmployeeInfoRecord::getEmpId()
{
    return this->mEmpId;
}

void EmployeeInfoRecord::setEmpId(std::string empIdParm)
{
    this->mEmpId = empIdParm;
}

const std::string EmployeeInfoRecord::getEmpStatus()
{
    return this->mEmpDesignationStatus;
}

void EmployeeInfoRecord::setEmpStatus(std::string empStatusParm)
{
    this->mEmpDesignationStatus = empStatusParm;
}

const std::string EmployeeInfoRecord::getEmpType()
{
    return this->mEmpDesignationType;
}

void EmployeeInfoRecord::setEmpType(std::string empTypeParm)
{
    this->mEmpDesignationType = empTypeParm;
}

const std::string EmployeeInfoRecord::getEmpGender()
{
    return this->mEmpGender;
}

void EmployeeInfoRecord::setEmpGender(std::string empGenderParm)
{
    this->mEmpGender = empGenderParm;
}

const std::string EmployeeInfoRecord::getDOB()
{
    return this->mDateOfBirth;
}

const std::string EmployeeInfoRecord::getDOJ()
{
    return this->mDateOfJoining;
}

const std::string EmployeeInfoRecord::getDOL()
{
    return this->mDateOfLeaving;
}

const std::string EmployeeInfoRecord::getCollege()
{
    return this->mCollege;
}

const std::string EmployeeInfoRecord::getBranch()
{
    return this->mCollegeBranch;
}

const std::string EmployeeInfoRecord::getAgency()
{
    return this->mAgencyName;
}

const std::string EmployeeInfoRecord::getLocation()
{
    return this->mAgencyLocation;
}

const int EmployeeInfoRecord::getNoOfLeaves()
{
    return this->mNoOfLeaves;
}

const int EmployeeInfoRecord::getTotalLeaves()
{
    return this->mTotalNoOfLeaves;
}

void EmployeeInfoRecord::setDOB(std::string dobParm)
{
    this->mDateOfBirth = dobParm;
}

void EmployeeInfoRecord::setDOJ(std::string dojParm)
{
    this->mDateOfJoining = dojParm;
}

void EmployeeInfoRecord::setDOL(std::string dolParm)
{
    this->mDateOfLeaving = dolParm;
}

void EmployeeInfoRecord::setCollege(std::string collegeParm)
{
    this->mCollege = collegeParm;
}

void EmployeeInfoRecord::setBranch(std::string branchParm)
{
    this->mCollegeBranch = branchParm;
}

void EmployeeInfoRecord::setAgency(std::string agencyParm)
{
    this->mAgencyName = agencyParm;
}

void EmployeeInfoRecord::setLocation(std::string locationParm)
{
    this->mAgencyLocation = locationParm;
}

void EmployeeInfoRecord::setNoOfLeaves(int leaveParm)
{
    this->mNoOfLeaves = leaveParm;
}

void EmployeeInfoRecord::setTotalLeaves(int totalParm)
{
    this->mTotalNoOfLeaves = totalParm;
}

void EmployeeInfoRecord::printEmployeeDetails()
{

}

void EmployeeInfoRecord::printEmployeeInfoRecord()
{
    std::cout << "| "<< std::left << std::setw(24) << std::setfill(' ') << getEmpName();
    std::cout << "| "<< std::left << std::setw(12)<< std::setfill(' ') << getEmpId();
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << getEmpType();
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << getEmpStatus();
    std::cout << "| "<< std::left << std::setw(14)<< std::setfill(' ') << getEmpGender();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << getDOB();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << getDOJ();
    std::cout << "| "<< std::left << std::setw(18)<< std::setfill(' ') << getDOL();

    if(getEmpStatus() != "Resigned")
    {
        if(getPrintVal() == true)
        {
            if(getEmpType() == "FullTime")
            {
                std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << getTotalLeaves();    
                std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << getNoOfLeaves();
            }
            else
            {
                std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << "--";    
                std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << "--";
            }
            std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << (getAgency().length() ? mAgencyName : "--");
            std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << (getLocation().length() ? mAgencyLocation : "--");
            std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << (getCollege().length() ? mCollege : "--");
            std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << (getBranch().length() ? mCollegeBranch : "--");
        }
        else
        {
            if(mEmpDesignationType == "FullTime")
            {
                std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') << getTotalLeaves() << std::endl;
                std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') << getNoOfLeaves();
            }
            else if(mEmpDesignationType == "Contractor")
            {
                std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') << (getAgency().length() ? mAgencyName : "--");
                std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') << (getLocation().length() ? mAgencyLocation : "--");
            }
            else if(mEmpDesignationType == "Intern")
            {
                std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') << (getCollege().length() ? mCollege : "--");
                std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') << (getBranch().length() ? mCollegeBranch : "--");
            }
        }
    }
    std::cout << std::endl;
}