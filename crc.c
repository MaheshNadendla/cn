#include <stdio.h>
#include <string.h>

int main()
{
    char div[100];
    char divsr[5];

    

    int n,m;

    printf("Enter the length of dividend : ");
    scanf("%d",&n);

    printf("\n");

    printf("Enter the dividend : ");
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%c",&div[i]);
    }

    printf("\n");





    printf("Enter the length of divisor : \n");
    scanf("%d",&m);
   
    printf("Enter the divisor : ");
    getchar();
    for(int i=0;i<m;i++)
    {
        scanf("%c",&divsr[i]);
    }

    printf("\n");

   





    
    printf("dividened is : ");
    for(int i=0;i<n;i++)
    {
        printf("%c",div[i]);
    }

    printf("\n");

    printf("divisor is : ");
    for(int i=0;i<m;i++){

        printf("%c",divsr[i]);
    }

    printf("\n");



    printf("dividened is : ");

    for(int i=0;i<n;i++)
    {
        printf("%c",div[i]);
    }

    printf("\n");



    char rem[m+n-1];

    for(int i=0;i<n;i++){

        rem[i]=div[i];
    }

    
    for(int i=n;i<m+n-1;i++) {
        rem[i]='0';
    }



    for (int i = 0; i < n; i++) {
        if (rem[i] == '1') {
            for (int j = 0; j < m; j++) {
                rem[j + i] = (rem[i + j] == divsr[j]) ? '0' : '1';
            }
        }
    }


    printf("dividened is : ");
    for(int i=0;i<n+m;i++)
    {
        printf("%c",rem[i]);
    }

    printf("\n");

    char rems[m-1];

    for(int i=n;i<m+n-1;i++){

        rems[i-n]=rem[i];
    }

      printf("reminder is : ");
    for(int i=0;i<m-1;i++){

        printf("%c",rems[i]);
    }

    printf("\n");




    printf("divisor is : ");
    for(int i=0;i<m;i++){

        printf("%c",divsr[i]);
    }

    printf("\n");


    for(int i=0;i<n;i++){

        rem[i]=div[i];
    }

    printf("passed data is : ");
    for(int i=0;i<n+m-1;i++){

        printf("%c",rem[i]);
    }

    printf("\n");


      for (int i = 0; i < n; i++) {
        if (rem[i] == '1') {
            for (int j = 0; j < m; j++) {
                rem[j + i] = (rem[i + j] == divsr[j]) ? '0' : '1';
            }
        }
    }


    
    printf("passed data is : ");
    for(int i=0;i<n+m-1;i++){

        printf("%c",rem[i]);
    }

    printf("\n");



    
    







}