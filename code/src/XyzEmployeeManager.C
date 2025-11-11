#include "Utilities.H"
#include "XyzEmployeeManager.H"

xyzEmployeeManager::xyzEmployeeManager()
{
    mActiveandInactiveEmpDeq = new Edll<xyzEmployeeInterface>(); 
    mResignedEmpDeq = new Edll<xyzEmployeeInterface>();
    mStaticEmpId=1;
}

xyzEmployeeManager::~xyzEmployeeManager()
{
    delete mActiveandInactiveEmpDeq;
    mActiveandInactiveEmpDeq = NULL;
    delete mResignedEmpDeq;
    mResignedEmpDeq = NULL;
}

void xyzEmployeeManager::setStaticEmpID()
{
    this->mStaticEmpId++;
}

int xyzEmployeeManager::getStaticEmpID()
{
    return this->mStaticEmpId;
}

void xyzEmployeeManager::addNewEmployee(std::string empIDParam,std::string nameParam,
        ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,std::string dobParam,
            std::string dojParam,std::string dolParam, int noOfLeavesParam, ems::Agency agencyParam,
            ems::Location locationParam,ems::College collegeParam,ems::Branch branchParam)
{
    xyzEmployeeInterface *sNewEmployee = NULL;
    if(typeParam == ems::FullTime)
    {
        sNewEmployee = new xyzFullTimeEmployee(empIDParam,nameParam,typeParam,statusParam,genderParam,dobParam,dojParam,dolParam,noOfLeavesParam);
    }
    else if(typeParam == ems::Contractor)
    {
        sNewEmployee = new xyzContractorEmployee(empIDParam,nameParam,typeParam,statusParam,genderParam,dobParam,dojParam,dolParam,agencyParam,locationParam);
    }
    else if(typeParam == ems::Intern)
    {
        sNewEmployee = new xyzInternEmployee(empIDParam,nameParam,typeParam,statusParam,genderParam,dobParam,dojParam,dolParam,collegeParam,branchParam);
    }

    if(statusParam == ems::Resigned)
    {
        mResignedEmpDeq->pushBack(sNewEmployee);
    }
    else
    {
        mActiveandInactiveEmpDeq->pushBack(sNewEmployee);
    }
}

void xyzEmployeeManager::removeEmployee(std::string empIDParam)
{
    xyzRandomGenerator sRandomGeneratorObj;
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(sEmployee->getEmpId() == empIDParam)
        {
            mActiveandInactiveEmpDeq->removeAtPostion(sIdx);
            sEmployee->setDesignationStatus(ems::Resigned);
            mResignedEmpDeq->pushBack(sEmployee);
            if(sEmployee->getDesignationType() == ems::FullTime)
            {
                sEmployee->setDateOfLeaving(sRandomGeneratorObj.generateRandomDateOfLeaving(sEmployee->getDateOfJoining()));
            }
            break;
        }
        sFrontNode = sFrontNode->mNext;
    }
}

void xyzEmployeeManager::printResignedEmployeeSummary()
{
    EmployeeInfoRecord *sEmpInfo = new EmployeeInfoRecord();
    int sResignedEmpCount = mResignedEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mResignedEmpDeq->getNodeAtPos(0);

    printEmployeeHeader(152, ems::ResignedType);

    int sIdx;
    for(sIdx=0;sIdx<sResignedEmpCount;sIdx++)
    {
        sEmpInfo->clearEmployeeInfoRecord();
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        sEmployee->fillEmployeeTypeDetails(sEmpInfo);
        sEmpInfo->setPrintVal(false);
        sEmpInfo->printEmployeeInfoRecord();
        sFrontNode = sFrontNode->mNext;
    }
    delete sEmpInfo;
}

