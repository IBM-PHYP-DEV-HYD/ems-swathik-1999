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

void xyzEmployeeManager::addNewEmployee(string empIDParam,string nameParam,
        ems::EmpType typeParam,ems::EmpStatus statusParam,
            ems::EmpGender genderParam,string dobParam,
            string dojParam,string dolParam, int noOfLeavesParam, ems::Agency agencyParam,
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

void xyzEmployeeManager::removeEmployee(string empIDParam)
{
    xyzRandomGenerator sRandomGeneratorObj;
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    int sIdx;
    for(sIdx=1;sIdx<sEmpCount;sIdx++)
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
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::printResignedEmployeeSummary()
{
    EmployeeInfo sEmpInfo;
    int sResignedEmpCount = mResignedEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mResignedEmpDeq->getNodeAtPos(0);

    printEmployeeHeader(152, ems::ResignedType);

    int sIdx;
    for(sIdx=0;sIdx<sResignedEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        sEmployee->fillEmployeeDetails(sEmpInfo);
        sEmpInfo.mPrintAll=false;
        sEmpInfo.printEmployeeInfo();
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::addRandomEmployee(xyzRandomGenerator randObjParam)
{
    xyzEmployeeInterface *sNewEmployee = NULL;

    string sRandName = randObjParam.generateRandomName(randObjParam);
    EmpType sRandEmpType = randObjParam.generateRandomDesignationType();
    string sRandEmpID = calculateEmployeeID(this->mStaticEmpId,sRandEmpType);
    setStaticEmpID();
    string sRandDOB = randObjParam.generateRandomDateOfBirth();
    string sRandDOJ = randObjParam.generateRandomDateOfJoining(sRandDOB);
    EmpGender sRandEmpGender = (randObjParam.mGenderDecideParam == 0 ? ems::Male : ems::Female);
    (randObjParam.mGenderDecideParam == 0 ? (randObjParam.mGenderDecideParam = 1) : (randObjParam.mGenderDecideParam = 0));
    EmpStatus sRandEmpStatus = randObjParam.generateRandomDesignationStatus();

    if(sRandEmpType == ems::FullTime)
    {
        int sRandLeaves = randObjParam.generateRandomNoofLeaves();
        if(sRandEmpStatus == ems::Resigned)
        {
            string sRandDOL = randObjParam.generateRandomDateOfLeaving(sRandDOB);
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
        string sRandDOL = calculatorContractorLastDate(sRandDOJ);
        sNewEmployee = new xyzContractorEmployee(sRandEmpID,sRandName,sRandEmpType,sRandEmpStatus,sRandEmpGender,sRandDOB,sRandDOJ,sRandDOL,sRandAgency,sRandLocation);
    }
    else if(sRandEmpType == ems::Intern)
    {
        College sRandCollege = randObjParam.generateRandomCollege();
        Branch sRandBranch = randObjParam.generateRandomBranch();
        string sRandDOL = calculateInternLastDate(sRandDOJ);
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

void xyzEmployeeManager::printAllEmployeeSummary()
{
    EmployeeInfo sEmpInfo;
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq ? mActiveandInactiveEmpDeq->getNodeAtPos(0) : NULL;

    printEmployeeHeader(270, ems::AllType);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        sEmpInfo.clearEmployeeInfo();
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        sEmployee->fillEmployeeDetails(sEmpInfo);
        sEmployee->fillEmployeeTypeDetails(sEmpInfo);
        sEmpInfo.mPrintAll=true;
        sEmpInfo.printEmployeeInfo();
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::printEmpSumByGender(int empGenderParam)
{
    EmployeeInfo sEmpInfo;
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    printEmployeeHeader(270, ems::AllType);

    int sIdx;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(sEmployee->getGender() == empGenderParam)
        {
            sEmpInfo.clearEmployeeInfo();
            sEmployee->fillEmployeeDetails(sEmpInfo);
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo.mPrintAll=false;
            sEmpInfo.printEmployeeInfo();
        }
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::printEmpSumByStatus(int empStatusParam)
{
    EmployeeInfo sEmpInfo;
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
            sEmpInfo.clearEmployeeInfo();
            sEmployee->fillEmployeeDetails(sEmpInfo);
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo.mPrintAll=true;
            sEmpInfo.printEmployeeInfo();
        }
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::printEmpSumByType(int empTypeParam)
{
    EmployeeInfo sEmpInfo;
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
            sEmpInfo.clearEmployeeInfo();
            sEmployee->fillEmployeeDetails(sEmpInfo);
            sEmployee->fillEmployeeTypeDetails(sEmpInfo);
            sEmpInfo.mPrintAll=false;
            sEmpInfo.printEmployeeInfo();
        }
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::searchEmployeewithID(string empIdParam)
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
            cout << " Employee Name   : " << sEmployee->getEmpName() << endl;
            cout << " Employee ID     : " << sEmployee->getEmpId() << endl;
            cout << " Employee Type   : " << ems::empType[sEmployee->getDesignationType()] << endl;
            cout << " Employee Status : " << ems::empStatus[sEmployee->getDesignationStatus()] << endl;
            cout << " Gender          : " << ems::empGender[sEmployee->getGender()] << endl;
            cout << " Date Of Birth   : " << sEmployee->getDateOfBirth() << endl;
            cout << " Date Of Joining : " << sEmployee->getDateOfJoining() << endl;
            cout << " Date Of Leaving : " << sEmployee->getDateOfLeaving() << endl;
            if(ems::FullTime == sEmployee->getDesignationType())
            {
                cout << " Leaves left     :" << sEmployee->getNoofLeavesAvailed();
            }
            else if(ems::Contractor == sEmployee->getDesignationType())
            {
                cout << " External Agency : " << ems::empAgency[sEmployee->getAgencyName()] << endl;
                cout << " Agency Location : " << ems::empLocation[sEmployee->getAgencyLocation()];
            }
            else
            {
                cout << " College         : " << ems::empCollege[sEmployee->getCollege()] << endl;
                cout << " Branch          : " << ems::empBranch[sEmployee->getBranch()];
            }
            sCheckFlag = 1;
            break;
        }
        sFrontNode = sFrontNode->mTail;
    }
    if(sCheckFlag == 0)
    {
        cout << empIdParam << "is not present in our Employee Records." << endl;
    }
}

void xyzEmployeeManager::searchEmployeewithName(string empNameParam)
{
    int sEmpCount = mActiveandInactiveEmpDeq->size();
    Node<xyzEmployeeInterface> *sFrontNode = mActiveandInactiveEmpDeq->getNodeAtPos(0);

    int sIdx, sCheckFlag = 0;
    for(sIdx=0;sIdx<sEmpCount;sIdx++)
    {
        xyzEmployeeInterface *sEmployee = sFrontNode->mData;
        if(empNameParam == sEmployee->getEmpName())
        {
            cout << " Employee Name   : " << sEmployee->getEmpName() << endl;
            cout << " Employee ID     : " << sEmployee->getEmpId() << endl;
            cout << " Employee Type   : " << ems::empType[sEmployee->getDesignationType()] << endl;
            cout << " Employee Status : " << ems::empStatus[sEmployee->getDesignationStatus()] << endl;
            cout << " Gender          : " << ems::empGender[sEmployee->getGender()] << endl;
            cout << " Date Of Birth   : " << sEmployee->getDateOfBirth() << endl;
            cout << " Date Of Joining : " << sEmployee->getDateOfJoining() << endl;
            if(ems::FullTime == sEmployee->getDesignationType())
            {
                cout << " Leaves left     :" << sEmployee->getNoofLeavesAvailed();
            }
            else if(ems::Contractor == sEmployee->getDesignationType())
            {
                cout << " External Agency : " << ems::empAgency[sEmployee->getAgencyName()] << endl;
                cout << " Agency Location : " << ems::empLocation[sEmployee->getAgencyLocation()];
            }
            else
            {
                cout << " College         : " << ems::empCollege[sEmployee->getCollege()] << endl;
                cout << " Branch          : " << ems::empBranch[sEmployee->getBranch()];
            }
            sCheckFlag = 1;
            break;
        }
        sFrontNode = sFrontNode->mTail;
    }
    if(sCheckFlag == 0)
    {
        cout << empNameParam << "is not present in our Employee Records." << endl;
    }
}

void xyzEmployeeManager::convertInternToFullTimeEmployee(string empIdParam, xyzRandomGenerator randomobjParam)
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
                string sEmpName = sEmployee->getEmpName();
                string sEmpDOJ = sEmployee->getDateOfJoining();
                string sEmpDOB = sEmployee->getDateOfBirth();
                EmpGender sEmpGender = sEmployee->getGender();
                EmpStatus sEmpStatus = sEmployee->getDesignationStatus();
                int sNoOfLeaves = randomobjParam.generateRandomNoofLeaves();
                string sEmpIdParam = empIdParam.substr(0,7) + "F";
                cout << "sEmpIdParam :" << sEmpIdParam << endl;

                xyzEmployeeInterface *sNewFullTimeEmployee = new xyzFullTimeEmployee(sEmpIdParam,sEmpName,ems::FullTime,sEmpStatus,sEmpGender,sEmpDOB,sEmpDOJ,"N/A",sNoOfLeaves);

                sFrontNode->mData = sNewFullTimeEmployee;
                sEmpFlag = 1;
            }
            else
            {
                cout << "Already a Full time Employee." << endl;
                sEmpFlag = 1;
            }
        }
        sFrontNode = sFrontNode->mTail;
    }
    if(sEmpFlag == 0)
    {
        cout << "EmployeeId is Not Available." << endl;
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
        sFrontNode = sFrontNode->mTail;
    }
}

void xyzEmployeeManager::checkFunc()
{
    cout << "Active size in checkFunc: " << mActiveandInactiveEmpDeq->size() << endl;
    cout << "Resigned size in checkFunc: " << mResignedEmpDeq->size() << endl;
}