#include "bst.h"

int main()
{
    bst object;
    object.build();     //builds a BST
    object.display();   //displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //node* n = new node();
    //n->data = 0;
    //int in = 0;
    //cin >> in;
    //object.dlt(NULL, NULL, in);

    //object.dlte(NULL, 0);

    int n = 0;
    object.count(NULL, n);
    cout << "C:" << n << endl;

    object.display();   //displays again after!

    return 0;
}

void bst::dlte(node* curr, int small){
  if(curr == NULL){
    curr = root;
  }

  if(curr->left){
    dlte(curr->left, curr->data);
  }else{
    if(curr->right){
      small = curr->right->data;
    }
    cout << small << endl;
    cout << curr->data << endl;
    dlt(NULL, NULL, curr->data);
    dlt(NULL, NULL, small);
  }
}

void bst::dlt(node* curr, node* prev, int todlt){
  if(curr == NULL){
    curr = root;
  }
  if(todlt > curr->data){
    dlt(curr->right, curr, todlt);
    return;
  }else if(todlt < curr->data){
    dlt(curr->left, curr, todlt);
    return;
  }

  if(todlt == curr->data){
    if(!curr->left && !curr->right){ //no children
      node* temp = curr;
      if(prev->left == curr) prev->left = NULL;
      if(prev->right == curr) prev->right = NULL;
      delete temp;
    }else if(curr->left && !curr->right){ //lchild only
      curr->data = curr->left->data;
      node* temp = curr->left;
      curr->left = NULL;
      delete temp;
    }else if(!curr->left && curr->right){ //rchild only
      curr->data = curr->right->data;
      node* temp = curr->right;
      curr->right = NULL;
      delete temp;
    }else { //2 children
      node* n = new node();
      int iopn = iop(curr, n)->data;
      dlt(NULL, NULL, iopn);
      curr->data = iopn;
    }
  }
}

node* bst::iop(node* curr, node*& n){
  if(curr == NULL){
    curr = root;
  }
  if(n->data == 0){
    if(curr->left){
      curr = curr->left;
      n = curr;
    }else{
      cout << "NO IOP!" << endl;
      return NULL;
    }
  }

  if(curr->right){
    iop(curr->right, n);
  }else{
    n = curr;
  }
  return n;
}

void bst::count(node* curr, int& num){
  if(!curr) curr = root;

  if(curr->right) count(curr->right, num);
  if(curr->left) count(curr->left, num);
  if(!curr->right && !curr->left) num++;
}
