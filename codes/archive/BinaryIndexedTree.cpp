/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#define N 100100
int input[N];
int tree[2*N];

void update(int key, int value) {
      while(key <= N-1) {
            tree[key] += value;
            key += key & (-key);
      }
}

int query(int key) {
      int sum = 0;
      while(key > 0) {
            sum += tree[key];
            key -= key & (-key);
      }
      return sum;
}