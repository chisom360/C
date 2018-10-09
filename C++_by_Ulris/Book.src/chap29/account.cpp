// ----------------------------------------------------
// account.cpp:  Implements methods of the classes
//               Account, DepAcc, SavAcc and AccFile. 
// ----------------------------------------------------
 
#include "account.h"
 
ostream& Account::write(ostream& os) const
{
   os << name << '\0';
   
   os.write((char*)&nr, sizeof(nr) );
   os.write((char*)&balance, sizeof(balance) );
 
   return os;
}

istream& Account::read(istream& is)
{
   getline( is, name, '\0');

   is.read((char*)&nr, sizeof(nr) );
   is.read((char*)&balance, sizeof(balance));

   return is;
}

ostream& DepAcc::write(ostream& os) const
{
   if(!Account::write(os))
       return os;
    
   os.write((char*)&limit, sizeof(limit) );
   os.write((char*)&interest, sizeof(interest) );

   return os;   
}

istream& DepAcc::read(istream& is)
{
   if(!Account::read(is))
       return is;

   is.read((char*)&limit, sizeof(limit) );
   is.read((char*)&interest, sizeof(interest));
   
   return is;
} 


ostream& SavAcc::write(ostream& os) const
{
   if(!Account::write(os))
       return os;
   os.write((char*)&interest, sizeof(interest) );
    
   return os;   
}
 
istream& SavAcc::read(istream& is)
{
   if(!Account::read(is))
       return is;
   is.read((char*)&interest, sizeof(interest) );

   return is;
}


// ---------------------------------------------------
// Methods of class AccFile
// ---------------------------------------------------

AccFile::AccFile(const string& s) throw(OpenError)
{
    ios::openmode mode = ios::in | ios::out | ios::app | ios::binary;
    f.open( s.c_str(), mode );
   
    if(!f)
        throw OpenError(s);
    else  
        name = s;
}

void AccFile::display() throw(ReadError)
{
    Account acc, *pAcc = NULL;
    DepAcc depAcc;
    SavAcc savAcc;
    TypeId id;
 
    if(!f.seekg(0L))
       throw ReadError(name);
     
    cout << "\nThe account file: " << endl;

    while( f.read((char*)&id, sizeof(TypeId)) )
    {
       switch(id)
       {
          case ACCOUNT:  pAcc = &acc;
                         break; 
          case DEP_ACC:  pAcc = &depAcc;
                         break; 
          case SAV_ACC:  pAcc = &savAcc;
                         break; 
                        
          default: cerr << "Invalid flag in account file" << endl; 
                   exit(1);
       } 
  
       if(!pAcc->read(f))
          break;

       pAcc->display();
       cin.get();             // Go on with return
    }
 
    if( !f.eof())
        throw ReadError(name);
    
    f.clear();
}

long AccFile::append( Account& acc) throw( WriteError)
{
   f.seekp(0L, ios::end);     // Seek to end,
   long pos = f.tellp();      // save the position.

   if( !f ) 
      throw WriteError(name);

   TypeId id = acc.getTypeId();
   f.write( (char*)&id, sizeof(id));  // Write the TypeId

   if(!f)
       throw WriteError(name);
   else
       acc.write(f);        // Add an object to the file. 

   if(!f)
       throw WriteError(name);
   else
       return pos;
}

Account* AccFile::retrieve( long pos) throw(ReadError)
{
    f.clear();
    f.seekg(pos);                   // Set the get pointer
    
    if( !f )
       throw ReadError(name);

    TypeId id;
    f.read( (char*)&id, sizeof(id) );     // Get TypeId
    
    if(!f)
       throw ReadError(name);
      
    Account* buf;
    switch( id )
    {
      case ACCOUNT:  buf = new Account;
                     break;
      case SAV_ACC:  buf = new SavAcc; 
                     break;
      case DEP_ACC:  buf = new DepAcc; 
                     break;
    }

    if( !(buf->read(f)))                  // Get data
       throw ReadError(name);

    return buf;
}
