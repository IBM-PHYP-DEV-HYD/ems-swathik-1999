#ifndef _XYZ_RANDOM_GENERATOR_H
#define _XYZ_RANDOM_GENERATOR_H

#include "Utilities.H"
#include "XyzEmployee.H"

using namespace ems;

class xyzRandomGenerator
{
public:
    xyzRandomGenerator();
    ~xyzRandomGenerator();
    string generateRandomName();
    ems::EmpType generateRandomDesignationType();
    ems::EmpStatus generateRandomDesignationStatus();
    string generateRandomDateOfBirth();
    string generateRandomDateOfJoining(string sDobParam); 
    string generateRandomDateOfLeaving(string sDojParam);
    ems::EmpGender generateRandomEmpGender();
    int generateRandomNoofLeaves();
    Agency generateRandomAgency();
    Location generateRandomLocation();
    College generateRandomCollege();
    Branch generateRandomBranch();
};

#endif //_XYZ_RANDOM_GENERATOR_H