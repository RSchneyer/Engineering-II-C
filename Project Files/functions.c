#include <stdio.h>
#include "functions.h"
#define OUTFILE_NAME "xactlog.txt"

// Creates column headers at the beginning of xactlog.txt
// Super boring, and didn't really need to be a function, but whatever
// Might change so that it has the ability to create the header and footer 
void createFileHeader(){
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "w");
    if(outfile == NULL){
        printf("An error occurred writing to the file");
    }
    fprintf(outfile, "Type, Amount, Current Balance,\n");
    fclose(outfile);
}

// Logs an account change (deposit, withdrawl, fee) to the xactlog.txt file
// Separates lines and line items with commas, so the text file can be easily converted into a .csv file for use with spreadsheet programs
// cat xactlog.txt >> xactlog.csv (if you're using linux/bash) 
void logAccountEvent(double balanceChange, double currentBalance){
    double newBalance = balanceChange + currentBalance;
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "a");
    if(outfile == NULL){
        printf("\nCan't open logfile!\n");
    }

    if(balanceChange >= 0.0){// Deposit is occuring
        fprintf(outfile, "deposit,  %.2f,  %.2f,\n", balanceChange, newBalance);
    } else if(balanceChange < 0.0){
        fprintf(outfile, "withdrawl,  %.2f,  %.2f,\n", balanceChange, newBalance);
    }

    fclose(outfile);
}

// Prompts user with message asking how much they'd like to deposit/withdraw, then returns that amount
// Prompt type should be 0 if the balance change is a deposit, and anything else if it's a withdrawl
// It also checks widthdrawl amount compared to current balance, and won't let the user overdraw
double changeBalance(int promptType, double currentBalance){
    double balanceChange = 0.0;
    if(promptType == 0){
        do{
            printf("Deposit how much? ");
            scanf("%lf", &balanceChange);
        } while(balanceChange<=0.0);
    } 
    else{
        do{
            printf("Withdraw how much? ");
            scanf("%lf", &balanceChange);
        } while((currentBalance-balanceChange)<0.0 && balanceChange<=0.0);
        balanceChange *= -1;
    }
    logAccountEvent(balanceChange, currentBalance);
    return balanceChange;
}
//Contains the 7 or so printf statements for the system menu
//I realize I could have used a single printf statement, but I think multiple statements makes it more readable
void printMenu(){
    printf("\n");
    printf("SYSTEM MENU\n");
    printf("1 - Make a deposit\n");
    printf("2 - Make a withdrawl\n");
    printf("3 - Calculate Interest?\n");
    printf("4 - Apply a fee\n");
    printf("5 - Close your account\n");
    printf("Please enter your choice: ");
}
//Repeatedly calls printMenu() until user input is between 1 and 5 (available menu options), then returns the user's selection
int getMenuSelection(){
    int selection = 0;
    while(selection<1 || selection>5){
        printMenu();
        scanf("%d", &selection);
    }
    return selection;

}

//Function to initialize an account
//Prompts user and takes in input for starting balance and APR, then stores them in the pointered array argument
//Since C functions can't return multiple vars or arrays
void initAccount(double *initDepositAndAPR){
    double balance, apr;
    printf("Welcome to Reid's Banking Simulator! ");
    do{
        printf("Please enter your starting balance: ");
        scanf("%lf", &balance);
        printf("\n");
    } while(balance<0.0);

    do{
        printf("Please enter your APR: ");
        scanf("%lf", &apr);
        printf("\n");
    } while(apr<0.0);

    initDepositAndAPR[0] = balance;
    initDepositAndAPR[1] = apr;
    createFileHeader();
}