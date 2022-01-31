/**
 * \file RegistreBorne.cpp
 * \brief Implementation de la classe RegistreBorne
 * \author bdelhafid El kanfoud et djodji Komlan
 * \date 17 avril 2021, 20:11
 */

#include "ContratException.h"
#include "RegistreBorne.h"
#include "validationFormat.h"
#include "BorneException.h"
#include <vector>
#include <iostream>
#include <sstream>
namespace bornesQuebec
{

  /**
   * \brief Constructeur avec parametres
   *        Création d'un objet RegistreBorne à partir de valeurs passées en paramètres.
   * \param[in] p_nomRegistreBorne un string qui représente la version du Registre.
   * \pre p_type ne doit pas être vide).
   * \post m_nomRegistreBorne prend la valeur de p_nomRegistreBorne
   */
  RegistreBorne::RegistreBorne (const string& p_nomRegistreBorne) :
  m_nomRegistreBorne (p_nomRegistreBorne), m_vBornes ()
  {
    PRECONDITION (!p_nomRegistreBorne.empty ());


    POSTCONDITION (m_nomRegistreBorne == p_nomRegistreBorne);
    POSTCONDITION (m_vBornes.size () == 0);
    INVARIANTS ();
  }

  /**
   * \brief Constructeur copie
   *        Création d'un objet RegistreBorne à partir d'un autre RegistreBorne passées en paramètres.
   * \param[in] p_registreBorne un objet RegistreBorn.
   */

  RegistreBorne::RegistreBorne (const RegistreBorne& p_registreBorne) :
  m_nomRegistreBorne (p_registreBorne.reqNomRegistreBorne ()),
  m_vBornes ()
  {
    copieVecteur (p_registreBorne.reqVBornes ());
  }

  /**
   * \brief destructeur de l'objet RegistreBorne
   */

  RegistreBorne::~RegistreBorne ()
  {
    viderVecteur ();
  }

  /**
   * \brief L’opérateur d'assignation
   * \param[in] p_registreBorne un objet RegistreBorn.
   * \return l'objet courant sous forme de copie profond de l'objet RegistreBorn passé en paramétre.
   */

  const RegistreBorne& RegistreBorne::operator= (const RegistreBorne& p_registreBorne)
  {
    if (this != &p_registreBorne)
      {
        m_nomRegistreBorne = p_registreBorne.reqNomRegistreBorne ();
        viderVecteur ();
        copieVecteur (p_registreBorne.reqVBornes ());
      }
    return *this;
  }

  /**
   * \brief videur de vecteur de l'objet RegistreBorne
   */

  void
  RegistreBorne::viderVecteur ()
  {
    if (m_vBornes.size () > 0)
      {
        vector<Borne* >::const_iterator iter;

        for (iter = m_vBornes.begin (); iter != m_vBornes.end (); iter++)
          {
            delete (*iter);
          }
        m_vBornes.clear ();
      }

  }

  /**
   * \brief copieur du vecteur de l'objet RegistreBorne
   * \param[in] p_vBornes un vecteur des objet Borne.
   */

  void
  RegistreBorne::copieVecteur (const vector<Borne*>& p_vBornes)
  {
    vector<Borne* >::const_iterator iter;
    for (iter = p_vBornes.begin (); iter != p_vBornes.end (); iter++)
      {
        ajouteBorne (*(*iter));
      }
  }

  /**
   * \brief Accesseur pour la version du Registre.
   * \return m_nomRegistreBorne la version du Registre.
   */


  const string&
  RegistreBorne::reqNomRegistreBorne () const
  {

    return m_nomRegistreBorne;
  }

  /**
   * \brief Accesseur pour la version du vecteur.
   * \return m_vBornes le vecteur.
   */

  const vector<Borne*>&
  RegistreBorne::reqVBornes () const
  {

    return m_vBornes;
  }

  /**
   * \brief méthode permet de vérifier si la borne n’est pas déjà dans le vecteur (sur la base de l’identifiant).
   * \param[in] p_borne un objet de typle Borne.
   * \return retourne true si la borne  est déjà dans le vecteuret false dans le cas contraire.
   */

