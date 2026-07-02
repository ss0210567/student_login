#include "student.h"

void stud_show()
{
    struct student *temp = head;

    if(!temp)
    {
        printf("\n---------------------------------------------\n");
        printf("|              NO RECORDS FOUND              |\n");
        printf("---------------------------------------------\n");
        return;
    }

    printf("\n================================================\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    printf("================================================\n");

    while(temp)
    {
        printf("| %-8d | %-20s | %10.2f |\n",
               temp->roll, temp->name, temp->percent);
        temp = temp->next;
    }

    printf("================================================\n");
}
