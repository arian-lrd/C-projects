//tempMonitor.c - Code for SEP101 lab 2

//  Sep 20, 2022    Created      Arian.A
//  Sep 25, 2022    Modified     Arian.A
//  Dec 25, 2022    Modified     Arian.A

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int const NUM_DAYS = 4;
    double tempLows[NUM_DAYS];
    double tempHighs[NUM_DAYS] = {0};
    double tempMin = 100;
    double tempMax = -100;
    double tempMinDay = 0;
    double tempMaxDay = 0;
    double highTotal = 0;
    double lowTotal = 0;
    int validEntry = 0;
    double averageHigh;
    double averageLow;
    double averageTotal;
    int lowestPossibleTemp = -40;
    int highestPossibleTemp = 40;

    printf("---=== Arian's Temperature Analyzer ===---"
    "\nNOTE: You should enter low temp first, then high!!");

    
    int tDay = 0;
    for(tDay +=1; tDay<=NUM_DAYS; ++tDay)
    {   
        do
        {
            printf("\nEnter the low value for day %d: ", tDay); //Take tDay's low
            scanf("%lf", &tempLows[tDay - 1]);
            if (tempLows[tDay - 1] < lowestPossibleTemp ||
                tempLows[tDay - 1] > highTotal ) //Should not be out of range
            {
                validEntry = 0;
                printf("---Invalid entry! temperature has to be between -40 & +40---\n"
                "...Try again...");
            }
            else
            {
                lowTotal += tempLows[tDay - 1];
                validEntry = 1;
            }
            /*
            else //Should not be an invalid number
            {
                printf("Invalid entry!\n Enter a valid number");
                validEntry = 0;
            } */
        } while (validEntry == 0);
        
       do
        {
            printf("Enter the high value for day %d: ", tDay);// Take tDay's High
            scanf("%lf", &tempHighs[tDay - 1]);
            if (tempHighs[tDay - 1] > highestPossibleTemp  ||
                tempLows[tDay - 1] < lowestPossibleTemp ) //Should not be out of range
            {
                validEntry = 0;
                printf("---Invalid entry! temperature has to be between -40 & +40---\n"
                "...Try again...\n");
            }
            else if (tempHighs[tDay - 1] < tempLows[tDay - 1])//High can't be lass than low
            {
                validEntry = 0;
                printf("Invalid entry! high temperature can't be lower than low"
                " temperature\n...Try again...\n");
            }
            
            else
            {
                highTotal += tempHighs[tDay - 1];
                validEntry = 1;
            }
            
            /*
            else //Should not be an invalid number
            {
                printf("Invalid entry!\n Enter a valid number");
                validEntry = 0;
            }*/
        } while (validEntry == 0);

        //Set MAX & MIN temperatures
        ///MAX
        if (tempHighs[tDay - 1] > tempMax) //Assign new temp MAX & MIN
        {
            tempMax = tempHighs[tDay - 1];
            tempMaxDay = tDay; //tempMaxDay is (index+1)
        }//Min
        if (tempLows[tDay -1 ] < tempMin)
        {
            tempMin = tempLows[tDay - 1];
            tempMinDay = tDay; //tempMinDay is (index+1)

        }

    }

    //Calculate the averages
    averageHigh = highTotal / NUM_DAYS; 
    averageLow = lowTotal / NUM_DAYS;
    averageTotal = (averageHigh + averageLow) / 2;

    //Output Prompts
    ///High temperatures
    printf("\n\nThe high temperatures were: ");
    for (int i = 0; i <= (NUM_DAYS - 1); ++i)
    {
        printf("%.0lf", tempHighs[i]);
        if (i <(NUM_DAYS - 1)) {printf(",");}
    }
    ///Low temperatures
    printf("\nThe low temperatures were: ");
    for (int i = 0; i <= (NUM_DAYS - 1); i++)
    {
        printf("%.0lf", tempLows[i]);
        if (i <(NUM_DAYS - 1)) {printf(",");}
    }
    
    ///Average HIGH, LOW, TOTAL
    printf("\nAverage high was %.2lf\n", averageHigh);
    printf("Average low was %.2lf\n", averageLow);
    printf("total Average  was %.2lf\n", averageTotal);
    ///MAX, MIN
    printf("The maximum tempreture was %.2lf, on day %.0lf\n", tempMax, tempMaxDay);
    printf("The minimum temprature was %.2lf, on day %.lf\n", tempMin, tempMinDay);

    //Fix: 1)User inputs nonnumbers
    //     2) User presses "control + x" during operation
}