//StockMarket.h - Header file for SEP101 lab 5, Stock Price Evaluation

//  Oct	15, 2022    Created      Arian.A
//  Oct 18, 2022    Modified     Arian.A
//  Dec 26, 2022    Modified     Arian.A



//Avoid Magic Numbers
#define MAX_STR 32
#define NUM_OF_COMPANIES 2

//Define a strcut for the program
struct Company {
    char name[MAX_STR];
    char symbol[MAX_STR];
    double stckprice;//StockPrice
    double dividendPerShare;
    double dividendYield;
    char valuation[MAX_STR];
};

//Prototypes of the functions defined in the C file
void InitializeCompanies(struct Company* companies);
void DividendYield(struct Company* companies);
void CompanyValue(struct Company* companies);
void UserInput(struct Company* companies);
void FinalOutput(const struct Company* companies);
void utilClearInputBuffer();
