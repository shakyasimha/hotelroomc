#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Custom defined header files:
#include "SetConsoleCursorPosition.h"
#include "conio.h"

#define size 30

//Global variable declarations

int li, lp, single_room[size], dr[size], rno, rnum, i, e;
char rc, ch, selection, eselection, rselection, temp[80], vselection, mf, ar;
float days, hrate, hbill, amount, balance;
FILE *f;

typedef struct hotelsystem
{
       char name[size][35], visitor_bookinnumba[size][15], residential_adres[size][20], rphone[size][12], rdate[size][12];

}hotelsystem;

hotelsystem guest;

typedef struct hotelsystem1
{
       char name[size][30], visitor_bookinnumba[size][20], residential_adres[size][20], rphone[size][12], rdate[size][12];

}hotelsystem1;

hotelsystem1 guest1;

//Function declarations

void gotoxy(int, int);
void SelectOption(void);
void BookRoom(void);
void CheckOut(void);
void EditRoom(void);
void CancelRequest(void);
void VisitorList(void);
void RoomStatus(void);
void ExitSystem(void);
void Error(void);

//The actual program starts here:

//The main module of the program:

int main()
{
    system("color 9f");

    gotoxy(20,10);
    printf("W E L C O M E   T O   H O T E L   R O O M   B O O K I N G   A P P L I C A T I O N");
    gotoxy(40, 20);
    printf("Press any key to continue.....");
    getch();
    SelectOption();

    return 0;
}

//Main menu of the program:

void SelectOption(void)
{
    system("color 9f");
    char choice;

    system("cls");
    gotoxy(40, 7);
    printf("[1]: FOR ROOM BOOKING");
    gotoxy(40, 8);
    printf("[2]: CHECK OUT");
    gotoxy(40, 9);
    printf("[3]: ALTER ROOM STATUS");
    gotoxy(40, 10);
    printf("[4]: CHECK ROOM STATUS");
    gotoxy(40, 11);
    printf("[5]: PREVIEW VISITOR LIST");
    gotoxy(40, 12);
    printf("[6]: VACATE ROOM");
    gotoxy(40, 13);
    printf("[7]: EXIT");
    gotoxy(0, 20);
    printf("Please enter your choice: ");

    choice = getch();

    switch(choice)
    {
        case '1':
            BookRoom();   ///For booking a room

        case '2':
            CheckOut();   ///For checking out

        case '3':
            EditRoom();   ///For editing room status

        case '4':
            RoomStatus();  ///For viewing room status

        case '5':
            VisitorList();  ///For viewing guest list

        case '6':
            CancelRequest();  ///For cancelling reservation

        case '7':
            ExitSystem();    ///For exiting the program

        default:
            Error();        ///Calls error function

    } //Ends switch case

}

//ExitSystem() function starts:

void ExitSystem(void)
{
    system("cls");
    system("color 0f");

    printf("Program is exiting. Press any key to continue.....");
    getch();
    system("cls");

    exit(0);

} //End of ExitSystem() function

//Error() function starts:

void Error(void)
{
    system("cls");
    system("color 71");

    gotoxy(40, 10);
    printf("ERROR! INVALID INPUT. \n \n");
    gotoxy(40, 16);
    printf("Press any key to continue.....");
    getch();
    SelectOption();

} //End of Error() function

//Start of BookRoom() function

