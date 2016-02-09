/* Brian Lin bjlin Due:4/4/14 */
/* Simple decToBinary program implementing the intStack module. */

#include "myinclude.h"
#include "intstack.h"

int main () {
    /* create an empty stack */
    StackHndl theStack = NewStack();
    int theInt;
    
    /* ask for input */
    printf("Input a non-negative decimal integer to convert to binary:\n> ");
    
    /* scan the number, return failure if nothing in inputed or negative value */
    /* program will register any input with letters or symbols in it as 32767*/
    if(scanf("%d", &theInt) == EOF){
        printf("Error reading input.\n");
        return 1;
    }
    if(theInt < 0){
        printf("Number is negative or too big.\n");
        return 1;
    }
    printf("Decimal %d is ", theInt);
    
    /* if the number is 0, then push a 0 onto the stack */
    if(theInt == 0) Push(theStack, 0);
    
    /* while the number is positive,
     * if the number is odd, push a 1 onto the stack
     * else push a 0 onto the stack
     * set the number to the number divided by 2 (rounded down)
     */
    while(theInt > 0){
        if(theInt % 2 == 1) Push(theStack, 1);
        else Push(theStack, 0);
        theInt /= 2;
    }
    /* while the stack is not empty
     * print the top number on the stack,
     * and pop it off the stack
     */
    while(!IsEmpty(theStack)){
        printf("%d", Top(theStack));
        Pop(theStack);
    }
    printf(" in binary.\n");
    
    /* free the stack */
    FreeStack(&theStack);
    
    /* return success */
    return 0;
}