  bool
  RegistreBorne::BorneEstDejaPresente (const Borne & p_borne) const
  {
    bool BornePresente = false;
    vector<Borne* >::const_iterator iter;

    for (iter = m_vBornes.begin (); iter != m_vBornes.end (); iter++)
      {
        if ((*iter)->reqIdentifiant () == p_borne.reqIdentifiant ())
          {

            BornePresente = true;
          }
      }
    return BornePresente;
  }

  /**
   * \brief méthode permet de vérifier si la borne est déjà dans le vecteur (sur la base de l’identifiant)
   *        pour l'utiliser dans les tests de l'operateur d'assignation .
   * \param[in] p_borne un objet de typle Borne.
   * \return retourne true si la borne  est déjà dans le vecteuret false dans le cas contraire.
   */

  bool
  RegistreBorne::verifierBornePresentePourTest (const Borne& p_borne) const
  {

    return BorneEstDejaPresente (p_borne);
  }

  /**
   * \brief méthode permet de vérifier si la borne n'existe pas dans le vecteur (sur la base de l’identifiant)
   * \param[in] p_identifiant lÉ'identifiant de la borne.
   * \return retourne true si la borne  n'est pas le vecteuret false dans le cas contraire.
   */

  bool
  RegistreBorne::BorneAbsente (int p_identifiant) const
  {
    bool estAabsente = true;
    vector<Borne*>::const_iterator iter;
    for (iter = m_vBornes.begin (); iter != m_vBornes.end (); iter++)
      {
        if ((*iter)->reqIdentifiant () == p_identifiant)
          {
            estAabsente = false;
          }
      }
    return estAabsente;

  }

  /**
   * \brief supprime une borne du registre, S’il n’y a pas de Borne qui possède cet identifiant dans le registre, une BorneAbsenteException est lancée
   * \param[in] p_identifiant l’identifiant de la Borne.
   */
  void
  RegistreBorne::supprimeBorne (int p_identifiant)
  {
    if (BorneAbsente (p_identifiant))
      {
        throw BorneAbsenteException ("Aucune borne trouvée dans le registre avec cet identifiant: ");
      }
    else
      {
        vector<Borne*>::const_iterator iter;
        for (iter = m_vBornes.begin (); iter != m_vBornes.end (); ++iter)
          {
            if ((*iter)->reqIdentifiant () == p_identifiant)
              {
                delete (*iter);
                m_vBornes.erase (iter);
                break;

              }
          }
      }
  }

  /**
   * \brief ajouter une borne au vecteur de bornes seulement si la borne n’est pas déjà présente dans cette liste. Autrement, il ne « se passe rien »,
   * \param[in] p_borne un objet de typle Borne.
   */

  void
  RegistreBorne::ajouteBorne (const Borne & p_Borne)
  {

    if (BorneEstDejaPresente (p_Borne))
      {
        throw BorneDejaPresenteException ("Ce Borne est déja enregistré voila ses information\n:" + p_Borne.reqBorneFormate ());
      }
    else
      {

        m_vBornes.push_back (p_Borne.clone ());
      }
  }

  /**
   * \brief Affiche les informations du registre de bornes. sous forme d'une chaîne de caractère formatée
   * \return une chaîne de caractère contient les informations de l'objet
   */

  string
  RegistreBorne::reqRegistreBorneFormate () const
  {
    ostringstream chaine;
    chaine << "Registre : " << reqNomRegistreBorne () << endl;
    vector<Borne*>::const_iterator iter;
    for (iter = m_vBornes.begin (); iter != m_vBornes.end (); iter++)
      {
        chaine << (*iter) ->reqBorneFormate ();
        chaine << "----------------------------------------------\n";

      }
    return chaine.str ();

  }

  /**
   * \brief Vérifie les invariants de la classe
   */

  void
  RegistreBorne::verifieInvariant () const
  {
    INVARIANT (!m_nomRegistreBorne.empty ());

  }
}