#include "kvs.h"

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	FILE *fp = fopen("student.dat", "r");
	char key[100];
	char* value = (char*)malloc(sizeof(char)*300);
	printf("Put operation ...\n");
	while(1){
		fscanf(fp, "%s %s", key, value);
		
		if(feof(fp))
			break;
		
		put(kvs, key, value);
	}
	fclose(fp);

	// 2) put data 

	char key2[100];
        char* value2 = (char*)malloc(sizeof(char)*300);
        char* rvalue = (char*)malloc(sizeof(char)*300);
 
	// 3. get for test 

	// 1) file read 
	// 2) get & compare return value with original vallue
	
	FILE *fp2 = fopen("student.dat", "r");
	
	printf("\nGet operation ...\n");
	while(1){
		fscanf(fp2, "%s %s", key2, value2);
	
		if(feof(fp))
                        break;

		if(!(rvalue = get(kvs, key2))){
			printf("Failed to get data\n");
			exit(-1);
		}
		printf("get: %s, %s\n", key2, rvalue);
	}

	fclose(fp2);


	// 4. print all items 
	printf("\nseek operation ...\n");

	for (int i = 0; i < 5; i++){
		seek(kvs); 
	}

	close(kvs);

	return 0;

}
