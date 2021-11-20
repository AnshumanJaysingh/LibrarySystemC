#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void returnfunc(void);
void adminmenu(void);
void usermenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void returnbooks(void);
void viewbooks(void);
int  getdata();
int  verifyid(int);

void password();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findbook;
char id_admin[10]={"admin"};
char pass_admin[10]={"admin"};

char id_fac[10]={"kghosh"};
char pass_fac[10]={"kripa"};

char id_user1[10]={"maj17ms054"};
char pass_user1[10]={"anshuman"};
char id_user2[10]={"na17ms026"};
char pass_user2[10]={"avni"};
char id_user3[10]={"a17ms063"};
char pass_user3[10]={"abhi"};
char id_user4[10]={"rk17ms213"};
char pass_user4[10]={"rudresh"};



/* struct database_user database[3];

database.id_user[0] = "user1";
database.pass_user[0] = "pass1";

database.id_user[1 = "user2";
database.pass_user[1] = "pass2";

database.id_user[2] = "user3";
database.pass_user[2] = "pass3";

database.id_user[3] = "user4";
database.pass_user[3] = "pass4"; */

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void box(int a,int b,int c,int d)      					// defining box function where a,b,c,d will take the 4 coordinates of the corners of the box
{	
	int i,j;
	for(i=a;i<c;i++)
	{
		gotoxy(i,b);printf("\xcd");                                      
		gotoxy(i,d);printf("\xcd");
	}
	for(j=b;j<d;j++)
	{
		gotoxy(a,j);printf("\xba");
		gotoxy(c,j);printf("\xba");
	}
		gotoxy(a,b);printf("\xc9");
		gotoxy(c,b);printf("\xbb");
		gotoxy(a,d);printf("\xc8");
		gotoxy(c,d);printf("\xbc");
}

struct Date
{
int mm,dd,yy;
};
int day, mon, year;

struct books
{
int id;
char name[20];
char author[20];
int quantity;
float price;
int count;
struct Date issued;
struct Date duedate;
};


struct books a;


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

void headMessage()
{
    system("cls");
    printf("\t\t\t|------------------------------------\  /----------------------------------|");
    printf("\n\t\t\t|                                   \/                                    |");
    printf("\n\t\t\t|                                   ||                                    |");
    printf("\n\t\t\t|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   ||   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    |");
    printf("\n\t\t\t|                                   ||                                    |");
    printf("\n\t\t\t|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   ||   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    |");
    printf("\n\t\t\t|                                   ||                                    |");
    printf("\n\t\t\t|                LIBRARY MANAGEMENT || SYSTEM PROJECT IN C                |");
    printf("\n\t\t\t|                                   ||                                    |");
    printf("\n\t\t\t|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   ||   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    |");
    printf("\n\t\t\t|                                   ||                                    |");
    printf("\n\t\t\t|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   ||   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    |");
    printf("\n\t\t\t|                                   /\                                    |");
    printf("\n\t\t\t|----------------------------------/  \-----------------------------------|\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                  LIBRARY                  =");
    printf("\n\t\t\t        =                MANAGEMENT                 =");
    printf("\n\t\t\t        =                  SYSTEM                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute(hConsoleOutput, 1000);
	getch();
    
}
int main()
{
time_t t;
t=time(NULL);
struct tm tm=*localtime(&t);
day=tm.tm_mday;
mon=tm.tm_mon;
year=tm.tm_year;
//headMessage();
//system("cls");
welcomeMessage();
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
SetConsoleTextAttribute(hConsoleOutput, 1000);
password();
getch();
return 0;
}

void adminmenu()
{

system("cls");
int i;
box(10,1,80,25);
gotoxy(27,3);
printf("ADMIN MAIN MENU ");

gotoxy(20,5);
printf(" 1. Add Books   ");
gotoxy(20,7);
printf(" 2. Delete Books");
gotoxy(20,9);
printf(" 3. Search Books");
gotoxy(20,11);
printf(" 4. View Book list");
gotoxy(20,13);
printf(" 5. Update Book's Record");
gotoxy(20,15);
printf(" 6. Close Application");
gotoxy(20,20);
printf("Enter your choice:");
switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
viewbooks();
break;
case '5':
editbooks();
break;
case '6':
{
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!! Please re-entered correct option");
if(getch())
adminmenu();
}

}
}

void usermenufac()
{

system("cls");
int i;
box(30,3,100,18);
gotoxy(60,5);
printf("FACULTY USER MAIN MENU ");

gotoxy(50,7);
printf(" 1. Issue Book   ");
gotoxy(50,9);
printf(" 2. Return Book");
gotoxy(50,11);
printf(" 3. View Book List");
gotoxy(50,13);
printf(" 4. Search Book");
gotoxy(50,15);
printf(" 5. Close Application");
gotoxy(50,17);
printf("Enter your choice:");
switch(getch())
{
case '1':
issuebooksfac();
break;
case '2':
returnbooksfac();
break;
case '3':
facviewbooks();
break;
case '4':
searchbooksuserfac();
break;
case '5':
{
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
usermenufac();
}

}
}


