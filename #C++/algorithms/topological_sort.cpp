#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> degree(numCourses, 0), topoOrder;
    queue<int> zeroDegree;
    for(int i = 0; i<prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        degree[prerequisites[i][0]]++;
    }
    for(int i = 0; i<numCourses; i++){
        if(degree[i] == 0){
            zeroDegree.push(i);
            topoOrder.push_back(i);
        }
    }
    while(!zeroDegree.empty()){
        int node = zeroDegree.front();
        zeroDegree.pop();
        for(int connectedNode: graph[node]){
            degree[connectedNode]--;
            if(degree[connectedNode] == 0){
                zeroDegree.push(connectedNode);
                topoOrder.push_back(connectedNode);
            }
        }
    }
    if(topoOrder.size() != numCourses){
        return vector<int>();
    }
    return topoOrder;
}

int main(){
    return 0;
}