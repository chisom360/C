// expIns_t.cpp:  Zum Testen expliziter Instantiierungen
// ------------------------------------------------------ 

#include "quadmatrix.h"

template class QuadMatrix<long double, 3>;

int main()
{
	QuadMatrix<long double, 4> m;

    try
    {
        for(int k=0; k < m.dim(); k++)
           for( int l = 0; l < m.dim(); l++)
                 m[k][l] = k*l;
           
    }   
    catch(out_of_range& err )
    {
        cerr << err.what() << endl;
    }

    return 0;
}