void usermenu()
{

system("cls");
int i;
box(30,3,100,18);
gotoxy(60,5);
printf("STUDENT USER MAIN MENU ");

gotoxy(50,7);
printf(" 1. Issue Book   ");
gotoxy(50,9);
printf(" 2. Return Book");
gotoxy(50,11);
printf(" 3. View Book List");
gotoxy(50,13);
printf(" 4. Search Book");
gotoxy(50,15);
printf(" 5. Close Application");
gotoxy(50,17);
printf("Enter your choice:");
switch(getch())
{
case '1':
issuebooks();
break;
case '2':
returnbooks();
break;
case '3':
userviewbooks();
break;
case '4':
searchbooksuser();
break;
case '5':
{
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
usermenu();
}

}
}


void addbooks(void)    //funtion that add books
{
system("cls");
int i;

system("cls");
fp=fopen("library_file.dat","ab+");
if(getdata()==1)
{
fseek(fp,0,SEEK_SET);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
adminmenu();
else
system("cls");
addbooks();
}
}


void deletebooks()   
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found, press any key to return");
if(getch())
adminmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
//fseek(ft,0,SEEK_CUR);
fseek(ft,sizeof(a)-ftell(ft)-1,sizeof(a)-ftell(ft));
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("library_file.dat");
rename("test.dat","library_file.dat"); //copy all item from temporary file to fp except that
fp=fopen("library_file.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
adminmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
adminmenu();
}


void searchbooksuser()
{
system("cls");
int d;
printf("Search Books");
gotoxy(20,10);
printf(" 1. Search By ID");
gotoxy(20,14);
printf(" 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("library_file.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("Search Books By Id");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s ",a.author);
gotoxy(20,12);
printf("Qantity:%d ",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooksuser();
else
usermenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("Search Books By Name");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s",a.author);
gotoxy(20,12);
printf("Quantity:%d",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
d++;
}

}
if(d==0)
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooksuser();
else
usermenu();
break;
}
default :
getch();
searchbooksuser();
}
fclose(fp);
}

void searchbooksuserfac()
{
system("cls");
int d;
printf("Search Books");
gotoxy(20,10);
printf(" 1. Search By ID");
gotoxy(20,14);
printf(" 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("library_file.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("Search Books By Id");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s ",a.author);
gotoxy(20,12);
printf("Qantity:%d ",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooksuserfac();
else
usermenufac();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("Search Books By Name");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s",a.author);
gotoxy(20,12);
printf("Quantity:%d",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
d++;
}

}
if(d==0)
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooksuserfac();
else
usermenufac();
break;
}
default :
getch();
searchbooksuserfac();
}
fclose(fp);
}

void searchbooks()
{
system("cls");
int d;
printf("Search Books");
gotoxy(20,10);
printf(" 1. Search By ID");
gotoxy(20,14);
printf(" 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("library_file.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("Search Books By Id");
gotoxy(20,5);
printf("Enter the book id:");
scanf("%d",&d);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s ",a.author);
gotoxy(20,12);
printf("Qantity:%d ",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
adminmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("Search Books By Name");
gotoxy(20,5);
printf("Enter Book Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available");
gotoxy(20,9);
printf("ID:%d",a.id);
gotoxy(20,10);
printf("Name:%s",a.name);
gotoxy(20,11);
printf("Author:%s",a.author);
gotoxy(20,12);
printf("Quantity:%d",a.quantity);
gotoxy(20,13);
printf("Price:Rs.%.2f",a.price);
d++;
}

}
if(d==0)
{
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchbooks();
else
adminmenu();
break;
}
default :
getch();
searchbooks();
}
fclose(fp);
}

