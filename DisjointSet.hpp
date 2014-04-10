#ifndef _DISJOINTSET_
#define _DISJOINTSET_

#include <iostream>
#include <unordered_map>

class DisjointSet {
public:
  DisjointSet();
  DisjointSet( int height, int width );
  virtual ~DisjointSet();
  void print( std::ostream& os );
private:
  int height_;
  int width_;
  std::unordered_map<int, int> map_;
};

#endif
