#include <stdio.h>
#include <string.h>

int main() {
    char s[100], cs[200];
    int i, j, count = 0, n;

    // Input string
    printf("\nENTER THE STRING: ");
    fgets(s, sizeof(s), stdin);
    n = strlen(s);

    // Remove the newline character if present
    if (s[n - 1] == '\n') {
        s[n - 1] = '\0';
        n--;
    }

    printf("\nOriginal String: %s\n", s);

    // Step 2: Append DLE STX at the beginning
    strcpy(cs, "DLESTX");
    strcat(cs, s);

    // Step 3: Handle 'DLE' insertion for existing DLEs in the string
    for (i = 0, j = strlen(cs); i < n; i++) {
        if (s[i] == 'D' && s[i + 1] == 'L' && s[i + 2] == 'E') {
            cs[j++] = 'D';
            cs[j++] = 'L';
            cs[j++] = 'E';
            cs[j++] = 'D';
            cs[j++] = 'L';
            cs[j++] = 'E';
            i += 2; // Skip the next 'L' and 'E'
        } else {
            cs[j++] = s[i];
        }
    }

    // Step 4: Append DLE ETX at the end
    strcat(cs, "DLEETX");

    printf("\nTransmitted String: %s\n", cs);

    // Step 5: Display string
    printf("\nModified String with Character Count:\n");
    for (i = 0; i < strlen(cs); i++) {
        printf("%c", cs[i]);
    }

    return 0;
}
