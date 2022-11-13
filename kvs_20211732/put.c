#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{	
	printf("put: %s, %s\n", key, value);

	node_t* cur = kvs -> db;
	node_t* new;
	int item_num = kvs -> items;

	new = (node_t*)malloc(sizeof(node_t));
	char* val = (char*)malloc(sizeof(char)*300);
	
	strcpy(new -> key, key);
        strcpy(val, value);
        new -> value = val;

	for(int i = 0; i < (item_num)-1; i++){
                cur = cur -> next;
        }

	if (item_num == 0){
		kvs -> db = new;
		kvs -> items += 1;

		return 0;
	}

	else{
		cur -> next = new;
		kvs -> items += 1;

		return 0;
	}
}
