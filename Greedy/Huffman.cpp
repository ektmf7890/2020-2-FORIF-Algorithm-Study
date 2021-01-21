// 2019073027 윤다영 11802
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

class MinHeapNode{
public:
    int freq;
    int depth;

    MinHeapNode *leftChild, *rightChild;

    MinHeapNode(int freq){
        this->freq = freq;
        depth = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class CompareObj{
public:
    bool operator() (MinHeapNode *node1, MinHeapNode *node2){
        return node1->freq > node2->freq;
    }
};

MinHeapNode* Huffman(priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareObj> pq);
void getCodeLength(MinHeapNode* node);

int answer;

int main(){
    int n;
    cin >> n;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareObj> pq;

    string character;
    int freq;
    for(int i=0; i<n; i++){
        cin >> character >> freq;
        MinHeapNode* newNode = new MinHeapNode(freq);
        pq.push(newNode);
    }

    int numOfChar;
    cin >> numOfChar;

    MinHeapNode* rootNode = Huffman(pq);

    getCodeLength(rootNode);

    int fixedCodeLength = int(ceil(log(n) / log(2)));
    cout << numOfChar * fixedCodeLength << endl;
    cout << answer <<endl;
}

MinHeapNode* Huffman(priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareObj> pq) {
    MinHeapNode *left, *right, *top;
    while(pq.size() != 1){
        left = pq.top();
        pq.pop();

        right = pq.top();
        right->depth ++;
        pq.pop();

        top = new MinHeapNode(left->freq + right->freq);
        top->leftChild = left;
        top->rightChild = right;

        pq.push(top);
    }
    return pq.top();
}

void getCodeLength(MinHeapNode* node){
    if(!node) return;

    // root
    if(!node->leftChild && !node->rightChild){
        answer += (node->freq) * (node->depth);
    }
    if(node->leftChild) {
        node->leftChild->depth = (node->depth) + 1;
//        cout << node->leftChild->freq << ", " << node->leftChild->depth <<endl;
    }
    if(node->rightChild) {
        node->rightChild->depth = (node->depth) + 1;
//        cout << node->rightChild->freq << ", " << node->rightChild->depth <<endl;
    }
    //left child
    getCodeLength(node->leftChild);

    //right child
    getCodeLength(node->rightChild);
}