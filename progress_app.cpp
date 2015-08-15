//paper progress

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
//#include <fcntl.h>

#define REQUIRED_PAGES 30 
#define DEADLINE 21

//#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);

using namespace std;

int getpages(){
	FILE *readpointer;

	int month;
	float date;
	float progress;
	float finish_progress = 0;

	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		exit(-1);
	}
	//fscanf(readpointer, "%d%d%d", &read1, &read2, &read3);
	while(fscanf(readpointer, "%d%f%f", &month, &date, &progress) != EOF){
		finish_progress += progress;
	}
	fclose(readpointer);
	return finish_progress;
}

void today_progress(){
	FILE *filepointer;

	int month;
	int date;
	float progress;

	printf("Month: ");
	scanf("%d", &month);
	printf("Date: ");
	scanf("%d,", &date);
	printf("Progress Today: ");
	scanf("%f,", &progress);


	filepointer = fopen("progress.txt", "a");
	if(filepointer == NULL){
		printf("error file\n");
		exit(-1);
	}

	fprintf(filepointer, "%d %d %.1f\n", month, date, progress);
	fclose(filepointer);

	printf("!!!!!!!!!!!!!!!!\n\n");
	printf("%d/%d \n", month, date);
	printf("Today's Progress: %.1f\n", progress);
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");
}

void progress_calculate(){
	
	float remaining_pages = REQUIRED_PAGES;
	float remaining_days;
	float avg;

	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	
	int date_now = timeinfo->tm_mday;
	float hour_now = timeinfo->tm_hour;
	float today = (24-hour_now)/24;

	if(getpages() == 0){
		printf("!!!!!!!!!!!!!!!!\n\n");
		printf("No Record to Calculate\n");
		printf("Please Insert Your First Record\n");
		printf("\n!!!!!!!!!!!!!!!!\n\n\n");
		return;
	}
	remaining_pages -= getpages();
	remaining_days = DEADLINE - date_now + today;
	avg = remaining_pages/remaining_days;

	printf("!!!!!!!!!!!!!!!!\n\n");
	printf("You still have %.1f pages to go within %.2f days. \n"
		, remaining_pages, remaining_days);
	printf("Write at least %.2f pages tomorrow!\n", avg);
	printf("\n!!!!!!!!!!!!!!!!\n\n\n");
}

void history(){
	int month;
	float date;
	float page = -1;

	FILE *readpointer;
	readpointer = fopen("progress.txt", "r");
	if(readpointer == NULL){
		printf("error file\n");
		exit(-1);
	}

	printf("\nHistory below: \n");

	fscanf(readpointer, "%d%f%f", &month, &date, &page);
	if(page == -1){
		printf("!!!!!!!!!!!!!!!!\n\n");
		printf("No History\n");
		printf("Please Insert Your First Record\n");
		printf("\n!!!!!!!!!!!!!!!!\n\n\n");
		fclose(readpointer);
	}else{
		printf("!!!!!!!!!!!!!!!!\n\n");
		do{
			printf("%d/%.1f Progress Today: %.1f\n", month, date, page);
		}while(fscanf(readpointer, "%d%f%f", &month, &date, &page) != EOF);
		printf("\n!!!!!!!!!!!!!!!!\n\n\n");
		fclose(readpointer);
	}
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
		printf("1. Progress\n");
		printf("2. Remaining Work\n");
		printf("3. History\n");
		printf("4. Refresh\n");
		printf("5. Quit\n");
		printf("****************\n");
		printf("Enter your choice: ");
		
		//cin >> option;

		scanf("%c", &option);
		getchar();
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


		printf("Press Enter key to continue...");
		while(getchar() != '\n');

		//fgetc(stdin);
		//system("pause");
	}
	return 0;

}
