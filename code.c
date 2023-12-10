#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lop=1;
void surebye()
{
    system("cls");
            printf("\t\t\tThank For Visiting US!\n");
            printf("\t\t\t    Stay With US\n");
            exit(0);
}
void menu()
{
    printf("<============================Student Database========================>\n");
    printf("\t\t\t[1] Add A New Student\n");
    printf("\t\t\t[2] Show All Student\n");
    printf("\t\t\t[3] Search A Student\n");
    printf("\t\t\t[4] Edit A Student Information\n");
    printf("\t\t\t[5] Delete A Student\n");
    printf("\t\t\t[6] Update Result\n");
    printf("\t\t\t[7] User Guideline\n");
    printf("\t\t\t[0] Exit\n");
    printf("\t\t\tEnter Your Choice: ");

}

void goodbye()
{
    printf("\n\n\t [1] Main Menu");
   printf("\n\t [2] Exit");
   int op;
   printf("\n\t Enter Your Choice  : ");
   scanf("%d",&op);
   if(op!=1)
   {
       surebye();
   return;
   }
   system("cls");
   return;
}
FILE *st;
FILE *dp;
struct student
{
    char id[12];
    char name[30];
    char email[50];
    char phone[12];
    char cgpa[5];
}s;
void add_a_student()
{
    system("cls");
   st=fopen("student document.txt","ab");
   printf("\n\t\tEnter Student ID: ") ;
   scanf("%s",&s.id);
   printf("\n\t\tEnter Student Full Name: ");
   fflush(stdin);
   gets(s.name);
   printf("\n\t\tEnter Student Email: ");
   fflush(stdin);
   scanf("%s",&s.email);
   printf("\n\t\tEnter Phone Number: ");
   scanf("%s",&s.phone);
   printf("\n\t\tEnter Stdudent Current CGPA: ");
   scanf("%s",&s.cgpa);
   fflush(stdin);
   char en[]="\n";

   fwrite(&s,sizeof(s),1,st);
   fprintf(st,"\n");
   fclose(st);
   goodbye();
   return;


}

void  show_all_student()
{
    system("cls");
    printf("\t\t\t\t\t<================All Student Details===============>\n");
    printf("\t%-8 %-15s %-30s %-30s %-17s %s \n","ID","NAME","EMAIL","PHONE","CGPA","\n");
    st=fopen("student document.txt","rb");
    while(fread(&s,sizeof(s)+1,1,st))
    {
        printf("\t%-10s   %-20s %-40s %-20s %-10s\n",s.id,s.name,s.email,s.phone,s.cgpa);
        fflush(stdin);
    }
    fclose(st);
    goodbye();
}

void search_a_student()
{
    system("cls");
    printf("\t\tEnter Student ID: ");
    char givenid[12];
    fflush(stdin);
    scanf("%s",&givenid);
    fflush(stdin);
    system("cls");
    st=fopen("student document.txt","rb");
    int find=0;
    while(fread(&s,sizeof(s)+1,1,st))
    {
        if(strcmp(givenid,s.id)==0)
        {
            printf("\n\n\n\t\tStudent ID: %s\n",s.id);
            printf("\t\tStudent Name: %s\n",s.name);
            printf("\t\tStudent Email: %s\n",s.email);
            printf("\t\tStudent Phone: %s\n",s.phone);
            printf("\t\tStudent CGPA: %s\n",s.cgpa);
            find++;
        }
    }
    if(find==0)
    {
        printf("\t\tThis Id is not available\n");
        printf("\t\tPlease Enter valid ID\n");

    }
    goodbye();
}

