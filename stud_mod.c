#include "student.h"

struct student* find_by_roll(int roll)
{
    struct student *temp = head;
    while(temp)
    {
        if(temp->roll == roll)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void stud_mod()
{
    char ch;
    int roll;
    char name[50];

    struct student *rec = NULL;

    if(head == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n================ MODIFY RECORD ================\n");
    printf("| R/r : Search by Roll No                      |\n");
    printf("| N/n : Search by Name                         |\n");
    printf("| P/p : Search by Percentage                   |\n");
    printf("================================================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    // Search by Roll Number
    if(ch == 'R' || ch == 'r')
    {
        printf("Enter Roll No: ");
        scanf("%d", &roll);

        rec = find_by_roll(roll);

        if(!rec)
        {
            printf("\nRecord Not Found!\n");
            return;
        }
    }
    // Search by Name
    else if(ch == 'N' || ch == 'n')
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        printf("\n================ MATCHING RECORDS ================\n");
        printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
        printf("--------------------------------------------------\n");

        struct student *temp = head;
        int found = 0;

        while(temp)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("| %-8d | %-20s | %10.2f |\n",
                       temp->roll, temp->name, temp->percent);
                found = 1;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("           NO RECORDS FOUND\n");
            printf("--------------------------------------------------\n");
            return;
        }

        printf("--------------------------------------------------\n");
        printf("Enter Roll No to Modify: ");
        scanf("%d", &roll);
        rec = find_by_roll(roll);
    }
    // Search by Percentage
    else if(ch == 'P' || ch == 'p')
    {
        float percent;
        printf("Enter Percentage: ");
        scanf("%f", &percent);

        printf("\n================ MATCHING RECORDS ================\n");
        printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
        printf("--------------------------------------------------\n");

        struct student *temp = head;
        int found = 0;

        while(temp)
        {
            if(temp->percent == percent)
            {
                printf("| %-8d | %-20s | %10.2f |\n",
                       temp->roll, temp->name, temp->percent);
                found = 1;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("           NO RECORDS FOUND\n");
            printf("--------------------------------------------------\n");
            return;
        }

        printf("--------------------------------------------------\n");
        printf("Enter Roll No to Modify: ");
        scanf("%d", &roll);
        rec = find_by_roll(roll);
    }
    else
    {
        printf("Invalid Choice!\n");
        return;
    }

    if(!rec)
    {
        printf("\nInvalid Roll No.\n");
        return;
    }

    printf("\n================ MODIFY OPTIONS =================\n");
    printf("| N/n : Modify Name                             |\n");
    printf("| P/p : Modify Percentage                       |\n");
    printf("=================================================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if(ch == 'N' || ch == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %[^\n]", rec->name);
    }
    else if(ch == 'P' || ch == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &rec->percent);
    }
    else
    {
        printf("Invalid Choice!\n");
        return;
    }

    printf("\nRecord Modified Successfully!\n");
}
