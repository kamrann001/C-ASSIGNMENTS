#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct StackNode {
  char data;
  struct StackNode* next;
};

// a function that returns a pointer to dynamically created stacknode
struct StackNode* newNode(char data) {
  struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

int isEmpty(struct StackNode* root) {
  return !root;
}

void push(struct StackNode** root, char data) {
  struct StackNode* stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
}

char pop(struct StackNode** root) {
  if (isEmpty(*root)) return ' ';
  struct StackNode* temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);
  return popped;
}

char peek(struct StackNode* root) {
  if (isEmpty(root)) {
    return ' ';
  }
  return root->data;
}

int length(char *array) {
	int i = 0;
  while (array[i]) i++;
  return i;
}

int isItBalanced(char *expr) {
  struct StackNode* stack = NULL;
  // if the length of expression is odd number it cannot be balanced
  if (length(expr)%2) return 0;

  int i = 0;
  while(expr[i]) {
    char current = expr[i];  // current bracket in expression
    // pushing only if it is the opening bracket
    if (current == '(' || current == '[' || current == '{') push(&stack, current);
    else {
      char last = peek(stack); // last bracked in expression
      if (stack == NULL) return 0;
      if (
        current == ')' && last == '(' ||
        current == '}' && last == '{' ||
        current == ']' && last == '[') pop(&stack);

      else {
        return 0;
      }
    }
    i++;
  }
  return 1;
}

int main(int argc, char **argv) {
  printf(isItBalanced(argv[1])?"Yes\n":"No\n");
}
