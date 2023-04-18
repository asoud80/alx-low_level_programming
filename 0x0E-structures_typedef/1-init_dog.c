#include "DOG.h"

/**
 * init_dog - initialize a variable of type struct dog
 *@d: array
 *@name: name
 *@age: age
 *@owner: owner
 *
 * Return: always 0.
 * Description: Initialize the strycture of a dog
 */

void init_dog(struct dog *d, char *name, float age, char *owneri)

{
	if (d)
	{
	d->name = name;
	d->age = age;
	d->owner = owner;
	}
}
