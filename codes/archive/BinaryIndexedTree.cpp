/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
int query(int index) {
      int sum = 0;
      while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
      }
      return sum;
}

void update(int index, int value, int n) {
      while (index <= n) {
            tree[index] += value;
            index += index & (-index);
      }
}