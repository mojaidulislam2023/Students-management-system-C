#include <stdio.h>

struct students
{
    int id;
    char name[50];
    int age;
    float marks;
};

int main()
{
    struct students s[5];

    int choice = 0;
    int count = 0;
    int i, j;
    int searchId, updateId, deleteId;
    int found, top;
    float sum, average;
    FILE *fp;

    /* Load Previous Data */

    fp = fopen("students.txt", "r");

    if (fp != NULL)
    {
        while (count < 5 &&
               fscanf(fp, "%d %49s %d %f",
                      &s[count].id,
                      s[count].name,
                      &s[count].age,
                      &s[count].marks) == 4)
        {
            count++;
        }

        fclose(fp);
        printf("Previous Data Loaded Successfully!\n");
    }
    else
    {
        printf("No Previous Data Found.\n");
    }

    while (choice != 8)
    {
        printf("\n================================\n");
        printf("   STUDENT MANAGEMENT SYSTEM\n");
        printf("================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Calculate Average Marks\n");
        printf("7. Find Topper\n");
        printf("8. Save and Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        /* Add Student */

        if (choice == 1)
        {
            if (count < 5)
            {
                printf("Enter Student ID: ");
                scanf("%d", &s[count].id);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (s[i].id == s[count].id)
                    {
                        found = 1;
                        break;
                    }
                }

                if (found == 1)
                {
                    printf("Student ID Already Exists!\n");
                }
                else
                {
                    printf("Enter Student Name: ");
                    scanf("%49s", s[count].name);

                    printf("Enter Student Age: ");
                    scanf("%d", &s[count].age);

                    printf("Enter Student Marks: ");
                    scanf("%f", &s[count].marks);

                    if (s[count].age <= 0 ||
                        s[count].marks < 0 ||
                        s[count].marks > 100)
                    {
                        printf("Invalid Age or Marks!\n");
                    }
                    else
                    {
                        count++;
                        printf("Student Added Successfully!\n");
                    }
                }
            }
            else
            {
                printf("Student Limit Full!\n");
            }
        }

        /* Display Students */

        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No Student Data Available.\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    printf("\nStudent %d\n", i + 1);
                    printf("ID    = %d\n", s[i].id);
                    printf("NAME  = %s\n", s[i].name);
                    printf("AGE   = %d\n", s[i].age);
                    printf("MARKS = %.2f\n", s[i].marks);
                }
            }
        }

        /* Search Student */

        else if (choice == 3)
        {
            printf("Enter Student ID to Search: ");
            scanf("%d", &searchId);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == searchId)
                {
                    printf("\nStudent Found!\n");
                    printf("ID    = %d\n", s[i].id);
                    printf("NAME  = %s\n", s[i].name);
                    printf("AGE   = %d\n", s[i].age);
                    printf("MARKS = %.2f\n", s[i].marks);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("Student Not Found!\n");
            }
        }

        /* Update Student */

        else if (choice == 4)
        {
            printf("Enter Student ID to Update: ");
            scanf("%d", &updateId);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == updateId)
                {
                    printf("Enter New Name: ");
                    scanf("%49s", s[i].name);

                    printf("Enter New Age: ");
                    scanf("%d", &s[i].age);

                    printf("Enter New Marks: ");
                    scanf("%f", &s[i].marks);

                    if (s[i].age <= 0 ||
                        s[i].marks < 0 ||
                        s[i].marks > 100)
                    {
                        printf("Invalid Age or Marks!\n");
                    }
                    else
                    {
                        printf("Student Updated Successfully!\n");
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("Student Not Found!\n");
            }
        }

        /* Delete Student */

        else if (choice == 5)
        {
            printf("Enter Student ID to Delete: ");
            scanf("%d", &deleteId);

            found = 0;

            for (i = 0; i < count; i++)
            {
                if (s[i].id == deleteId)
                {
                    for (j = i; j < count - 1; j++)
                    {
                        s[j] = s[j + 1];
                    }

                    count--;
                    found = 1;

                    printf("Student Deleted Successfully!\n");
                    break;
                }
            }

            if (found == 0)
            {
                printf("Student Not Found!\n");
            }
        }

        /* Calculate Average */

        else if (choice == 6)
        {
            if (count == 0)
            {
                printf("No Student Data Available.\n");
            }
            else
            {
                sum = 0;

                for (i = 0; i < count; i++)
                {
                    sum = sum + s[i].marks;
                }

                average = sum / count;

                printf("Average Marks = %.2f\n", average);
            }
        }

        /* Find Topper */

        else if (choice == 7)
        {
            if (count == 0)
            {
                printf("No Student Data Available.\n");
            }
            else
            {
                top = 0;

                for (i = 1; i < count; i++)
                {
                    if (s[i].marks > s[top].marks)
                    {
                        top = i;
                    }
                }

                printf("\n===== TOPPER =====\n");
                printf("ID    = %d\n", s[top].id);
                printf("NAME  = %s\n", s[top].name);
                printf("AGE   = %d\n", s[top].age);
                printf("MARKS = %.2f\n", s[top].marks);
            }
        }

        else if (choice == 8)
        {
            printf("Exiting Program...\n");
        }
        else
        {
            printf("Invalid Choice! Try Again.\n");
        }

        /* Save Data After Add, Update or Delete */

        if (choice == 1 || choice == 4 || choice == 5 ||
            choice == 8)
        {
            fp = fopen("students.txt", "w");

            if (fp == NULL)
            {
                printf("File Could Not Be Opened!\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    fprintf(fp, "%d %s %d %.2f\n",
                            s[i].id,
                            s[i].name,
                            s[i].age,
                            s[i].marks);
                }

                fclose(fp);
                printf("Student Data Saved!\n");
            }
        }
    }

    return 0;
}