#include <bits/stdc++.h>
using namespace std;

//bfs
auto bfs(auto &s){
    deque<auto> q = {s};
    while(!q.empty()){
        auto front = q[0];
        q.pop_front();
        for ii in nextlayer{
            bool condition = true;
            if(condition){
                q.push_back(ii);
            }
        }
    }
}

//bfs level traversal
auto bfs_lv(auto &s){
    deque<int> q = {s};
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto front = q[0];
            q.pop_front();
            for ii in nextlayer{
                bool condition = true;
                if(condition){
                    q.push_back(ii);
                }
            }
        }
    }
}

//bfs bidirectional (level traversal)
auto bfs_bi(auto &start,auto &end){
    unordered_map <auto> q1,q2;
    q1.insert(start);
    q2.insert(end);
    int count = 0
    while(!q1.empty() && !q2.emplty()){
        if(q1.size()>q2.size())
            swap(q1,q2);
        int size = q1.size();
        for(int i=0;i<size;i++){
            auto item = q1[i]; //no pop
            for ii in nextlayer{
                if (q2.find(ii) != q2.end())
                    return count + 1;
                bool condition = true;
                if(condition){
                    q1.push_back(ii);
                }
            }
        }
        count++;
    }
}


//dfs
int dfs(int &ss){
    stack<int> s = {ss};
    while(!s.empty()){
        int top = s.top();
        s.pop();
        for ii in nextlayer{
            bool condition = true;
            if(condition){
                s.push(ii);
            }
        }
    } 
}
