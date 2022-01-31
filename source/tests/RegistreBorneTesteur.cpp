/**
 * \file RegistreBorneTesteur.cpp
 * \brief Implantation des tests unitaires de la classe RegistreBorne
 * \author Abdelhafid El kanfoud
 * \date 4 avril 2011 * \date 2 juin 2011
 */

#include <gtest/gtest.h>
#include "ContratException.h"
#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneException.h"
using namespace std;
using namespace bornesQuebec;

/**
 * \brief Test du Constructeur
 *        Cas valides: Création d'un objet RegistreBorne et verification de l’assignation de tous les attributs
 * 	  Cas invalides:
 * 			version du Registre vide
 */

TEST (RegistreBorne, ConstructeurDefaut)
{
  RegistreBorne unRegistreBorne ("Québec centre 2020");
  ASSERT_EQ ("Québec centre 2020", unRegistreBorne.reqNomRegistreBorne ());

}
//cas invalide

TEST (RegistreBorne, ConstructeurNomRegistreBorneInvalide)
{
  ASSERT_THROW (RegistreBorne unRegistreBorne (""), PreconditionException);
}

/**
 * \class unRegistreBorne
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe  RegistreBorne
 */
class unRegistreBorne : public ::testing::Test
{
public:

  unRegistreBorne () :
  f_registre ("Québec centre 2021") { }
  ;

  RegistreBorne f_registre;

};

/**
 * \brief Test du Constructeur copie
 *        Cas valides: Création d'un objet RegistreBorne et verification de l’assignation de tous les attributs
 * 	  Cas invalides: aucun
 */
TEST_F (unRegistreBorne, constructeurCopie)
{
  RegistreBorne registreCopie (f_registre);
  ASSERT_EQ (registreCopie.reqNomRegistreBorne (), f_registre.reqNomRegistreBorne ());
  ASSERT_EQ (registreCopie.reqVBornes (), f_registre.reqVBornes ());
}

/**
 * \test Test de l'operateur d'assignation
 *     Cas valide: vérifier f_registre aprés l'assignation d'un registre p_registre au registre f_registre.
 *                 vérifier p_registre aprés l'assignation d'un registre p_registre à lui-même.
 *                 vérifier p_registre aprés l'assignation d'un registre p_registre au registre f_registre.
 *     Cas invalide: aucun
 */

TEST_F (unRegistreBorne, AssignationRegistreARegistre)
{
  RegistreBorne p_registre ("Québec centre 2020");
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  p_registre.ajouteBorne (f_borne);
  f_registre = p_registre;
  ASSERT_EQ (f_registre.reqNomRegistreBorne (), p_registre.reqNomRegistreBorne ());
  ASSERT_EQ (f_registre.reqVBornes ().size (), p_registre.reqVBornes ().size ());
  ASSERT_TRUE (f_registre.verifierBornePresentePourTest (f_borne));
}

TEST_F (unRegistreBorne, AssignationRegistreALuiMeme)
{
  RegistreBorne p_registre ("Québec centre 2020");
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  p_registre.ajouteBorne (f_borne);
  p_registre = p_registre;
  ASSERT_EQ (p_registre.reqNomRegistreBorne (), p_registre.reqNomRegistreBorne ());
  ASSERT_EQ (p_registre.reqVBornes ().size (), p_registre.reqVBornes ().size ());
  ASSERT_TRUE (p_registre.verifierBornePresentePourTest (f_borne));
}

TEST_F (unRegistreBorne, egistreApresAssignationAutreRegistre)
{
  RegistreBorne p_registre ("Québec centre 2020");
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  p_registre.ajouteBorne (f_borne);
  f_registre = p_registre;
  ASSERT_EQ (p_registre.reqNomRegistreBorne (), p_registre.reqNomRegistreBorne ());
  ASSERT_EQ (p_registre.reqVBornes ().size (), p_registre.reqVBornes ().size ());
  ASSERT_TRUE (p_registre.verifierBornePresentePourTest (f_borne));
}
//const RegistreBorne& RegistreBorne::operator== (const RegistreBorne& p_registreBorne)

/**
 * \test Test de la méthode reqNomRegistreBorne()
 *     Cas valide: vérifier le retour de la version du Registre
 *     Cas invalide: aucun
 */

TEST_F (unRegistreBorne, reqNomRegistreBorne)
{
  ASSERT_EQ ("Québec centre 2021", f_registre.reqNomRegistreBorne ());
}

/**
 * \test Test de la méthode reqVBornes()
 *     Cas valide: vérifier la capacité du vecteur
 *     Cas invalide: aucun
 */

TEST_F (unRegistreBorne, reqVBornes)
{
  ASSERT_EQ (0, f_registre.reqVBornes ().size ());
}

/**
 * \test Test de la méthode void ajouteBorne (const Borne& p_Borne);
 * 		Cas valide: l'ajout d'un objets Bornes si n'est pas déja ajouter
 * 		Cas invalide:   l'ajout d'un objets Bornes déja ajouter

 */

TEST_F (unRegistreBorne, ajouteNouveauBorne)
{
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  f_registre.ajouteBorne (f_borne);
  ASSERT_EQ (1, f_registre.reqVBornes ().size ());
}
//cas invalide

TEST_F (unRegistreBorne, ajouteBorneExistant)
{
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  f_registre.ajouteBorne (f_borne);
  ASSERT_THROW (f_registre.ajouteBorne (f_borne), BorneDejaPresenteException);
}

/**
 * \test Test de la méthode void supprimeBorne (int p_identifiant);
 * 		Cas valide: suprimer un objets Bornes existe déja dans le registre
 * 		Cas invalide:   suprimer un objets Bornes qui n'existe pas dans le registre

 */

TEST_F (unRegistreBorne, supprimerBorneExistant)
{
  BorneFontaine f_borne (4598, "Sud", "3040 rue de la fone", 123655.32, 123365.332, "Québec", "Charlesbourg");
  f_registre.ajouteBorne (f_borne);
  ASSERT_EQ (1, f_registre.reqVBornes ().size ());
  f_registre.supprimeBorne (4598);
  ASSERT_EQ (0, f_registre.reqVBornes ().size ());

}
//cas invalide

TEST_F (unRegistreBorne, supprimerBorneAbsant)
{
  ASSERT_THROW (f_registre.supprimeBorne (1), BorneAbsenteException);
}


