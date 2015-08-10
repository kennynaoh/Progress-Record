//paper progress

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
//#include <fcntl.h>

#define REQUIRED_PAGES 30 
#define DEADLINE 21

#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);

using namespace std;

int getpages(){
	FILE *readpointer;

	int read1, read2;
	int read3;
	int finish_progress = 0;

	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		exit(-1);
	}
	//fscanf(readpointer, "%d%d%d", &read1, &read2, &read3);
	while(fscanf(readpointer, "%d%d%d", &read1, &read2, &read3) != EOF){
		finish_progress += read3;
	}
	fclose(readpointer);
	return finish_progress;
}

void today_progress(){
	FILE *filepointer;

	int month;
	int date;
	int progress;

	printf("Month: ");
	scanf("%d", &month);
	printf("Date: ");
	scanf("%d,", &date);
	printf("Progress Today: ");
	scanf("%d,", &progress);


	filepointer = fopen("progress.txt", "a");
	if(filepointer == NULL){
		printf("error file\n");
		exit(-1);
	}

	fprintf(filepointer, "%d %d %d\n", month, date, progress);
	fclose(filepointer);

	printf("!!!!!!!!!!!!!!!!\n\n");
	printf("%d/%d \n", month, date);
	printf("Today's Progress: %d\n", progress);
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");
}

void progress_calculate(){
	
	float remaining_pages = REQUIRED_PAGES;
	float remaining_days;
	float avg;

	time_t timep;
	struct tm *p;
	time (&timep);
	p = gmtime(&timep);
	int date_now = p->tm_mday;	

	if(getpages() == 0){
		printf("!!!!!!!!!!!!!!!!\n\n");
		printf("No Record to Calculate\n");
		printf("Please Insert Your First Record\n");
		printf("\n!!!!!!!!!!!!!!!!\n\n\n");
		return;
	}
	remaining_pages -= getpages();
	remaining_days = DEADLINE - date_now;
	avg = remaining_pages/remaining_days;

	printf("!!!!!!!!!!!!!!!!\n\n");
	printf("You still have %.0f pages to go within %.0f days. \n"
		, remaining_pages, remaining_days);
	printf("Write at least %.2f pages tomorrow!\n", avg);
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");
}

void history(){
	int read1, read2;
	int read3 = -1;

	FILE *readpointer;
	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		exit(-1);
	}

	printf("\nHistory below: \n");

	fscanf(readpointer, "%d%d%d", &read1, &read2, &read3);
	if(read3 == -1){
		printf("!!!!!!!!!!!!!!!!\n\n");
		printf("No History\n");
		printf("Please Insert Your First Record\n");
		printf("\n!!!!!!!!!!!!!!!!\n\n\n");
		fclose(readpointer);
		return;
	}

	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		exit(-1);
	}

	printf("!!!!!!!!!!!!!!!!\n\n");
	while(fscanf(readpointer, "%d%d%d", &read1, &read2, &read3) != EOF){
		printf("%d/%d Progress Today: %d\n", read1, read2, read3);
	}
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");	
	
	fclose(readpointer);
}

void refresh(){
	FILE *filepointer;

	filepointer = fopen("progress.txt", "w");
	if(filepointer == NULL){
		printf("error file\n");
	}
	fclose(filepointer);
	printf("!!!!!!!!!!!!!!!!\n\n");
	printf("Refresh Now\n");
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");
}

int main(){	
	char option;

	while(1){

		
		printf("****************\n");
		printf("1. Today's Progress\n");
		printf("2. Remaining Work\n");
		printf("3. History\n");
		printf("4. Refresh\n");
		printf("5. Quit\n");
		printf("****************\n");
		printf("Enter your choice: ");
		
		//cin >> option;
		scanf("%c", &option);
		switch(option){
			case '1': today_progress();
				break;
			case '2': progress_calculate();
				break;
			case '3': history();
				break;
			case '4': refresh();
				break;
			case '5':
				exit(-1);
			default:
				printf("error option\n");
				printf("try it again\n");
				break;
		}
		printf("*  * **** **** ****   **** **** * *   * ****\n");
		printf("* *  *    *    *  *   *    *  * * **  * *\n");
		printf("**   ***  ***  ****   * ** *  * * * * * * **\n");
		printf("* *  *    *    *      *  * *  * * *  ** *  *\n");
		printf("*  * **** **** *      **** **** * *   * ****\n");
		printf("\n");
		printf("\n");

		while(getchar() != '\n');
		printf("Press Enter key to continue...");
		while(getchar() != '\n');

		//fgetc(stdin);
		//system("pause");
	}
	return 0;

}