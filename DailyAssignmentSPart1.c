//Reid Schneyer
// 11-2-18
//Daily Assignment S Part 1
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int i;
    FILE * outFile;
    outFile = fopen("fifteen.txt", "w");
    if(outFile == NULL){
        printf("Cannot Open output File!");
    }
    for(i=0;i<16;i++){
        int randNum = (rand() % 102) + 14 ;
        fprintf(outFile, "%d\n", randNum);
    }   

    fclose(outFile);
    return 0;
}