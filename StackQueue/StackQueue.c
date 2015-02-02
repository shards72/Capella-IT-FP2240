#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int count = 0;

void enque();
void deque();
void average();
void display();

int main()
{
    int response;
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
                enque();
                break;
            case 2:
                deque();
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

/* Push data into stack */
void enque()
{
    int add_item;
    if (rear == MAX - 1)
    {
        printf("Queue overflow, we cannot take more than 50 grades!\n");
        system("pause");
    }
    else
    {
        if (front == - 1)
        front = 0;
        printf("Please enter the grade you'd like to add: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
        count++;
        system("pause");
    }
}

/* Pop operation on stack */
void deque()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue underflow. You need to enter at least 1 grade!\n");
        return ;
        system("pause");
    }
    else
    {
        printf("Grade deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
        count--;
        system("pause");
    }
}

/* Display stack elements */
void display()
{
    int i;
    if (front == - 1 || front >= rear)
    {
        printf("No grades entered.  Queue is empty.\n");
        system("pause");
    }
    else
    {
        printf("Grades currently include: \n");
        for (i = front; i <= rear; i++)
            printf("%d\n", queue_array[i]);
        printf("\n");
        system("pause");
    }
 }

void average()
{
    int i, sum, avg;
    sum = 0;
    if (front == -1)
    {
        printf("No grades currently entered.  Please enter data!\n");
        system("pause");
    }
    else
    {
        for (i=0; i<count; i++)
            {
                sum = sum + queue_array[i];
            }
        avg = sum / count;
        printf("Current number of grades is: %d\n", count);
        printf("current total of those grades is %d\n", sum);
        printf("Current average mark therefore is: %d.\n", avg);
        system("pause");
    }
}
