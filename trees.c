#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "scanner.h"
#include "tree.h"
#include "Fatal.h"
#include "avl.h"
#include "bst.h"

bool AVL;

int ProcessOptions(int argc, char **argv);
tree *processCorpus(FILE *fp);
//void processCommands(FILE *fp);

int main(int argc,char **argv){
    int argIndex;
    argIndex = ProcessOptions(argc,argv);
    FILE *corpus = NULL;
    FILE *commands = NULL;
    if (argIndex == 1){
        Fatal("no option specified\n");
    }
    else {
        corpus = fopen(argv[argIndex], "r");
        commands = fopen(argv[argIndex+1], "r");
    }
    tree *t = processCorpus(corpus);
    printLevelOrder(t,stdout);
    //processCommands(commands,t);
    if(corpus != NULL)
        fclose(corpus);
    if(commands != NULL)
        fclose(commands);
    return 0;
}

/* only -oXXX  or -o XXX options */

int
ProcessOptions(int argc, char **argv)
{
    int argIndex;
    int argUsed;
    int separateArg;

    argIndex = 1;

    while (argIndex < argc && *argv[argIndex] == '-')
        {
        /* check if stdin, represented by "-" is an argument */
        /* if so, the end of options has been reached */
        if (argv[argIndex][1] == '\0') return argIndex;

        separateArg = 0;
        argUsed = 0;

        if (argv[argIndex][2] == '\0')
            {
            separateArg = 1;
            }

        switch (argv[argIndex][1])
            {
            case 'a':
                AVL = true;
                break;
            case 'b':
                AVL = false;
                break;
            default:
                Fatal("option %s not understood\n",argv[argIndex]);
            }

        if (separateArg && argUsed)
            ++argIndex;

        ++argIndex;
        }
    return argIndex;
}
char *strip(char *token){
    int i,j = 0;
    for(i = 0;i < strlen(token);++i){
        if(islower(token[i])){
            token[j] = token[i];
            j++;
        }
        else if(isupper(token[i])){
            token[j] = tolower(token[i]);
            j++;
        }
    }
    token[j] = '\0';
    return token;
}
char *compress(char *token){
    int i,j = 0;
    for(i = 0;i < strlen(token);++i){
        if(isspace(token[i])){
            token[j] = ' ';
            j++;
            while(isspace(token[i]))
                i++;
            i--;
        }
        else if(isalpha(token[i])){
            if(islower(token[i])){
                token[j] = token[i];
                j++;
            }
            else if(isupper(token[i])){
                token[j] = tolower(token[i]);
                j++;
            }
        }
    }
    token[j] = '\0';
    return token;
}
tree *processCorpus(FILE *fp){
    char *token = NULL;
    tree *t = newTree();
    node *n = NULL;
    if (stringPending(fp))
        token = compress(readString(fp));
    else
        token = strip(readToken(fp));
    while(token != NULL){
        if(token != NULL){
            token = compress(token);
            n = newTreeNode(token);
            if (n == NULL) Fatal("n is NULL!!\n");
            if(AVL)
                avlInsert(t,n);
            else
                bstInsert(t,n);
        }
        if(stringPending(fp))
            token = readString(fp);
        else
            token = readToken(fp);
    }
    return t;
}
