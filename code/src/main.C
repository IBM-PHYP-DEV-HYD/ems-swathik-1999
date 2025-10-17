#include <iostream>
#include <string>

using namespace std;

#include "Utilities.H"
#include "XyzEmployeeManager.H"
#include "XyzRandomGenerator.H"

void processAddEmployee(xyzEmployeeManager *empManagerObj)
{
    int sAddMenuChoice=0;
    xyzRandomGenerator sRandomGeneratorobj;

    int sEmpTypeChoice=1, sEmpGenderChoice=1,sAgencyChoice=1,sLocationChoice=1,sCollegeChoice=1,sBranchChoice=1,sEmpNoofLeaves=0;

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
                empManagerObj->addRandomEmployee(sRandomGeneratorobj);
                break;
            }
            case ems::AddMenu::Type:
            {
                getDesignationTypeBasedMenu();
                cin >> sEmpTypeChoice;

                if(isValidInput())
                {
                   sEmpType = (EmpType)sEmpTypeChoice;
                    
                    cout << "Enter your Name:";
                    cin >> sEmpName;
                    if(isValidInput())
                    {
                        cout << "Enter your Date Of Birth in (DD-MM-YY) format:";
                        cin >> sEmpDOB;

                        cout << "Enter your Date of Joining in (DD-MM-YY) format:";
                        cin >> sEmpDOJ;

                        cout << "Enter your Gender: \n 1. Female \n 2. Male \n 3. Others"<< endl;
                        cin >> sEmpGenderChoice;

                        if(isValidInput())
                        {
                            sEmpGender = (EmpGender)sEmpGenderChoice;
                            cout << "sEmpGender " << sEmpGender << endl;
                            sEmpId = calculateEmployeeID(empManagerObj->getStaticEmpID(),sEmpType);
                            empManagerObj->setStaticEmpID();

                            sEmpStatus = sRandomGeneratorobj.generateRandomDesignationStatus();

                            if(sEmpType == ems::Contractor)
                            {
                                sEmpDOL = calculatorContractorLastDate(sEmpDOJ);
                                getEmployeeAgency();
                                cin>>sAgencyChoice;

                                sEmpAgency = (Agency)sAgencyChoice;

                                contractorAgencyLocationDetails();
                                cin >> sLocationChoice;

                                sEmpLocation = (Location)sLocationChoice;
                            }
                            else if(sEmpType == ems::Intern)
                            {
                                sEmpDOL = calculateInternLastDate(sEmpDOJ);
                                internCollegeDetails();
                                cin >> sCollegeChoice;

                                sEmpCollege = (College)sCollegeChoice;

                                internBranchDetails();
                                cin >> sBranchChoice;

                                sEmpBranch = (Branch)sBranchChoice;
                            }
                            else if(sEmpType == ems::FullTime && sEmpStatus == ems::Resigned)
                            {
                                sEmpDOL = sRandomGeneratorobj.generateRandomDateOfLeaving(sEmpDOJ);

                                sEmpNoofLeaves = sRandomGeneratorobj.generateRandomNoofLeaves();
                            }
                        }
                    }
                }
                empManagerObj->addNewEmployee(sEmpId,sEmpName,sEmpType,sEmpStatus,sEmpGender,sEmpDOB,sEmpDOJ,sEmpDOL,sEmpNoofLeaves,sEmpAgency,sEmpLocation,sEmpCollege,sEmpBranch);
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
                empManagerObjParam->searchEmployeewithID(sEmpIdUserInput);
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

void othersMenu(xyzEmployeeManager *empManagerObjParam)
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
                empManagerObjParam->addNoOfLeavestoallFullTimeEmployees(sUserInputLeaves);
                break;
            }
            case ems::OthersMenu::ConvertToFullTimeEmp:
            {
                string sEmpIDInput;
                cout << "Enter Employee ID :";
                cin >> sEmpIDInput;
                empManagerObjParam->convertInternToFullTimeEmployee(sEmpIDInput);
                break;
            }
            case ems::OthersMenu::SearchById:
            {
                string sEmpIDInput;
                cout << "Enter Employee ID :";
                cin >> sEmpIDInput;
                empManagerObjParam->searchEmployeewithID(sEmpIDInput);
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
                    processAddEmployee(sEmpManager);
                    break;
                }
                case ems::MainMenu::RemoveEmployee:
                {
                    string sUserInputEmpId;
                    cout << "Enter the EmpLoyee Id:" <<endl;
                    cin >> sUserInputEmpId;
                    sEmpManager->removeEmployee(sUserInputEmpId);
                    break;
                }
                case ems::MainMenu::GetEmployee:
                {
                     sEmpManager->checkFunc();
                    processGetEmployee(sEmpManager);
                    break;
                }
                case ems::MainMenu::Others:
                {
                    othersMenu(sEmpManager);
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