//StockMarketMain.c - main function for SEP101 lab 5, Stock Price Evaluation

//  Oct	15, 2022    Created      Arian.A
//  Oct 18, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A



//Include only the header file
#include "StockMarket.h"

int main() {
    struct Company companies[NUM_OF_COMPANIES]; //Declare ab array of 5 companies

    InitializeCompanies(companies);//Initialize the variables
    UserInput(companies);//Get input from the user
    DividendYield(companies); //Do calculations on the gathered info
    CompanyValue(companies);  //Do calculations on the gathered info
    FinalOutput(companies); //print the finished calculations/data

    return 0;//Return control
}

