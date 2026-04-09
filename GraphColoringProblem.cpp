#include <bits/stdc++.h>

using namespace std;

int V;
int graph[10][10];
int color[10];

bool isSafe(int v, int c) {
  for(int i = 0; i < V; i++) {
    if(graph[v][i] && color[i] == c) return false;
  }

  return true;
}

bool solve(int v, int m) {
  if(v == V) return true;

  for(int c = 1; c <= m; c++) {
    if(isSafe(v,c)) {
      color[v] = c;
      if(solve(v+1,m)) return false;
      color[v] = 0;
    }
  }

  return false;
}

int main() {

  V = 4;
  int m = 3;

  graph[0][1] = graph[1][0] = 1;
  graph[0][2] = graph[2][0] = 1;
  graph[1][2] = graph[2][1] = 1;
  graph[1][3] = graph[3][1] = 1;
  graph[2][3] = graph[3][2] = 1;

  memset(color,0,sizeof(color));

  if(!solve(0,m)) {
    cout << "SOLUTION NOT POSSIBLE" << endl;
  } else {
    cout << "COLOR ASSIGNED:\n";
    for(int i = 0; i < V; i++) {
      cout << "Vertex: " << i << " -> Color" << color[i] << endl;
    }
  }
}
