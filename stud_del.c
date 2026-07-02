#include "student.h"

void delete_by_roll(int roll)
{
    struct student *temp = head;
    struct student *prev = NULL;

    while(temp)
    {
        if(temp->roll == roll)
        {
            if(prev)
                prev->next = temp->next;
            else
                head = temp->next;

            free(temp);
            printf("Record Deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Roll No Not Found.\n");
}

void delete_by_name(char *name)
{
    struct student *temp = head;
    int found = 0;

    printf("\nMatching Records:\n");
    while(temp)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("Roll: %d  Name: %s  Percentage: %.2f\n",
                   temp->roll, temp->name, temp->percent);
            found = 1;
        }
        temp = temp->next;
    }

    if(found == 0)
    {
        printf("No matching name found.\n");
        return;
    }

    int r;
    printf("Enter Roll No to delete: ");
    scanf("%d", &r);
    delete_by_roll(r);
}

void stud_del()
{
    char ch;

    if(head == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n=======================================\n");
    printf("| R/r : Delete using Roll Number      |\n");
    printf("| N/n : Delete using Name             |\n");
    printf("=======================================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if(ch == 'R' || ch == 'r')
    {
        int r;
        printf("Enter Roll No: ");
        scanf("%d", &r);
        delete_by_roll(r);
    }
    else if(ch == 'N' || ch == 'n')
    {
        char name[50];
        printf("Enter Name: ");
        scanf(" %[^\n]", name);
        delete_by_name(name);
    }
    else
        printf("Invalid Choice!\n");
}