void issuebooksfac(void)  
{
int t,d=0;
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("Issue Books");
gotoxy(10,6);
printf("Enter the Book Id:");
scanf("%d",&t);
fp=fopen("library_file.dat","rb+");
fs=fopen("Issue.dat","ab+");
if(verifyid(t)==0) 
{
	printf("Number of books you wish to issue(Avl quantity %d):",a.quantity);
	scanf("%d",&d);
if(d<=a.quantity)
{
gotoxy(10,8);
printf("The book record is available");
gotoxy(10,9);
printf("There are %d unissued books in library",a.quantity);
gotoxy(10,10);
printf("The name of book is %s",a.name);
if (a.quantity>0)
{
    a.quantity = a.quantity-d;
    fseek(fp,ftell(fp)-sizeof(a),0);
    fwrite(&a,sizeof(a),1,fp);
    gotoxy(10,12);
    printf("Issued date=%d-%d-%d",day,mon+1,year+1900);
    gotoxy(10,13);
    printf("The BOOK of ID %d is issued",a.id);
    a.duedate.dd=day+a.quantity*3;   //for return date
    a.duedate.mm=mon+1;
    a.duedate.yy=year+1900;
    if(a.duedate.dd>30)
    {
        a.duedate.mm+=a.duedate.dd/30;
        a.duedate.dd%=30;
        }
    
    if(a.duedate.mm>12)
    {
        a.duedate.yy+=a.duedate.mm/12;
        a.duedate.mm-=12;
        }
    gotoxy(10,14);
    printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
    fseek(fs,sizeof(a),SEEK_END);
    fwrite(&a,sizeof(a),1,fs);
    fclose(fs);
    c=1;

}
}
}
if(c==0 && d<=a.quantity)
{
gotoxy(10,11);
printf("No record found");
}
else if(c==0 && d>a.quantity)
{
	printf("Not enough copies to issue");
}
gotoxy(10,15);
printf("Issue any more(Y/N):");
fflush(stdin);
another=getche();
fclose(fp);
}
system("cls");
gotoxy(1,30);
printf(" Press ENTER to return to main menu");
a:
if(getch()==13) //allow only use of enter
usermenufac();
else
goto a;
}


void issuebooks(void)
{
int t,d;
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("Issue Books");
gotoxy(10,6);
printf("Enter the Book Id:");
scanf("%d",&t);
fp=fopen("library_file.dat","rb+");
fs=fopen("Issue.dat","ab+");
if(verifyid(t)==0) 
{
	printf("Number of books you wish to issue(Avl quantity %d)(Maximum limit %d):",a.quantity, min(2,a.quantity));
    scanf("%d",&d);
	if(d<3)
	{
gotoxy(10,8);
printf("The book record is available");
gotoxy(10,9);
printf("There are %d unissued books in library",a.quantity);
gotoxy(10,10);
printf("The name of book is %s",a.name);

if (a.quantity>=3)
{
    a.quantity = a.quantity-d;
    fseek(fp,ftell(fp)-sizeof(a),0);
    fwrite(&a,sizeof(a),1,fp);
    gotoxy(10,12);
    printf("Issued date=%d-%d-%d",day,mon+1,year+1900);
    gotoxy(10,13);
    printf("The BOOK of ID %d is issued",a.id);
    a.duedate.dd=day+a.quantity*3;   //for return date
    a.duedate.mm=mon+1;
    a.duedate.yy=year+1900;
    if(a.duedate.dd>30)
    {
        a.duedate.mm+=a.duedate.dd/30;
        a.duedate.dd%=30;
        }
    
    if(a.duedate.mm>12)
    {
        a.duedate.yy+=a.duedate.mm/12;
        a.duedate.mm-=12;
        }
    gotoxy(10,14);
    printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
    fseek(fs,sizeof(a),SEEK_END);
    fwrite(&a,sizeof(a),1,fs);
    fclose(fs);
    c=1;

}
}
}
if(c==0 && d<3)
{
gotoxy(10,11);
printf("Student not allowed to issue this book due to less copies");
}
else
printf("maximum limit exceeded");
gotoxy(10,15);
printf("Issue any more(Y/N):");
fflush(stdin);
another=getche();
fclose(fp);
}
system("cls");
gotoxy(1,30);
printf(" Press ENTER to return to main menu");
a:
if(getch()==13) //allow only use of enter
usermenu();
else
goto a;
}

void returnbooksfac(void)
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to return:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found, press any key to return");
if(getch())
usermenufac();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to return it?(Y/N):");
if(getch()=='y')
{
ft=fopen("returnfac.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,sizeof(a)-ftell(ft)-1,sizeof(a)-ftell(ft));
fwrite(&a,sizeof(a),1,ft); 
}                          
else
{
fseek(ft,sizeof(a)-ftell(ft)-1,sizeof(a)-ftell(ft));
a.quantity++;
fwrite(&a,sizeof(a),1,ft);	
}
}
fclose(ft);
fclose(fp);
remove("library_file.dat");
rename("returnfac.dat","library_file.dat"); //copy all item from temporary file to fp except that
fp=fopen("library_file.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("Return successful");
gotoxy(10,11);
printf("Return another book?(Y/N)");
}
}
else
usermenufac();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
usermenufac();
}


