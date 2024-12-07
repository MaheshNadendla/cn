#include <stdio.h>
#include <stdlib.h>

void charStuff(void);

int main()
{
    int choice;
    while (1)
    {
        printf("\n");
        printf("\n       <------- Enter Below Choice -------> \n");
        printf(".....................................................\n");
        printf(".                                                   .\n");
        printf(".   1. Character stuffing     :           -> 1      .\n");
        printf(".   2. Exit                   :           -> 2      .\n");
        printf(".....................................................\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        if (choice == 1){
            charStuff();
        }
        else if(choice == 2){
            break;
        }
        else{
            printf("\n\nInvalid option... please re-enter.\n");
        }
        
    }
    return 0;
}

void charStuff(void)
{
    char c[50], d[100], t[50]; // Increased `d` size for safety
    int i, m, j;

    printf("Enter the number of characters (max 50) : ");
    scanf("%d", &m);

    if (m <= 0 || m > 50)
    {
        printf("\nInvalid number of characters. Please try again.\n");
        return;
    }

    printf("Enter the characters : ");
    getchar(); // To consume leftover newline character
    for (i = 0; i < m; i++)
    {
        scanf("%c", &c[i]);
    }

    printf("\nOriginal data : ");
    for (i = 0; i < m; i++)
        printf("%c", c[i]);

    // Start stuffing
    d[0] = 'd';
    d[1] = 'l';
    d[2] = 'e';
    d[3] = 's';
    d[4] = 't';
    d[5] = 'x';

    for (i = 0, j = 6; i < m; i++, j++)
    {
        if (c[i] == 'd' && c[i + 1] == 'l' && c[i + 2] == 'e')
        {
            d[j++] = 'd';
            d[j++] = 'l';
            d[j++] = 'e';
        }
        d[j] = c[i];
    }

    d[j++] = 'd';
    d[j++] = 'l';
    d[j++] = 'e';
    d[j++] = 's';
    d[j++] = 't';
    d[j++] = 'x';

    printf("\nTransmitted data : ");
    for (i = 0; i < j; i++)
        printf("%c", d[i]);

    // Start unstuffing
    int receivedLength = j;
    for (i = 6, j = 0; i < receivedLength - 6; i++, j++)
    {
        if (d[i] == 'd' && d[i + 1] == 'l' && d[i + 2] == 'e' &&
            d[i + 3] == 'd' && d[i + 4] == 'l' && d[i + 5] == 'e')
        {
            i += 3; // Skip the stuffed part
        }
        t[j] = d[i];
    }

    printf("\nReceived data : ");
    for (i = 0; i < j; i++)
        printf("%c", t[i]);

    printf("\n");
}
