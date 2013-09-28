#include <stdio.h>
#include <stdlib.h>


#define HOSTS_FILE "/etc/hosts"
#define BUFFER_SIZE 512
typedef unsigned char BYTE;


int main(){
	FILE *fd;
	BYTE buffer[BUFFER_SIZE]={0};

	fd=fopen(HOSTS_FILE, "r");
	
	if(fd==NULL){
		fprintf(stderr, "Cannot open file.\n");
		return EXIT_FAILURE;
	}
	if(fread(buffer, 1, 9, fd)==9){
		printf("The first 9 character i read is %s\n", buffer);
	}

	/*Add a hostname*/
	printf("Enter an ip:");
	scanf("%s", buffer);

	int len=strlen(buffer);
	buffer[len]=' ';

	printf("Enter a hostname:");
	scanf("%s", buffer+len+1);

	fclose(fd);

	/*Write back to the host file*/

	fd=fopen(HOSTS_FILE, "a");
	if(fd==NULL){
		fprintf(stderr, "Cannot open the file.\n");
		return EXIT_SUCCESS;
	}
	fprintf(fd, "%s\n",buffer);

	fclose(fd);
	
	return EXIT_SUCCESS;
}
