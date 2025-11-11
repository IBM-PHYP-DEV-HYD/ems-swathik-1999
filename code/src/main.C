#include <iostream>
#include <string>

#include "Utilities.H"
#include "XyzEmployeeManager.H"
#include "XyzRandomGenerator.H"

void processAddEmployee(xyzEmployeeManager *empManagerObj, xyzRandomGenerator randomObjParam)
{
    int sAddMenuChoice=0,sChoice = 1,sRetValue=1;

    std::string sEmpName;
    EmpType sEmpType;
    EmpGender sEmpGender;

    while(sRetValue)
    {
        addEmployeeMenu();
        std::cin >> sAddMenuChoice;

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
                std::cin >> sChoice;

                if(isValidInput() && (sChoice > 0 && sChoice < 4))
                {
                    sEmpType = (EmpType)sChoice;

                    std::cout << "Enter Employee Name:";
                    std::cin >> sEmpName;

                    std::cout << "Enter Gender \n 1.Male \n 2.Female \n 3.Others \n" << std::endl;;
                    std::cin >> sChoice;

                    sEmpGender = (EmpGender)sChoice;
                    if(isValidInput())
                    { 
                        empManagerObj->addNewEmployee(sEmpName,sEmpType,sEmpGender,randomObjParam);
                    }
                    else
                    {
                        std::cout << "Enter Valid Employee Name." << std::endl;
                    }
                }
                break;
            }
            case ems::AddMenu::ExitAddMenu:
            {
                sRetValue=0;
            }
            default:
            break;
        }
    }
}

void processGetEmployee(xyzEmployeeManager *empManagerObjParam)
{
    int sGetMenuchoice = 1,sGetEmpByTypeChoice = 1,sGetEmpByGenderChoice = 1,sGetEmpByStatusChoice = 1;
    int sRetValue=1;
    std::string sEmpIdUserInput;

    while(sRetValue)
    {
        getEmployeeMenu();
        std::cin >> sGetMenuchoice;

        if(sGetMenuchoice == -1 || isValidInput())
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
                    std::cin >> sGetEmpByTypeChoice;
                    if(isValidInput() && sGetEmpByTypeChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByType(sGetEmpByTypeChoice);
                    }
                    break;
                }
                case ems::GetMenu::ByGender:
                {
                    getGenderBasedMenu();
                    std::cin >> sGetEmpByGenderChoice;
                    if(isValidInput() && sGetEmpByGenderChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByGender(sGetEmpByGenderChoice);
                    }
                    break;
                }
                case ems::GetMenu::ByStatus:
                {
                    getDesignationStatusBaseMenu();
                    std::cin >> sGetEmpByStatusChoice;
                    if(isValidInput() && sGetEmpByStatusChoice != -1)
                    {
                        empManagerObjParam->printEmpSumByStatus(sGetEmpByStatusChoice);
                    }
                    break;
                }
                case ems::GetMenu::SingleEmployee:
                {
                    std::cout << "Enter Employee Id: " << std::endl;
                    std::cin >> sEmpIdUserInput;
                    if(isValidEmpId(sEmpIdUserInput))
                    {
                        empManagerObjParam->searchEmployeewithID(sEmpIdUserInput);
                    }
                    break;
                }
                case ems::GetMenu::ExitGetMenu:
                {
                    sRetValue=0;
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
    std::cin >> sOtherMenuChoice;

    if(sOtherMenuChoice == -1 || isValidInput())
    {
        switch(sOtherMenuChoice)
        {
            case ems::OthersMenu::AddLeaves:
            {
                int sUserInputLeaves;
                std::cout << "Enter No of leaves:";
                std::cin >> sUserInputLeaves;
                if(isValidInput())
                {
                    empManagerObjParam->addNoOfLeavestoallFullTimeEmployees(sUserInputLeaves);
                }
                break;
            }
            case ems::OthersMenu::ConvertToFullTimeEmp:
            {
                std::string sEmpIDInput;
                std::cout << "Enter Employee ID :";
                std::cin >> sEmpIDInput;
                if(isValidEmpId(sEmpIDInput))
                {
                    empManagerObjParam->convertInternToFullTimeEmployee(sEmpIDInput,randObjParam);
                }
                break;
            }
            case ems::OthersMenu::SearchById:
            {
                std::string sEmpIDInput;
                std::cout << "Enter Employee ID :";
                std::cin >> sEmpIDInput;
                if(isValidEmpId(sEmpIDInput))
                {
                    empManagerObjParam->searchEmployeewithID(sEmpIDInput);
                }
                break;
            }
            case ems::OthersMenu::SearchByName:
            {
                std::string sEmpNameInput;
                std::cout << "Enter Employee Name :";
                std::cin.clear();
                std::cin.ignore();
                getline(std::cin,sEmpNameInput);
                empManagerObjParam->searchEmployeewithName(sEmpNameInput);
                break;
            }
            case ems::OthersMenu::ExitOtherMenu:
            {
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
    int sMainMenuOption = 0, sRetVal = 1;
    xyzRandomGenerator sRandomGeneratorobj;

    while(sRetVal)
    {
        mainMenu();
        std::cin >> sMainMenuOption;

        if(sMainMenuOption == -1 || isValidInput())
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
                    std::string sUserInputEmpId;
                    if(sEmpManager->getsize() != 0)
                    {
                        std::cout << "Enter the EmpLoyee Id:" <<std::endl;
                        std::cin >> sUserInputEmpId;
                        if(isValidEmpId(sUserInputEmpId))
                        {   
                            sEmpManager->removeEmployee(sUserInputEmpId);
                        }
                    }
                    else
                    {
                        std::cout << "There are no Active Employees to Remove." << std::endl;
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
                    sRetVal = 0;
                }
            }
        }
    }

    delete sEmpManager;
    return 0;
}