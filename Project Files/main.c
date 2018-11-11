#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//I'm saving myself from typing 5 letters each time. It adds up, I swear
#define OUTFILE_NAME "xactlog.txt"

// Creates column headers at the beginning of xactlog.txt
void createFileHeader(){
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "w");
    if(outfile == NULL){
        printf("An error occurred writing to the file");
    }
    fprintf(outfile, "Type, Amount, Current Balance,\n");
    fclose(outfile);
}

void logDeposit(double depositAmount, double currentBalance){
    if(depositAmount<0.0){
        return;
    }
    double newBalance = depositAmount + currentBalance;
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "a");
    if(outfile == NULL){
        printf("\nCan't open logfile!\n");
    }
    fprintf(outfile, "deposit,  %.2f,  %.2f,\n", depositAmount, newBalance);
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
        logDeposit(balanceChange, currentBalance);
    } 
    else{
        do{
            printf("Withdraw how much? ");
            scanf("%lf", &balanceChange);
        } while((currentBalance-balanceChange)>0.0);
        balanceChange *= -1;
    }
    return balanceChange;
}

//Contains the 7 or so printf statements for the system menu
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

//Displays the menu from printMenu(), and returns an int between 1 and 5 based on user input
int getMenuSelection(){
    int selection = 0;
    while(selection<1 || selection>5){
        printMenu();
        scanf("%d", &selection);
    }
    return selection;

}

double initAccount(){
    double balance;
    printf("Welcome to Reid's Banking Simulator! Please enter your starting balance: ");
    scanf("%lf", &balance);
    logDeposit(balance, 0);
    return balance;
}







int main(void){
    //Delete old log file
    //Might not be the best way to do this: https://stackoverflow.com/questions/19913446/why-should-the-system-function-be-avoided-in-c-and-c
    int status = system("rm xactlog.txt");
    if(status == 0){//If the file got deleted 
        createFileHeader();

        int actionSelection = 1;
        double balance, APR;

        balance = initAccount();

        while(actionSelection>0 && actionSelection<5){//While the user has chosen a number between 1-4
            actionSelection = getMenuSelection();
            printf("Selected menu action: %d\n", actionSelection);
            double balanceChange;
            switch(actionSelection){
                case 1:
                    //Make a deposit
                    balance += changeBalance(0, balance);
                    break;
                case 2:
                    //Make a withdrawl
                    printf("Function not available right now\n");
                    break;
                case 3:
                    //Calculate interest
                    printf("Function not available right now\n");
                    break;
                case 4:
                    //Apply a fee
                    printf("Function not available right now\n");
                    break;
            }

        }
        //Account closed




    }
    return 0; 
}


