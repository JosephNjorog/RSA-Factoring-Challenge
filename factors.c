#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        printf("where <file> is a file containing natural numbers to factor.\n");
        printf("One number per line\n");
        printf("You can assume that all lines will be valid natural numbers greater than 1\n");
        printf("You can assume that there will be no empy line, and no space before and after the valid number\n");
        printf("The file will always end with a new line\n");
        printf("Output format: n=p*q\n");
        printf("one factorization per line\n");
        printf("p and q don’t have to be prime numbers\n");
        printf("See example\n");
        printf("You can work on the numbers of the file in the order of your choice\n");
        printf("Your program should run without any dependency: You will not be able to install anything on the machine we will run your program on\n");
        printf("Time limit: Your program will be killed after 5 seconds if it hasn’t finish\n");
        printf("Push all your scripts, source code, etc… to your repository\n");
        printf("we will only run your executable factors\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        int num = atoi(line);
        printf("%d=", num);
        for (int i = 2; i <= num / i; i++) {
            while (num % i == 0) {
                printf("%d*", i);
                num /= i;
            }
        }
        if (num > 1) {
            printf("%d", num);
        } else {
            printf("\b");
        }
        printf("\n");
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    return 0;
}
