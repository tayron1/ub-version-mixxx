/***************************************************************************
                          dlgprefmidi.h  -  description
                             -------------------
    begin                : Thu Apr 17 2003
    copyright            : (C) 2003 by Tue & Ken Haste Andersen
    email                : haste@diku.dk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef DLGPREFMIDI_H
#define DLGPREFMIDI_H

#include "dlgprefmididlg.h"
#include "configobject.h"

class QWidget;
class MidiObject;
class PowerMate;
class Mouse;
class Hercules;
class Joystick;
class QProgressDialog;
class QTimer;

/**
  *@author Tue & Ken Haste Andersen
  */

class DlgPrefMidi : public DlgPrefMidiDlg  {
    Q_OBJECT
public:
    DlgPrefMidi(QWidget *parent, ConfigObject<ConfigValue> *pConfig);
    ~DlgPrefMidi();
public slots:
    void slotUpdate();
    void slotApply();
    void slotMouseCalibrate1();
    void slotMouseCalibrate2();
    void slotMouseHelp();
    void slotUpdateProgressBar();
    void slotCancelCalibrate();

signals:
    void apply();

private:
/*    void setupPowerMates();
    void setupMouse();
    void setupJoystick();
    void setupHercules();*/
    
    MidiObject *m_pMidi;
    ConfigObject<ConfigValue> *m_pConfig;
    ConfigObject<ConfigValueMidi> *m_pMidiConfig;
    PowerMate *m_pPowerMate1, *m_pPowerMate2;
    Mouse *m_pMouse1, *m_pMouse2;
    Hercules *m_pHercules;
    Joystick *m_pJoystick;
    QProgressDialog *m_pProgressDialog;
    QTimer *m_pTimer;
    int m_iProgress;
    Mouse *m_pMouseCalibrate;
};

#endif
