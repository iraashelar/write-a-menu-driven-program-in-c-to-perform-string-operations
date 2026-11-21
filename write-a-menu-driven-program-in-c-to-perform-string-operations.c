#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

// Read a line safely and remove the trailing newline
void read_string(char *str, const char *prompt) {
    printf("%s", prompt);
    fgets(str, SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    int choice;
    char s1[SIZE], s2[SIZE], temp[SIZE * 2];

    do {
        printf("\n========== STRING OPERATIONS MENU ==========\n");
        printf("1. Find length of a string\n");
        printf("2. Copy a string\n");
        printf("3. Concatenate two strings\n");
        printf("4. Compare two strings\n");
        printf("5. Reverse a string\n");
        printf("6. Check palindrome\n");
        printf("7. Count vowels and consonants\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');   // clear bad input
            choice = -1;
            continue;
        }
        getchar();   // remove the leftover newline

        switch (choice) {
            case 1:
                read_string(s1, "Enter a string: ");
                printf("Length = %d\n", (int)strlen(s1));
                break;

            case 2:
                read_string(s1, "Enter a string to copy: ");
                strcpy(s2, s1);
                printf("Copied string = %s\n", s2);
                break;

            case 3:
                read_string(s1, "Enter first string: ");
                read_string(s2, "Enter second string: ");
                strcpy(temp, s1);
                strcat(temp, s2);
                printf("Concatenated string = %s\n", temp);
                break;

            case 4: {
                read_string(s1, "Enter first string: ");
                read_string(s2, "Enter second string: ");
                int r = strcmp(s1, s2);
                if (r == 0)
                    printf("The strings are equal.\n");
                else if (r < 0)
                    printf("\"%s\" comes before \"%s\".\n", s1, s2);
                else
                    printf("\"%s\" comes after \"%s\".\n", s1, s2);
                break;
            }

            case 5: {
                read_string(s1, "Enter a string: ");
                int len = strlen(s1);
                for (int i = 0; i < len; i++)
                    temp[i] = s1[len - 1 - i];
                temp[len] = '\0';
                printf("Reversed string = %s\n", temp);
                break;
            }

            case 6: {
                read_string(s1, "Enter a string: ");
                int len = strlen(s1), is_pal = 1;
                for (int i = 0, j = len - 1; i < j; i++, j--) {
                    if (tolower((unsigned char)s1[i]) != tolower((unsigned char)s1[j])) {
                        is_pal = 0;
                        break;
                    }
                }
                if (is_pal)
                    printf("\"%s\" is a palindrome.\n", s1);
                else
                    printf("\"%s\" is not a palindrome.\n", s1);
                break;
            }

            case 7: {
                read_string(s1, "Enter a string: ");
                int vowels = 0, consonants = 0;
                for (int i = 0; s1[i] != '\0'; i++) {
                    char c = tolower((unsigned char)s1[i]);
                    if (isalpha((unsigned char)c)) {
                        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                            vowels++;
                        else
                            consonants++;
                    }
                }
                printf("Vowels = %d, Consonants = %d\n", vowels, consonants);
                break;
            }

            case 8:
                read_string(s1, "Enter a string: ");
                for (int i = 0; s1[i] != '\0'; i++)
                    s1[i] = toupper((unsigned char)s1[i]);
                printf("Uppercase = %s\n", s1);
                break;

            case 9:
                read_string(s1, "Enter a string: ");
                for (int i = 0; s1[i] != '\0'; i++)
                    s1[i] = tolower((unsigned char)s1[i]);
                printf("Lowercase = %s\n", s1);
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
