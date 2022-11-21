//Developed By : @Deepkumar Mahajan

//Github:- https://github.com/Deepkumarmahajan




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
COORD coord = {0,0};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void login()
{
    int a=0,i=0;
    char uname[20],c=' ';
    char pword[20],code[10];
    char user[10]="user";
    char pass[10]="pass";
    time_t t;
    time(&t);
    do
    {
        system("Color e");
       printf("\n\n\n\n\t\t\t\t\t"
               "MAHAJAN.LTD");
        printf("\n\t\t\t\t"
               "                 EMPLOYEE RECORD BOOK 2.0\t");
        printf("\n\t\t\t\t                           WE MAKES THINGS EASY FOR YOU.....!");
        printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
               "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
               "~~~");
        printf("\n\t\t\t============================================="
               "==============================\n");
        printf("\n\n\n\t\t\t\t\t\t\t"
               "Developed By : @Deepkumar Mahajan"
               "\n\n \t");
        printf("\t\t\t\t\t\t\t"
               " Github:- http://github.com/Deepkumarmahajan "
               "\n\n \t");
        printf("\n\n\n\t\t\t\t\t\t\t",ctime(&t));
        printf("\n  :::::::::::::::::::::::::::::::::::::::  LOGIN DETAIL :::::::::::::::::::::::::::::::::::::::::::::  ");
        printf("\n");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while(i<20)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';

        i=0;

        if(strcmp(uname,"MAHAJAN")==0 && strcmp(pword,"MAHAJAN")==0)
        {
            system("Color 0");
            printf("  \n\n\n       WELCOME TO EMPLOYEE RECORD MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n LOADING PLEASE WAIT... \n");
            for(i=0; i<3; i++)
            {
                printf(".");
                Sleep(500);
            }
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            system("Color 4");
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch();
            system("cls");

        }
    }
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have Entered the Wrong Username & Password for Four(4) Times!!!");
        getch();
        exit(0);
    }
    system("cls");
}


int main()
{
    int i=1,k=0;
    login();
    FILE *fp, *ft;
    char another, choice;
    struct emp
    {
        char name[100];
        int ID;
        int age;
        int phone_number;
        char address[100];
        float bs;
    };
    struct emp e;

    char empname[100];

    long int recsize;
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    recsize = sizeof(e);


    while(1)
    {

        system("cls");

        system("Color 70");
        printf("\n::::::::::::::::::::::::::::::::::::::::: |MAHAJAN.LTD| :::::::::::::::::::::::::::::::::::::::::::: \n");
        printf("\::::::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT SYSTEM| :::::::::::::::::::::::::::::::::::: \n");
        printf("\n");
        gotoxy(45,05);
        printf("1> Add Employee's Records");
        gotoxy(45,07);
        printf("2> List Employee's Records");
        gotoxy(45,9);
        printf("3> Modify Employee's Records");
        gotoxy(45,11);
        printf("4> Delete Employee's Records");
        gotoxy(45,13);
        printf("5> EXIT System");
        gotoxy(45,15);
        printf("Your Choice: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)
        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name: ");
                scanf("%s",e.name);
                printf("\nEnter EMP-ID: ");
                scanf("%d", &e.ID);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("Enter Phone number: ");
                scanf("%d", &e.phone_number);
                printf("\nEnter Email Address:");
                scanf("%s",e.address);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.bs);

                fwrite(&e,recsize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {
                printf("\n\n                                           < MAHAJAN.LTD >                                     \n");
                printf("\n\n                                          Employee Details                                     \n");
                printf("-------------------------------------------------------------------------------------------------------\n");
                printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
                printf("-------------------------------------------------------------------------------------------------------\n");
                printf("| %-19s",e.name);
                printf("| %-9d",e.ID);
                printf("| %-7d",e.age);
                printf("| 0%-13d",e.phone_number);
                printf("| %-19s",e.address);
                printf("| %-13.3lf|\n",e.bs);
                printf("-------------------------------------------------------------------------------------------------------\n");
            }
            getch();
            break;

        case '3':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
            system("cls");
                printf("\nYou Can't change EMP-ID , Phone Number , Address Its Permanent");
                printf("\nEnter the Employee name to Modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,empname) == 0)
                    {
                        printf("\nEnter new name:");
                        scanf("%s", e.name);
                        printf("\nEnter new age :");
                        scanf("%d", &e.age);
                        printf("\nEnter new salary :");
                        scanf("%f", &e.bs);

                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of Employee to Delete Employee's Records: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,empname) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT");
                rename("Temp.dat","EMP.DAT");
                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);
            exit(0);
        }
    }
    return 0;
}
//Developed By : @Deepkumar Mahajan
//Github:- https://github.com/Deepkumarmahajan
