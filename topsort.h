#ifndef OP2SEM_TOPSORT_H
#define OP2SEM_TOPSORT_H
#include <vector>

class Stack{
    struct Node{
        int vertex;
        Node* next;
        Node(int vertex) : vertex(vertex), next(nullptr){}
    };
    Node* top;
public:
    Stack()
            : top(nullptr){
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

    void push(int data){
        Node* NewNode = new Node(data);
        NewNode -> next = top;
        top = NewNode;
    }

    void pop(){
        if(isEmpty()){
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return top->vertex;
    }

    bool isEmpty(){
        return top == nullptr;
    }
};

void Dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, Stack& answer);
void TopSort(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, int Vertex);

#endif
