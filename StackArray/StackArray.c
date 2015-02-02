#include <stdio.h>
#include <stdlib.h>
#define max 5

int value, response, top, status;
float sum, average;

/* Push Function */
void push (int stack[], int grade)
{
    if (top == (max - 1))
    {
        status = 0;
    }
    else
    {
        status = 1;
        ++top;
        stack[top] = grade;
    }
}

/* Pop Function */
int pop (int stack[])
{
    int result;
    if (top == -1)
    {
        result = 0;
        status = 0;
    }
    else
    {
        status = 1;
        result = stack[top];
        --top;
    }
return result;
}

/* Calculate Average */
void calc (int stack[])
{
    int i;
    if (top == -1)
    {
        printf("No grades are present to calculate.\n");
    }
    else
    {
            for(i = top; i >= 0; --i)
            sum += stack[i];
            average = sum/(top + 1);
            printf("Average grade is %.2f\n", average);
            sum = 0;
    }
}

/* Display Stack */
void display (int stack[])
{
    int i;
    printf ("\nThe current grades are: ");
    if (top == -1)
    {
        printf ("empty.\n");
    }
    else
    {
        for (i = top; i >= 0; --i)
        printf ("\n%d", stack[i]);
    }
    printf ("\n");
}


int main()
{
    int stack [max], grade;
    system("cls");
    top = -1;
    do {
        system("cls");
        printf("\nPlease make a selection from the menu below\n\n");
        printf("\t1. Add a grade\n");
        printf("\t2. Remove last grade\n");
        printf("\t3. Display the current grade average\n");
        printf("\t4. Display all grades\n");
        printf("\t5. Quit\n");
        printf("\n\nEnter your selection now: ");
        scanf("%d", &response);

        switch(response)
            {
            case 1:
                printf("\nEnter a new grade: ");
                scanf("%d", &grade);
                push(stack, grade);
                if (status)
                {
                    printf("\nYou added %d to the current grades.\n", grade);
                    if (top == (max - 1))
                        printf("\nThe stack is now full.");
                }
                else
                {
                    printf("\nGrades not recorded due to stack overflow.\n");
                }
                system("pause");
                break;
            case 2:
                grade = pop(stack);
                if (status)
                {
                    printf("\nThe grade %d has been removed.\n", grade);
                }
                system("pause");
                break;
            case 3:
                calc(stack);
                system("pause");
                break;
            case 4:
                display(stack);
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("You did not enter a valid number!\n");
                system("pause");
                break;
            }
        } while (response != 5);
        return 0;
}
