#include <iostream>
#include <malloc.h>
using namespace std; 
typedef int ElementType;             
typedef struct bitnode{	
    ElementType data;	
    struct bitnode *left, *right;
} bitnode, *bitree;      

bitree PerCreateTree(){	
    bitree T; 	
    ElementType item;	
    cin >> item;	
    if( item == 0 ) T = NULL;  
    else{		
        T = (bitree)malloc(sizeof(bitnode));		
        T->data = item;				
        T->left = PerCreateTree();            	
        T->right = PerCreateTree();           
    } 		
    return T;                         
} 

void PerOrder(bitree T){	
    if(T){
        cout << T->data << " ";		
        PerOrder(T->left);            
        PerOrder(T->right);          
    }
} 

void InOrder(bitree T){
    if(T){
        InOrder(T->left);
        cout<<T->data<<" ";
        InOrder(T->right);
    }
}

void PostOrder(bitree T){
    if(T){
        PostOrder(T->left);
        PostOrder(T->right);
        cout<<T->data<<" ";
    }
}

int leaf(bitree T){
    if(!T) return 0;
    else if((!T->left)&&(!T->right)) return 1;
    else return (leaf(T->left)+leaf(T->right));
}

int deep(bitree T){
    if(T==NULL) return 0;
    else{
        int m=deep(T->left);
        int n=deep(T->right);
        return (m>n)?m+1:n+1;
    }
}

bitree FreeTree(bitree T){
	if(T){		
        FreeTree(T->left);         
        FreeTree(T->right);          
        free(T);            
        T = NULL;        
    }		
    return T;          
}  

int main(){	
    bitree root;		
    cout << "Please put in the data:";	
    root = PerCreateTree();

    cout << "The Per_tree is: "; 	
    PerOrder(root);            
    cout << endl;
    
    cout<<"The In_tree is: ";
    InOrder(root);
    cout<<endl;

    cout<<"The Post_tree is: ";
    PostOrder(root);
    cout<<endl;

    cout<<"The number of leaves is: "<<leaf(root)<<endl;

    cout<<"The deep of tree is: "<<deep(root)<<endl;
    
    return 0;
}
