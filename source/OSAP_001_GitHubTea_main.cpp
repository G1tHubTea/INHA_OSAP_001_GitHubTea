/****************************************************************************************
   File Name: OSAP_001_GitHubTea_main.cpp
   Copyright (c) 2024 GitHubTea

   This software is distributed under the MIT License.
   For more details on the MIT License, please refer to the LICENSE file in this
project. This software is provided "as is," without any warranty of any kind.

   Author: GitHubTea
   Date: 2024-11-28
*****************************************************************************************/

#include <iostream>

#include "../header/OSAP_001_GitHubTea_AVLTree.h"
#include "../header/OSAP_001_GitHubTea_Node.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 0, Q = 0;
  cin >> T;

  string instruction;
  while (T--) {
    AVLTree avl;
    cin >> Q;
    while (Q--) {
      cin >> instruction;
      if (instruction == "Empty") {
        /*
          set�� ��� �ִٸ� 1, �ƴϸ� 0�� ��� 
        */ 
        cout << (avl.Empty() ? 1 : 0) << "\n";
      } else if (instruction == "Size") {
        /*
          set�� ����� ������ �� ���
        */
        cout << avl.Size() << "\n";
      } else if (instruction == "Height") {
        /*
          AVL Ʈ���� ���� ���. AVLƮ���� ��� �ִٸ� -1 ���.
        */
        cout << avl.Height() << "\n";
      } else if (instruction == "Find") {
        /*
          ��� x�� ���̿� ������ ���� ���.
          ��� x�� �������� ���� ��, 0�� ���
        */
        int x;
        cin >> x;
        cout << avl.Find(x) << "\n";
      } else if (instruction == "Insert") {
        /*
          ��� x�� �����ϰ�, ��� x�� ���̿� ������ ���� ���.
          �̶� x�� ���� set�� �������� �ʴ� ������ �־���
        */
        int x;
        cin >> x;
        
        // Insert()�� x���� AVLƮ���� ����
        avl.Insert(x);
        
        // ���̿� ������ �� ���
        cout << avl.Depth(x) + avl.Height(x) << "\n";
      } else if (instruction == "Ancestor") {
        /*
          ��� x�� ���̿� ������ ��, x�� �θ�κ��� ��Ʈ������
          ����� ������ key ������ ���� �������� �����Ͽ� ����Ѵ�.
          �̶� x�� ���� set�� �����ϴ� ���ҷθ� �־�����.
        */
        int x;
        cin >> x;

        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        int ancestor_key_sum = avl.Ancestor(x);

        if (avl.isExist(x) && avl.isRoot(x)) {        // ��Ʈ ����� ���
          cout << depth_height_sum << " " << "0\n";   // ���̿� ������ �� (����) 0
        } else {
          cout << depth_height_sum << " " << ancestor_key_sum << "\n";
        }
      } else if (instruction == "Average") {
        /*
          ��� x�� ��Ʈ�� ����Ʈ������ ������ key ����
          �ּڰ�, �ִ��� �������� ����Ѵ�.
          �̶� x�� ���� set�� �����ϴ� ���ҷθ� �־�����.
        */
        int x;
        cin >> x;
        int min_key = (avl.MinDescendant(x));
        int max_key = (avl.MaxDescendant(x));
        cout << (min_key + max_key) / 2 << "\n";
      } else if (instruction == "Rank") {
        /*
          ��� x�� ���̿� ������ ��, ������ �������� �����Ͽ� ����Ѵ�.
          ���� ��� x�� ���ٸ� 0�� ����Ѵ�. �̶� ������ set����
          x���� ���� ������ �� + 1 �� �����Ѵ�.
        */
        int x;
        cin >> x;
        int depth_height_sum = avl.Depth(x) + avl.Height(x);
        if (avl.isExist(x)) {             // set�� ������ ��
          cout << depth_height_sum << " " << avl.Rank(x) << "\n";
        } else {                          // set�� �������� ���� ��
          cout << "0\n";
        }
      } else if (instruction == "Erase") {
        /*
          ��� x�� ���̿� ������ ���� ����ϰ� �ش� ��带 �����Ѵ�.
          ���� ��� x�� ���ٸ� 0�� ����Ѵ�.
        */
        int x;
        cin >> x;
        if (avl.isExist(x)) {             // set�� ������ ��
          cout << avl.Depth(x) + avl.Height(x) << "\n";
          avl.Erase(x);
        } else {                          // set�� �������� ���� ��
          cout << "0\n";
        }
      }
    }
  }

  return 0;
}
