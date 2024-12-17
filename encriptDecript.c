#include <stdio.h>
#include <string.h>
void encrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
    printf("Encrypted Message: %s\n", message);
}
void decrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
    printf("Decrypted Message: %s\n", message);
}

int main()
{
    char message[100];
    int key;
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}