#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to a type
 * @old_size: the initial size of the memory location
 * @new_size: the size of the new memory allocation
 *
 * Return: nothing
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *np;
	unsigned int i;
	char *pt = (char *)ptr;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		np = malloc(new_size);
		return (np);
	}
	if (new_size == old_size)
		return (ptr);

	np = malloc(new_size);

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
		{
			*(np + i) = pt[i];
		}
	}
	else
	{
		for (i = 0; i < old_size; i++)
		{
			*(np + i) = pt[i];
		}
	}
	return (np);
}
