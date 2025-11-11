#include "Utilities.H"
#include "XyzRandomGenerator.H"
#include "XyzEmployee.H"

int xyzRandomGenerator::mGenderDecideParam = 0;

xyzRandomGenerator::xyzRandomGenerator() {
    this->mGenderDecideParam = 0;
}

xyzRandomGenerator::~xyzRandomGenerator() {}

std::string generateRandomDateinstring(int startYearParam, int endYearParam)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> yearDist(startYearParam, endYearParam);
    int sRandYear = yearDist(gen);

    std::uniform_int_distribution<> monthDist(1, 12);
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

    std::uniform_int_distribution<> dayDist(1, sRandDaylimit);
    int sRandDay = dayDist(gen);

    std::string sRandDate = std::to_string(sRandDay) + "-" + std::to_string(sRandMonth) + "-" + std::to_string(sRandYear);

    return sRandDate;
}

std::string generateRandomFirstName()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(SurName::Kumar) - 1);

    return ems::empSurName[static_cast<SurName>(dist(gen))];
}

std::string generateRandomLastName(xyzRandomGenerator randObjParam)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    if(randObjParam.mGenderDecideParam == 0)
    {
        std::uniform_int_distribution<> dist(1, static_cast<int>(MaleName::EndMaleName) - 1);
        return ems::empMaleName[static_cast<MaleName>(dist(gen))];
    }
    else
    {
        std::uniform_int_distribution<> dist(1, static_cast<int>(FemaleName::EndFemaleName) - 1);
        return ems::empFemaleName[static_cast<FemaleName>(dist(gen))];
    }

}

std::string xyzRandomGenerator::generateRandomName(xyzRandomGenerator randObjParam)
{
    std::string sRandFirstName = generateRandomFirstName();
    std::string sRandLastName = generateRandomLastName(randObjParam);

    std::string sRandName = sRandLastName + " " + sRandFirstName;

    return sRandName;
}

ems::EmpType xyzRandomGenerator::generateRandomDesignationType()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(EmpType::EndEmpType) - 1);

    return static_cast<EmpType>(dist(gen));
}

ems::EmpStatus xyzRandomGenerator::generateRandomDesignationStatus()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(EmpStatus::EndEmpStatus) - 1);

    return static_cast<EmpStatus>(dist(gen));
}

std::string xyzRandomGenerator::generateRandomDateOfBirth()
{
    std::string sRandDateOfBirth = generateRandomDateinstring(1900,2000);

    return sRandDateOfBirth;
}

std::string xyzRandomGenerator::generateRandomDateOfJoining(std::string sDobParam)
{

    int sYear = stoi(sDobParam.substr(sDobParam.size()-4));

    std::string sRandDateofJoining = generateRandomDateinstring(sYear+22,2025);

    return sRandDateofJoining;
}

std::string xyzRandomGenerator::generateRandomDateOfLeaving(std::string DojParam)
{
    int sYear = stoi(DojParam.substr(DojParam.size()-4));

    std::string sRandDateOfLeaving = generateRandomDateinstring(sYear,2025);

    return sRandDateOfLeaving;
}

int xyzRandomGenerator::generateRandomNoofLeaves()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> yearDist(1, 22);
    int sRandLeaves = yearDist(gen);

    return sRandLeaves;
}

Agency xyzRandomGenerator::generateRandomAgency()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(Agency::EndAgency) - 1);

    return static_cast<Agency>(dist(gen));
}

College xyzRandomGenerator::generateRandomCollege()
{

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(College::EndCollege) - 1);

    return static_cast<College>(dist(gen));
}

EmpGender xyzRandomGenerator::generateRandomEmpGender()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(EmpGender::EndEmpGender) - 1);

    return static_cast<EmpGender>(dist(gen));
}


Branch xyzRandomGenerator::generateRandomBranch()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(Branch::EndBranch) - 1);

    return static_cast<Branch>(dist(gen));
}

Location xyzRandomGenerator::generateRandomLocation()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, static_cast<int>(Location::endlocation) - 1);

    return static_cast<Location>(dist(gen));
}