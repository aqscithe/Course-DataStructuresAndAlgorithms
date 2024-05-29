#include "EmployeeInfo.h"


/****************************************************************
* Function:   EmployeeInfo
* Inputs:     None
* Outputs:    None
* Purpose:    This is the default constructor for the EmployeeInfo
*             class, initializing the employeeID to -1 and
*             employeeName to an empty string.
****************************************************************/
EmployeeInfo::EmployeeInfo()
    : employeeID(-1), employeeName("") {}


/****************************************************************
* Function:   EmployeeInfo
* Inputs:     int id, const std::string& name
* Outputs:    None
* Purpose:    This constructor initializes the EmployeeInfo object
*             with the specified id and name.
****************************************************************/
EmployeeInfo::EmployeeInfo(int id, const std::string& name)
    : employeeID(id), employeeName(name) {}


/****************************************************************
* Function:   getID
* Inputs:     None
* Outputs:    int
* Purpose:    This function returns the employeeID of the EmployeeInfo object.
****************************************************************/
int EmployeeInfo::getID() const 
{ 
    return employeeID; 
}


/****************************************************************
* Function:   getName
* Inputs:     None
* Outputs:    std::string
* Purpose:    This function returns the employeeName of the EmployeeInfo object.
****************************************************************/
std::string EmployeeInfo::getName() const 
{ 
    return employeeName; 
}


/****************************************************************
* Function:   operator<
* Inputs:     const EmployeeInfo& other
* Outputs:    bool
* Purpose:    This function compares the employeeID of the current
*             EmployeeInfo object with another EmployeeInfo object
*             to determine if it is less.
****************************************************************/
bool EmployeeInfo::operator<(const EmployeeInfo& other) const 
{
    return employeeID < other.employeeID;
}


/****************************************************************
* Function:   operator>
* Inputs:     const EmployeeInfo& other
* Outputs:    bool
* Purpose:    This function compares the employeeID of the current
*             EmployeeInfo object with another EmployeeInfo object
*             to determine if it is greater.
****************************************************************/
bool EmployeeInfo::operator>(const EmployeeInfo& other) const 
{
    return employeeID > other.employeeID;
}


/****************************************************************
* Function:   operator==
* Inputs:     const EmployeeInfo& other
* Outputs:    bool
* Purpose:    This function compares the employeeID of the current
*             EmployeeInfo object with another EmployeeInfo object
*             to determine if they are equal.
****************************************************************/
bool EmployeeInfo::operator==(const EmployeeInfo& other) const 
{
    return employeeID == other.employeeID;
}
