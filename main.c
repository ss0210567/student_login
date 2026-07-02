#include "student.h"

struct student *head = NULL;

int main()
{
    char ch;

    stud_load();   // Load existing records

    while(1)
    {
        printf("\n=============================================\n");
        printf("|           STUDENT RECORD MENU             |\n");
        printf("=============================================\n");
        printf("|  A/a : Add New Record                     |\n");
        printf("|  D/d : Delete A Record                    |\n");
        printf("|  S/s : Show the List                      |\n");
        printf("|  M/m : Modify A Record                    |\n");
        printf("|  V/v : Save Records                       |\n");
        printf("|  T/t : Sort the List                      |\n");
        printf("|  E/e : Exit                                |\n");
        printf("=============================================\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case 'A': case 'a': stud_add();  break;
            case 'D': case 'd': stud_del();  break;
            case 'S': case 's': stud_show(); break;
            case 'M': case 'm': stud_mod();  break;
            case 'V': case 'v': stud_save(); break;
            case 'T': case 't': stud_sort(); break;

            case 'E': case 'e':
                printf("\n=========== EXIT MENU ==============\n");
                printf("|  S/s : Save and Exit              |\n");
                printf("|  E/e : Exit Without Saving        |\n");
                printf("=====================================\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &ch);

                if(ch=='S' || ch=='s')
                    stud_save();

                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
