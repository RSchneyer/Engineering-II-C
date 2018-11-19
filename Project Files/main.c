#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

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


int main(void){
    //Delete old log file
    //Might not be the best way to do this: https://stackoverflow.com/questions/19913446/why-should-the-system-function-be-avoided-in-c-and-c
    int status = system("rm xactlog.txt");
    // int status = 0;
    if(status == 0){//If the file got deleted succesfully
        int actionSelection = 1;
        // This part is a bit confusing, I wanted one function for setting up an account
        // C functions can't straight up return arrays, so initAccount() takes an array pointer as an argument
        // Basically, I wanted to return two values from one function, and this is my solution
        double balance, apr;
        double balanceAndAprArray[2] = {0};
        initAccount(balanceAndAprArray);
        // Too bad C doesn't have array destructuring :/
        balance = balanceAndAprArray[0];
        apr = balanceAndAprArray[1];

        logAccountEvent(balance, 0);

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
                    balance += changeBalance(1, balance);
                    // printf("Function not available right now\n");
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


