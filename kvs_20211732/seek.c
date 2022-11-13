#include "kvs.h"

int seek(kvs_t* kvs)
{
	
	node_t* tmp = kvs -> db;
	node_t* nex = NULL;
	node_t* pre = kvs -> db;

	int num = 0;

	if(kvs -> items > 2){
		nex = tmp -> next;

		for(int i = 0; i < (kvs -> items)-1; i++){
			if(strcmp(tmp -> key, nex -> key) > 0){
				tmp = nex;
				num = i;

			}
			nex = nex -> next;
		}

		if (num == 0){
			kvs -> db = tmp -> next;
		}
	
		else{
			for(int j = 0; j < num; j++){
				pre = pre -> next;
			}
			pre -> next = tmp -> next;
		}
	}

	else if(kvs -> items == 2){
		nex = tmp -> next;
		if(strcmp(tmp -> key, nex -> key) > 0){
			tmp = nex;
			
			pre = kvs -> db;
			pre -> next = NULL;
		}
	}

	else{
		tmp = kvs -> db;
	}
	
	printf("(%s, %s)\n", tmp -> key, tmp -> value);

	kvs -> items -= 1;

	return 0;
}
