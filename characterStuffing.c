#include <stdio.h>
#include <stdlib.h>

void charStuff(void);
void bitStuff(void);

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
        printf(".   2. Bit stuffing           :           -> 2      .\n");
        printf(".   3. Exit                   :           -> 3      .\n");
        printf(".....................................................\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            charStuff();
        }
        else if (choice == 2)
        {
            bitStuff();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("\n\nInvalid option... please re-enter.\n");
        }
    }
    return 0;
}

void charStuff(void)
{
    char c[50], d[100], t[50];
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

void bitStuff(void)
{
    int data[50], stuffed[100], unstuffed[50];
    int n, i, j = 0, k, count = 0;

    printf("Enter the number of bits (max 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50)
    {
        printf("\nInvalid number of bits. Please try again.\n");
        return;
    }

    printf("Enter the bits (0 or 1): ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        if (data[i] != 0 && data[i] != 1)
        {
            printf("\nInvalid bit. Only 0 and 1 are allowed.\n");
            return;
        }
    }

    printf("\nOriginal data: ");
    for (i = 0; i < n; i++)
        printf("%d", data[i]);

    // Bit stuffing
    for (i = 0; i < n; i++)
    {
        if (data[i] == 1)
        {
            count++;
            if (count == 5)
            {
                stuffed[j++] = data[i];
                stuffed[j++] = 0; // Insert a 0 after 5 consecutive 1s
                count = 0;
            }
            else
            {
                stuffed[j++] = data[i];
            }
        }
        else
        {
            stuffed[j++] = data[i];
            count = 0;
        }
    }

    printf("\nStuffed data: ");
    for (i = 0; i < j; i++)
        printf("%d", stuffed[i]);

    // Bit unstuffing
    for (i = 0, k = 0, count = 0; i < j; i++)
    {
        if (stuffed[i] == 1)
        {
            count++;
            unstuffed[k++] = stuffed[i];
            if (count == 5)
            {
                i++; // Skip the stuffed 0
                count = 0;
            }
        }
        else
        {
            unstuffed[k++] = stuffed[i];
            count = 0;
        }
    }

    printf("\nUnstuffed data: ");
    for (i = 0; i < k; i++)
        printf("%d", unstuffed[i]);

    printf("\n");
}
