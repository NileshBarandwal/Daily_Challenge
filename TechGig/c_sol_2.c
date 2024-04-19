/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{
	// Variable to store input
    char input[10000];
    
    // Read input from stdin and store it
    fgets(input, sizeof(input), stdin);
    
    // Print 'Hello Techgig'
    printf("Hello Techgig\n");
    
    // Print the content of the variable
    printf("%s", input);
    
    return 0;
}
