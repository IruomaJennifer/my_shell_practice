#include "shell.h"


list_dir *link_dir(char **tokens)
{
	list_dir *head, *temp, *next;
	int i  = 1;

	head = malloc(sizeof(list_dir));
	head->dir = tokens[0];
	temp = head;

	while (tokens[i])
	{
		next = malloc(sizeof(list_dir));
		next->dir = tokens[i];
		temp->next = next;
		temp = next;
		i++;
	}
	temp->next = NULL;
	return (head);
}

