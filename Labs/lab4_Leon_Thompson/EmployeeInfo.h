
#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H

#include <string>


class EmployeeInfo
{
    public:
        // Default Constructors
        EmployeeInfo();
        EmployeeInfo(int id, const std::string& name);

        // Getter Methods
        int getID() const;
        std::string getName() const;

        // Overloaded Operators
        bool operator<(const EmployeeInfo& other) const;
        bool operator>(const EmployeeInfo& other) const;
        bool operator==(const EmployeeInfo& other) const;
        
    private:

        int         employeeID;
        std::string employeeName;

}; // EmployeeInfo

#endif