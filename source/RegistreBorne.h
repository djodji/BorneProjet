
/**
 * \file RegistreBorne.h
 * \brief Implementation de la classe BorneFontaine
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 4 avril 2021, 20:11
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H

#include <string>
#include "Borne.h"
#include <vector>

using namespace std;
namespace bornesQuebec
{

  /**
   * \class RegistreBorne
   * \brief Cette class permet la gestion des bornes-fontaines et de stationnement.
   **/

  class RegistreBorne
  {
  public:

    RegistreBorne (const string& p_nomRegistreBorne);
    RegistreBorne (const RegistreBorne& p_registreBorne);
    const RegistreBorne& operator= (const RegistreBorne& p_registreBorne);

    const string& reqNomRegistreBorne () const;
    void ajouteBorne (const Borne& p_Borne);
    const vector<Borne*>& reqVBornes () const;
    string reqRegistreBorneFormate () const;

    ~RegistreBorne ();
    bool verifierBornePresentePourTest (const Borne& p_borne) const;
    void supprimeBorne (int p_identifiant);

  private:
    string m_nomRegistreBorne;
    vector<Borne*> m_vBornes;
    void viderVecteur ();
    void copieVecteur (const vector<Borne*>& m_vBornes);
    bool BorneEstDejaPresente (const Borne& p_borne) const;
    bool BorneAbsente (int p_identifiant) const;
    void verifieInvariant () const;

  };

}



#endif /* REGISTREBORNE_H */


