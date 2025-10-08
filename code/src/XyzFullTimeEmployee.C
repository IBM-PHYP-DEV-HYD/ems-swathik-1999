#include "Utilities.H"
#include "XyzFullTimeEmployee.H"


void calculateLeavesAvailed(int leavesAvailedParam)
{
    srand(time(0));

    leavesAvailedParam = 1 + (rand() % (22));
}

xyzFullTimeEmployee::xyzFullTimeEmployee()
{

}

xyzFullTimeEmployee::xyzFullTimeEmployee(string empIDParam,string nameParam,
            string typeParam,string statusParam,
            string genderParam,string dobParam,
            string dojParam,string dolParam,
            int leavesAvailedParam):xyzEmployee(empIDParam,nameParam,
            typeParam,statusParam,
            genderParam,dobParam,
            dojParam,dolParam)
{
    calculateLeavesAvailed(leavesAvailedParam);
    this->mNoofLeavesAvailed = leavesAvailedParam;
}

xyzFullTimeEmployee::~xyzFullTimeEmployee(){}

int xyzFullTimeEmployee::getTotalNoofLeaves()
{
    return this->mTotalNoofLeaves;
}

int xyzFullTimeEmployee::getNoofLeavesAvailed()
{
    return this->mNoofLeavesAvailed;
}

void xyzFullTimeEmployee::setNoofLeavesAvailed(unsigned int leavesAvailedParam)
{
    this->mNoofLeavesAvailed = leavesAvailedParam;
}