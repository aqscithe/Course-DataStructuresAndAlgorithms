/*
-------------------------------------------------------------------------
Name:            Leon Thompson
Date:            05/11/2024
Lab #:           4
Status:          Completed
-------------------------------------------------------------------------
Description
    This program manages an employee database using a binary search tree.
    It allows users to perform various operations such as finding an 
    employee by ID, displaying the entire tree structure, adding new 
    employees, removing employees, and listing all employees in sorted 
    order by their ID. The program presents a main menu with options for 
    these operations.
-------------------------------------------------------------------------
*/




#include "EmployeeInfo.h"
#include "BinarySearchTree/BinarySearchTree.h"



void greetUser();
void displayHeader();
void displayOptions();
std::string getStringData(std::string);
int getIntegerData(std::string prompt);
char getCharData(std::string);
void clearCin();
void findEmployee(const BinarySearchTree<EmployeeInfo>& tree);
std::shared_ptr<EmployeeInfo> findEmployeeByID(const BinarySearchTree<EmployeeInfo>& tree, int id);
void addEmployee(BinarySearchTree<EmployeeInfo>& tree);
void removeEmployee(BinarySearchTree<EmployeeInfo>& tree); 
void listEmployees(BinarySearchTree<EmployeeInfo>& tree);


int main()
{
	// Declare main variables
    char optionSelection;
    bool showMainMenu = true;

	// Initializing employee binary search tree
    BinarySearchTree<EmployeeInfo> employeeInfoSearchTree;
	employeeInfoSearchTree.add(EmployeeInfo(6702, "James B W Bevis"));
    employeeInfoSearchTree.add(EmployeeInfo(1255, "Romney Wordsworth"));
    employeeInfoSearchTree.add(EmployeeInfo(1071, "Revis Jacara"));
    employeeInfoSearchTree.add(EmployeeInfo(2390, "Clegg Forbes"));
    employeeInfoSearchTree.add(EmployeeInfo(1558, "Kalin Tros"));
    employeeInfoSearchTree.add(EmployeeInfo(7406, "Archibald Beechcroft"));
    employeeInfoSearchTree.add(EmployeeInfo(7562, "Penthor Mul"));
    employeeInfoSearchTree.add(EmployeeInfo(3004, "Bartlet Finchley"));
    employeeInfoSearchTree.add(EmployeeInfo(4922, "Latham Bine"));
    employeeInfoSearchTree.add(EmployeeInfo(8483, "Jeff Myrtlebank"));

	greetUser();

	// Main Menu Loop
    while(showMainMenu)
    {
        displayOptions();
        optionSelection = getCharData("What would you like to do next? ");

        switch (optionSelection)
        {
            case 'I':
            {
                findEmployee(employeeInfoSearchTree);
                break;
            }

			case 'D':
            {
                employeeInfoSearchTree.displayTree();
                break;
            }

			case 'A':
            {
                addEmployee(employeeInfoSearchTree);
                break;
            }

			case 'R':
            {
                removeEmployee(employeeInfoSearchTree);
                break;
            }

			case 'L':
			{
				listEmployees(employeeInfoSearchTree);
				break;
			}

            case 'Q':
            case 'X':
            {
                showMainMenu = false;
                break;
            }
            
            default:
            {
                break;
            }
        } // end switch
    } // end while

	std::cout << "Have a nice day." << std::endl;

} // end main



/****************************************************************
* Function:   greetUser
* Inputs:     none
* Outputs:    none
* Purpose:    This function greets the user upon app load and
*   		  provides a brief explanation.
****************************************************************/
void greetUser()
{
	std::cout << "WELCOME TO THE EMPLOYEE INTERFACE EDITOR" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
} // end greetUser


/****************************************************************
* Function:   findEmployee
* Inputs:     const BinarySearchTree<EmployeeInfo>& tree
* Outputs:    None
* Purpose:    This function will search for an employee by ID and 
*             display their information if found
****************************************************************/
void findEmployee(const BinarySearchTree<EmployeeInfo>& tree)
{
    int id = getIntegerData("Enter ID to search by: ");

    // Search for employee by ID
    auto employee = findEmployeeByID(tree, id);
    if (employee)
	{
		std::cout << employee->getID() << " " << employee->getName() << std::endl;
	}
	else
    {
		std::cout << "Employee with ID: " << id << " not found." << std::endl;
	} // end if
        
} // end findEmployee


/****************************************************************
* Function:   findEmployeeByID
* Inputs:     const BinarySearchTree<EmployeeInfo>& tree, int id
* Outputs:    std::shared_ptr<EmployeeInfo> 
* Purpose:    This function searches the tree for an employee by ID
*             and returns a shared pointer to the employee if found
****************************************************************/
std::shared_ptr<EmployeeInfo> findEmployeeByID(const BinarySearchTree<EmployeeInfo>& tree, int id) 
{
	// Temporary object with the target ID
    EmployeeInfo temp(id, "");  
    try 
	{
		// Use the tree's getEntry method
        auto entry = tree.getEntry(temp);  
        return std::make_shared<EmployeeInfo>(entry);
    } 
	catch (const NotFoundException&) 
	{
		// Return nullptr if not found
        return nullptr;  
    } // end try
} // end findEmployeeByID



