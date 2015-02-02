#include <stdio.h>
#include <stdlib.h>

struct node
{
    int grade;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int frontelement();
int count = 0;

void enqueue(int data);
void dequeue();
void display();
void average();


int main()
{
    int grade, response;
    do {
        system("cls");
        printf("\nPlease make a selection from the menu below\n\n");
        printf("\t1. Add a grade\n");
        printf("\t2. Remove the first grade\n");
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
                enqueue(grade);
                system("pause");
                break;
            case 2:
                dequeue();
                break;
            case 3:
                average();
                break;
            case 4:
                display();
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

/* Enqueing the queue */
void enqueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->grade = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->grade = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

/* Dequeing the queue */
void dequeue()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("Sorry there are no grades currently recorded!\n");
        system("pause");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("Successfully removed %d from the grade list.\n", front->grade);
            free(front);
            front = front1;
            system("pause");
        }
        else
        {
            printf("Successfully removed the only grade from the list: %d\n", front->grade);
            free(front);
            front = NULL;
            rear = NULL;
            system("pause");
        }
        count--;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("List of grades is empty!\n");
        system("pause");
        return;
    }
    printf("Here are the current list of grades: \n");
    while (front1 != rear)
    {
        printf("%d\n", front1->grade);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d\n", front1->grade);
        system("pause");
}

void average()
{
    front1 = front;
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("No grades currently recorded!\n");
        system("pause");
    }
    else
        {
            int sum, avg;
            sum = 0;
            while(front1)
            {
                sum += front1->grade;
                front1 = front1->ptr;
            }
            avg = sum / count;
            printf("The total count of grades is: %d\n", count);
            printf("The total sum of the grades is: %d\n", sum);
            printf("Total average is %d\n", avg);
            system("pause");
        }
}
