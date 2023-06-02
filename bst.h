//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
        //These functions are supplied already
        bst();                  //supplied
        void build();           //supplied
        void display();//supplied
  void count(node*, int&);
  node* iop(node*, node*&);
  void dlt(node*, node*, int);
  void dlte(node*, int);
  /* ************** PLACE YOUR PROTOTYPE HERE ***************** */


        private:
                node * root;
                void display_tree(node*, int);
};
