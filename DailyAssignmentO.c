#include <stdio.h>
#include <math.h>


//Reid Schneyer
//Daily Assignment O
//10-17-18
//Law of cosines calculator

int main(void){
    int side_a;
    int side_b;
    double side_c;
    int angle_in_degrees;
    double angle_in_rads;

    printf("ENTER INTEGERS ONLY!\n");
    printf("Enter the length of side A: ");
    scanf("%d", &side_a);
    printf("\nEnter the length of side B: ");
    scanf("%d", &side_b);
    printf("\nEnter the angle between the two sides (degrees): ");
    scanf("%d", &angle_in_degrees);

    angle_in_rads = angle_in_degrees *(M_PI / 180.0);

    side_c = sqrt( (pow(side_a, 2.0) + pow(side_b, 2.0)) - ((2*side_a*side_b)*cos(angle_in_rads)) );

    printf("\nThe length of side C is: %f", side_c );

    return 0;
}
