//paper progress

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
//#include <fcntl.h>

#define REQUIRED_PAGES 30 
#define DEADLINE 21

using namespace std;

int getpages(){
	FILE *readpointer;

	int read1, read2;
	int read3;
	int finish_progress = 0;

	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		return 1;
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

	printf("!!!!!!!!!!!!!!!!\n");
	printf("\n");
	printf("%d/%d \n", month, date);
	printf("Today's Progress: %d\n", progress);
	printf("\n");
	printf("!!!!!!!!!!!!!!!!\n");
	printf("\n");
	printf("\n");
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
		printf("!!!!!!!!!!!!!!!!\n");
		printf("\n");
		printf("No Record to Calculate\n");
		printf("Please Insert Your First Record\n");
		printf("\n");
		printf("!!!!!!!!!!!!!!!!\n");
		printf("\n");
		printf("\n");
		return;
	}
	remaining_pages -= getpages();
	remaining_days = DEADLINE - date_now;
	avg = remaining_pages/remaining_days;

	printf("!!!!!!!!!!!!!!!!\n");
	printf("\n");
	printf("You still have %.0f pages to go within %.0f days. \n"
		, remaining_pages, remaining_days);
	printf("Write at least %.2f pages tomorrow!\n", avg);
	printf("Keep Going\n");
	printf("\n");
	printf("!!!!!!!!!!!!!!!!\n");
	printf("\n");
	printf("\n");
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

	printf("History below: \n");

	while(fscanf(readpointer, "%d%d%d", &read1, &read2, &read3) != EOF){
		printf("%d/%d Progress Today: %d\n", read1, read2, read3);
	}
	if(read3 == -1){
		printf("!!!!!!!!!!!!!!!!\n");
		printf("\n");
		printf("No History\n");
		printf("Please Insert Your First Record\n");
		printf("\n");
		printf("!!!!!!!!!!!!!!!!\n");
		printf("\n");
		printf("\n");
	}
	fclose(readpointer);
}

void refresh(){
	FILE *filepointer;

	filepointer = fopen("progress.txt", "w");
	if(filepointer == NULL){
		printf("error file\n");
	}
	fclose(filepointer);
}

int main(){	
	char option;

	while(1){

		
		printf("****************\n");
		printf("1. Insert Your Today's Progress\n");
		printf("2. Calculate Your Remaining Work\n");
		printf("3. Check your History\n");
		printf("4. Refresh the file information\n");
		printf("5. Quit\n");
		printf("****************\n");
		printf("Enter your choice: ");
		
		cin >> option;
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
		}
		printf("*  * **** **** ****   **** **** * *   * ****\n");
		printf("* *  *    *    *  *   *    *  * * **  * *\n");
		printf("**   ***  ***  ****   * ** *  * * * * * * **\n");
		printf("* *  *    *    *      *  * *  * * *  ** *  *\n");
		printf("*  * **** **** *      **** **** * *   * ****\n");
		printf("\n");
		printf("\n");
		//system("pause");
	}
	return 0;
}