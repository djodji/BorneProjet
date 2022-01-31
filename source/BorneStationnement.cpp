/**
 * \file Borne.cpp
 * \brief Implementation de la classe Borne
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 22 février 2021, 20:11
 */

#include "ContratException.h"
#include "BorneStationnement.h"
#include "validationFormat.h"
#include <iostream>
#include <sstream>
namespace bornesQuebec
{

  /**
   * \brief Constructeur avec parametres
   *        Création d'un objet Borne à partir de valeurs passées en paramètres.
   * \param[in] p_identifiant un entier qui représente L’identifiant de la borne.
   * \param[in] p_direction un string qui représente Le côté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   * \param[in] p_nomTopographique un string qui représente Le nom topographique (générique, liaison, spécifique, direction) du centre de chaussée.
   * \param[in] p_longitude un nombre réel qui représente La longitude.
   * \param[in] p_latitude un nombre réel qui représente Le coté par rapport au centre de chaussée ou l’intersection dans le cas d’un terre-plein.
   * \param[in] p_type un string représente Le type de borne de stationnement
   * \param[in] p_lectureMetrique un nombre réel, représente la distance mesurée à partir du début du tronçon dans le sens des numéros d'immeuble.
   * \param[in] p_segmentRue un nombre entier qui représente L’identifiant du segment de voie publique.
   * \param[in] p_numBorne un entier Le numéro de la borne.
   * \param[in] p_coteRue un string représente le coté par rapport au centre de chaussée où est la borne.
   * \pre p_type doit être soit « stationnement », soit « paiement ».
   * \pre p_lectureMetrique doit être plus grand que 0.
   * \pre p_numBorne doit être composé de 1 à 4 chiffres.
   * \pre p_coteRue Il doit correspondre à un point cardinal.
   * \post m_type prend la valeur de p_type
   * \post m_lectureMetrique prend la valeur de p_lectureMetrique
   * \post m_segmentRue prend la valeur de p_segmentRue
   * \post m_numBorne prend la valeur de p_numBorne
   * \post m_coteRue prend la valeur de p_coteRue
   */

  BorneStationnement::BorneStationnement (const int p_identifiant, const string& p_direction,
                                          const string& p_nomTopographique, const double p_longitude,
                                          const double p_latitude, const string& p_type, const double p_lectureMetrique,
                                          const int p_segmentRue, const int p_numBorne, const string& p_coteRue) :
  Borne (p_identifiant, p_direction, p_nomTopographique, p_longitude, p_latitude),
  m_type (p_type), m_lectureMetrique (p_lectureMetrique), m_segmentRue (p_segmentRue), m_numBorne (p_numBorne), m_coteRue (p_coteRue)
  {
    PRECONDITION (p_type == "stationnement" || p_type == "paiement");
    PRECONDITION (p_lectureMetrique > 0);
    PRECONDITION (p_segmentRue > 0);
    PRECONDITION (p_numBorne >= 0 && p_numBorne <= 9999);
    PRECONDITION (util::validerPointCardinal (p_coteRue));


    POSTCONDITION (m_type == p_type);
    POSTCONDITION (m_lectureMetrique == p_lectureMetrique);
    POSTCONDITION (m_segmentRue == p_segmentRue);
    POSTCONDITION (m_numBorne == p_numBorne);
    POSTCONDITION (m_coteRue == p_coteRue);
    INVARIANTS ();
  }

  /**
   * \brief Accesseur pour le type de borne.
   * \return m_type le type de borne.
   */

  const string&
  BorneStationnement::reqType () const
  {
    return m_type;
  }

  /**
   * \brief Accesseur pour la distance mesurée à partir du début du tronçon dans le sens des numérosd'immeuble.
   * \return m_lectureMetrique la distance mesurée à partir du début du tronçon dans le sens des numérosd'immeuble.
   */

  double
  BorneStationnement::reqLectureMetrique () const
  {
    return m_lectureMetrique;
  }

  /**
   * \brief Accesseur l’identifiant du segment de voie publique.
   * \return m_segmentRue l’identifiant du segment.
   */

  int
  BorneStationnement::reqSegmentRue () const
  {
    return m_segmentRue;
  }

  /**
   * \brief Accesseur pour la distance mesurée à partir du début du tronçon dans le sens des numérosd'immeuble.
   * \return m_numBorne lla distance mesurée à partir du début du tronçon dans le sens des numérosd'immeuble.
   */

  int
  BorneStationnement::reqNumBorne () const
  {
    return m_numBorne;
  }

  /**
   * \brief Accesseur pour le numéro de la borne.
   * \return m_coteRue le numéro de la borne.
   */

  const string&
  BorneStationnement::reqCoteRue () const
  {
    return m_coteRue;
  }

  /**
   * \brief faire une copie allouée sur le monceau de l'objet BorneStationnement courant.
   * \return une copie allouée sur le monceau de l'objet BorneStationnement courant.
   */

  Borne*
  BorneStationnement::clone () const
  {
    return new BorneStationnement (*this);
  }

  /**
   * \brief Affiche les informations de l'objet Borne de stationnement sous forme d'une chaîne de caractère formatée
   * \return une chaîne de caractère contient les informations de l'objet
   */

  string
  BorneStationnement::reqBorneFormate () const
  {
    ostringstream chaine;
    chaine << "Borne de stationnement\n"
            << "----------------------------------------------\n"
            << Borne::reqBorneFormate ()
            << "Distance mesuree    : " << m_lectureMetrique
            << "\nSegment de rue\t    : " << m_segmentRue
            << "\nNumero de la borne  : " << m_numBorne
            << "\nCote de la rue\t    : " << m_coteRue << endl;
    return chaine.str ();
  }

  /**
   * \brief Vérifie les invariants de la classe
   */

  void
  BorneStationnement::verifieInvariant () const
  {
    INVARIANT (m_type == "stationnement" || m_type == "paiement");
    INVARIANT (m_lectureMetrique > 0);
    INVARIANT (m_segmentRue > 0);
    INVARIANT (m_numBorne >= 0 && m_numBorne <= 9999);
    INVARIANT (util::validerPointCardinal (m_coteRue));

  }
}