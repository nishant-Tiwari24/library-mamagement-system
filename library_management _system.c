
// createm some file


#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include <string.h>

void title();
void welcome();
void clear_display();
void menu();
void add_book();
void delete_book();
void search_book();
void issue_book();
void book_list();
void reading(); // reading the value file
void pause();
void update_book_list(int num);
void copy_file();
void delete(); // reprint file after deleting
void empty_structure();

//structure for viewing book
struct book_name
{
	char book_name[100];
	char book_id[100];
	char book_author[100];
    int book_quantity;

}b1[100];

int total_number_book=0; //total books available in file

int main()
{
    welcome();
    pause(); // to continue the programe
    empty_structure();
    reading(); // scanning file
    
    int ch=1;

    while(1)
    {
        clear_display();
        menu();
        int choice = 1;
        printf("\n\nEnter your choice -> ");
        scanf("%d", &ch);

        //choice of the user
        switch(ch)
        {
            // add book
            case 1:
                clear_display();
                title();
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                             Add New Books\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\nEnter Your Details Below :\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                while (choice)
                {
                    add_book();
                    printf("\n\nTo add more book -> (Press 1)");
                    printf("\nBack to Main Menu -> (Press 0)");
                    printf("\nEnter your choice : ");
                    fflush(stdin);
                    scanf("%d", &choice);
                }
                break;
            
            // delete book
            case 2:
                clear_display();
                title();
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                             Delete Book\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\nEnter the details given below :\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                while (choice)
                {
                    delete_book();
                    printf("\n\nTo delete more book -> (Press 1)");
                    printf("\nBack to Main Menu -> (Press 0)");
                    printf("\nEnter your choice : ");
                    scanf("%d", &choice);
                }
                break;

            // search book
            case 3:
                title();
                clear_display();
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                             Search Books\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\nEnter Your Details Below :\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                while (choice)
                {
                    search_book();
                    printf("\n\nTo search more book -> (Press 1)");
                    printf("\nBack to Main Menu -> (Press 0)");
                    printf("\nEnter your choice : ");
                    scanf("%d", &choice);
                }
                break;

            // book issue
            case 4:
                title();
                clear_display();
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                             Issue Books\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\nEnter Your Details Below :\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                while (choice)
                {
                    issue_book();
                    fflush(stdin);
                    printf("\n\nTo issue more book -> (Press 1)");
                    printf("\nBack to Main Menu -> (Press 0)");
                    printf("\nEnter your choice : ");
                    scanf("%d", &choice);
                }
                break;

            // view book list
            case 5:
                title();
                clear_display();
                printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("                                                             Book List\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\nHere are the available books :\n");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                book_list();
                printf("\nBack to Main Menu -> (Press 0)");
                printf("\nEnter your choice : ");
                scanf("%d", &choice);
                break;

            case 6:
                exit(1);
                break;
            default:
            exit(1);
                break;
        };
    }
    return 0;
}

// university sign
void title()
{
    printf("\n\n");
    printf("                        ******************** * SRM UNIVERSITY AP * ********************\n");
    printf("                                         * Library Management System * ");   
}
//welcome 
void welcome()
{
    title();
    printf("\n\n\n\n\n");
    printf("                                   Project Made By : \n");
    printf("                                        -> Mehu  (AP22110010962) \n");
    printf("                                        -> Bhowmik (AP22110010962) \n");
    printf("                                        -> Nila ticket (AP22110010962) \n\n\n");

}

//pause
void pause ( void )
{
    printf("                              Press enter to continue.....");
    char enter = 0;
    while (enter != '\r' && enter != '\n') 
    { 
        enter = getchar(); 
    }
};

// to clear the output screen
void clear_display()
{
    system("cls");
};


// display the main menu
void menu()
{
    title();
    printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                             Main Menu\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n1. Add Book\n");
    printf("2. Delete Book\n");
    printf("3. Search Book\n");
    printf("4. Issue Book\n");
    printf("5. View Book List\n");
    printf("6. Close Application\n");
};