void edit_a_student()
{
    system("cls");
    printf("\t\tEnter Student ID: ");
    char givenid[12];
    fflush(stdin);
    scanf("%s",&givenid);
    fflush(stdin);
    system("cls");
    st=fopen("student document.txt","rb");
    dp=fopen("duplicate.txt","ab");
    int find=0;

    while(fread(&s,sizeof(s)+1,1,st))
    {
        if(strcmp(givenid,s.id)==0)
        {
            printf("\n\n\n\t\tStudent ID: %s\n",s.id);
            printf("\t\tStudent Name: %s\n",s.name);
            printf("\t\tStudent Email: %s\n",s.email);
            printf("\t\tStudent Phone: %s\n",s.phone);
            printf("\t\tStudent CGPA: %s\n",s.cgpa);
            find++;

            printf("\n\n\t\tSelect Editable Information\n");
            printf("\t\t[1] Change Name\n");
            printf("\t\t[2] Change Email\n");
            printf("\t\t[3] Change Phone\n");
            printf("\t\t[4] Change CGPA\n");
            printf("\t\t[5] Change ID\n");
            printf("\t\t[0] Don't Change\n");

            int op;
            char nw[50];
            printf("\t\tEnter Your Choice: ");
            scanf("%d",&op);
            printf("\n");
            switch(op)
            {
            case 0:
                {

                    break;
                }
            case 1:
                {
                    printf("\t\tEnter New Name: ");
                    fflush(stdin);
                    gets(nw);
                    strcpy(s.name,nw);


                  break;
                }
                case 2:
                    {
                        printf("\t\tEnter New Email: ");
                    fflush(stdin);
                    gets(nw);
                    strcpy(s.email,nw);
                    break;

                    }
                case 3:
                    {
                        printf("\t\tEnter New Phone: ");
                    fflush(stdin);
                    gets(nw);
                    strcpy(s.phone,nw);
                    break;

                    }
                case 4:
                    {
                        printf("\t\tEnter New CGPA: ");
                    fflush(stdin);
                    gets(nw);
                    strcpy(s.cgpa,nw);
                    break;

                    }

                case 5:
                    {
                        printf("\t\tEnter New ID: ");
                    fflush(stdin);
                    gets(nw);
                    strcpy(s.id,nw);
                    break;

                    }
                default :
                    {
                        break;
                    }
            }
        }


            fwrite(&s,sizeof(s),1,dp);
            fprintf(dp,"\n");

    }
    fclose(st);
    fclose(dp);
    if(find==0)
    {
        printf("\t\tThis Id is not available\n");
        printf("\t\tPlease Enter valid ID\n");

    }

    remove("student document.txt");
    rename("duplicate.txt","student document.txt");

    goodbye();
}

void delete_a_student()
{
    system("cls");
    printf("\t\tEnter Student ID: ");
    char givenid[12];
    fflush(stdin);
    scanf("%s",&givenid);
    fflush(stdin);
    system("cls");
    st=fopen("student document.txt","rb");
    dp=fopen("duplicate.txt","ab");
    int find=0;

    while(fread(&s,sizeof(s)+1,1,st))
    {
        if(strcmp(s.id,givenid)==0)
        {
            find++;
        }
        else
        {
            fwrite(&s,sizeof(s),1,dp);
            fprintf(dp,"\n");
        }
    }


    fclose(st);
    fclose(dp);
    if(find==0)
    {
        printf("\t\tThis Id is not available\n");
        printf("\t\tPlease Enter valid ID\n");

    }
    else
    {
        printf("\t\tStudent information Deleted Successfully.\n");
    }

    remove("student document.txt");
    rename("duplicate.txt","student document.txt");

    goodbye();

}

void user_manual()
{
    system("cls");

    printf("\t\t[1] Student id must be unique and less then 12 character\n");
    printf("\t\t[2] Name must full name and white space also included. It's atmosts contain less then 30 character\n");
    printf("\t\t[3] Any type of email that student actively use. \n\t\t    Student email id not specific. Email must contain less then 50 character \n");
    printf("\t\t[4] Phone number only contain 11 character. Sample 01#########\n");
    printf("\t\t[5] At registration time CGPA must be 0. After publishing semester result it will be updated\n");
    printf("\n\n\t\tThis project Now under Construction. Stay with us. \n");

    printf("\t\tThis program is created by Md Yeasin Arafat\n");

    goodbye();
}

void result()
{
    system("cls");
    printf("\t\tThis site is now under construction\n");
    goodbye();
}


int main()
{
    while(lop)
    {
        menu();
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        {
            surebye();



            exit(0);
            break;
        }
        case 1:
            {
                add_a_student();
                break;

            }
        case 2:
            {
                show_all_student();
                break;

            }
        case 3:
            {
                search_a_student();
                break;

            }
        case 4:
            {
                edit_a_student();
                break;

            }
        case 5:
            {
                delete_a_student();
                break;

            }
        case 6:
            {
                result();
                break;

            }
        case 7:
            {
                user_manual();
                break;

            }
        default :
            {
                break;
            }
    }

    }


    return 0;
}
