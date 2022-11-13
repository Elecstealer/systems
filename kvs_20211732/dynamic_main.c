#include "kvs.h"
#include <dlfcn.h>

int main(){
	void *handle;
	char *error;
	kvs_t* (*open)();
	int (*put)(kvs_t*, const char*, const char*);
	char* (*get)(kvs_t*, const char*);
	int (*seek)(kvs_t*);
	int (*close)(kvs_t*);
	
	handle = dlopen("./libkvs.so", RTLD_LAZY);
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	open = (kvs_t*(*)()) dlsym(handle, "open");
	put = (int(*)(kvs_t*, const char*, const char*)) dlsym(handle, "put");
	get = (char*(*)(kvs_t*, const char*)) dlsym(handle, "get");
	seek = (int(*)(kvs_t*)) dlsym(handle, "seek");
	close = (int(*)(kvs_t*)) dlsym(handle, "close");

	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());
                exit(1);
	}

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

	char key2[100];
        char* value2 = (char*)malloc(sizeof(char)*300);
        char* rvalue;

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

        printf("\nseek operation ...\n");

        for (int i = 0; i < 5; i++){
                seek(kvs);
        }

        close(kvs);

	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

        return 0;

}

