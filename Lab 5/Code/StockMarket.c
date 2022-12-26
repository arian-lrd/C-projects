//StockMarket.c - Function definitions for SEP101 lab 5, Stock Price Evaluation

//  Oct	15, 2022    Created      Arian.A
//  Oct 18, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A



#include <stdio.h>
#include <strings.h>
#include "StockMarket.h"



//Initialize companies, as many as necessitated by NUM_OF_FUNCTIONS
void InitializeCompanies(struct Company* companies) {
    for (int i = 0; i < NUM_OF_COMPANIES; ++i) {
        strcpy(companies[i].name, "\n");
        strcpy(companies[i].symbol, "\n");
        companies[i].stckprice = 10000000;//Initialize to a big number because in case of a mistake no one buys a stock with a price this high
        companies[i].dividendPerShare = 0;
        companies[i].dividendYield = 0; //As a percentage
        strcpy(companies[i].valuation, "\n");
    }

}
//Calculate the dividend yield = 100% x dividend_per_share / share_price.
void DividendYield(struct Company* companies) {
    for (int i = 0; i < NUM_OF_COMPANIES; ++i) {
        companies[i].dividendYield = 100 * (companies[i].dividendPerShare / companies[i].stckprice);
    }
}

//Evaluate Company's value into 1 of 3 possible classes
void CompanyValue(struct Company* companies) {
    for (int i = 0; i < NUM_OF_COMPANIES; ++i) {
        if(companies[i].dividendYield > 5.00) {
            strcpy(companies[i].valuation, "Under-Valued");
        }
        else if (companies[i].dividendYield == 5.00) {
            strcpy(companies[i].valuation, "Fully-Valued");
        }
        else if (companies[i].dividendYield < 5.00) {
            strcpy(companies[i].valuation, "Over-Valued");
        }
    }

}

//Prompt the user for input, & Store that info
void UserInput(struct Company* companies) {
    for (int i = 0; i < NUM_OF_COMPANIES; ++i) {
        printf("\nEnter the company name: ");//Get company's name
        scanf("%[^\n]s", companies[i].name);
        utilClearInputBuffer();
        printf("Enter %s's stock symbol: ", companies[i].name);//Get company's stock symbol
        scanf("%[^\n]s", companies[i].symbol);
        utilClearInputBuffer();
        printf("Enter %s's current stock price: ", companies[i].name);//Get company's stock price
        scanf("%lf", &companies[i].stckprice);//scanf_s is not available on non-Microsoft
        utilClearInputBuffer();
        printf("Enter %s's annual dividend per share: ", companies[i].name);//Get company's dividend per share
        scanf("%lf", &companies[i].dividendPerShare);
        utilClearInputBuffer();
    }
}

//Print out the final data
void FinalOutput(const struct Company* companies) {
    printf("%25s   SYMBOL  PRICE   DIV   YIELD   VALUATION   \n", "COMPANY");
    for (int i = 0; i < NUM_OF_COMPANIES; ++i) {
        printf("%25s   %6s  %5.2lf  %.3lf  %.3lf   %12s\n",companies[i].name, companies[i].symbol, companies[i].stckprice, companies[i].dividendPerShare, companies[i].dividendYield, companies[i].valuation);
    }
}

//Empty the buffer
void utilClearInputBuffer() {
    while (getchar() != '\n');
}










