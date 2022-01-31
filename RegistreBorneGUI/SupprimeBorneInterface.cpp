/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SupprimeBorneInterface.cpp
 * Author: etudiant
 *
 * Created on 18 avril 2021, 04:20
 */

#include "SupprimeBorneInterface.h"
#include <qmessagebox.h>

SupprimeBorneInterface::SupprimeBorneInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}

SupprimeBorneInterface::~SupprimeBorneInterface () { }

int
SupprimeBorneInterface::reqIdentifiant () const
{
  return widget.txtIdentifiant->value ();
}

void
SupprimeBorneInterface::validerIdentifiant ()
{

  if (widget.txtIdentifiant->value () < 0)
    {
      QString message (" La direction est non valide.\n");
      QMessageBox::information (this, "ERREUR", message);
    }

  else
    {
      accept ();
    }
}

