#include "student.h"

// Copy linked list node addresses into an array
int list_to_array(struct student *arr[])
{
    struct student *temp = head;
    int n = 0;

    while(temp)
    {
        arr[n++] = temp;
        temp = temp->next;
    }
    return n;
}

void sort_by_name()
{
    struct student *arr[100];
    int n = list_to_array(arr);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(arr[i]->name, arr[j]->name) > 0)
            {
                struct student *t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    printf("\n============ SORTED BY NAME (A - Z) ============\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    printf("================================================\n");

    for(int i = 0; i < n; i++)
        printf("| %-8d | %-20s | %10.2f |\n",
               arr[i]->roll, arr[i]->name, arr[i]->percent);

    printf("================================================\n");
}

void sort_by_percentage()
{
    struct student *arr[100];
    int n = list_to_array(arr);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i]->percent < arr[j]->percent)
            {
                struct student *t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    printf("\n======= SORTED BY PERCENTAGE (High - Low) ======\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    printf("--------------------------------------------------\n");

    for(int i = 0; i < n; i++)
        printf("| %-8d | %-20s | %10.2f |\n",
               arr[i]->roll, arr[i]->name, arr[i]->percent);

    printf("==================================================\n");
}

void stud_sort()
{
    char ch;

    if(head == NULL)
    {
        printf("\nList Empty!\n");
        return;
    }

    printf("\nN/n : Sort By Name\n");
    printf("P/p : Sort By Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if(ch == 'N' || ch == 'n')
        sort_by_name();
    else if(ch == 'P' || ch == 'p')
        sort_by_percentage();
    else
        printf("Invalid Sort Option!\n");
}
