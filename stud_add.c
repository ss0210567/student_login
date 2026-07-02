#include "student.h"

// Find smallest available roll number
int missing_roll()
{
    struct student *temp;
    int roll = 1;

    while(1)
    {
        temp = head;
        int found = 0;

        while(temp)
        {
            if(temp->roll == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
            return roll;

        roll++;
    }
}

void stud_add()
{
    struct student *temp = (struct student *)malloc(sizeof(struct student));

    temp->roll = missing_roll();
    printf("Generated Roll No: %d\n", temp->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp->name);

    printf("Enter Percentage: ");
    scanf("%f", &temp->percent);

    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct student *last = head;
        while(last->next)
            last = last->next;
        last->next = temp;
    }

    printf("Record Added Successfully.\n");
}
