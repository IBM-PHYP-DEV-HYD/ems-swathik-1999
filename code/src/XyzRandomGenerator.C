#include "Utilities.H"
#include "XyzRandomGenerator.H"
#include "XyzEmployee.H"

int xyzRandomGenerator::mGenderDecideParam = 0;

xyzRandomGenerator::xyzRandomGenerator() {
    this->mGenderDecideParam = 0;
}

xyzRandomGenerator::~xyzRandomGenerator() {}

string generateRandomDateinString(int startYearParam, int endYearParam)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> yearDist(startYearParam, endYearParam);
    int sRandYear = yearDist(gen);

    uniform_int_distribution<> monthDist(1, 12);
    int sRandMonth = monthDist(gen);

    int sRandDaylimit;
    if (sRandMonth == 2) {
        bool isLeap = (sRandYear % 4 == 0 && sRandYear % 100 != 0) || (sRandYear % 400 == 0);
        sRandDaylimit = isLeap ? 29 : 28;
    } else if (sRandMonth == 4 || sRandMonth == 6 || sRandMonth == 9 || sRandMonth == 11) {
        sRandDaylimit = 30;
    } else {
        sRandDaylimit = 31;
    }

    uniform_int_distribution<> dayDist(1, sRandDaylimit);
    int sRandDay = dayDist(gen);

    string sRandDate = to_string(sRandDay) + "-" + to_string(sRandMonth) + "-" + to_string(sRandYear);

    return sRandDate;
}

string generateRandomFirstName()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(SurName::Kumar) - 1);

    return ems::empSurName[static_cast<SurName>(dist(gen))];
}

string generateRandomLastName(xyzRandomGenerator randObjParam)
{
    static random_device rd;
    static mt19937 gen(rd());
    if(randObjParam.mGenderDecideParam == 0)
    {
        uniform_int_distribution<> dist(1, static_cast<int>(MaleName::EndMaleName) - 1);
        return ems::empMaleName[static_cast<MaleName>(dist(gen))];
    }
    else
    {
        uniform_int_distribution<> dist(1, static_cast<int>(FemaleName::EndFemaleName) - 1);
        return ems::empFemaleName[static_cast<FemaleName>(dist(gen))];
    }

}

string xyzRandomGenerator::generateRandomName(xyzRandomGenerator randObjParam)
{
    string sRandFirstName = generateRandomFirstName();
    string sRandLastName = generateRandomLastName(randObjParam);

    string sRandName = sRandLastName + " " + sRandFirstName;

    return sRandName;
}

ems::EmpType xyzRandomGenerator::generateRandomDesignationType()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(EmpType::EndEmpType) - 1);

    return static_cast<EmpType>(dist(gen));
}

ems::EmpStatus xyzRandomGenerator::generateRandomDesignationStatus()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(EmpStatus::EndEmpStatus) - 1);

    return static_cast<EmpStatus>(dist(gen));
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
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> yearDist(1, 22);
    int sRandLeaves = yearDist(gen);

    return sRandLeaves;
}

Agency xyzRandomGenerator::generateRandomAgency()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(Agency::EndAgency) - 1);

    return static_cast<Agency>(dist(gen));
}

College xyzRandomGenerator::generateRandomCollege()
{

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(College::EndCollege) - 1);

    return static_cast<College>(dist(gen));
}

EmpGender xyzRandomGenerator::generateRandomEmpGender()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(EmpGender::EndEmpGender) - 1);

    return static_cast<EmpGender>(dist(gen));
}


Branch xyzRandomGenerator::generateRandomBranch()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(Branch::EndBranch) - 1);

    return static_cast<Branch>(dist(gen));
}

Location xyzRandomGenerator::generateRandomLocation()
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, static_cast<int>(Location::EndLocation) - 1);

    return static_cast<Location>(dist(gen));
}