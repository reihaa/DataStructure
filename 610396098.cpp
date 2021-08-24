#include <iostream>
using namespace std;

struct node
  {
    int data;
    node *next;
  };


  class list
  {
    private:
    node *head, *tail;
    public:
    list()
    {
      head=NULL;
      tail=NULL;
    }
    void add(int value)
 {
   node *temp=new node;
   temp->data=value;
   temp->next=head;
   head=temp;
 }

 node* T(){
   return head;
 }
};

int A(node* a){
  if (a->next == NULL){
    if (a-> data == 9){
      a-> data = 0;
      return 1;
    }
    else{
      (a->data)++;
      return 0;
    }
  }
  else{
    int h = A(a->next);
    if (h == 1 && a->data == 9){
      a->data = 0;
      return 1;
    }
    else if(h == 1){
      (a->data)++;
      return 0;
    }
    else return 0;
  }
}

int main(){
  int n;
  cin>>n;
  list mylist;
  int b;
  while(n != 0){
    b = n%10;
    mylist.add(b);
    n= n/10;
  }
  int v = A(mylist.T());
  if (v == 1)
    mylist.add(1);
  node* s = mylist.T();
  while(s!= NULL){
    cout<<s->data;
    s = s->next;

  }
  return 0;
}
