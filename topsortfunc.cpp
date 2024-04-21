#include "topsort.h"
#include <iostream>

void Dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, PairStack& dfs, IntStack& postOrder){

    for(int i = 0 ; i <= v; i++){
        if(!visited[i]){
            dfs.push(std::make_pair(false,i));
        }
        while(!dfs.isEmpty()){
            std::pair<bool,int> node = dfs.peek();
            dfs.pop();
            if (node.first) {
                postOrder.push(node.second);
                continue;
            }
            if (visited[node.second]) {
                continue;
            }
            visited[node.second]=true;
            dfs.push(std::make_pair(true, node.second));
            const auto& newVec = matrix[node.second];
            for(const auto son: newVec){
                if(!visited[son]){
                    dfs.push(std::make_pair(false, son));
                }
            }
        }
    }

}

void TopSort(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, int Vertex){

    PairStack dfs;
    IntStack postOrder;

    visited.assign(Vertex, false);
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            Dfs(i, visited, matrix, dfs, postOrder);
        }
    }

    while(!postOrder.isEmpty()){
        std::cout << postOrder.peek() << " ";
        postOrder.pop();
    }
}
