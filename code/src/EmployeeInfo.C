#include "EmployeeInfo.H"

EmployeeInfo::EmployeeInfo()
{
    mNoOfLeaves=0;
    mTotalNoOfLeaves=0;
}

EmployeeInfo::~EmployeeInfo()
{

}

void EmployeeInfo::clearEmployeeInfo()
{
    mEmpName.clear();
    mEmpId.clear();
    mEmpDesignationType.clear();
    mEmpDesignationStatus.clear();
    mEmpGender.clear();
    mDateOfBirth.clear();
    mDateOfJoining.clear();
    mDateOfLeaving.clear();
    mNoOfLeaves=0;
    mTotalNoOfLeaves=0;
    mAgencyName.clear();
    mAgencyLocation.clear();
    mCollege.clear();
    mCollegeBranch.clear();
}

void EmployeeInfo::printEmployeeInfo()
{
    cout << "| "<< left << setw(24) << setfill(' ') << mEmpName;
    cout << "| "<< left << setw(12)<< setfill(' ') << mEmpId;
    cout << "| "<< left << setw(14)<< setfill(' ') << mEmpDesignationType;
    cout << "| "<< left << setw(14)<< setfill(' ') << mEmpDesignationStatus;
    cout << "| "<< left << setw(14)<< setfill(' ') << mEmpGender;
    cout << "| "<< left << setw(18)<< setfill(' ') << mDateOfBirth;
    cout << "| "<< left << setw(18)<< setfill(' ') << mDateOfJoining;
    cout << "| "<< left << setw(18)<< setfill(' ') << mDateOfLeaving;

    if(mEmpDesignationStatus != "Resigned")
    {
        if(mPrintAll == true)
        {
            if(mEmpDesignationType == "FullTime")
            {
                cout << "| "<< left << setw(18) << setfill(' ') << mTotalNoOfLeaves;    
                cout << "| "<< left << setw(18) << setfill(' ') << mNoOfLeaves;
            }
            else
            {
                cout << "| "<< left << setw(18) << setfill(' ') << "--";    
                cout << "| "<< left << setw(18) << setfill(' ') << "--";
            }
            cout << "| "<< left << setw(18) << setfill(' ') << (mAgencyName.length() ? mAgencyName : "--");
            cout << "| "<< left << setw(18) << setfill(' ') << (mAgencyLocation.length() ? mAgencyLocation : "--");
            cout << "| "<< left << setw(18) << setfill(' ') << (mCollege.length() ? mCollege : "--");
            cout << "| "<< left << setw(18) << setfill(' ') << (mCollegeBranch.length() ? mCollegeBranch : "--");
        }
        else
        {
            if(mEmpDesignationType == "FullTime")
            {
                cout << "| "<< left << setw(14) << setfill(' ') << mTotalNoOfLeaves << endl;
                cout << "| "<< left << setw(14) << setfill(' ') << mNoOfLeaves;
            }
            else if(mEmpDesignationType == "Contractor")
            {
                cout << "| "<< left << setw(14) << setfill(' ') << (mAgencyName.length() ? mAgencyName : "--");
                cout << "| "<< left << setw(18) << setfill(' ') << (mAgencyLocation.length() ? mAgencyLocation : "--");
            }
            else if(mEmpDesignationType == "Intern")
            {
                cout << "| "<< left << setw(14) << setfill(' ') << (mCollege.length() ? mCollege : "--");
                cout << "| "<< left << setw(14) << setfill(' ') << (mCollegeBranch.length() ? mCollegeBranch : "--");
            }
        }
    }
    cout << endl;
}