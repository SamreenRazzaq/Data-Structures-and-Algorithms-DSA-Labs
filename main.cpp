//
//  main.cpp
//  BST
//
//  Created by Hina Khalid  on 17/06/2020.
//  Updated on 28/03/2022
//  Copyright © 2022 Hina Khalid . All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/////////////////BST

class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
};


class BST
{
    
public:
    
    treeNode * root;
    
    BST()
    {
        root=NULL;
    }
    
    ////////// Inorder Traversal
    
    void InorderTraverse(treeNode *t )
    {
        if (t!=NULL)
        {
            InorderTraverse(t->left);
            cout<<t->data<<" ";
            InorderTraverse(t->right);
        }
    }
    
    ////////// Postorder Traversal
    
    void PostorderTraverse(treeNode *t )
    {
 	 if(t!=NULL)
 	 PostorderTraverse(t->left);
 	 PostorderTraverse(t->right);
 	 cout<<t->data<<endl;
    }
    
    ////////// Preorder Traversal
    
    void PreorderTraverse(treeNode *t)
    {
        if(t!=NULL)
        cout<<t->data<<endl;
        PreorderTraverse(t->left);
        PreorderTraverse(t->right);
    }
    
    ////////// Insert in Tree
    
    void insert( string m)
    {
        treeNode *z=new treeNode();
        z->data=m;
        z->left=NULL;
        z->right=NULL;
        
        treeNode *y=NULL;
        treeNode *x=root;
        
        while(x!=NULL)
        {
            
            y=x;
            if(x->data.compare(z->data)>0)
                x=x->left;
            else
                x=x->right;
            
        }
        
        z->parent=y;
        if(root==NULL)
            root=z;
        else if(y->data.compare(z->data)<0)
            y->right=z;
        else
            y->left=z;
    }
    
    ////////// Min Tree
    
    string TreeMin(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        if(x->left !=NULL)
            x=x->left;
        return x->data;
    }
    
    ////////// Max Tree

    string TreeMax(treeNode* x=NULL)
    {
 		if(x==NULL)
 			x=root;
 		if(x->right!=NULL)
 			x=x->right;
        return x->data;
    }
    
    /////////// Tree Search
    
    treeNode* search(string s)
    {
     treeNode*t=root;
	 while(t!=NULL){
	 	if(t->data==s){
	 		cout<<t->data<<"";
		 }
		if(t->data>s){
         t=t->left;}
        else{
         t=t->right;
    }
}
	cout<<"DATA NOT FOUND"<<"";
}
//    ////////// Predecessor of x
//    
//    
//    treeNode* Predecessor(string x)
//    {
//        treeNode * c=search(x);
//        if(c->left!=NULL)
//        {
//            string val=TreeMax(c->left);
//            
//            // TreeMin will return the minimum value not node containing that value, but this function has to return the node. How to handle it without changing TreeMin
//            ?
//            
//        }
//        else
//        {
//            ?
//        }
//        
//        
//        
//    }
//    
//    
//    ////////// Successor of x
//    
//    ?  Successor(?)
//    {
//        
//    }
//    
//    
//    ////////// Delete from tree
//    
//    void delete( string x)
//    {
//        
//        
//    }
//  
};

int main()
{
    BST St;
    St.insert("pat");
    St.insert("use");
    St.insert("zoo");
    St.insert("try");
    St.insert("bat");
    St.insert("hay");
    St.insert("key");
    St.insert("jig");
    
    
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.PreorderTraverse(St.root);
    cout<<endl;
    
    St.PostorderTraverse(St.root);
    cout<<endl;
    
    cout<<St.TreeMin()<<endl;
        treeNode* sNode=St.search("");
    if(sNode!=NULL)
        cout<<sNode->data<<endl;
    else
        cout<<"Data not found"<<endl;
    
 /*   cout<<St.TreeMax()<<endl;
    
    treeNode* scNode=Predecessor("");
    cout<<scNode->data<<endl;
    cout<<St.Successor("")<<endl;
    
    
    St.PreorderTraverse();
    cout<<endl;
    St.PostorderTraverse();
    cout<<endl;
    
    treeNode* sNode=St.search("");
    if(sNode!=NULL)
        cout<<sNode->data<<endl;
    else
        cout<<"Data not found"<<endl;
    
    St.delete("jig");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.delete("bat");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.delete("use");
    St.InorderTraverse(St.root);
    cout<<endl;
 */
    
}


