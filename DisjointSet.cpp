#include "DisjointSet.hpp"

DisjointSet::DisjointSet() : height_( 0 ), width_( 0 ) {
}

DisjointSet::~DisjointSet() {
}

DisjointSet::DisjointSet( int height, int width ) : height_( height ), width_( width ) {
  //
  // initially all elements are in their own set
  //
  int size = height * width;
  for( int i = 0; i < size; ++i ) {
    map_[i] = i;
  }
}

void DisjointSet::print( std::ostream& os ) {
  using namespace std;
  /*
  for( int h = 0; h < height_; ++h ) {
    for( int w = 0; w < width_; ++w ) {
      
    }
  }
  */
  for( auto it : map_ )
    cout << it.second << endl;
}
