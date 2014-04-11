#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdexcept>
#include "DisjointSet.hpp"

using namespace std;

enum {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

int xmap( int x, int y, int width );

struct wall {
  int A;
  int B;
  wall( int x, int y ) : A(x), B(y) {}
};

int main(int argc, char **argv ) {
  string input;
  int height = 0, width = 0;

  try {
    if( argc > 1 ) {
      input = argv[1];
    } else {
      cout << "Maze height? ";
      cin >> input;
    }
    height = stoi( input );
    if( height <= 0 ) {
      throw invalid_argument( "Cannot create a maze with non-positive height" );
    }

    if( argc > 2 ) {
      input = argv[2];
    } else {
      cout << "Maze width? ";
      cin >> input;
    }
    width = stoi( input );
    if( width <= 0 ) {
      throw invalid_argument( "Cannot create a maze with non-positive width" );
    }
  } catch( invalid_argument& e ) {
    cout << "Error: invalid argument \"" << input << "\"" << endl;
    exit( 0 );
  } catch( out_of_range& e ) {
    cout << e.what() << endl;
    exit( 0 );
  } catch( ... ) {
    cout << "Unknown exception caught" << endl;
    exit( 0 );
  }

  //
  // Seed random number generator
  // TODO: change to seed with time
  //
  srand( time( NULL ) );
  const int size = width * height;
  vector<wall> walls;

  //
  // Generate all of the walls in the maze and push them into the vector
  //
  for( int i = 0; i < size; ++i ) {
    if( ( ( i + 1 ) % width ) == 0 ) {
      if( ( i + width ) < size ) {
	walls.emplace_back( i, i + width );
      }
    } else if( ( i + width ) >= size ) {
      walls.emplace_back( i, i + 1 );
    } else {
      walls.emplace_back( i, i + 1 );
      walls.emplace_back( i, i + width );
    }
  }

  DisjointSet * djset = new DisjointSet( size );
  bool ** maze;
  maze = new bool*[size];
  for( int w = 0; w < size; ++w ) {
    maze[w] = new bool[size];
  }
  
  for( int w = 0; w < size; ++w ) {
    for( int h = 0; h < size; ++h ) {
      maze[w][h] = false;
    }
  }

  try {
    while( djset->NumberOfSets() != 1 /* djset->Find( start ) != djset->Find( end ) */ ) {
      if( walls.size() == 0 ) {
	break;
      }
      const int r = rand() % walls.size();
      const int square1 = walls.at( r ).A;
      const int square2 = walls.at( r ).B;

      const int set1 = djset->Find( square1 );
      const int set2 = djset->Find( square2 );
      if( set1 != set2 ) {
	djset->Union( set1, set2 );
      } else {
	maze[square1][square2] = true;
	maze[square1][square2] = true;
      }

      walls.erase( walls.begin() + r, walls.begin() + r + 1  );
    }
  } catch( ... ) {
    cout << "Unknown exception caught" << endl;
    exit( 0 );
  }

  for( const auto& it : walls ) {
    maze[ it.A ][ it.B ] = true;
    maze[ it.B ][ it.A ] = true;
  }

  cout << "    ";
  for( int x = 1; x < width; ++x ) {
    cout << " ---";
  }
  cout << endl;

  for( int y = 0; y < height; ++y ) {
    cout << "|   ";
    for( int x = 1; x < width; ++x ) {
      int t = xmap( x, y, width );
      if( maze[t][t-1] ) {
	cout << "|   ";
      } else {
	cout << "    ";
      }
    }
    cout << "|" << endl;
    
    if( y == ( height - 1 ) ) {
      for( int x = 0; x < (width - 1); ++x ) {
	cout << " ---";
      }
      cout << endl;
    }
    else {	
      for( int x = 0; x < width; ++x ) {
	int t = xmap( x, y, width );
	if( maze[t][t + width] ) {
	  cout << " ---";
	} else {
	  cout << "    ";
	}
      }
      cout << endl;
    }
  }


  //
  // free dynamic memory
  //
  for( int i = 0; i < size; ++i ) {
    delete [] maze[i];
    maze[i] = NULL;
  }
  delete [] maze;
  delete djset;
  
  return 0;
}

int xmap( int x, int y, int width ) {
  return y*width + x;
}
