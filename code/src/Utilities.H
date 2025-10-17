#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

namespace ems{
    
    enum MainMenu{
        AddEmployee = 1,
        RemoveEmployee,
        GetEmployee,
        Others,
        ExitMainMenu = -1
    };

    enum AddMenu {
        Random = 1,
        Type,
        ExitAddMenu = -1
    };

    enum RemoveMenu {
        ByID = 1,
        ExitRemoveMenu = -1
    };

    enum GetMenu {
        AllSummary = 1,
        ByType,
        ByGender,
        ByStatus,
        SingleEmployee,
        ExitGetMenu = -1
    };

    enum OthersMenu {
        AddLeaves = 1,
        ConvertToFullTimeEmp,
        SearchById,
        SearchByName,
        ExitOtherMenu = -1
    };

    enum EmpStatus {
        Active = 1,
        Inactive,
        Resigned
    };

    enum EmpType {
        FullTime = 1,
        Contractor,
        Intern,
    };

    enum printHeaderType {
        FullTimeType = 1,
        ContractorType,
        InternType,
        ResignedType,
        EmployeeType,
        AllType
    };

    enum EmpGender {
        Male = 1,
        Female,
        OtherGender
    };

    enum Leaves {
        MinNoOfLeaves = 0,
        TotalNoOfLeaves = 22
    };

    enum Agency {
        Avengers = 1,
        Justice_League,
        X_Men
    };

    enum College {
        IIT_Delhi = 1,
        IIT_Mumbai,
        IIT_Kanpur,
        IIT_Hyderabad,
        NIT_Warangal,
        NIT_Tiruchi,
        IIIT_Hyderabad
    };

    enum Branch {
        ECE = 1,
        CSE,
        IT
    };

    enum Location {
        Hyderabad = 1,
        Delhi,
        Mumbai,
        Pune,
        Kolkata,
        Chennai,
        Banglore
    };

    enum SurName {
        Sharma,
        Varma,
        Singh,
        Gupta,
        Mehta,
        Reddy,
        Rao,
        Iyyer,
        Pillai,
        Smith,
        Cooper,
        Mukherjee,
        shinde,
        Gaikwad,
        Taylor,
        Roy,
        sen,
        Choudary,
        Naidu,
        Kapoor,
        Shastry,
        Kumar
    };

    enum Name {
        Aditi,
        Swathi,
        Priya,
        Kavya,
        Ananya,
        Sneha,
        Divya,
        Nisha,
        Riya,
        Meena,
        Lakshmi,
        Pooja,
        Neha,
        Shreya,
        Deepa,
        Arjun,
        Rahul,
        Surya,
        Kiran,
        Rohan,
        Aditya,
        Suresh,
        Rajesh,
        Naveen,
        Vikram,
        Pranav,
        Manoj,
        Abhishek,
        Rohit,
        Venkatesh
    };

    enum InputValid{
        Success=1,
        Failure =0
    };

    extern string empSurName[];
    extern string empName[];
    extern string empType[];
    extern string empStatus[];
    extern string empGender[];
    extern string empAgency[];
    extern string empCollege[];
    extern string empBranch[];
    extern string empLocation[];
}



string calculateEmployeeID(int empIdparam,ems::EmpType empTypeParam);
string calculateInternLastDate(string dateOfJoiningParam);
string calculatorContractorLastDate(string dateOfJoiningParam);
void mainMenu();
void addEmployeeMenu();
void getEmployeeAgency();
void contractorAgencyLocationDetails();
void internCollegeDetails();
void internBranchDetails();
void getEmployeeMenu();
void getGenderBasedMenu();
void getDesignationTypeBasedMenu();
void getDesignationStatusBaseMenu();
void doSomethingElseMenu();
void printEmployeeHeader(int widthParam, ems::printHeaderType optionParam);
ems::InputValid isValidInput() ;





#endif //_UTILITIES_H_