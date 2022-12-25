//cashRegister.c - Code for SEP101 lab 1

//  Sep 14, 2022    Created      Arian.A
//  Sep 19, 2022    Modified     Arian.A


#include <stdio.h>

int main(void)
{                //testing numbers to show each step's actions
    float cost1; //12.50
    printf("Enter the cost of item 1: ");
    scanf("%f", &cost1);
    
    float cost2; //13.25
    printf("Enter the cost of item 2: ");
    scanf("%f", &cost2);

    float cost3; //5.17
    printf("Enter the cosst of item 3: ");
    scanf("%f", &cost3);

    float totalCost = cost1 + cost2 + cost3; //30.92
    printf("Total cost is %.2f\n", totalCost);

    int dollars = totalCost; // dollars = 30 integer
    int remainder = (totalCost * 100) - (dollars * 100); // remainder = 3092 - 3000 = 92
    printf("Remainder is: %d\n",remainder);

    // Calculate Quarters 
    int quarters = remainder / 25; // 92/25 = 3.2 = (3)
    remainder = remainder % 25; // remainder = 17
    //remainder = remainder - (25 * quarters);

    // Calculate Dimes
    int dimes = remainder / 10; // 17/10 = 1.7 = (1)
    remainder = remainder % 10; // remainder = 7
    //remainder = remainder - (10 * dimes);

    // Calculate Nickles
    int nickles = remainder / 5; // 7/5 = 1.4 = (1)
    remainder = remainder % 5; // now remainder = 2
    //remainder = remainder - (5 * dimes);

    //Calculate cents
    int cents = remainder; // cents = 2

    // Print the final output
    printf("You used %d dollars, %d quarters, %d dimes, %d nickels and %d pennies.",
    dollars, quarters, dimes, nickles, cents);

}

