#include "user_median_v2_implementation.h"


/*
//#include <bits/stdc++.h>
using namespace std;

Node::Node(int key, int level) {
  this->key = key;

  // Allocate memory to forward
  forward = new Node *[level + 1];

  // Fill forward array with 0(NULL)
  memset(forward, 0, sizeof(Node *) * (level + 1));
};

SkipList::SkipList(int MAXLVL, float P) {
  this->MAXLVL = MAXLVL;
  this->P = P;
  level = 0;

  // create header node and initialize key to -1
  header = new Node(-1, MAXLVL);
};

// create random level for node
int SkipList::randomLevel() {
  float r = (float)rand() / RAND_MAX;
  int lvl = 0;
  while (r < P && lvl < MAXLVL) {
    lvl++;
    r = (float)rand() / RAND_MAX;
  }
  return lvl;
};

// create new node
Node *SkipList::createNode(int key, int level) {
  Node *n = new Node(key, level);
  return n;
};

// Insert given key in skip list
void SkipList::insertElement(int key) {
  Node *current = header;

  // create update array and initialize it
  std::vector<Node*> update = std::vector( Node(-1,MAXLVL + 1));
  //Node *update[MAXLVL + 1];
  memset(update, 0, sizeof(Node *) * (MAXLVL + 1));

  /* start from highest level of skip list
          move the current pointer forward while key
          is greater than key of node next to current
          Otherwise inserted current in update and
          move one level down and continue search
  */
  for (int i = level; i >= 0; i--) {
    while (current->forward[i] != NULL && current->forward[i]->key < key)
      current = current->forward[i];
    update[i] = current;
  }

  /* reached level 0 and forward pointer to
  right, which is desired position to
  insert key.
  */
  current = current->forward[0];

  /* if current is NULL that means we have reached
  to end of the level or current's key is not equal
  to key to insert that means we have to insert
  node between update[0] and current node */
  if (current == NULL || current->key != key) {
    // Generate a random level for node
    int rlevel = randomLevel();

    // If random level is greater than list's current
    // level (node with highest level inserted in
    // list so far), initialize update value with pointer
    // to header for further use
    if (rlevel > level) {
      for (int i = level + 1; i < rlevel + 1; i++) update[i] = header;

      // Update the list current level
      level = rlevel;
    }

    // create new node with random level generated
    Node *n = createNode(key, rlevel);

    // insert node by rearranging pointers
    for (int i = 0; i <= rlevel; i++) {
      n->forward[i] = update[i]->forward[i];
      update[i]->forward[i] = n;
    }
    cout << "Successfully Inserted key " << key << "\n";
  }
};

// Delete element from skip list
void SkipList::deleteElement(int key) {
  Node *current = header;

  // create update array and initialize it
  Node *update[MAXLVL + 1];
  memset(update, 0, sizeof(Node *) * (MAXLVL + 1));

  /*    start from highest level of skip list
      move the current pointer forward while key
      is greater than key of node next to current
      Otherwise inserted current in update and
      move one level down and continue search
  */
  for (int i = level; i >= 0; i--) {
    while (current->forward[i] != NULL && current->forward[i]->key < key)
      current = current->forward[i];
    update[i] = current;
  }

  /* reached level 0 and forward pointer to
     right, which is possibly our desired node.*/
  current = current->forward[0];

  // If current node is target node
  if (current != NULL and current->key == key) {
    /* start from lowest level and rearrange
       pointers just like we do in singly linked list
       to remove target node */
    for (int i = 0; i <= level; i++) {
      /* If at level i, next node is not target
         node, break the loop, no need to move
        further level */
      if (update[i]->forward[i] != current) break;

      update[i]->forward[i] = current->forward[i];
    }

    // Remove levels having no elements
    while (level > 0 && header->forward[level] == 0) level--;
    cout << "Successfully deleted key " << key << "\n";
  }
};

// Search for element in skip list
void SkipList::searchElement(int key) {
  Node *current = header;

  /*    start from highest level of skip list
      move the current pointer forward while key
      is greater than key of node next to current
      Otherwise inserted current in update and
      move one level down and continue search
  */
  for (int i = level; i >= 0; i--) {
    while (current->forward[i] && current->forward[i]->key < key)
      current = current->forward[i];
  }

  /* reached level 0 and advance pointer to
     right, which is possibly our desired node*/
  current = current->forward[0];

  // If current node have key equal to
  // search key, we have found our target node
  if (current and current->key == key) cout << "Found key: " << key << "\n";
};

// Display skip list level wise
void SkipList::displayList() {
  cout << "\n*****Skip List*****"
       << "\n";
  for (int i = 0; i <= level; i++) {
    Node *node = header->forward[i];
    cout << "Level " << i << ": ";
    while (node != NULL) {
      cout << node->key << " ";
      node = node->forward[i];
    }
    cout << "\n";
  }
};

Subtractor::imgMedian_V2::imgMedian_V2() {}

Subtractor::imgMedian_V2::imgMedian_V2(unsigned char R_temp) {
  R = R_temp;
  R_half = (R / 2) - 1;
}

void Subtractor::imgMedian_V2::InitMedian(cv::Mat &img) {
  width = static_cast<unsigned int>(img.cols);
  height = static_cast<unsigned int>(img.rows);
  unsigned int len = static_cast<unsigned int>(width * height);
  SkipList lst(2, 0.1);

  for (unsigned int i = 0; i < len; i++) {
    V.push_back(lst);
  }

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      unsigned int i = x + y * width;
      for (unsigned int c = 0; c < R; c++) {
        V[i].insertElement((img.at<unsigned char>(cv::Point(x, y))));
        v_historyList[i].push_back(img.at<unsigned char>(cv::Point(x, y)));
      }
    }
  }

  localCopy = img.clone();
}

void Subtractor::imgMedian_V2::AddImage(cv::Mat &img) {
  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      unsigned int i = x + y * width;
      V[i].deleteElement(v_historyList[i][0]);
      v_historyList[i].pop_front();
      V[i].insertElement((img.at<unsigned char>(cv::Point(x, y))));
      v_historyList[i].push_back(img.at<unsigned char>(cv::Point(x, y)));
    }
  }
}

void Subtractor::imgMedian_V2::getMedian(cv::Mat &img) {}

cv::Mat Subtractor::imgMedian_V2::getMedian() {
  int lvl = 0;

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      unsigned int i = x + y * width;
      Node *node = V[i].header->forward[i];
      for (auto j = 0; j < R_half; j++) {
        cout << node->key << " ";
        node = node->forward[i];
      }
      localCopy.at<unsigned char>(
          cv::Point(static_cast<int>(x), static_cast<int>(y))) = node->key;
    }
  }
  return localCopy;
}

Subtractor::imgMedian_V2::~imgMedian_V2() {}
*/
