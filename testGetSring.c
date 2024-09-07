#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter your name: ");
    scanf("%[^\n]", name);  // Read the full name until newline is encountered

    printf("Name: %d\n", strlen(name));



    return 0;
}

