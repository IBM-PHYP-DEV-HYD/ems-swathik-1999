#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Node.H"

using namespace std;

namespace ems{
    
    enum EmpStatus {
        Active = 1,
        Inactive,
        Resigned
    };

    enum EmpType {
        FullTime = 1,
        Contractor,
        Intern
    };

    enum EmpGender {
        Male = 1,
        Female,
        Other
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
        Naidu,
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
}

//Calculate LastDate for Intern Employee
string calculateInternLastDate(string dateOfJoiningParam)
{
    int sYear = stoi(dateOfJoiningParam.substr(dateOfJoiningParam.size()-4));
    int sMonth = stoi(dateOfJoiningParam.substr(4,2));
    int sDay = stoi(dateOfJoiningParam.substr(7,2));

    if(sMonth > 6)
    {
        sMonth = sMonth + 6 - 12;
        sYear = sYear + 1;
    }
    else
    {
        sMonth = sMonth + 6;
    }

    string sDate = to_string(sDay) + "-" + to_string(sMonth) + "-" + to_string(sYear);
    return sDate;
}

// Calculate LastDate for contractor Employee
string calculatorContractorLastDate(string dateOfJoiningParam)
{
    int sYear = stoi(dateOfJoiningParam.substr(dateOfJoiningParam.size()-4));
    int sMonth = stoi(dateOfJoiningParam.substr(4,2));
    int sDay = stoi(dateOfJoiningParam.substr(7,2));

    sYear++;

    string sDate = to_string(sDay) + "-" + to_string(sMonth) + "-" + to_string(sYear);
    return sDate;
}

// Display Menus
void mainMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "|          1. Add an Employee                          |" << endl;
    cout << "|          2. Remove an Employee                       |" << endl;
    cout << "|          3. Get Employee Details                     |" << endl;
    cout << "|          4. Do Something Else                        |" << endl;
    cout << "|            (Enter -1 to exit)                        |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void addEmployeeMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Add an Employee:                                     |" << endl;
    cout << "|          1. Add an Employee at Random                |" << endl;
    cout << "|          2. Add an Employee (F/C/I)                  |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void getBasicDetails()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Enter Type Of Employee:                              |" << endl;
    cout << "|          1. Full Time Employee                       |" << endl;
    cout << "|          2. Contractor Employee                      |" << endl;
    cout << "|          3. Intern Employee                          |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void contractorAgencyDetails()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Enter Contractor Agency:                             |" << endl;
    cout << "|          1. Avengers                                 |" << endl;
    cout << "|          2. Justice League                           |" << endl;
    cout << "|          3. X-Men                                    |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void contractorAgencyLocationDetails()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Enter Contractor Agency Location:                    |" << endl;
    cout << "|          1. Hyderabad                                |" << endl;
    cout << "|          2. Delhi                                    |" << endl;
    cout << "|          3. Mumbai                                   |" << endl;
    cout << "|          4. Pune                                     |" << endl;
    cout << "|          5. Kolkata                                  |" << endl;
    cout << "|          6. Chennai                                  |" << endl;
    cout << "|          7. Banglore                                 |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void internCollegeDetails()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Enter Intern College:                                |" << endl;
    cout << "|          1. IIT Delhi                                |" << endl;
    cout << "|          2. IIT Mumbai                               |" << endl;
    cout << "|          3. IIT Kanpur                               |" << endl;
    cout << "|          4. IIT Hyderabad                            |" << endl;
    cout << "|          5. NIT Warangal                             |" << endl;
    cout << "|          6. NIT Tiruchi                              |" << endl;
    cout << "|          7. IIIT Hyderabad                           |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void internBranchDetails()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Enter Intern Branch:                                 |" << endl;
    cout << "|          1. ECE                                      |" << endl;
    cout << "|          2. CSE                                      |" << endl;
    cout << "|          3. IT                                       |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void removeEmployeeMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Remove an Employee:                                  |" << endl;
    cout << "|          1. Remove an Employee by ID                 |" << endl;
    cout << "|          2. Remove an Employee by Name               |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void getEmployeeMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Employee Details:                                |" << endl;
    cout << "|          1. All Employees Summary                    |" << endl;
    cout << "|          2. Employee Summary (F/C/I)                 |" << endl;
    cout << "|          3. Employee Summary (M/F)                   |" << endl;
    cout << "|          4. Employee Summary (A/I/R)                 |" << endl;
    cout << "|          5. Display Employee Details                 |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void getDesignationTypeBasedMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Employee Type:                                   |" << endl;
    cout << "|          1. Full Time Employee                       |" << endl;
    cout << "|          2. Contractor Employee                      |" << endl;
    cout << "|          3. Intern Employee                          |" << endl;
    cout << "|       (Enter -1 to go  back to main menu)            |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void getGenderBasedMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Gender Type:                                     |" << endl;
    cout << "|             1. Male                                  |" << endl;
    cout << "|             2. Female                                |" << endl;
    cout << "|       (Enter -1 to go  back to main menu)            |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";

}

void getDesignationStatusBaseMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Status Type:                                     |" << endl;
    cout << "|             1. Active                                |" << endl;
    cout << "|             1. Inactive                              |" << endl;
    cout << "|             2. Resigned                              |" << endl;
    cout << "|       (Enter -1 to go  back to main menu)            |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}



void doSomethingElseMenu()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Do Something Else:                                   |" << endl;
    cout << "|  1. Add 'n' no of leaves to all Full Time Employees  |" << endl;
    cout << "|  2. Convert an Intern to a Full Time Employee        |" << endl;
    cout << "|  3. Search an Employee by ID                         |" << endl;
    cout << "|  4. Search an Employee by Name                       |" << endl;
    cout << "|      (Enter -1 to go back to main menu)              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}



#endif //_UTILITIES_H_