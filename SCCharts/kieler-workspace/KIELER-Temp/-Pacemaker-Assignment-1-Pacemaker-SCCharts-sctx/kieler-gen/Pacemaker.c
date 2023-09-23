/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"

#include "Pacemaker.h"

void logic(TickData* d) {
  d->_g80 = d->_pg64;
  d->_g74 = d->_pg61;
  d->_g77_e1 = !(d->_g80 || d->_g74);
  d->_g130 = d->_pg31;
  if (d->_g130) {
    d->_region0_null_PVARP_Clock += d->deltaT;
  }
  d->_g95 = d->_pg9;
  d->_cg95 = d->AS == 1 && d->_region0_null_PVARP_Clock >= d->PVARP;
  d->_g96 = d->_g95 && d->_cg95;
  if (d->_g96) {
    d->_Pacemaker_local__Atrig = 1;
  }
  d->_g118 = d->_pg52;
  if (d->_g118) {
    d->AEI_Clock += d->deltaT;
  }
  d->_g98 = d->_g95 && !d->_cg95;
  d->_cg98 = d->AS == 0 && d->AEI_Clock >= d->AEI;
  d->_g99 = d->_g98 && d->_cg98;
  if (d->_g99) {
    d->_Pacemaker_local__Atrig1 = 1;
  }
  d->_g98 = d->_g98 && !d->_cg98;
  d->_cg100 = d->AS == 1;
  d->_g101 = d->_g98 && d->_cg100;
  if (d->_g101) {
    d->_Pacemaker_local__Atrig2 = 1;
  }
  d->sleepT = 1000.0;
  d->_g80 = d->_g74 || d->_g80;
  d->_cg75 = d->AEI_Clock < d->AEI;
  d->_g74 = d->_g80 && d->_cg75;
  if (d->_g74) {
    d->sleepT = (d->sleepT < (d->AEI - d->AEI_Clock)) ? d->sleepT : (d->AEI - d->AEI_Clock);
  }
  d->_cg76 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g75 = d->_g80 && !d->_cg75;
  d->_cg78 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g77 = d->_g74 && d->_cg76 || d->_g75 && d->_cg78;
  d->_g91 = d->_pg48;
  d->_g85 = d->_pg26;
  d->_g88_e2 = !(d->_g91 || d->_g85);
  d->_g91 = d->_g85 || d->_g91;
  d->_cg86 = d->_region0_null_PVARP_Clock < d->PVARP;
  d->_g85 = d->_g91 && d->_cg86;
  if (d->_g85) {
    d->sleepT = (d->sleepT < (d->PVARP - d->_region0_null_PVARP_Clock)) ? d->sleepT : (d->PVARP - d->_region0_null_PVARP_Clock);
  }
  d->_cg87 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g86 = d->_g91 && !d->_cg86;
  d->_cg89 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g88 = d->_g85 && d->_cg87 || d->_g86 && d->_cg89;
  d->_g95 = !d->_g95;
  d->_g99 = d->_g96 || d->_g99 || d->_g101;
  d->_g101 = (d->_g77_e1 || d->_g77) && (d->_g88_e2 || d->_g88) && (d->_g95 || d->_g99) && (d->_g77 || d->_g88 || d->_g99);
  d->_cg102 = d->_Pacemaker_local__Atrig;
  d->_g96 = d->_g101 && d->_cg102;
  if (d->_g96) {
    d->_taken_transitions[0] += 1;
  }
  d->_g97 = d->_pg88;
  d->_g88 = d->_GO || d->_g97;
  if (d->_g88) {
    d->AP = 0;
    d->VP = 0;
  }
  d->_g77 = d->_g101 && !d->_cg102;
  d->_cg104 = d->_Pacemaker_local__Atrig1;
  d->_g77_e1 = d->_g77 && d->_cg104;
  if (d->_g77_e1) {
    d->AP |= 1;
    d->_taken_transitions[1] += 1;
  }
  d->_g97_e3 = d->_GO || d->_g96 || d->_g77_e1;
  if (d->_g97_e3) {
    d->_Pacemaker_local_AVI_Clock = 0;
    d->_Pacemaker_local__CFSterm = 0;
  }
  d->_g88_e2 = d->_pg35;
  if (d->_g88_e2) {
    d->_Pacemaker_local_AVI_Clock += d->deltaT;
  }
  d->_g138 = d->_pg54;
  d->_g102 = d->_pg45;
  d->_g105 = !(d->_g138 || d->_g102);
  d->_g103 = d->_pg37;
  if (d->_g103) {
    d->VRP_Clock += d->deltaT;
  }
  d->_g52 = d->_pg27;
  d->_cg52 = d->VS == 1 && d->VRP_Clock >= d->VRP;
  d->_g53 = d->_g52 && d->_cg52;
  if (d->_g53) {
    d->_Pacemaker_local__Atrig3 = 1;
  }
  d->_g126 = d->_pg42;
  if (d->_g126) {
    d->URI_Clock += d->deltaT;
  }
  d->_g55 = d->_g52 && !d->_cg52;
  d->_cg55 = d->VS == 0 && d->_Pacemaker_local_AVI_Clock >= d->AVI && d->URI_Clock >= d->URI;
  d->_g56 = d->_g55 && d->_cg55;
  if (d->_g56) {
    d->_Pacemaker_local__Atrig4 = 1;
  }
  d->_g122 = d->_pg20;
  if (d->_g122) {
    d->LRI_Clock += d->deltaT;
  }
  d->_g55 = d->_g55 && !d->_cg55;
  d->_cg57 = d->VS == 0 && d->LRI_Clock >= d->LRI;
  d->_g58 = d->_g55 && d->_cg57;
  if (d->_g58) {
    d->_Pacemaker_local__Atrig5 = 1;
  }
  d->_g10 = d->_g102 || d->_g138;
  d->_cg10 = d->VRP_Clock < d->VRP;
  d->_g11 = d->_g10 && d->_cg10;
  if (d->_g11) {
    d->sleepT = (d->sleepT < (d->VRP - d->VRP_Clock)) ? d->sleepT : (d->VRP - d->VRP_Clock);
  }
  d->_cg11 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g10 = d->_g10 && !d->_cg10;
  d->_cg13 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g12 = d->_g11 && d->_cg11 || d->_g10 && d->_cg13;
  d->_g26 = d->_pg23_e2;
  d->_g20 = d->_pg34_e3;
  d->_g23_e2 = !(d->_g26 || d->_g20);
  d->_g21 = d->_g20 || d->_g26;
  d->_cg21 = d->LRI_Clock < d->LRI;
  d->_g22 = d->_g21 && d->_cg21;
  if (d->_g22) {
    d->sleepT = (d->sleepT < (d->LRI - d->LRI_Clock)) ? d->sleepT : (d->LRI - d->LRI_Clock);
  }
  d->_cg22 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g21 = d->_g21 && !d->_cg21;
  d->_cg24 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g23 = d->_g22 && d->_cg22 || d->_g21 && d->_cg24;
  d->_g37 = d->_pg7;
  d->_g31 = d->_pg60;
  d->_g34_e3 = !(d->_g37 || d->_g31);
  d->_g32 = d->_g31 || d->_g37;
  d->_cg32 = d->URI_Clock < d->URI;
  d->_g33 = d->_g32 && d->_cg32;
  if (d->_g33) {
    d->sleepT = (d->sleepT < (d->URI - d->URI_Clock)) ? d->sleepT : (d->URI - d->URI_Clock);
  }
  d->_cg33 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g32 = d->_g32 && !d->_cg32;
  d->_cg35 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g34 = d->_g33 && d->_cg33 || d->_g32 && d->_cg35;
  d->_g48 = d->_pg18;
  d->_g42 = d->_pg13;
  d->_g45_e4 = !(d->_g48 || d->_g42);
  d->_g43 = d->_g42 || d->_g48;
  d->_cg43 = d->_Pacemaker_local_AVI_Clock < d->AVI;
  d->_g44 = d->_g43 && d->_cg43;
  if (d->_g44) {
    d->sleepT = (d->sleepT < (d->AVI - d->_Pacemaker_local_AVI_Clock)) ? d->sleepT : (d->AVI - d->_Pacemaker_local_AVI_Clock);
  }
  d->_cg44 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g43 = d->_g43 && !d->_cg43;
  d->_cg46 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g45 = d->_g44 && d->_cg44 || d->_g43 && d->_cg46;
  d->_g54_e5 = !d->_g52;
  d->_g56 = d->_g53 || d->_g56 || d->_g58;
  d->_g53 = (d->_g105 || d->_g12) && (d->_g23_e2 || d->_g23) && (d->_g34_e3 || d->_g34) && (d->_g45_e4 || d->_g45) && (d->_g54_e5 || d->_g56) && (d->_g12 || d->_g23 || d->_g34 || d->_g45 || d->_g56);
  d->_cg59 = d->_Pacemaker_local__Atrig3;
  d->_g58 = d->_g53 && d->_cg59;
  if (d->_g58) {
    d->_taken_transitions[4] += 1;
  }
  d->_g23 = d->_g97_e3 || d->_g58;
  if (d->_g23) {
    d->_Pacemaker_local_AVI_Clock = 0;
    d->_Pacemaker_local__Atrig3 = 0;
    d->_Pacemaker_local__Atrig4 = 0;
    d->_Pacemaker_local__Atrig5 = 0;
  }
  d->_cg6 = d->VRP_Clock < d->VRP;
  d->_g12 = d->_g23 && d->_cg6;
  if (d->_g12) {
    d->sleepT = (d->sleepT < (d->VRP - d->VRP_Clock)) ? d->sleepT : (d->VRP - d->VRP_Clock);
  }
  d->_cg7 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g45 = d->_g12 && !d->_cg7 || d->_g11 && !d->_cg11;
  d->_g34 = d->_g23 && !d->_cg6;
  d->_cg16 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g54 = d->_g10 && !d->_cg13 || d->_g34 && !d->_cg16;
  d->_cg17 = d->LRI_Clock < d->LRI;
  d->_g45_e4 = d->_g23 && d->_cg17;
  if (d->_g45_e4) {
    d->sleepT = (d->sleepT < (d->LRI - d->LRI_Clock)) ? d->sleepT : (d->LRI - d->LRI_Clock);
  }
  d->_cg18 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g34_e3 = d->_g45_e4 && !d->_cg18 || d->_g22 && !d->_cg22;
  d->_g54_e5 = d->_g23 && !d->_cg17;
  d->_cg27 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g23_e2 = d->_g21 && !d->_cg24 || d->_g54_e5 && !d->_cg27;
  d->_cg28 = d->URI_Clock < d->URI;
  d->_g12_e1 = d->_g23 && d->_cg28;
  if (d->_g12_e1) {
    d->sleepT = (d->sleepT < (d->URI - d->URI_Clock)) ? d->sleepT : (d->URI - d->URI_Clock);
  }
  d->_cg29 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g60 = d->_g12_e1 && !d->_cg29 || d->_g33 && !d->_cg33;
  d->_g11 = d->_g23 && !d->_cg28;
  d->_cg38 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g7 = d->_g32 && !d->_cg35 || d->_g11 && !d->_cg38;
  d->_cg39 = d->_Pacemaker_local_AVI_Clock < d->AVI;
  d->_g16 = d->_g23 && d->_cg39;
  if (d->_g16) {
    d->sleepT = (d->sleepT < (d->AVI - d->_Pacemaker_local_AVI_Clock)) ? d->sleepT : (d->AVI - d->_Pacemaker_local_AVI_Clock);
  }
  d->_cg40 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g13 = d->_g16 && !d->_cg40 || d->_g44 && !d->_cg44;
  d->_g22 = d->_g23 && !d->_cg39;
  d->_cg49 = d->_Pacemaker_local__Atrig3 || d->_Pacemaker_local__Atrig4 || d->_Pacemaker_local__Atrig5;
  d->_g18 = d->_g43 && !d->_cg46 || d->_g22 && !d->_cg49;
  d->_g27 = d->_g23 || d->_g55 && !d->_cg57;
  d->_g24 = d->_g53 && !d->_cg59;
  d->_cg61 = d->_Pacemaker_local__Atrig4;
  d->_g33 = d->_g24 && d->_cg61;
  if (d->_g33) {
    d->VP |= 1;
    d->_taken_transitions[5] += 1;
    d->_Pacemaker_local__CFSterm = 1;
  }
  d->_g29 = d->_g24 && !d->_cg61;
  if (d->_g29) {
    d->VP |= 1;
    d->_taken_transitions[6] += 1;
    d->_Pacemaker_local__CFSterm = 1;
  }
  d->_g38 = d->_g33 || d->_g29;
  if (d->_g38) {
    d->_region0_null_PVARP_Clock = 0;
    d->VRP_Clock = 0;
    d->AEI_Clock = 0;
    d->LRI_Clock = 0;
    d->URI_Clock = 0;
  }
  d->_cg65 = d->_Pacemaker_local__CFSterm;
  d->_cg67 = d->_Pacemaker_local__CFSterm;
  d->_g35 = d->_g97_e3 && !d->_cg65 || d->_g88_e2 && !d->_cg67;
  d->_g44 = d->_g88_e2 && d->_cg67;
  d->_g40 = !(d->_g52 || d->_g138 || d->_g26 || d->_g37 || d->_g48 || d->_g102 || d->_g20 || d->_g31 || d->_g42);
  d->_g49 = !d->_g88_e2;
  d->_g46 = (d->_g40 || d->_g38) && (d->_g49 || d->_g44) && (d->_g38 || d->_g44);
  if (d->_g46) {
    d->_taken_transitions[3] += 1;
  }
  d->_g5 = d->_g77 && !d->_cg104;
  if (d->_g5) {
    d->_taken_transitions[2] += 1;
  }
  d->_g57 = d->_g46 || d->_g5;
  if (d->_g57) {
    d->_Pacemaker_local__Atrig = 0;
    d->_Pacemaker_local__Atrig1 = 0;
    d->_Pacemaker_local__Atrig2 = 0;
  }
  d->_cg71 = d->AEI_Clock < d->AEI;
  d->_g59 = d->_g57 && d->_cg71;
  if (d->_g59) {
    d->sleepT = (d->sleepT < (d->AEI - d->AEI_Clock)) ? d->sleepT : (d->AEI - d->AEI_Clock);
  }
  d->_cg72 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g61 = d->_g59 && !d->_cg72 || d->_g74 && !d->_cg76;
  d->_g62 = d->_g57 && !d->_cg71;
  d->_cg81 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g64 = d->_g75 && !d->_cg78 || d->_g62 && !d->_cg81;
  d->_cg82 = d->_region0_null_PVARP_Clock < d->PVARP;
  d->_g3 = d->_g57 && d->_cg82;
  if (d->_g3) {
    d->sleepT = (d->sleepT < (d->PVARP - d->_region0_null_PVARP_Clock)) ? d->sleepT : (d->PVARP - d->_region0_null_PVARP_Clock);
  }
  d->_cg83 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g26 = d->_g3 && !d->_cg83 || d->_g85 && !d->_cg87;
  d->_g15 = d->_g57 && !d->_cg82;
  d->_cg92 = d->_Pacemaker_local__Atrig || d->_Pacemaker_local__Atrig1 || d->_Pacemaker_local__Atrig2;
  d->_g48 = d->_g86 && !d->_cg89 || d->_g15 && !d->_cg92;
  d->_g9 = d->_g57 || d->_g98 && !d->_cg100;
  d->_g37 = d->_GO || d->_g103;
  d->_g52 = d->_GO || d->_g118;
  d->_g20 = d->_GO || d->_g122;
  d->_g42 = d->_GO || d->_g126;
  d->_g31 = d->_GO || d->_g130;
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
  d->_region0_null_PVARP_Clock = 0.0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->_taken_transitions[0] = 0;
  d->_taken_transitions[1] = 0;
  d->_taken_transitions[2] = 0;
  d->_taken_transitions[3] = 0;
  d->_taken_transitions[4] = 0;
  d->_taken_transitions[5] = 0;
  d->_taken_transitions[6] = 0;
  d->_pg64 = 0;
  d->_pg61 = 0;
  d->_pg31 = 0;
  d->_pg9 = 0;
  d->_pg52 = 0;
  d->_pg48 = 0;
  d->_pg26 = 0;
  d->_pg88 = 0;
  d->_pg35 = 0;
  d->_pg54 = 0;
  d->_pg45 = 0;
  d->_pg37 = 0;
  d->_pg27 = 0;
  d->_pg42 = 0;
  d->_pg20 = 0;
  d->_pg23_e2 = 0;
  d->_pg34_e3 = 0;
  d->_pg7 = 0;
  d->_pg60 = 0;
  d->_pg18 = 0;
  d->_pg13 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg64 = d->_g64;
  d->_pg61 = d->_g61;
  d->_pg31 = d->_g31;
  d->_pg9 = d->_g9;
  d->_pg52 = d->_g52;
  d->_pg48 = d->_g48;
  d->_pg26 = d->_g26;
  d->_pg88 = d->_g88;
  d->_pg35 = d->_g35;
  d->_pg54 = d->_g54;
  d->_pg45 = d->_g45;
  d->_pg37 = d->_g37;
  d->_pg27 = d->_g27;
  d->_pg42 = d->_g42;
  d->_pg20 = d->_g20;
  d->_pg23_e2 = d->_g23_e2;
  d->_pg34_e3 = d->_g34_e3;
  d->_pg7 = d->_g7;
  d->_pg60 = d->_g60;
  d->_pg18 = d->_g18;
  d->_pg13 = d->_g13;
  d->_GO = 0;
}
