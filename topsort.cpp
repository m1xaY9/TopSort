#include <iostream>
#include "topsort.h"

std::vector<std::vector<int>> matrix;
std::vector<bool> visited;

int main(){

    int Vertex, Edge;
    std::cin >> Vertex >> Edge;

    for(int i = 0; i < Vertex; i++){
        matrix.emplace_back();
    }

    for(int i = 0; i < Edge; i++){

        int start, end;
        std::cin >> start >> end;
        matrix[start].push_back(end);

    }

    std::cout << "Результат топологической сортировки: ";

    TopSort(Vertex, visited, matrix, Vertex);

    return 0;
}


