#ifndef _XYZ_RANDOM_GENERATOR_H
#define _XYZ_RANDOM_GENERATOR_H

#include "Utilities.H"
#include "XyzEmployee.H"

using namespace ems;

class xyzRandomGenerator
{
public:
    static int mGenderDecideParam;
    xyzRandomGenerator();
    ~xyzRandomGenerator();
    std::string generateRandomName(xyzRandomGenerator randObjParam);
    ems::EmpType generateRandomDesignationType();
    ems::EmpStatus generateRandomDesignationStatus();
    std::string generateRandomDateOfBirth();
    std::string generateRandomDateOfJoining(std::string sDobParam); 
    std::string generateRandomDateOfLeaving(std::string sDojParam);
    ems::EmpGender generateRandomEmpGender();
    int generateRandomNoofLeaves();
    Agency generateRandomAgency();
    Location generateRandomLocation();
    College generateRandomCollege();
    Branch generateRandomBranch();
};

#endif //_XYZ_RANDOM_GENERATOR_H