#include "student.h"

void stud_save()
{
    struct student *temp = head;
    FILE *fp = fopen("student.txt", "w");

    if(!fp)
    {
        printf("File Not Found!\n");
        return;
    }

    while(temp)
    {
        fprintf(fp, "%d %s %.2f\n", temp->roll, temp->name, temp->percent);
        temp = temp->next;
    }

    fclose(fp);
    printf("Data Saved to student.txt\n");
}

void stud_load()
{
    FILE *fp = fopen("student.txt", "r");

    if(!fp)
        return;   // file doesn't exist yet — first run

    struct student *temp, *last = NULL;
    int roll;
    char name[50];
    float percent;

    while(fscanf(fp, "%d %s %f", &roll, name, &percent) == 3)
    {
        temp = (struct student *)malloc(sizeof(struct student));
        temp->roll = roll;
        strcpy(temp->name, name);
        temp->percent = percent;
        temp->next = NULL;

        if(head == NULL)
            head = temp;
        else
            last->next = temp;

        last = temp;
    }

    fclose(fp);
}