void xyzEmployeeManager::addRandomEmployee(xyzRandomGenerator randObjParam)
{
    xyzEmployeeInterface *sNewEmployee = NULL;
    int sNoOfEmployees=0;

    std::cout << "Enter No of Random Employees you want to add:" << std::endl;
    std::cin >> sNoOfEmployees; 

    if(isValidInput() && (sNoOfEmployees > 1 && sNoOfEmployees > 1000))
    {
        int sIdx;
        for(sIdx=0;sIdx<sNoOfEmployees;sIdx++)
        {
            std::string sRandName = randObjParam.generateRandomName(randObjParam);
            EmpType sRandEmpType = randObjParam.generateRandomDesignationType();
            std::string sRandEmpID = calculateEmployeeID(this->mStaticEmpId,sRandEmpType);
            setStaticEmpID();
            std::string sRandDOB = randObjParam.generateRandomDateOfBirth();
            std::string sRandDOJ = randObjParam.generateRandomDateOfJoining(sRandDOB);
            EmpGender sRandEmpGender = (randObjParam.mGenderDecideParam == 0 ? ems::Male : ems::Female);
            (randObjParam.mGenderDecideParam == 0 ? (randObjParam.mGenderDecideParam = 1) : (randObjParam.mGenderDecideParam = 0));
            EmpStatus sRandEmpStatus = randObjParam.generateRandomDesignationStatus();

            if(sRandEmpType == ems::FullTime)
            {
                int sRandLeaves = randObjParam.generateRandomNoofLeaves();
                if(sRandEmpStatus == ems::Resigned)
                {
                    std::string sRandDOL = randObjParam.generateRandomDateOfLeaving(sRandDOB);
                    sNewEmployee = new xyzFullTimeEmployee(sRandEmpID,sRandName,sRandEmpType,sRandEmpStatus,sRandEmpGender,sRandDOB,sRandDOJ,sRandDOL,sRandLeaves);
                }
                else
                {
                    sNewEmployee = new xyzFullTimeEmployee(sRandEmpID,sRandName,sRandEmpType,sRandEmpStatus,sRandEmpGender,sRandDOB,sRandDOJ,"N/A",sRandLeaves);
                }
            }
            else if(sRandEmpType == ems::Contractor)
            {
                Agency sRandAgency = randObjParam.generateRandomAgency();
                Location sRandLocation = randObjParam.generateRandomLocation();
                std::string sRandDOL = calculatorContractorLastDate(sRandDOJ);
                sNewEmployee = new xyzContractorEmployee(sRandEmpID,sRandName,sRandEmpType,sRandEmpStatus,sRandEmpGender,sRandDOB,sRandDOJ,sRandDOL,sRandAgency,sRandLocation);
            }
            else if(sRandEmpType == ems::Intern)
            {
                College sRandCollege = randObjParam.generateRandomCollege();
                Branch sRandBranch = randObjParam.generateRandomBranch();
                std::string sRandDOL = calculateInternLastDate(sRandDOJ);
                sNewEmployee = new xyzInternEmployee(sRandEmpID,sRandName,sRandEmpType,sRandEmpStatus,sRandEmpGender,sRandDOB,sRandDOJ,sRandDOL,sRandCollege,sRandBranch);
            }

            if(sRandEmpStatus == ems::Resigned)
            {
                mResignedEmpDeq->pushBack(sNewEmployee);
            }
            else
            {
                mActiveandInactiveEmpDeq->pushBack(sNewEmployee);
            }
        }
    }
    else
    {
        std::cout << "Enter the value between 1-1000" << std::endl;
    }
}

void xyzEmployeeManager::printAllEmployeeSummary()
{
    EmployeeInfoRecord *sEmpInfo = new EmployeeInfoRecord();
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq ? mActiveandInactiveEmpDeq->getNodeAtPos(0) : NULL;

    printEmployeeHeader(270, ems::AllType);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        sEmpInfo->clearEmployeeInfoRecord();
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        sEmployee->fillEmployeeTypeDetails(sEmpInfo);
        sEmpInfo->setPrintVal(true);
        sEmpInfo->printEmployeeInfoRecord();
        sFrontNode = sFrontNode->mNext;
    }
    delete sEmpInfo;
}

