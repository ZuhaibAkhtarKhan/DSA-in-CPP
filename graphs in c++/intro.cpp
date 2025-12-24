#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// G = (V,E)

void BFS(int gr[][8], int n, int i) {
    bool visited[8] = {0};
    queue <int> q;

    cout << i << " ";
    visited[i] = true;

    q.push(i);

    while(!q.empty()) {
        
        int u = q.front();
        q.pop();
        for(int j = 1; j < n; j++) {
            if(gr[u][j] == 1 && visited[j] == false) {
                cout << j << " ";
                visited[j] = true;
                q.push(j);
            }
        }
    }
    cout << endl;
}

void DFS(int gr[][8], int n, int i) {
    static bool visited[8] = {0};

    // cout << i << " ";                           // By suppressive stack
    // visited[i] = true;
    // for(int j = 1; j < n; j++) {
    //     if(gr[i][j] == 1 && visited[j] == 0) {
    //         DFS(gr, 8, j);
    //     }
    // }

    // By running stack now
    stack <int> s;
    cout << i << " ";
    s.push(i);
    
    while(!s.empty()) {
            bool yes = false;
            visited[i] = true;
            
            for(int j = 1; j< n; j++) {
                if(gr[i][j] == 1 && visited[j] == 0) {
                    cout << j << " ";
                    s.push(j);
                    yes = true;
                    i = j;
                    break;
                }
                
            }
            if(!yes) {
                    if(!s.empty()) i = s.top();
                    else break;
                    s.pop();
            }
                
            
         
        
    } ;
}
int main() {
    int gr[8][8] = {
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 1, 1, 1, 0, 0, 0},
        { 0, 1, 0, 1, 0, 0, 0, 0},
        { 0, 1, 1, 0, 1, 1, 0, 0},
        { 0, 1, 0, 1, 0, 1, 0, 0},
        { 0, 0, 0, 1, 1, 0, 1, 1},
        { 0, 0, 0, 0, 0, 1, 0, 0},
        { 0, 0, 0, 0, 0, 1, 0, 0}
    };

    BFS(gr, 8, 4);
    DFS(gr, 8, 4);
}
