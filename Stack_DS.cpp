
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
class Stack
{
public:
    int top;
    unsigned capacity;
    char *array;
};

// function to create a stack of given
Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new char[(stack->capacity * sizeof(char))];
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(Stack *stack) { return stack->top == -1; }

// Function to add an item to stack.
void push(Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// A stack based function to reverse a string
void reverse(char str[])
{
    // Create a stack of capacity
    // equal to length of string
    int n = strlen(str);
    Stack *stack = createStack(n);

    // Push all characters of string to stack
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);

    // Pop all characters of string and
    // put them back to str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

// Driver code
int main()
{
    char str[] = "sasta nahi sabse accha ";

    reverse(str);
    cout << "Reversed string is " << str;

    return 0;
}

// This code is contributed by rathbhupendra
