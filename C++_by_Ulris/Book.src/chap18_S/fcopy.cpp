// ----------------------------------------------------
// fcopy.cpp
// Copy files
// Call: fcopy  [ source  [ destination ] ]
// ----------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

char usage[] = "Call: fcopy [source [destination]]";

inline void openerror( const char *file)
{
  cerr << "Error opening the file " << file << endl;
  exit(1);
}

bool copy( istream& is, ostream& os),    // Prototype,
     ok = true;                          // ok flag.

int main(int argc, char *argv[])
{
  char source[256] = "", dest[256] = "";

  switch( argc ) 
  {
   case 1:                       // No file declared
                                 // ==> input file name.
     cout << "Copying source file to destination file!\n"
             "Source file: ";
     cin.getline( source, 256);
     if( strlen(source) == 0)
     {
        cerr << "No source file declared!" << endl;
        return 1;
     }
     cin.sync();                 // No previous input
     cout << "Destination file: ";
     cin.getline( dest, 256);
     break;

   case 2:                       // One file is declared. 
     strcpy( source, argv[1]);
     break;

   case 3:    // Source and destination files are declared.
     strcpy( source, argv[1]);
     strcpy( dest, argv[2]);
     break; 
 
   default:                // Invalid call to the program.
     cerr << usage << endl;
     return 2;                   // or: exit(2);
  }

  if( strlen(dest) == 0)         // Only source file?
  {                              // yes ==> output to cout.
    ifstream infile(source); 
    if( !infile )
        openerror( source);
    ok = copy( infile, cout);
    // The file is closed by the ifstream destructor. 
  }
  else                        // Copy source to destination
  {                           // file in binary mode.
    ifstream infile( source, ios::in | ios::binary); 
    if( !infile )
        openerror( source);
    else
    {
       ofstream outfile( dest, ios::out | ios::binary); 
       if( !outfile)
          openerror( dest);
       ok = copy( infile, outfile);
       if( ok)
         cerr << "File " << source << " to file "
              << dest <<" copied!"<< endl;
    }
  }

  if(!ok)
  {
     cerr << "Error while copying!" << endl;
     return 3;
  }

  return 0; 
}

bool copy( istream& is, ostream& os)  // To copy 
{                                     // is to os.
  const int BufSize = 1024; 
  char buf[BufSize];
  do
  {
     is.read( buf, BufSize);
     if( is.gcount() > 0)
       os.write(buf, is.gcount());
  }
  while( !is.eof() && !is.fail() && !os.fail() );

  if( !is.eof() ) return false; 
  else            return true;
}