void returnbooks(void)
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Book ID to return:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The book record is available");
gotoxy(10,8);
printf("Book name is %s",a.name);
findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found, press any key to return");
if(getch())
usermenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to return it?(Y/N):");
if(getch()=='y')
{
ft=fopen("return.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
//fseek(ft,0,SEEK_CUR);
fseek(ft,sizeof(a)-ftell(ft)-1,sizeof(a)-ftell(ft));
fwrite(&a,sizeof(a),1,ft); 
}                          
else
{
fseek(ft,sizeof(a)-ftell(ft)-1,sizeof(a)-ftell(ft));
a.quantity++;
fwrite(&a,sizeof(a),1,ft);	
}
}
fclose(ft);
fclose(fp);
remove("library_file.dat");
rename("return.dat","library_file.dat"); //copy all item from temporary file to fp except that
fp=fopen("library_file.dat","rb+");    //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("Return successful");
gotoxy(10,11);
printf("Return another book?(Y/N)");
}
}
else
usermenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
usermenu();
}
void userviewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("===================Book List=====================");
gotoxy(2,2);
printf(" ID    BOOK NAME     AUTHOR       QTY     PRICE ");
j=4;
fp=fopen("library_file.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(1,j);
printf("%d",a.id);
gotoxy(12,j);
printf("%s",a.name);
gotoxy(26,j);
printf("%s",a.author);
gotoxy(40,j);
printf("%d",a.quantity);
gotoxy(47,j);
printf("%.2f",a.price);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc1();
}

void facviewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("===================Book List=====================");
gotoxy(2,2);
printf(" ID    BOOK NAME     AUTHOR       QTY     PRICE ");
j=4;
fp=fopen("library_file.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(1,j);
printf("%d",a.id);
gotoxy(12,j);
printf("%s",a.name);
gotoxy(26,j);
printf("%s",a.author);
gotoxy(40,j);
printf("%d",a.quantity);
gotoxy(47,j);
printf("%.2f",a.price);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc2();
}


void viewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("===================Book List=====================");
gotoxy(2,2);
printf(" ID    BOOK NAME     AUTHOR       QTY     PRICE ");
j=4;
fp=fopen("library_file.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(1,j);
printf("%d",a.id);
gotoxy(12,j);
printf("%s",a.name);
gotoxy(26,j);
printf("%s",a.author);
gotoxy(40,j);
printf("%d",a.quantity);
gotoxy(47,j);
printf("%.2f",a.price);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}

void editbooks(void)  //Update information about book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("Update Books Section");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be Updateed:");
scanf("%d",&d);
fp=fopen("library_file.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(verifyid(d)==0)
{
gotoxy(15,7);
printf("The book is availble");
gotoxy(15,8);
printf("The Book ID:%d",a.id);
gotoxy(15,9);
printf("Enter new name:");scanf("%s",a.name);
gotoxy(15,10);
printf("Enter new Author:");scanf("%s",a.author);
gotoxy(15,11);
printf("Enter new quantity:");scanf("%d",&a.quantity);
gotoxy(15,12);
printf("Enter new price:");scanf("%f",&a.price);
gotoxy(15,14);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}

void returnfunc2(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //to allow only use of enter
usermenufac();
else
goto a;
}


void returnfunc1(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //to allow only use of enter
usermenu();
else
goto a;
}

void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //to allow only use of enter
adminmenu();
else
goto a;
}


int getdata()
{
int t;
gotoxy(20,3);
printf("Enter the Information Below\n");
gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(verifyid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a");
getch();
adminmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Book Name:");gotoxy(33,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Author:");gotoxy(30,8);
scanf("%s",a.author);
gotoxy(21,9);
printf("Quantity:");gotoxy(31,9);
scanf("%d",&a.quantity);
gotoxy(21,10);
printf("Price:");gotoxy(28,10);
scanf("%f",&a.price);
gotoxy(21,11);
return 1;
}


int verifyid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}

void password(void) 
{

system("cls");
char ch,pass[10];
char username[20];
int i=0,j,iter=0;

box(10,6,80,21);
gotoxy(15,7);
printf("Enter Username: ");
scanf("%s",username);
gotoxy(15,9);
printf("Enter Password: ");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';

if((strcmp(pass,pass_admin)==0)&&(strcmp(username,id_admin)==0))
{

system("cls");
gotoxy(17,9);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
adminmenu();
}

if((strcmp(username,id_user1)==0)&&(strcmp(pass,pass_user1)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenu();
}
if((strcmp(username,id_user2)==0)&&(strcmp(pass,pass_user2)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenu();
}
if((strcmp(username,id_user3)==0)&&(strcmp(pass,pass_user3)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenu();
}
if((strcmp(username,id_user4)==0)&&(strcmp(pass,pass_user4)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenu();
}
if((strcmp(username,id_fac)==0)&&(strcmp(pass,pass_fac)==0))
{   
    system("cls");
    gotoxy(17,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to continue.....");
    getch(); //conio.h in windows wont work in linux
    usermenufac();
}

else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Username or password");
getch();
password();
}
}
