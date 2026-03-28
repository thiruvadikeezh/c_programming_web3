#include <stdio.h>



int main(){
	FILE *fptr;
	

	fptr = fopen("mydata.txt", "w");
	if(fptr == NULL){
		printf("error openeing file!!!!!\n");
		return 1;
	}
	
	fprintf(fptr, "hello this is saved  to in file;\n");
	fprintf(fptr, "My Age is %d\n", 24);
	fclose(fptr);


	fptr = fopen("mydata.txt", "r");
	if(fptr == NULL){
		printf("error opening the file !!!!!!\n");
	}
	
	char line[256];
	
	while(fgets(line, 100, fptr) != NULL){
		printf("%s\n", line);
	}
	fclose(fptr);

	return 0;
}
			
