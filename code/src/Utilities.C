#include "Utilities.H"
#include <sstream>

namespace ems {

    std::string empSurName[] = {
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

    std::string empFemaleName[] = {
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
        "Deepa"
    };
    std::string empMaleName[] = {
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

    std::string empType[] =  {" ", "FullTime", "Contractor", "Intern"};
    std::string empStatus[] = {" ", "Active", "Inactive", "Resigned"};
    std::string empGender[] = {" ", "Male", "Female", "OtherGender"};

    std::string empAgency[] = {" ", "Avengers", "Justice_League", "X_Men"};
    std::string empCollege[] = {" ", "IIT_Delhi", "IIT_Mumbai", "IIT_Kanpur", "IIT_Hyderabad", "NIT_Warangal", "NIT_Tiruchi", "IIIT_Hyderabad"};
    std::string empBranch[] = {" ", "ECE", "CSE", "IT"};
    std::string empLocation[] = {" ", "Hyderabad", "Delhi", "Mumbai", "Pune", "Kolkata", "Chennai", "Banglore"};
    
}

// calculate Employee ID
std::string calculateEmployeeID(int empIdparam,ems::EmpType empTypeParam)
{
    std::string sEmployeeID = "XYZ";

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

    sEmployeeID += std::to_string(empIdparam);

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


    return sEmployeeID;
}
//Calculate LastDate for Intern Employee
std::string calculateInternLastDate(std::string dateOfJoiningParam)
{
    std::stringstream ss(dateOfJoiningParam);
    std::string sYearStr, sMonthStr, sDayStr;

    getline(ss, sDayStr, '-');
    getline(ss, sMonthStr, '-');
    getline(ss, sYearStr, '-');

    int sYear = stoi(sYearStr);
    int sMonth = stoi(sMonthStr);
    int sDay = stoi(sDayStr);

    if(sMonth > 6)
    {
        sMonth = sMonth + 6 - 12;
        sYear = sYear + 1;
    }
    else
    {
        sMonth = sMonth + 6;
    }

    std::string sDate = std::to_string(sDay) + "-" + std::to_string(sMonth) + "-" + std::to_string(sYear);
    return sDate;
}

// Calculate LastDate for contractor Employee
std::string calculatorContractorLastDate(std::string dateOfJoiningParam)
{
    std::stringstream ss(dateOfJoiningParam);
    std::string sYearStr, sMonthStr, sDayStr;

    getline(ss, sDayStr, '-');
    getline(ss, sMonthStr, '-');
    getline(ss, sYearStr, '-');

    int sYear = stoi(sYearStr);
    int sMonth = stoi(sMonthStr);
    int sDay = stoi(sDayStr);

    sYear++;
    std::string sDate = std::to_string(sDay) + "-" + std::to_string(sMonth) + "-" + std::to_string(sYear);

    return sDate;
}

// Display Menus
void mainMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|          1. Add an Employee                          |" << std::endl;
    std::cout << "|          2. Remove an Employee                       |" << std::endl;
    std::cout << "|          3. Get Employee Details                     |" << std::endl;
    std::cout << "|          4. Do Something Else                        |" << std::endl;
    std::cout << "|            (Enter -1 to exit)                        |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void addEmployeeMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Add an Employee:                                     |" << std::endl;
    std::cout << "|          1. Add an Employee at Random                |" << std::endl;
    std::cout << "|          2. Add an Employee (F/C/I)                  |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void getEmployeeAgency()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Enter Contractor Agency:                             |" << std::endl;
    std::cout << "|          1. Avengers                                 |" << std::endl;
    std::cout << "|          2. Justice League                           |" << std::endl;
    std::cout << "|          3. X-Men                                    |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void contractorAgencyLocationDetails()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Enter Contractor Agency Location:                    |" << std::endl;
    std::cout << "|          1. Hyderabad                                |" << std::endl;
    std::cout << "|          2. Delhi                                    |" << std::endl;
    std::cout << "|          3. Mumbai                                   |" << std::endl;
    std::cout << "|          4. Pune                                     |" << std::endl;
    std::cout << "|          5. Kolkata                                  |" << std::endl;
    std::cout << "|          6. Chennai                                  |" << std::endl;
    std::cout << "|          7. Banglore                                 |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void internCollegeDetails()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Enter Intern College:                                |" << std::endl;
    std::cout << "|          1. IIT Delhi                                |" << std::endl;
    std::cout << "|          2. IIT Mumbai                               |" << std::endl;
    std::cout << "|          3. IIT Kanpur                               |" << std::endl;
    std::cout << "|          4. IIT Hyderabad                            |" << std::endl;
    std::cout << "|          5. NIT Warangal                             |" << std::endl;
    std::cout << "|          6. NIT Tiruchi                              |" << std::endl;
    std::cout << "|          7. IIIT Hyderabad                           |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void internBranchDetails()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Enter Intern Branch:                                 |" << std::endl;
    std::cout << "|          1. ECE                                      |" << std::endl;
    std::cout << "|          2. CSE                                      |" << std::endl;
    std::cout << "|          3. IT                                       |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void getEmployeeMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Get Employee Details:                                |" << std::endl;
    std::cout << "|          1. All Employees Summary                    |" << std::endl;
    std::cout << "|          2. Employee Summary (F/C/I)                 |" << std::endl;
    std::cout << "|          3. Employee Summary (M/F)                   |" << std::endl;
    std::cout << "|          4. Employee Summary (A/I/R)                 |" << std::endl;
    std::cout << "|          5. Display Employee Details                 |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void getGenderBasedMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Get Gender Type:                                     |" << std::endl;
    std::cout << "|             1. Male                                  |" << std::endl;
    std::cout << "|             2. Female                                |" << std::endl;
    std::cout << "|             3. Others                                |" << std::endl;
    std::cout << "|       (Enter -1 to go  back to main menu)            |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";

}

void getDesignationTypeBasedMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Get Employee Type:                                   |" << std::endl;
    std::cout << "|          1. Full Time Employee                       |" << std::endl;
    std::cout << "|          2. Contractor Employee                      |" << std::endl;
    std::cout << "|          3. Intern Employee                          |" << std::endl;
    std::cout << "|       (Enter -1 to go  back to main menu)            |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void getDesignationStatusBaseMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Get Status Type:                                     |" << std::endl;
    std::cout << "|             1. Active                                |" << std::endl;
    std::cout << "|             2. Inactive                              |" << std::endl;
    std::cout << "|             3. Resigned                              |" << std::endl;
    std::cout << "|       (Enter -1 to go  back to main menu)            |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void doSomethingElseMenu()
{
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "|              Employee Management System              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "| Do Something Else:                                   |" << std::endl;
    std::cout << "|  1. Add 'n' no of leaves to all Full Time Employees  |" << std::endl;
    std::cout << "|  2. Convert an Intern to a Full Time Employee        |" << std::endl;
    std::cout << "|  3. Search an Employee by ID                         |" << std::endl;
    std::cout << "|  4. Search an Employee by Name                       |" << std::endl;
    std::cout << "|      (Enter -1 to go back to main menu)              |" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

void printEmployeeHeader(int widthParam, ems::printHeaderType optionParam)
{
    std::cout << std::setfill('-') << std::setw(widthParam) << "-" << std::endl;
    std::cout << "| "<< std::left << std::setw(24) << std::setfill(' ') <<"Employee Name";
    std::cout << "| "<< std::left << std::setw(12) << std::setfill(' ') <<"ID";
    std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') <<"Type";
    std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') <<"Status";
    std::cout << "| "<< std::left << std::setw(14) << std::setfill(' ') <<"Gender";
    std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Date of Birth";
    std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Date of Joining";
    std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Date of Leaving";
    if(optionParam == ems::FullTimeType || optionParam == ems::AllType)
    {
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Leaves Availed";
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Leaves Left";    
    }
    if(optionParam == ems::ContractorType || optionParam == ems::AllType)
    {
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Agency";
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Location";
    }
    if(optionParam == ems::InternType || optionParam == ems::AllType)
    {
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"College";
        std::cout << "| "<< std::left << std::setw(18) << std::setfill(' ') <<"Branch";
    }
    std::cout << std::endl;     
    std::cout << std::setfill('-') << std::setw(widthParam) << "-" << std::endl;
    std::cout << std::setfill(' ') << std::setw(widthParam) << " " << std::endl;
}

 ems::InputValid isValidInput() 
 {
    ems::InputValid sRetValue = ems::Success;
    if(std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Value, Please enter valid value." << std::endl;
        sRetValue = ems::Failure;
    }
    return sRetValue;
}


ems::InputValid isValidEmpId(std::string inputParam)
{
    ems::InputValid sRetValue = ems::Success;
    
    if(inputParam.length() != 8)
    {
        if(inputParam.at(0) != 'X' || inputParam.at(1) != 'Y' || inputParam.at(2) != 'Z')
        {
            for (int idx = 3; idx < 7; ++idx)
            {
                if (!isdigit(static_cast<unsigned char>(inputParam[idx])))
                {
                    sRetValue = ems::Failure;
                    break;
                }
            }

            if(sRetValue != ems::Failure && inputParam.at(7) != 'F' && inputParam.at(7) != 'C' && inputParam.at(7) != 'I')
            {
                sRetValue = ems::Failure;
            }
        }
    }

    if(sRetValue == ems::Failure)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Employee Id, Please enter Valid Employee ID ." << std::endl;
    }
    return sRetValue;
}