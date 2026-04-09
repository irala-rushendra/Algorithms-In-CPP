#include <bits/stdc++.h>

using namespace std;

struct Node {
  char ch;
  int freq;
  unique_ptr<Node> left, right;

  Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

void printCodes(const unique_ptr<Node>& root, string msg) {

  if(root->ch != '$') {
    cout << root->ch << " : " << msg << "\n";
    return;
  }

  printCodes(root->left, msg + "0");
  printCodes(root->right, msg + "1");
}

void HuffmanCoding(string_view message) {

  if(!message.size()) return;

  map<char,int> freqList;
  
  for(char ch : message) {
    freqList[ch]++;
  }

  auto cmp = [](const unique_ptr<Node>& l, const unique_ptr<Node>& r) {
    return l->freq > r->freq;
  };

  priority_queue<unique_ptr<Node>, vector<unique_ptr<Node>>, decltype(cmp)> pq(cmp);

  for(auto const&[charecter, count] : freqList) {
    pq.push(make_unique<Node>(charecter, count));
  }

  while(pq.size() > 1) {

    auto l = std::move(const_cast<unique_ptr<Node>&>(pq.top()));
    pq.pop();

    auto r = std::move(const_cast<unique_ptr<Node>&>(pq.top()));
    pq.pop();

    auto parent = make_unique<Node>('$',l->freq + r->freq);
    parent->left = std::move(l);
    parent->right = std::move(r);

    pq.push(std::move(parent));
  }

  printCodes(pq.top(), "");
}

int main() {

  string msg = "ALLTHEBEST";
  HuffmanCoding(msg);
  
}
