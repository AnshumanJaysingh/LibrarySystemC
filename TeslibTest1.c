#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "AticleworldLibBookS.bin"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
typedef struct// to call in program
{
    unsigned int books_id; // declare the integer data type
    char bookName[MAX_BOOK_NAME];// declare the character data type
    char authorName[MAX_AUTHOR_NAME];// declare the charecter data type
    char studentName[MAX_STUDENT_NAME];// declare the character data type
    char studentAddr[MAX_STUDENT_ADDRESS];// declare the character data type
    Date bookIssueDate;// declare the integer data type
} s_BooksInfo;
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
// Add books in list
void addBookInDataBase()
{
    int days;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tBook ID NO  = ");
    fflush(stdin);
    scanf("%u",&addBookInfoInDataBase.books_id);
    do
    {
        printf("\n\t\t\tBook Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tAuthor Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName,MAX_AUTHOR_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName,MAX_STUDENT_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
        //check date validity
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
}
// search books
void searchBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH BOOKS");
    //put the control on books detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Book Name to search:");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tBook id = %u\n",addBookInfoInDataBase.books_id);
        printf("\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}
// v books function
void viewBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
    headMessage("VIEW BOOKS DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n",countBook);
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// delete function
void deleteBooks()
{
    int found = 0;
    int bookDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;
    headMessage("Delete Books Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%d",&bookDelete);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(addBookInfoInDataBase.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\ttLogin Again:");
    fflush(stdin);
    getchar();
    exit(1);
}
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addBookInDataBase();
            break;
        case 2:
            searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
//login password
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="aticleworld\n";
    const char defaultPassword[] ="aticleworld\n";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
int enterkey(){
	int c; // not char c, to accomodate EOF
	int first_char;
	int is_first_char = 1;
	while ((c = getchar()) != '\n' && c != EOF){
		if (is_first_char == 1){
			first_char = c;
			is_first_char = 0;
		}
	}
	return first_char;
}

void booksrch(){
	system("cls");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to Search Book! \xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,6);
	printf("1. Search by Call ID");
	gotoxy(20,8);
	printf("2. Search by Book Name");
	gotoxy(20,10);
	printf("3. Search by Author\n");
	gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,14);
	printf("Enter your choice.......");
	char choice = enterkey();
	/**************************/
	/* If anything other than 1 or 2 is entered, then error */
	if (choice < '1' || choice > '3'){
		gotoxy(20,16);
		printf("It's an Invalid key!'... Press Enter to continue...");
		enterkey();
		return ;
	}
	else if (choice == '1'){
		/* Option 1: Search by Call ID */
		gotoxy(20,16);
		printf("Search by Call ID");
		gotoxy(20,17);
		printf("The Call ID needs to be exact.");
		char callid[6];
		gotoxy(20,18);
		printf("Enter your 5 digit Call ID: ");
		strinp(callid, 5);
		if (vldt_dgtstr(callid, 5) == 0){
			gotoxy(20,19);
			printf("Invalid Call ID!");
			gotoxy(20,20);
			printf("It should contains 5 digits only");
			getch();
			return ;
		}
		crfbooksrch(callid, 1);
		FILE *fsearch = fopen("tmp/searchout.txt", "r");
		// The columns will be callid, bookname, authors and number of available copies
		int widths[] = {9, 58, 33, 7, 11, 8, 11};
		char heading[100];
		sprintf(heading, "Showing search results for Call ID '%s'", callid);
		fdisp(fsearch, 7, widths, heading);
		fclose(fsearch);
		remove("tmp/searchout.txt");
	}
	else if (choice == '2'){
		/* Option 2: Search by Book Name */
		gotoxy(20,16);
		printf("Search by Book Name");
		gotoxy(20,17);
		printf("you can search by characters in book name.");
		gotoxy(20,18);
		printf("For example, to search for 'Basics of C language', you can enter 'basics'.");
		gotoxy(20,19);
		printf("Enter (Book Name) search term (50 characters max): ");
		char searchterm[51];
		strinp(searchterm, 50);
		crfbooksrch(searchterm, 2);
		FILE *fsearch = fopen("tmp/searchout.txt", "r");
		// The columns will be callid, bookname, authors and number of available copies
		int widths[] = {9, 58, 33, 7, 11, 8, 11};
		char heading[100];
		sprintf(heading, "Showing search results for Book Name '%s'", searchterm);
		fdisp(fsearch, 7, widths, heading);
		fclose(fsearch);
		remove("tmp/searchout.txt");
	}
	else if (choice == '3'){
		/* Option 3: Search by Author/s */
		gotoxy(20,16);
		printf("Search by Author/s");
		gotoxy(20,17);
		printf("You can search by characters in author/s name.");
		gotoxy(20,19);
		printf("Enter (Author/s) search term (50 characters max): ");
		char searchterm[51];
		strinp(searchterm, 50);
		crfbooksrch(searchterm, 3);
		FILE *fsearch = fopen("tmp/searchout.txt", "r");
		// The columns will be callid, bookname, authors and number of available copies
		// Adjust widths according to it
		int widths[] = {9, 58, 33, 7, 11, 8, 11};
		char heading[100];
		sprintf(heading, "Showing search results for Author/s '%s'", searchterm);
		fdisp(fsearch, 7, widths, heading);
		fclose(fsearch);
		remove("tmp/searchout.txt");
	}
	return ;
}
void issuebook(char username[]){
	system("cls");
	gotoxy(35,5);
	printf(" Issue Book");
	gotoxy(25,7);
	printf("Enter Call ID book to issue: ");
	/************************************/
	/* Get callid */
	char callid[6];
	strinp(callid, 5);
	// If callid input invalid, then error
	if (vldt_dgtstr(callid, 5) == 0){
		gotoxy(25,8);
		printf("Invalid Call ID!");
		gotoxy(25,9);
		printf("Should be of length 5 containing only digits! Press Enter to continue...");
		enterkey();
		return ;
	}
	/**************************/
	/* Open file pointers */
	FILE *fbooks = fopen("data/books_info.txt", "r");
	FILE *fbooks_tmp = fopen("tmp/books_tmp.txt", "w");
	/**************************/
	/* Get and put the header */
	char row[3000];
	fgets(row, 3000, fbooks);
	fputs(row, fbooks_tmp);
	/**************************/
	/* Check if callid entered exists */
	char exist_callid[6];
	int found = 0;
	while (fgets(row, 3000, fbooks) != NULL){
		rowele_extrxt(exist_callid, row, 1);
		if (strcmp(callid, exist_callid) == 0){
			found = 1;
			break;
		}
		// Keep on putting rows in books_tmp until callid is found (matching row not put yet)
		fputs(row, fbooks_tmp);
	}
	/**************************/
	/* If callid not found, then error */
	if (found == 0){
		gotoxy(25,8);
		printf("Call ID not found! Press Enter to continue...");
		fclose(fbooks);
		fclose(fbooks_tmp);
		remove("tmp/books_tmp.txt");
		enterkey();
		return ;
	}
	/**************************/
	/* If given callid is found */
	// Extract all info from required row
	printf("\nBook Found!");
	printf("\n-----------");
	char bookname[1001];
	char authors[1001];
	char copynos[201];
	char ref[201];
	char issue[201];
	rowele_extrxt(bookname, row, 2);
	rowele_extrxt(authors, row, 3);
	rowele_extrxt(copynos, row, 4);
	rowele_extrxt(ref, row, 5);
	rowele_extrxt(issue, row, 6);
	// Display Book Name, Author/s, Existing Copies, Reference Copies
	printf("\nBook Name: %s", bookname);
	printf("\nAuthor/s: %s", authors);
	printf("\nExisting Copy Numbers: ");
	dispconcat(copynos, 2);
	printf("\nReference Copies: ");
	dispconcat(ref, 2);
	printf("\nIssued Copies: ");
	dispconcat(issue, 2);
	/**************************/
	FILE *fusers = fopen("data/users_login.txt", "r");
	FILE *fusers_tmp = fopen("tmp/users_tmp.txt", "w");
	/**************************/
	/* Get and put the header */
	fgets(row, 3000, fusers);
	fputs(row, fusers_tmp);
	/**************************/
	char exist_username[51];
	while (fgets(row, 3000, fusers) != NULL){
		rowele_extrxt(exist_username, row, 1);
		if (strcmp(exist_username, username) == 0){
			// This username will always be found because it will be called by the logged in user
			break;
		}
		fputs(row, fusers_tmp);
	}
	// If a copy of book already issued,  or if five books already isseud then error
	char password[51];
	char name[101];
	char type[2];
	char issued_callids[MAXISSUE*5+1];
	char issued_copies[MAXISSUE*2+1];
	char issued_ons[MAXISSUE*8+1];
	rowele_extrxt(password, row, 2);
	rowele_extrxt(name, row, 3);
	rowele_extrxt(type, row, 4);
	rowele_extrxt(issued_callids, row, 5);
	rowele_extrxt(issued_copies, row, 6);
	rowele_extrxt(issued_ons, row, 7);
	// If a copy of the book already issued by user, then error
	if (mtchconcat(callid, issued_callids) != 0){
		printf("\n\nA copy of the book is already issued by user %s! Cannot issue book...", username);
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// If 5 books issued by user, then error
	if (strlen(issued_callids) == MAXISSUE * 5){ // since 5 is the length of callids
		printf("\n\nMax issueable books (5) reached by user %s! Cannot issue book...", username);
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// Now check the total number of issueable copies (not currently issueable, just issueable i.e. total-reference)
	// If issueable copies <= 3, allow issue only if type faculty
	if ((strlen(copynos) - strlen(ref))/2 <= 3 && strcmp(type, "S") == 0){
		printf("\n\nSorry. Only 3 issueable copies! Only faculties can issue! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// If number of copies left (except for reference copies) is 0, then error
	if ((strlen(copynos) - strlen(ref) - strlen(issue)) == 0){
		printf("\n\nSorry, No Copies Left! ;-( Please try later...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// Now ask for copy number which user wants to take
	char to_issue[3];
	printf("\n\nEnter copy number to issue: ");
	strinp(to_issue, 2);
	if (vldt_dgtstr(to_issue, 2) == 0){
		printf("\n\nInvalid Copy Number! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// If asked copy doesnt exist
	if (mtchconcat(to_issue, copynos) == 0){
		printf("\n\nCopy not found! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// If asked copy is already issued (by another user)
	if (mtchconcat(to_issue, issue) != 0){
		printf("\n\nCopy already issued by another user! Cannot be issued! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// If asked copy is a reference copy
	if (mtchconcat(to_issue, ref) != 0){
		printf("\n\nIt's a Reference Copy! Cannot be issued! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// Ask for current date (NOT IDEAL)
	char date[9];
	printf("Enter issue date (Warning: Incorrect information can lead to temporary suspension of library facilities) (ddmmyyyy): ");
	strinp(date, 8);
	if (vldt_dgtstr(date, 8) == 0){
		printf("\n\n Date Format is Incorrect! Press Enter to continue...");
		enterkey();
		fclose(fbooks);
		fclose(fbooks_tmp);
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/books_tmp.txt");
		remove("tmp/users_tmp.txt");
		return ;
	}
	// Now if everything is fine, add to issue in books_info.txt and add to issued_callid, issued_copies, issued_on in users_login.txt
	append(issue, to_issue);
	fprintf(fbooks_tmp, "%s|%s|%s|%s|%s|%s|\n", callid, bookname, authors, copynos, ref, issue);
	while (fgets(row, 3000, fbooks) != NULL){
		fputs(row, fbooks_tmp);
	}
	append(issued_callids, callid);
	append(issued_copies, to_issue);
	append(issued_ons, date);
	fprintf(fusers_tmp, "%s|%s|%s|%s|%s|%s|%s|\n", username, password, name, type, issued_callids, issued_copies, issued_ons);
	while (fgets(row, 3000, fusers) != NULL){
		fputs(row, fusers_tmp);
	}
	printf("\n\nBook has been Issued to you Successfully!! Press Enter to continue...");
	enterkey();
	fclose(fbooks);
	fclose(fbooks_tmp);
	fclose(fusers);
	fclose(fusers_tmp);
	remove("data/books_info.txt");
	remove("data/users_login.txt");
	rename("tmp/books_tmp.txt", "data/books_info.txt");
	rename("tmp/users_tmp.txt", "data/users_login.txt");
	return ;
}

void returnbook(char username[]){
	system("cls");
	gotoxy(35,5);
	printf("Book Return");
	gotoxy(25,7);
	usrinfo(username, 0, 0);
	printf("\n\nEnter Call ID of book to return: ");
	char callid[6];
	strinp(callid, 5);
	FILE *fusers = fopen("data/users_login.txt", "r");
	FILE *fusers_tmp = fopen("tmp/users_tmp.txt", "w");
	char row[3000];
	/* Get and put header */
	fgets(row, 3000, fusers);
	fputs(row, fusers_tmp);
	/***********************/
	char exist_username[51];
	while (fgets(row, 3000, fusers) != NULL){
		rowele_extrxt(exist_username, row, 1);
		if (strcmp(exist_username, username) == 0){
			break;
		}
		fputs(row, fusers_tmp);
	}
	char password[51];
	char name[101];
	char type[2];
	char issued_callids[MAXISSUE*5+1];
	char issued_copies[MAXISSUE*2+1];
	char issued_ons[MAXISSUE*8+1];
	rowele_extrxt(password, row, 2);
	rowele_extrxt(name, row, 3);
	rowele_extrxt(type, row, 4);
	rowele_extrxt(issued_callids, row, 5);
	rowele_extrxt(issued_copies, row, 6);
	rowele_extrxt(issued_ons, row, 7);
	int index = mtchconcat(callid, issued_callids);
	if (index == 0){
		printf("\n\n This book is not issued by you.\nYou can not return this book! Press Enter to continue...");
		enterkey();
		fclose(fusers);
		fclose(fusers_tmp);
		remove("tmp/users_tmp.txt");
		return ;
	}
	char new_issued_callids[MAXISSUE*5+1];
	char new_issued_copies[MAXISSUE*2+1];
	char new_issued_ons[MAXISSUE*8+1];
	esconcat(issued_callids, new_issued_callids, 5, index);
	esconcat(issued_copies, new_issued_copies, 2, index);
	esconcat(issued_ons, new_issued_ons, 8, index);
	fprintf(fusers_tmp, "%s|%s|%s|%s|%s|%s|%s|\n", username, password, name, type, new_issued_callids, new_issued_copies, new_issued_ons);
	char skip_copy[3];
	concatindex(skip_copy, issued_copies, 2, index);
	while (fgets(row, 3000, fusers) != NULL){
		fputs(row, fusers_tmp);
	}
	FILE *fbooks = fopen("data/books_info.txt", "r");
	FILE *fbooks_tmp =fopen("tmp/books_tmp.txt", "w");
	/* Get and put header */
	fgets(row, 3000, fbooks);
	fputs(row, fbooks_tmp);
	/***********************/
	char exist_callid[6];
	while (fgets(row, 3000, fbooks) != NULL){
		rowele_extrxt(exist_callid, row, 1);
		if (strcmp(exist_callid, callid) == 0){
			break;
		}
		fputs(row, fbooks_tmp);
	}
	char bookname[1001];
	char authors[1001];
	char copynos[201];
	char ref[201];
	char issue[201];
	rowele_extrxt(bookname, row, 2);
	rowele_extrxt(authors, row, 3);
	rowele_extrxt(copynos, row, 4);
	rowele_extrxt(ref, row, 5);
	rowele_extrxt(issue, row, 6);
	char newissue[201];
	ecpcopy(issue, newissue, skip_copy);
	fprintf(fbooks_tmp, "%s|%s|%s|%s|%s|%s|\n", callid, bookname, authors, copynos, ref, newissue);
	while (fgets(row, 3000, fbooks) != NULL){
		fputs(row, fbooks_tmp);
	}
	printf("\n\nYour Book returned successfully!! Press Enter to continue...");
	enterkey();
	fclose(fusers);
	fclose(fusers_tmp);
	fclose(fbooks);
	fclose(fbooks_tmp);
	remove("data/books_info.txt");
	rename("tmp/books_tmp.txt", "data/books_info.txt");
	remove("data/users_login.txt"); 
	rename("tmp/users_tmp.txt", "data/users_login.txt");
	return ;
}

int main()
{
    init();
    welcomeMessage();
    login();
    return 0;
}
