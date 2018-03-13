
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
#define ESC 27
#define Gold 14
#define Blue 11
#define White 15
#define Time time(NULL)
#define Pink 13
#define Green 10
#define File FILE
#define Red 4

void textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

//num to string
void toString(char* str, int num, int numOfElement){
	int count = 0, digit[numOfElement];
	while (num != 0){
		digit[count] = num % 10;
		num = num / 10;
		count++;
	}
	
	count--;
	
	while (count >= 0) {
		*str = digit[count] + 48;
		str++;
		count--;
	}
}

struct library
{
	char codeBook[100];
	char nameBook[100];
	char cateBook[100];
	char estabBook[100];
	char quanBook[100];
	char quanAvaiBook[100];
	char userRec[100];
	char userPassword[100];
	
	char strCode[100];
	char stuCode[100];
	int newOrOld;
	int id;
	int maxStruct;
	int adminOrUser;
};
	struct library viewBooksInfo[1999];
	
struct borrowingList
{
	char codeBook[100];
	char nameBook[100];
	char cateBook[100];
	char estabBook[100];
	char quanBook[100];
	char quanAvaiBook[100];
	char bday[100];
	char bmonth[100];
	char byear[100];
	char rday[100];
	char rmonth[100];
	char ryear[100];
	char status[100];
	long deadline;
};

struct borrowingList historyOfBorrowing[799];
//viewBooksInfo[0].stuCode, viewBooksInfo[0].newOrOld, viewBooksInfo[0].id, viewBooksInfo[0].maxStruct

void makeLine(unsigned short max);
void makeTab(int unsigned max);
void menuOfUser(int id, char stuCode[100]);


void backTitle()
{
	printf("\n\n\n\t  ");
	textColor(Green);
	printf("<Press Esc to Back]");
	textColor(White);
}

void trouble()
{
	printf("\n\n\n");
	printf("\t\tIf you get trouble press Esc to back or Tab to reset\n");
}

struct bookRent {
	char userName[9];
	char title[501];
	int returnStatus;
	int day;
	int month;
	int year;
	int dayEnd;
	int monthEnd;
	int yearEnd;
	int codeRent;
	int dayReturn;
	int monthReturn;
	int yearReturn;
	char category[101];
	int yearEstablished;
};

struct bookRent rent[2000];

struct books {
	char name[501]; //name of the book
	char category[101]; // category of the book
	char year[5]; //year established
	char quanlity[5]; // total number of book
	char quanlityAvaiable[5]; // number book is still avaiable
	char term[501];//to sort
	int code;//code of book
	
	char strCode[100];
};
//declare info
struct books book[1200];

void drawLine(int max)//make-------line
{
	int i = 0;
	
	for (i = 0; i < max; i++)
	{
		printf("-");
	}
	
	printf("\n");
} // end of drawLine function


//print menu search status
void printMenuSearchStatus() {
	//system("cls");
	textColor(14);
	//printf("\n\n\n\n\t\tChoose your requirement\n ");
	printf("\n\n");
	textColor(Gold);
	printf("\t\t");
	drawLine(35);
	textColor(15);
	printf("\t\t1. Search by title.\n");
	printf("\t\t2. Search by year established.\n");
	printf("\t\t3. Search by category.\n");
	printf("\t\t4. Back.\n");
	printf("\t\t5. Exit.\n");
}

//print menu book info
void printMenuBookInfo(){
	textColor(14);//yellow
	//printf("\n\n\t\tChoose your requirement\n ");
	//textColor(11);//blue
	printf("\t\t");
	drawLine(24);//----------
	textColor(15);
	printf("\t\t1. Search Info.\n");
	printf("\t\t2. Arrange Info.\n");
	printf("\t\t3. Add Info.\n");
	printf("\t\t4. Delete Info.\n");
	printf("\t\t5. Edit Info.\n");
//	printf("\t\t6. Print all books.\n");
	printf("\t\t6. Back.\n");
	printf("\t\t7. Exit.\n");
	textColor(Gold);
	printf("\t\t");
	drawLine(24);//----------
	textColor(White);
}

//get positive integer number
int getIntNum(){
	int temp, num;
	char term;
	
	do {
		fflush(stdin);
		temp = scanf("%d%c", &num, &term);
		if (temp != 2 || term != '\n' || num <= 0) 
		printf("\t\tError. Input Again\n\t\t");
	} while (temp != 2 || term != '\n' || num <= 0);
	
	return num;
}

//get choice from user
int getChoice(int max){
	int choice, temp;
	char term;
	
	do {
		fflush(stdin);
		temp = scanf("%d%c", &choice, &term);
		if (temp != 2 || term != '\n' || choice < 1 || choice > max){
		textColor(4);
			printf("\t\tWrong!!\n");
			textColor(14);
			//printf("\t\tYour requirement is: ");
			printf("\t\tYour requirement is: ");
			textColor(15);
		}
	} while (temp != 2 || term != '\n' || choice < 1 || choice > max);
	return choice;
}

//get Yes or No
char getYesNo(){
	char input[2];
	do {
		fflush(stdin);
		scanf("%s", input);

		if (input[1] != '\0' ||( input[0] != 'n' && input[0] != 'N'
							  && input[0] != 'y' && input[0] != 'Y'))
		printf("\t\tError Input! Again!\n\t\t\t\t");
		
	} while (input[1] != '\0' ||( input[0] != 'n' && input[0] != 'N'
							   && input[0] != 'y' && input[0] != 'Y'));
							 
	return input[0];
}

//print short form of a string longer than "max" characters
void printInShort(char* str, int max){
	int count = 0;

	while (count < (max - 6)) {
		printf("%c", *str);
		str++;
		count++;
	}
	printf("...");
}

int printTitle(int check){

	if (check) {
		int i;
		printf("\n\t\tCode ");//5
		for (i = 0; i < 5; i++) printf(" "); //old is 10
		
		printf("Name of Book ");//13
		for (i = 0; i < 24; i++) printf(" "); // oild is 27
		
		printf("Category ");//9
		for (i = 0; i < 11; i++) printf(" "); // old is 21
		
		printf("Year Established ");//17
		for (i = 0; i < 6; i++) printf(" "); //old is 13
		
		printf("Quanlity ");//9
		for (i = 0; i < 5; i++) printf(" "); //old is 11
		
		printf("Number on bookself ");//19
		for (i = 0; i < 6; i++) printf(" ");
		
		printf("Number of lending \n");//18
	}
	return 0; //return to prevent print many times.	
}

//print line
int printLine(int check){
	if (check){
		int i;
		printf("\t\t");
		for (i = 0; i < 150; i++) printf("-"); // old is 165
		printf("\n");
	}
	return 1;
}

//import title
int importName(){
	int i = 0;
	
	FILE *f = fopen("Title.txt", "r");
	while (!feof(f)){
		fscanf(f, "%[^\n]%*c", book[i].name);
		if (strlen(book[i].name) != 0) i++;
	}

	return i; // return quanlity of name of book
	fclose(f);
}