void add_book()
{
    char name[20];
    char No[20];
    char author[20];
    int quantity_book=0;
    fflush(stdin);
    printf("\nBook Name : ");
    gets(name);
    printf("Book id No. : ");
    fflush(stdin);
    gets(No);
    printf("Book Auhtor Name : ");
    gets(author);
    printf("Book quantity : ");
    fflush(stdin);
    scanf("%d", &quantity_book);

    FILE *file=NULL;
    file = fopen("D:\\book_list.txt", "a");
    if(file == NULL)
    {
        printf("File Not available....");
        exit(1);
    }

    // add book to structure
    {
        strcpy(b1[total_number_book].book_name, name);
        strcpy(b1[total_number_book].book_id, No);
        strcpy(b1[total_number_book].book_author, author);
        b1[total_number_book].book_quantity = quantity_book;
        total_number_book++;
    }
    fprintf(file, "%s\n", name);
    fprintf(file, "%s\n", No);
    fprintf(file, "%s\n", author);
    fprintf(file, "%d\n", quantity_book);
    
    fclose(file);
};

// deletion of book from main
void delete_book()
{
    char id[10];
	printf("\nEnter Book id No. : ");
	scanf("%s", &id);
    int flag = 0;
    for(int i=0; i<total_number_book; i++)
	{
        if(id == b1[total_number_book-1].book_id)
        {
            printf("\nBook deleted....");
            printf("\nBook Name : %s", b1[i].book_name);
            printf("\nBook Id No. : %s", b1[i].book_id);
            printf("\nBook Author : %s", b1[i].book_author);
            printf("\nBook Quantity : %d", b1[i].book_quantity);
            strcpy(b1[i].book_name, "");
            strcpy(b1[i].book_id, "");
            strcpy(b1[i].book_author, "");
            b1[i].book_quantity = 0;
            total_number_book--;
            flag++;
            break;
        }
		if(!strcmp(id, b1[i].book_id))
        {
            printf("\nBook deleted....");
            printf("\nBook Name : %s", b1[i].book_name);
            printf("\nBook Id No. : %s", b1[i].book_id);
            printf("\nBook Author : %s", b1[i].book_author);
            printf("\nBook Quantity : %d", b1[i].book_quantity);
            for (int j=i; j <  total_number_book - 1; j++)
            {
                strcpy(b1[j].book_name, b1[j+1].book_name);
                strcpy(b1[j].book_id, b1[j+1].book_id);
                strcpy(b1[j].book_author, b1[j+1].book_author);
                b1[j].book_quantity = b1[j+1].book_quantity;
            }
            total_number_book--; 
            strcpy(b1[total_number_book].book_name, "");
            strcpy(b1[total_number_book].book_id, "");
            strcpy(b1[total_number_book].book_author, "");
            b1[total_number_book].book_quantity = 0;

            delete(); // delete book info from the data file
            flag++;
            break; 
        }
       
    }
    flag == 0?printf("\nBook Not available....."):0;
    
        
};

// deleting data from the file
void delete()
{
    FILE *file = NULL;
    file = fopen("D:\\delete.txt", "w");
    if (file == NULL)
    {
        exit(1);
    }
    for(int i=0; i<total_number_book; i++)
    {
        fprintf(file, "%s\n", b1[i].book_name);
        fprintf(file, "%s\n", b1[i].book_id);
        fprintf(file, "%s\n", b1[i].book_author);
        fprintf(file, "%d\n", b1[i].book_quantity);
    }
    
}
// search of book
void search_book()
{
    char id[10];
	printf("\nEnter Book id No. : ");
	scanf("%s", &id);
    
    int i = 0;
	for(i=0; i<total_number_book; i++)
	{
		if(!strcmp(id , b1[i].book_id))
		{
			printf("\n\nBook found");
            printf("\nBook Name : %s", b1[i].book_name);
            printf("\nBook Id No. : %s", b1[i].book_id);
            printf("\nBook Author : %s", b1[i].book_author);
            printf("\nBook Quantity : %d", b1[i].book_quantity);
            break;
		}
	}
    i == total_number_book?printf("\nBook with given id Not available....."):0;
};

