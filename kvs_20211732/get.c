#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
	/* do program here */

	char* value = (char*)malloc(sizeof(char)*100);

	node_t *cur = kvs -> db;

	if(strcmp(cur -> key, key) == 0){
                value = cur -> value;

		return value;
        }

	for(int i = 0; i < (kvs -> items)-1; i++){
		cur = cur -> next;

		if(strcmp(cur -> key, key) == 0){
                       	value = cur -> value;

			return value;
                }

	}

	

	if(!value){
		printf("Failed to malloc\n");
		return NULL;
	}
	
	strcpy(value, "deadbeaf");
	return value;

}