//export title
void exportName(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("Title.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%s", book[i].name);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import category
void importCate(){
	int i = 0;
	FILE* f = fopen("Cate.txt", "r");
	while (!feof(f)){
		fscanf(f, "%[^\n]%*c", book[i].category);
		i++;
	} 
	fclose(f);
}

//export category
void exportCate(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("Cate.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%s", book[i].category);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import book's code
void importBookCode(){
	int i = 0;
	
	FILE* f = fopen("BookCode.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &book[i].code);
		i++;
	} 
	fclose(f);
}

//export book's code
void exportBookCode(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("BookCode.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%d", book[i].code);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);	
}

//import quanlity
void importQuanlity(){
	int i = 0;
	
	FILE* f = fopen("Quanlity.txt", "r");
	while (!feof(f)){
		fscanf(f, "%[^\n]%*c", book[i].quanlity);
		i++;
	} 
		
	fclose(f);
}

//export quanlity
void exportQuanlity(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("Quanlity.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%s", book[i].quanlity);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import quanlity avaiable
void importQuanlityAvaiable(){
	int i = 0;
	
	FILE* f = fopen("QuanlityAvai.txt", "r");
	while (!feof(f)){
		fscanf(f, "%[^\n]%*c", book[i].quanlityAvaiable);
		i++;
	} 
	fclose(f);
}

//export quablity avaiable
void exportQuanlityAvaiable(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("QuanlityAvai.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%s", book[i].quanlityAvaiable);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import year establishes
void importYear(){
	int i = 0;
	FILE* f = fopen("YearEstab.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%[^\n]%*c", book[i].year);
		i++;
	}
	fclose(f);
}

//export year
void exportYear(int numOfBook, int newStatus, int editStatus){
	int i = 0;

	FILE *f = fopen("YearEstab.txt", "w");

	for (i = 0; i < numOfBook + newStatus; i++){
		fprintf(f, "%s", book[i].year);
		if (editStatus) {
			if (i != (numOfBook - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfBook) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//get string from user
int getStringIn(char* strIn, int max, int numberMode){
	//number mode: 1 -> yes
	//			   0 -> no
	int check;
	char* temp = strIn;//default address of array
	do {
		strIn = temp;//restart address of array
		check = 0;
		fflush(stdin);
		gets(strIn);
		if (numberMode == 1) {
			while (*strIn != '\0') {
				if (*strIn < '0' || *strIn > '9') {
					printf("\t\tYou must input positive number. Input again\n\t\t");
					check = 1;
					break;
				} else strIn++;
			}
		}
	} while (check != 0);
	
	int count = 0;//to check number of charater
	strIn = temp; //restart address of array
	while (*strIn != '\0'){
		count++;
		if (count > max) {
			*strIn = '\0';
			printf("\t\tYou must input lower than %d character.", max);
			printf("\n\t\tWhat your input is saved is %s", temp);
			printf("\n\t\tEnter: Y - approve.");
			printf("\n\t\tEnter: N - input again.");
			printf("\n\t\tYour choice: ");
			char yesNo = getYesNo();
			
			if (yesNo == 'y' || yesNo == 'Y') return 1;
			return 0;
		}
		strIn++;
	}
	return 1;
}

//initialize
void initialize(char* orgin, char* son){
	if (strlen(orgin) >= strlen(son)) {
		while (*orgin != '\0') {
			*son = *orgin;
			son++;
			orgin++;
		}
	} else {
		while (*son != '\0') {
			*son = *orgin;
			son++;
			orgin++;
		}	
	} 
}




//upper case
void toUpper(char* str){
	do {
		*str = toupper(*str);
		str++;
	} while (*str != '\0');
}

//transform char to num
int toNum(char* str){
	int count = 0;
	int digit[5];
	int num = 0;
	int temp = 0;
	
	while (*str != '\0'){
		digit[count] = *str - 48;
		count++;
		str++;
	}
	count--;
	while (count >= 0){
		num += digit[count] * pow(10,temp);
		count--;
		temp++;
	}
	return num;
}

//str1 is the input
//str2 is the ordinary
int isMatchEachCha(char* str1, char* str2){
	int count = 0;
	char* term = str1; 
	
	if (strcmp(str1, str2) == 0) return 1;
	else {
		while (*str1 != '\0'){
			if (*str1 == *str2) {
				count++;
				str1++;
				str2++;	
			} else break;
		} 
		if (count == strlen(term)) return 1;
		else return 0;
	}
}

//calculate length of number
/*int calNumLen(int num){
	int length = 0;
	while (num != 0) {
		length += (num % 10);
		num = num / 10;
	}
	return length;
}*/

//print book info
void printInfo(int* check, int* check2, int i){
	*check = printTitle(*check);//print title
	*check2 = printLine(*check2);//print line
	
	int j;
	
	printf("\t\t%4d", book[i].code); // old is tab not 3 spaces
	for (j = 0; j < (10- 4); j++) printf(" "); // old is 15 not 10
	
	if (40 >= strlen(book[i].name)) {
		printf("%s", book[i].name);
		for (j = 0; j < (39 - strlen(book[i].name)); j++) printf(" "); // old is 40 not 39
	} else {
		printf("\t\t");
		printInShort(book[i].name, 40);
		printf("   ");
	}
	
	if (35 >= strlen(book[i].category)) {
		printf("%s", book[i].category);
		for (j = 0; j < (25 - strlen(book[i].category)); j++) printf(" ");	// old is 35
	} else {
		printInShort(book[i].category, 35);
		printf("   ");
	}
	
	printf("%s", book[i].year);
	for (j = 0; j < (20 - strlen(book[i].year)); j++) printf(" "); // old is 28 
	
	printf("%s", book[i].quanlity);
	for (j = 0; j < (19 - strlen(book[i].quanlity)); j++) printf(" "); //old is 24
	
	printf("%s", book[i].quanlityAvaiable);
	for (j = 0; j < (23 - strlen(book[i].quanlityAvaiable)); j++) printf(" "); // old is 25
	
	printf("%d\n", (toNum(book[i].quanlity) - toNum(book[i].quanlityAvaiable)));
	
//	if (codeStatus) {
		
//	}
}

void printYesNo(){
	printf("\t\t\tEnter: Y - Yes\t");
	printf("\tEnter: N - No\n\t\t\t");
}

void importValue(int* numOfBook){
	*numOfBook = importName();
	importCate();
	importQuanlity();
	importQuanlityAvaiable();
	importYear();	
	importBookCode();
}

//export
void exportValue(int numOfBook, int newStatus, int editStatus){
	exportCate(numOfBook, newStatus, editStatus);
	exportName(numOfBook, newStatus, editStatus);
	exportQuanlity(numOfBook, newStatus, editStatus);
	exportQuanlityAvaiable(numOfBook, newStatus, editStatus);
	exportYear(numOfBook, newStatus, editStatus);
	exportBookCode(numOfBook, newStatus, editStatus);	
}

//check info by code
int isMatchByCode(int code, int* index){
	int numOfBook;
	importValue(&numOfBook);
	
	int i;
	for (i = 0; i < numOfBook; i++){
		if (code == book[i].code){
			*index = i;
			return 1;
		} 
	}
	return 0;
}

//check book existance
int isExistedTileBook(char* newTitle, int numOfBook){
	int i;

	for (i = 0; i < numOfBook; i++){
		toUpper(newTitle);
//		initialize(book[i].name, book[i].term);
		strcpy(book[i].term, book[i].name);
		toUpper(book[i].term);
		if (strcmp(newTitle, book[i].term) == 0)
		return 1;
	}
	return 0;
}

void neon(int loop)
{
	int i = 0;
	while(i < loop)
	{
		
		//system("color 1");
		//sleep(1);
		system("color 2");
		sleep(1);
		system("color 3");
		sleep(1);
		system("color 4");
		sleep(1);
		system("color 6");
		sleep(1);
		//system("color 9");
		//sleep(1);
		system("color a");
		sleep(1);
		system("color b");
		sleep(1);
		system("color c");
		sleep(1);
		system("color d");
		sleep(1);
		system("color e");
		sleep(1);
		system("color f");
		sleep(1);
		i++;
	}
} // end of neon function



void end()
{
	system("cls");
	printf("\n\n\n");//textColor(4);
	printf("\t\t\t\t\t");printf("                    ________         _________     __________  ");printf("\n");
	printf("\t\t\t\t\t");printf("                   //              ||            ||            ");printf("\n");//textColor(11);
	printf("\t\t\t\t\t");printf("                  //               ||            ||            ");printf("\n");
	printf("\t\t\t\t\t");printf("                 ||                ||            ||             ");printf("\n");//textColor(5);
	printf("\t\t\t\t\t");printf("                 \\\\________        ||________    ||________      ");printf("\n");
	printf("\t\t\t\t\t");printf("                          \\\\       ||            ||              ");printf("\n");//textColor(14);
	printf("\t\t\t\t\t");printf("                           ||      ||            ||             ");printf("\n");
	printf("\t\t\t\t\t");printf("                           //      ||            ||             ");printf("\n");//textColor(6);
	printf("\t\t\t\t\t");printf("                   _______//       ||_________   ||__________      ");printf("\n");
	printf("\t\t\t\t\t");printf("");printf("\n");//textColor(14);
	printf("\t\t\t\t\t");printf("                                ________                     ");printf("\n");
	printf("\t\t\t\t\t");printf("                  \\\\      //   //       \\\\    ||        ||    ");printf("\n");
	printf("\t\t\t\t\t");printf("                   \\\\    //   ||        ||    ||        ||        ");printf("\n");//textColor(5);
	printf("\t\t\t\t\t");printf("                    \\\\  //    ||        ||    ||        ||   ");printf("\n");
	printf("\t\t\t\t\t");printf("                     \\\\//     ||        ||    ||        ||     ");printf("\n");//textColor(4);
	printf("\t\t\t\t\t");printf("                      //      ||        ||    ||        ||  ");printf("\n");
	printf("\t\t\t\t\t");printf("                     //       ||        ||    ||        || ");printf("\n");//textColor(11);
	printf("\t\t\t\t\t");printf("                    //        ||        ||    ||        ||   ");printf("\n");
	printf("\t\t\t\t\t");printf("                   //          \\\\_______//     \\\\_______//      ");printf("\n");
	printf("\t\t\t\t\t");printf("");printf("\n");//textColor(6);
	printf("\t\t\t\t\t");printf("                          ______                                    ");printf("\n");
	printf("\t\t\t\t\t");printf("             /\\         //                  /\\         ||   |\\     ||");printf("\n");//textColor(14);
	printf("\t\t\t\t\t");printf("            //\\\\       ||                  //\\\\        ||   ||\\    || ");printf("\n");
	printf("\t\t\t\t\t");printf("           //  \\\\      ||                 //  \\\\       ||   ||\\\\   ||   ");printf("\n");//textColor(5);
	printf("\t\t\t\t\t");printf("          //    \\\\     ||     ____       //    \\\\      ||   || \\\\  ||    ");printf("\n");
	printf("\t\t\t\t\t");printf("         //______\\\\    ||        ||     //______\\\\     ||   ||  \\\\ ||     ");printf("\n");//textColor(11);
	printf("\t\t\t\t\t");printf("        //        \\\\   ||        ||    //        \\\\    ||   ||   \\\\||     ");printf("\n");
	printf("\t\t\t\t\t");printf("       //          \\\\  ||        ||   //          \\\\   ||   ||    \\\\|     ");printf("\n");//textColor(4);
	printf("\t\t\t\t\t");printf("      //            \\\\  \\\\_______//  //            \\\\  ||   ||     \\|");printf("\n");
	printf("\n\n\n\n\n");
	
	neon(1);
	getch();
	exit(0);
	
}

//search
void search(){
	int choiceSearch, i, numOfBook;
	char yesNoBookInfo = 'y';
	do {
		printMenuSearchStatus();
		textColor(Gold);
		printf("\t\t");
		drawLine(35);
		choiceSearch = checkChoice(5);
		
		switch (choiceSearch) {
			//search by name
			case 1:{
				char yesNoSearch = 'Y';
				do {
					//get name
					char nameIn[500];
					do printf("\t\tEnter the TITLE or some of first character of book's TITLE: ");
					while (!getStringIn(nameIn, 500, 0));
					toUpper(nameIn);
							
					//import value
					importValue(&numOfBook);
							
					int check = 1;//for printing title
					int check2 = 0;//for printting line
					for (i = 0 ; i < numOfBook ; i++){
						//initialize(book[i].name, book[i].term);
						strcpy(book[i].term, book[i].name);
						toUpper(book[i].term);
						
						if (isMatchEachCha(nameIn, book[i].term))
						printInfo(&check, &check2, i);
					}
					
					printLine(1);
					//if no log in print info -> no book
					if (check) printf("\t\tNo matching title\n");
					printf("\t\tContinue searching?\n");
					printYesNo();
					yesNoSearch = getYesNo();
				} while (yesNoSearch == 'Y' || yesNoSearch == 'y');
				break;
			}
					
			//search by year				
			case 2:{
				char yesNoSearch = 'Y';
				do {
					//get year
					printf("\t\tEnter year: ");
					int year = getIntNum();
	
					//import value
					importValue(&numOfBook);
					
					int check = 1;//for printing title
					int check2 = 0;//for printting line
					for (i = 0 ; i < numOfBook ; i++){
				
						if (year == toNum(book[i].year))
						printInfo(&check, &check2, i);
					}
					
					printLine(1);
					//if no log in print info -> no book
					if (check) printf("\t\tNo matching year\n");
					printf("\t\tContinue searching?\n");
					printYesNo();
					yesNoSearch = getYesNo();
				} while (yesNoSearch == 'Y' || yesNoSearch == 'y');
				break;
			}
			
			//search by category
			case 3:{
				char yesNoSearch = 'Y';
				do {
					//get category
					char strIn[500];
					do printf("\t\tEnter the CATEGORY or some of first character of CATEGORY: ");
					while (!getStringIn(strIn, 100, 0));
					toUpper(strIn);
	
					//import value
					importValue(&numOfBook);
				
					int check = 1;//for printing title
					int check2 = 0;//for printting line
					for (i = 0 ; i < numOfBook ; i++){
						//initialize(book[i].category, book[i].term);
						strcpy(book[i].term, book[i].category);
						toUpper(book[i].term);
							
						if (isMatchEachCha(strIn, book[i].term)) 
						printInfo(&check, &check2, i);
					}
						
					printLine(1);
					//if not log in book info -> no book
					if (check) printf("\t\tNo matching category\n");
					printf("\t\tContinue searching?\n");
					printYesNo();
					yesNoSearch = getYesNo();		
				} while (yesNoSearch == 'Y' || yesNoSearch == 'y');
				break;
			}
			case 4:{
				yesNoBookInfo = 'n';
				if(viewBooksInfo[0].adminOrUser == 0) 
				{
					pageEnterAdmin();
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					
					pageEnterUser(viewBooksInfo[0].stuCode, viewBooksInfo[0].newOrOld, viewBooksInfo[0].id, viewBooksInfo[0].maxStruct);
					
				}
				break;
			}
			default: end();
		}
	} while (yesNoBookInfo == 'Y' || yesNoBookInfo == 'y');
}

//add 
void add(){
	char yesNoLoop = 'y';//for continue add book info
	char yesNoAdd = 'y';//for decision adding or not
	system("cls");
	printf("\n\n\n\n");
	int numOfBook;//store number of book at present
	do {
		importValue(&numOfBook);
		if (numOfBook >= 1500) {
			printf("\t\tFull disk! You cannot add more book!\n");
			printf("\t\tPress anykey to back!");
			getch();
			goto END;
		}
			
		//input title
		do {
			do printf("\t\tInput title of book (< 500 characters): ");
			while (!getStringIn(book[numOfBook].name, 500, 0));
						
			//to check upper type of string
			char term[501];
			//initialize(book[numOfBook].name, term);
			strcpy(term, book[numOfBook].name);
						
			if (isExistedTileBook(term, numOfBook)){
				printf("\t\tThis book's title is existed. You cannot add the same title!");
				printf("\n\t\tDo you want to continue adding?");
				printYesNo();
				yesNoLoop = getYesNo();
				if (yesNoLoop == 'n' || yesNoLoop == 'N') goto END;
			} else break;
		} while (yesNoLoop == 'y' || yesNoLoop == 'Y');
					
		//input category
		do printf("\n\t\tInput category of book (< 100 characters): ");
		while (!getStringIn(book[numOfBook].category, 100, 0));
					
		//input year
		do printf("\n\t\tInput year established of book (< 4 characters): ");
		while (!getStringIn(book[numOfBook].year, 4, 1));
					
		//input quanlity
		do printf("\n\t\tInput quanlity of book on shelves (< 4 characters): ");
		while (!getStringIn(book[numOfBook].quanlity, 4, 1));
				
		//import quanlity avaiable. new book -> no one's borrow yet
		//initialize(book[numOfBook].quanlity, book[numOfBook].quanlityAvaiable);
		strcpy(book[numOfBook].quanlityAvaiable, book[numOfBook].quanlity);
		
		//import new code
		book[numOfBook].code = numOfBook + 1;
		
		printf("\n\t\tBook info you've just inputed is: ");
		int check = 1; //to print info (due to default)
		printInfo(&check, &check, numOfBook);
					
		printf("\n\t\tDo you want to import?");
		printYesNo();
		yesNoAdd = getYesNo();
					
		if (yesNoAdd == 'y' || yesNoAdd == 'Y') exportValue(numOfBook, 1, 0);
		else {
			*book[numOfBook].category = '\0';
			*book[numOfBook].name = '\0';
			*book[numOfBook].quanlity = '\0';
			*book[numOfBook].quanlityAvaiable = '\0';
			*book[numOfBook].term = '\0';
			*book[numOfBook].year = '\0';
		}
		
		printf("\t\tDo you want to continue adding ?");
		printYesNo();
		yesNoLoop = getYesNo();
					
	} while (yesNoLoop == 'y' || yesNoLoop == 'Y');
	END:{system("cls");}
	pageEnterAdmin();
	
}

//delete info by title
int deleteInfoByTitle(char* name){
	toUpper(name);
	int numOfBook;

	//import info
	importValue(&numOfBook);
	int temp = 0;//to check delete successful status

	int i, j; //i for check each single title
			  //j for delete
	for (i = 0; i < numOfBook; i++){
		//initialize(book[i].name, book[i].term);
		strcpy(book[i].term, book[i].name);
		toUpper(book[i].term);

		while (strcmp(book[i].term, name) == 0) {
			j = i;
			if (j == (numOfBook - 1)){
				char term[] = {'\0'};
				//initialize(term, book[j].name);
				strcpy(book[j].name, term);
				//initialize(term, book[j].category);
				strcpy(book[j].category, term);
				//initialize(term, book[j].quanlity);
				strcpy(book[j].quanlity, term);
				//initialize(term, book[j].quanlityAvaiable);
				strcpy(book[j].quanlityAvaiable, term);
				//initialize(term, book[j].term);
				strcpy(book[j].term, term);
				//initialize(term, book[j].year);
				strcpy(book[j].year, term);
			} else {
				while (j < numOfBook){
					//initialize(book[j+1].name, book[j].name);
					strcpy(book[j].name, book[j+1].name);
					//initialize(book[j+1].category, book[j].category);
					strcpy(book[j].category, book[j+1].category);
					//initialize(book[j+1].quanlity, book[j].quanlity);
					strcpy(book[j].quanlity, book[j+1].quanlity);
					//initialize(book[j+1].quanlityAvaiable, book[j].quanlityAvaiable);
					strcpy(book[j].quanlityAvaiable, book[j+1].quanlityAvaiable);
					//initialize(book[j+1].term, book[j].term);
					strcpy(book[j].term, book[j+1].term);
					//initialize(book[j+1].year, book[j].year);
					strcpy(book[j].year, book[j+1].year);
					j++;
				}
			}
			temp++;
		}
	}
		if (temp == 0) return 0;
		//export
		if (numOfBook - temp - 1 < 0) exportValue(0, 0, 0);
		else exportValue(numOfBook - temp - 1, 0, 0);
		return 1;
		//0 : no match book title
		//1 : delete successfully
}

//delete info by code
void deleteInfoByCode(int code){
	int numOfBook;

	//import info
	importValue(&numOfBook);

	int i, j; //i for check each single title
			  //j for delete
	for (i = 0; i < numOfBook; i++){
		if (code == book[i].code) {
			j = i;
			if (j == (numOfBook - 1)){
				char term[] = {'\0'};
				//initialize(term, book[j].name);
				strcpy(book[j].name, term);
				//initialize(term, book[j].category);
				strcpy(book[j].category, term);
				//initialize(term, book[j].quanlity);
				strcpy(book[j].quanlity, term);
				//initialize(term, book[j].quanlityAvaiable);
				strcpy(book[j].quanlityAvaiable, term);
				//initialize(term, book[j].term);
				strcpy(book[j].term, term);
				//initialize(term, book[j].year);
				strcpy(book[j].year, term);
				/*
				initialize(term, book[j].name);
				initialize(term, book[j].category);
				initialize(term, book[j].quanlity);
				initialize(term, book[j].quanlityAvaiable);
				initialize(term, book[j].term);
				initialize(term, book[j].year);*/
				book[i].code = -1;
			} else {
				while (j < numOfBook){
				/*	initialize(book[j+1].name, book[j].name);
					initialize(book[j+1].category, book[j].category);
					initialize(book[j+1].quanlity, book[j].quanlity);
					initialize(book[j+1].quanlityAvaiable, book[j].quanlityAvaiable);
					initialize(book[j+1].term, book[j].term);
					initialize(book[j+1].year, book[j].year);*/
					
					//initialize(book[j+1].name, book[j].name);
					strcpy(book[j].name, book[j+1].name);
					//initialize(book[j+1].category, book[j].category);
					strcpy(book[j].category, book[j+1].category);
					//initialize(book[j+1].quanlity, book[j].quanlity);
					strcpy(book[j].quanlity, book[j+1].quanlity);
					//initialize(book[j+1].quanlityAvaiable, book[j].quanlityAvaiable);
					strcpy(book[j].quanlityAvaiable, book[j+1].quanlityAvaiable);
					//initialize(book[j+1].term, book[j].term);
					strcpy(book[j].term, book[j+1].term);
					//initialize(book[j+1].year, book[j].year);
					strcpy(book[j].year, book[j+1].year);
					j++;
				}
			}
		}
	}
	
	if (numOfBook - 2 < 0) exportValue(0, 0, 0);
	else exportValue(numOfBook - 2, 0, 0);
}

//delete choice
void deleteChoice(){
	
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");textColor(14);//yellow
		printf("\t\tChoose your requirement\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(36);//--------------------
		textColor(15);
			
		printf("\t\t1. Enter Title Of Book to Delete\n");
		printf("\t\t2. Enter Code of Book to Delete\n");
		printf("\t\t3. Back\n");
		printf("\t\t4. Exit.\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(36);//-----------------
	
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);		
		
		int choice = getChoice(4);
		switch (choice) {
			//delete by title
			case 1: {
				system("cls");
				printf("\n\n\n\n");
				char yesNoContinue = 'y';
				do {
					char name[501];
					printf("\t\tTile: ");
					getStringIn(name, 500, 0);
					printf("\t\tDo you want to delete %s ?\n", name);
					printYesNo();
					char yesNoDelete = getYesNo();
					
					if (yesNoDelete == 'y' || yesNoDelete == 'Y'){
						if (deleteInfoByTitle(name) == 0) printf("\n\t\tNo matching book title.");
						else printf("\n\t\tDelete %s successfully!", name);
					} 
					
					printf("\t\tDo you want to continue deleting ?\n");
					printYesNo();
					yesNoContinue = getYesNo();
				} while (yesNoContinue == 'y' || yesNoContinue == 'Y');
				
				break;
			}

			//delete by code
			case 2:{
				system("cls");
				printf("\n\n\n\n");
				char yesNoContinue = 'y';
				do {
					printf("\t\tCode: ");
					int code = getIntNum();
					
					int index;//store index of book info
					char yesNoDelete = 'n';//to decide to delete
					if (isMatchByCode(code, &index)) {
						printf("\t\tDo you want to delete %s ?\n", book[index].name);
						printYesNo();
						yesNoDelete = getYesNo();
					} else printf("\n\t\tNo matching book code.");
					char term[501] = {'\0'};
					//initialize(book[index].name, term);
					strcpy(term, book[index].name);
					if (yesNoDelete == 'y' || yesNoDelete == 'Y'){
						deleteInfoByCode(code);
						printf("\n\t\tDelete %s successfully!", term);
					} 
					
					printf("\t\tDo you want to continue deleting ?\n");
					printYesNo();
					yesNoContinue = getYesNo();
				} while (yesNoContinue == 'y' || yesNoContinue == 'Y');
				
				break;
			}
			
			//back
			case 3: {
				yesNo = 'n';
				break;
			}
			
			//exit
			case 4: {
				end();
			}
		}	
	} while (yesNo == 'y');
}

//edit title by code
void editTitleByCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		printf("\t\tEnter code of book need editing:");
		int code = getIntNum();		
		
		int check = 1;//to print info
		int index;//to store index of book matched with the code
		if (isMatchByCode(code, &index)) {
			printf("\n\t\tBook you want to edit is:");
			printInfo(&check, &check, index);
			
			printf("\t\tDo you want to edit title of %s?", book[index].name);
			printYesNo();
			char yesNoCode = getYesNo(); //to get decision if the book is right
			if (yesNoCode == 'n' || yesNoCode == 'N') goto Tocontinue;
		}
		
		char yesNoEdit = 'y';
		//new name
		char newName[501];
		do printf("\n\t\tNew title is: ");
		while (!getStringIn(newName, 500, 0));
		//initialize(newName, book[index].name);
		strcpy(book[index].name, newName);
		
		printInfo(&check, &check, index);
		printf("\n\t\tEdit?");
		printYesNo();
		yesNoEdit = getYesNo();
			
		//export if yes
		if (yesNoEdit == 'y' || yesNoEdit == 'Y')
		exportValue(numOfBook, 0, 1);		
		
		Tocontinue: {
			printf("\t\tDo you want to continue editing title of book?");
			printYesNo();
			yesNo = getYesNo();
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit tile 
void editTitle(){
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		char name[501];
		do printf("\t\tEnter title of book need editing: ");
		while (!getStringIn(name, 500, 0));
		toUpper(name);
		
		int check2 = 0; //check 2 to check existed book
		//print book info need editing
		int i;
		for (i = 0; i < numOfBook; i++){
			//initialize(book[i].name, book[i].term);
			strcpy(book[i].term, book[i].name);
			toUpper(book[i].term);
			int check = 1;//to print info
			if (strcmp(name, book[i].term) == 0) {
				printInfo(&check, &check, i);
				check2 = 1;
				break;
			}
		}
		
		char yesNoEdit = 'y';
		if (check2 == 0) printf("\t\tNo matching book's title.");
		else {
			//new name
			char newName[501];
			do printf("\n\t\tNew title is: ");
			while (!getStringIn(newName, 500, 0));
			//initialize(newName, book[i].name);
			strcpy(book[i].name, newName);
			
			int check = 1;//to print info
			printInfo(&check, &check, i);
			printf("\n\t\tEdit?");
			printYesNo();
			yesNoEdit = getYesNo();
			
			//export if yes
			if (yesNoEdit == 'y' || yesNoEdit == 'Y')
			exportValue(numOfBook, 0, 1);	
		}
		
		printf("\t\tDo you want to continue editing title of book?");
		printYesNo();
		yesNo = getYesNo();
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit category by code
void editCateByCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		printf("\t\tEnter code of book need editing:");
		int code = getIntNum();		
		
		int check = 1;//to print info
		int index;//to store index of book matched with the code
		if (isMatchByCode(code, &index)) {
			printf("\n\t\tBook you want to edit is:");
			printInfo(&check, &check, index);
			
			printf("\t\tDo you want to edit category of %s?", book[index].name);
			printYesNo();
			char yesNoCode = getYesNo(); //to get decision if the book is right
			if (yesNoCode == 'n' || yesNoCode == 'N') goto Tocontinue;
		}
		
		char yesNoEdit = 'y';

		//new category
		char newCate[101];
		do printf("\n\t\tNew category is: ");
		while (!getStringIn(newCate, 100, 0));
		//initialize(newCate, book[index].category);
		strcpy(book[index].category, newCate);
		
		printInfo(&check, &check, index);
		printf("\n\t\tEdit?");
		printYesNo();
		yesNoEdit = getYesNo();
			
		//export if yes
		if (yesNoEdit == 'y' || yesNoEdit == 'Y')
		exportValue(numOfBook, 0, 1);		
	
		Tocontinue: {
			printf("\t\tDo you want to continue editing title of book?");
			printYesNo();
			yesNo = getYesNo();
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit category 
void editCate(){
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
	
		char name[501];
		do printf("\t\tEnter title of book need editing:");
		while (!getStringIn(name, 500, 0));
		toUpper(name);
		
		int check2 = 0; //check 2 to check existed book
		//print book info need editing
		int i;
		for (i = 0; i < numOfBook; i++){
			//initialize(book[i].name, book[i].term);
			strcpy(book[i].term, book[i].name);
			toUpper(book[i].term);
			int check = 1;//to print info
			if (strcmp(name, book[i].term) == 0) {
				printInfo(&check, &check, i);
				check2 = 1;
				break;
			}
		}
		
		char yesNoEdit = 'y';
		if (check2 == 0) printf("\t\tNo matching book's title.");
		else {
			//new cate
			char newCate[101];
			do printf("\n\t\tNew category is: ");
			while (!getStringIn(newCate, 100, 0));
			//initialize(newCate, book[i].category);
			strcpy(book[i].category, newCate);
			
			int check = 1;//to print info
			printInfo(&check, &check, i);
			printf("\n\t\tEdit?");
			printYesNo();
			yesNoEdit = getYesNo();
			
			//export if yes
			if (yesNoEdit == 'y' || yesNoEdit == 'Y')
			exportValue(numOfBook, 0, 1);	
		}
		
		printf("\t\tDo you want to continue editing category of book?");
		printYesNo();
		yesNo = getYesNo();
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit quanlity by code
void editQuanlityByCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		printf("\t\tEnter code of book need editing:");
		int code = getIntNum();		
		
		int check = 1;//to print info
		int index;//to store index of book matched with the code
		if (isMatchByCode(code, &index)) {
			printf("\n\t\tBook you want to edit is:");
			printInfo(&check, &check, index);
			
			printf("\t\tDo you want to edit quanlity of %s?", book[index].name);
			printYesNo();
			char yesNoCode = getYesNo(); //to get decision if the book is right
			if (yesNoCode == 'n' || yesNoCode == 'N') goto Tocontinue;
		}
		
		char yesNoEdit = 'y';

		//new cate
		char newQuanlity[5];
		do printf("\n\t\tNew quanlity is: ");
		while (!getStringIn(newQuanlity, 4, 0));
		//initialize(newQuanlity, book[index].quanlity);
		strcpy(book[index].quanlity, newQuanlity);
			
		printInfo(&check, &check, index);
		printf("\n\t\tEdit?");
		printYesNo();
		yesNoEdit = getYesNo();
			
		//export if yes
		if (yesNoEdit == 'y' || yesNoEdit == 'Y')
		exportValue(numOfBook, 0, 1);
		
		Tocontinue: {
			printf("\t\tDo you want to continue editing title of book?");
			printYesNo();
			yesNo = getYesNo();
		}	
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit quanlity 
void editQuanlity(){
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		char name[501];
		do printf("\t\tEnter title of book need editing:");
		while (!getStringIn(name, 500, 0));
		toUpper(name);
		
		int check2 = 0; //check 2 to check existed book
		//print book info need editing
		int i;
		for (i = 0; i < numOfBook; i++){
			//initialize(book[i].name, book[i].term);
			strcpy(book[i].term, book[i].name);
			toUpper(book[i].term);
			int check = 1;//to print info
			if (strcmp(name, book[i].term) == 0) {
				printInfo(&check, &check, i);
				check2 = 1;
				break;
			}
		}
		
		char yesNoEdit = 'y';
		if (check2 == 0) printf("\t\tNo matching book's title.");
		else {
			//new cate
			char newQuanlity[5];
			do printf("\n\t\tNew quanlity is: ");
			while (!getStringIn(newQuanlity, 4, 0));
			//initialize(newQuanlity, book[i].quanlity);
			strcpy(book[i].quanlity, newQuanlity);
			
			int check = 1;//to print info
			printInfo(&check, &check, i);
			printf("\n\t\tEdit?");
			printYesNo();
			yesNoEdit = getYesNo();
			
			//export if yes
			if (yesNoEdit == 'y' || yesNoEdit == 'Y')
			exportValue(numOfBook, 0, 1);	
		}
		
		printf("\t\tDo you want to continue editing quanlity of book?");
		printYesNo();
		yesNo = getYesNo();
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit year by code
void editYearByCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		printf("\t\tEnter code of book need editing:");
		int code = getIntNum();		
		
		int check = 1;//to print info
		int index;//to store index of book matched with the code
		if (isMatchByCode(code, &index)) {
			printf("\n\t\tBook you want to edit is:");
			printInfo(&check, &check, index);
			
			printf("\t\tDo you want to edit year established of %s?", book[index].name);
			printYesNo();
			char yesNoCode = getYesNo(); //to get decision if the book is right
			if (yesNoCode == 'n' || yesNoCode == 'N') goto Tocontinue;
		}
		
		char yesNoEdit = 'y';

		//new year
		char newYear[5];
		do printf("\n\t\tNew year is: ");
		while (!getStringIn(newYear, 4, 0));
		//initialize(newYear, book[index].year);
		strcpy(book[index].year, newYear);
			
		printInfo(&check, &check, index);
		printf("\n\t\tEdit?");
		printYesNo();
		yesNoEdit = getYesNo();
			
		//export if yes
		if (yesNoEdit == 'y' || yesNoEdit == 'Y')
		exportValue(numOfBook, 0, 1);
		
		Tocontinue: {
			printf("\t\tDo you want to continue editing title of book?");
			printYesNo();
			yesNo = getYesNo();
		}		
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit year 
void editYear(){
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//import value
		int numOfBook;
		importValue(&numOfBook);
		
		char name[501];
		do printf("\t\tEnter title of book need editing:");
		while (!getStringIn(name, 500, 0));
		toUpper(name);
		
		int check2 = 0; //check 2 to check existed book
		//print book info need editing
		int i;
		for (i = 0; i < numOfBook; i++){
			//initialize(book[i].name, book[i].term);
			strcpy(book[i].term, book[i].name);
			toUpper(book[i].term);
			int check = 1;//to print info
			if (strcmp(name, book[i].term) == 0) {
				printInfo(&check, &check, i);
				check2 = 1;
				break;
			}
		}
		
		char yesNoEdit = 'y';
		if (check2 == 0) printf("\t\tNo matching book's title.");
		else {
			//new cate
			char newYear[5];
			do printf("\n\t\tNew year is: ");
			while (!getStringIn(newYear, 4, 0));
			//initialize(newYear, book[i].year);
			strcpy(book[i].year, newYear);
			
			int check = 1;//to print info
			printInfo(&check, &check, i);
			printf("\n\t\tEdit?");
			printYesNo();
			yesNoEdit = getYesNo();
			
			//export if yes
			if (yesNoEdit == 'y' || yesNoEdit == 'Y')
			exportValue(numOfBook, 0, 1);	
		}
		
		printf("\t\tDo you want to continue editing year established of book?");
		printYesNo();
		yesNo = getYesNo();
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit
void edit(){
	char yesNo = 'y';
	do {
		//print menu and get choice
		system("cls");
		printf("\n\n\n\n");textColor(14);//yellow
		printf("\t\tChoose your requirement\n");
	
		textColor(11);
		printf("\t\t");
		drawLine(31);//--------------------
	
		textColor(15);
		printf("\t\t1. Edit title.\n");
		printf("\t\t2. Edit category.\n");
		printf("\t\t3. Edit year established.\n");
		printf("\t\t4. Edit quanlity.\n");
		printf("\t\t5. Back.\n");
		printf("\t\t6. Exit.\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(31);//-----------------
	
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);	
		int choice = getChoice(6);
		
		switch (choice) {
			//edit tile
			case 1:{
				system("cls");
				printf("\n\n\n\n");textColor(14);//yellow
				printf("\t\tChoose your requirement\n");
	
				textColor(11);
				printf("\t\t");
				drawLine(27);//--------------------
				
				printf("\t\t1. Enter code of book\n");
				printf("\t\t2. Enter Title of book\n");
				printf("\t\t3. Back\n");
				printf("\t\t4. Exit\n");
				
				textColor(11);
				printf("\t\t");
				drawLine(27);//-----------------
	
				textColor(14);
				printf("\t\tYour requirement is: ");
				textColor(15);
				int choiceEdit = getChoice(4);
				
				switch (choiceEdit) {
					//enter code
					case 1: {
						editTitleByCode();
						break;
					}
					
					//enter title
					case 2: {
						editTitle();
						break;
					}
				}
				break;
			}
			
			//edit category
			case 2:{
				system("cls");
				printf("\n\n\n\n");textColor(14);//yellow
				printf("\t\tChoose your requirement\n");
	
				textColor(11);
				printf("\t\t");
				drawLine(27);//--------------------
	
				textColor(15);
				
				printf("\t\t1. Enter code of book\n");
				printf("\t\t2. Enter category of book\n");
				printf("\t\t3. Back\n");
				printf("\t\t4. Exit\n");
				textColor(11);
				printf("\t\t");
				drawLine(27);//-----------------
	
				textColor(14);
				printf("\t\tYour requirement is: ");
				textColor(15);
				int choiceEdit = getChoice(4);
				
				switch (choiceEdit) {
					//enter code
					case 1: {
						editCateByCode();
						break;
					}
					
					//enter category
					case 2: {
						editCate();	
						break;
					}	
				}
				break;
			}
			
			//edit year
			case 3:{
				system("cls");
				printf("\n\n\n\n");textColor(14);//yellow
				printf("\t\tChoose your requirement\n");
	
				textColor(11);
				printf("\t\t");
				drawLine(38);//--------------------
	
				textColor(15);
				printf("\t\t1. Enter code of book\n");
				printf("\t\t2. Enter year established of book\n");
				printf("\t\t3. Back\n");
				printf("\t\t4. Exit\n");
				textColor(11);
				printf("\t\t");
				drawLine(38);//-----------------
	
				textColor(14);
				printf("\t\tYour requirement is: ");
				textColor(15);
				int choiceEdit = getChoice(4);
				
				switch (choiceEdit) {
					//enter code
					case 1: {
						editYearByCode();
						break;
					}
					
					//enter year
					case 2: {
						editYear();	
						break;
					}	
				}
				break;
			}
			
			//edit quanlity
			case 4:{
				system("cls");
				printf("\n\n\n\n");textColor(14);//yellow
				printf("\t\tChoose your requirement\n");
	
				textColor(11);
				printf("\t\t");
				drawLine(35);//--------------------
	
				textColor(15);
				printf("\t\t1. Enter code of book\n");
				printf("\t\t2. Enter year quanlity of book\n");
				printf("\t\t3. Back\n");
				printf("\t\t4. Exit\n");
				textColor(11);
				printf("\t\t");
				drawLine(35);//-----------------
	
				textColor(14);
				printf("\t\tYour requirement is: ");
				textColor(15);
				int choiceEdit = getChoice(4);
				
				switch (choiceEdit) {
					//enter code
					case 1: {
						editQuanlityByCode();
						break;
					}
					
					//enter quanlity
					case 2: {
						editQuanlity();	
						break;
					}	
				}
				break;
			}
			
			//back
			case 5:{
				yesNo = 'n';
				break;
			}
			
			//exit
			case 6: end();
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}


void intro ()//first
{
	
	
	system("cls");
	printf("\n\n\n\n\n\n");textColor(4);
	printf("\t\t\t\t");printf("                                   ____________                __________    ________         \n");
	printf("\t\t\t\t");printf("  \\\\                           // ||            ||           //            //        \\   |\\          /||\n");
	printf("\t\t\t\t");printf("   \\\\            /\\           //  ||            ||          ||            ||         ||  ||\\        //||\n");textColor(11);
	printf("\t\t\t\t");printf("    \\\\          //\\\\         //   ||            ||          ||            ||         ||  ||\\\\      // ||\n");
	printf("\t\t\t\t");printf("     \\\\        //  \\\\       //    ||________    ||          ||            ||         ||  || \\\\    //  ||\n");textColor(10);
	printf("\t\t\t\t");printf("      \\\\      //    \\\\     //     ||            ||          ||            ||         ||  ||  \\\\  //   ||\n");
	printf("\t\t\t\t");printf("       \\\\    //      \\\\   //      ||            ||          ||            ||         ||  ||   \\\\//    ||\n");textColor(14);
	printf("\t\t\t\t");printf("        \\\\  //        \\\\ //       ||            ||          \\\\            ||         ||  ||    \\/     ||\n");
	printf("\t\t\t\t");printf("         \\\\//          \\\\/        ||__________  ||_________  \\\\_________   \\________//   ||           ||\n");textColor(3);
	printf("\t\t\t\t");printf("\n\n");
	printf("\t\t\t\t");printf("                                            ||            _______\n");
	printf("\t\t\t\t");printf("                                         ===||===        //     \\\\ \n");
	printf("\t\t\t\t");printf("                                            ||          ||      ||\n");
	printf("\t\t\t\t");printf("                                            ||          ||      ||\n");
	printf("\t\t\t\t");printf("                                            ||          ||      ||\n");
	printf("\t\t\t\t");printf("                                            ||          ||      ||\n");
	printf("\t\t\t\t");printf("                                             \\\\_____//   \\\\_____// \n");textColor(14);
	printf("\t\t\t\t");printf("\n\n");
	printf("\t\t\t\t");printf("                            _________       _________                         _________       \n");
	printf("\t\t\t\t");printf("          ||          ||   ||       ||     ||       ||            /\\         ||       ||  \\\\      //   \n");
	printf("\t\t\t\t");printf("          ||          ||   ||	    ||     ||       ||           //\\\\        ||       ||   \\\\    //   \n");textColor(10);
	printf("\t\t\t\t");printf("          ||          ||   ||       ||     ||       ||          //  \\\\       ||       ||    \\\\  //     \n");
	printf("\t\t\t\t");printf("      	  ||	      ||   ||_______//     ||______//          //    \\\\      ||______//      \\\\//     \n");textColor(11);
	printf("\t\t\t\t");printf("          ||          ||   ||       \\\\     ||     \\\\          //______\\\\     ||      \\\\       \\\\ \n");
	printf("\t\t\t\t");printf("          ||          ||   ||        \\\\    ||      \\\\        //        \\\\    ||       \\\\      ||   \n");textColor(4);
	printf("\t\t\t\t");printf("          ||          ||   ||        ||    ||       \\\\      //          \\\\   ||        \\\\     ||     \n");
	printf("\t\t\t\t");printf("          ||________  ||   ||________||    ||        \\\\    //            \\\\  ||         \\\\    ||     \n");											
	
	
	printf("\n\n\n\n");
	textColor(15);//reset default color
	getch();
	system("cls");
	
}


int checkFirstNumber(int max)//check input is a integer or not
{
	//for firstMenu
	// your requirement
	// your requirement
	int num;
	int tmp;
	char word;
	
	do
	{
		fflush(stdin);
		tmp = scanf("%d%c", &num, &word);

		if(tmp != 2 || word != '\n')
		{
			textColor(4);//red
			printf("\t\tWrong!!\n");
			textColor(14);//yellow
			printf("\t\tYour requirement is: ");
			textColor(15);//default
		}
		else if(num < 1 || num > max)//limit integer
		{
			textColor(4);
			printf("\t\tWrong!!\n");
			textColor(14);
			printf("\t\tYour requirement is: ");
			textColor(15);
		}
	}while(tmp != 2 || word != '\n'|| num < 1 || num > max);
	
	return num;// input
	
}//end of checkFirstNumber function

int checkChoice(int max)
{
	int num;
	int tmp;
	char word;
	textColor(Gold);
	printf("\t\tYour choice is: ");
	textColor(White);
	
	do
	{
		fflush(stdin);
		tmp = scanf("%d%c", &num, &word);

		if(tmp != 2 || word != '\n')
		{
			textColor(4);//red
			printf("\t\tWrong!!\n");
			textColor(14);//yellow
			printf("\t\tYour choice is: ");
			textColor(15);//default
		}
		else if(num < 1 || num > max)//limit integer
		{
			textColor(4);
			printf("\t\tWrong!!\n");
			textColor(14);
			printf("\t\tYour choice is: ");
			textColor(15);
		}
	}while(tmp != 2 || word != '\n'|| num < 1 || num > max);
	
	return num;// input
} // end of checkChoice function

void change(char str[100])
{
	
	char ch;
	int i = 0;
	
	while(str[i] != '\0')
	{
		// vowel   a    e    i     o    u
		// value  97  101   105   111  117
		// change  @   #    $     %    &
		// value  64  35   36    37   38
		if(str[i] == 97) str[i] = 64;
		else if(str[i] == 101) str[i] = 35;
		else if(str[i] == 105) str[i] = 36;
		else if(str[i] == 111) str[i] = 37;
		else if(str[i] == 117) str[i] = 38;
		
		// revowel
		else if(str[i] == 64) str[i] = 97;
		else if(str[i] == 35) str[i] = 101;
		else if(str[i] == 36) str[i] = 105;
		else if(str[i] == 37) str[i] = 111;
		else if(str[i] == 38) str[i] = 117;
		
		// extension
		// vowel
		
		else if(str[i] > 97 && str[i] < 101) str[i] += 4; // between a and e +
		else if(str[i] > 101 && str[i] < 105) str[i] -= 4; // between e and i -
		
		else if(str[i] == 110) str[i] = 94; // n-^
		else if(str[i] == 94) str[i] = 110; // n-^
		else if(str[i] == 116) str[i] = 63; // t-?
		else if(str[i] == 63) str[i] = 116; // t-?
		else if(str[i] > 105 && str[i] < 111) str[i] += 6; // between i and o +
		else if(str[i] > 111 && str[i] < 117) str[i] -= 6; // between o and u -
		
		else if(str[i] == 118) str[i] = 126; // v-~
		else if(str[i] == 126) str[i] = 118; // v-~
		// 4 last low char
		else if(str[i] >= 119 && str[i] <= 120) str[i] += 2;
		else if(str[i] >= 121 && str[i] <= 122) str[i] -= 2;
		
		// A-Z
		else if(str[i] >= 65 && str[i] <= 90-13) str[i] += 13; 
		else if(str[i] > 90-13 && str[i] <= 90) str[i] -= 13;
		
		// num 1-9
		else if(str[i] >= 49 && str[i] <= 57) str[i] -= 10; // 1-9 -
		else if(str[i] >= 39 && str[i] <= 47) str[i] += 10; // + 1-9
		else if(str[i] == 48) str[i] = 125; // 0-}
		else if(str[i] == 125) str[i] = 48; // 0-}
		
		// others
		else if(str[i] == 33) str[i] = 34; // !-"
		else if(str[i] == 34) str[i] = 33; // !-"
		else if(str[i] >= 59 && str[i] <= 60) str[i] += 2;// ; <
		else if(str[i] >= 61 && str[i] <= 62) str[i] -= 2;// = >
		else if(str[i] == 92) str[i] = 93; // \-]
		else if(str[i] == 93) str[i] = 92; // \-]
		else if(str[i] == 95) str[i] = 96; // _-`
		else if(str[i] == 96) str[i] = 95; // _-`
		else if(str[i] == 123) str[i] = 124; // {-|
		else if(str[i] == 124) str[i] = 123; // {-|
		else if(str[i] == 91) str[i] = 58; // [-:
		else if(str[i] == 58) str[i] = 91; // [-:
		
		
		i++;//printf("f");
	}
	
	//printf("\n%s", str);
	
} // end of change function


void rechange(char str[100])
{

	int i = 0;
	
	while(str[i] != '\0')
	{
		// vowel   a    e    i     o    u
		// value  97  101   105   111  117
		// change  @   #    $     %    &
		// value  64  35   36    37   38
		
		// revowel
		if(str[i] == 64) str[i] = 97;
		else if(str[i] == 35) str[i] = 101;
		else if(str[i] == 36) str[i] = 105;
		else if(str[i] == 37) str[i] = 111;
		else if(str[i] == 38) str[i] = 117;
		
		// vowel
		else if(str[i] == 97) str[i] = 64;
		else if(str[i] == 101) str[i] = 35;
		else if(str[i] == 105) str[i] = 36;
		else if(str[i] == 111) str[i] = 37;
		else if(str[i] == 117) str[i] = 38;
		
		
		// extension
		// vowel
		
		else if(str[i] > 97+4 && str[i] < 101+4) str[i] -= 4; // between a and e +
		else if(str[i] > 101-4 && str[i] < 105-4) str[i] += 4; // between e and i -
		
		else if(str[i] == 94) str[i] = 110; // n-^
		else if(str[i] == 110) str[i] = 94; // n-^
		else if(str[i] == 63) str[i] = 116; // t-?
		else if(str[i] == 116) str[i] = 63; // t-?
		else if(str[i] > 105+6 && str[i] < 111+6) str[i] -= 6; // between i and o +
		else if(str[i] > 111-6 && str[i] < 117-6) str[i] += 6; // between o and u -
		
		else if(str[i] == 126) str[i] = 118; // v-~
		else if(str[i] == 118) str[i] = 126; // v-~
		// 4 last low char
		else if(str[i] >= 119+2 && str[i] <= 120+2) str[i] -= 2;
		else if(str[i] >= 121-2 && str[i] <= 122-2) str[i] += 2;
		
		// A-Z
		else if(str[i] >= 65+13 && str[i] <= 90-13+13) str[i] -= 13; 
		else if(str[i] > 90-13-13 && str[i] <= 90-13) str[i] += 13;
		
		// num 1-9
		else if(str[i] >= 49-10 && str[i] <= 57-10) str[i] += 10; // 1-9 -
		else if(str[i] >= 39+10 && str[i] <= 47+10) str[i] -= 10; // + 1-9
		else if(str[i] == 125) str[i] = 48; // 0-}
		else if(str[i] == 48) str[i] = 125; // 0-}
		
		// others
		else if(str[i] == 34) str[i] = 33; // !-"
		else if(str[i] == 33) str[i] = 34; // !-"
		else if(str[i] >= 59+2 && str[i] <= 60+2) str[i] -= 2;// ; <
		else if(str[i] >= 61-2 && str[i] <= 62-2) str[i] += 2;// = >
		else if(str[i] == 93) str[i] = 92; // \-]
		else if(str[i] == 92) str[i] = 93; // \-]
		else if(str[i] == 96) str[i] = 95; // _-`
		else if(str[i] == 95) str[i] = 96; // _-`
		else if(str[i] == 124) str[i] = 123; // {-|
		else if(str[i] == 123) str[i] = 124; // {-|
		else if(str[i] == 58) str[i] = 91; // [-:
		else if(str[i] == 91) str[i] = 58; // [-:
		
		
		i++;//printf("f");
	}
	
	//printf("\n%s", str);
	
} // end of rechange function


void firstMenu()//the first menu since started
{
	int choose;
	
	makeLine(4);
	makeTab(3);
	textColor(14);
	printf("---/~~Harsh Library~~/---");
	textColor(15);
	
	printf("\n\n");textColor(14);//yellow
	printf("\t\tChoose your requirment\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(40);//----------------------
	textColor(15);
	
	printf("\t\t1. Admin\n");
	printf("\t\t2. User\n");
	printf("\t\t3. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(40);//---------------------
	
	textColor(14);
	printf("\t\tYour requirment is: ");
	textColor(15);
		
	choose = checkFirstNumber(3);//check 1-2
	
	switch(choose)
	{
		case 1:
			fflush(stdin);
			system("cls");
			
			//if you are a admin enter your password
			adminPassword();//call other function
			
			break;
		
		case 2:
			fflush(stdin);
			system("cls");
			trouble();
			enterUserAccount();//call other function
			
			//---------------------------------------------
			//if you are a user enter your account
			
			break;
		
		case 3://wnat to exit
			fflush(stdin);
			system("cls");
			end();
			
		default:
			//never should use
			fflush(stdin);
			system("cls");
			firstMenu();
			//the same function
		break;
			
	}
	
	
	}//end of firstMenu function


void menuOfUser(int id, char stuCode[30]);


int enterUserPassword(int follow) //follow make many situation
{
	
	char realPassword[100];//array of password
	
	// Enter password
	char password[100];//password
	int i = 0;
	int j = 0;
	int id1 = 1;//id of username
	int id2 = 1;//id of password
	char ch;
	char chj;
	printf("\n\n");
	
	if(follow == 1) printf("\t\tEnter username: ");
	if(follow == 2) printf("\t\tEnter password: ");

	while(2)
	{
		ch = getch();
		if(ch == ENTER)//enter when finish
		//enter 13
		{
			password[i] ='\0';
			
			
			if (follow  == 1)
			{
			
			FILE *pw;//file password
			pw = fopen("userUsername.txt", "r");//open file to read
			
				while(!feof(pw))
			{
				
				fscanf(pw, "%[^\n]%*c", realPassword);
			
				if(strcmp(password, realPassword) == 0)
				{
					//when your password is not correct
					//checkId(password);
					//printf("%d", id1);
					
					fclose(pw);//close file
					
					return id1;
				}
					id1++;// id of pasword
		
			}//end of small while
			}// end if follow 1
			
			if (follow  == 2)
			{
			
			FILE *pw;//file password
			pw = fopen("userPassword.txt", "r");//open file to read
			
				while(!feof(pw))
			{
				
				fscanf(pw, "%[^\n]%*c", realPassword);
				rechange(realPassword);
				if(strcmp(password, realPassword) == 0)
				{
					//when your password is not correct
					//checkId(password);
					//printf("%d", id2);
					
					fclose(pw);// close file
					
					return id2;
				}
					id2++;// id of pasword
		
			}//end of small while
			}// end if follow 2
		// when enter wrong password	
		
		if(follow == 1)printf("\n\t\tYour username doesn't exist.");
		if(follow == 2)printf("\n\t\tYour account doesn't exist.");
		
		//printf("\n");
		//printf("\t\tEnter password: ");
		i = 0;
		id1 = 1;
		id2 = 1;
		fflush(stdin);
		//enterUserPassword();// the same function
		printf("\n\n");
		
		//enterUserPassword(follow);
		//return 0;
		
		if(follow == 1) printf("\t\tEnter Username: ");
		if(follow == 2) printf("\t\tEnter password: ");

		//	return 0;
		
		}
	
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			
			firstMenu();
			//this is firstMenu
			return 0;
			break;			
			
		}
		
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			
			trouble();
			enterUserAccount();
			//the same function
			return 0;//end
			break;
			//continue;
		}
		else if(i > 0 && ch > 255)
		{
			chj = getch();
			if(chj == 75)
			{
				j = i - 1;
				printf("\b");
				
			}
			else continue;
		}
		
		else if(follow == 1) 
		{  //make a chracter
			password[i] = ch;
			i++;
			printf("%c", ch);
			
		}
		else if(follow == 2) 
		{  //make a chracter to *
			password[i] = ch;
			i++;
			printf("*");
			
		}
	}
	
	
	//call other function
	return 1;
}//end of enterUserPassword function
	


int enterUserAccount()//with id
{
	
	int id1 = 1;
	int id2 = 1;
	
	int follow = 1;
	id1 = enterUserPassword(follow);
	
	if(id1 == 0)
	{
		return 0;
		//shut down enterUserPassword if wrong
	}
	
	// get student's code
	char stuCode[100];
	int temp = id1; //help to get student's code
	FILE *f;
	f = fopen("userUsername.txt", "r");

	while(temp >= 1)
	{
		fscanf(f, "%[^\n]%*c", stuCode);
		temp--;
	}
	
	
	follow = 2;
	id2 = enterUserPassword(follow);
	
	if(id2 == 0)
	{
		return 0;
		//shut down enterUserPassword if wrong
	}
	
	while(1)
	{
		fflush(stdin);
		//printf("\n\t\t   Your account doesn't exist");
		
		//fclose(f);//close file
		//enterUserAccount();// the same function
		
		if(id1 != id2)
		{
			printf("\n\t\tYour account doesn't exist");
			id2 = enterUserPassword(follow);//follow = 2
		}
		
		else 
		{
		fflush(stdin);
		system("cls");
		//id = id2;
		fclose(f);//close file
		menuOfUser(id2, stuCode);//call other function
	
		return id2;
		}
		
		
	} //end of while
	

	return 0;// end of function enterUserAccount
} // end of enterUserAccount
		

int checkNumber(int max)//check input is a integer or not
{
	// your requirement
	int num;
	int tmp;
	char word;
	
	do
	{
		fflush(stdin);
		tmp = scanf("%d%c", &num, &word);

		if(tmp != 2 || word != '\n')
		{
			textColor(4);//red
			printf("\t\tWrong!!\n");
			textColor(14);//yellow
			printf("\t\tYour requirement is: ");
			textColor(15);//default
		}
		else if(num < 1 || num > max)//limit integer
		{
			textColor(4);
			printf("\t\tWrong!!\n");
			textColor(14);
			printf("\t\tYour requirement is: ");
			textColor(15);
		}
	}while(tmp != 2 || word != '\n'|| num < 1 || num > max);
	
	return num;// input
	
}//end of checkNumber function


//arrange by title of book
void arrageByTitle() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. A -> Z\n");
	printf("\t\t2. Z -> A\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].name < *book[j-1].name) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].name > *book[j-1].name) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//arrange by category of book
void arrageByCate() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. A -> Z\n");
	printf("\t\t2. Z -> A\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].category < *book[j-1].category) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].category > *book[j-1].category) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//arrange by year established
void arrageByYear() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].year) < toNum(book[j-1].year)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].year) > toNum(book[j-1].year)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//arrange by quanlity
void arrageByQuanlity() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlity) < toNum(book[j-1].quanlity)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlity) > toNum(book[j-1].quanlity)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//arrange by number on bookself
void arrageByQuanlityAvai() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			char term[501];
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlityAvaiable) < toNum(book[j-1].quanlityAvaiable)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			char term[501];
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlityAvaiable) > toNum(book[j-1].quanlityAvaiable)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//arrange by number lending
void arrageByNumLending() {
	system("cls");
	printf("\n\n\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	textColor(15);
	
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
	printf("\t\t3. Back\n");
	printf("\t\t4. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(10);
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	int choice = getChoice(4);
	
	int numOfBook;
	importValue(&numOfBook);
	system("cls");
	printf("\n\n\n\n");
	
	switch (choice) {
		//a -> z
		case 1: {
			int i, j, temp;
			char term[501];
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if ((toNum(book[j].quanlity) - toNum(book[j].quanlityAvaiable) 
				    	< (toNum(book[j-1].quanlity) - toNum(book[j-1].quanlityAvaiable)))){
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();
			break;
		}
		
		//z -> a
		case 2: {
			int i, j, temp;
			char term[501];
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if ((toNum(book[j].quanlity) - toNum(book[j].quanlityAvaiable) 
				    	> (toNum(book[j-1].quanlity) - toNum(book[j-1].quanlityAvaiable)))) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						temp = book[j-1].code;
						book[j-1].code = book[j].code;
						book[j].code = temp;
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			
			printf("\t\tPress any key to continue");
			getch();			
			break;
		}
		
		//back
		case 3: {
			break;
		}
		
		//exit
		case 4: end();
	}
}

//print all book info menu
void printAllBookInfo() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		textColor(14);
		printf("\t\tChoose your requirement\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(35);
		textColor(15);
		
		printf("\t\t1. Arrange by title of book\n");
		printf("\t\t2. Arrange by category of book\n");
		printf("\t\t3. Arrange by year established\n");
		printf("\t\t4. Arrange by quanlity\n");
		printf("\t\t5. Arrange by number on bookself\n");
		printf("\t\t6. Arrange by number of lending\n");
		printf("\t\t7. Back\n");
		printf("\t\t8. Exit\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(35);
		
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);
		
		int choice = getChoice(8);
		
		switch (choice) {
			//arrage by title
			case 1: {
				arrageByTitle();
				break;
			}
			
			//arrage by category
			case 2: {
				arrageByCate();
				break;
			}
			
			//arrage by year
			case 3: {
				arrageByYear();
				break;
			}
			
			//arrage by quanlity
			case 4: {
				arrageByQuanlity();
				break;
			}
			
			//arrange by number on bookself
			case 5: {
				arrageByQuanlityAvai();
				break;
			}
			
			//arrage by number of lending
			case 6: {
				arrageByNumLending();
				break;
			}
			
			//back
			case 7: {
				yesNo = 'n';
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageEnterAdmin();
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					pageEnterUser(viewBooksInfo[0].stuCode, viewBooksInfo[0].newOrOld, viewBooksInfo[0].id, viewBooksInfo[0].maxStruct);
				}
				break;
			}
			
			//exit
			case 8: end();
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}


 int borrowBooks(int id)
{
	int i = 0;
	char code[20];
	char enterCode;
	
	printf("\n\n");
	printf("\t\tEnter book's code to borrow: ");
	
	
	
	while(1)
	{
		enterCode = getch();
		if(enterCode == ENTER)
		{
			code[i] = '\0';
			break;
		}
		else if(enterCode == ESC)
		{
			continue;
		}
		else if(enterCode == TAB)
		{
			continue;
		}
		else if(enterCode == BKSP)
		{
			if(i > 0)
			{
			printf("\b \b");
			i--;	
			}
		}
		else
		{
			code[i] = enterCode;
			i++;
			printf("%c", enterCode);
		}
	}//end while
	
	
	
	
	FILE *bb;//borrow books
	bb = fopen("BookCode.txt", "r");
	char cmpCode[20];
	int idb = 1;
	
	FILE *quantity;//quantity in library
	quantity = fopen("QuanlityAvai.txt", "r");//use idb
	int soLuongConLai[20];
	int soLuong;
	int tmp = 0; // help idp
	
	while(!feof(bb))
	{
		fscanf(bb,"%[^\n]%*c", cmpCode);//check book's code
		
		if(strcmp(code, cmpCode) == 0 )
		{
			printf("\n\t\tSucess!!");
			printf("  Check in your browwing list.");
			tmp = idb;
			/* xem xet so luong = 0
			while(tmp >= 0)
			{

				
				fscanf(quantity, "%[^\n]%*c", soLuongConLai);//check so luong con lai
				fgets(soLuong, 100, quantity);
				
				//bug
				/*
				if(soLuongConLai == 0)
				{
				  printf("khong con sach");
				  return 0;
				}
				//
				printf("%d\n", tmp);
				printf("%d", soLuongConLai);
				printf("soluong:%d", soLuong);
			
				
				tmp--;
				//return 0;
			}
			*/
			
			
			
			printf("id:%d\n", id);//id of user
			printf("idb:%d\n", idb);//id of book
			fclose(bb);//close file borrow books
			
			int t1 = id;//temp for id help borrowing list
			int t2 = idb;//temp for idp help borrowing list
			char borrow [100];
			
			FILE *bl;//borrowing list
			bl = fopen("borrowingList.txt", "r");
			int line = 0;//line in borrowingList
			
			while (!feof(bl)) // scan the line in borrowingList
			{
				
			fscanf(bl, "%[^\n]%*c", borrow);//scan line
			printf("123\n");
			line++;//how many line
			
			}//bug
			fclose(bl);// close file borrowingList 1
			
			printf("id: %d", t1);
			printf("line: %d", line);
			
			bl = fopen("borrowingList.txt", "a"); // write in borrowingList
			if(line < t1) //t1 is id of user
			{
				while(line < t1)//make line in brorrowingList
				{
					fprintf(bl ,"\n");
					//printf("%d", line);
					line++;
				}
			}
			
			
			//bl = fopen("borrowingList.txt", "a"); // write in borrowingList
			fprintf(bl, "%s\n", cmpCode);//print code book in borrowingList
			
			fclose(bl);
			
			getch();
			
			
//			menuOfUser(id, idb);
			//return 0;
			//printf("fsd");
		}
		idb++;
	}
	
	if(strcmp(code, cmpCode) != 0)
		{
			printf("\n\t\tWrong!!\n");
			borrowBooks(id);
			fclose(bb);
			return 0;
			//printf("fsd");
		}
		
		
		
		
	return 0;
}//end borrowBooks function

int spaceLeftSide(char string[100], short max) // print space in list dependent on len of string
{
	// max are space and string
	short num = 0;;
	if(max > strlen(string))
	{
		short follow = strlen(string);
		while(follow < max)
		{
			printf(" ");
			follow++;
			num++;
		}
	}
	return num;
} //end of spaceRightSide funciton


int wantString(int num, char string[3000])
{
	int count = 0, digit[3000];
	char letter;
	
	int i = 0; // num in array
	
	while (num != 0)
	{
		digit[count] = num % 10;
		num = num / 10;
		count++;
	}
	
	count--;
	
	while (count >= 0) 
	{
		letter = digit[count] + 48;
		count--;
		string[i] = letter;
		i++;
	}
	i--; // superfuous
	//printf("%s", string);
	return *string;
} // end of wantString function

void makeLine(unsigned short max)
{
	unsigned short newLine = 0;
	for(; newLine < max; newLine++)
	{
		printf("\n");
	}
}

void makeTab(int unsigned max)
{
	int unsigned tab = 0;
	for( ; tab < max; tab++)
	{
		printf("\t");
	}
}

void override(int unsigned lenOfString) // only space
{
	int i = 0;
	for( ; i < lenOfString; i++)
	{
		printf("\b");
	}
	for( i = 0 ; i < lenOfString; i++)
	{
		printf(" ");
	}
}

void moonwalk(int unsigned max)
{
	int i = 0;
	for( ; i < max; i++)
	{
		printf("\b");
	}
}

void spaceRightSide(char string[100], short max) // print space in list dependent on len of string
{
	// max are space and string
	if(max > strlen(string))
	{
		short follow = strlen(string);
		while(follow < max)
		{
			printf(" ");
			follow++;
		}
	}
	else
	{
		printf("  "); //only divide
	}
} //end of spaceRightSide funciton
/*
int cleanArray(char array[100])
{
	
	short i = 0;
	while(i <= 100)
	{
		
		array[i] = NULL;
		i++;
	}
	
	return *array;
} // end of cleanArray function
*/
int intel(int max, int more) // intel
{
	long mutation;
	srand(time(NULL)+ more);
	mutation = rand() % max; // from 0 -> max-1 
	
	return mutation;
}
void copyArray(char paste[100], char copy[100])
{
	int i = 0;
	while (copy[i] != '\0')
		{
			paste[i] = copy[i];
			i++;
		}
} // end of copyArrayToStruct

void copyArrayToStruct(char array[200], char mainArray[100], int lenOfString)
{
	int j = 0;
	while (j < lenOfString)
		{
			array[j] = mainArray[j];
			//printf("%c", viewBooksInfo[i].codeBook[j]);
			j++;
		}
} // end of copyArrayToStruct


int arrangeNameAZ()
{
	int numOfBook;
	importValue(&numOfBook);

	//printf("%d", numOfBook);
	int i, j, temp;
	char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
	
			for (i = 0; i < numOfBook; i++) {
				//wantString(book[i].code, book[i].strCode);
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].name < *book[j-1].name) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			/*
			int check = 1, check2 = 0;
			for (i = 0; i < numOfBook; i++) {
				printInfo(&check, &check2, i);
			}
			*/
	return numOfBook;
}

int arrangeNameZA()
{
	int numOfBook;
	importValue(&numOfBook);
	char tmp[100];
	
	
	int i, j, temp;
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].name > *book[j-1].name) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
	return numOfBook;
} // end of arrangeNameZA

int arrangeCateAZ()
{
		int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].category < *book[j-1].category) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	
	return numOfBook;
} // end of arrangeCateAZ

int arrangeCateZA()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
	
	char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (*book[j].category > *book[j-1].category) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeCateZA

int arrangeEstabAscending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
	char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].year) < toNum(book[j-1].year)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeEstabAscending

int arrangeEstabDescending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
	char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].year) > toNum(book[j-1].year)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeEstabDescending

int arrangeQuanAscending()
{
			int numOfBook;
	importValue(&numOfBook);
		int i, j, temp;
		char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlity) < toNum(book[j-1].quanlity)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);
						

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeQuanAscending

int arrangeQuanDescending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
	char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
	
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlity) > toNum(book[j-1].quanlity)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeQuanDescending

