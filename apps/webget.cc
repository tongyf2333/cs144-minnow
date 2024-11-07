#include "socket.hh"

#include <cstdlib>
#include <iostream>
#include <span>
#include <string>
#include  "tcp_minnow_socket.hh"

using namespace std;

void get_URL( const string& host, const string& path )
{
  TCPSocket a;
  a.connect( Address( host, "http" ) );
  const string aa = "GET " + path + " HTTP/1.1\r\n" + "Host: " + host + " \r\n" + "Connection: close\r\n\r\n";
  vector<string> buf;
  buf.push_back( aa );
  a.write( buf );
  a.shutdown( SHUT_WR );
  while ( !a.eof() ) {
    string output;
    a.read( output );
    cout << output;
  }
  a.close();
}

int main( int argc, char* argv[] )
{
  try {
    if ( argc <= 0 ) {
      abort(); // For sticklers: don't try to access argv[0] if argc <= 0.
    }

    auto args = span( argv, argc );

    // The program takes two command-line arguments: the hostname and "path" part of the URL.
    // Print the usage message unless there are these two arguments (plus the program name
    // itself, so arg count = 3 in total).
    if ( argc != 3 ) {
      cerr << "Usage: " << args.front() << " HOST PATH\n";
      cerr << "\tExample: " << args.front() << " stanford.edu /class/cs144\n";
      return EXIT_FAILURE;
    }

    // Get the command-line arguments.
    const string host { args[1] };
    const string path { args[2] };

    // Call the student-written function.
    get_URL( host, path );
  } catch ( const exception& e ) {
    cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
