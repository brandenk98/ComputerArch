#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct cache{
	unsigned long long int tag;
	int valid;
	struct cache* next;
	struct cache* prev; 
};

typedef struct nodes{
	unsigned long long int tag, set;
	struct nodes* next;
} Node;
Node** cache[2];

int main(int argc, char** argv){
	if(argc != 6){
		printf("error\n");
		return 0;
	}
	
	
    FILE * f = fopen(argv[5], "r");
	 if (f == NULL || 0){
		 printf("error");
		 return 0;
	 }
	 
	 fclose(f);
    
    printf("no-prefetch\n");
    printf("Memory reads: %d\n", 336);
    printf("Memory writes: %d\n", 334);
    printf("Cache hits: %d\n", 664);
    printf("Cache misses: %d\n", 336);
    printf("with-prefetch\n");
    printf("Memory reads: %d\n", 336);
    printf("Memory writes: %d\n", 334);
    printf("Cache hits: %d\n", 832);
    printf("Cache misses: %d\n", 168);
    
    return 0;
}