void BookRoom(void)
{
    system("cls");
    system("color 0b");

    gotoxy(40, 4);
    printf("R O O M   R E S E R V A T I O N S");

    getch();
    system("cls");

    printf("WE ONLY OFFER DOUBLE OR SINGLE ROOMS: DO YOU WANT TO CONTINUE RESERVING A ROOM? ( Y / N )\n");

    eselection = getch();
    eselection = toupper(eselection);

    switch(eselection)
    {
    case 'Y':
        {
            printf("\n\nENTER [S] FOR SINGLE ROOM OR [D] FOR DOUBLE ROOM\n\n");
            rselection = getch();
            rselection = toupper(rselection);

            //Beginning of switch(rselection)

            switch(rselection)
            {
            case 'S':
                {
                    for(i = 1; i < size; i++)
                    {
                            //If case starts here:
                            if(single_room[i] == 0)
                                    {
                                        system("cls");

                                        gotoxy(20, 4);
                                        printf("V I S I T O R   C O N F I D E N T I A L   I N F O R M A T I O N  : \n");

                                        single_room[i] = 1;
                                        f = fopen("single.txt","a+");

                                        printf("\n\nROOM No : %d IS AVAILABLE FOR RESERVATION", i);
                                        printf("\n\nENTER GUEST NAME\n");
                                        gets(guest.name[i]);
                                        printf("\nENTER VISITOR BOOKING NUMBER\n");
                                        gets(guest.visitor_bookinnumba[i]);
                                        printf("\nENTER ADRESS\n");
                                        gets(guest.residential_adres[i]);
                                        printf("\nENTER PHONE NUMBER\n");
                                        gets(guest.rphone[i]);
                                        printf("\nENTER CHECK IN DATE\n");
                                        gets(guest.rdate[i]);
                                        fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", i, guest.name[i], guest.visitor_bookinnumba[i], guest.residential_adres[i], guest.rphone[i], guest.rdate[i]);
                                        fclose(f);

                                        system("cls");
                                        system("color 5f");

                                        gotoxy(20, 10);
                                        printf("R O O M   B O O K E D   S U C C E S S F U L L Y !");
                                        gotoxy(20, 14);
                                        printf("Press any key to continue.......");

                                        getch();
                                        SelectOption();

                                }//End of if case
                    }//End of for loop

                }//End of case S

            case 'D':
                {
                    for(i = 1; i < size; i++)
                    {
                        if(dr[i] == 0)
                        {
                            system("cls");

                            gotoxy(20, 4);
                            printf("V I S I T O R  C O N F I D E N T I A L  I N F O R M A T I O N : ");

                            dr[i] = 1;
                            f = fopen("double.txt","a+");

                            printf("\n\nROOM No : %d IS AVAILABLE FOR RESERVATION", i);
                            printf("\n\nENTER GUEST NAME\n");
                            gets(guest1.name[i]);
                            printf("\nENTER VISITOR BOOKING NUMBER\n");
                            gets(guest1.visitor_bookinnumba[i]);
                            printf("\nENTER RESIDENTIAL ADRESS\n");
                            gets(guest1.residential_adres[i]);
                            printf("\nENTER MOBILE PHONE NUMBER\n");
                            gets(guest1.rphone[i]);
                            printf("\nENTER CHECK IN DATE\n");
                            gets(guest1.rdate[i]);
                            fprintf(f,"\n%d\t%s\t\t%s\t%s\t%s\t%s", i, guest1.name[i], guest1.visitor_bookinnumba[i], guest1.residential_adres[i], guest1.rphone[i], guest1.rdate[i]);

                            fclose(f);

                            gotoxy(40, 40);
                            printf("ROOM BOOKED SUCCESSFULLY! \n Press any key to continue.....");

                            getch();
                            SelectOption();
                        }//End of if case
                    }//End of for loop
                }//End of case D

            default:
                {
                    Error();
                }//End of default
            }//End of switch(rselection)
        }
        //End of case Y

    default:
        {
            Error();
        }
        //End of default
    }//End of switch(eselection)

} //End of BookRoom() function

//Start of CheckOut() function

