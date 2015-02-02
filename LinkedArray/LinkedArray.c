#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *top, *top1, *temp;

void push(int data);
void pop();
void average();
void display();
int count = 0;

int main()
{
    int grade, response;
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

        switch (response)
        {
            case 1:
                printf("Please enter a grade: ");
                scanf("%d", &grade);
                push(grade);
                break;
            case 2:
                pop();
                break;
            case 3:
                average();
                system("pause");
                break;
            case 4:
                display();
                system("pause");
                break;
            case 5:
                break;
            default :
                printf("Not a valid menu options. Please try again.\n");
                system("pause");
                break;
        }
        } while (response != 5);
        return 0;
}

/* Push data into stack */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
        printf("Successfully added the first grade of: %d\n", data);
        system("pause");
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
        printf("Successfully added another grade of: %d\n", data);
        system("pause");
    }
    count++;
}

/* Display stack elements */
void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Sorry!  No grades have yet been recorded!\n");
        return;
    }

    printf("Here are the current list of grades:\n");

    while (top1 != NULL)
    {
        printf("%d\n", top1->info);
        top1 = top1->ptr;
    }
 }

/* Pop Operation on stack */
void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Sorry, no grades have yet been recorded!\n");
        return;
    }
    else
    {
        top1 = top1->ptr;
        printf("Removed grade: %d\n", top->info);
        free(top);
        top = top1;
        count--;
        system("pause");
    }
}

void average()
{
    top1 = top;
    if (top1 == NULL)
        printf("No grades currently recorded!\n");
    else
        {
            int sum, avg;
            sum = 0;
            while(top1)
            {
                sum += top1->info;
                top1 = top1->ptr;
            }
            avg = sum / count;
            printf("Total average is %d\n", avg);
        }
}
