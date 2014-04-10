#ifndef _DISJOINTSET_
#define _DISJOINTSET_

#include <iostream>
#include <vector>

class DisjointSet {
public:
  enum {
    NORTH = 0,
    WEST,
  };

  struct Node {
    int elem;
    bool walls[2];
    Node * parent;

    Node( int x, Node* p ) : elem( x ), parent( p ) {
      for( int i = 0; i < 2; ++i ) walls[i] = true;
    }
  };
public:
  DisjointSet();
  DisjointSet( int height, int width );
  virtual ~DisjointSet();
  void print( std::ostream& os );
private:
  int height_;
  int width_;
  std::vector<Node*> set_;
};

#endif
