#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	//char filename[100];       //holds file name(s)
	char *linecontent = " "; //buffer for line text
	
	//char delim[] = " ";       //delim to seperate filenames
	//char searchterm[100];     //holds the substring to search within each line
	
	/*
	printf("\nenter filename:	");
	printf("\n");
	scanf("%[^\n]%*c", filename);//scanset character takes input until 
	                             //newline doesnt get encountered 
	printf("you entered the following filenames:  %s", filename);
	
	
	
	printf("\n\nenter search term:	");
	printf("\n");
	scanf("%[^\n]%*c", searchterm);
	printf("you entered the following search term:  %s", searchterm);
	
	*/
	
	
	//char *fileptr = strtok(filename, delim);
	//printf("filepointer test: %s", fileptr);
	
	for(int x = 2; x < argc - 2; x++){ //x=0 program name x=1 search term x>=2 filename 
		
		int linecount = 0;
		size_t len = 0;
		FILE *fp;
		//int tempmatch = 0;
		
		
		//while(fgets(filecontent, 100, fp) != NULL){
		//	printf(" %s", filecontent);
		//}
		while(linecontent != NULL){
			if(argc < 3){
				x= argc;
				getline(&linecontent, &len, stdin);
			}
			else{
				fp = fopen(argv[x], "r");
				getline(&linecontent, &len, fp);
				if(fp == NULL){
					printf("wgrep cannot open file \n");
					exit(1);
				}
			}
			
			printf("linecontent check: %s", linecontent);
			linecount++;
			printf("LINE %d",linecount);
			if(strstr(linecontent, argv[1])!= NULL){
				printf("LINE %d: %s",linecount, linecontent);
			}
			/* 
			for(int i = 0; i < len; i++){
				if(linecontent[i] == searchterm[0]){
					tempmatch = 1;
					for(int s = 1; s < strlen(searchterm); s++){
					 	if(linecontent[i+s] != searchterm[s]){
					 		tempmatch = 0;
					 		break;
					 	}
					}		
				}
				if(tempmatch == 1){
				printf("LINE %d: %s",linecount, linecontent);
				tempmatch = 0;
				break;
				}
			}
			*/
			
			free(linecontent);
			linecontent = NULL;
			if(argc > 2){
				fclose(fp);
			}
			printf("\n THE END2");

		}
		printf("\n THE END1");
		//fileptr = strtok(NULL, delim);
	}
	printf("\n THE END");

	exit(0);
	return 0;
}
