#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <random>

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
        Resigned,
        EndEmpStatus
    };

    enum EmpType {
        FullTime = 1,
        Contractor,
        Intern,
        EndEmpType
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
        OtherGender,
        EndEmpGender
    };

    enum Leaves {
        MinNoOfLeaves = 0,
        TotalNoOfLeaves = 22
    };

    enum Agency {
        Avengers = 1,
        Justice_League,
        X_Men,
        EndAgency
    };

    enum College {
        IIT_Delhi = 1,
        IIT_Mumbai,
        IIT_Kanpur,
        IIT_Hyderabad,
        NIT_Warangal,
        NIT_Tiruchi,
        IIIT_Hyderabad,
        EndCollege
    };

    enum Branch {
        ECE = 1,
        CSE,
        IT,
        EndBranch
    };

    enum Location {
        Hyderabad = 1,
        Delhi,
        Mumbai,
        Pune,
        Kolkata,
        Chennai,
        Banglore,
        EndLocation
    };

    enum SurName {
        Sharma = 1,
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
        Kumar,
        EndSurName
    };

    enum FemaleName {
        Aditi = 1,
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
        EndFemaleName
    };

    enum MaleName{
        Arjun = 1,
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
        Venkatesh,
        EndMaleName
    };

    enum InputValid{
        Success = 1,
        Failure = 0
    };

    extern string empSurName[];
    extern string empMaleName[];
    extern string empFemaleName[];
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
ems::InputValid isValidInput();
ems::InputValid isValidEmpId(string inputParam);





#endif //_UTILITIES_H_