
#include <stdio.h>
#include <string.h>

int main()
{
    char files[10][30], name[30];
    int n = 0, choice, i, found;

    while (1)
    {
        printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%29s", name);

                found = 0;
                for (i = 0; i < n; i++)
                    if (strcmp(files[i], name) == 0)
                        found = 1;

                if (found)
                    printf("File already exists\n");
                else if (n < 10)
                {
                    strcpy(files[n++], name);
                    printf("File created\n");
                }
                else
                    printf("Directory full\n");
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%29s", name);

                found = 0;
                for (i = 0; i < n; i++)
                    if (strcmp(files[i], name) == 0)
                    {
                        for (int j = i; j < n - 1; j++)
                            strcpy(files[j], files[j + 1]);
                        n--;
                        found = 1;
                        printf("File deleted\n");
                        break;
                    }

                if (!found)
                    printf("File not found\n");
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%29s", name);

                found = 0;
                for (i = 0; i < n; i++)
                    if (strcmp(files[i], name) == 0)
                        found = 1;

                printf(found ? "File found\n" : "File not found\n");
                break;

            case 4:
                printf("Files in directory:\n");
                for (i = 0; i < n; i++)
                    printf("%s\n", files[i]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
