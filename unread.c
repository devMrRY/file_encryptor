#include"stdio.h"
#include"conio.h"

FILE *ptr,*p;
int i=0,choice;
char ch[5000];
void encrypt();
void decrypt();
int main()
{
    int j=0,c=0;
    char pass[5],password[5];
    p=fopen("pass.txt","r");    //path of password file
    if(p==NULL)
    {
        printf("connection not established");
        exit(1);
    }   //end of if block
    else
    {
        while(!feof(p))
        {
            pass[j++]=fgetc(p);
        }   //end of while loop
        printf("enter a 4 digit password : ");
        gets(password);
        for(j=0;j<=3;j++)
        {
            c=c+(password[j]-pass[j]);
            printf("%d",password[j]-pass[j]);
        }   //end of for loop
    }       //end of else block
    if(c)
        printf("wrong password");
    else{
    fclose(p);
    ptr=fopen("shummy.txt","r+");   //path for .txt file you want to encrypt of decrypt
    if(ptr==NULL)
     {
         printf("connection not established");
         exit(1);
     }  //end of if block
    else
    {
        while(!feof(ptr))
        {
            ch[i++]=fgetc(ptr);
        }
    }   //end of else block
    printf("\n1: Encryption\n2: Decryption\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: encrypt();
                break;

        case 2: decrypt();
                break;

        default: printf("invalid choice");
    }   //end of switch block

    fclose(ptr);
    }   //end of else block
 }
void encrypt(){
    fclose(ptr);
    fopen("shummy.txt","w");
    for(i=0;ch[i]!="\0";i++)
    {
        ch[i]=ch[i]+45;
        putc(ch[i],ptr);
    }   //end of for loop
}

void decrypt(){
    fclose(ptr);
    fopen("shummy.txt","w");
    for(i=0;ch[i]!="\0";i++)
    {
        ch[i]=ch[i]-45;
        putc(ch[i],ptr);
    }   //end of for loop
}
