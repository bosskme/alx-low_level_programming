#include <stdlib.h>
#include "dog.h"

/**
 * new_dog     - Create a new dog variable
 * @name:        Name of the dog
 * @age:         Age of the dog
 * @owner:       Owner of the dog
 * Return:       Pointer to new dog variable
 */

dog_t *new_dog(char *name, float age, char *owner) {
    dog_t *d = malloc(sizeof(dog_t));
    if (d == NULL) {
        return NULL;
    }
    d->name = malloc(strlen(name) + 1);
    if (d->name == NULL) {
        free(d);
        return NULL;
    }

 /**
 * strcpy  -   Make a copy of passed in argument
 * @d->name:      Data to make copy of
 * @name: name of the data to copy
 * Return:    Pointer
 */

 strcpy(d->name, name);
    d->age = age;
    d->owner = malloc(strlen(owner) + 1);
    if (d->owner == NULL) {
        free(d->name);
        free(d);
        return NULL;
    }
    strcpy(d->owner, owner);
    return d;
}
