#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void){
    //Delete old log file
    //Might not be the best way to do this: https://stackoverflow.com/questions/19913446/why-should-the-system-function-be-avoided-in-c-and-c
    // int status = system("rm xactlog.txt");
    int status = 0;
    
    if(status == 0){//If the file got deleted succesfully
        int actionSelection;
        double balance, apr;
        //use enum for account action types?

        // This part is a bit confusing, I wanted one function for setting up an account
        // C functions can't straight up return arrays, so initAccount() takes an array pointer as an argument
        // Basically, I wanted to return two values from one function, and this is my solution
        double balanceAndAprArray[2] = {0};
        int startDateArray[3] = {0};
        initAccount(balanceAndAprArray, startDateArray);
        // Too bad C doesn't have array destructuring :/
        balance = balanceAndAprArray[0];
        apr = balanceAndAprArray[1];

        logAccountEvent(0, balance, 0);

        do{
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
                    balance += calculateInterest(balance, apr);
                    break;
                case 4:
                    //Apply a fee
                    balance += changeBalance(3, balance);
                    break;
            }
        } while(actionSelection>0 && actionSelection<5);
        closeAccount(balance, startDateArray);
        //Account closed
    }
    return 0; 
}


