
/**
 * \file BorneStationnement.h
 * \brief Implementation de la classe BorneFontaine
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 4 avril 2021, 20:11
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H


#include <string>
#include "Borne.h"

using namespace std;
namespace bornesQuebec
{

  /**
   * \class BorneStationnement
   * \brief Classe dérivée de la classe Borne
   */

  class BorneStationnement : public Borne
  {
  public:

    BorneStationnement (const int p_identifiant, const string& p_direction,
                        const string& p_nomTopographique, const double p_longitude,
                        const double p_latitude, const string& p_type, const double p_lectureMetrique,
                        const int p_segmentRue, const int p_numBorne, const string& p_coteRue);

    ~BorneStationnement () { };

    //Accesseurs
    const string& reqType () const;
    double reqLectureMetrique () const;
    int reqSegmentRue () const;
    int reqNumBorne () const;
    const string& reqCoteRue () const;

    virtual Borne* clone () const;
    virtual string reqBorneFormate () const;


  private:
    string m_type;
    double m_lectureMetrique;
    int m_segmentRue;
    int m_numBorne;
    string m_coteRue;
    void verifieInvariant () const;

  };

}



#endif /* BORNESTATIONNEMENT_H */