void xyzEmployeeManager::printEmpSumByGender(int empGenderParam)
{
    EmployeeInfoRecord *sEmpInfo = new EmployeeInfoRecord();
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    printEmployeeHeader(270, ems::AllType);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(sEmployee->getGender() == empGenderParam)
        {
            sEmpInfo->clearEmployeeInfoRecord();
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo->setPrintVal(false);
            sEmpInfo->printEmployeeInfoRecord();
        }
        sFrontNode = sFrontNode->mNext;
    }
    delete sEmpInfo;
}

void xyzEmployeeManager::printEmpSumByStatus(int empStatusParam)
{
    EmployeeInfoRecord *sEmpInfo = new EmployeeInfoRecord();
    int sEmpCount;
    Node<xyzEmployeeInterface> *sFrontNode = NULL;

    if(empStatusParam == Resigned)
    {
        sEmpCount = mResignedEmpDeq->size();
        sFrontNode = mResignedEmpDeq->getNodeAtPos(0);
        printEmployeeHeader(270, ems::ResignedType);
    }
    else
    {
        sEmpCount = mActiveandInactiveEmpDeq->size();
        sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);
        printEmployeeHeader(270, ems::AllType);
    }

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(empStatusParam == sEmployee->getDesignationStatus())
        {
            sEmpInfo->clearEmployeeInfoRecord();
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo->setPrintVal(true);
            sEmpInfo->printEmployeeInfoRecord();
        }
        sFrontNode = sFrontNode->mNext;
    }
    delete sEmpInfo;
}

void xyzEmployeeManager::printEmpSumByType(int empTypeParam)
{
    EmployeeInfoRecord *sEmpInfo = new EmployeeInfoRecord();
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    if(empTypeParam == ems::FullTime)
    {
        printEmployeeHeader(188,ems::FullTimeType);
    }
    else if(empTypeParam == ems::Contractor)
    {
        printEmployeeHeader(190,ems::ContractorType);
    }
    else
    {
        printEmployeeHeader(190,ems::InternType);
    }

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(empTypeParam == sEmployee->getDesignationType())
        {
            sEmpInfo->clearEmployeeInfoRecord();
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo->setPrintVal(true);
            sEmpInfo->printEmployeeInfoRecord();
        }
        sFrontNode = sFrontNode->mNext;
    }
    delete sEmpInfo;
}

void xyzEmployeeManager::searchEmployeewithID(std::string empIdParam)
{
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);
    int sCheckFlag = 0;

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(empIdParam == sEmployee->getEmpId())
        {
            std::cout << " Employee Name   : " << sEmployee->getEmpName() << std::endl;
            std::cout << " Employee ID     : " << sEmployee->getEmpId() << std::endl;
            std::cout << " Employee Type   : " << ems::empType[sEmployee->getDesignationType()] << std::endl;
            std::cout << " Employee Status : " << ems::empStatus[sEmployee->getDesignationStatus()] << std::endl;
            std::cout << " Gender          : " << ems::empGender[sEmployee->getGender()] << std::endl;
            std::cout << " Date Of Birth   : " << sEmployee->getDateOfBirth() << std::endl;
            std::cout << " Date Of Joining : " << sEmployee->getDateOfJoining() << std::endl;
            if(ems::FullTime == sEmployee->getDesignationType())
            {
                std::cout << " Leaves left     :" << sEmployee->getNoofLeavesAvailed();
            }
            else if(ems::Contractor == sEmployee->getDesignationType())
            {
                std::cout << " External Agency : " << ems::empAgency[sEmployee->getAgencyName()] << std::endl;
                std::cout << " Agency Location : " << ems::empLocation[sEmployee->getAgencyLocation()];
            }
            else
            {
                std::cout << " College         : " << ems::empCollege[sEmployee->getCollege()] << std::endl;
                std::cout << " Branch          : " << ems::empBranch[sEmployee->getBranch()];
            }
            sCheckFlag = 1;
            break;
        }
        sFrontNode = sFrontNode->mNext;
    }
    if(sCheckFlag == 0)
    {
        std::cout << empIdParam << "is not present in our Employee Records." << std::endl;
    }
}

