#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"
int main() {
	printf("vvedite pervoe chislo\n");
	char* line1=NULL;
	size_t len1=0;
	int sizeLine1=0;
	char* line2=NULL;
	size_t len2=0;
	int sizeLine2=0;
	sizeLine1=getline(&line1,&len1,stdin);
	*(line1+sizeLine1-1)='\0';
	char sim;
	if (*(line1+0) == '~'){
		if (*(line1+1) != '0'){
			binory_1(line1);
		}
		if (*(line1+1) == '0' && *(line1+2) != 'x'){
			int ten4=0;
			for (int i=2; i<strlen(line1);i++){
				ten4+=pow(8,strlen(line1)-i-1)*(*(line1+i)-48);
			}	
			printf("%i",ten4);
			int index=0;
			while (ten4>0){
				if (ten4%2 == 0){
					*(line1+index)='0';
				}
				else{
					*(line1+index)='1';
				}
				index++;
	     		ten4=ten4/2;
			}
			char* line3=calloc(128,sizeof(char));
			for (int i=0; i<strlen(line1); i++){
				*(line3+i)=*(line1+strlen(line1)-i-1);
			}
			strcpy(line1,line3);
			free(line3);
			line3=NULL;
			oct_1(line1);
		}
		if (*(line1+1) == '0' && *(line1+2) == 'x'){
			int ten4=0;
			for (int i=3; i<strlen(line1);i++){
				if (*(line1+i) > 47 && *(line1+i)<58){
					ten4+=pow(16,strlen(line1)-i-1)*(*(line1+i)-48);
				}
				else{
					ten4+=pow(16,strlen(line1)-i-1)*(*(line1+i)-87);
				}
			}
			int index=0;
			while (ten4>0){
				if (ten4%2 == 0){
					*(line1+index)='0';
				}
				else{
					*(line1+index)='1';
				}
				index++;
	     		ten4=ten4/2;
			}
			char* line3=calloc(128,sizeof(char));
			for (int i=0; i<strlen(line1); i++){
				*(line3+i)=*(line1+strlen(line1)-i-1);
			}
			strcpy(line1,line3);
			free(line3);
			line3=NULL;
			hex_1(line1);
		}
	}
	else{
		printf("vvedite vtoroe chislo\n");
		sizeLine2=getline(&line2,&len2,stdin);
		*(line2+sizeLine2-1)='\0';
		printf("vvedite simvol operacii\n");
		scanf(" %c", &sim);
		if (((sim == '&') || (sim == '^') || (sim == '|')) && (((*line1)+0 == '-') || (*line1)+0 == '-')){
			printf("Ошибка: числа должны быть положительные\n");
		}
		else{
			if (*(line1+0) != *(line2+0)){
				printf("Ошибка: системы исчисления не совпадают\n");
			}
			if  ( (*(line1+1) != *(line2+1)) && (*(line1+0) == '0') && (*(line2+0) == '0')){
				printf("Ошибка: системы исчисления не совпадают\n");
			}	
			if (*(line1) != '0' && *(line2) != '0'){
				binory(line1, line2, sim);
			}
			if (*(line1) == '0' && *(line1+1) != 'x' && *(line2) == '0' && *(line2+1) != 'x'){
				int ten4=0;
				for (int i=1; i<strlen(line1);i++){
					ten4+=pow(8,strlen(line1)-i-1)*(*(line1+i)-48);
				}
				int ten5=0;
				for (int i=1; i<strlen(line2);i++){
					ten5+=pow(8,strlen(line2)-i-1)*(*(line2+i)-48);
				}
				int index=0;
				while (ten4>0){
					if (ten4%2 == 0){
						*(line1+index)='0';
					}
					else{
						*(line1+index)='1';
					}
				index++;
	     		ten4=ten4/2;
				}
				char* line3=calloc(128,sizeof(char));
				for (int i=0; i<strlen(line1); i++){
					*(line3+i)=*(line1+strlen(line1)-i-1);
				}
				strcpy(line1,line3);
				index=0;
				char* line4=calloc(128,sizeof(char));
				while (ten5>0){
					if (ten5%2 == 0){
						*(line2+index)='0';
					}
					else{
						*(line2+index)='1';
					}
					index++;
	     			ten5=ten5/2;
				}
				for (int i=0; i<strlen(line2); i++){
					*(line4+i)=*(line2+strlen(line2)-i-1);
				}
				strcpy(line2, line4);
				free(line3);
				line3=NULL;
				free(line4);
				line4=NULL;
				oct(line1,line2,sim);
			}
			if (*(line1) == '0' && *(line1+1) == 'x' && *(line2) == '0' && *(line2+1) == 'x'){
				int ten4=0;
				for (int i=2; i<strlen(line1);i++){
					if (*(line1+i) > 47 && *(line1+i)<58){
						ten4+=pow(16,strlen(line1)-i-1)*(*(line1+i)-48);
					}
					else{
						ten4+=pow(16,strlen(line1)-i-1)*(*(line1+i)-87);
					}
				}
				int ten5=0;
				for (int i=2; i<strlen(line2);i++){
					if (*(line2+i) > 47 && *(line2+i)<58){
						ten5+=pow(16,strlen(line2)-i-1)*(*(line2+i)-48);
					}
					else{
						ten5+=pow(16,strlen(line2)-i-1)*(*(line2+i)-87);
					}
				}
				int index=0;
				while (ten4>0){
					if (ten4%2 == 0){
						*(line1+index)='0';
					}
					else{
						*(line1+index)='1';
					}
					index++;
	     			ten4=ten4/2;
				}
				char* line3=calloc(128,sizeof(char));
				for (int i=0; i<strlen(line1); i++){
					*(line3+i)=*(line1+strlen(line1)-i-1);
				}
				strcpy(line1,line3);
				index=0;
				char* line4=calloc(128,sizeof(char));
				while (ten5>0){
					if (ten5%2 == 0){
						*(line2+index)='0';
					}
					else{
						*(line2+index)='1';
					}
					index++;
	     			ten5=ten5/2;
				}
				for (int i=0; i<strlen(line2); i++){
					*(line4+i)=*(line2+strlen(line2)-i-1);
				}
				strcpy(line2, line4);
				free(line3);
				line3=NULL;
				free(line4);
				line4=NULL;
				hex(line1,line2,sim);
			}	
		}
	}
}
