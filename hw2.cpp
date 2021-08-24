#include <iostream>
using namespace std;

void mult(int i,int j,int* v,int* array, int* m, int* d, bool h){
    array[*v] = m[i] + d[j];
    array[*v+1] += m[i+1] * d[j+1];
    if(i != 2*m[0]-1 && j!= 2*d[0] -1){
      if(m[i]+d[j+2]>= m[i+2]+ d[j]){
        if(h || i == 1 && j == 1){
          (*v) += 2;
          mult(i,j+2, v, array, m,d,true);
          if(m[i]+d[j+2] != m[i+2]+ d[j])
            *v = *v+2;
          mult(i+2,j, v , array,m,d,false );
      }
        else
          return;
      }
      if (m[i]+d[j+2]< m[i+2]+ d[j]){
        if(!h|| i == 1 && j == 1){
              (*v) += 2;
          mult(i+2, j, v , array,m,d,false );
          *v = *v+2;
          mult(i,j+2, v, array, m,d,true);
      }
    }
  }
        else
          return;
}

int main() {
    int n;  //tedad jomle haye chand jomle ii aval
    cin>>n;
    int *m = new int [n*2 + 1];  // araye aval
    m[0] = n;
    for (int u = 1; u <n*2 + 1 ; u++) {
        cin>>m[u];
    }
    cout<<'\n';
    int b;  //tedad jomle haye chand jomle ii dovom
    cin>>b;

    int *d = new int [b*2 + 1];
     d[0] = b;
    for (int s = 1; s <b*2+1 ; s++) {
        cin>>d[s];
    }
    int *sum_ = new int [(n+b)*2 +1];
    int i = 1;int j = 1;int  w = 1;int z = 0;
    while((i<(n*2))||(j<(b*2))){
        //cout<<"i"<<i<<"\n"<<"j"<<j<<'\n'<<"sum_[w-2]"<<sum_[w-2]<<'\n'<<"sum_[w-1]"<<sum_[w-1];
        if(m[i] == d[j]){
            sum_[w] = m[i];
            sum_[w+1] = m[i+1] + d[j+1];
            w+=2;j+=2;i+=2;z+=1;
            continue;
        }
        if ((j > b*2 )|| (m[i]>d[j])){
            sum_[w] = m[i];
            sum_[w+1] = m[i+1];
            w+=2;i+=2;z+=1;
            continue;
        }
        if ((i > n*2)|| (m[i]<d[j])){
            sum_[w] = d[j];
            sum_[w+1] = d[j+1];
            w+=2;j+=2;z+=1;
        }

    }
    sum_[0] = z;
    for (int k = 0; k <z*2+1 ; ++k) {
        cout<<sum_[k]<<' ';
    }
    cout<<endl;

     i= 1;
     int V = 1;
    int *v = &V;
     j = 1;
    int *array = new int [n*b+1];
    mult(i,j,v, array, m, d, true);
    for (int h = 0; h <12  ; h++) {
      cout << array[h] << ' ';
    }
    return 0;
}

//zarbesh ro benevis