int arrangeQuanAvaiAscending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
			char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlityAvaiable) < toNum(book[j-1].quanlityAvaiable)) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeQuanAvaiAscending

int arrangeQuanAvaiDescending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
			char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if (toNum(book[j].quanlityAvaiable) > toNum(book[j-1].quanlityAvaiable)) {
						
						char term[100];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeQuanDescending

int arrangeQuanLendingAscending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
			char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if ((toNum(book[j].quanlity) - toNum(book[j].quanlityAvaiable) 
				    	< (toNum(book[j-1].quanlity) - toNum(book[j-1].quanlityAvaiable)))){
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
			
	return numOfBook;
} // end of arrangeQuanLendingAscending

int arrangeQuanLendingDescending()
{
			int numOfBook;
	importValue(&numOfBook);
	int i, j, temp;
			char tmp[100];
	
	for (i = 0; i < numOfBook; i++)
	{
		wantString(book[i].code, tmp);
		strcpy(book[i].strCode, tmp);
	}
			
			for (i = 0; i < numOfBook; i++) {
				for (j = numOfBook - 1; j > i; j--) {
					if ((toNum(book[j].quanlity) - toNum(book[j].quanlityAvaiable) 
				    	> (toNum(book[j-1].quanlity) - toNum(book[j-1].quanlityAvaiable)))) {
						
						char term[501];
						strcpy(term, book[j-1].category);
						strcpy(book[j-1].category, book[j].category);
						strcpy(book[j].category, term);
						
						//temp = book[j-1].code;
						//book[j-1].code = book[j].code;
						//book[j].code = temp;
						strcpy(term, book[j-1].strCode);
						strcpy(book[j-1].strCode, book[j].strCode);
						strcpy(book[j].strCode, term);
						
						//wantString()
						strcpy(term, book[j-1].name);
						strcpy(book[j-1].name, book[j].name);
						strcpy(book[j].name, term);

						
						strcpy(term, book[j-1].quanlity);
						strcpy(book[j-1].quanlity, book[j].quanlity);
						strcpy(book[j].quanlity, term);
						
						strcpy(term, book[j-1].quanlityAvaiable);
						strcpy(book[j-1].quanlityAvaiable, book[j].quanlityAvaiable);
						strcpy(book[j].quanlityAvaiable, term);
						
						strcpy(term, book[j-1].year);
						strcpy(book[j-1].year, book[j].year);
						strcpy(book[j].year, term);
					}
				}
			}
	return numOfBook;
} // end of arrangeQuanLendingDescending

int loadBooksArrange(int numOfBook)
{
	//int numOfBook;
	//importValue(&numOfBook);
	int i = 0;
	int j = numOfBook;
	char code[3000];
	int temp;
	
	//File *fcode;
	//fcode = fopen("BookCode.txt", "r");
	
	for(i = 0; i < numOfBook; i++)
	{
		//toString(viewBooksInfo[i].codeBook, temp, 0);
		//wantString(book[i].code, viewBooksInfo[i].codeBook);
		//printf("%dfd", book[i].code);
		//getch(); code
		strcpy(viewBooksInfo[i].codeBook, book[i].strCode);
		//fscanf(fcode, "%[^\n]%*c", viewBooksInfo[i].codeBook);
	}
	for(i = 0; i < numOfBook; i++)
	{
		strcpy(viewBooksInfo[i].nameBook, book[i].name);		
	}
	for(i = 0; i < numOfBook; i++)
	{
		strcpy(viewBooksInfo[i].cateBook, book[i].category);
	}
	for(i = 0; i < numOfBook; i++)
	{
		//wantString(book[i].year, estab);
		strcpy(viewBooksInfo[i].estabBook, book[i].year);
	}
	for(i = 0; i < numOfBook; i++)
	{
		//wantString(book[i].year, estab);
		strcpy(viewBooksInfo[i].quanBook, book[i].quanlity);
	}
	for(i = 0; i < numOfBook; i++)
	{
		//wantString(book[i].year, estab);
		strcpy(viewBooksInfo[i].quanAvaiBook, book[i].quanlityAvaiable);
	}
	/*
	for(i = 0; i <numOfBook; i++)
	{
		printf("%s", viewBooksInfo[i].nameBook);
	}
	printf("\n\n");
	for(i = 0; i <numOfBook; i++)
	{
		printf("%s\n\n", book[i].name);
	}
	*/
//	fclose(fcode);
	return j; // num of struct
} // end of loadBooksArrange



int arrangeTitle(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
			printf("\t\t1. A-Z\n");
			printf("\t\t2. Z-A\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeNameAZ(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeNameZA();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}
				//pageEnterUser(stuCode, newOrOld, id, i);
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeTitle

int arrangeCate(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
			printf("\t\t1. A-Z\n");
			printf("\t\t2. Z-A\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeCateAZ(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeCateZA();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeCate

int arrangeEstab(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeEstabAscending(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeEstabDescending();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeEstab

int arrangeQuan(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeQuanAscending(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeQuanDescending();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeQuan

int arrangeQuanAvai(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeQuanAvaiAscending(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeQuanAvaiDescending();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}	page(stuCode, newOrOld, id, i); // id is not used
				
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeQuanAvai

int arrangeQuanLending(char stuCode[100], int newOrOld, int id, int i)
{
	int numOfBook = 0; // how many books
		printf("\n");
	printf("\t\t1. Ascending\n");
	printf("\t\t2. Descending\n");
			printf("\t\t3. Back\n");
			printf("\t\t4. Exit\n");
			
			textColor(Gold);
			makeTab(2);
			drawLine(25);
			textColor(White);
			int choice = checkChoice(4);
			
			if(choice == 1) // A-Z
			{
				numOfBook = arrangeQuanLendingAscending(); // load books in strange function
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 1 A-Z
		
			if(choice == 2) // Z-A
			{
				numOfBook = arrangeQuanLendingDescending();
				i = loadBooksArrange(numOfBook); // copy to struct
				system("cls");
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					pageAdmin(viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					page(stuCode, newOrOld, id, i); // id is not used
				}
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 2 Z-A
		
			if(choice == 3) // back to enter to user more feature
			{
				if(viewBooksInfo[0].adminOrUser == 0)
				{
					arrange(' ', 0, 0, viewBooksInfo[0].maxStruct);
				}
				else if(viewBooksInfo[0].adminOrUser == 1)
				{
					arrange(stuCode, newOrOld, id, i);
				}
				
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of 3 back
		
			if(choice == 4) // exit
			{
				end();
				return 0;
			} // end of if 4
			
	return 0;
} // end of arrangeQuanLending

int arrange(char stuCode[100], int newOrOld, int id, int i)
{
	
		printf("\n");
		textColor(Gold);
		makeTab(2);
		drawLine(35);
		textColor(White);
		printf("\t\t1. Arrange by title of book\n");
		printf("\t\t2. Arrange by category of book\n");
		printf("\t\t3. Arrange by year established\n");
		printf("\t\t4. Arrange by quanlity\n");
		printf("\t\t5. Arrange by number on bookself\n");
		printf("\t\t6. Arrange by number of lending\n");
		printf("\t\t7. Back\n");
		printf("\t\t8. Exit\n");
		
		textColor(Gold);
		makeTab(2);
		drawLine(35);
		textColor(White);
		int choice = checkChoice(8);
	
	if(choice == 1)
	{
		arrangeTitle(stuCode, newOrOld, id, i);
		
	} // end of if 1 Arrange by title of book
	
	if(choice == 2)
	{
		arrangeCate(stuCode, newOrOld, id, i);
		
	}
	
	if(choice == 3)
	{
		
		arrangeEstab(stuCode, newOrOld, id, i);
		
	}
	
	if(choice == 4)
	{
		arrangeQuan(stuCode, newOrOld, id, i);
		
	}
	
	if(choice == 5)
	{
		arrangeQuanAvai(stuCode, newOrOld, id, i);
		
	}
	
	if(choice == 6)
	{
		arrangeQuanLending(stuCode, newOrOld, id, i);
		
	}
	
	if(choice == 7)
	{
		if(viewBooksInfo[0].adminOrUser == 0)
		{
			pageEnterAdmin(' ', 0, 0, viewBooksInfo[0].maxStruct);
		}
		
		else if(viewBooksInfo[0].adminOrUser == 1)
		{
			pageEnterUser(stuCode, newOrOld, id, i);
		}
		// code of user, new or old user, id in txt, max num in struct(all books)
	} // end of big if choice 3
	
	if(choice == 8) // exit
	{
		end();
	} // enf of big if choice 4
	
	return 0;
} // end of arrange

int pageEnterUser(char stuCode[100], int newOrOld, int id, int i) // newOrOld, id is not used
// code of user, new or old user, id in txt, max num in struct(all books)
{
	int numOfBook = 0; // how many books
	//numOfBook = arrangeNameAZ(); // load books in strange function
	//loadBooksArrange(numOfBook); // copy to struct
	
	printf("\n");
	makeTab(3);
	textColor(Blue);
	printf("AI: These features will interact with books list.");		
	printf("\n");
	
	textColor(14);
	makeTab(2);
	drawLine(30);
	textColor(15);
	
	printf("\t\t1. Search.\n");
	printf("\t\t2. Arrange.\n");
//	printf("\t\t3. Print all books.\n");
	printf("\t\t3. Back.\n");
	printf("\t\t4. Exit.\n");
	
	textColor(14);
	makeTab(2);
	drawLine(30);
	
	textColor(15);
	int choice = checkChoice(4);
	
	if(choice == 1)
	{
		search();
	}
	
	if(choice == 2)
	{
		arrange(stuCode, newOrOld, id, i);
	} // end of medium if choice 2
	
/*	if(choice == 3)
	{
		printAllBookInfo();
	}*/
	
	if(choice == 3) // back
	{
		system("cls");
		menuOfUser(id, stuCode);
		//pageEnterUser(stuCode, newOrOld, id, i);
		// code of user, new or old user, id in txt, max num in struct(all books)
	} // end of big if choice 3
	
	if(choice == 4) // exit
	{
		end();
		return 0;
	} // enf of big if choice 4
	
	return 0;
}

int now(int *dayNow, int *monthNow, int *yearNow) // getDate
{
	long second = Time - 60 - 36000 - (31536000 * 36) - ( (31536000 + 86400) * 12 ) - (3600 * 4) - (3600 * 3);
	long i = 0;
	int day = 1;
	int month = 1;
	int year = 2018;
	int hour = 0;
	int minute = 0;
	
	for(i = 0; i <= second; i++)
	{
		if(i % (24*3600) == 0)
		{
			day++;
			if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
			{
				day = 1;
			}
			else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			{
				day = 1;
			}
			else if((month == 2 && ((year % 400 == 0 ||  (year % 4 == 0 && year % 100 != 0) ) ) ) && day > 29 )
			{
				day = 1;
			}
			else if (month == 2 && day > 28)
			{
				day = 1;
			}
			month = (day == 1) ? month + 1 : month;
			year = (month > 12) ? year + 1 : year;
			month = (month > 12) ? 1 : month;
		}
		
		//hour = (i % 3600 == 0) ? hour + 1 : (hour = (hour > 24) ? 0 : hour);
		/*
		if(i % 60 == 0)
		{
			minute++;
			if(minute > 59)
			{
				minute = 0;
			}
		}
		*/
	} // end of for

	*dayNow = day;
	*monthNow = month;
	*yearNow = year;
	
	//printf("%d/%d/%d", day, month, year);
	
	//FILE *bday;
	//bday = fopen("borrowingDay.txt", "a");
	//fprintf(bday, "%ld\n", second);
	
	//fclose(bday);
	
	//printf("\n%4d   %4d   %4d   %4d", second, day, month, year);
	//printf("\n%d    %d", hour, minute);
	return second;
} // end of now function

int nowFinish(long second)
{
	FILE *bday;
	bday = fopen("borrowingDay.txt", "a");
	fprintf(bday, "%ld\n", second);
	
	fclose(bday);
	return 0;
} // end of nowFinish


int returningDay(long second ,int deadline)
{
	long clock = second + (deadline * 3600);
	
	FILE *fclock;
	fclock = fopen("returningDay.txt", "a");
	fprintf(fclock, "%ld", clock);
	
	fclose(fclock);
	return 0;
} // end of returningDay

void voiceMenuOfAdmin(int mutation)
{
	textColor(11);
	printf("AI: ");
	if(mutation == 0) printf("Welcom to Harsh Library!");
	if(mutation == 1) printf("Nice too meet you.");
	if(mutation == 2) printf("You're an important person can help Harsh Library becomes better.");
	if(mutation == 3) printf("Everything is going well?");
	if(mutation == 4) printf("Don't be lazy when you're admin.");
	if(mutation == 5) printf("Do not overwork.");
	if(mutation == 6) printf("Stay health.");
	if(mutation == 7) printf("Good day to work?");
	if(mutation == 8) printf("How have you been?");
	if(mutation == 9) printf("Have a nice day.");
	//if(mutation == 5) printf("Be careful when checking the information");
	textColor(15);
}

void voiceAfterMenuOfAdmin(int mutation)
{
	textColor(11);
	printf("AI: ");
	if(mutation == 0) printf("Be careful when checking the information!");
	if(mutation == 1) printf("You need to focus on your goal.");
	if(mutation == 2) printf("Don't be lazy.");
	if(mutation == 3) printf("Don't forget your missons.");
	if(mutation == 4) printf("Remember your schedule.");
	if(mutation == 5) printf("I hope you finish your work well.");
	textColor(15);
}

void voiceMenuOfUser(int mutation)
{
	textColor(11);
	printf("AI: ");
	if(mutation == 0) printf("Harsh Library is a place where you can find thousands books.");
	if(mutation == 1) printf("Welcom to Harsh Library!");
	if(mutation == 2) printf("Be a smart person.");
	if(mutation == 3) printf("Harsh Library is a knowledge storage.");
	if(mutation == 4) printf("Don't be a lazy person");
	if(mutation == 5) printf("Try to have new experiments.");
	if(mutation == 6) printf("Thousands books are waitting for you.");
	if(mutation == 7) printf("Knowledge is power so try to improve your knowledge.");
	if(mutation == 8) printf("Genius is 1%% inspriration and 99%% perspriration.");
	if(mutation == 9) printf("The only source of knowledge is experience.");
	textColor(15);
}


void voicePageRecOld(int mutation)
{
	textColor(11);
	printf("AI: ");
	if(mutation == 0) printf("Some books you may like.\n");
	if(mutation == 1) printf("I have some books for you.\n");
	if(mutation == 2) printf("I have some books like category you usually read.\n");
	if(mutation == 3) printf("Try to read some new books.\n");
	if(mutation == 4) printf("I hope you like these books.\n");
	if(mutation == 5) printf("I have found some books you may want to read.\n");
	if(mutation == 6) printf("Here are recommend books.\n");
	if(mutation == 7) printf("I want to recommend books to you.\n");
	textColor(15);
}

void voiceRemind(int mutation)
{
	textColor(Blue);
	printf("AI: ");
		 if(mutation == 0) printf("Pay attention! Remember to return books before deadline.");
	else if(mutation == 1) printf("Don't forget to return books.");
	else if(mutation == 2) printf("You haven't returned books to Harsh Library.");
}


struct searchBox
{
	char yearEstabBox[100];
	
};
//struct search wantSearch[1000];

int searchNum(char search[100], int orderOfBook[100])
{
	int subOrder = 0;
	int i = 0; // num in struct
	int j = 0; // num array
	struct searchBox wantSearch[1000];
	FILE *fsearchNum;
	fsearchNum = fopen("YearEstab.txt", "r");
	char yearEstab[100];
	
	while(!feof(fsearchNum))
	{
		fscanf(fsearchNum, "%[^\n]%*c", yearEstab);
		if(strcmp(search, yearEstab) == 0)
		{
			while(yearEstab[j] != '\0')
			{
			
			wantSearch[i].yearEstabBox[j] = yearEstab[j];
			j++;
			}
			
			i++;
		}
		j = 0; // reset num in array
		//subOrder++;
	}
	//j = i; // get max in struct
	//i = 0; // reser num int struct
	while(i >= 0)
	{
		printf("%s", wantSearch[i].yearEstabBox);printf("sdf");
		i--;
	}
	
	fclose(fsearchNum);
	return 0;
	
} // end of searchNum function


int getSearch()
{
	char search[100];
	char ch;
	short i = 0;
	short call = 0;
	int orderOfBook[100];
	gets(search);
	
	if(search[0] >= 48 && search[0] <= 57)
	{
		searchNum(search, orderOfBook);
	}
	
	
} // end of getSearch function

int loadUserPassword()
{
	int i = 0;
	File *f;
	f = fopen("userPassword.txt", "r");
	char tmp[100];
	
	while(!feof(f))
	{
		fscanf(f, "%[^\n]%*c", tmp);
		rechange(tmp);
		strcpy(viewBooksInfo[i].userPassword, tmp);
		i++;
		//printf("%s", viewBooksInfo[i].userPassword);
	}
	i -= 2; // superfluous txt
	fclose(f);
	return i;
} // end of loadUserAccount


int enterUserChangePassword(int id, char stuCode[100], short order)
{
	if(order == 1) printf("\n\n\t\tEnter password: ");
	else if(order == 2) printf("\n\n\t\tEnter new password: ");
	else if(order == 3) printf("\n\n\t\tEnter new password again: ");
	
	int istruct = loadUserPassword();
	int i = 0;
	int j = 0;
	
	char ch;
	char password[100];
	char newPassword[100];
	char newPassword2[100];
	
		while(1)
	{
		ch = getch();
		if(ch == ENTER)
		{
			if(order == 1) password[i] = '\0';
			else if(order == 2) newPassword[i] = '\0';
			else if(order == 3) newPassword2[i] = '\0';
			
			if(order == 1)
			{
				for(j = 0; j <= istruct; j++)
				{
					
					if(strcmp(password, viewBooksInfo[j].userPassword) == 0)
					{
						textColor(Gold);
						printf("\tOK!!");
						textColor(White);
						return 0;
					}
				}
				i = 0;
				textColor(Red);
				printf("\tWrong!!");
				textColor(White);
				printf("\n\n\t\tEnter password: ");
				continue;
				
			} // if order 1
			/*
			else
			{
				i = 0;
				textColor(Red);
				printf("\tWrong!!");
				textColor(White);
				printf("\n\n\t\tEnter password: ");
				continue;
			} // else order 1
			*/
			if (order == 2)
			{
				if(strcmp(newPassword, password) != 0) // different
				{
					textColor(Gold);
					printf("\tOK!!");
					textColor(White);
					return 0;
				}
				else
				{
					printf("\n\t\tNew Pasword must different from old password.");
					printf("\n\n\t\tEnter new password: ");
					i = 0;
					continue;
				}
				
			} // if order 2
			if(order == 3)
			{
				if(strcmp(newPassword2, newPassword) == 0)
				{
					
					//for(j = 0; j < id; j++)
					//{
						strcpy(viewBooksInfo[id - 1].userPassword, newPassword);
					//}
					File *fnp;
					fnp = fopen("userPassword.txt", "w");
					for(j = 0; j <= istruct; j++)
					{
						change(viewBooksInfo[j].userPassword);
						fprintf(fnp ,"%s\n",viewBooksInfo[j].userPassword);
					}
					fclose(fnp);
					textColor(Gold);
					printf("\tSucess!!");
					textColor(White);
					printf("\n\t\tPress a key to continue...");
					getch();
					system("cls");
					menuOfUser(id, stuCode);
					return 0;
				}
				else
				{
					i = 0;
					textColor(Red);
					printf("\tWrong!!");
					textColor(White);
					printf("\n\n\t\tEnter new password again: ");
					continue;
				}
			} // end of if order 3
		} // enter
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			menuOfUser(id, stuCode);
			//this is menu of admin
			return 1;
			break;			
			
		}
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			userChangePassword(id, stuCode);
			//the same function
			return 1;
			//continue;
		}
		else
		{
			if(order == 1)password[i] = ch;
			else if(order == 2) newPassword[i] = ch;
			else if(order == 3) newPassword2[i] = ch;
			i++;
			printf("*");
		}
		
	} // end of while 1
	return 0;
} // end of enterUserChangePassword

int userChangePassword(int id, char stuCode[100])
{
	trouble();
	short order = 1;
	short shutdown = -1;
	
	shutdown = enterUserChangePassword(id, stuCode, order);
	if(shutdown == 1) return 0;
	
	order = 2;
	shutdown = enterUserChangePassword(id, stuCode, order);
	if(shutdown == 1) return 0;
	
	order = 3;
	shutdown = enterUserChangePassword(id, stuCode, order);
	if(shutdown == 1) return 0;
	
	return 0;
} // end of userChangePassword

int viewBooksInfoOption(int i, int wall, int lastWall) // i is a num in struct to prevent
{
	
	char leader; // the first character since typed
	char walker; // the second character since typed
	
	
	while(1)
	{
		leader = getch(); // the first
		if(leader >= 0 && leader <= 255)
		{
			if(leader == ENTER) // want to search / use other features
			{
				return 3;
			}
			if(leader == ESC)
			{
				
				return 4;
			}
			// wrong condition
			continue;
		}
		walker = getch(); // the second
		
		// when enter correct left and right
		if((walker == 75 || walker == 77))
		{
			if(walker == 75)
			{
				if(i < wall )
				{
					continue;
				}
				fflush(stdin);
				return 1; // left
			}
			if(walker == 77) 
			{
				if(i >= lastWall) // or slide in page funciton
				{
					
					continue;
				}
				fflush(stdin);
				return 2; // right
			}
			
		}
	
		
	} // end of big while
	
	
	
	return 0;
} // end of viewBooksInfoOption function

void titleOfRec()
{
	printf("\n");
	printf("\t\t ");
	//printf("\t\t  Code\t\tName Of Book\t\tCategory\tYear Established\n");
	printf("\t\t  Code                   Name Of Book            Category    Year Established\n");
	
	printf("\t\t");
}


void titleOfPage() // fist in page
{
	
	printf("\n\n\n");
	textColor(14);
	printf("\t\t  Books In Library:\n\n");
	textColor(15);
	//printf("\t\t  Code\t\t\tName Of Book\t\tCategory\tYear Established\tQuantity   Number on bookshelf   Number of lending\n");
	printf("\t\t  Code\t\t\tName Of Book               Category        Year Established    Quantity    Number on bookshelf   Number of lending\n");

	printf("\t\t");
	
}


int membership(char stuCode[100])
{
	int newOrOld = 0; // new = 0
	// new or old user
	FILE *fmember;
	fmember = fopen("StudentCodeRent.txt", "r");
	char member[100];
	char white[100];
	while(!feof(fmember))
	{
		fscanf(fmember, "%[^\n]%*c", member);
		if(strcmp(member, stuCode) == 0)
		{
			newOrOld++;
		}
		member[0] = ' ';
	}
	fclose(fmember);
	return newOrOld;
} // end of membership function


void menuOfUser(int id, char stuCode[100])//need id in enterUserAccount
{
	int choose = 0;
	char word;
	int tmp = 0;
	int tmp2 = 0;
	
	int newOrOld = 0;
	newOrOld = membership(stuCode);
	//printf("code %s", stuCode);
	//printf("\n%d", newOrOld)
	
	makeLine(4);
	makeTab(3);
	int mutation = intel(10, 0);
	voiceMenuOfUser(mutation);
	
	int i = loadBooks(); // all info of books
	
	viewBooksInfo[0].id = id;
	viewBooksInfo[0].maxStruct = i;
	viewBooksInfo[0].newOrOld = newOrOld;
	strcpy(viewBooksInfo[0].stuCode, stuCode);
	viewBooksInfo[0].adminOrUser = 1;
	
	makeLine(3);
	makeTab(3);
	textColor(14);
	printf("---/~~Harsh Library~~/---");
	textColor(15);
	
	printf("\n\n");
	textColor(14);
	printf("\t\tChoose your requirement\n");
	
	textColor(Blue);
	printf("\t\t");
	drawLine(40);//-------------------
	
	textColor(15);
	printf("\t\t1. Informations of books\n");//should change
	printf("\t\t2. History of borrowing\n");
	printf("\t\t3. Change password\n");
	printf("\t\t4. Back\n");
	printf("\t\t5. Exit\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(40);//-----------------
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	
	choose = checkNumber(5);// max choice can be changed
	
		switch(choose)
	{
		case 1:
			fflush(stdin);
			system("cls");
			page(stuCode, newOrOld, id, i); // id is not used
			// code of user, new or old user, id in txt, max num in struct(all books)
			break;
		
		case 2://want to borrow books
			system("cls");
			borrowingList(id, stuCode);//need id
			break;
		
		case 3: // user change password
			system("cls");
			userChangePassword(id, stuCode);
			break;
		
		case 4://want to back
			fflush(stdin);
			system("cls");
			firstMenu();//call other function
			
			break;
		
		case 5://want to exit
			
		system("cls");
		end();
		/*
		default:
		// never should use
		fflush(stdin);
		system("cls");
		
		menuOfUser(id, idb);
		// the same function
		//printf("\n   Wrong!!\n");
		break;
		*/
	}
	
	
} // end of menuOfUser function

int escape()
{
	char ch;
	
	while(1)
	{
		ch = getch();
		if(ch == ESC)
		{
			fflush(stdin);
			system("cls");
			return 1;
		}
		else
		{
			fflush(stdin);
			continue;
		}
	}
	
} //end of escape function


//import user name rent
int importUserNameRent(){
	int i = 0;
	
	FILE* f = fopen("StudentCodeRent.txt", "r");
	while (!feof(f)){
		fscanf(f, "%[^\n]%*c", rent[i].userName);
		i++;
	}
	
	fclose(f);
	if (*rent[0].userName == '\0') return 0;
	return i;
}

//export user rent
void exportUserNameRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("StudentCodeRent.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%s", rent[i].userName);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import title of book rent
void importTitleRent(){
	int i = 0;
	
	FILE* f = fopen("TitleRent.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%[^\n]%*c", rent[i].title);
		i++;
	}
	fclose(f);
}

//export title of rent
void exportTitleRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("TitleRent.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%s", rent[i].title);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import return status
void importReturnStatus(){
	int i = 0;
	
	FILE* f = fopen("ReturnStatus.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].returnStatus);
		i++;
	}
	fclose(f);
}

//export return status
void exportReturnStatus(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("ReturnStatus.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].returnStatus);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import day return
void importDayReturn() {
	int i = 0;
	FILE* f = fopen("DayReturn.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d%*c", &rent[i].dayReturn);
		i++;
	}
	fclose(f);
}

//export day return
void exportDayReturn(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("DayReturn.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].dayReturn);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}


//import day rent
void importDayRent(){
	int i = 0;
	
	FILE* f = fopen("DayRent.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].day);
		i++;
	}
	fclose(f);
}

//export day rent
void exportDayRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("DayRent.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].day);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import day deadline
void importDayEnd(){
	int i = 0;
	
	FILE* f = fopen("DayDeadline.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].dayEnd);
		i++;
	}
	fclose(f);
}

//export day deadline
void exportDayEnd(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("DayDeadline.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].dayEnd);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import month return
void importMonthReturn(){
	int i = 0;
	
	FILE* f = fopen("MonthReturn.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].monthReturn);
		i++;
	}
	fclose(f);
}

//export month return
void exportMonthReturn(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("MonthReturn.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].monthReturn);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}


//import month rent
void importMonthRent(){
	int i = 0;
	
	FILE* f = fopen("MonthRent.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].month);
		i++;
	}
	fclose(f);
}

//export month rent
void exportMonthRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("MonthRent.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].month);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import month deadline
void importMonthEnd(){
	int i = 0;
	
	FILE* f = fopen("MonthDeadline.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].monthEnd);
		i++;
	}
	fclose(f);
}

//export month deadline
void exportMonthEnd(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("MonthDeadline.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].monthEnd);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import year return
void importYearReturn(){
	int i = 0;
	
	FILE* f = fopen("YearReturn.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].yearReturn);
		i++;
	}
	fclose(f);
}

//export year return
void exportYearReturn(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("YearReturn.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].yearReturn);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import year rent
void importYearRent(){
	int i = 0;
	
	FILE* f = fopen("YearRent.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].year);
		i++;
	}
	fclose(f);
}

//export year rent
void exportYearRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("YearRent.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].year);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import year deadline
void importYearEnd(){
	int i = 0;
	
	FILE* f = fopen("YearDeadline.txt", "r");
	while (!feof(f)){
		fscanf(f, "%d%*c", &rent[i].yearEnd);
		i++;
	}
	fclose(f);
}

//export year deadline
void exportYearEnd(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("YearDeadline.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].yearEnd);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import date return
void importDateReturn() {
	importDayReturn();
	importMonthReturn();
	importYearReturn();
}

//import code rent
void importCodeRent() {
	int i = 0;
	
	FILE* f = fopen("RentCode.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d%*c", &rent[i].codeRent);
		i++;
	}
	fclose(f);
}

//export code rent
void exportCodeRent(int numOfRent, int newStatus, int editStatus) {
	int i = 0;
	
	FILE* f = fopen("RentCode.txt", "w");
	
	for (i = 0; i < numOfRent + newStatus; i++) {
		fprintf(f, "%d", rent[i].codeRent);
		if (editStatus) {
			if (i != (numOfRent - 1)) fprintf(f, "%c", '\n');	
		} else if (i != numOfRent) fprintf(f, "%c", '\n');
	}
	fclose(f);
}

//import rent value
void importRentValue(int* numOfRent) {
	*numOfRent = importUserNameRent();
	importCodeRent();
	importDayRent();
	importMonthRent();
	importReturnStatus();
	importYearRent();
	importTitleRent();
	importDayEnd();
	importMonthEnd();
	importYearEnd();
}

//export rent value
void exportRentValue(int numOfRent, int newStatus, int editStatus) {
	exportUserNameRent(numOfRent, newStatus, editStatus);
	exportCodeRent(numOfRent, newStatus, editStatus);
	exportDayRent(numOfRent, newStatus, editStatus);
	exportMonthRent(numOfRent, newStatus, editStatus);
	exportYearRent(numOfRent, newStatus, editStatus);
	exportReturnStatus(numOfRent, newStatus, editStatus);
	exportDayEnd(numOfRent, newStatus, editStatus);
	exportMonthEnd(numOfRent, newStatus, editStatus);
	exportYearEnd(numOfRent, newStatus, editStatus);
	exportTitleRent(numOfRent, newStatus, editStatus);
}

//export date return
void exportDateReturn(int numOfRent, int newStatus, int editStatus) {
	exportDayReturn(numOfRent, newStatus, editStatus);
	exportMonthReturn(numOfRent, newStatus, editStatus);
	exportYearReturn(numOfRent, newStatus, editStatus);
}

//set extra value for book rent
void setExtraBookRentInfo() {
	int numOfBook, numOfRent;
	importValue(&numOfBook);
	importRentValue(&numOfRent);
	
	int i;
	for (i = 0; i < numOfRent; i++) {
		int j;
		for (j = 0; j < numOfBook; j++) {
			if (strcmp(rent[i].title, book[j].name) == 0) {
				strcpy(rent[i].category, book[j].category); 
				rent[i].yearEstablished = toNum(book[j].year);
				break;
			}
		}
	}
}

//print title for borrowing info
int printTitleBorrowingInfo(int check){
	if (check) {
		int i;
		printf("\n\t\tCode:");//5
		for (i = 0; i < 10; i++) printf(" ");
		
		printf("Student's Name "); //15
		for (i = 0; i < 20; i++) printf(" ");
		
		printf("Student's Code ");//15
		for (i = 0; i < 10; i++) printf(" ");
		
		printf("Title of Book  ");//15
		for (i = 0; i < 25; i++) printf(" ");
		
		printf("Date borrow");//11
		for (i = 0; i < 19; i++) printf(" ");
		
		printf("Deadline\n");//8
//		for (i = 0; i < 22; i++) printf(" ");
		
//		printf("Return Status\n");//13
	}
	return 0;
}

//print title for return info
int printTitleReturnInfo(int check){
	if (check) {
		int i;
		printf("\n\t\tCode:");//5
		for (i = 0; i < 10; i++) printf(" ");
		
		printf("Student's Name "); //15
		for (i = 0; i < 20; i++) printf(" ");		
		
		printf("Student's Code ");//15
		for (i = 0; i < 10; i++) printf(" ");
		
		printf("Title of Book  ");//15
		for (i = 0; i < 25; i++) printf(" ");
		
		printf("Date borrow");//11  
		for (i = 0; i < 9; i++) printf(" "); // old is 19
		
		printf("Date return\n");//11
//		for (i = 0; i < 22; i++) printf(" ");
		
//		printf("Return Status\n");//13
	}
	return 0;
}

void printStudentName(int i) {
	
	char term[9];
	int j = 0;
	FILE* f = fopen("userUsername.txt", "r");
	do {
		fscanf(f, "%[^\n]%*c", term);
		if (strcmp(term, rent[i].userName) != 0) j++;
	} while (strcmp(term, rent[i].userName) != 0);
	fclose(f);
	
	char term2[101];
	f = fopen("nameOfStudents.txt", "r");
	int j2 = 0;
	do {
		fscanf(f, "%[^\n]%*c", term2);
		if (j2 != j) j2++;
		else break;
	} while (1);
	fclose(f);
	
	toUpper(term2);
	int i2;			
	if (35 >= strlen(term2)) {
		printf("%s", term2);
		for (i2 = 0; i2 < (35 - strlen(term2)); i2++) printf(" ");
	} else {
		printf("\t\t");
		printInShort(term2, 35);
		printf("   ");
	}
}

//print borrowing info
void printBorrowingInfo(int* check, int* check2, int i, int* isExist){
	if (!rent[i].returnStatus) {
		*check = printTitleBorrowingInfo(*check);
		*check2 = printLine(*check2);
			
		int j;
			
		//print code rent
		printf("\t\t%4d", rent[i].codeRent);
		for (j = 0; j < (15 - 4); j++) printf(" ");
		
		//print studen't name
		printStudentName(i);
			
		//print student code
		printf(" %s", rent[i].userName);
		for (j = 0; j < (25 - strlen(rent[i].userName)); j++) printf(" ");
			
		//print title of book
		if (40 >= strlen(rent[i].title)) {
			printf("%s", rent[i].title);
			for (j = 0; j < (40 - strlen(rent[i].title)); j++) printf(" ");
		} else {
			printf("\t\t");
			printInShort(rent[i].title, 40);
			printf("   ");
		}
			
		//print date borrow
		if (rent[i].day < 10) printf("0%d/", rent[i].day);
		else printf("%d/", rent[i].day);
		if (rent[i].month < 10) printf("0%d/",rent[i].month);
		else printf("%d/", rent[i].month);
		printf("%d", rent[i].year);
		for (j = 0; j < (30 - 10); j++) printf(" ");
		
		//print deadline
		if (rent[i].dayEnd < 10) printf("0%d/", rent[i].dayEnd);
		else printf("%d/", rent[i].dayEnd);
		if (rent[i].monthEnd < 10) printf("0%d/",rent[i].monthEnd);
		else printf("%d/", rent[i].monthEnd);
		printf("%d\n", rent[i].yearEnd);
//		for (j = 0; j < (30 - 10); j++) printf(" ");
		*isExist = 1;
	}
	//printf return status
//	if (rent[i].returnStatus) printf("     YES\n");
//	else printf("     NO\n");
}

//print returned info
void printReturnedInfo(int* check, int* check2, int i, int* isExist){
	if (rent[i].returnStatus) {
		*check = printTitleReturnInfo(*check);
		*check2 = printLine(*check2);
			
		int j;
			
		//print code rent
		printf("\t\t%4d", rent[i].codeRent);
		for (j = 0; j < (15 - 4); j++) printf(" ");
		
		//print student name
		printStudentName(i);
			
		//print student code
		printf(" %s", rent[i].userName);
		for (j = 0; j < (25 - strlen(rent[i].userName)); j++) printf(" ");
			
		//print title of book
		if (40 >= strlen(rent[i].title)) {
			printf("%s", rent[i].title);
			for (j = 0; j < (40 - strlen(rent[i].title)); j++) printf(" ");
		} else {
			printf("\t\t");
			printInShort(rent[i].title, 40);
			printf("   ");
		}
			
		//print date borrow
		if (rent[i].day < 10) printf("0%d/", rent[i].day);
		else printf("%d/", rent[i].day);
		if (rent[i].month < 10) printf("0%d/",rent[i].month);
		else printf("%d/", rent[i].month);
		printf("%d", rent[i].year);
		for (j = 0; j < (20 - 10); j++) printf(" "); // old is 30
		
		//print date return
		if (rent[i].dayReturn < 10) printf("0%d/", rent[i].dayReturn);
		else printf("%d/", rent[i].dayReturn);
		if (rent[i].monthReturn < 10) printf("0%d/",rent[i].monthReturn);
		else printf("%d/", rent[i].monthReturn);
		printf("%d\n", rent[i].yearReturn);
//		for (j = 0; j < (30 - 10); j++) printf(" ");
		*isExist = 1;
	}
	//printf return status
//	if (rent[i].returnStatus) printf("     YES\n");
//	else printf("     NO\n");
}

//view borrowing list by student's code
void viewBorrowingByStudent(){
	int numOfRent;
	importRentValue(&numOfRent);
	
	char yesNoStudenCode = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//input student's code
		char studentCodeIn[9];
		do printf("\t\tEnter student's code: ");
		while (!getStringIn(studentCodeIn, 8, 0));
		toUpper(studentCodeIn);
		
		//search
		int i, isExist = 0;
		int check = 1;//for print title
		int check2 = 0;//for print line
		
		for (i = 0; i < numOfRent; i++) {
			if (strcmp(studentCodeIn, rent[i].userName) == 0) {	
				printBorrowingInfo(&check, &check2, i, &isExist); 
			}
		}
		
		if (!isExist) printf("\t\tNo matching student's code\n");
		printf("\n\t\tDo you want to continue to view by student's code?");
		printYesNo();
		yesNoStudenCode = getYesNo();
			
	} while (yesNoStudenCode == 'y' || yesNoStudenCode == 'Y');

	
}

//view returned list by student's code
void viewReturnedByStudent(){
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	char yesNoStudenCode = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		//input student's code
		char studentCodeIn[9];
		do printf("\t\tEnter student's code: ");
		while (!getStringIn(studentCodeIn, 8, 0));
		toUpper(studentCodeIn);
		
		//search
		int i, isExist = 0;
		int check = 1;//for print title
		int check2 = 0;//for print line
		
		for (i = 0; i < numOfRent; i++) {
			if (strcmp(studentCodeIn, rent[i].userName) == 0) {	
				printReturnedInfo(&check, &check2, i, &isExist); 
			}
		}
		
		if (!isExist) printf("\t\tNo matching student's code\n");
		printf("\n\t\tDo you want to continue to view by student's code?");
		printYesNo();
		yesNoStudenCode = getYesNo();
			
	} while (yesNoStudenCode == 'y' || yesNoStudenCode == 'Y');

	
}

//view borrowing list by book code
void viewBorrowingByBookCode(){
	//import value
	int numOfBook, numOfRent;
	importValue(&numOfBook);
	importRentValue(&numOfRent);
	
	do {
		system("cls");
		printf("\n\n\n\n");
		//input
		printf("\t\tEnter book's code: ");
		int code = getIntNum();
		
		//search
		int i, isExist = 0;
		for (i = 0; i < numOfBook; i++) {
			if (code == book[i].code) {
				isExist = 1;
				printf("\t\tDo you want to search title: %s ?", book[i].name);
				printYesNo();
				char yesNoTrueInfo = getYesNo();
				if (yesNoTrueInfo == 'y' || yesNoTrueInfo == 'Y') break;
				else goto CONTI;	
			}
		}
		
		if (!isExist) {
			printf("\t\tNo matching book's code.\n");
			goto CONTI;
		} else {
			isExist = 0;
			int i2;
			int check = 1, check2 = 0;//for print info
			for (i2 = 0; i2 < numOfRent; i2++) {
				if (strcmp(book[i].name, rent[i2].title) == 0) {
					printBorrowingInfo(&check, &check2, i2, &isExist);
				}
			}
			
			if (!isExist) printf("\t\tNo %s is borrowing.", book[i].name);
			
			CONTI: {
				printf("\t\tDo you want to continue search by book's code?");
				printYesNo();
				char yesNo = getYesNo();
				if (yesNo == 'n' || yesNo == 'N') goto END;
			}			
		}
	} while (1);
	END: {}
}

//view returned list by book code
void viewReturnedByBookCode(){
	//import value
	int numOfBook, numOfRent;
	importValue(&numOfBook);
	importRentValue(&numOfRent);
	importDateReturn();
	
	do {
		system("cls");
		printf("\n\n\n\n");
		//input
		printf("\t\tEnter book's code: ");
		int code = getIntNum();
		
		//search
		int i, isExist = 0;
		for (i = 0; i < numOfBook; i++) {
			if (code == book[i].code) {
				isExist = 1;
				printf("\t\tDo you want to search title: %s ?", book[i].name);
				printYesNo();
				char yesNoTrueInfo = getYesNo();
				if (yesNoTrueInfo == 'y' || yesNoTrueInfo == 'Y') break;
				else goto CONTI;	
			}
		}
		
		if (!isExist) {
			printf("\t\tNo matching book's code.\n");
			goto CONTI;
		} else {
			isExist = 0;
			int i2;
			int check = 1, check2 = 0;//for print info
			for (i2 = 0; i2 < numOfRent; i2++) {
				if (strcmp(book[i].name, rent[i2].title) == 0) {
					printReturnedInfo(&check, &check2, i2, &isExist);
				}
			}
			
			if (!isExist) printf("\t\tNo %s is borrowing.", book[i].name);
			
			CONTI: {
				printf("\t\tDo you want to continue search by book's code?");
				printYesNo();
				char yesNo = getYesNo();
				if (yesNo == 'n' || yesNo == 'N') goto END;
			}			
		}
	} while (1);
	END: {}
}

//view borrowing list by book title
void viewBorrowingByBookTitle() {
	//import
	int numOfRent;
	importRentValue(&numOfRent);
	
	do {
		system("cls");
		printf("\n\n\n\n");
		//input
		char titleInput[501];
		do printf("\t\tEnter book's title or some of first character of book's title: ");
		while (!getStringIn(titleInput, 500, 0));
		toUpper(titleInput);
		//search
		int i, isExist = 0, check = 1, check2 = 0;
		for (i = 0; i < numOfRent; i++){
			char term[501];
			//initialize(rent[i].title, term);
			strcpy(term, rent[i].title);
			toUpper(term);
			if (isMatchEachCha(titleInput, term)){
				printBorrowingInfo(&check, &check2, i, &isExist); 
			}
		}
		
		if (!isExist) printf("\t\tNo matching title.\n");
		
		printf("\t\tDo you want to continue searching by title?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view returned list by book title
void viewReturnedByBookTitle() {
	//import
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	do {
		system("cls");
		printf("\n\n\n\n");
		//input
		char titleInput[501];
		do printf("\t\tEnter book's title or some of first character of book's title: ");
		while (!getStringIn(titleInput, 500, 0));
		toUpper(titleInput);
		//search
		int i, isExist = 0, check = 1, check2 = 0;
		for (i = 0; i < numOfRent; i++){
			char term[501];
			//initialize(rent[i].title, term);
			strcpy(term, rent[i].title);
			toUpper(term);
			if (isMatchEachCha(titleInput, term)){
				printReturnedInfo(&check, &check2, i, &isExist); 
			}
		}
		
		if (!isExist) printf("\t\tNo matching title.\n");
		
		printf("\t\tDo you want to continue searching by title?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}


//view borrowing list by book info
void viewBorrowingByBookInfo(){
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		printf("\t\t1. Search by book's code.\n");
		printf("\t\t2. Search by book's title.\n");
		printf("\t\t3. Back.\n");
		printf("\t\t4. Exit.\n");
		//get choice
		printf("\t\tYour choice: ");
		int choiceViewByBookInfo = getChoice(4);
		
		//switch choice
		switch (choiceViewByBookInfo) {
			//by book's code
			case 1: {
				viewBorrowingByBookCode();
				break;
			}
			
			//by book's title
			case 2: {
				viewBorrowingByBookTitle();
				break;
			}
			
			//back
			case 3: goto END;
			
			//exit
			case 4: end();
		}	
	} while (1);
	END: {}
}

//view returned list by book info
void viewReturnedByBookInfo(){
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		printf("\t\t1. Search by book's code.\n");
		printf("\t\t2. Search by book's title.\n");
		printf("\t\t3. Back.\n");
		printf("\t\t4. Exit.\n");
		//get choice
		printf("\t\tYour choice: ");
		int choiceViewByBookInfo = getChoice(4);
		
		//switch choice
		switch (choiceViewByBookInfo) {
			//by book's code
			case 1: {
				viewReturnedByBookCode();
				break;
			}
			
			//by book's title
			case 2: {
				viewReturnedByBookTitle();
				break;
			}
			
			//back
			case 3: goto END;
			
			//exit
			case 4: end();
		}	
	} while (1);
	END: {}
}


//check right day
int isRightDay(int day) {
	if (day > 31) {
		printf("\t\tYou cannot enter greater than 31! Again!\n");
		return 0;	
	}
	return 1;
}

//check right month
int isRightMonth(int month) {
	if (month > 12) {
		printf("\t\tYou cannot enter greater than 12! Again!\n");
		return 0;	
	}
	return 1;
}

//check right year
int isRightYear(int year) {
	if (year < 2000) {
		printf("\t\tYou cannot enter lower than 2000! Again!\n");
		return 0;
	}
	return 1;
}

//check leap year
int isLeapYear(int year) {
	if ((year % 400) == 0) return 1;
	if ((year % 4) == 0 && (year % 100) != 0) return 1;
	return 0;
}

//check exist date
int isExistDate(int day, int month, int year) {
	//check february
	if (isLeapYear(year)) {
		if (month == 2 && day > 29) {
			printf("\t\tYour date is not existed. Input again!\n");
			return 0;
		}
	} else {
		if (month == 2 && day > 28) {
			printf("\t\tYour date is not existed. Input again!\n");
			return 0;
		}
	}
	
	//check other month
	switch (month) {
		case 4:
		case 6:
		case 9:
		case 11: {
			if (day > 30) {
				printf("\t\tYour date is not existed. Input again!\n");
				return 0;
			}
			break;
		}
	}
	return 1;
}

//get date
void getDate(int* day, int* month, int* year,
			 int dayMode, int monthMode) {

	do {
		//get day
		if (dayMode) {
			do {
				printf("\t\tDay: ");
				*day = getIntNum();
			} while (!isRightDay(*day));	
		} else *day = 1;
		
		//get month
		if (monthMode) {
			do {
				printf("\n\t\tMonth: ");
				*month = getIntNum();		
			} while (!isRightMonth(*month));
		} else *month = 1;
		
		//get year
		do {
			printf("\n\t\tYear: ");
			*year = getIntNum();		
		} while (!isRightYear(*year));
		
	} while (!isExistDate(*day, *month, *year));
}

//view borrowing list by dd/mm/yyyy
void viewBorrowingByDDMMYY(){
	do {
		//input
		int day, month, year;
		system("cls");
		printf("\n\n\n\n");
		getDate(&day, &month, &year, 1, 1);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (day == rent[i].day) {
				if (month == rent[i].month) {
					if (year == rent[i].year) {
						printBorrowingInfo(&check, &check2, i, &isExist);
					}
				}
			}
		}
		
		if (!isExist) printf("\t\tNo borrower in %d/%d/%d\n", day, month, year);
		printf("\t\tDo you want to continue searching by dd/mm/yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view returned list by dd/mm/yyyy
void viewReturnedByDDMMYY(){
	do {
		//input
		int day, month, year;
		system("cls");
		printf("\n\n\n\n");
		getDate(&day, &month, &year, 1, 1);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (day == rent[i].day) {
				if (month == rent[i].month) {
					if (year == rent[i].year) {
						printReturnedInfo(&check, &check2, i, &isExist);
					}
				}
			}
		}
		
		if (!isExist) printf("\t\tNo return in %d/%d/%d\n", day, month, year);
		printf("\t\tDo you want to continue searching by dd/mm/yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view borrowing list by mm/yyyy
void viewBorrowingByMMYYYY(){
	do {
		//input
		int day, month, year;
		getDate(&day, &month, &year, 0, 1);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (month == rent[i].month) {
				if (year == rent[i].year) {
					printBorrowingInfo(&check, &check2, i, &isExist);
				}
			}
		}
		
		if (!isExist) printf("\t\tNo borrower in %d/%d\n", month, year);
		printf("\t\tDo you want to continue searching by mm/yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view returned list by mm/yyyy
void viewReturnedByMMYYYY(){
	do {
		//input
		int day, month, year;
		getDate(&day, &month, &year, 0, 1);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (month == rent[i].month) {
				if (year == rent[i].year) {
					printReturnedInfo(&check, &check2, i, &isExist);
				}
			}
		}
		
		if (!isExist) printf("\t\tNo return in %d/%d\n", month, year);
		printf("\t\tDo you want to continue searching by mm/yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view borrowing list by yyyy
void viewBorrowingByYYYY(){
	do {
		//input
		int day, month, year;
		getDate(&day, &month, &year, 0, 0);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (year == rent[i].year) {
				printBorrowingInfo(&check, &check2, i, &isExist);
			}
		}
		
		if (!isExist) printf("\t\tNo borrower in %d\n", year);
		printf("\t\tDo you want to continue searching by yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view returned list by yyyy
void viewReturnedByYYYY(){
	do {
		//input
		int day, month, year;
		getDate(&day, &month, &year, 0, 0);
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, check = 1, check2 = 0, isExist = 0;
		for (i = 0; i < numOfRent; i++) {
			if (year == rent[i].year) {
				printReturnedInfo(&check, &check2, i, &isExist);
			}
		}
		
		if (!isExist) printf("\t\tNo return in %d\n", year);
		printf("\t\tDo you want to continue searching by yyyy ?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1);
	END: {}
}

//view borrowing list by date
void viewBorrowingByDate(){
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		printf("\t\t1. Search by dd/mm/yyyy\n");
		printf("\t\t2. Search by mm/yyyy\n");
		printf("\t\t3. Search by yyyy\n");
		printf("\t\t4. Back\n");
		printf("\t\t5. Exit\n");
		//get choice
		printf("\t\tYour choice: ");
		int choiceByDate = getChoice(5);
		
		//switch choice
		switch (choiceByDate) {
			//dd/mm/yyyy
			case 1: {
				viewBorrowingByDDMMYY();
				break;
			}
			
			//mm/yyyy
			case 2: {
				viewBorrowingByMMYYYY();
				break;
			}
			
			//yyyy
			case 3: {
				viewBorrowingByYYYY();
				break;
			}
			
			//back
			case 4: goto END;
			
			//exit
			case 5: end();
		}
	} while (1);
	END: {}
}

//view returned list by date
void viewReturnedByDate(){
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		printf("\t\t1. Search by dd/mm/yyyy\n");
		printf("\t\t2. Search by mm/yyyy\n");
		printf("\t\t3. Search by yyyy\n");
		printf("\t\t4. Back\n");
		printf("\t\t5. Exit\n");
		//get choice
		printf("\t\tYour choice: ");
		int choiceByDate = getChoice(5);
		
		//switch choice
		switch (choiceByDate) {
			//dd/mm/yyyy
			case 1: {
				viewReturnedByDDMMYY();
				break;
			}
			
			//mm/yyyy
			case 2: {
				viewReturnedByMMYYYY();
				break;
			}
			
			//yyyy
			case 3: {
				viewReturnedByYYYY();
				break;
			}
			
			//back
			case 4: goto END;
			
			//exit
			case 5: end();
		}
	} while (1);
	END: {}
}

//view all rent info
void viewAllRentInfo(){
	int numOfRent;
	importRentValue(&numOfRent);
	
	int i, check = 1, check2 = 0, isExist;
	for (i = 0; i < numOfRent; i++) {
		printBorrowingInfo(&check, &check2, i, &isExist);
	}
}

//view all rent info
void viewAllReturnedInfo(){
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	int i, check = 1, check2 = 0, isExist;
	for (i = 0; i < numOfRent; i++) {
		printReturnedInfo(&check, &check2, i, &isExist);
	}
}


//view returned list option
void viewReturnedList() {
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		textColor(14);//yellow
		printf("\t\tChoose your requirement\n");
	
		textColor(11);
		printf("\t\t");
		drawLine(33);//--------------------
	
		textColor(15);
		printf("\t\t1. Search by student's code.\n");
		printf("\t\t2. Search by book's info.\n");
		printf("\t\t3. Search by date.\n");
		printf("\t\t4. View all info.\n");
		printf("\t\t5. Back.\n");
		printf("\t\t6. Exit.\n");
		//get choice
		textColor(11);
		printf("\t\t");
		drawLine(33);//-----------------
	
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);
		int choiceViewReturnedList = getChoice(6);
		
		//switch choice
		switch (choiceViewReturnedList) {
			//view by student's code
			case 1: {
				viewReturnedByStudent();
				break;
			}
			
			//view by book's info
			case 2: {
				viewReturnedByBookInfo();
				break;
			}
			
			//view by date
			case 3: {
				viewReturnedByDate();
				break;
			}
			
			//view all info
			case 4: {
				viewAllReturnedInfo();
				getch();
				break;
			}
			
			//back 
			case 5: goto END;
			
			//exit
			case 6: end();
		}
	} while (1);
	END: {}
}

//check student's code
int checkStudentCode(char* studentCode, int* numBorrowed){
	toUpper(studentCode);
	int numOfRent;
	importRentValue(&numOfRent);
	//open file
	char term[9];
	FILE* f = fopen("userUserName.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%[^\n]%*c", term);
		if (strcmp(studentCode, term) == 0) {
			int i, count = 0;
			for (i = 0; i < numOfRent; i++) 
				if (strcmp(studentCode, rent[i].userName) == 0 && (rent[i].returnStatus == 0)) count++;

			if (count >= 5) {
					printf("\t\tThis user has borrowed more than 5 books.\n");
					printf("\t\tNo more book can be borrowed!");
					printf("\t\tPress anykey to start again!");
					getch();
					fclose(f);
					return 2;
			}
			*numBorrowed = count;
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}

//check book's code
int checkBookCode(int bookCode, int* index) {
	int numOfBook;
	importValue(&numOfBook);
	
	//check
	int i;
	for (i = 0; i < numOfBook; i++) {
		if (book[i].code == bookCode) {
			*index = i;
			return 1;
		}
	}
	return 0;
}

//check book's has borrowed
int isBorrowed(int bookCode, char* studentCode, int addBorrowerStatus) {
	int numOfBook;
	importValue(&numOfBook);
	int numOfRent;
	importRentValue(&numOfRent);
	
	
	//return 1: book has been borrowed, skip this book
	//return 0: book hasn't been borrowed.
	int i;
	for (i = 0; i < numOfBook; i++) {
		if (book[i].code == bookCode) {
			int j;
			for (j = 0; j < numOfRent; j++) {
				if (strcmp(rent[j].title, book[i].name) == 0 && strcmp(rent[j].userName, studentCode) == 0 
					&& rent[j].returnStatus == 0) {
						
					printf("\t\tThis book has been borrowed before.\n");
					if (addBorrowerStatus) printf("\t\tPress anykey to continue adding others book.\n");
					getch();
					return 1;
				}
			}
		}
	}
	return 0;
}

//set deadline
void setDeadline(int* dayEnd, int* monthEnd, int* yearEnd, 
				 int day, int month, int year){
	int i;
	for (i = 0; i < 14; i++) {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10: {
				day++;
				if (day > 31) {
					month++;
					day = 1;
				}
				break;
			}
			
			case 4:
			case 6:
			case 9:
			case 11: {
				day++;
				if (day > 30) {
					day = 1;
					month++;
				}
				break;
			}
			
			case 12: {
				day++;
				if (day > 31) {
					day = 1;
					month = 1;
					year++;
				}
				break;
			}
			
			case 2: {
				day++;
				if (isLeapYear(year)) {
					if (day > 29) {
						day = 1;
						month++;
					}
				} else {
					if (day > 28) {
						day = 1;
						month++;
					}
				}
				break;
			}
		}
	}
	*dayEnd = day;
	*monthEnd = month;
	*yearEnd = year;
}

//set array in the same value
void setArrSameValue(int numBorrow, int numOfRent) {
	int count = 1;
	while (numBorrow > 1) {
		//set student's code
		//initialize(rent[numOfRent].userName, rent[numOfRent + count].userName); 
		strcpy(rent[numOfRent + count].userName, rent[numOfRent].userName);
		//set date rent
		rent[numOfRent + count].day = rent[numOfRent].day;
		rent[numOfRent + count].month = rent[numOfRent].month;
		rent[numOfRent + count].year = rent[numOfRent].year; 
		//set deadline
		rent[numOfRent + count].dayEnd = rent[numOfRent].dayEnd;
		rent[numOfRent + count].monthEnd = rent[numOfRent].monthEnd;
		rent[numOfRent + count].yearEnd = rent[numOfRent].yearEnd;
		//set code
		rent[numOfRent + count].codeRent = rent[numOfRent].codeRent + count;
		count++;
		numBorrow--;
	}
}


//add borrower
void addBorrower() {
	do {
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		system("cls");
		printf("\n\n\n\n");
		
		if (numOfRent >= 2000) {
			printf("\t\tFull disk. Please delete RETURNED INFO before adding more info!\n");
			printf("\t\tPress anykey to back");
			getch();
			goto END;
		}
		//input number of book borrowed
		int numBorrow;
		do {
			printf("\t\tEnter number of borrowed book: ");
			numBorrow = getIntNum();
			if (numBorrow > 5) {
				printf("\t\tYou cannot borrow more than 5 books.\n");
				printf("\t\tPress anykey to start again!");
				getch();
				goto END;
			}	
		} while (numBorrow > 5);
		
		//input student's code
		int numBorrowed;
		do {
			do printf("\t\tEnter student's code: ");
			while (!(getStringIn(rent[numOfRent].userName, 8, 0)));	
			
			if (checkStudentCode(rent[numOfRent].userName, &numBorrowed) == 2) goto END;
			
			if (checkStudentCode(rent[numOfRent].userName, &numBorrowed) == 0) 
			printf("\t\tNo matching studen's code. Again!\n");		
		} while (!(checkStudentCode(rent[numOfRent].userName, &numBorrowed)));

		
		if ((numBorrow + numBorrowed) > 5) {
				printf("\t\tYou cannot borrow more than 5 books.\n");
				printf("\t\tPress anykey to start again!");
				getch();
				goto END;
			}	
			
		//get date

		
		
		//set borrower code
		rent[numOfRent].codeRent = rent[numOfRent - 1].codeRent + 1;
		
		//set array
		setArrSameValue(numBorrow, numOfRent);
			
		while (numBorrow > 0) {
			
			//get book's code
			int bookCode, index;
			int temp;//to check right book code
			do {
				printf("\t\tEnter book's code: ");
				bookCode = getIntNum();
				temp = checkBookCode(bookCode, &index);
				if (!temp) {
					printf("\t\tNo matching book's code. Enter again.\n");
				} else {
					
					if (isBorrowed(bookCode, rent[numOfRent].userName, 1)) {
						numBorrow--;
						goto CON;
					}
							//getDate(&rent[numOfRent].day, &rent[numOfRent].month, &rent[numOfRent].year, 1, 1);
		long second = now(&rent[numOfRent].day, &rent[numOfRent].month, &rent[numOfRent].year);
		//int now(int *dayNow, int *monthNow, int *yearNow)
		printf("\n\t\tBorrowing day is in: %d/%d/%d\n", rent[numOfRent].day, rent[numOfRent].month, rent[numOfRent].year);
		//set deadline
		setDeadline(&rent[numOfRent].dayEnd, &rent[numOfRent].monthEnd, &rent[numOfRent].yearEnd,
					 rent[numOfRent].day, rent[numOfRent].month, rent[numOfRent].year);
					 printf("\n\t\tDeadline is in: %d/%d/%d\n\n", rent[numOfRent].dayEnd, rent[numOfRent].monthEnd, rent[numOfRent].yearEnd);
					
					importName();
					printf("\t\tDo you want to add %s ?", book[index].name);
					printYesNo();
					char yesNoRightTitle = getYesNo();
					if (yesNoRightTitle == 'n' || yesNoRightTitle == 'N') {
						printf("\t\tDo you want to continue adding?");
						printYesNo();
						char yesNoContinue = getYesNo();
						if (yesNoContinue == 'n' || yesNoContinue == 'N') goto END;
						else numBorrow--;
					} else {
						//set book title
						//initialize(book[index].name, rent[numOfRent].title);
						strcpy(rent[numOfRent].title, book[index].name);
						
						//change num of book avaiable
						int numOfBook;
						importValue(&numOfBook);
						
//						printf("%d\t%d\t%s",index, toNum(book[index].quanlityAvaiable), book[index].quanlityAvaiable);
						int temp2 = toNum(book[index].quanlityAvaiable) - 1;
						
						if (temp2 <= 0) {
							printf("\t\tERROR. This book isn't avaiable!\n");
							printf("\t\tDo you want to skip this book and continue adding others?");
							printYesNo();
							char yesNoOut = getYesNo();
							if (yesNoOut == 'y' || yesNoOut == 'Y') {
								numBorrow--;
								goto CON;
							} else goto END;
						} else {
							toString(book[index].quanlityAvaiable, temp2, 4);
						}
						exportQuanlityAvaiable(numOfBook, 0, 0);
						
						exportRentValue(numOfRent, 1, 0);
						
						nowFinish(second);
						returningDay(second, 14); // how many day
						
						numOfRent++;
						numBorrow--;
					}
				}
			}
			while (!temp);
			CON:{}	
		}
		
		printf("\t\tDo you want to continue adding borrower?");
		printYesNo();
		char yesNo = getYesNo();
		if (yesNo == 'n' || yesNo == 'N') goto END;
	} while (1); 
	END: {}
}

//check deadline
int isPassDeadLine(int dayEnd, int monthEnd, int yearEnd,
				  int dayReturn, int monthReturn, int yearReturn) {
	
	int flag = 0;	
			  	
	if (yearReturn > yearEnd) flag = 1;
	else if (yearReturn == yearEnd) {
		if (monthReturn > monthEnd) flag = 1;
		else if (monthReturn == monthEnd) {
			if (dayReturn > dayEnd) flag = 1;
		}
	}
	return flag;
}

//change return status
void changeReturnStatus() {
	system("cls");
	printf("\n\n\n\n");
	
	char yesNo = 'y';
	do {
		printf("\n\t\tEnter borrowing code you want to check: ");
		int code = getIntNum();
		
		//import value 
		int numOfRent, numOfBook;
		importRentValue(&numOfRent);
		importValue(&numOfBook);
		importDateReturn();
		
		//search code
		int i, isExist = 0, check = 1, check2 = 0;
		for (i = 0; i < numOfRent; i++){
			if (rent[i].codeRent == code) {
				printReturnedInfo(&check, &check2, i, &isExist);
				break;
				} 	
			}
		
		if (!isExist) {
			printf("\t\tNo matching borrow's code.");
			printf("\n\t\tDo you want to enter again?");
			printYesNo();
			yesNo = getYesNo();
			if (yesNo == 'n' || yesNo == 'N') break;
		} else {
			printf("\t\tDo you want to change returned status to NO?");
			printYesNo();
			yesNo = getYesNo();
			
			if (yesNo == 'y' || yesNo == 'Y') {
				rent[i].returnStatus = 0;
				rent[i].dayReturn = 0;
				rent[i].monthReturn = 0;
				rent[i].yearReturn = 0;
				
				//change book's info
				int i2;
				for (i2 = 0; i2 < numOfBook; i2++) {
					if (strcmp(rent[i].title, book[i2].name) == 0) {
						int temp = toNum(book[i2].quanlityAvaiable);
						temp--;
						toString(book[i2].quanlityAvaiable, temp, 4);
						break;
					}
				}
				
				exportRentValue(numOfRent, 0, 1);
				exportDateReturn(numOfRent, 0, 1);
				exportValue(numOfBook, 0, 1);

				printf("\t\tSuccess!");
				printf("\n\t\tDo you want to continue to check returned status?");
				printYesNo();
				yesNo = getYesNo();
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//check return status
void checkReturnStatus() {
	system("cls");
	printf("\n\n\n\n");
	printf("\t\tEnter date return\n");
	int day, month, year;
	getDate(&day, &month, &year, 1, 1);
	
	char yesNoExist;
	do {
		printf("\n\n");
		//get code
		printf("\t\tEnter borrowing code you want to check: ");
		int code = getIntNum();
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		int numOfBook;
		importValue(&numOfBook);
		
		//search code
		int i, isExist = 0, check = 1, check2 = 0;
		for (i = 0; i < numOfRent; i++){
			if (rent[i].codeRent == code) {
				printBorrowingInfo(&check, &check2, i, &isExist);
				break;
				} 	
			}
		
		if (!isExist) {
			printf("\t\tNo matching borrow's code.");
			printf("\n\t\tDo you want to enter again?");
			printYesNo();
			yesNoExist = getYesNo();
			if (yesNoExist == 'n' || yesNoExist == 'N') break;
		} else {
			//check deadline
			if (isPassDeadLine(rent[i].dayEnd, rent[i].monthEnd, rent[i].yearEnd, day, month, year)) 
			printf("\t\tThis borrower has passed the deadline.\n");
			
			printf("\t\tDo you want to change returned status to YES?");
			printYesNo();
			char yesNoReturn = getYesNo();
			if (yesNoReturn == 'n' || yesNoReturn == 'N') {
				printf("\t\tDo you want to continue to check returned status?");
				printYesNo();
				yesNoExist = getYesNo();
				if (yesNoExist == 'n' || yesNoExist == 'N') break;				
			} else {
				rent[i].returnStatus = 1;
				rent[i].dayReturn = day;
				rent[i].monthReturn = month;
				rent[i].yearReturn = year;
				
				//change book's info
				int i2;
				for (i2 = 0; i2 < numOfBook; i2++) {
					if (strcmp(rent[i].title, book[i2].name) == 0) {
						int temp = toNum(book[i2].quanlityAvaiable);
						temp++;
						toString(book[i2].quanlityAvaiable, temp, 4);
						break;
					}
				}
				
				exportRentValue(numOfRent, 0, 1);
				exportDateReturn(numOfRent, 0, 1);
				exportValue(numOfBook, 0, 1);
				
				printf("\t\tSuccess!");
				printf("\n\t\tDo you want to continue to check returned status?");
				printYesNo();
				yesNoExist = getYesNo();
				if (yesNoExist == 'n' || yesNoExist == 'N') break;				
			}
		}
	} while (yesNoExist == 'y' || yesNoExist == 'Y');
}

//delete borrow info by date
void deleteBorrowInfoByDate() {
	system("cls");
	printf("\n\n\n\n");
	printf("\t\tEnter date return:\n");
	//input
	int day, month, year;
	getDate(&day, &month, &year, 1, 1);
	
	//import value
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	int i;
	int check = 1, check2 = 0, isExist = 0;
	for (i = 0; i < numOfRent; i++) {
		if (rent[i].returnStatus) {
			if (rent[i].dayReturn == day && rent[i].monthReturn == month && rent[i].yearReturn == year) {
				printReturnedInfo(&check, &check2, i, &isExist);
			}
		}
	}
	
	int temp = 0;
	
	if (!isExist) {
		printf("\t\tNo return in that date.");
	} else {
		printf("\t\tDo you want to delete this info?");
		printYesNo();
		char yesNo = getYesNo();
		
		if (yesNo == 'y' || yesNo == 'Y') {
			int j;//to delete
			for (i = 0; i< numOfRent; i++) {
				while (rent[i].returnStatus) {
					while (rent[i].dayReturn == day && rent[i].monthReturn == month && rent[i].yearReturn == year) {
						j = i;
						temp++;
						if (j != numOfRent - 1) {
							while (j < numOfRent) {
								//initialize(rent[j+1].title, rent[j].title);
								strcpy(rent[j].title, rent[j+1].title);
								//initialize(rent[j+1].userName, rent[j].userName);
								strcpy(rent[j].userName, rent[j+1].userName);
								rent[j].day = rent[j+1].day;
								rent[j].dayEnd = rent[j+1].dayEnd;
								rent[j].dayReturn = rent[j+1].dayReturn;
								rent[j].month = rent[j+1].month;
								rent[j].monthEnd = rent[j+1].monthEnd;
								rent[j].monthReturn = rent[j+1].monthReturn;
								rent[j].returnStatus = rent[j+1].returnStatus;
								rent[j].year = rent[j+1].year;
								rent[j].yearEnd = rent[j+1].yearEnd;
								rent[j].yearReturn = rent[j+1].yearReturn;
								j++;
							}
						}
					}
				} 
			}
			
			printf("\n%d\n", temp);
			printf("\t\tDelete Successfully.\n");
			if (numOfRent - temp - 1 < 0) {
				exportRentValue(0, 0, 0);
				exportDateReturn(0, 0, 0);
			} else {
				exportRentValue(numOfRent - temp - 1, 0, 0);
				exportDateReturn(numOfRent - temp - 1, 0, 0);
			}	
		}
	}
}

//delete borrow info by code
void deleteBorrowInfoByCode() {
	system("cls");
	printf("\n\n\n\n");
	printf("\t\tEnter code you want to delete: ");
	int code = getIntNum();
	
	//import value
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	int i;
	int check = 1, check2 = 0, isExist = 0;
	for (i = 0; i < numOfRent; i++) {
		if (code == rent[i].codeRent) {
			printReturnedInfo(&check, &check2, i, &isExist);
			break;
		}
	}
	
	int temp = 0;
	if (!isExist) {
		printf("\t\tNo existed code.\n");
	} else {
		printf("\t\tDo you want to delete this info?");
		printYesNo();
		char yesNo = getYesNo();
		
		if (yesNo == 'y' || yesNo == 'Y') {
			int j = i; //to delete
			temp++;
			
			if (j != numOfRent - 1) {
				while (j < numOfRent) {
					//initialize(rent[j+1].title, rent[j].title);
					strcpy(rent[j].title, rent[j+1].title);
					//initialize(rent[j+1].userName, rent[j].userName);
					strcpy(rent[j].userName, rent[j+1].userName);
					rent[j].day = rent[j+1].day;
					rent[j].dayEnd = rent[j+1].dayEnd;
					rent[j].dayReturn = rent[j+1].dayReturn;
					rent[j].month = rent[j+1].month;
					rent[j].monthEnd = rent[j+1].monthEnd;
					rent[j].monthReturn = rent[j+1].monthReturn;
					rent[j].returnStatus = rent[j+1].returnStatus;
					rent[j].year = rent[j+1].year;
					rent[j].yearEnd = rent[j+1].yearEnd;
					rent[j].yearReturn = rent[j+1].yearReturn;
					j++;
				}	
			}
			printf("\t\tDelete Successfully.\n");
			if (numOfRent - temp - 1 < 0) {
				exportRentValue(0, 0, 0);
				exportDateReturn(0, 0, 0);
			} else {
				exportRentValue(numOfRent - temp - 1, 0, 0);
				exportDateReturn(numOfRent - temp - 1, 0, 0);
			}		
		}		
	}
}

//delete all returned info
void deleteAllReturnInfo() {
	system("cls");
	//import value
	int numOfRent;
	importRentValue(&numOfRent);
	importDateReturn();
	
	int i, check = 1, check2 = 0, isExisted;
	for (i = 0; i < numOfRent; i++) {
		if (rent[i].returnStatus) {
			printReturnedInfo(&check, &check2, i, &isExisted);
		}
	}
	
	int temp = 0;
	printf("\t\tDo you want to delete this info?");
	printYesNo();
	char yesNo = getYesNo();
	if (yesNo == 'y' || yesNo == 'Y') {
		int j;
		
		for (i = 0; i < numOfRent; i++) {
			while (rent[i].returnStatus) {
				temp++;
				j = i;
				if (j != numOfRent - 1) {
					while (j < numOfRent) {
						//initialize(rent[j+1].title, rent[j].title);
						strcpy(rent[j].title, rent[j+1].title);
						//initialize(rent[j+1].userName, rent[j].userName);
						strcpy(rent[j].userName, rent[j+1].userName);
						rent[j].day = rent[j+1].day;
						rent[j].dayEnd = rent[j+1].dayEnd;
						rent[j].dayReturn = rent[j+1].dayReturn;
						rent[j].month = rent[j+1].month;
						rent[j].monthEnd = rent[j+1].monthEnd;
						rent[j].monthReturn = rent[j+1].monthReturn;
						rent[j].returnStatus = rent[j+1].returnStatus;
						rent[j].year = rent[j+1].year;
						rent[j].yearEnd = rent[j+1].yearEnd;
						rent[j].yearReturn = rent[j+1].yearReturn;
						j++;
					}						
				}
			}
		}
		
		printf("\t\tDelete Successfully.\n");			
		if (numOfRent - temp - 1 < 0) {
			exportRentValue(0, 0, 0);
			exportDateReturn(0, 0, 0);
		} else {
			exportRentValue(numOfRent - temp - 1, 0, 0);
			exportDateReturn(numOfRent - temp - 1, 0, 0);
		}	
		getch();
	}
}

//delete borrow info
void deleteBorrowInfo() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		textColor(14);//yellow
		printf("\t\tChoose your requirement\n");
	
		textColor(11);
		printf("\t\t");
		drawLine(24);//--------------------
	
		textColor(15);
		printf("\t\t1. Delete by date.\n");
		printf("\t\t2. Delete by code.\n");
		printf("\t\t3. Delete all info.\n");
		printf("\t\t4. Back.\n");
		printf("\t\t5. Exit.\n");
		textColor(11);
		printf("\t\t");
		drawLine(24);//-----------------
	
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);
		int choice = getChoice(5);
		
		switch (choice) {
			//delete by date
			case 1: {
				deleteBorrowInfoByDate();
				printf("\t\tDo you want to continue deleting?");
				printYesNo();
				yesNo = getYesNo();
				break;
			}
			
			//delete by code
			case 2: {
				deleteBorrowInfoByCode();
				printf("\t\tDo you want to continue deleting?");
				printYesNo();
				yesNo = getYesNo();				
				break;
			}
			
			//delete all info
			case 3: {
				deleteAllReturnInfo();
				break;
			}
			
			//back
			case 4: {
				yesNo = 'n';
				break;
			}
			
			//exit
			case 5: {
				end();
				break;
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit student's code in borrowing list 
void editBorrowingStudentCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		printf("\t\tEnter borrowing code: ");
		int code = getIntNum();
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, isExisted = 0; //to check existed code
		for (i = 0; i < numOfRent; i++) {
			if (rent[i].codeRent == code) {
				int check = 1, check2 = 0; 
				printBorrowingInfo(&check, &check2, i, &isExisted);
				break;
			}
		}
		
		if (!isExisted) {
			printf("\t\tNo matching code.\n");
			printf("\t\tDo you want to continue ?");
			printYesNo();
			yesNo = getYesNo();
		} else {
			char newStudentCode[9], yesNoWrongStudentCode = 'n';
			do {
				do printf("\n\t\tEnter new student's code: ");
				while (!getStringIn(newStudentCode, 8, 0));	
				int numBorrowed = 1; //no use, just for function check code
				
				int check = checkStudentCode(newStudentCode, &numBorrowed);
				
				//0 -> no existed student's code
				if (check == 0) {
					printf("\t\t%s is not existed.\n", newStudentCode);
					printf("\t\tDo you want to enter again ?");
					printYesNo();
					yesNoWrongStudentCode = getYesNo();
					
					if (yesNoWrongStudentCode == 'n' || yesNoWrongStudentCode == 'N') {
						printf("\t\tDo you want to continue ?");
						printYesNo();
						yesNo = getYesNo();
					}
				//2 -> this student rent more than 5 books
				} else if (check == 2) {
						printf("\t\tDo you want to continue ?");
						printYesNo();
						yesNo = getYesNo();	
				//1 -> success				
				} else {
					//initialize(newStudentCode, rent[i].userName);
					strcpy(rent[i].userName, newStudentCode);
					exportRentValue(numOfRent, 0, 1);
					printf("\t\tEdit successfully!\n");
					printf("\t\tDo you want to continue ?");
					printYesNo();
					yesNo = getYesNo();
				}				
			} while (yesNoWrongStudentCode == 'y' || yesNoWrongStudentCode == 'Y');
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit book's code in borrowing list 
void editBorrowingBookCode() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		printf("\t\tEnter borrowing code: ");
		int code = getIntNum();
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, isExisted = 0; //to check existed code
		for (i = 0; i < numOfRent; i++) {
			if (rent[i].codeRent == code) {
				int check = 1, check2 = 0; 
				printBorrowingInfo(&check, &check2, i, &isExisted);
				break;
			}
		}
		
		if (!isExisted) {
			printf("\t\tNo matching code.\n");
			printf("\t\tDo you want to continue ?");
			printYesNo();
			yesNo = getYesNo();
		} else {
			int newBookCode;
			char yesNoWrongBookCode = 'n';
			
			printf("\t\tEnter new book's code: ");
			newBookCode = getIntNum();
				
			int index; //no use, just for function check exist book code
			if (!checkBookCode(newBookCode, &index)) {
				printf("\t\tNo matching book's code.\n");
				printf("\t\tDo you want to enter again ?");
				printYesNo();
				yesNo = getYesNo();
			} else {
				if (isBorrowed(newBookCode, rent[i].userName, 0)) {
					printf("\t\tDo you want to enter again ?");
					printYesNo();
					yesNo = getYesNo();						
				} else {
					int numOfBook;
					importValue(&numOfBook);
					
					int i2;
					for (i2 = 0; i2 < numOfBook; i2++) {
						if (book[i2].code == newBookCode) {
							//initialize(book[i2].name, rent[i].title);
							strcpy(rent[i].title, book[i2].name);
						}
					}
					
					//export
					exportRentValue(numOfRent, 0, 1);
					printf("\t\tEdit successfully!\n");
					printf("\t\tDo you want to continue ?");
					printYesNo();
					yesNo = getYesNo();
				}
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit date borrow
void editDateBorrow() {
	char yesNo = 'y';
	do {
		system("cls");
		printf("\n\n\n\n");
		printf("\t\tEnter borrowing code: ");
		int code = getIntNum();
		
		//import value
		int numOfRent;
		importRentValue(&numOfRent);
		
		//search
		int i, isExisted = 0; //to check existed code
		for (i = 0; i < numOfRent; i++) {
			if (rent[i].codeRent == code) {
				int check = 1, check2 = 0; 
				printBorrowingInfo(&check, &check2, i, &isExisted);
				break;
			}
		}
		
		if (!isExisted) {
			printf("\t\tNo matching code.\n");
			printf("\t\tDo you want to continue ?");
			printYesNo();
			yesNo = getYesNo();
		} else {
			int newDay, newMonth, newYear, newDayEnd, newMonthEnd, newYearEnd;
			getDate(&newDay, &newMonth, &newYear, 1, 1);
			setDeadline(&newDayEnd, &newMonthEnd, &newYearEnd, newDay, newMonth, newYear);
			
			printf("\t\tNew Deadline is in: %d/%d/%d\n", newDayEnd, newMonthEnd, newYearEnd);
			
			printf("\t\tDo you want to edit ?");
			printYesNo();
			yesNo = getYesNo();	
			
			if (yesNo == 'y' || yesNo == 'Y') {
				rent[i].day = newDay;
				rent[i].month = newMonth;
				rent[i].year = newYear;
				
				rent[i].dayEnd = newDayEnd;
				rent[i].monthEnd = newMonthEnd;
				rent[i].yearEnd = newYearEnd;
				
				exportRentValue(numOfRent, 0, 1);
				
				printf("\t\tEdit successfully!\n");
				printf("\t\tDo you want to continue ?");
				printYesNo();
				yesNo = getYesNo();
			} else {
				printf("\t\tDo you want to continue ?");
				printYesNo();
				yesNo = getYesNo();
			}			
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}

//edit borrowing list
void editBorrowingList() {
	
	do {
		system("cls");
		printf("\n\n\n\n");
		textColor(14);//yellow
		printf("\t\tChoose your requirement\n");
	
		textColor(11);
		printf("\t\t");
		drawLine(28);//--------------------
	
		textColor(15);
		printf("\t\t1. Edit student's code.\n");
		printf("\t\t2. Edit book's code.\n");
		printf("\t\t3. Edit date rent.\n");
		printf("\t\t4. Back\n");
		printf("\t\t5. Exit.\n");
		textColor(11);
		printf("\t\t");
		drawLine(28);//-----------------
	
		textColor(14);
		printf("\t\tYour requirement is: ");
		textColor(15);
		int choice = getChoice(5);
		
		switch (choice) {
			//edit student's code
			case 1: {
				editBorrowingStudentCode();
				break;
			}
			
			//edit book's code
			case 2: {
				editBorrowingBookCode();
				break;
			}
			
			//edit date rent
			case 3: {
				editDateBorrow();
				break;
			}
			
			//back
			case 4: {
				goto END;
				break;
			}
			
			//exit
			case 5: end();
		}	
	} while (1);
	END: {}
}

//view borrowing list option
void viewBorrowingList() {
	do {
		system("cls");
		//print menu
		printf("\n\n\n\n");
		textColor(Gold);//yellow
		printf("\t\tChoose your requirement\n");
		
		textColor(11);
		printf("\t\t");
		drawLine(33);//--------------------
		
		textColor(15);
		printf("\t\t1. Search by student's code.\n");
		printf("\t\t2. Search by book's info.\n");
		printf("\t\t3. Search by date.\n");
		printf("\t\t4. View all info.\n");
		printf("\t\t5. Back.\n");
		printf("\t\t6. Exit.\n");
		
		//get choice
		textColor(11);
		printf("\t\t");
		drawLine(33);//-----------------
	
		textColor(Gold);
		printf("\t\tYour requirement is: ");
		textColor(15);
		int choiceViewBorrowingList = getChoice(6);
		
		//switch choice
		switch (choiceViewBorrowingList) {
			//view by student's code
			case 1: {
				viewBorrowingByStudent();
				break;
			}
			
			//view by book's info
			case 2: {
				viewBorrowingByBookInfo();
				break;
			}
			
			//view by date
			case 3: {
				viewBorrowingByDate();
				break;
			}
			
			//view all info
			case 4: {
				viewAllRentInfo();
				getch();
				break;
			}
			
			//back 
			case 5: goto END;
			
			//exit
			case 6: end();
		}
	} while (1);
	END: {}
}

int pageEnterAdmin()
{
	int mutation;
	int choice;
	/*
	makeLine(4);
	makeTab(3);
	mutation = intel(6, 0);
	voiceAfterMenuOfAdmin(mutation);
	*/
	
	makeLine(4);
	makeTab(3);
	textColor(Blue);
	printf("AI: These features will interact with books list.");		
	textColor(White);
	printf("\n");
	char tmp[100];
	
	printMenuBookInfo();
	textColor(14);
	//printf("\t\tYour choice is: ");
	textColor(15);
	choice = checkChoice(7);
				//choiceBookInfo = getChoice(7);
	if(choice == 1)
	{
		search();
	}
	
	else if(choice == 2)
	{
		arrange( tmp, 0, 0, viewBooksInfo[0].maxStruct);
	}
	
	else if(choice == 3)
	{
		add();
	}
	
	else if(choice == 4)
	{
		deleteChoice();
	}
	
	else if(choice == 5)
	{
		edit();
	}
	
/*	else if(choice == 6)
	{
		printAllBookInfo();
	}*/
	
	else if(choice == 6)
	{
		fflush(stdin);
		system("cls");
		menuOfAdmin();
	}
	
	else if(choice == 7)
	{
		end();
	}
	system("cls");
	pageEnterAdmin();
	return 0;

} // end of enterPageAdmin

int menuOfAdmin() //Menu of admin when enter correct password
{
	int choose = 0;
	char word;
	int tmp = 0;
	int tmp2 = 0;
	int i = loadBooks();
	
	makeLine(4);
	makeTab(3);
	int mutation = intel(10, 0);
	voiceMenuOfAdmin(mutation);
	
	viewBooksInfo[0].adminOrUser = 0;
	viewBooksInfo[0].maxStruct = i;
	
	makeLine(3);
	makeTab(3);
	textColor(14);
	printf("---/~~Harsh Library~~/---");
	textColor(15);
	//makeLine(2);
	
	makeLine(2);
	textColor(14);//yellow
	printf("\t\tChoose your requirement\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(34);//--------------------
	
	textColor(15);
	printf("\t\t1. Informations of books.\n");
	printf("\t\t2. Borrowing list.\n");
	printf("\t\t3. Returning list.\n");
	printf("\t\t4. Change password.\n");
	printf("\t\t5. Create an account for user.\n");
	printf("\t\t6. Back.\n");
	printf("\t\t7. Exit.\n");
	
	textColor(11);
	printf("\t\t");
	drawLine(34);//-----------------
	
	textColor(14);
	printf("\t\tYour requirement is: ");
	textColor(15);
	
	
	choose = checkNumber(7);// max choice can be changed
	
	if(choose == 1) // info of books
	{
		system("cls");
		pageAdmin(i);
	}
	
	if(choose == 2) // borrowing list
	{
		do {
			char yesNoBorrowingList = 'y';
			system("cls");
			makeLine(4);
			makeTab(3);
			mutation = intel(6, 0);
			voiceAfterMenuOfAdmin(mutation);
			//print menu
			printf("\n\n");
			textColor(14);//yellow
			printf("\t\tChoose your requirement\n");
	
			textColor(11);
			printf("\t\t");
			drawLine(30);//--------------------
	
			textColor(15);
			printf("\t\t1. View borrowing list.\n");
			printf("\t\t2. Add borrower.\n");
			printf("\t\t3. Check returned status.\n");
			printf("\t\t4. Edit info.\n");
			printf("\t\t5. Back.\n");
			printf("\t\t6. Exit.\n");
			//get choice
			textColor(11);
			printf("\t\t");
			drawLine(30);//-----------------
	
			textColor(14);
			printf("\t\tYour requirement is: ");
			textColor(15);
			int borrowingList = getChoice(6);
			
			//switch choice
			switch (borrowingList) {
				//View borrowing list
				case 1: {
					viewBorrowingList();
					break;
				}
				
				//Add borrower
				case 2: {
					addBorrower();
					break;
				}
				
				//check returned status
				case 3: {
					checkReturnStatus();
					break;
				}
				
				//edit info
				case 4: {
					editBorrowingList();
					break;
				}
				
				//back
				case 5: {
					system("cls");
					menuOfAdmin();
					break;
				}
				
				//exit
				case 6: end();
				}
			} while (1);
	} // end of if choose 2
	
	if(choose == 3)
	{
		do {
				system("cls");
				//print menu
				makeLine(4);
				makeTab(3);
				mutation = intel(6, 0);
				voiceAfterMenuOfAdmin(mutation);
				printf("\n\n");textColor(14);//yellow
				printf("\t\tChoose your requirement\n");
	
				textColor(11);
				printf("\t\t");
				drawLine(31);//--------------------
	
				textColor(15);
				printf("\t\t1. View returned list.\n");
				printf("\t\t2. Change returned status.\n");
				printf("\t\t3. Delete info.\n");
				printf("\t\t4. Back.\n");
				printf("\t\t5. Exit.\n");
				//get choice
				textColor(11);
				printf("\t\t");
				drawLine(31);//-----------------
	
				textColor(14);
				printf("\t\tYour requirement is: ");
				textColor(15);
				int returnList = getChoice(5);
				
				//switch
				switch (returnList) {
					//view returned list
					case 1: {
						viewReturnedList();
						break;
					}
					
					//change returned status
					case 2: {
						changeReturnStatus();
						break;
					}
					
					//delete info
					case 3: {
						deleteBorrowInfo();
						break;
					}
					
					//back
					case 4: {
						system("cls");
						menuOfAdmin();
						break;
					}
					
					//exit
					case 5: end();
				}
			} while (1);
	} // end of if choose 3
	
	if(choose == 4) // change password
	{
		system("cls");
		fflush(stdin);
		changePassword();
	} // end of if choose 4
	
	if(choose == 5) // creat account for users
	{
		fflush(stdin);
		system("cls");
		userPassword();
	} // end of if chooose 5
	
	if(choose == 6) // back
	{
		system("cls");
		firstMenu();
	} // end of if choose 6
	
	if(choose == 7) // exit
	{
		end();
	} // end of if choose 7
	

	return 0;
} //end of menu of admin


int checkPass(char acc[100], int follow) //check password 2 time of create account feature
{
	char ch; // a character
	int i = 0; // number in array
	
	if ( follow == 3) printf("\n\n\t\tEnter password: ");
	if ( follow == 4) printf("\n\n\t\tEnter password again: ");
	
	
		while(1)//password of user
	{
		ch = getch();
		if(ch == ENTER)//enter when finish
		//enter 13
		{
			acc[i] ='\0';
			break;
			
		}
		
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			menuOfAdmin();//call other function
			//get back
			return 0;
			break;			
			
		}
		
		
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			userPassword();
			//the same function
			return 0;
			break;
			
			
			//continue;
		}
		else {  //make a chracter to *
			acc[i] = ch;
			i++;
			printf("*");
			
		}
	} // end enter password of user
	
	
	return *acc;
}

 

char create(char string[100], int follow)//enter username of user
{
	//char username[100];
	int i = 0;
	char ch;
	
	printf("\n");
	
	// int folow make many situations
	if(follow == 1)printf("\n\t\tStudent's name: ");
	if(follow == 2)printf("\n\t\tEnter username: ");
	
	
	while(1)//username of user
	{
		ch = getch();
		if(ch == ENTER)//enter when finish
		//enter 13
		{
			string[i] ='\0';
			break;
			
		}
		
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			menuOfAdmin();//call other function
			//get back
			return 0;
			break;			
			
		}
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			userPassword();
			//the same function
			return 0;
			break;
			
			
			//continue;
		}
		else {  //make a chracter to *
			string[i] = ch;
			i++;
			printf("%c", ch);
			
		}
	}//end enter username
	
	return *string;
}

int userPassword()//create account need id, FIRST function of create feature account
{
	char cmpacc[100];//compare account
	char name[100];//name of student
	char username[100];//username or student's code
	int i = 0;//num in array
	char ch;// a character
	int follow;// subNumber
	int shutdown = 1; // shut down when go out or wrong
	
	trouble();
	
	follow = 1;// the first situation
	shutdown = create(name, follow);// name of student
	if(shutdown == 0) return 0;
	
	follow = 2;// the second situation
	
	while(1)
	{
	
	shutdown = create(username, follow);//username or student's code
	if (compareAccount(cmpacc, username) == 1) break;
	//check acount
	}
	if(shutdown == 0) return 0;

	// when input useranme successfully
	if(strcmp(cmpacc, username) != 0)
	{
	printf(" \tSucess!!\n");
	}
	
	char acc[100]; //first input password
	char acc2[100]; // second input password
	i = 0;//reset i 1
	
	follow = 3; //the first input password of create account feature
	shutdown = checkPass(acc, follow);
	if(shutdown == 0) return 0;
	
	// when finish first input pasword
	printf(" \tSucess!!");
	
	// the second input password
	follow = 4;
	shutdown = checkPass(acc2, follow);
	if(shutdown == 0) return 0;
	
	while(strcmp(acc, acc2) != 0)
	{
		textColor(4); // red
		printf(" \tWrong!!");
		textColor(15);
		checkPass(acc2, follow); //follow = 4
	}
	if(shutdown == 0) return 0;
	
	// when create account sucessfully
	if(strcmp(acc, acc2) == 0)
	{	
		printf(" \tSucess!!");
		
		// file of user's name
		FILE *facc1;//file account
		facc1 = fopen("nameOfStudents.txt", "a");//write->
		fprintf(facc1, "%s\n", name);
			
		fclose(facc1); // close file user's name
		
		// file of username
		FILE *facc2;//file account
		facc2 = fopen("userUsername.txt", "a");//write->
		fprintf(facc2, "%s\n", username);
			
		fclose(facc2); //close file username
		
		
		FILE *facc3;
		facc3 = fopen("userPassword.txt", "a");//write
		change(acc);
		fprintf(facc3, "%s\n", acc);
		printf("\n\t\tPress a key to back...\n");
		getch();//press a key...
								
		fclose(facc3);//close userPassword.txt
		
		fflush(stdin);
		system("cls");
		
		menuOfAdmin();//back
	}
	
	return 0;
	
}//end of userPassword function

int changePassword()
{
	
	FILE *pw;//file password
	
	pw = fopen("password.txt", "r");//open file to read
	char realPassword[100];//array of password
	
	fscanf(pw, "%[^\n]%*c", realPassword);//txt to console 
	//puts(arr);//print to console
	
	fclose(pw);//close file
	
	
	char password[100];//array of new password
	int i = 0;//sub number
	char ch;//a character
	
	
	trouble();
	
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\t\tEnter password: ");
	
	while(1)
	{
		ch = getch();
		//get a character
		if(ch == ENTER)//enter will stop
		{
			password[i] = '\0';
			rechange(realPassword);
			if(strcmp(password, realPassword ) == 0)
			{
				printf("\tOK!");
				//when correct password
				break;
			}
			
			if(strcmp(password, realPassword) != 0)
			{
				//when wrong password
				system("cls");
				trouble();
				printf("\n\n\n\tYour password is not correct.");
				
				printf("\n\tEnter your password again!!\n");
				printf("\n\n");
				printf("\t\tEnter password: ");
				i = 0;//new loop
			}
							
		}
		
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			menuOfAdmin();
			//this is menu of admin
			return 0;
			break;			
			
		}
		
		
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			changePassword();
			//the same function
			return 0;
			break;
			
			
			//continue;
		}
		else
		{
			password[i] = ch;
			i++;
			printf("*");
		}
	}
	
	printf("\n\n\t\tEnter new password: ");
	
	char newPassword[100];
	i = 0;//restart i (1)
	//char ch;
	
	while(2)
	{
		ch = getch();
		
		if(ch == ENTER)//end new pass word
		{
			
			newPassword[i] = '\0';
			rechange(newPassword);
			//new password need to be compared to old pass word
			
			if(strcmp(newPassword, realPassword) == 0)
			{
				
				printf("\n\t\t\tNew password must be different from old password");
				printf("\n\t\tEnter new password: ");
				i = 0;
			}
			if(strcmp(newPassword, realPassword) != 0)
			{
				printf("\tOK!");
				break;//end loop
			}
			//end loop will make enter new password again
			
			
		}
		
		else if(ch == BKSP)
		{
			if(i > 0)
			{
			i--;
			printf("\b \b");
			}
		}
		
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			
			//call other function
			menuOfAdmin();
			return 0;
			break;			
			
		}
		
		
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			changePassword();
			//the same function
			return 0;
			break;
			
			
			//continue;
		}
		else
		{
			newPassword[i] = ch;
			i++;
			printf("*");
		}
	}
	
	printf("\n\n");
	printf("\t\tEnter new password again: ");
	
	char newPassword2[100];
	i = 0; //restart i (2)
	//char ch;
	
	
	while(3)
	{
		ch = getch();
		
		if(ch == ENTER)
		{
			newPassword2[i] = '\0';
			rechange(newPassword);
			if(strcmp(newPassword2, newPassword) == 0)
			{
				printf("\tOK!");
				
				// change password in txt
				
				//open file password.txt
				pw = fopen("password.txt", "w");
				
				change(newPassword);
				//print new password in txt
				fprintf(pw,"%s", newPassword);
				
				//close file txt
				fclose(pw);
				
				//finish
				
				break;
			}
			if(strcmp(newPassword2, newPassword) != 0)
			{
				//when newPassword2 is not the same newPassword
				printf("\tNOPE!");
				printf("\n\t\tEnter new password again: ");
				i = 0;
			}
		}
		else if(ch == BKSP)
		{
			if(i > 0)
			{
			
			i--;
			printf("\b \b");
			}
			
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			//call other function
			menuOfAdmin();
			//this is menu of admin
			return 0;
			break;			
			
		}
		
		
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			changePassword();
			//the same function
			return 0;
			break;
			
			
			//continue;
		}
		else
		{
			newPassword2[i] = ch;
			i++;
			printf("*");
		}
	}
	
	// finish will back
	//should change ---------------
	printf("\n\n");
	printf("\t\tPress a key to back...");
	getch();//press a key
	fflush(stdin);
	system("cls");
	
	//call other function
	//back
	
	menuOfAdmin();
	return 0;
}//end of funtion changePassword

int adminPassword() {
		
	trouble();
	
	// Enter password
	char password[100];//password
	int i = 0;
	int j = 0;
	char ch;
	char chj;
	printf("\n\n\n\n");
	printf("\n\n\n");
	printf("\t\tEnter password: ");
	while(1)
	{
		ch = getch();
		if(ch == ENTER)//enter when finish
		//enter 13
		{
			password[i] ='\0';
			FILE *pw;//file password
	
			pw = fopen("password.txt", "r");//open file to read
			char realPassword[100];//array of password
	
			fscanf(pw, "%[^\n]%*c", realPassword);//txt to console 
			
			fclose(pw);//close file
			rechange(realPassword);
			//break;
			if(strcmp(password, realPassword) == 0)
			{
				printf("\n\n\tCorrect password!!\n");
				getch();
		
				fflush(stdin);
				system("cls");
				menuOfAdmin();// call other function
		
				return 0;
				break;
			}
			if(strcmp(password, realPassword) != 0)
			{
				//when your password is not correct
		
				system("cls");
				trouble();
				printf("\n\n\n\tYour password is not correct.");
		
				printf("\n\tEnter your password again!!\n");
				printf("\n\n");
				printf("\t\tEnter password: ");
				i = 0;
			//new loop
		}
		}//end enter
		else if (ch == BKSP)
		{
			if(i > 0)
			{			
			//back space
			i--;
			printf("\b \b");
			}
		}
		else if(ch == ESC)//want to get back
		{
			//back
			i = 0;
			fflush(stdin);
			system("cls");
			firstMenu();
			//this is firstMenu
			return 0;
			break;			
			
		}
		else if (ch == TAB)//want to reset
		{
			//tab can't work
			//tab will reset function
			i = 0;
			fflush(stdin);
			system("cls");
			adminPassword();
			//the same function
			return 0;//end
			break;	
			//continue;
		}
		else 
		{  //make a chracter to *
			password[i] = ch;
			i++;
			printf("*");
			
		}
	}
	//printf("\n\nYour password is: %s", password);
	//getch();
	//system("cls");
	
	//call other function
	menuOfAdmin();
	return 0;
}//end of password function


int compareAccount(char cmpacc[100], char username[100]) // create account feature
{
	
	FILE *facc;//file account
	
	facc = fopen("userUsername.txt", "r");//read


	while (!feof(facc)) //scan account in userPassword.txt
	{
		
		fscanf(facc, "%[^\n]%*c", cmpacc);
		if(strcmp(cmpacc, username) == 0 )
		{
		printf("\n\t\tThis account has been existed\n");
		
		fflush(stdin);
		
		return 0;
		break;
		}
		//fscanf(facc, "\n");
		//it may never stop
		//i++; -> line++
	}
		fclose(facc);
		
	return 1;
	
} // end of compareAccount function


int loadBooks()
{
	int i = 0; // num in struct
	int j = 0; // num in array
	
	
	FILE *fcode;
	fcode = fopen("BookCode.txt", "r");
	char code[100];
	
	FILE *fname;
	fname = fopen("Title.txt", "r");
	char name[100];
	
	FILE *fcate;
	fcate = fopen("Cate.txt", "r");
	char cate[100];
	
	FILE *festab;
	festab = fopen("YearEstab.txt", "r");
	char estab[100];
	
	FILE *fquan;
	fquan = fopen("Quanlity.txt", "r");
	char quan[100];
	
	FILE *fquanAvai;
	fquanAvai = fopen("QuanlityAvai.txt", "r");
	char quanAvai[100];
	
	while(!feof(fcode))
	{
		
		fscanf(fcode, "%[^\n]%*c", code);
		fscanf(fname, "%[^\n]%*c", name);
		fscanf(fcate, "%[^\n]%*c", cate);
		fscanf(festab, "%[^\n]%*c", estab);
		fscanf(fquan, "%[^\n]%*c", quan);
		fscanf(fquanAvai, "%[^\n]%*c", quanAvai);
		
		strcpy(viewBooksInfo[i].codeBook, code);
		strcpy(viewBooksInfo[i].nameBook, name);
		strcpy(viewBooksInfo[i].cateBook, cate);
		strcpy(viewBooksInfo[i].estabBook, estab);
		strcpy(viewBooksInfo[i].quanBook, quan);
		strcpy(viewBooksInfo[i].quanAvaiBook, quanAvai);
		
		i++; // num in struct
		//wall++; // make page
		
	} // end of big while 1
	
	//i--; // superfluous
	
	// close all file
	fclose(fcode);
	fclose(fname);
	fclose(fcate);
	fclose(festab);
	fclose(fquan);
	fclose(fquanAvai);
	
	return i;
} // end of loadBooks

int pageAdmin(int i) 
// code of user, new or old user, id in txt, max num in struct(all books)
{
	//	struct library viewBooksInfo[1999];
	//backTitle();
	
	int numOfBook;
	importRentValue(&numOfBook);
	//setExtraBookRentInfo();
	
	int  numberOfLending = 0;
	
	int wall = 0; // make page
	char walk; // type to make new page
	int slide = 1; // ordinal of page
	
	//i = loadBooks();
	backTitle();
	titleOfPage();
	drawLine(144);
	
	slide = i + 1; // sub num help know begin,last page. +1(arr)
	int symbol = slide; // symbol || in first page
	int max = i - 1; // -1 (arr)
	i = 0; // reset i
	wall = 0;
	int numOfPage = 1;
	short balance = 0;
	
	// while 2
		while(2) // no 1
	{
		makeTab(2);
		
		spaceLeftSide(viewBooksInfo[i].codeBook, 4); // only for code;
		
		printf("%s",viewBooksInfo[i].codeBook);
		
		printf("\t ");
		
		printf("%s",viewBooksInfo[i].nameBook);
		spaceRightSide(viewBooksInfo[i].nameBook, 42); // 1
		
		balance = spaceLeftSide(viewBooksInfo[i].cateBook, 6);
		printf("%s",viewBooksInfo[i].cateBook);
		spaceRightSide(viewBooksInfo[i].cateBook, 21- balance); // 2
		
		
		printf("%s",viewBooksInfo[i].estabBook);
		spaceRightSide(viewBooksInfo[i].estabBook, 18); // 3
		
		printf("%s",viewBooksInfo[i].quanBook);
		spaceRightSide(viewBooksInfo[i].quanBook, 18); // 4
		
		printf("%s",viewBooksInfo[i].quanAvaiBook);
		spaceRightSide(viewBooksInfo[i].quanAvaiBook, 22); // 5
		
		numberOfLending = toNum(viewBooksInfo[i].quanBook) - toNum(viewBooksInfo[i].quanAvaiBook);
		if( toNum(viewBooksInfo[i].quanBook) > 0) printf("%d", numberOfLending);
		
		printf("\n");
		printf("\t\t");
		
		drawLine(144);

		wall++; // make page
		
		//printf("%d", slide);
		if(wall == 10) // can be changed
		{
			printf("\n");
			makeTab(14);
			printf(" ");
			if(slide == symbol) printf("||"); // first page
			printf("<-- Back  |%d|  Next-->", numOfPage);
			if(slide <= wall + 1) printf("||"); // last page
			printf("\n\n");
			makeTab(14);
			
			printf("Enter to Use More Features");
			
			walk = viewBooksInfoOption(i, wall, max); // left or right, max can prevent go out from last/begin page
			
			if(walk == 1 || walk == 2) // left or right
			{
				system("cls");
				//printf("\n\n");
				makeTab(4);
				
			if(walk == 1) // left
			{
				i -= ((wall * 2) - 1); // i must be double and plus 1 and dependent on condition of wall
				slide += wall; // max of slide is biggest num in struct + 1 (arr)
				numOfPage--; // back
				
				//system("cls");
				backTitle();
				titleOfPage(); // make new page
				drawLine(144);
				
				wall = 0; // reset wall to make page
				
			} // end of if 1
			
			if (walk == 2) // right
			{	
				i++; // num instruct
				slide -= wall; // min of slide is wall + 1 (arr)
				
				numOfPage++; // next
				
				//system("cls");
				//titleOfPage(); //make new page
				//drawLine(144);
				
				backTitle();
				wall = 0; // reset wall to make page
				titleOfPage(); //make new page
				drawLine(144);
			} // end of if 2
			} // end of if 1||2
			
			if(walk == 3)
			{
				override(strlen("Enter to Use More Features"));
				//moonwalk(115);
				pageEnterAdmin(i);
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 3
			
			
			if(walk == 4) // want back
			{
				system("cls");
				fflush(stdin);
				menuOfAdmin();
				return 0;
			} // end of if 4
			
		
		} // end of if wall
		else
		{
			i++; // num in struct
		}

	
	} // end of big while 2
	
	return 0;
	
} //end of pageAdmin function


int page(char stuCode[100], int newOrOld, int id, int i) 
// code of user, new or old user, id in txt, max num in struct(all books)
{
	//	struct library viewBooksInfo[1999];
	backTitle();
	
	char rec[100];
	int recNumArray[4999];
	int recNum = 0;
	int dif = -1; // not the same rec
	int mutation = -1;
	int hiddenMutation[999]; // no mutation
	short ihiddenMutation = 0; // in hiddenMutation
	unsigned short needMore = 0; // in intel
	unsigned short moreThanOne = 0; // more 1 book
	unsigned short makeNewRec = 0;
	int difMakeNewRec[999]; // not the same makeNewRec
	short idifMakeNewRec = 0; // num in difMakeNewRec array
	unsigned short breakBigger = 0; // break bigger while
	//unsigned int newOrOldUser = 0; // new = 0
	char recCode[3000]; // num-string
	char recEstab[3000]; // num-string
	short balance = 0; // look better
	
	FILE *frec;
	frec = fopen("Cate.txt", "r");
	int r = 0; // for userRec
	int maxr = 0;
	
	// all cate
	while(!feof(frec))
	{
		fscanf(frec, "%[^\n]%*c", viewBooksInfo[r].userRec);// end
		//printf("%s\n", viewBooksInfo[r].userRec);
		r++;
	}
	fclose(frec); // close file
	//r -= 2; // superfluous(txt\n)
	r--; // superfluous
	
	maxr = r; // max in struct.userRect
	
	int numOfBook;
	importRentValue(&numOfBook);
	//setExtraBookRentInfo();
	
	if(newOrOld > 0) // old
	{
		printf("\n\n");
		makeTab(4);
		mutation = intel(8, -6969);	// can be changed
		voicePageRecOld(mutation);
		int n = 0; // num in strange array/struct
		// strange function
		int numOfRent;
		importRentValue(&numOfRent);
		setExtraBookRentInfo();
		// cate borrowed
		for(; n >= numOfRent; n++)
		{
			rent[n].category;
		}
		// some books
		for(r = 0; r <= maxr; r++)
		{
			if(strcmp(rent[n].category, viewBooksInfo[r].userRec) == 0)
			{
				recNumArray[recNum] = r;
				recNum++;
				moreThanOne++;
			}
		}
	
		recNum--; // superfluous
		mutation = intel(recNum, needMore); // mutation num 1
		difMakeNewRec[idifMakeNewRec] = mutation; // first difMakeNewRec
		hiddenMutation[ihiddenMutation] = mutation; // storage 1
		dif = mutation;
		mutation = recNumArray[mutation];
	
		// voice
		titleOfRec();
		makeTab(2);
		drawLine(85);//--------
		makeTab(4);
		
		wantString(book[mutation].code, recCode);
		spaceLeftSide(recCode, 4);
		printf("%s", recCode);
		spaceRightSide(recCode, 6);
			
		printf("%s", book[mutation].name);
		spaceRightSide(book[mutation].name, 40);
		
		balance = spaceLeftSide(book[mutation].category, 6);
		printf("%s", book[mutation].category);
		spaceRightSide(rent[mutation].category, 19 - balance);
		
		printf("%s", book[mutation].year);
	
		if(moreThanOne > 1)
		{
			while(1)
			{
				mutation = intel(recNum, needMore); // mutation num 2
				if(mutation != dif)
				{
					idifMakeNewRec++;
					difMakeNewRec[idifMakeNewRec] = mutation; // the second difMakeNewRec 
					ihiddenMutation++;
					hiddenMutation[ihiddenMutation] = mutation; // storage 2
					mutation = recNumArray[mutation];
					break;
				}
				fflush(stdin);
				needMore++;
			}
		} // end of if moreThanOne
		//printf("%d", mutation);
		printf("\n");
		makeTab(4);
		drawLine(85);//-------
		makeTab(4);
	
		wantString(book[mutation].code, recCode);
		spaceLeftSide(recCode, 4);
		printf("%s", recCode);
		spaceRightSide(recCode, 6);
			
		printf("%s", book[mutation].name);
		spaceRightSide(book[mutation].name, 40);
		
		balance = spaceLeftSide(book[mutation].category, 6);
		printf("%s", book[mutation].category);
		spaceRightSide(rent[mutation].category, 19 - balance);
		
		printf("%s", book[mutation].year);
 
	} // end of if newOrOld > 0
	//int i = 0; // num in struct
	int  numberOfLending = 0;
	
	int wall = 0; // make page
	char walk; // type to make new page
	int slide = 1; // ordinal of page
	
	//i = loadBooks();
	titleOfPage();
	drawLine(144);
	
	slide = i + 1; // sub num help know begin,last page. +1(arr)
	int symbol = slide; // symbol || in first page
	int max = i - 1; // -1 (arr)
	i = 0; // reset i
	wall = 0;
	int numOfPage = 1;
	//short balance = 0;
	
	// while 2
		while(2) // no 1
	{
		makeTab(2);
		
		spaceLeftSide(viewBooksInfo[i].codeBook, 4);
		
		printf("%s",viewBooksInfo[i].codeBook);
		
		printf("\t ");
		
		printf("%s",viewBooksInfo[i].nameBook);
		spaceRightSide(viewBooksInfo[i].nameBook, 42); // 1
		
		balance = spaceLeftSide(viewBooksInfo[i].cateBook, 6);
		printf("%s",viewBooksInfo[i].cateBook);
		spaceRightSide(viewBooksInfo[i].cateBook, 21 - balance); // 2
		
		
		printf("%s",viewBooksInfo[i].estabBook);
		spaceRightSide(viewBooksInfo[i].estabBook, 18); // 3
		
		printf("%s",viewBooksInfo[i].quanBook);
		spaceRightSide(viewBooksInfo[i].quanBook, 18); // 4
		
		printf("%s",viewBooksInfo[i].quanAvaiBook);
		spaceRightSide(viewBooksInfo[i].quanAvaiBook, 22); // 5
		
		numberOfLending = toNum(viewBooksInfo[i].quanBook) - toNum(viewBooksInfo[i].quanAvaiBook);
		if( toNum(viewBooksInfo[i].quanBook) > 0) printf("%d", numberOfLending);
		
		printf("\n");
		printf("\t\t");
		
		drawLine(144);

		wall++; // make page
		
		//printf("%d", slide);
		if(wall == 10) // can be changed
		{
			printf("\n");
			makeTab(14);
			printf(" ");
			if(slide == symbol) printf("||"); // first page
			printf("<-- Back  |%d|  Next-->", numOfPage);
			if(slide <= wall + 1) printf("||"); // last page
			printf("\n\n");
			makeTab(14);
			
			printf("Enter to Use More Features");
			
			walk = viewBooksInfoOption(i, wall, max); // left or right, max can prevent go out from last/begin page
			
			if(walk == 1 || walk == 2) // left or right
			{
				system("cls");
				backTitle();
				
				mutation = intel(8, -6969);	// can be changed
				
				if(newOrOld > 0) // old
				{
				makeNewRec++;
				printf("\n\n");
				makeTab(4);
				voicePageRecOld(mutation);
				if(makeNewRec == 2) // can be changed
				{
					makeNewRec = 0; // reset makeNewRec
						//int n = 0; // num in strange array/struct
						
						while (1) // compare old and new rec
						{
						
						mutation = intel(recNum + 1, needMore); // not 0
						for(idifMakeNewRec = 0; idifMakeNewRec <= 9; idifMakeNewRec++) // condition dependent num in array
						{
							if(difMakeNewRec[idifMakeNewRec] == mutation)
							{
								//printf("difmake: %d \t mutation: %d\n", difMakeNewRec[idifMakeNewRec], mutation);
								//printf("%d\n", idifMakeNewRec);
								breakBigger++;
							}
							//printf("%d\n", idifMakeNewRec);
						}
						
						if(breakBigger == 0) break;
						breakBigger = 0; // reset breakBigger
						needMore++;
						} // end of while compare old and new rec
						
						idifMakeNewRec = 0; // reset in the first rec
						difMakeNewRec[idifMakeNewRec] = mutation; // make new difMakeNewRec
						ihiddenMutation = 0; // reset
						hiddenMutation[ihiddenMutation] = mutation; // storage 1
						dif = mutation;
						mutation = recNumArray[mutation];
						
						// voice
						titleOfRec();
						makeTab(2);
						drawLine(85);//-------
						makeTab(4);
						//printf(" ");
						
						wantString(book[mutation].code, recCode);
						spaceLeftSide(recCode, 4);
						printf("%s", recCode);
						spaceRightSide(recCode, 6);
			
						printf("%s", book[mutation].name);
						spaceRightSide(book[mutation].name, 40);
		
						balance = spaceLeftSide(book[mutation].category, 6);
						printf("%s", book[mutation].category);
						spaceRightSide(rent[mutation].category, 19 - balance);
		
						printf("%s", book[mutation].year);
						/*
						//wantString(rent[mutation].codeRent, recCode);
						wantString(book[mutation].code, recCode);
						spaceLeftSide(recCode, 4);
						printf("%s", recCode);
						spaceRightSide(recCode, 6);
						
						//printf("%s", rent[mutation].title);
						printf("%s", book[mutation].name);
						spaceRightSide(book[mutation].name, 33);
	
						//printf("%s", rent[mutation].category);
						printf("%s", book[mutation].category);
						spaceRightSide(rent[mutation].category, 19);
	
						//wantString(rent[mutation].yearEstablished, recEstab);
						//wantString(book[mutation].year, recEstab);
						printf("%s", book[mutation].year);
						*/
						//printf("%d", mutation);
						fflush(stdin);
						
						// may like before
						if(moreThanOne > 1)
						{
							while(1)
							{
								mutation = intel(recNum + 1, needMore); // not 0
								if(mutation != dif)
								{
									ihiddenMutation++;
									hiddenMutation[ihiddenMutation] = mutation; // storage 2
									mutation = recNumArray[mutation];
									break;
								}
								fflush(stdin);
								needMore++;
							}
						}
						//printf("%d", mutation);
						printf("\n");
						makeTab(4);
						drawLine(85);//------
						makeTab(4);
						
						
						wantString(book[mutation].code, recCode);
						spaceLeftSide(recCode, 4);
						printf("%s", recCode);
						spaceRightSide(recCode, 6);
			
						printf("%s", book[mutation].name);
						spaceRightSide(book[mutation].name, 40);
		
						balance = spaceLeftSide(book[mutation].category, 6);
						printf("%s", book[mutation].category);
						spaceRightSide(rent[mutation].category, 19 - balance);
		
						printf("%s", book[mutation].year);
					/*
					//wantString(rent[mutation].codeRent, recCode);
					wantString(book[mutation].code, recCode);
					spaceLeftSide(recCode, 4);
					printf("%s", recCode);
					spaceRightSide(recCode, 6);
	
					//printf("%s", rent[mutation].title);
					printf("%s", book[mutation].name);
					spaceRightSide(book[mutation].name, 33);
					
					//printf("%s", rent[mutation].category);
					printf("%s", book[mutation].category);
					spaceRightSide(rent[mutation].category, 19);
	
					//wantString(rent[mutation].yearEstablished, recEstab);
					//wantString(book[mutation].year, recEstab);
					printf("%s", book[mutation].year);
					*/
					
				} // end of if makeNewRec
				else
				{
					
					// voice
					titleOfRec();
					makeTab(2);
					drawLine(85);//---------
					makeTab(4);
					
					ihiddenMutation = 0; // reset
					ihiddenMutation = hiddenMutation[ihiddenMutation];
					wantString(book[ihiddenMutation].code, recCode);
					spaceLeftSide(recCode, 4);
					printf("%s", recCode);
					spaceRightSide(recCode, 6);
						
					printf("%s", book[ihiddenMutation].name);
					spaceRightSide(book[ihiddenMutation].name, 40);
					
					balance = spaceLeftSide(book[ihiddenMutation].category, 6);
					printf("%s", book[ihiddenMutation].category);
					spaceRightSide(rent[ihiddenMutation].category, 19 - balance);
	
					printf("%s", book[ihiddenMutation].year);
					
					printf("\n");
					makeTab(4);
					drawLine(85);//-------
					makeTab(4);
					
					ihiddenMutation = 1;
					ihiddenMutation = hiddenMutation[ihiddenMutation];
					
					wantString(book[ihiddenMutation].code, recCode);
					spaceLeftSide(recCode, 4);
					printf("%s", recCode);
					spaceRightSide(recCode, 6);
						
					printf("%s", book[ihiddenMutation].name);
					spaceRightSide(book[ihiddenMutation].name, 40);
					
					balance = spaceLeftSide(book[ihiddenMutation].category, 6);
					printf("%s", book[ihiddenMutation].category);
					spaceRightSide(rent[ihiddenMutation].category, 19 - balance);
	
					printf("%s", book[ihiddenMutation].year);
				} // end of else makeNewRec
				
				} // end of if newOrOld > 0
			if(walk == 1) // left
			{
				i -= ((wall * 2) - 1); // i must be double and plus 1 and dependent on condition of wall
				slide += wall; // max of slide is biggest num in struct + 1 (arr)
				numOfPage--; // back
				
				//system("cls");
				
				titleOfPage(); // make new page
				drawLine(144);
				
				wall = 0; // reset wall to make page
				
			} // end of if 1
			
			if (walk == 2) // right
			{	
				i++; // num instruct
				slide -= wall; // min of slide is wall + 1 (arr)
				
				numOfPage++; // next
				
				//system("cls");
				//titleOfPage(); //make new page
				//drawLine(144);
				
				wall = 0; // reset wall to make page
				
				titleOfPage(); //make new page
				drawLine(144);
			} // end of if 2
			} // end of if 1||2
			
			if(walk == 3)
			{
				override(strlen("Enter to Use More Features"));
				//moonwalk(115);
				pageEnterUser(stuCode, newOrOld, id, i);
				// code of user, new or old user, id in txt, max num in struct(all books)
				return 0;
			} // end of if 3
			
			if(walk == 4) // want back
			{
				system("cls");
				fflush(stdin);
				menuOfUser(id, stuCode);
				return 0;
			} // end of if 4
			
		
		} // end of if wall
		else
		{
			i++; // num in struct
		}

	
	} // end of big while 2
	
	return 0;
	
} //end of page function

// note
int borrowingList(int id, char stuCode[100])//in enterUserAccount->
{
	//int tmp = idb;//id of book
	//printf("%s", stuCode);
	
	
	int n = 0; // num in strange array/struct
	// strange function
	int numOfRent;
	importRentValue(&numOfRent);
	setExtraBookRentInfo();
	
	char code[100];
	//int c = 0;
	
	FILE *fbook;
	fbook = fopen("TitleRent.txt", "r");
	char book[100];//name of book
		
	FILE *fstatus;
	fstatus = fopen("ReturnStatus.txt", "r");
	char status[100];
		
	FILE *fcode;
	fcode = fopen("StudentCodeRent.txt", "r");
	char cmpCode[100];
	
	
	// borrowed day
	FILE *fbday;
	fbday = fopen("DayRent.txt", "r");
	char bday[100];
		
	FILE *fbmonth;
	fbmonth = fopen("MonthRent.txt", "r");
	char bmonth[100];
		
	FILE *fbyear;
	fbyear = fopen("YearRent.txt", "r");
	char byear[100];
	
	// returned day
	FILE *frday;
	frday = fopen("DayDeadline.txt", "r");
	char rday[100];
		
	FILE *frmonth;
	frmonth = fopen("MonthDeadline.txt", "r");
	char rmonth[100];
	
	FILE *fryear;
	fryear = fopen("YearDeadline.txt", "r");
	char ryear[100];
	
	// ai remind
	File *fremind;
	fremind = fopen("returningDay.txt", "r");
	char remind[300];
	int remindNum = 0;
	long second = Time - 60 - 36000 - (31536000 * 36) - ( (31536000 + 86400) * 12 ) - (3600 * 4) - (3600 * 3);
	
	int i = 0; //number in array
	char stringOrdinal[7000];
	char stringCode[200];
	char stringEstab[200];
	
	while(!feof(fcode))
	{
		fscanf(fcode, "%[^\n]%*c", cmpCode);
		
		fscanf(fbook, "%[^\n]%*c", book);
		fscanf(fstatus, "%[^\n]%*c", status);
				
		// borrowed day
		fscanf(fbday, "%[^\n]%*c", bday);
		fscanf(fbmonth, "%[^\n]%*c", bmonth);
		fscanf(fbyear, "%[^\n]%*c", byear);
				
				
		// returned day
		fscanf(frday, "%[^\n]%*c", rday);
		fscanf(frmonth, "%[^\n]%*c", rmonth);
		fscanf(fryear, "%[^\n]%*c", ryear);
		
		// remind
		fscanf(fremind, "%[^\n]%*c", remind);
		
		if(strcmp(cmpCode, stuCode) == 0)
		{
			strcpy(historyOfBorrowing[i].nameBook, book);
			
			strcpy(historyOfBorrowing[i].bday, bday);
			strcpy(historyOfBorrowing[i].bmonth, bmonth);
			strcpy(historyOfBorrowing[i].byear, byear);
			
			strcpy(historyOfBorrowing[i].rday, rday);
			strcpy(historyOfBorrowing[i].rmonth, rmonth);
			strcpy(historyOfBorrowing[i].ryear, ryear);
			
			strcpy(historyOfBorrowing[i].status, status);
			
			//historyOfBorrowing[i].deadline = toNum(remind);
			historyOfBorrowing[i].deadline = atoi(remind);
			if((strcmp(historyOfBorrowing[i].status, "0") == 0) &&  (historyOfBorrowing[i].deadline != 0 )  && (historyOfBorrowing[i].deadline - second <= 86400 * 2 )  ) // no returned
			{
				remindNum++;//printf("i: %d", i);
			}
			//printf("x %ld     x\n", historyOfBorrowing[i].deadline);
			//printf("   %ld\n", historyOfBorrowing[i].deadline - second);
			i++;
		}
	}
	i--; // superfuous
	int ordinal = 1;
	int j = i;
	i = 0;	// sub i
	int mutation = 0;
	int balance = 0; // for cate

	backTitle();
	//printf("%d", remindNum);
	printf("\n");
	if(remindNum > 0) 
	{
		textColor(Blue);
		mutation = intel(3, -12345);
		makeLine(1);
		makeTab(4);
		voiceRemind(mutation);
		makeLine(2);
		textColor(White);
	}
	else
	{
		printf("\n");
	}
	//printf("\t\tOrdinal\t\t  Name of Book\t\t\tCategory\tYear Established\tBorrowed day\t Returned day\t\tReturned Status\n");
	printf("\t\t Ordinal               Name of Book               Category      Year Established         Borrowed day     Returned day         Returned Status\n");
	printf("\t\t");
	drawLine(143);
	
	for(i = 0; i <= j; i++)
	{
		makeTab(2);
		wantString(ordinal, stringOrdinal);
		spaceLeftSide(stringOrdinal, 4);
		printf("%s", stringOrdinal);
		spaceLeftSide(stringOrdinal, 6);
		
		printf("%s", historyOfBorrowing[i].nameBook);
		spaceRightSide(historyOfBorrowing[i].nameBook, 42);
		/*
		wantString(code[i], stringCode);
		printf("%s", stringCode);
		spaceRightSide(stringCode, 7);
		*/
		for(; n < numOfRent; n++)
		{
			if(strcmp(rent[n].userName, stuCode) == 0)
			{
				//printf("yes");
				break;
			}
		}
					
		//printf("%sx", rent[n-1].category);
		balance = spaceLeftSide(rent[n].category, 5);
		printf("%s", rent[n].category);
		spaceRightSide(rent[n].category , 18 - balance);
					
		wantString(rent[n].yearEstablished, stringEstab);
		printf("%s", stringEstab); // num year not string
		spaceRightSide(stringEstab, 20);
		n++; // the next
		
		
		printf("%s/", historyOfBorrowing[i].bday);
		printf("%s/", historyOfBorrowing[i].bmonth);
		printf("%s", historyOfBorrowing[i].byear);
		spaceRightSide(historyOfBorrowing[i].byear, 14);
		
		printf("%s/", historyOfBorrowing[i].rday);
		printf("%s/", historyOfBorrowing[i].rmonth);
		printf("%s", historyOfBorrowing[i].ryear);
		spaceRightSide(historyOfBorrowing[i].byear, 21);
		
		//printf("%s \n", historyOfBorrowing[i].status);
		
		if(strcmp(historyOfBorrowing[i].status, "1") == 0)
		{
			printf("X");
		}
		else printf(" ");
		
		printf("\n");
		printf("\t\t");
		drawLine(143);
		
		ordinal++;
	}
			
			
	//close file information of books
	fclose(fbook);
	fclose(fstatus);
	fclose(fcode);
	
	// close file of time
	fclose(fbday);
	fclose(fbmonth);
	fclose(fbyear);
	fclose(frday);
	fclose(frmonth);
	fclose(fryear);
	
	// close special file
	fclose(fremind);
	
	// want to get back
	//get back to menuOfUser
	
	if(escape())
	{
		//get back when press Esc
		menuOfUser(id, stuCode);
		//call other function
	}

	return 0;
} //end of borrowingList function

int main(int argc, char *argv[]) {
	intro();

	firstMenu(); //need 

	//int numOfBook = arrangeNameAZ();
	//loadBooksArrange(numOfBook);
	
	//long second = Time - 60 - 36000 - (31536000 * 36) - ( (31536000 + 86400) * 12 ) - (3600 * 4) - (3600 * 3);
	//printf("%ld", second);
	//now();

	return 0;
}
