#include "Utilities.H"
#include "XyzRandomGenerator.H"
#include "XyzEmployee.H"


xyzRandomGenerator::xyzRandomGenerator() {
    srand(static_cast<unsigned>(time(0)));
}

xyzRandomGenerator::~xyzRandomGenerator() {}

string generateRandomDateinString(int startYearParam, int endYearParam)
{
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

    string sRandDate = to_string(sRandDay) + "-" + to_string(sRandMonth) + "-" + to_string(sRandYear);

    return sRandDate;
}

string generateRandomFirstName()
{
    SurName sRandomFirstName;
    do
    {
       sRandomFirstName = static_cast<SurName>(rand() % (static_cast<int>(SurName::Kumar) + 1));
    }while(sRandomFirstName == 0);

    return ems::empSurName[sRandomFirstName];
}

string generateRandomLastName()
{
    Name sRandomLastName;
    do
    {
        sRandomLastName = static_cast<Name>(rand() % (static_cast<int>(Name::Venkatesh) + 1));
    }while(sRandomLastName == 0);

    return ems::empName[sRandomLastName];
}

string xyzRandomGenerator::generateRandomName()
{
    string sRandFirstName = generateRandomFirstName();
    string sRandLastName = generateRandomLastName();

    string sRandName = sRandLastName + " " + sRandFirstName;

    cout << "Name :" << sRandName << endl;
    return sRandName;
}

ems::EmpType xyzRandomGenerator::generateRandomDesignationType()
{
    EmpType sRandDesignationType;
    do
    {
        sRandDesignationType = static_cast<EmpType>(rand() % (static_cast<int>(EmpType::Intern) + 1));
    }while(sRandDesignationType == 0);

    // cout << "generateRandomDesignationType : " << sRandDesignationType << "emp : " << ems::empType[sRandDesignationType] << endl;
    return sRandDesignationType;
}

ems::EmpStatus xyzRandomGenerator::generateRandomDesignationStatus()
{
    EmpStatus sRandDesignationStatus;
    do
    {
        sRandDesignationStatus = static_cast<EmpStatus>(rand() % (static_cast<int>(EmpStatus::Resigned) + 1));
    }while(sRandDesignationStatus == 0);

    return sRandDesignationStatus;
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

string xyzRandomGenerator::generateRandomDateOfLeaving(string DojParam)
{
    int sYear = stoi(DojParam.substr(DojParam.size()-4));

    string sRandDateOfLeaving = generateRandomDateinString(sYear,2025);

    return sRandDateOfLeaving;
}

int xyzRandomGenerator::generateRandomNoofLeaves()
{
    int sRandLeaves  = 1 + (rand() % 22);

    return sRandLeaves;
}

Agency xyzRandomGenerator::generateRandomAgency()
{   
    Agency sRandAgency;
    do{
        sRandAgency = static_cast<Agency>(rand() % (static_cast<int>(Agency::X_Men) + 1));
    }while(sRandAgency == 0);

    return sRandAgency;
}

College xyzRandomGenerator::generateRandomCollege()
{
    College sRandCollege;
    do{
        sRandCollege = static_cast<College>(rand() % (static_cast<int>(College::IIIT_Hyderabad) + 1));
    }while(sRandCollege == 0);
        
    return sRandCollege;
}

EmpGender xyzRandomGenerator::generateRandomEmpGender()
{
    EmpGender sRandEmpGender;
    do{
        sRandEmpGender = static_cast<EmpGender>(rand() % (static_cast<int>(EmpGender::OtherGender) + 1));
    }while(sRandEmpGender == 0);

    return sRandEmpGender;
}


Branch xyzRandomGenerator::generateRandomBranch()
{
    Branch sRandBranch;
    do{
        sRandBranch = static_cast<Branch>(rand() % (static_cast<int>(Branch::IT) + 1));
    }while(sRandBranch == 0);

    return sRandBranch;
}

Location xyzRandomGenerator::generateRandomLocation()
{
    Location sRandLocation;
    do{
        sRandLocation = static_cast<Location>(rand() % (static_cast<int>(Location::Banglore) + 1));
    }while(sRandLocation == 0);

    return sRandLocation;
}