#include <bits/stdc++.h> // IM SORRY FOR USING THIS

using namespace std; // IM SORRY FOR USING THIS
  

struct Item {
  double value;
  double weight;
  double ratio;

  Item(double val, double wt) : value(val), weight(wt) {
    ratio = value / weight;
  }
};

int GreedyKnapsack(int capacity, vector<Item>& arr) {

  if(!arr.size()) return 0;

  sort(arr.begin(), arr.end(), [](const Item& a, const Item& b){
      return a.ratio > b.ratio;
      });

  double totalValue = 0;
  for(auto it = arr.begin(); it != arr.end(); it++) {
    
    if(capacity == 0) break;
    if(it->weight <= capacity) {
      totalValue += it->value;
      capacity -= it->weight;
    } else {
      totalValue += capacity * (it->value / it->weight);
      capacity = 0;
    }
  }

  return totalValue;
}

int main() {
  
  vector<Item> arr = {{60,10},{100,20},{120,30}};
  int capacity = 50;

  cout << "The Max Value: " << GreedyKnapsack(capacity, arr) << endl;

  return 0;
}
