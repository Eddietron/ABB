#include <stdio.h>
#include <stdlib.h>

char* getString(){
    fflush( stdin );
	char* r = NULL;
	char key = getchar();
    int i = 0;
    
	if(key != 10 ){
		r = (char*)malloc(sizeof(char));
		*r = key;
        i++;
		while(1){
			key = getchar();
			if(key == 10 ){
                r = (char*)realloc(r, sizeof(char));
                r[i] = '\0';
                
				return r;
			}
			r = (char*)realloc(r, sizeof(char));
			r[i] = key;
			i++;
		}
	}else{
		return NULL;
	}
}

int getValor(char* s){
    int total = 0;
    int i = 0;
    while ( s[i] != '\0'){
        total += (int)(s[i]);
        i++;
    }
    return total;
}

int len(const char * s){
    return (*s) ? (1 + len(s+1)) : 0;
}

int equals(char* s1, char* s2){
    int l1 = len(s1);
    int l2 = len(s2);
    int i = 0;
    if(l1 == l2){
        for(;i<l1;i++){
            if(s1[i] != s2[i])
                return 0;
        }
        return 1;
    }
    return 0;
}

