#include "Utilities.H"

namespace ems {

    string empSurName[] = {
        " ",
        "Sharma",
        "Varma",
        "Singh",
        "Gupta",
        "Mehta",
        "Reddy",
        "Rao",
        "Iyyer",
        "Pillai",
        "Smith",
        "Cooper",
        "Mukherjee",
        "shinde",
        "Gaikwad",
        "Taylor",
        "Roy",
        "sen",
        "Choudary",
        "Naidu",
        "Kapoor",
        "Shastry",
        "Kumar"
    };

    string empName[] = {
        " ",
        "Aditi",
        "Swathi",
        "Priya",
        "Kavya",
        "Ananya",
        "Sneha",
        "Divya",
        "Nisha",
        "Riya",
        "Meena",
        "Lakshmi",
        "Pooja",
        "Neha",
        "Shreya",
        "Deepa",
        "Arjun",
        "Rahul",
        "Surya",
        "Kiran",
        "Rohan",
        "Aditya",
        "Suresh",
        "Rajesh",
        "Naveen",
        "Vikram",
        "Pranav",
        "Manoj",
        "Abhishek",
        "Rohit",
        "Venkatesh"
    };

    string empType[] =  {" ", "FullTime", "Contractor", "Intern"};
    string empStatus[] = {" ", "Active", "Inactive", "Resigned"};
    string empGender[] = {" ", "Male", "Female", "OtherGender"};

    string empAgency[] = {" ", "Avengers", "Justice_League", "X_Men"};
    string empCollege[] = {" ", "IIT_Delhi", "IIT_Mumbai", "IIT_Kanpur", "IIT_Hyderabad", "NIT_Warangal", "NIT_Tiruchi", "IIIT_Hyderabad"};
    string empBranch[] = {" ", "ECE", "CSE", "IT"};
    string empLocation[] = {" ", "Hyderabad", "Delhi", "Mumbai", "Pune", "Kolkata", "Chennai", "Banglore"};
    
}

string calculateEmployeeID(int empIdparam,ems::EmpType empTypeParam)
{
    cout << "empTypeParam : " << empTypeParam << " " << ems::empType[empTypeParam] << endl;
    string sEmployeeID = "XYZ";

    if(empIdparam > 0  && empIdparam < 10)
    {
        sEmployeeID += "000";
    }
    else if(empIdparam > 9  && empIdparam < 100)
    {
        sEmployeeID += "00";
    }
    else if(empIdparam > 99  && empIdparam < 1000)
    {
        sEmployeeID += "0";
    }

    sEmployeeID += to_string(empIdparam);

    if(empTypeParam == ems::FullTime)
    {
        sEmployeeID += "F";
    }
    else if(empTypeParam == ems::Contractor)
    {
        sEmployeeID += "C";
    }
    else
    {
         sEmployeeID += "I";
    }

    cout << "sEmp: " << sEmployeeID << endl;

    return sEmployeeID;
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
    cout << endl;
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
    cout << endl;
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

void getEmployeeAgency()
{
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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

void getEmployeeMenu()
{
    cout << endl;
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

void getGenderBasedMenu()
{
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Gender Type:                                     |" << endl;
    cout << "|             1. Male                                  |" << endl;
    cout << "|             2. Female                                |" << endl;
    cout << "|             3. Others                                |" << endl;
    cout << "|       (Enter -1 to go  back to main menu)            |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";

}

void getDesignationTypeBasedMenu()
{
    cout << endl;
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

void getDesignationStatusBaseMenu()
{
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "|              Employee Management System              |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Get Status Type:                                     |" << endl;
    cout << "|             1. Active                                |" << endl;
    cout << "|             2. Inactive                              |" << endl;
    cout << "|             3. Resigned                              |" << endl;
    cout << "|       (Enter -1 to go  back to main menu)            |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void doSomethingElseMenu()
{
    cout << endl;
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

void printEmployeeHeader(int widthParam, ems::printHeaderType optionParam)
{
    cout << setfill('-') << setw(widthParam) << "-" << endl;
    cout << "| "<< left << setw(24) << setfill(' ') <<"Employee Name";
    cout << "| "<< left << setw(12) << setfill(' ') <<"ID";
    cout << "| "<< left << setw(14) << setfill(' ') <<"Type";
    cout << "| "<< left << setw(14) << setfill(' ') <<"Status";
    cout << "| "<< left << setw(14) << setfill(' ') <<"Gender";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Birth";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Joining";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Leaving";
    if(optionParam == ems::FullTimeType || optionParam == ems::AllType)
    {
        cout << "| "<< left << setw(18) << setfill(' ') <<"Leaves Availed";
        cout << "| "<< left << setw(18) << setfill(' ') <<"Leaves Left";    
    }
    if(optionParam == ems::ContractorType || optionParam == ems::AllType)
    {
        cout << "| "<< left << setw(18) << setfill(' ') <<"Agency";
        cout << "| "<< left << setw(18) << setfill(' ') <<"Location";
    }
    if(optionParam == ems::InternType || optionParam == ems::AllType)
    {
        cout << "| "<< left << setw(18) << setfill(' ') <<"College";
        cout << "| "<< left << setw(18) << setfill(' ') <<"Branch";
    }
    cout << endl;     
    cout << setfill('-') << setw(widthParam) << "-" << endl;
    cout << setfill(' ') << setw(widthParam) << " " << endl;
}

 ems::InputValid isValidInput() 
 {
    ems::InputValid sRetValue = ems::Success;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /* discard the invalid input */
        std::cout << "Invalid Value, Please enter valid value." << std::endl;
        sRetValue = ems::Failure;
    }
    return sRetValue;
}