/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjouterBorneStationnementInterface.h
 * Author: etudiant
 *
 * Created on 18 avril 2021, 21:45
 */

#ifndef _AJOUTERBORNESTATIONNEMENTINTERFACE_H
#define _AJOUTERBORNESTATIONNEMENTINTERFACE_H

#include "ui_AjouterBorneStationnementInterface.h"

class AjouterBorneStationnementInterface : public QDialog
{
  Q_OBJECT
public:
  AjouterBorneStationnementInterface (QWidget *parent = 0);
  virtual ~AjouterBorneStationnementInterface ();
  int reqIdentifiant () const;
  QString reqDirection () const;
  QString reqNomTopographique () const;
  double reqLongitude () const;
  double reqLatitude () const;
  QString reqType () const;
  double reqLectureMetrique () const;
  int reqSegmentRue () const;
  int reqNumBorne () const;
  QString reqCoteRue () const;

public slots:
  void validerChamps ();

private:
  Ui::AjouterBorneStationnementInterface widget;
};

#endif /* _AJOUTERBORNESTATIONNEMENTINTERFACE_H */
