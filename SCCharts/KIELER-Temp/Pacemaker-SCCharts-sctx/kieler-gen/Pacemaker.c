/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"
#include <stdio.h>

#include "Pacemaker.h"

void logic(TickData* d) {
  d->_g151 = d->_pg147;
  if (d->_g151) {
    d->VEvents_Clock += d->deltaT;
  }
  d->_g61 = d->_pg60;
  d->_g61 = d->_g61 && d->VS;
  if (d->_g61) {
    d->_Pacemaker_local__Atrig6 = 1;
  }
  d->_g62 = d->_pg159;
  d->_g159 = d->_GO || d->_g62;
  if (d->_g159) {
    d->AP = 0;
    d->VP = 0;
    d->AR = 0;
    d->VR = 0;
  }
  d->sleepT = 1000.0;
  d->_g135 = d->_pg127;
  d->_cg135 = !d->_region0_Main_VEvents_Stop;
  d->_g136 = d->_g135 && d->_cg135;
  if (d->_g136) {
    d->_Pacemaker_local__Atrig10 = 1;
  }
  d->_g136 = d->_pg125;
  d->_cg126 = d->_region0_Main_VEvents_Stop;
  d->_g126 = d->_g136 && d->_cg126;
  if (d->_g126) {
    d->_taken_transitions[15] += 1;
    d->_Pacemaker_local__Atrig10 = 0;
  }
  d->_g127 = d->_g126 || d->_g135 && !d->_cg135;
  d->_g135 = d->_pg17;
  d->_g18 = d->_g135 && d->AS;
  if (d->_g18) {
    d->_Pacemaker_local__Atrig = 1;
  }
  d->_g19 = d->_pg116;
  if (d->_g19) {
    d->AVI_Clock += d->deltaT;
  }
  d->_g116 = d->_pg115;
  if (d->_g116) {
    d->AVI_Clock = 0;
  }
  d->_g116 = d->_GO || d->_g19;
  d->_g147 = d->_GO || d->_g151;
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->AVI = AVI_VALUE;
  d->AEI = AEI_VALUE;
  d->PVARP = PVARP_VALUE;
  d->VRP = VRP_VALUE;
  d->LRI = LRI_VALUE;
  d->URI = URI_VALUE;
  d->AVI_Clock = 0;
  d->VEvents_Clock = 0;
  d->_region0_Main_AVI_Stop = 1;
  d->_region0_Main_VEvents_Stop = 1;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->_taken_transitions[0] = 0;
  d->_taken_transitions[1] = 0;
  d->_taken_transitions[2] = 0;
  d->_taken_transitions[3] = 0;
  d->_taken_transitions[4] = 0;
  d->_taken_transitions[5] = 0;
  d->_taken_transitions[6] = 0;
  d->_taken_transitions[7] = 0;
  d->_taken_transitions[8] = 0;
  d->_taken_transitions[9] = 0;
  d->_taken_transitions[10] = 0;
  d->_taken_transitions[11] = 0;
  d->_taken_transitions[12] = 0;
  d->_taken_transitions[13] = 0;
  d->_taken_transitions[14] = 0;
  d->_taken_transitions[15] = 0;
  d->_taken_transitions[16] = 0;
  d->_pg147 = 0;
  d->_pg60 = 0;
  d->_pg159 = 0;
  d->_pg127 = 0;
  d->_pg125 = 0;
  d->_pg17 = 0;
  d->_pg116 = 0;
  d->_pg115 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg147 = d->_g147;
  d->_pg60 = d->_g60;
  d->_pg159 = d->_g159;
  d->_pg127 = d->_g127;
  d->_pg125 = d->_g125;
  d->_pg17 = d->_g17;
  d->_pg116 = d->_g116;
  d->_pg115 = d->_g115;
  d->_GO = 0;
}
