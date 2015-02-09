#include <stdio.h> //Input & Output library
#include <stdlib.h> // General functions
#include <errno.h> // System Call error handling
#include <math.h> // Used for pow() operations
#include <string.h> // Character manipulation


extern int errno; // Used to return error values.

int main( void )
{
    float M;
    float P = 0;
    float ai = 0;
    float mi = 0;
    int years = 0;
    int months = 0;

    while (floor(P) < 1) // Check size of P
    {
        printf("Please enter the principal borrowed: ");
        scanf("%f", &P);
        fseek(stdin,0,SEEK_END); // Clears buffer
    }

    while (floor(ai) < 1)
    {
        printf("Please enter the annualized interest rate: ");
        scanf("%f", &ai);
        fseek(stdin,0,SEEK_END);
    }
    ai = ai/100; // converts to percentage
    mi = ai/12; // Defines monthly interest

    while (floor(years) < 1)
    {
        printf("Please enter the term in years: ");
        scanf("%d", &years);
        fseek(stdin,0,SEEK_END);
    }
    months = years * 12; // Converts years to months.

    if (mi <= 0 || ai <= 0 || P <= 0 || months <= 0)  // Makes sure none of the values are zeroed out.
        {
            fprintf(stderr, "You did not enter valid values! Exiting...\n"); // Normal as errno of 0 is returned (No Error)
            if (errno != 0)
            {
                fprintf(stderr, "Your entry gave error number: %d!\n", errno); // To show how you'd highlight the error number
                perror("Invalid Value"); // To show how you'd use perror to return the value
                fprintf(stderr, "You entered an invalid value: %s\n", strerror(errno)); //To show how'd you reference the pointer to get the value
            }
            exit(EXIT_FAILURE);
        }

    printf("Principal borrowed equals %.2f\n", P); // Verifies the Principal
    printf("Annual Interest equals %.2f%%\n", 100*ai); // Verifies the Annualized Interest
    printf("Monthly Interest equals %.2f%%\n", 100*mi); // Verifies the Monthly Interest
    printf("Total Years borrowed %d\n", years); // Verifies the term in years.
    printf("Total Months borrowed %d\n\n", months); // Verifies the term in months.
    printf("Monthly = (Principal * (Interest(1+Interest)^Months))/((1+Interest)^Months)-1\n");  // Shows user calculation method.
    printf("M = (%f * (%f(1+%f)^%d))/((1+%f)^%d)-1\n", P, mi, mi, months, mi, months); // Shows user exact calculation

    M = (P * (mi*(pow((1 + mi), months))) / (pow((1 + mi), months) - 1)); // Calculates the monthly payment.
    printf("Therefore your monthly payment will be: %.2f", M);  // Shows the user the monthly payment amount.

    exit(EXIT_SUCCESS); /* indicate success.*/
}
