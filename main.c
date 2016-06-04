#include "ds.h"
#include <stdio.h>
#include <string.h>

# ifdef sun
# define const
# endif

void test_tree(int, char **);

extern const char *
okfail(int val)
{
    return val ? "[ OK ]" : "[FAIL]";
}

int main(int argc, char *argv[])
{
    int i;
    char input[13][3];
    
    printf("Homework #4 -ShinYunseob- ID: 2013313064\n");
    printf("\n");
    printf("Input data : \n");
    
    fflush(stdin);
    for (i=0; i<13; i++) {
        if(i>0) puts(input[i-1]);
        scanf("%s", input[i]);
        if(strlen(input[i]) < 2) {
            char t1[3] = {'0'};
            strncat(t1, input[i], 1);
            strcpy(input[i], t1);
        }
    }
    
    AVLTREE 	tree;
    tree = avlMake();
    traversal(tree, 13, input);
    deleteNode(tree);
    return 0;
}

static void
printfunc(void *data)
{
    printf("user-data: %s\n",(const char*)data);
}

void test_tree(int n, char **A)
{
    AVLTREE 	tree;
    char *	s;
    
    tree = avlMake();
    
    while (n--)
        avlAdd(tree,A[n],(void*)A[n]);
    
    printf(" Number of nodes: %d\n",avlTotalNodes(tree));
    printf(" Tree height: %d\n",avlHeight(tree));
    
    for (s = avlFirst(tree); s; s = avlNext(tree))
    {
        printf("s = %s (%s)\n",s,okfail(s==avlCurrent(tree)));
    }
    printf("Current should now be NULL: %s\n",okfail(avlCurrent(tree)==NULL));
    
    printf("avlLast() returns %s\n",(char*)avlLast(tree));
    printf("===============\n");
    printf("setting current to %s\n",A[0]);
    avlSetCurrent(tree,A[0]);
    printf("avlNext() returns %s\n",(char*)avlNext(tree));
    printf("Current is now %s\n",(char*)avlCurrent(tree));
    
    printf("Clearing current.\n");
    avlClearCurrent(tree);
    printf("avlCurrent returns %s\n",(char*)avlCurrent(tree));
    printf("avlPrev() returns %s\n",(char*)avlPrev(tree));
    printf("avlNext() returns %s\n",(char*)avlNext(tree));
    printf("avlLast() returns %s\n",(char*)avlLast(tree));
    printf("avlPrev() returns %s\n",(char*)avlPrev(tree));
    printf("avlFirst() returns %s\n",(char*)avlFirst(tree));
    printf("avlCurrent() returns %s\n",(char*)avlCurrent(tree));
    printf("avlPrev() returns %s\n",(char*)avlPrev(tree));
    printf("avlCurrent() returns %s\n",(char*)avlCurrent(tree));
    printf("avlNext() returns %s\n",(char*)avlNext(tree));
    
    printf("+---- avlWalkAscending() ----+\n");
    avlWalkAscending(tree,printfunc);
    printf("+---- avlWalkDescending() ----+\n");
    avlWalkDescending(tree,printfunc);
    printf("+---- avlWalk() ----+\n");
    printf("pre-order:\n");
    avlWalk(tree,printfunc,AVLPreWalk);
    printf("in-order:\n");
    avlWalk(tree,printfunc,AVLInWalk);
    printf("post-order:\n");
    avlWalk(tree,printfunc,AVLPostWalk);
    
    printf("+---- avlCloseWithFunction() ----+\n");
    avlCloseWithFunction(tree,printfunc);
    
}