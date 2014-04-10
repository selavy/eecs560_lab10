#include <iostream>
#include <string>
#include <stdexcept>
#include "DisjointSet.hpp"

using namespace std;

int main(int argc, char **argv ) {
  string input;
  int height = 0, width = 0;

  try {
    cout << "Maze height? ";
    cin >> input;
    height = stoi( input );
    cout << "Maze width? ";
    cin >> input;
    width = stoi( input );
  } catch( invalid_argument& e ) {
    cout << "Error: invalid argument \"" << input << "\"" << endl;
    return 0;
  } catch( out_of_range& e ) {
    cout << e.what() << endl;
  } catch( ... ) {
    cout << "Unknown exception caught" << endl;
  }

  cout << "height = " << height << ", width = " << width << endl;
  DisjointSet maze( height, width );
  maze.print( cout );
  return 0;
}
