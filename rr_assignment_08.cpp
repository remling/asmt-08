/* ------------------    Source File of Assignment 8 : Option A ---------------
                          Roswitha Remling -- Nov 19, 2012                   */

//--------------------------includes and namespace ----------------------------
#include <iostream>
#include <string>
#include <sstream>                                                /// not sure I need this! YET
using namespace std; 

// ------------------------- DateProfile class prototype ----------------------
class DateProfile
{
private:
   char gender, searchGender;
   int romance, finance;
   string name;
public:
   static const char DEFAULT_CHAR;
   static const char FEMALE;
   static const char MALE;
   static const int DEFAULT_INT;
   static const int MIN_INT;
   static const int MAX_INT;
   static const string DEFAULT_STRING;
   static const int MIN_STRING;
   static const int MAX_STRING;

   // (default) constructor(s)
   DateProfile();
   DateProfile(char gender, char searchGender, int romance, int finance, string name);
   // accessors
   char getGender() { return gender; }
   char getSearchGender() {return searchGender; }
   int getRomance() { return romance; }
   int getFinance() { return finance; }
   string getName() { return name; }
   // other mutators
   bool setGender(char gender);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance); 
   bool setName(string name);
   double fitValue(DateProfile partner);
private: 
   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinacneFit(DateProfile partner);
};
// ----- set constant(s) aka static member initialization ---------------------
   char const DateProfile::DEFAULT_CHAR = 'X';
   char const DateProfile::MALE = 'M';
   char const DateProfile::FEMALE = 'F';
   int const DateProfile::DEFAULT_INT = -1;
   int const DateProfile::MIN_INT = 0;
   int const DateProfile::MAX_INT= 10;
   string const DateProfile::DEFAULT_STRING = "(undefined)";
   int const DateProfile::MIN_STRING = 2;
   int const DateProfile::MAX_STRING = 80;

// ----------------------- main method definition  ----------------------------
int main()
{
   //set max array size
   int max_size = 10;
   // declare array and populate
   DateProfile applicant1('F', 'M', 3, 5, "rr");
   applicant1.setGender('M');
   applicant1.setSearchGender('F');
   applicant1.setName("cccc");
   cout << "gender: " << applicant1.getGender() << "  searchGender: " << applicant1.getSearchGender()
      << "   romance: " << applicant1.getRomance() << "    finance:   " << applicant1.getFinance()
      << "   name :   " << applicant1.getName() << endl << endl;
   return 0;
}
// --------------DateProfile class member method definitions ------------------
// (default) constructor(s)
DateProfile::DateProfile()      // default
{
   gender = searchGender = DEFAULT_CHAR;
   romance = finance = DEFAULT_INT;
   name = DEFAULT_STRING;
}
DateProfile::DateProfile(char gender, char searchGender, int romance, 
   int finance, string name)
{
  if ( !setGender(gender) )
      this->gender = DEFAULT_CHAR;
  if ( !setSearchGender(searchGender) )
      this->searchGender = DEFAULT_CHAR;
  if ( !setRomance(romance) )
     this-> romance = DEFAULT_INT;
  if ( !setFinance(finance) )
      this->finance = DEFAULT_INT;
  if ( !setName(name))
      this->name = DEFAULT_STRING;
}
// other mutators (sets)
bool DateProfile::setGender(char gender)
{
   if ( (gender != FEMALE) && (gender != MALE) )
      return false;
   this->gender = gender;
   return true;
}
bool DateProfile::setSearchGender(char searchGender)
{
   if ( (searchGender != FEMALE) && (searchGender != MALE) )
      return false;
   this->searchGender = searchGender;
   return true;
}
bool DateProfile::setRomance(int romance)
{
   if ( (romance < MIN_INT) || (romance > MAX_INT) )
      return false;
   this->romance = romance;
   return true;
}
bool DateProfile::setFinance(int finance)
{
   if ( (finance < MIN_INT) || (finance > MAX_INT) )
      return false;
   this->finance = finance;
   return true;
}
bool DateProfile::setName(string name)
{
   if ( (name.length() < MIN_STRING) || (name.length() > MAX_STRING) )
      return false;
   this->name = name;
   return true;
}
/* --------------------- Sample Test Run --------------------------------------


-----------------------------------------------------------------------------*/