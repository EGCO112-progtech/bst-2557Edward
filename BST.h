struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

void insertNode_R(TreeNodePtr * ,int );

void insertNode_R(TreeNodePtr * t,int value){
   if((*t) == NULL){
      (*t) = (TreeNodePtr)malloc(sizeof(struct TreeNode));
   
      if((*t)){
         (*t)->leftPtr=NULL;
         (*t)->rightPtr=NULL;
         (*t)->data=value;
      }
   }

   else{
      if((*t)->data>=value) { //left
         insertNode_R(&((*t)->leftPtr), value);
      }
      else { //right 
         insertNode_R(&((*t)->rightPtr), value);
      }

   }
}

void insertNode( BST *b, int value ){
	TreeNodePtr t = b->root,new_node;
	int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		
		if(!b->root) {
         b->root=new_node;
      }
      else {
         while(!inserted){
            if(t->data >=value) {
               
               if (t->leftPtr == NULL) {
                  t->leftPtr = new_node;
                  inserted = 1;
               }
               t = t->leftPtr;

            }
            else{
               
               
               if (t->rightPtr == NULL) {
                  t->rightPtr = new_node;
                  inserted = 1;
               }
               t = t->rightPtr;

            }
         }		
      }
   b->size++;
   }
}

void inOrder( TreeNodePtr treePtr )
{ 
   
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); 
 
      printf("%3d",treePtr->data) ;  
   
      inOrder( treePtr->rightPtr ); 
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr )
{ 
   
   if ( treePtr != NULL ) {        
        
      printf("%3d",treePtr->data) ;  

      preOrder( treePtr->leftPtr ); 
   
      preOrder( treePtr->rightPtr ); 
   } // end if                          
} // end 

void postOrder( TreeNodePtr treePtr )
{ 
   
   if ( treePtr != NULL ) {        

      postOrder( treePtr->leftPtr ); 
   
      postOrder( treePtr->rightPtr ); 
   
      printf("%3d",treePtr->data) ;  
   } // end if                          
} // end 

void Lap_print( TreeNodePtr treePtr, int n )
{ 
  
   if ( treePtr != NULL ) {        
        
      Lap_print( treePtr->rightPtr, n+1 ); 

      for (int i = 0; i < n; i++) {
         printf("   ");
      }
      printf("%3d\n",treePtr->data) ;  
   
      Lap_print( treePtr->leftPtr, n+1 ); 
   } // end if                          
} 