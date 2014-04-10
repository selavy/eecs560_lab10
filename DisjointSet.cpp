#include "DisjointSet.hpp"

DisjointSet::DisjointSet() : height_( 0 ), width_( 0 ) {
}

DisjointSet::~DisjointSet() {
  for( auto it : set_ ) {
    delete it;
  }
}

DisjointSet::DisjointSet( int height, int width ) : height_( height ), width_( width ) {
  //
  // initially all elements are in their own set
  //
  int size = height * width;
  for( int i = 0; i < size; ++i ) {
    Node * node = new Node( i, NULL );
    set_.push_back( node );
  }
}

void DisjointSet::print( std::ostream& os ) {
  using namespace std;

  int height = 0;
  for( int i = 0; i < static_cast<int>( set_.size() ); ++i ) {
    if( i != 0 ) {
      if( set_.at( i )->walls[WEST] ) {
	cout << "   |";
      } else {
	cout << "    ";
      }
    }

    if( ( i % width_ ) == 0 ) {
      cout << endl;
      for( int w = 0; w < width_; ++w ) {
	if( set_.at( width_ * height + w )->walls[NORTH] ) {
	  cout << " ---";
	} else {
	  cout << "    ";
	}
      }
      cout << endl << "|";
      ++height;
    }
  }

  cout << "   |" << endl;
  for( int w = 0; w < width_; ++w ) {
    cout << " ---";
  }
  cout << endl;
}
