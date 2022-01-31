/**
 * \file BorneFontaine.h
 * \brief Implementation de la classe BorneFontaine
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 4 avril 2021, 20:11
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H

#include <string>
#include "Borne.h"


using namespace std;
namespace bornesQuebec
{

  /**
   * \class BorneFontaine
   * \brief Classe dérivée de la classe Borne
   */

  class BorneFontaine : public Borne
  {
  public:
    BorneFontaine (const int p_identifiant, const string& p_direction,
                   const string& p_nomTopographique, const double p_longitude,
                   const double p_latitude, const string& p_ville, const string& p_arrondissement);

    ~BorneFontaine () { };
    //Accesseurs
    const string& reqVille () const;
    const string& reqArrondissement () const;


    virtual string reqBorneFormate () const;
    virtual Borne* clone () const;



  private:
    string m_ville;
    string m_arrondissement;
    void verifieInvariant () const;

  };

}

#endif /* BORNEFONTAINE_H */