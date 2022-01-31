/**
 * \file Borne.h
 * \brief Prototype de la classe Borne
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 04 avril 2021, 20:11
 */

#ifndef BORNE_H
#define BORNE_H


#include <string>

using namespace std;
namespace bornesQuebec
{

  /**
   * \class Borne
   * \brief Classe de base
   **/

  class Borne
  {
  public:
    Borne (const int p_identifiant, const string& p_direction, const string& p_nomTopographique, const double m_longitude, const double m_latitude);

    virtual
    ~Borne () { };
    int reqIdentifiant () const;
    const string& reqDirection () const;
    const string& reqNomTopographique () const;
    double reqLongitude () const;
    double reqLatitude () const;


    void asgNomTopographique (const string& p_nomTopographique);
    bool operator== (const Borne& p_borne) const;

    virtual string reqBorneFormate () const = 0;
    virtual Borne* clone () const = 0;


  private:
    int m_identifiant;
    string m_direction;
    string m_nomTopographique;
    double m_longitude;
    double m_latitude;
    void verifieInvariant () const;

  };

}

#endif /* BORNE_H */
