#include <iostream>
using namespace std;

int main() {
    int n;
    int b;
    int v;
    int *sum_;
    cin>>n>>b;
    n++;b++;
    int* m = new int[n];
    int *d = new int[b];
    for (int i = 0; i <n ; ++i) {
        cin>>m[i];
    }
    for (int j = 0; j <b ; ++j) {
        cin>>d[j];
    }
    if (n>b){
        v = n;
        sum_ = new int [n];
        for (int i = 0; i < n-b; ++i) {
            sum_[i] = m[i];
        }
        for (int j = 0; j <b ; ++j) {
            sum_[n-b+j] = m[n-b+j] + d[j];

        }
    }
    else {
        v = b;
        sum_ = new int [b];
        for (int i = 0; i < b-n; ++i) {
            sum_[i] = d[i];
        }
        for (int j = 0; j <n ; ++j) {
            sum_[b-n+j] = d[b-n+j] + m[j];

        }
    }
    for (int k = 0; k < v; ++k) {
        cout<<sum_[k]<<" ";

    }
    cout<<endl;

    int *mul = new int [n+b-1];
    for (int l = 0; l <n ; ++l) {
        for (int i = 0; i <b; ++i) {
            mul[i+l] += m[l]*d[i];

        }

    }
    for (int k = 0; k < n+b-1; ++k) {
        cout << mul[k] << " ";

    }
    return 0;
}