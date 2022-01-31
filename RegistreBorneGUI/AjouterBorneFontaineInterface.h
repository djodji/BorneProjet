/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterBorneFontaineInterface.h
 * Author: etudiant
 *
 * Created on 18 avril 2021, 22:45
 */

#ifndef _AJOUTERBORNEFONTAINEINTERFACE_H
#define _AJOUTERBORNEFONTAINEINTERFACE_H

#include "ui_AjouterBorneFontaineInterface.h"

class AjouterBorneFontaineInterface : public QDialog
{
  Q_OBJECT
public:
  AjouterBorneFontaineInterface (QWidget *parent = 0);
  virtual ~AjouterBorneFontaineInterface ();
  int reqIdentifiant () const;
  QString reqDirection () const;
  QString reqNomTopographique () const;
  double reqLongitude () const;
  double reqLatitude () const;
  QString reqVille () const;
  QString reqArrondissement () const;
public slots:
  void validerChamps ();
private:
  Ui::AjouterBorneFontaineInterface widget;
};

#endif /* _AJOUTERBORNEFONTAINEINTERFACE_H */
