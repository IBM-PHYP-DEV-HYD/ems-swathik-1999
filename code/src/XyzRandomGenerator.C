#include "Utilities.H"
#include "XyzRandomGenerator.H"
#include "XyzEmployeeManager.H"

string generateRandomDateinString(int startYearParam, int endYearParam)
{
    srand((time(0)));

    int sRandYear = startYearParam + (rand() % (endYearParam - startYearParam + 1));
    int sRandMonth = 1 + (rand() % 12);

    int sRandDay;
    if(sRandMonth == 2)
    {
        bool sIsLeap = (sRandYear % 4 == 0 && sRandYear % 100 != 0) || (sRandYear % 400 == 0);
        sRandDay = 1 + rand() % (sIsLeap ? 29 : 28);
    }
    else if (sRandMonth == 4 || sRandMonth == 6 || sRandMonth == 9 || sRandMonth == 11)
    {
        sRandDay = 1 + rand() % 30;
    }
    else
    {
        sRandDay = 1 + rand() % 31;
    }

    string sRandDate = to_string(sRandYear) + "-" + to_string(sRandMonth) + "-" + to_string(sRandDay);

    return sRandDate;
}

string generateRandomFirstName()
{
    srand(time(0));

    SurName sRandomFirstName = static_cast<SurName>(rand() % (static_cast<int>(SurName::Kumar) + 1));

    return to_string(sRandomFirstName);
}

string generateRandomLastName()
{
    srand((time(0)));

    Name sRandomLastName = static_cast<Name>(rand() % (static_cast<int>(Name::Venkatesh) + 1));

    return to_string(sRandomLastName);
}

string xyzRandomGenerator::generateRandomName()
{
    string sRandFirstName = generateRandomFirstName();
    string sRandLastName = generateRandomLastName();

    string sRandName = sRandFirstName + " " + sRandLastName;

    return sRandName;
}

string xyzRandomGenerator::generateRandomEmpID()
{
    string sRandomEmpID = "XYZ";

    if(xyzEmployeeManager::mIdNumber > 0  || xyzEmployeeManager::mIdNumber < 10)
    {
        sRandomEmpID += "000";
    }
    else if(xyzEmployeeManager::mIdNumber > 9  || xyzEmployeeManager::mIdNumber < 100)
    {
        sRandomEmpID += "00";
    }
    else if(xyzEmployeeManager::mIdNumber > 99  || xyzEmployeeManager::mIdNumber < 1000)
    {
        sRandomEmpID += "0";
    }

    sRandomEmpID += to_string(xyzEmployeeManager::mIdNumber);

    return sRandomEmpID;
}

string xyzRandomGenerator::generateRandomDesignationType()
{
    srand(time(0));

    EmpType sRandDesignationType = static_cast<EmpType>(rand() % (static_cast<int>(EmpType::Intern) + 1));

    return to_string(sRandDesignationType);
}

string xyzRandomGenerator::generateRandomDateOfBirth()
{
    string sRandDateOfBirth = generateRandomDateinString(1900,2000);

    return sRandDateOfBirth;
}

string xyzRandomGenerator::generateRandomDateOfJoining(string sDobParam)
{

    int sYear = stoi(sDobParam.substr(sDobParam.size()-4));

    string sRandDateofJoining = generateRandomDateinString(sYear+22,2025);

    return sRandDateofJoining;
}

Agency xyzRandomGenerator::generateRandomAgency()
{
    srand(time(0));
    
    Agency sRandAgency = static_cast<Agency>(rand() % (static_cast<int>(Agency::X_Men) + 1));

    return sRandAgency;
}

College xyzRandomGenerator::generateRandomCollege()
{
    srand(time(0));

    College sRandCollege = static_cast<College>(rand() % (static_cast<int>(College::IIIT_Hyderabad) + 1));

    return sRandCollege;
}

Branch xyzRandomGenerator::generateRandomBranch()
{
    srand(time(0));

    Branch sRandBranch = static_cast<Branch>(rand() % (static_cast<int>(Branch::IT) + 1));

    return sRandBranch;
}

Location xyzRandomGenerator::generateRandomLocation()
{
    srand(time(0));

    Location sRandLocation = static_cast<Location>(rand() % (static_cast<int>(Location::Banglore) + 1));

    return sRandLocation;
}