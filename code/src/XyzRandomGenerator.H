#ifndef _XYZ_RANDOM_GENERATOR_H
#define _XYZ_RANDOM_GENERATOR_H

#include "Utilities.H"

using namespace ems;

class xyzRandomGenerator
{
public:
    xyzRandomGenerator(/* args */);
    ~xyzRandomGenerator();
    string generateRandomName();
    string generateRandomEmpID();
    string generateRandomDesignationType();
    string generateRandomDateOfBirth();
    string generateRandomDateOfJoining(string sDobParam); 
    Agency generateRandomAgency();
    Location generateRandomLocation();
    College generateRandomCollege();
    Branch generateRandomBranch();
};

#endif //_XYZ_RANDOM_GENERATOR_H