#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_

#include "OSAP_001_GitHubTea_Node.h"

class AVLTree
{
public:
    AVLTree(); // AVLTree instance에 대한 생성자
    ~AVLTree(); // AVLTree instance에 대한 소멸자

    void set_root_(int); // member data root_에 대한 setter
    void set_size_(int); // member data size_에 대한 setter
    void set_height_(int); // member data height_에 대한 setter

    bool Empty() const; // set이 비어 있다면 1을, 아니라면 0을 return함
    int Size() const; // 현재 tree에 존재하는 node들의 개수를 출력함
    int Height() const; // 전체 tree의 height를 return함
    int Height(int) const; // node의 key를 입력받고, 그 node의 높이를 출력함
    int Depth(int) const; // node의 key를 입력받고, 그 node의 깊이를 출력함
    int Ancestor(int) const; // node의 key를 입력받고, 그 node의 Ancestors들의 key의 합을 return함
    int MinDescendant(int) const; // node의 key를 입력받고, 그 node의 Descendant들 중 가장 작은 key를 return함
    int MaxDescendant(int) const; // node의 key를 입력받고, 그 node의 Descendant들 중 가장 큰 key를 return함
    int Rank(int) const; // node의 key를 입력받고, 그 node의 rank를 출력함
    void Insert(int); // tree에 새로운 Node를 삽입함
    void Erase(int);  // node의 key를 입력받고, 그 node를 삭제함

private:
    Node* root_; //root node의 주소
    int size_; // 현재 tree에 존재하는 node들의 개수
    int height_; // 현재 tree의 height
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_