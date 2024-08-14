#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100] = "My name is Sarvesh Naik";
    char str2[100] = "I study at VU.";
    char str3[100];
    int length, i, j;

    printf("Inbuilt String Operations\n");

    // Convert to uppercase using inbuilt function
    strcpy(str3, str1);  // Copy original string to another string
    for(i = 0; str3[i] != '\0'; i++) {
        str3[i] = toupper(str3[i]);
    }
    printf("Uppercase: %s\n", str3);

    // Convert to lowercase using inbuilt function
    strcpy(str3, str1);  // Reset to original string
    for(i = 0; str3[i] != '\0'; i++) {
        str3[i] = tolower(str3[i]);
    }
    printf("Lowercase: %s\n", str3);

    // Find length using inbuilt function
    length = strlen(str1);
    printf("Length: %d\n", length);

    // Reverse string using inbuilt function
    strcpy(str3, str1);  // Reset to original string
    strrev(str3);
    printf("Reversed: %s\n", str3);

    // Concatenate using inbuilt function
    strcat(str1, " World");
    printf("Concatenation: %s\n", str1);

    printf("******************************\n");
    printf("Manually Designed String Operations\n");

    // Convert to uppercase without inbuilt function
    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str2[i] = str1[i] - 32;
        } else {
            str2[i] = str1[i];
        }
    }
    str2[i] = '\0';  // Null-terminate the string
    printf("Uppercase: %s\n", str2);

    // Convert to lowercase without inbuilt function
    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'A' && str1[i] <= 'Z') {
            str2[i] = str1[i] + 32;
        } else {
            str2[i] = str1[i];
        }
    }
    str2[i] = '\0';
    printf("Lowercase: %s\n", str2);

    // Find length without inbuilt function
    length = 0;
    while(str1[length] != '\0') {
        length++;
    }
    printf("Length: %d\n", length);

    // Reverse string without inbuilt function
    for(i = length - 1, j = 0; i >= 0; i--, j++) {
        str2[j] = str1[i];
    }
    str2[j] = '\0';
    printf("Reversed: %s\n", str2);

    // Concatenate without inbuilt function
    char str4[] = " World";
    for(i = 0; str1[i] != '\0'; i++);  // Move to end of str1
    for(j = 0; str4[j] != '\0'; j++, i++) {
        str1[i] = str4[j];
    }
    str1[i] = '\0';
    printf("Concatenation: %s\n", str1);

    return 0;
}
