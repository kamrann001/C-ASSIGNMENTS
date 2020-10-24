#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define STACK_CAPACITY 2 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack() 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = STACK_CAPACITY; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

int* newrealloc(int* ptr, size_t size)
{
	int* new;
	if(sizeof(ptr) < size)	
	{
		new = malloc(size);
		memcpy(new, ptr, sizeof(ptr)); //copies the contents of pointer to the new one
		free(ptr);					   //and frees the old unused dynamic memory
	}
	else new = ptr;
	return new;
}

void divide_memory(struct Stack* stack)
{
	stack->capacity /= 2;
	stack->array = (int*)newrealloc(stack->array, stack->capacity); //here we use newrealloc function istead of built-in relloc() function to shrink the memory by half
	printf("stack reallocated, new size: %d\n",stack->capacity);
}

void sizeCheck(struct Stack* stack)
{
	if((stack->capacity)*0.25 >= stack->top) //divides the memory by half if only the quarter of capcity is full
		divide_memory(stack);	
}



// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack) 
{ 
    free(stack->array);
    free(stack);
    printf("deallocated\n"); 
} 

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 

void resize(struct Stack* stack) 
{
    stack->capacity *= 2;
    stack->array = (int*)newrealloc(stack->array,stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n",stack->capacity);
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        resize(stack);
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    sizeCheck(stack);
	return stack->array[stack->top--]; 
} 
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
  
int main() 
{ 
    struct Stack* stack = createStack(); 
  
	push(stack, 10); 
	push(stack, 20); 
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	push(stack, 60);
	push(stack, 70);
	push(stack, 80);
	push(stack, 90);	
	for(int i =0; i<7; i++)
		pop(stack);

	sizeCheck(stack);
	printf("%d popped from stack\n", pop(stack)); 

	deallocStack(stack);
	return 0; 
} 