// book to be issued by user
void issue_book()
{
    char student_name[20], id_book[10], issue_date[10], student_id[13];
    printf("Student name : ");
    scanf("%s", &student_name);
    printf("Student id : ");
    scanf("%s", &student_id);
    printf("Book id : ");
    scanf("%s", &id_book);
    printf("Issue Date (DD/MM/YY) : ");
    scanf("%s", &issue_date);

    FILE *file=NULL;
    file = fopen("D:\\book_issue.txt", "a");
    if(file == NULL)
    {
        exit(1);
    }
    int num = 0, i = 0;
    for(i=0; i<total_number_book; i++)
    {
        if(!strcmp(id_book, b1[i].book_id))
        {
            {
                num = b1[i].book_quantity--;
                fprintf(file, "%s\n", student_name);
                fprintf(file, "%s\n", student_id);
                fprintf(file, "%s\n", id_book);
                fprintf(file, "%s\n", issue_date);
            }
            break;
        }
    }
    i == total_number_book?printf("\nBook not available...."):0;
 
    fclose(file);
    fflush(stdin);
    update_book_list(num++);

};

// book list updating
void update_book_list(int num)
{
    // programe to replace string with string
    FILE *file = NULL, *file2;
    file = fopen("D:\\book_list.txt", "r");
    file2 = fopen("D:\\temp.txt", "w");
    if(file == NULL)
    {
        exit(1);
    }
    char value;
    while(!feof(file))
    {
        value = fgetc(file);
            if(value-48 == num)
            {
                fprintf(file2, "%d", num--);
            }
            else
            {
                fprintf(file2, "%c", value);
            }
    }
    fclose(file);
    fclose(file2);
    copy_file();
}

// copying file2 to file1
void copy_file()
{
    FILE *file1, *file2;
    file2 = fopen("D:\\book_li.txt", "w");
    file1 = fopen("D:\\temp.txt", "r");
    char value;
    value = fgetc(file1);
    while(!feof(file1))
    {
        fprintf(file2, "%c", value);
        value = fgetc(file1);
    }
    fclose(file1);
    fclose(file2);
    

}
// print the list of book avialable
void book_list()
{
    printf("\v");
    printf("%d", total_number_book);
    printf("\t+--------+-------------------------+-----------+------------------------+------------+\n");
    printf("\t| S.No.  |      Book Name          |  Book Id  |      Book Author       |  Quantity  |\n");
    printf("\t+--------+-------------------------+-----------+------------------------+------------+\n");
    for(int i=0; i<total_number_book; i++)
    {
        printf("\t|  %-2d    |      %-16s   |   %-6s  |      %-15s   |     %-2d     |\n", i+1, b1[i].book_name, b1[i].book_id, b1[i].book_author, b1[i].book_quantity);   
    }
    printf("\t+--------+-------------------------+-----------+------------------------+------------+\n");
};

//empty structure
void empty_structure()
{
    for(int i=0; i<100; i++)
    {
        strcpy(b1[i].book_name, "");
        strcpy(b1[i].book_id, "");
        strcpy(b1[i].book_author, "");
        b1[i].book_quantity = 0;
    }
}

// reading book file
void reading()
{
    FILE *fp=NULL;
	fp = fopen("D:\\book_list.txt", "r");
	if(fp==NULL)
	{
		printf("not available.");
	}
	char arr;
	int count = 1, i=0;
	while(!feof(fp))
	{
		arr = fgetc(fp);
		switch(count)
		{
			case 1:
                arr == '\n'?0:strncat(b1[i].book_name,&arr, 1);
				break;

			case 2:
				arr == '\n'?0:strncat(b1[i].book_id, &arr, 1);
				break;

			case 3:
				arr == '\n'?0:strncat(b1[i].book_author, &arr, 1);
				break;
            case 4:
                arr == '\n'?0:(b1[i].book_quantity=arr-48);
                break;

		};
		arr=='\n'?count++:0;

		if(count > 4)
		{
			count = 1;
            total_number_book++;
			i++;
		}	
	}
	fclose(fp);

};