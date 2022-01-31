/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RegistreBorneGUI.h
 * Author: etudiant
 *
 * Created on 17 avril 2021, 16:39
 */

#ifndef _REGISTREBORNEGUI_H
#define _REGISTREBORNEGUI_H

#include "ui_RegistreBorneGUI.h"
#include "RegistreBorne.h"

#include <vector>
#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>


using namespace std;
using namespace bornesQuebec;

class RegistreBorneGUI : public QMainWindow
{
  Q_OBJECT
public:
  RegistreBorneGUI (QWidget *parent = 0);
  virtual ~RegistreBorneGUI ();
  void ajouterBorneFontaine (int p_identifiant, const string& p_direction,
                             const string& p_nomTopographique, const double p_longitude,
                             const double p_latitude, const string& p_ville, const string& p_arrondissement);
  void ajouterBorneStationnement (const int p_identifiant, const string& p_direction,
                                  const string& p_nomTopographique, const double p_longitude,
                                  const double p_latitude, const string& p_type, const double p_lectureMetrique,
                                  const int p_segmentRue, const int p_numBorne, const string& p_coteRue);
  void supprimerBorne (int p_identifiant);
public slots:
  void dialogAjouterBorneFontaine ();
  void dialogAjouterBorneStationnement ();
  void dialogSupprimerBorne ();

private:
  Ui::RegistreBorneGUI ui;
  RegistreBorne* m_RegistreBorne;
  bool verifiePresentBorne (const Borne& p_borne);
  bool verifiePresentEmployeBorneSuprim (int p_identifiant);
};

#endif /* _REGISTREBORNEGUI_H */
