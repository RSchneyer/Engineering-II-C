#include <stdio.h>
#include "functions.h"
#define OUTFILE_NAME "xactlog.txt"

// Creates column headers at the beginning of xactlog.txt
// Super boring, and didn't really need to be a function, but whatever
// Might change so that it has the ability to create the header and footer 
void createFileHeader(int dateArray[]){
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "w");
    (outfile == NULL)?(printf("An error occured writing to the file")):(printf(" "));    
    fprintf(outfile," ,Account Created On:, \n");
    fprintf(outfile,"%d, %d, %d,\n", dateArray[0],dateArray[1],dateArray[2]);
    fprintf(outfile, "Type, Amount, Current Balance,\n");
    fclose(outfile);
}

//Creates footer for xactlog.txt
//Includes date closed and final balance, along with a closing message
void createFileFooter(int dateArray[], double currentBalance){
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "a");
    (outfile == NULL)?(printf("An error occured writing to the file")):(printf(" ")); 
    fprintf(outfile, "-----,-----,-----\n");
    fprintf(outfile, "Closing balance, , %.2f\n", currentBalance);
    fprintf(outfile, ",Account Closed on, \n");
    fprintf(outfile, "%d, %d, %d\n", dateArray[0],dateArray[1],dateArray[2]);
    fprintf(outfile, ",Thank you for using Reid's Banking Simulator,\n");
    fclose(outfile);       
}

// Logs an account change (deposit, withdrawl, fee) to the xactlog.txt file
// Separates lines and line items with commas, so the text file can be easily converted into a .csv file for use with spreadsheet programs
// cat xactlog.txt >> xactlog.csv (if you're using linux/bash) 
void logAccountEvent(int eventType, double balanceChange, double currentBalance){
    double newBalance = balanceChange + currentBalance;
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "a");
    if(outfile == NULL){
        printf("\nCan't open logfile!\n");
    }
    switch(eventType){ //Might set string var instead of printing a bunch? idk
        case 0:
            //Deposit
            fprintf(outfile, "deposit, %.2f, %.2f,\n", balanceChange, newBalance);
            break;
        case 1:
            //Withdrawl
            fprintf(outfile, "withdrawl, %.2f, %.2f,\n", balanceChange, newBalance);
            break;
        case 2:
            //Apply interest
            fprintf(outfile, "interest, %.2f, %.2f\n", balanceChange, newBalance);
            break;
        case 3:
            //Apply a fee (CAN GO NEGATIVE)
            fprintf(outfile, "fee, %.2f, %.2f,\n", balanceChange, newBalance);
            break;
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
        logAccountEvent(0, balanceChange, currentBalance);
    }
    else if (promptType == 3){
        do{
            printf("Apply a fee: ");
            scanf("%lf", &balanceChange);
        } while(balanceChange<=0.0);
        balanceChange *= -1;
        logAccountEvent(3, balanceChange, currentBalance);
    }
    else if (promptType == 1){
        if (currentBalance<=0.0){
            printf("\nCan't withdraw, account balance is: %.2f\n", currentBalance);
        }
        else{
            do{
                printf("Withdraw how much? ");
                scanf("%lf", &balanceChange);
            } while(balanceChange<0.0 || (currentBalance-balanceChange)<=0.0);
            balanceChange *= -1;
            logAccountEvent(1, balanceChange, currentBalance);
        }
    }
    
    return balanceChange;
}

//Using the equation Interest = Balance * APR, calculate interest on the account
//Return the interest earned, and prints the process to the screen
double calculateInterest(double balance, double apr){
    double interest = balance * apr;
    printf("Calculating Interest...\n");
    printf("Balance: %.2f\nAPR: %.2f\n", balance, apr);
    printf("Interest earned: $%.2f\n", interest);
    logAccountEvent(2, interest, balance);
    return interest;
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
    int dateArray[3];
    printf("Welcome to Reid's Banking Simulator! ");
    do{
        printf("Please enter your starting balance: ");
        scanf("%lf", &balance);
        printf("\n");
    } while(balance<0.0);

    do{
        printf("Please enter your APR as a percentage: ");
        scanf("%lf", &apr);
        printf("\n");
    } while(apr<0.0);
    do{
        printf("Please enter account start date (MM):");
        scanf("%d", &dateArray[0]);
    } while(dateArray[0]<1 || dateArray[0]>12);
    do{
        printf("Please enter account start date (DD):");
        scanf("%d", &dateArray[1]);
    } while(dateArray[1]<1 || dateArray[1]>31);
    do{
        printf("Please enter account start date (YYYY):");
        scanf("%d", &dateArray[2]);
    } while(dateArray[2]<0 || dateArray[2]>9999);

    initDepositAndAPR[0] = balance;
    //Convert percentage to decimal for use in calculating interest
    initDepositAndAPR[1] = apr / 100.0;
    createFileHeader(dateArray);
}

//Asks user for the date the account is being closed, then stores that in an array
//dateArray and finalBalance are then passed to createFileFooter()
void closeAccount(double finalBalance){
    int dateArray[3];
    printf("\nClosing your account...\n");
    do{
        printf("Please enter account start date (MM):");
        scanf("%d", &dateArray[0]);
    } while(dateArray[0]<1 || dateArray[0]>12);
    do{
        printf("Please enter account start date (DD):");
        scanf("%d", &dateArray[1]);
    } while(dateArray[1]<1 || dateArray[1]>31);
    do{
        printf("Please enter account start date (YYYY):");
        scanf("%d", &dateArray[2]);
    } while(dateArray[2]<0 || dateArray[2]>9999);

    createFileFooter(dateArray, finalBalance);

}