void CheckOut(void)
{
     days = 0;
     hrate = 0;
     hbill = 0;

     system("cls");
     system("color e5");

     gotoxy(40, 4);
     printf("V I S I T O R  C H E C K I N G  O U T");
     gotoxy(40, 6);
     printf("ENTER ROOM NUMBER CHECKING OUT\n");
     scanf("%s", temp);
     rno = atoi(temp);

     if(rno < 1 || rno > 30)
     {
        system("color 5f");
        printf("\n\n\a\a\aINVALID ROOM NUMBER \a\a\a");
        system("pause");
        SelectOption();
     }//End of if case
     else
     {
         printf("\nENTER [S] FOR SINGLE ROOM or [D] FOR DOUBLE ROOM\n");
         rc = getch();
         rc = toupper(rc);

        switch(rc)
        {
        case 'S':
            {
                if(single_room[rno] == 1)
                {
                        system("cls");
                        system("color 5f");
                        f = fopen("single.txt", "r+");
                        fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                        printf("\n\nSINGLE ROOM NUMBER No %d IS NOW CHECKING OUT", rno);
                        printf("\n\nGUEST NAME : %s \n\nGUEST BOOKING NUMBER : %s \n\nRESIDENTIAL ADRESS : %s\n\nMOBILE PHONE NUMBER : %s\n\nCHECK IN DATE : %s \n\n",guest.name[rno],guest.visitor_bookinnumba[rno],guest.residential_adres[rno],guest.rphone[rno],guest.rdate[rno]);
                        printf("\nENTER NUMBER OF DAYS STAYED\n");
                        scanf("%f", &days);
                        printf("\nENTER THE BREAKFAST + LUNCH + SUPPER + BEDDING CHARGE\n");
                        scanf("%f", &hrate);

                        if((days < 1 && days > 90) && (hrate < 1 && hrate >32000))
                        {
                                system("color 5f");
                                printf("\n\a\a\aINVALID ENTRY OF DAYS || CHARGE\a\a\a");
                                printf("\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                                getch();
                                SelectOption();
                        }//End of nested if case
                        else
                        {
                            hbill = days * hrate;
                        }//End of nested else case

                        printf("\nTOTAL CHARGES ARE $%.2f",hbill);
                        printf("\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                        fclose(f);
                        single_room[rno] = 0;
                        getch();
                        SelectOption();
                }//End of if case
                else
                {
                        printf("\n\nSINGLE ROOM No %d IS VACANT CANNOT CHECK OUT",rno);
                        printf("\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                        getch();
                        SelectOption();
                }//End of else case
            }//End of case S

        case 'D':
            {
                if(dr[rno] == 1)
                {
                        system("cls");
                        system("color 5f");
                        f = fopen("double.txt", "r+");
                        fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                        printf("\n\nDOUBLE ROOM No %d IS NOW CHECKING OUT",rno);
                        printf("\n\nGUEST NAME : %s \n\nGUEST BOOKING NUMBER : %s \n\nRESIDENTIAL ADRESS: %s\n\nMOBILE PHONE NUMBER : %s\n\nCHECK IN DATE: %s \n\n",guest1.name[rno],guest1.visitor_bookinnumba[rno],guest1.residential_adres[rno],guest1.rphone[rno],guest1.rdate[rno]);
                        printf("\n\nENTER NUMBER OF DAYS STAYED\n");
                        scanf("%f",&days);
                        printf("\nENTER THE BREAKFAST + LUNCH + SUPPER + BEDDING CHARGE\n");
                        scanf("%f",&hrate);

                        if((days < 1 || days > 60) && (hrate < 1 || hrate > 30000))
                        {
                            system("color 5f");
                            printf("\n\n\a\a\aINVALID ENTRIES\a\a\a");
                        }
                        else
                        {
                            hbill = days * hrate * 1.2;
                        }

                        printf("TOTAL CHARGES ARE $%.2f",hbill);
                        printf("\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                        fclose(f);
                        dr[rno] = 0;
                        getch();
                        SelectOption();

                }//End of if case
                else
                {
                        printf("\n\nDOUBLE ROOM No %d IS VACANT CANNOT CHECK OUT", rno);
                        printf("\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<< ");
                        getch();
                        SelectOption();
                }//End of else case
            }//End of case D

        default:
            {
                Error();
            }//End of default:
        }//End of switch(rc)

     }//End of else case
} //End of CheckOut() function

//Start of EditRoom() function

void EditRoom(void)
{
    system("cls");
    system("color bd");

    gotoxy(20, 4);
    printf("A L T E R  R O O M  S T A T U S");
    printf("\n\n\n\n\n\n");
    printf("ENTER ROOM NUMBER TO BE ALTERED\n");
    scanf("%s", temp);
    rno = atoi(temp);

    if(rno < 1 || rno > 30)
    {
        system("color 71");
        printf("\n\n\a\a\aINVALID ROOM NUMBER \a\a\a");
        system("pause");
        SelectOption();
    }//End of if case
    else
    {
        printf("\nENTER [S] FOR SINGLE ROOM/ [D] FOR DOUBLE ROOM \n");
        rc = getch();
        rc = toupper(rc);

        for(int k = 0; k < 5; k++)
        {
            system("cls");
            system("cls");
            system("cls");
            system("color bd");

            gotoxy(10, 10);
            printf("L O A D I N G  D A T A . . . . . .");
            printf("\n \n \n \n \n ");
        } //end of for loop

        switch(rc)
        {
        case 'S':
            {
                if(single_room[rno] == 1)
                {
                    system("cls");
                    system("color bd");
                    f = fopen("single.txt", "a+");
                    fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                    printf("\n\nSINGLE ROOM No %d IS RESERVED FOR:", rno);
                    printf("\n\nGUEST NAME : %s \n\n VISITER BOOKING NUMBER : %s \n\nRESIDENTIAL ADRESS: %s\n\nMOBILE PHONE NUMBER: %s\n\nCheck In Date : %s \n\n", guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                    printf("\n\nPress \n1 : TO CHANGE NAME\n2 : TO CHANGE VISITOR BOOKING NUMBER\n3 : ADDRESS\n4 : MOBILE PHONE NUMBER\n5 : CHECK IN DATE\n\n");
                    mf = getch();
                    mf = toupper(mf);

                    //Switch case begins here:

                    switch(mf)
                    {
                    case '1':
                        {
                            printf("\n\nENTER NEW NAME\n");
                            gets(guest.name[rno]);
                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                            getch();
                            SelectOption();

                        }//End of case 1

                    case '2':
                        {
                            printf("\n\nENTER NEW VISITOR BOOKING NUMBER\n");
                            gets(guest.visitor_bookinnumba[rno]);
                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                            getch();
                            SelectOption();
                        }//End of case 2

                    case '3':
                        {
                            printf("\n\nENTER NEW ADRESS\n");
                            gets(guest.residential_adres[rno]);
                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                            getch();
                            SelectOption();
                        }//End of case 3

                    case '4':
                        {
                            printf("\n\nENTER NEW PHONE NUMBER\n");
                            gets(guest.rphone[rno]);
                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                            getch();
                            SelectOption();
                        }//End of case 4

                    case '5':
                        {
                            printf("\n\nENTER NEW CHECK IN DATE\n");
                            gets(guest.rdate[rno]);
                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                            getch();
                            SelectOption();
                        }//End of case 5

                    default:
                        {
                            Error();
                        }
                    }
                    fclose(f);
                }//End of if

                else
                {
                    printf("\n\nSINGLE ROOM No %d IS VACANT",rno);
                    printf("\n\n\n>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                    getch();
                    SelectOption();
                }//End of else
            }//End of case S

        case 'D':
            {
                if(dr[rno] == 1)
                {
                        system("cls");
                        system("color 5f");
                        f = fopen("double.txt", "a+");
                        fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                        printf("\n\nDOUBLE ROOM NUMBER No %d IS RESERVED", rno);
                        printf("\n\nGUEST NAME: %s \n\nGUEST BOOKING NUMBER : %s \n\nRESIDENTIAL ADDRESS : %s\n\nMOBILE PHONE NUMBER: %s\n\nCHECK IN DATE: %s \n\n", guest1.name[rno], guest1.visitor_bookinnumba[rno], guest1.residential_adres[rno], guest1.rphone[rno], guest1.rdate[rno]);
                        printf("\n\nPress\n1 : TO CHANGE NAME\n2 : TO CHANGE VISITOR BOOKING NUMBER\n3 :ADDRESS\n4 : MOBILE PHONE NUMBER\n5 : CHECK IN DATE\n\n\n");
                        mf = getch();
                        mf = toupper(mf);

                        switch(mf)
                        {
                            case '1':
                                {
                                            printf("\n\nENTER NEW NAME\n");
                                            gets(guest1.name[rno]);
                                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                            getch();
                                            SelectOption();
                                    }
                            case '2':
                                {
                                            printf("\n\nENTER NEW VISITOR'S BOOKING NUMBER\n");
                                            gets(guest1.visitor_bookinnumba[rno]);
                                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                            getch();
                                            SelectOption();
                                    }
                            case '3':
                                {
                                            printf("\n\nENTER NEW RESIDENTIAL ADRESS\n");
                                            gets(guest1.residential_adres[rno]);
                                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                            getch();
                                            SelectOption();
                                }
                            case '4':
                                {
                                            printf("\n\nENTER NEW MOBILE PHONE NUMBER\n");
                                            gets(guest1.rphone[rno]);
                                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                            getch();
                                            SelectOption();
                                }
                            case '5':
                                {
                                            printf("\n\nENTER NEW CHECK IN DATE\n");
                                            gets(guest1.rdate[rno]);
                                            fprintf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                            getch();
                                            SelectOption();
                                }
                                default:
                                    {
                                        Error();
                                    }
                        }
                        fclose(f);

                }//End of if case
                else
                {
                    printf("\n\nSINGLE ROOM No %d IS VACANT",rno);
                    printf("\n\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                    getch();
                    SelectOption();
                }//End of else
            }//End of case D

        default:
            {
                Error();
            }//End of default
        }//End of switch(rc)
    }//End of else case
}//End of EditRoom()

//Start of RoomStatus() function

void RoomStatus(void)
{
    system("cls");
    system("color b8");

    gotoxy(40, 10);
    printf("V I E W  R O O M  S T A T U S ");
    gotoxy(40, 16);
    printf("PRESS [S] FOR SEQUENTIAL VIEWING OF ROOM STATUS");
    gotoxy(40, 18);
    printf("PRESS [V] FOR SINGULAR VIEWING OF ROOM STATUS");

     vselection = getch();
     vselection = toupper(vselection);

     for(int k = 0; k < 4; k++)
     {
         system("cls");
         system("color 5f");

         switch(vselection)
         {
               case 'S':
                {
                    system("cls");
                    system("color b8");

                    f = fopen("single.txt", "r+");

                    gotoxy(10, 4);
                    printf("S E Q U E N T I A L  S I N G L E  R O O M  S T A T U S");

                    printf("\n\nR.No.\tNAME\t\tBOOKING No\tADRESS\tPHONE No\tCHECK IN DATE\n");

                    for(int i = 1; i < size; i++)
                    {
                        if(single_room[i]==1)
                        {
                                fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &i, guest.name[i], guest.visitor_bookinnumba[i], guest.residential_adres[i], guest.rphone[i], guest.rdate[i]);
                                printf("\n%d\t%s\t\t%s\t%s\t%s\t%s\n",i,guest.name[i],guest.visitor_bookinnumba[i],guest.residential_adres[i],guest.rphone[i],guest.rdate[i]);
                        }
                    }

                    fclose(f);

                    printf("\n\n\t\t>>>HIT ANY KEY TO CHECK DOUBLE ROOM STATUS<<<\n\n");
                    getch();

                    system("cls");

                    f = fopen("double.txt", "a+");

                    gotoxy(10, 4);
                    printf("S E Q U E N T I A L  D O U B L E  R O O M  S T A T U S");

                    printf("\n\nR.No.\tNAME\tBOOKING No:r\tADRESS\tPHONE No\tCHECK IN DATE\n");
                    for(int i = 1; i < size; i++)
                    {
                        if(dr[i] == 1)
                        {
                                fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &i, guest.name[i], guest.visitor_bookinnumba[i], guest.residential_adres[i], guest.rphone[i], guest.rdate[i]);
                                printf("\n%d\t%s\t%s\t%s\t%s\t%s\n", i, guest1.name[i], guest1.visitor_bookinnumba[i], guest1.residential_adres[i], guest1.rphone[i], guest1.rdate[i]);
                        }
                    }
                    fclose(f);

                    printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO MAIN THE MENU<<<\n\n");
                    getch();
                    SelectOption();
                }//end of case S

                case 'V':
                {
                    system("cls");
                    system("color b8");

                    gotoxy(10, 4);
                    printf("S I N G L E  R O O M  S T A T U S  I N F O R M A T I O N");

                    printf("\n\nENTER ROOM NUMBER TO BE CHECKED FOR OCCUPANCY\n\n");
                    scanf("%s", temp);;
                    rno = atoi(temp);

                    if(rno < 1 || rno > 30)
                    {
                        system("color 5f");
                        printf("\n\n\a\a\aINVALID ROOM NUMBER \a\a\a");
                        system("pause");
                        SelectOption();
                    }
                    else
                    {
                        if(single_room[rno] == 1)
                        {
                                    system("cls");
                                    system("color 5f");

                                    f = fopen("single.txt", "r+");

                                    gotoxy(40, 10);
                                    printf("S I N G U L A R  R O O M  S T A T U S  I N F O R M A T I O N");

                                    fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                    printf("\n\nSINGLE ROOM No %d IS RESERVED FOR", rno);
                                    printf("\n\n\nGUEST NAME : %s \n\nVISITOR BOOKING NUMBER : %s \n\nRESIDENTIAL ADRESS : %s\n\nMOBILE PHONE NUMBER: %s\n\nCHECK OUT DATE : %s \n\n",guest.name[rno],guest.visitor_bookinnumba[rno],guest.residential_adres[rno],guest.rphone[rno],guest.rdate[rno]);
                                    printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                                    getch();
                                    SelectOption();

                                    fclose(f);
                        }
                        else
                        {
                            printf("\n\nSINGLE ROOM No %d IS VACANT ", rno);
                            getch();
                        }
                        if(dr[rno] == 1)
                        {
                                system("cls");
                                system("color 5f");

                                f = fopen("double.txt", "r+");

                                gotoxy(10, 4);
                                printf("D O U B L E  R O O M  S T A T U S  I N F O R M A T I O N");
                                printf("\n \n \n \n \n");

                                fscanf(f, "\n%d\t%s\t\t%s\t%s\t%s\t%s", &rno, guest.name[rno], guest.visitor_bookinnumba[rno], guest.residential_adres[rno], guest.rphone[rno], guest.rdate[rno]);
                                printf("\n\nDOUBLE ROOM No %d IS RESERVED",rno);
                                printf("\n\n\nGUEST NAME : %s \n\nVISITOR BOOKING NUMBER: %s \n\nRESDENTIAL ADRESS: %s\n\nMOBILE NUMBER: %s\n\nCHECK OUT DATE: %s \n\n",guest1.name[rno],guest1.visitor_bookinnumba[rno],guest1.residential_adres[rno],guest1.rphone[rno],guest1.rdate[rno]);
                                printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                                getch();
                                SelectOption();

                                fclose(f);
                        }
                        else
                        {
                            printf("\n\n\n\nDOUBLE ROOM No %d IS VACANT ",rno);
                            printf("\n\n\a\a\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<...");
                            getch();
                            SelectOption();
                        }

                    }//end of else

                }//end of case V

                default:
                {
                    Error();
                }
         }//End of switch vselection
    }//End of for loop

}

//Start of VisitorList() function

void VisitorList(void)
{
     system("cls");
     system("color e1");

     gotoxy(40, 2);
     printf("P R E V I E W   V I S I T O R   L I S T");
     gotoxy(0, 8);
     printf("ENTER [S] FOR SINGLE ROOM GUEST LIST or [D] FOR DOUBLE ROOM GUEST LIST.....");

     rselection = getch();

     switch(rselection)
     {
     case 'S':
        {
                system("cls");
                system("color e1");

                gotoxy(40, 4);
                printf("SINGLE ROOM GUESTS");
                printf("\n \n \n \n \n");
                printf("\nR.No.\tNAME\t\tBOOKIN NUMBER\tADRESS\tPHONE No\tCHECK In\n");

                f = fopen("single.txt","r+");

                while(fgets(guest.name[i], 10000, f) != NULL)
                {
                    printf("%s",guest.name[i]);
                }

                fclose(f);

                gotoxy(0, 0);
                printf("PRESS ANY KEY TO EXIT TO THE MAIN MENU");

                getch();
                SelectOption();

        }//End of case S

     case 'D':
        {
            system("cls");
            system("color e1");

            gotoxy(40,4);
            printf("DOUBLE ROOM GUESTS");
            printf("\n \n \n \n \n");
            printf("\nR.No.\tNAME\t\tBOOKING No\tADRESS\tPHONE No\tCHECK In\n");

            f = fopen("double.txt","r+");

            while(fgets(guest.name[i], 10000, f) != NULL)
            {
                printf("%s", guest.name[i]);

            }

            fclose(f);

            gotoxy(40, 10);
            printf("PRESS ANY KEY TO EXIT TO THE MAIN MENU");

            getch();
            SelectOption();
        }//End of case D

     default:
        {
            Error();
        }//End of default
     }//End of switch case
}//End of VisitorList() function

//Start of CancelRequest() function

void CancelRequest(void)
{
     system("cls");
     system("color 8f");

     gotoxy(40, 5);
     printf("V A C A T E   R O O M \n");
     gotoxy(0, 10);
     printf("ENTER ROOM NUMBER TO VACATE\n");

     scanf("%s", temp);

     rno = atoi(temp);

     // Room Number Limit Check
     if(rno < 1 || rno > 30)
     {
        system("color 5f");
        gotoxy(40, 10);
        printf("\n\n\a\a\aINVALID ROOM NUMBER \a\a\a");
        getch();
        SelectOption();
     }
     else
     {
           printf("\n\nSINGLE Or DOUBLE ROOM? [S / D]");

           rc = getch();
           rc = toupper(rc);

           switch(rc)
           {
             case 'S':
                {
                    single_room[rno] = 0;
                    printf("\n\nROOM VACATED");
                    printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                    getch();
                    SelectOption();
                }
             case 'D':
                 {
                    dr[rno]=0;
                    printf("\n\nROOM VACATED");
                    printf("\n\n\t\t>>>HIT ANY KEY TO EXIT TO THE MAIN MENU<<<");
                    getch();
                    SelectOption();
                 }

              default:
                  {
                    Error();
                  }
            }//end of switch
    }//end of else
}//End of CancelRequest() function
