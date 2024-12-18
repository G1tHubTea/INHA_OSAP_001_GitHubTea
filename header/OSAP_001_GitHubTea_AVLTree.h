/****************************************************************************************
   File Name: OSAP_001_GitHubTea_AVLtree.h
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this project.
   This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#ifndef AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
#define AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_

#include "../header/OSAP_001_GitHubTea_Node.h"

class AVLTree {
public:
  // public method
  AVLTree();                         // normal constructor 
  bool IsRoot(int key);              // AVL Tree�� �Ű����� key���� ���� ��尡 ��Ʈ ������� �Ǻ��Ͽ� bool�� return
  bool IsExist(int key);             // AVL Tree�� �Ű����� key���� ���� ��尡 �����ϴ��� �Ǻ��Ͽ� bool�� return
  bool Empty() const;                // AVL Tree�� ����ִ��� �Ǻ��Ͽ� bool�� return
  int Size() const;                  // AVL Tree�� ����� ��ü ��� ������ int�� return
  int Height() const;                // AVL Tree�� root Node�� ���̸� int�� return
  int Height(int x);                 // AVL Tree�� �Ű����� key���� ���� ��带 ã�� ���̸� int�� return
  int Depth(int key);                // AVL Tree�� �Ű����� key���� ���� ��带 ã�� ���̸� int�� return
  int Find(int key);                 // AVL Tree�� �Ű����� key���� ���� ��带 ã�� ���̿� ������ ���� ���
  int MinDescendant(int x);          // AVL Tree�� �Ű����� key���� ���� ����� ����Ʈ������ �ּڰ��� int�� return
  int MaxDescendant(int x);          // AVL Tree�� �Ű����� key���� ���� ����� ����Ʈ������ �ִ��� int�� return
  int AncestorKeySum(int);           // AVL Tree�� �Ű����� key���� ���� ��带 ã�� �θ������ ��Ʈ������ ����� Node���� keyW���� ���� int�� return
  void Insert(int);                  // AVL Tree�� �Ű����� key���� ���� ��带 ����
  int Rank(int);                     // AVL Tree�� �Ű����� key���� ���� ��带 ã�� ������ return
  void Erase(int);                   // AVL Tree�� �Ű����� key���� ���� ��带 ã�� ���̿� ������ ���� ����ϰ� �ش� ��带 ����

private:
  // attribute
  Node* root_;                       // AVL Tree Root Node
  int size_;                         // AVL Tree ��ü ������

  // private method
  int Difference(Node*);             // �Ű����� curNode�� �� �ڽ� ����� ���� return
  void UpdateHeight(Node*);          // �Ű����� curNode�� ���̸� ������Ʈ��
  void UpdateSubtreeSize(Node*);     // �Ű����� curNode�� ����Ʈ�� ����� ������Ʈ��
  Node* LeftLeftRotation(Node*);     // Left-Left Rotation ���� Node*�� return
  Node* RightRightRotation(Node*);   // Right-Right Rotation ���� Node*�� return
  Node* LeftRightRotation(Node*);    // Left-Right Rotation ���� Node*�� return
  Node* RightLeftRotation(Node*);    // Right-Left Rotation ���� �� Node*�� return
  Node* Balance(Node*);              // �Ű����� curNode�� �˸��� ȸ���� ���� �� Node*�� return
  Node* Search(Node*, int);          // �Ű����� curNode�� root�� �ϴ� AVL Tree���� key���� ���� ��带 ã�� Node*�� return
  int FindMin(Node*);                // ����Ʈ���� ��� �� ���� ���� Ű���� int�� return
  int FindMax(Node*);                // ����Ʈ���� ��� �� ���� ū Ű���� int�� return
};

#endif // !AVL_TREE_OSAP_001_GITHUBTEA_AVLTREE_H_
