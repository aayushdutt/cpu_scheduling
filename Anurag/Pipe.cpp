#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char input_string[100];
    scanf("%s", input_string);
    char fixed_str[] = "forgeeks.org";
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid_t p = fork();

    if (p > 0)
    {
        char concat[100];
        close(fd1[0]);
        write(fd1[1], input_string, strlen(input_string) + 1);
        close(fd1[1]);
        wait(NULL);
        close(fd2[1]);
        read(fd2[0], concat, 100);
        printf("%s", concat);
        close(fd2[0]);
    }
    else
    {
        char temp[100];
        close(fd1[1]);
        read(fd1[0], temp, 100);
        close(fd1[0]);
        int k = strlen(temp);
        for (int i = 0; i < strlen(fixed_str); ++i)
        {
            temp[k++] = fixed_str[i];
        }
        temp[k] = '\0';
        close(fd2[0]);
        write(fd2[1], temp, strlen(temp) + 1);
        close(fd2[1]);
    }
}