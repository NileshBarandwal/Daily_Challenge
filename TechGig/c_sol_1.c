/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{
	    // Variable to store input
    char input[10000];
    char c;
    int i = 0;
    
    // Read input from stdin character by character until newline
    while ((c = getchar()) != '\n' && c != EOF && i < sizeof(input) - 1) {
        input[i++] = c;
    }
    input[i] = '\0'; // Null-terminate the string
    
    // Print 'Hello Techgig'
    printf("Hello Techgig\n");
    
    // Print the content of the variable
    printf("%s\n", input);
}
