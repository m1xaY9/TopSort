#ifndef OP2SEM_TOPSORT_H
#define OP2SEM_TOPSORT_H
#include <vector>

class PairStack{
    struct Node{
        std::pair<bool, int> vertex;
        Node* next;
        Node(std::pair<bool, int> vertex) : vertex(vertex), next(nullptr){}
    };
    Node* top;
public:
    PairStack()
            : top(nullptr){
    }
    ~PairStack(){
        while(!isEmpty()){
            pop();
        }
    }

    void push(std::pair<bool, int> data){
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

    std::pair<bool, int> peek(){
        if(isEmpty()){
            ret();
        }
        return top->vertex;
    }

    int ret(){
        return -1;
    }

    bool isEmpty(){
        return top == nullptr;
    }
};

class IntStack{
    struct Node{
        int vertex;
        Node* next;
        Node(int vertex) : vertex(vertex), next(nullptr){}
    };
    Node* top;
public:
    IntStack()
            : top(nullptr){
    }
    ~IntStack(){
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

void Dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, PairStack& dfs, IntStack& postOrder);
void TopSort(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& matrix, int Vertex);

#endif