void xyzEmployeeManager::searchEmployeewithName(std::string empNameParam)
{
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    int sIdx, sCheckFlag = 0;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(empNameParam == sEmployee->getEmpName())
        {
            std::cout << " Employee Name   : " << sEmployee->getEmpName() << std::endl;
            std::cout << " Employee ID     : " << sEmployee->getEmpId() << std::endl;
            std::cout << " Employee Type   : " << ems::empType[sEmployee->getDesignationType()] << std::endl;
            std::cout << " Employee Status : " << ems::empStatus[sEmployee->getDesignationStatus()] << std::endl;
            std::cout << " Gender          : " << ems::empGender[sEmployee->getGender()] << std::endl;
            std::cout << " Date Of Birth   : " << sEmployee->getDateOfBirth() << std::endl;
            std::cout << " Date Of Joining : " << sEmployee->getDateOfJoining() << std::endl;
            if(ems::FullTime == sEmployee->getDesignationType())
            {
                std::cout << " Leaves left     :" << sEmployee->getNoofLeavesAvailed();
            }
            else if(ems::Contractor == sEmployee->getDesignationType())
            {
                std::cout << " External Agency : " << ems::empAgency[sEmployee->getAgencyName()] << std::endl;
                std::cout << " Agency Location : " << ems::empLocation[sEmployee->getAgencyLocation()];
            }
            else
            {
                std::cout << " College         : " << ems::empCollege[sEmployee->getCollege()] << std::endl;
                std::cout << " Branch          : " << ems::empBranch[sEmployee->getBranch()];
            }
            sCheckFlag = 1;
            break;
        }
        sFrontNode = sFrontNode->mNext;
    }
    if(sCheckFlag == 0)
    {
        std::cout << empNameParam << "is not present in our Employee Records." << std::endl;
    }
}

void xyzEmployeeManager::convertInternToFullTimeEmployee(std::string empIdParam, xyzRandomGenerator randomobjParam)
{
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);
    int sEmpFlag = 0; 

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(sEmployee->getEmpId() == empIdParam)
        {
            if(sEmployee->getDesignationType() == ems::Contractor || sEmployee->getDesignationType() == ems::Intern)
            {
                std::string sEmpName = sEmployee->getEmpName();
                std::string sEmpDOJ = sEmployee->getDateOfJoining();
                std::string sEmpDOB = sEmployee->getDateOfBirth();
                EmpGender sEmpGender = sEmployee->getGender();
                EmpStatus sEmpStatus = sEmployee->getDesignationStatus();
                int sNoOfLeaves = randomobjParam.generateRandomNoofLeaves();
                std::string sEmpIdParam = empIdParam.substr(0,7) + "F";

                xyzEmployeeInterface *sNewFullTimeEmployee = new xyzFullTimeEmployee(sEmpIdParam,sEmpName,ems::FullTime,sEmpStatus,sEmpGender,sEmpDOB,sEmpDOJ,"N/A",sNoOfLeaves);

                delete sFrontNode->mData;
                sFrontNode->mData = sNewFullTimeEmployee;
                sEmpFlag = 1;
            }
            else
            {
                std::cout << "Already a Full time Employee." << std::endl;
                sEmpFlag = 1;
            }
            
        }
        sFrontNode = sFrontNode->mNext;
    }
    if(sEmpFlag == 0)
    {
        std::cout << "EmployeeId is Not Available." << std::endl;
    }
}

void xyzEmployeeManager::addNoOfLeavestoallFullTimeEmployees(int noOfleavesParam)
{
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(ems::FullTime == sEmployee->getDesignationType())
        {
            sEmployee->addNoOfleavestoFullTimeEmployees(noOfleavesParam);
        }
        sFrontNode = sFrontNode->mNext;
    }
}

int xyzEmployeeManager::getsize()
{
    return mActiveandInactiveEmpDeq->size();
}

void xyzEmployeeManager::checkFunc()
{
    std::cout << "Active size in checkFunc: " << mActiveandInactiveEmpDeq->size() << std::endl;
    std::cout << "Resigned size in checkFunc: " << mResignedEmpDeq->size() << std::endl;
}