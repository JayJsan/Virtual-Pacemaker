/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"

#include "Pacemaker.h"

void logic(TickData* d) {
  d->_g127 = d->_pg66;
  if (d->_g127) {
    d->AVI_Clock += d->deltaT;
  }
  d->_g70 = d->_pg44;
  d->_g64 = d->_pg38;
  d->_g67_e1 = !(d->_g70 || d->_g64);
  d->_g123 = d->_pg96;
  if (d->_g123) {
    d->PVARP_Clock += d->deltaT;
  }
  d->_g85 = d->_pg97;
  d->_cg85 = d->AS == 1 && d->PVARP_Clock >= d->PVARP;
  d->_g86 = d->_g85 && d->_cg85;
  if (d->_g86) {
    d->_Pacemaker_local__Atrig = 1;
  }
  d->_g111 = d->_pg58;
  if (d->_g111) {
    d->AEI_Clock += d->deltaT;
  }
  d->_g88 = d->_g85 && !d->_cg85;
  d->_cg88 = d->AS == 0 && d->AEI_Clock >= d->AEI;
  d->_g89 = d->_g88 && d->_cg88;
  if (d->_g89) {
    d->_Pacemaker_local__Atrig1 = 1;
  }
  d->_g88 = d->_g88 && !d->_cg88;
  d->_cg90 = d->AS == 1;
  d->_g91 = d->_g88 && d->_cg90;
  if (d->_g91) {
    d->_Pacemaker_local__Atrig2 = 1;
  }
  d->sleepT = 1000.0;
  d->_g70 = d->_g64 || d->_g70;
  d->_cg65 = d->AEI_Clock < d->AEI;
  d->_g64 = d->_g70 && d->_cg65;
  if (d->_g64) {
    d->sleepT = (d->sleepT < (d->AEI - d->AEI_Clock)) ? d->sleepT : (d->AEI - d->AEI_Clock);
  }
  d->_cg66 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g65 = d->_g70 && !d->_cg65;
  d->_cg68 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g67 = d->_g64 && d->_cg66 || d->_g65 && d->_cg68;
  d->_g81 = d->_pg57;
  d->_g75 = d->_pg55;
  d->_g78_e2 = !(d->_g81 || d->_g75);
  d->_g81 = d->_g75 || d->_g81;
  d->_cg76 = d->PVARP_Clock < d->PVARP;
  d->_g75 = d->_g81 && d->_cg76;
  if (d->_g75) {
    d->sleepT = (d->sleepT < (d->PVARP - d->PVARP_Clock)) ? d->sleepT : (d->PVARP - d->PVARP_Clock);
  }
  d->_cg77 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g76 = d->_g81 && !d->_cg76;
  d->_cg79 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g78 = d->_g75 && d->_cg77 || d->_g76 && d->_cg79;
  d->_g85 = !d->_g85;
  d->_g91 = d->_g86 || d->_g89 || d->_g91;
  d->_g89 = (d->_g67_e1 || d->_g67) && (d->_g78_e2 || d->_g78) && (d->_g85 || d->_g91) && (d->_g67 || d->_g78 || d->_g91);
  d->_cg92 = d->_Pacemaker_local__Atrig;
  d->_g86 = d->_g89 && d->_cg92;
  if (d->_g86) {
    d->_taken_transitions[0] += 1;
  }
  d->_g87 = d->_pg67_e1;
  d->_g67_e1 = d->_GO || d->_g87;
  if (d->_g67_e1) {
    d->AP = 0;
    d->VP = 0;
  }
  d->_g87_e3 = d->_g89 && !d->_cg92;
  d->_cg94 = d->_Pacemaker_local__Atrig1;
  d->_g67 = d->_g87_e3 && d->_cg94;
  if (d->_g67) {
    d->AP |= 1;
    d->_taken_transitions[1] += 1;
  }
  d->_g78 = d->_pg32;
  d->_g78_e2 = d->_pg10;
  d->_g135 = !(d->_g78 || d->_g78_e2);
  d->_g92 = d->_pg59;
  if (d->_g92) {
    d->URI_Clock += d->deltaT;
  }
  d->_g50 = d->_pg20;
  d->_cg50 = d->VS == 0 && d->AVI_Clock >= d->AVI && d->URI_Clock >= d->URI;
  d->_g51 = d->_g50 && d->_cg50;
  if (d->_g51) {
    d->_Pacemaker_local__Atrig3 = 1;
  }
  d->_g107 = d->_pg99;
  if (d->_g107) {
    d->VRP_Clock += d->deltaT;
  }
  d->_g53 = d->_g50 && !d->_cg50;
  d->_cg53 = d->VS == 1 && d->VRP_Clock >= d->VRP;
  d->_g54 = d->_g53 && d->_cg53;
  if (d->_g54) {
    d->_Pacemaker_local__Atrig4 = 1;
  }
  d->_g115 = d->_pg94;
  if (d->_g115) {
    d->LRI_Clock += d->deltaT;
  }
  d->_g53 = d->_g53 && !d->_cg53;
  d->_cg55 = d->VS == 0 && d->LRI_Clock >= d->LRI;
  d->_g56 = d->_g53 && d->_cg55;
  if (d->_g56) {
    d->_Pacemaker_local__Atrig5 = 1;
  }
  d->_g13 = d->_g78_e2 || d->_g78;
  d->_cg8 = d->VRP_Clock < d->VRP;
  d->_g7 = d->_g13 && d->_cg8;
  if (d->_g7) {
    d->sleepT = (d->sleepT < (d->VRP - d->VRP_Clock)) ? d->sleepT : (d->VRP - d->VRP_Clock);
  }
  d->_cg9 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g8 = d->_g13 && !d->_cg8;
  d->_cg11 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g10 = d->_g7 && d->_cg9 || d->_g8 && d->_cg11;
  d->_g24 = d->_pg32_e3;
  d->_g18 = d->_pg21_e2;
  d->_g21_e2 = !(d->_g24 || d->_g18);
  d->_g24 = d->_g18 || d->_g24;
  d->_cg19 = d->LRI_Clock < d->LRI;
  d->_g18 = d->_g24 && d->_cg19;
  if (d->_g18) {
    d->sleepT = (d->sleepT < (d->LRI - d->LRI_Clock)) ? d->sleepT : (d->LRI - d->LRI_Clock);
  }
  d->_cg20 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g19 = d->_g24 && !d->_cg19;
  d->_cg22 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g21 = d->_g18 && d->_cg20 || d->_g19 && d->_cg22;
  d->_g35 = d->_pg5;
  d->_g29 = d->_pg93;
  d->_g32_e3 = !(d->_g35 || d->_g29);
  d->_g35 = d->_g29 || d->_g35;
  d->_cg30 = d->URI_Clock < d->URI;
  d->_g29 = d->_g35 && d->_cg30;
  if (d->_g29) {
    d->sleepT = (d->sleepT < (d->URI - d->URI_Clock)) ? d->sleepT : (d->URI - d->URI_Clock);
  }
  d->_cg31 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g30 = d->_g35 && !d->_cg30;
  d->_cg33 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g32 = d->_g29 && d->_cg31 || d->_g30 && d->_cg33;
  d->_g46 = d->_pg16;
  d->_g40 = d->_pg11;
  d->_g43_e4 = !(d->_g46 || d->_g40);
  d->_g40 = d->_g40 || d->_g46;
  d->_cg41 = d->AVI_Clock < d->AVI;
  d->_g46 = d->_g40 && d->_cg41;
  if (d->_g46) {
    d->sleepT = (d->sleepT < (d->AVI - d->AVI_Clock)) ? d->sleepT : (d->AVI - d->AVI_Clock);
  }
  d->_cg42 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g41 = d->_g40 && !d->_cg41;
  d->_cg44 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g43 = d->_g46 && d->_cg42 || d->_g41 && d->_cg44;
  d->_g50 = !d->_g50;
  d->_g51 = d->_g51 || d->_g54 || d->_g56;
  d->_g56 = (d->_g135 || d->_g10) && (d->_g21_e2 || d->_g21) && (d->_g32_e3 || d->_g32) && (d->_g43_e4 || d->_g43) && (d->_g50 || d->_g51) && (d->_g10 || d->_g21 || d->_g32 || d->_g43 || d->_g51);
  d->_cg57 = d->_Pacemaker_local__Atrig3;
  d->_g54 = d->_g56 && !d->_cg57;
  d->_cg97 = d->_Pacemaker_local__Atrig4;
  d->_g10_e1 = d->_g54 && d->_cg97;
  if (d->_g10_e1) {
    d->_taken_transitions[5] += 1;
  }
  d->_g52 = d->_GO || d->_g86 || d->_g67 || d->_g10_e1;
  if (d->_g52) {
    d->AVI_Clock = 0;
    d->_Pacemaker_local__Atrig3 = 0;
    d->_Pacemaker_local__Atrig4 = 0;
    d->_Pacemaker_local__Atrig5 = 0;
  }
  d->_cg4 = d->VRP_Clock < d->VRP;
  d->_g21 = d->_g52 && d->_cg4;
  if (d->_g21) {
    d->sleepT = (d->sleepT < (d->VRP - d->VRP_Clock)) ? d->sleepT : (d->VRP - d->VRP_Clock);
  }
  d->_cg5 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g10 = d->_g21 && !d->_cg5 || d->_g7 && !d->_cg9;
  d->_g43 = d->_g52 && !d->_cg4;
  d->_cg14 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g32 = d->_g8 && !d->_cg11 || d->_g43 && !d->_cg14;
  d->_cg15 = d->LRI_Clock < d->LRI;
  d->_g52_e5 = d->_g52 && d->_cg15;
  if (d->_g52_e5) {
    d->sleepT = (d->sleepT < (d->LRI - d->LRI_Clock)) ? d->sleepT : (d->LRI - d->LRI_Clock);
  }
  d->_cg16 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g21_e2 = d->_g52_e5 && !d->_cg16 || d->_g18 && !d->_cg20;
  d->_g43_e4 = d->_g52 && !d->_cg15;
  d->_cg25 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g32_e3 = d->_g19 && !d->_cg22 || d->_g43_e4 && !d->_cg25;
  d->_cg26 = d->URI_Clock < d->URI;
  d->_g95 = d->_g52 && d->_cg26;
  if (d->_g95) {
    d->sleepT = (d->sleepT < (d->URI - d->URI_Clock)) ? d->sleepT : (d->URI - d->URI_Clock);
  }
  d->_cg27 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g93 = d->_g95 && !d->_cg27 || d->_g29 && !d->_cg31;
  d->_g98 = d->_g52 && !d->_cg26;
  d->_cg36 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g5 = d->_g30 && !d->_cg33 || d->_g98 && !d->_cg36;
  d->_cg37 = d->AVI_Clock < d->AVI;
  d->_g9 = d->_g52 && d->_cg37;
  if (d->_g9) {
    d->sleepT = (d->sleepT < (d->AVI - d->AVI_Clock)) ? d->sleepT : (d->AVI - d->AVI_Clock);
  }
  d->_cg38 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g11 = d->_g9 && !d->_cg38 || d->_g46 && !d->_cg42;
  d->_g14 = d->_g52 && !d->_cg37;
  d->_cg47 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g16 = d->_g41 && !d->_cg44 || d->_g14 && !d->_cg47;
  d->_g20 = d->_g52 || d->_g53 && !d->_cg55;
  d->_g22 = d->_g56 && d->_cg57;
  if (d->_g22) {
    d->VP |= 1;
    d->_taken_transitions[4] += 1;
  }
  d->_g25 = d->_g54 && !d->_cg97;
  if (d->_g25) {
    d->VP |= 1;
    d->_taken_transitions[6] += 1;
  }
  d->_g27 = d->_g22 || d->_g25;
  if (d->_g27) {
    d->PVARP_Clock = 0;
    d->VRP_Clock = 0;
    d->AEI_Clock = 0;
    d->URI_Clock = 0;
    d->LRI_Clock = 0;
    d->_taken_transitions[3] += 1;
  }
  d->_g31 = d->_g87_e3 && !d->_cg94;
  if (d->_g31) {
    d->_taken_transitions[2] += 1;
  }
  d->_g33 = d->_g27 || d->_g31;
  if (d->_g33) {
    d->_Pacemaker_local__Atrig = 0;
    d->_Pacemaker_local__Atrig1 = 0;
    d->_Pacemaker_local__Atrig2 = 0;
  }
  d->_cg61 = d->AEI_Clock < d->AEI;
  d->_g36 = d->_g33 && d->_cg61;
  if (d->_g36) {
    d->sleepT = (d->sleepT < (d->AEI - d->AEI_Clock)) ? d->sleepT : (d->AEI - d->AEI_Clock);
  }
  d->_cg62 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g38 = d->_g36 && !d->_cg62 || d->_g64 && !d->_cg66;
  d->_g42 = d->_g33 && !d->_cg61;
  d->_cg71 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g44 = d->_g65 && !d->_cg68 || d->_g42 && !d->_cg71;
  d->_cg72 = d->PVARP_Clock < d->PVARP;
  d->_g47 = d->_g33 && d->_cg72;
  if (d->_g47) {
    d->sleepT = (d->sleepT < (d->PVARP - d->PVARP_Clock)) ? d->sleepT : (d->PVARP - d->PVARP_Clock);
  }
  d->_cg73 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g55 = d->_g47 && !d->_cg73 || d->_g75 && !d->_cg77;
  d->_g3 = d->_g33 && !d->_cg72;
  d->_cg82 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g57 = d->_g76 && !d->_cg79 || d->_g3 && !d->_cg82;
  d->_g97 = d->_g33 || d->_g88 && !d->_cg90;
  d->_g99 = d->_GO || d->_g107;
  d->_g58 = d->_GO || d->_g111;
  d->_g94 = d->_GO || d->_g115;
  d->_g59 = d->_GO || d->_g92;
  d->_g96 = d->_GO || d->_g123;
  d->_g66 = d->_GO || d->_g127;
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
  d->VRP_Clock = 0;
  d->AEI_Clock = 0;
  d->LRI_Clock = 0;
  d->URI_Clock = 0;
  d->PVARP_Clock = 0;
  d->AVI_Clock = 0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->_taken_transitions[0] = 0;
  d->_taken_transitions[1] = 0;
  d->_taken_transitions[2] = 0;
  d->_taken_transitions[3] = 0;
  d->_taken_transitions[4] = 0;
  d->_taken_transitions[5] = 0;
  d->_taken_transitions[6] = 0;
  d->_pg66 = 0;
  d->_pg44 = 0;
  d->_pg38 = 0;
  d->_pg96 = 0;
  d->_pg97 = 0;
  d->_pg58 = 0;
  d->_pg57 = 0;
  d->_pg55 = 0;
  d->_pg67_e1 = 0;
  d->_pg32 = 0;
  d->_pg10 = 0;
  d->_pg59 = 0;
  d->_pg20 = 0;
  d->_pg99 = 0;
  d->_pg94 = 0;
  d->_pg32_e3 = 0;
  d->_pg21_e2 = 0;
  d->_pg5 = 0;
  d->_pg93 = 0;
  d->_pg16 = 0;
  d->_pg11 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg66 = d->_g66;
  d->_pg44 = d->_g44;
  d->_pg38 = d->_g38;
  d->_pg96 = d->_g96;
  d->_pg97 = d->_g97;
  d->_pg58 = d->_g58;
  d->_pg57 = d->_g57;
  d->_pg55 = d->_g55;
  d->_pg67_e1 = d->_g67_e1;
  d->_pg32 = d->_g32;
  d->_pg10 = d->_g10;
  d->_pg59 = d->_g59;
  d->_pg20 = d->_g20;
  d->_pg99 = d->_g99;
  d->_pg94 = d->_g94;
  d->_pg32_e3 = d->_g32_e3;
  d->_pg21_e2 = d->_g21_e2;
  d->_pg5 = d->_g5;
  d->_pg93 = d->_g93;
  d->_pg16 = d->_g16;
  d->_pg11 = d->_g11;
  d->_GO = 0;
}
