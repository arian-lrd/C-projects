// Employee.c - C file for SEP101 lab 3

//  Sep 28, 2022    Created      Arian.A
//  Oct  6, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A

#include "Employee.h"
#include <stdio.h>

#define SIZE 4

int main(void) 
{
    struct Employee emp[SIZE] = {{0,0,0.00}, {0,0,0.00}, {0,0,0.00}, {0,0,0.00}};
    printf("---=== EMPLOYEE DATA ===---\n");

    int done = 0;//flag
    do
    {
        int usrInput;
        printf("\n\n1. Display Employee Information\n"
        "2. Add Employee\n"
        "3. Update Employee Salary\n"
        "4. Remove Employee\n"
        "0. Exit\n"
        "Please select from the above options: ");
        scanf("%d", &usrInput);

        int testId = 0;
        int option = usrInput;
        switch (option)
        {
        case 0://exit the program
            done = 1;
            break;
        
        case 1:// display employee information
            printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========");
            for (int i = 0; i < SIZE; i++)
            {
                if (emp[i].id > 0)
                {
                    printf("\n%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
                } 
            }
            break;
        case 2://add amployee
            printf("Adding Employee\n");
			printf("===============\n");
            int emptySlotFound = 0;
            int slotLocation;
            for (int i = 0;i < SIZE; i++)
            {
                if (emp[i].id == 0)
                {
                    emptySlotFound = 1;
                    slotLocation = i;
                }
            }
            if (emptySlotFound == 1) 
            {
                printf("Enter Employee ID: ");
                scanf("%d", &emp[slotLocation].id);
                printf("Enter Employee Age: ");
                scanf("%d", &emp[slotLocation].age);
                printf("Enter Employee Salary: ");
                scanf("%lf", &emp[slotLocation].salary);
            }
            else if (emptySlotFound == 0)
            {
                printf("ERROR!!! Maximum Number of Employees Reached");
            }
            break;
        int empIdFound = 0;
        int idIndex = 0;
        case 3://update employee salary
            printf("Updating Employee Salary\n");
            printf("======================");
            do
            {
                testId = 0;
                printf("\nEnter Employee ID: ");
                scanf("%d", &testId);
                empIdFound = 0;
                idIndex = 0;
                for (int i = 0; i < SIZE; i++)
                {   
                    if (emp[i].id == testId)
                    {   
                        empIdFound = 1;
                        idIndex = i;
                    }    
                }
                if (empIdFound == 1)
                {
                    printf("The current salary is %.2lf\n", emp[idIndex].salary);
                    printf("Enter Employee New Salary: ");
                    scanf("%lf", &emp[idIndex].salary);
                }
                else if (empIdFound == 0)
                {
                    printf("*** ERROR: Employee ID not found! ***");
                }
            } while (empIdFound == 0);
            break;
        case 4://remove employee
            printf("Removing Employee\n");
			printf("===============");
            do
            {
                testId = 0;
                printf("\nEnter Employee ID: ");
                scanf("%d", &testId);
                empIdFound = 0;
                idIndex = 0;
                for (int i = 0; i < SIZE; i++)
                {
                    if (emp[i].id == testId)
                    {   
                        empIdFound = 1;
                        idIndex = i;
                    }    
                }
                if (empIdFound ==1)
                {
                    printf("Employee %d will be removed", emp[idIndex].id);
                    emp[idIndex].id = 0;
                    emp[idIndex].age = 0;
                    emp[idIndex].salary = 0.00;
                }
                else if (empIdFound == 0)
                {
                    printf("*** ERROR: Employee ID not found! ***");
                }
            } while (empIdFound == 0);            
            break;
        default:
            printf("ERROR: Incorrect Option: Try Again");
        }
    } while (done == 0);   
    printf("Exiting Employee Data Program. Good Bye!!!\n");

    return 0;
}
