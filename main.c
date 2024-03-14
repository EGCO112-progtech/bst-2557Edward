#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main( int argc, char** argv )
{ 
   unsigned int i; 
   int item; 
   BST b;

   
	b.root= NULL;  b.size=0;
   for ( i = 1; i < argc; ++i ) { 
      // insertNode( &b, atoi(argv[i]));
      insertNode_R(&b.root,atoi(argv[i]) );
   } 

   
   printf("\npreOrder\n" );
   preOrder( b.root );
   printf("\npostOrder\n" );
   postOrder( b.root);
   printf("\ninOrder\n" );
   inOrder( b.root );
   printf("\n");
   Lap_print( b.root, 0);
   printf("\n");

} 