/****************************************************************
* Function:   addEmployee
* Inputs:     BinarySearchTree<EmployeeInfo>& tree
* Outputs:    None
* Purpose:    This function prompts the user for employee details
*             and adds a new employee to the tree
****************************************************************/
void addEmployee(BinarySearchTree<EmployeeInfo>& tree) 
{
    int id;
    std::string name;

    id = getIntegerData("Enter Employee ID: ");
    name = getStringData("Enter Employee Name: ");

    EmployeeInfo newEmployee(id, name);
    tree.add(newEmployee);

    std::cout << "Employee added successfully!" << std::endl;
} // end addEmployee



/****************************************************************
* Function:   removeEmployee
* Inputs:     BinarySearchTree<EmployeeInfo>& tree
* Outputs:    None
* Purpose:    This function will remove an employee from the tree
****************************************************************/
void removeEmployee(BinarySearchTree<EmployeeInfo>& tree) 
{
    int id;

    // Get the employee ID to be removed from the user
    id = getIntegerData("Enter Employee ID to be removed: ");

    EmployeeInfo temp(id, "");  // Temporary object with the target ID

    // Attempt to remove the employee from the tree
    if (tree.remove(temp)) 
    {
        std::cout << "Employee removed successfully!" << std::endl;
    } 
    else 
    {
        std::cout << "Employee with ID " << id << " not found." << std::endl;
    } // end if
} // end removeEmployee


/****************************************************************
* Function:   listEmployees
* Inputs:     BinarySearchTree<EmployeeInfo>& tree
* Outputs:    None
* Purpose:    This function will list all employees in the tree
*             in sorted order by ID
****************************************************************/
void listEmployees(BinarySearchTree<EmployeeInfo>& tree)
{
    std::cout << "Sorted Employees by ID:" << std::endl;

    // Perform an in-order traversal to list employees
    tree.inorderTraverse([](EmployeeInfo& emp) 
    {
        std::cout << "ID: " << emp.getID() << ", Name: " << emp.getName() << std::endl;
    });
} // end listEmployees




/****************************************************************
* Function:   getStringData
* Inputs:     std::string prompt
* Outputs:    std::string value
* Purpose:    This function will return a string data entered by users
****************************************************************/
std::string getStringData(std::string prompt)
{
	std::string value;

	std::cout << prompt;	

	std::getline(std::cin, value); // accepts spaces in the entry

	return value;

} // end getStringData


/****************************************************************
* Function:   getIntegerData
* Inputs:     std::string prompt
* Outputs:    int value
* Purpose:    This function will get an integer value from the user
****************************************************************/
int getIntegerData(std::string prompt)
{
	int value;
	bool validValue = false;

	while (!validValue)
	{
		std::cout << prompt;

		// Ensures input matches type
		if (!(std::cin >> value))
		{
			std::cout << "\t\t\tError Message. Non numeric value has been entered" << std::endl;
			clearCin();
		}
		else
		{
			validValue = true;
		} // end if

	} // end while

	clearCin();

	return value;


} // end getIntegerData

/****************************************************************
* Function:   getCharData
* Inputs:     std::string prompt
* Outputs:    char value
* Purpose:    This function will get a char value from the user
****************************************************************/
char getCharData(std::string prompt)
{
	char value;

	std::cout << prompt;
	std::cin >> value;

	clearCin();

	value = toupper(value);

	return value;

} // end getCharData


/****************************************************************
* Function:   clearCin
* Inputs:     none
* Outputs:    none
* Purpose:    This functions clears the cin and then clears up to 120
*				characters or hits enter.
****************************************************************/
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

} // end clearCin


/****************************************************************
* Function:   displayHeader
* Inputs:     none
* Outputs:    none
* Purpose:    This function displays the calculator header
****************************************************************/
void displayHeader()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "EMPLOYEE INTERFACE" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;

} // end of displayHeader

/****************************************************************
* Function:   displayOptions
* Inputs:     none
* Outputs:    none
* Purpose:    This function displays the main menu options
****************************************************************/
void displayOptions()
{
	displayHeader();
	std::cout << "Main Menu" << std::endl;
	std::cout << std::endl;
	std::cout << "I\tEmployee ID Search" << std::endl;
	std::cout << "D\tDisplay the Tree" << std::endl;
	std::cout << "A\tAdd a New Employee" << std::endl;
	std::cout << "R\tRemove an Employee" << std::endl;
	std::cout << "L\tList Employees" << std::endl;
	std::cout << "Q\tQuit" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

} // end displayMainMenu