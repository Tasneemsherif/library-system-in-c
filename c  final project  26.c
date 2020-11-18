#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int books_num = 0;
static int count;

struct library {
   char  book_name[100][20];
   int   book_id[100];
}books;

void view_all_books()
{
    int q;

    for(q = 0 ;q <= (books_num-1) ;q++ ){
    printf("book's name : %s\n",books.book_name[q]);
    printf("book's id : %d\n",books.book_id[q]);
    }
    printf("\n\n");
};

void adding_book(){

    printf("Enter the book name:  ");
    scanf("%s",&books.book_name[books_num]);
    printf("Enter the book id:  ");
    scanf("%d",&books.book_id[books_num]);
    printf("Your book has been added.");
    books_num = books_num + 1;
    printf("\n\n");
}

void search_books()
{
    int SBID,i;

    printf("Enter the book id:  ");
    scanf("%d",&SBID);
    for (i = 0 ;i <= (books_num + 1);i++)
    {
        if(SBID == books.book_id[i])
        {
            printf("Yes, %s is here.",books.book_name[i]);
            break;
        }
    }
    if(i > books_num)
    {
        printf("This book isn't here yet");
    }
    printf("\n\n");
}

void student_registeration()
{
    char student[50];
    int ID = 0;
    int pass = 0;

    printf("Enter your name: ");
    scanf("%s",&student[50]);
    printf("Enter your ID: ");
    scanf("%d",&ID);
    printf("Create a password: ");
    scanf("%d",&pass);
    count = count + 1;
    printf("\n\n");
}

void user_number()
{

    printf("This is the number of all users registered on the system: %d",count);
    printf("\n\n");
}

int show_menu()
{
    int x;
    int feedback = 0;

    printf("Choose what do you want to do:\n");

    printf("[1] Student Registeration.\n");

    printf("[2] User's number.\n");

    printf("[3] Add a book.\n");

    printf("[4] View all books.\n");

    printf("[5] Search for a specific book.\n");

    printf("[99] Exit.\n");
    scanf("%d",&x);
    if (x > 0 && x < 6)
    {
        if (x == 1)
        {
            student_registeration();
            show_menu();
        }
        if (x == 2)
        {
            user_number();
            show_menu();
        }
        if (x == 3)
        {
            adding_book();
            show_menu();
        }
        if (x == 4)
        {
            view_all_books();
            show_menu();
        }
        if (x == 5)
        {
            search_books();
            show_menu();
        }
    }
    else if (x == 99)
    {

        printf("Give us your feedback out of 5.\n");
        scanf("%d",&feedback);
        printf("Thanks for using our library system.");
    }
    else
    {

        printf("We don't have that option please enter a valid option.");
        show_menu();
    }
    return (0);
};

void main()
{
    printf("Hello dear!\n");
    show_menu();
}

