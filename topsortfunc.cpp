#include "topsort.h"
#include <iostream>
#include <vector>

void Dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, Stack& answer){

    visited[v] = true;

    for(int i : matrix[v]){
        if(!visited[i]){
            Dfs(i, visited, matrix, answer);
        }
    }

    answer.push(v);
}

void TopSort(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, int Vertex){

    Stack answer;

    visited.assign(Vertex, false);
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            Dfs(i, visited, matrix, answer);
        }
    }

    while(!answer.isEmpty()){
        std::cout << answer.peek() << " ";
        answer.pop();
    }
}