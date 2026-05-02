#include "change.h"
#include <bits/stdc++.h>

void customerHelper(vector<int>& cstBills, int index, int curr, int price, set<int>& customer_values){
  if(index >= cstBills.size()){
    if(curr >= price){
      customer_values.insert(curr);
    }
    return;
  }
  customerHelper(cstBills, index + 1, curr, price, customer_values);
  customerHelper(cstBills, index + 1, curr + cstBills[index], price, customer_values);
}

bool cashierHelper(vector<int>& cshBills, int index, int curr, int price, set<int>& customer_values){
  if(customer_values.count(curr + price) != 0){
    return true;
  }

  if(index == cshBills.size()){
    return customer_values.count(curr + price) != 0;
  }

  return cashierHelper(cshBills, index + 1, curr, price, customer_values) ||
          cashierHelper(cshBills, index + 1, curr + cshBills[index], price, customer_values);
}

bool giveChange(vector<int> &cshBills, vector<int> &cstBills, int price) {
  set<int> customer_values;
  customerHelper(cstBills, 0, 0, price, customer_values);
  // for(int n : customer_values){
  //   cout << n << " ";
  // }

  // can pay exact amount
  if(customer_values.count(price) != 0){
    return true;
  }

  return cashierHelper(cshBills, 0, 0, price, customer_values);
}
