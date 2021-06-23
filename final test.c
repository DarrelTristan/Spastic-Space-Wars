

#include <stdio.h>
#include <omp.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "text.h"
#include "singleplayer.h"
#include "leaderboards.h"
#include "multiplayer.h"


int menu();	//main menu interface
void print_title();

int main(){
	int max_used_threads = 3;
	int option, player, dead = 0;
	int i,j,k;
	int refreshRate = 50;
	int globalScore; float time;
	char name[10];
	do {
		option = menu();
		system("cls");
		switch (option){
			case 1 : 
				{	//Singleplayer
					printf("Username : ");
					scanf("%s", &name);
					single(refreshRate, &time, &globalScore);
					leaderboard(name, &time, &globalScore);
					break;
				}
			case 2 : 
				{	//Local Multiplayer
					multi();
					break;
				}
			case 3 : 
				{	//Leaderboard and save in a file (make a new file if no save file)
					openf();
					display();
					break;
				}
			case 4 : 
				{	//How to Play
					
					break;
				}
			case 5 : 
				{	//Exit Game
					printf("Thanks for playing...");
					getch();
					return 0;
					break;
				}
		}	
	} while (option != 5);
	
	
	


/*	#pragma omp parallel num_threads(max_used_threads)
	{
		int numt = omp_get_thread_num();
		int threads = omp_get_num_threads();
		printf("Hello from thread %d of %d\n", numt, threads);
	}
	return 0;
*/	
	
	
	
	
	
	
}

int menu(){
	char code;
	int input = 0, maks = 5;
	do{
		print_title();
	
		int i;
		char select[maks][3];
		for(i = 0; i < maks; i++){
			strcpy(select[i],"");
		}
		char option[maks][20];
		strcpy(option[0],"Singleplayer");
		strcpy(option[1],"Local-Multiplayer");
		strcpy(option[2],"Leaderboard");
		strcpy(option[3],"How To Play?");
		strcpy(option[4],"Exit Game");
		
		strcpy(select[input],"-->");
		for(i = 0; i < maks; i++){
			printf("%3s |%s\n", select[i], option[i]);
		}
		code = tolower(getch());
		switch (code){
			case 'w' : 
					input--;
					if(input == -1){
						input = maks-1;
					}
					break;
			case 's' : 
					input++;
					if(input == maks){
						input = 0;
					}
					break;
		}
		system("cls");
	} while (code != '\r');
	return input+1;
}



