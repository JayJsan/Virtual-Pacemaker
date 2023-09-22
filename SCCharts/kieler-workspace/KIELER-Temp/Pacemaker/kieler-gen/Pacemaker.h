#ifndef PACEMAKER_H
#define PACEMAKER_H
/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"
#include <stdio.h>


typedef struct {
  int AVI;
  int AEI;
  int PVARP;
  int VRP;
  int LRI;
  int URI;
  double AVI_Clock;
  double VEvents_Clock;
  int _taken_transitions[17];
  char _region0_Main_AVI_Stop;
  char _region0_Main_VEvents_Stop;
  double deltaT;
  double sleepT;
  char AS;
  char VS;
  char AP;
  char VP;
  char AR;
  char VR;
  char _Pacemaker_local__Atrig;
  char _Pacemaker_local__Atrig1;
  char _Pacemaker_local__Atrig2;
  char _Pacemaker_local__Atrig3;
  char _Pacemaker_local__Atrig4;
  char _Pacemaker_local__Atrig5;
  char _Pacemaker_local__Atrig6;
  char _Pacemaker_local__Atrig7;
  char _Pacemaker_local__Atrig8;
  char _Pacemaker_local__Atrig9;
  char _Pacemaker_local__Atrig10;
  char _g17;
  char _g18;
  char _g19;
  char _g60;
  char _g61;
  char _g62;
  char _g115;
  char _g116;
  char _g125;
  char _g126;
  char _g127;
  char _g135;
  char _g136;
  char _g147;
  char _g151;
  char _g159;
  char _GO;
  char _cg5;
  char _cg6;
  char _cg10;
  char _cg9;
  char _cg12;
  char _cg15;
  char _cg21;
  char _cg18;
  char _cg23;
  char _cg26;
  char _cg27;
  char _cg31;
  char _cg30;
  char _cg33;
  char _cg36;
  char _cg37;
  char _cg38;
  char _cg42;
  char _cg41;
  char _cg44;
  char _cg47;
  char _cg48;
  char _cg49;
  char _cg53;
  char _cg52;
  char _cg55;
  char _cg58;
  char _cg66;
  char _cg61;
  char _cg64;
  char _cg68;
  char _cg71;
  char _cg72;
  char _cg76;
  char _cg75;
  char _cg78;
  char _cg81;
  char _cg91;
  char _cg84;
  char _cg87;
  char _cg89;
  char _cg93;
  char _cg95;
  char _cg97;
  char _cg100;
  char _cg110;
  char _cg113;
  char _cg119;
  char _cg126;
  char _cg129;
  char _cg135;
  char _TERM;
  char _pg147;
  char _pg60;
  char _pg159;
  char _pg127;
  char _pg125;
  char _pg17;
  char _pg116;
  char _pg115;
} TickData;

void reset(TickData* d);
void logic(TickData* d);
void tick(TickData* d);

#endif /* !PACEMAKER_H */
