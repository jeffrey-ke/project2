#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "set.h"

int main(int argc, char *argv[]) {
    return 1;
    
}

struct set{
    int count;
    int length;
    char* data;
};

SET *createSet(int maxElts){
    struct SET sp*;
    sp = malloc(sizeof(struct SET));
    sp->count = 0;
    sp->length = maxElts;
    sp->data = malloc(sizeof(char*) * maxElts);
    assert(sp->data != NULL);
    return sp;
}

void destroySet(SET *sp){
    int i;
    assert(sp != NULL);

    for(i = 0; i < sp->count; i++){
        free(sp->data[i]);
    }
    free(sp->data);
    free(sp);
}

int numElements(SET *sp){
    assert(sp != NULL);
    return sp->count;
}

void addElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    assert(sp->count < sp->length);
    if(search(sp, elt) == -1){
        char *new = strdup(elt);
        assert(new != NULL);
        sp->data[count] = new;
        sp->data++;
    }
}

static int search(struct SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    int i;
    for(i = 0; i < sp->count; i++){
        if(strcmp(sp->data[i], elt) == 0){
            return i;
        }
    }
    return -1;
}

void removeElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    int locn = search(sp, elt)
    if(locn != -1){
        sp->data[locn] = sp->data[sp->count];
        free(sp->data[sp->count]);
        sp->count--;
    }
    

}

char *findElement(SET *sp, char *elt){
    assert(sp != NULL && elt != NULL);
    int locn = search(sp, elt);
    return (locn != -1)? sp->data[locn] : NULL;
}

char **getElements(SET *sp){
    //returning the array of pointers to strings
    assert(sp != NULL);
    char** _query;
    _query = malloc(sizeof(char*) * sp->count);
    assert(_query != NULL);
    memcpy(_query, sp->data, sizeof(char*) * sp->count);
    return _query;

}
