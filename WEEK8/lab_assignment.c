#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isCorrect = 1;

struct Node{
	char name[256];
	struct Node *next;
};


void append(struct Node **head, char *input)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    strcpy(new_node->name, input);
    new_node->next = NULL;

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printList(struct Node* iter)
{
	printf("\nqueue: ");
	while(iter != NULL)
	{
		printf("%s ",iter->name);
		iter = iter->next;
		if(iter != NULL)
			printf(", ");
	}
	printf("\n");

}

void admit(struct Node **head)
{
	struct Node* next_node = NULL;

	if(*head == NULL)
	{
		printf("There is no one left\n");
		return;
	}

	next_node = (*head)->next;
	free(*head);
	*head = next_node;

	return;
}

void delete_specific(struct Node **head, char *input)
{

	struct Node *temp_node = *head, *prev;


	if (temp_node != NULL && strcmp(temp_node->name, input) == 0)
	{ 
        *head = temp_node->next;  
        free(temp_node);              
        return;
	}
	else
	{
		while(temp_node != NULL && strcmp(temp_node->name, input) != 0) 
		{ 
        	prev = temp_node; 
        	temp_node = temp_node->next; 
    	} 
    	if (temp_node == NULL)
		{ 
        	printf("Type a correct name!\n");
			isCorrect = 0;
        	return; 
    	}
    	prev->next = temp_node->next; 
    	free(temp_node); 
	}
}


void free_memory(struct Node *head) //frees the allocated memory
{
    while(head != NULL)
    {   
        free(head);
        head = head->next;
    }   
}



int main()
{
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));
	
	strcpy(head->name, "Elcan");
	
	head -> next = NULL;
 	
	append(&head, "Kamran");
 	append(&head, "Eli");
	append(&head, "Turqut");
	append(&head, "Nigar");

	printList(head);	
	printf("\n");

	char input[256];
	bool quit = 0;
	
	while(!quit)
	{
		printf("Enter a command: ");
  		scanf( "%s" , input);
  		if (strcmp(input,"quit") == 0)
  		{
		 printList(head);
   		 quit = 1;
		 free_memory(head); //before quitting, we free the allocated memory

  		}
  		else if (strcmp(input,"admit") == 0)
 		{
		 	admit(&head);
			printList(head);
			printf("\n");
		}
		else
		{
        	delete_specific(&head, input);
        	if(isCorrect)
			{
				append(&head, input);	
	   		}
			isCorrect = 1;
			printList(head);
			printf("\n");
	    }	
	
	}
	return 0;
}
    
