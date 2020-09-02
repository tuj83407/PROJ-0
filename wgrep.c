#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
		printf("argc:%d \n", argc);
		if(argc == 1){
			printf("wgrep: searchterm [file...] \n");
			exit(1);
		}

		//printf("for loop check:\n");
		int linecount = 0;
		printf("line 14 check");
		FILE *fp;
		
		//int tempmatch = 0;
		//while(fgets(filecontent, 100, fp) != NULL){
		//	printf(" %s", filecontent);
		//}
		
		
		
			
			//printf("while loop check 45");
		if(argc == 2){
			printf("argc:2");
			char *linecontent = "x";
			size_t len = 0;
			while(linecontent != NULL){
				getline(&linecontent, &len, stdin);
				linecount++;
				//printf("linecontent check: %s",linecontent);
				//printf("LINE %d",linecount);
				if(strstr(linecontent, argv[1])!= NULL){
					printf("LINE %d: %s",linecount, linecontent);
				}
				fclose(stdin);
			}
		}
		
		if(argc > 2){
		
			printf("argc>2");
			for(int e = 2; e <= argc ; e++){ //x=0 program name x=1 search term x>=2 filename 
				printf("argc>2 check");
				int charcount = 1;
				char tempchar = 'x';
				char *linecontent = "x";
				fp = fopen(argv[e], "r");
				while(linecontent != NULL){
					
					tempchar = fgetc(fp);
					while(tempchar != '\n'){
						charcount++;
						tempchar = fgetc(fp);
					} 
					char linecontent[charcount+10];
					fgets(linecontent, charcount, fp);
					if(fp == NULL){
						printf("wgrep cannot open file \n");
						exit(1);
					}
					linecount++;
					if(strstr(linecontent, argv[1])!= NULL){
						printf("LINE %d: %s",linecount, linecontent);
						break;
					}
					//realloc(linecontent, 1);
				}
				if(argc > 2){
				fclose(fp);
				}
			}	
		}
	exit(0);
	return 0;	
			/*
			//printf("linecontent check: %s", linecontent);
			linecount++;
			//printf("LINE %d",linecount);
			if(strstr(linecontent, argv[1])!= NULL){
				printf("LINE %d: %s",linecount, linecontent);
			}
			*/
	
			
			//free(linecontent);
			//linecontent = "x";

}
