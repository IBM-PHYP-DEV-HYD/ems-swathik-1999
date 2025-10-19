#include <iostream>
#include <string>

using namespace std;

#include "Utilities.H"
#include "XyzEmployeeManager.H"
#include "XyzRandomGenerator.H"

void processAddEmployee(xyzEmployeeManager *empManagerObj, xyzRandomGenerator randomObjParam)
{
    int sAddMenuChoice=0,sChoice = 1,sEmpNoofLeaves,sCheckFlag=0;

    string sEmpName,sEmpId,sEmpDOB,sEmpDOJ,sEmpDOL;
    EmpType sEmpType;
    EmpStatus sEmpStatus;
    EmpGender sEmpGender;
    College sEmpCollege;
    Branch sEmpBranch;
    Agency sEmpAgency;
    Location sEmpLocation;

    while(true)
    {
        addEmployeeMenu();
        cin >> sAddMenuChoice;

        switch(sAddMenuChoice)
        {
            case ems::AddMenu::Random:
            {
                empManagerObj->addRandomEmployee(randomObjParam);
                break;
            }
            case ems::AddMenu::Type:
            {
                getDesignationTypeBasedMenu();
                cin >> sChoice;

                if(isValidInput() && sChoice != -1 && (sChoice > 0 && sChoice < 4))
                {
                    sEmpType = (EmpType)sChoice;

                    cout << "Enter Employee Name:";
                    cin >> sEmpName;
                    if(isValidInput())
                    {
                        sEmpDOB = randomObjParam.generateRandomDateOfBirth();
                        sEmpDOJ = randomObjParam.generateRandomDateOfJoining(sEmpDOB);

                        cout << "Enter Employee Gender: \n 1. Female \n 2. Male \n 3. Others"<< endl;
                        cin >> sChoice;

                        if(isValidInput() && (sChoice > 0 && sChoice < 4))
                        {
                            sEmpGender = (EmpGender)sChoice;
                            sEmpId = calculateEmployeeID(empManagerObj->getStaticEmpID(),sEmpType);
                            empManagerObj->setStaticEmpID();

                            cout << "Enter Employee Status: \n 1. Active \n 2. InActive \n 3. Resigned"<< endl;
                            cin >> sChoice;
                            if(isValidInput() && (sChoice > 0 && sChoice < 4))
                            {
                                sEmpStatus = (EmpStatus)sChoice;
                                if(sEmpType == ems::Contractor)
                                {
                                    sEmpDOL = calculatorContractorLastDate(sEmpDOJ);
                                    getEmployeeAgency();
                                    cin>>sChoice;

                                    if(isValidInput())
                                    {
                                        sEmpAgency = (Agency)sChoice;

                                        contractorAgencyLocationDetails();
                                        cin >> sChoice;
                                        if(isValidInput())
                                        {
                                            sEmpLocation = (Location)sChoice;
                                            sCheckFlag = 1;
                                        }
                                    }
                                }
                                else if(sEmpType == ems::Intern)
                                {
                                    sEmpDOL = calculateInternLastDate(sEmpDOJ);
                                    internCollegeDetails();
                                    cin >> sChoice;
                                    if(isValidInput())
                                    {
                                        sEmpCollege = (College)sChoice;

                                        internBranchDetails();
                                        cin >> sChoice;
                                        if(isValidInput())
                                        {
                                            sEmpBranch = (Branch)sChoice;
                                            sCheckFlag = 1;
                                        }
                                    }
                                }
                                else if(sEmpType == ems::FullTime && sEmpStatus == ems::Resigned)
                                {
                                    sEmpDOL = randomObjParam.generateRandomDateOfLeaving(sEmpDOJ);
                                    sEmpNoofLeaves = randomObjParam.generateRandomNoofLeaves();
                                    sCheckFlag = 1;
                                }
                                if(sCheckFlag == 1 || sEmpType == ems::FullTime)
                                {
                                    empManagerObj->addNewEmployee(sEmpId,sEmpName,sEmpType,sEmpStatus,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpNoofLeaves,sEmpAgency,sEmpLocation,sEmpCollege,sEmpBranch);
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "Enter Valid Employee Name." << endl;
                    }
                }
                break;
            }
            case ems::AddMenu::ExitAddMenu:
            {
                return;
            }
            default:
                cout << "Enter a Valid Input" << endl;
            break;
        }

    }
}

void processGetEmployee(xyzEmployeeManager *empManagerObjParam)
{
    int sGetMenuchoice = 1,sGetEmpByTypeChoice = 1,sGetEmpByGenderChoice = 1,sGetEmpByStatusChoice = 1;

    string sEmpIdUserInput;

    while(1)
    {
        getEmployeeMenu();
        cin >> sGetMenuchoice;

        if(isValidInput())
        {
            switch(sGetMenuchoice)
            {
                case ems::GetMenu::AllSummary:
                {
                    empManagerObjParam->printAllEmployeeSummary();
                    break;
                }
                case ems::GetMenu::ByType:
                {
                    getDesignationTypeBasedMenu();
                    cin >> sGetEmpByTypeChoice;
                    if(isValidInput() && sGetEmpByTypeChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByType(sGetEmpByTypeChoice);
                    }
                    break;
                }
                case ems::GetMenu::ByGender:
                {
                    getGenderBasedMenu();
                    cin >> sGetEmpByGenderChoice;
                    if(isValidInput() && sGetEmpByGenderChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByGender(sGetEmpByGenderChoice);
                    }
                    break;
                }
                case ems::GetMenu::ByStatus:
                {
                    getDesignationStatusBaseMenu();
                    cin >> sGetEmpByStatusChoice;
                    if(isValidInput() && sGetEmpByStatusChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByStatus(sGetEmpByStatusChoice);
                    }
                    break;
                }
                case ems::GetMenu::SingleEmployee:
                {
                    cout << "Enter Employee Id: " << endl;
                    cin >> sEmpIdUserInput;
                    if(isValidEmpId(sEmpIdUserInput))
                    {
                        empManagerObjParam->searchEmployeewithID(sEmpIdUserInput);
                    }
                    break;
                }
                case ems::GetMenu::ExitGetMenu:
                {
                    return;
                    break;
                }
            }
        }
    }
}

void othersMenu(xyzEmployeeManager *empManagerObjParam, xyzRandomGenerator randObjParam)
{
    int sOtherMenuChoice;

    doSomethingElseMenu();
    cin >> sOtherMenuChoice;

    if(isValidInput())
    {
        switch(sOtherMenuChoice)
        {
            case ems::OthersMenu::AddLeaves:
            {
                int sUserInputLeaves;
                cout << "Enter No of leaves:";
                cin >> sUserInputLeaves;
                if(isValidInput())
                {
                    empManagerObjParam->addNoOfLeavestoallFullTimeEmployees(sUserInputLeaves);
                }
                break;
            }
            case ems::OthersMenu::ConvertToFullTimeEmp:
            {
                string sEmpIDInput;
                cout << "Enter Employee ID :";
                cin >> sEmpIDInput;
                if(isValidEmpId(sEmpIDInput))
                {
                    empManagerObjParam->convertInternToFullTimeEmployee(sEmpIDInput,randObjParam);
                }
                break;
            }
            case ems::OthersMenu::SearchById:
            {
                string sEmpIDInput;
                cout << "Enter Employee ID :";
                cin >> sEmpIDInput;
                if(isValidEmpId(sEmpIDInput))
                {
                    empManagerObjParam->searchEmployeewithID(sEmpIDInput);
                }
                break;
            }
            case ems::OthersMenu::SearchByName:
            {
                string sEmpNameInput;
                cout << "Enter Employee Name :";
                cin.clear();
                cin.ignore();
                getline(cin,sEmpNameInput);
                empManagerObjParam->searchEmployeewithName(sEmpNameInput);
                break;
            }
            case ems::OthersMenu::ExitOtherMenu:
            {
                return;
                break;
            }
            default:
            break;
        }
    }
}

int main()
{
    srand(time(0));
    xyzEmployeeManager *sEmpManager = new xyzEmployeeManager();
    int sMainMenuOption = 0;
    xyzRandomGenerator sRandomGeneratorobj;

    while(1)
    {
        mainMenu();
        cin >> sMainMenuOption;

        if(isValidInput())
        {
            switch(sMainMenuOption)
            {
                case ems::MainMenu::AddEmployee:
                {
                    processAddEmployee(sEmpManager,sRandomGeneratorobj);
                    break;
                }
                case ems::MainMenu::RemoveEmployee:
                {
                    string sUserInputEmpId;
                    cout << "Enter the EmpLoyee Id:" <<endl;
                    cin >> sUserInputEmpId;
                    if(isValidEmpId(sUserInputEmpId))
                    {   
                        sEmpManager->removeEmployee(sUserInputEmpId);
                    }
                    break;
                }
                case ems::MainMenu::GetEmployee:
                {
                    processGetEmployee(sEmpManager);
                    break;
                }
                case ems::MainMenu::Others:
                {
                    othersMenu(sEmpManager,sRandomGeneratorobj);
                    break;
                }
                case ems::MainMenu::ExitMainMenu:
                {
                    exit(EXIT_SUCCESS);
                }
                default:
                    cout << "Enter a Valid Input";
                break;
            }
        }
    }
}