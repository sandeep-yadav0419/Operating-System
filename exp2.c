
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, dest, n;
    char buffer[1024];

    source = open("requirement.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Cannot open source file\n");
        return 1;
    }

    dest = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0)
    {
        printf("Cannot open destination file\n");
        close(source);
        return 1;
    }

    while ((n = read(source, buffer, sizeof(buffer))) > 0)
    {
        if (write(dest, buffer, n) != n)
        {
            printf("Error writing file\n");
            close(source);
            close(dest);
            return 1;
        }
    }

    if (n < 0)
        printf("Error reading file\n");
    else
        printf("File copied successfully\n");

    close(source);
    close(dest);

    return 0;
}
