#include <stdio.h>
#include <string.h>  // only for strlen, not for reverse

int main() 
{
    char str[100];
    int i, length, vowelCount = 0;
    int isPalindrome = 1;  // flag

    // Input string
    printf("Enter a string: ");
    scanf("%s", str);   // reads until space (use fgets for full sentences)

    // Find length
    length = strlen(str);

    // Reverse manually (without library reverse)
    printf("Reversed string: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    // Count vowels
    for (i = 0; i < length; i++) {
        char ch = str[i];
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') {
            vowelCount++;
        }
    }
    printf("Number of vowels: %d\n", vowelCount);

    // Check palindrome
    for (i = 0; i < length/2; i++) {
        if (str[i] != str[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("The string is a Palindrome\n");
    else
        printf("The string is NOT a Palindrome\n");

    return 0;
}
                                 
                                 