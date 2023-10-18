<#macro simulation_imports position>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lib/cJSON.h"
</#macro>

<#macro simulation_init position>
sendVariables(1);
</#macro>

<#macro simulation_in position>
receiveVariables();
</#macro>

<#macro simulation_out position>
sendVariables(0);
</#macro>

<#macro simulation_body position>
void receiveVariables() {
    size_t blocksize = 2048;
    char *buffer = realloc(NULL, sizeof(char) * blocksize);
    size_t i = 0;
    
    // read next line
    int c = getchar();
    while (c != EOF && c != '\n') {
        buffer[i++] = (char) c;
        if (i == blocksize) {
            buffer = realloc(buffer, sizeof(char) * (blocksize += 2048));
        }
        c = getchar();
    }
    buffer[i++] = '\0';
    
    if (c == EOF) {
        exit(EOF);
    }
    
    cJSON *root = cJSON_Parse(buffer);
    cJSON *item = NULL;
    if(root != NULL) {
        // Receive AS
        item = cJSON_GetObjectItemCaseSensitive(root, "AS");
        if(item != NULL) {
            ${tickdata_name}.AS = item->valueint;
        }
        // Receive VS
        item = cJSON_GetObjectItemCaseSensitive(root, "VS");
        if(item != NULL) {
            ${tickdata_name}.VS = item->valueint;
        }
        // Receive deltaT
        item = cJSON_GetObjectItemCaseSensitive(root, "deltaT");
        if(item != NULL) {
            ${tickdata_name}.deltaT = item->valuedouble;
        }
        // Receive AP
        item = cJSON_GetObjectItemCaseSensitive(root, "AP");
        if(item != NULL) {
            ${tickdata_name}.AP = item->valueint;
        }
        // Receive AR
        item = cJSON_GetObjectItemCaseSensitive(root, "AR");
        if(item != NULL) {
            ${tickdata_name}.AR = item->valueint;
        }
        // Receive VP
        item = cJSON_GetObjectItemCaseSensitive(root, "VP");
        if(item != NULL) {
            ${tickdata_name}.VP = item->valueint;
        }
        // Receive VR
        item = cJSON_GetObjectItemCaseSensitive(root, "VR");
        if(item != NULL) {
            ${tickdata_name}.VR = item->valueint;
        }
        // Receive sleepT
        item = cJSON_GetObjectItemCaseSensitive(root, "sleepT");
        if(item != NULL) {
            ${tickdata_name}.sleepT = item->valuedouble;
        }
        // Receive #ticktime
        item = cJSON_GetObjectItemCaseSensitive(root, "#ticktime");
        if(item != NULL) {
            _ticktime = item->valuedouble;
        }
        // Receive AVI_Clock
        item = cJSON_GetObjectItemCaseSensitive(root, "AVI_Clock");
        if(item != NULL) {
            ${tickdata_name}.AVI_Clock = item->valuedouble;
        }
        // Receive VEvents_Clock
        item = cJSON_GetObjectItemCaseSensitive(root, "VEvents_Clock");
        if(item != NULL) {
            ${tickdata_name}.VEvents_Clock = item->valuedouble;
        }
        // Receive _GO
        item = cJSON_GetObjectItemCaseSensitive(root, "_GO");
        if(item != NULL) {
            ${tickdata_name}._GO = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig1
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig1");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig1 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig10
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig10");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig10 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig2
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig2");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig2 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig3
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig3");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig3 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig4
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig4");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig4 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig5
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig5");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig5 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig6
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig6");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig6 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig7
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig7");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig7 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig8
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig8");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig8 = item->valueint;
        }
        // Receive _Pacemaker_local__Atrig9
        item = cJSON_GetObjectItemCaseSensitive(root, "_Pacemaker_local__Atrig9");
        if(item != NULL) {
            ${tickdata_name}._Pacemaker_local__Atrig9 = item->valueint;
        }
        // Receive _TERM
        item = cJSON_GetObjectItemCaseSensitive(root, "_TERM");
        if(item != NULL) {
            ${tickdata_name}._TERM = item->valueint;
        }
        // Receive _cg10
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg10");
        if(item != NULL) {
            ${tickdata_name}._cg10 = item->valueint;
        }
        // Receive _cg100
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg100");
        if(item != NULL) {
            ${tickdata_name}._cg100 = item->valueint;
        }
        // Receive _cg110
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg110");
        if(item != NULL) {
            ${tickdata_name}._cg110 = item->valueint;
        }
        // Receive _cg113
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg113");
        if(item != NULL) {
            ${tickdata_name}._cg113 = item->valueint;
        }
        // Receive _cg119
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg119");
        if(item != NULL) {
            ${tickdata_name}._cg119 = item->valueint;
        }
        // Receive _cg12
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg12");
        if(item != NULL) {
            ${tickdata_name}._cg12 = item->valueint;
        }
        // Receive _cg126
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg126");
        if(item != NULL) {
            ${tickdata_name}._cg126 = item->valueint;
        }
        // Receive _cg129
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg129");
        if(item != NULL) {
            ${tickdata_name}._cg129 = item->valueint;
        }
        // Receive _cg135
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg135");
        if(item != NULL) {
            ${tickdata_name}._cg135 = item->valueint;
        }
        // Receive _cg15
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg15");
        if(item != NULL) {
            ${tickdata_name}._cg15 = item->valueint;
        }
        // Receive _cg18
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg18");
        if(item != NULL) {
            ${tickdata_name}._cg18 = item->valueint;
        }
        // Receive _cg21
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg21");
        if(item != NULL) {
            ${tickdata_name}._cg21 = item->valueint;
        }
        // Receive _cg23
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg23");
        if(item != NULL) {
            ${tickdata_name}._cg23 = item->valueint;
        }
        // Receive _cg26
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg26");
        if(item != NULL) {
            ${tickdata_name}._cg26 = item->valueint;
        }
        // Receive _cg27
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg27");
        if(item != NULL) {
            ${tickdata_name}._cg27 = item->valueint;
        }
        // Receive _cg30
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg30");
        if(item != NULL) {
            ${tickdata_name}._cg30 = item->valueint;
        }
        // Receive _cg31
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg31");
        if(item != NULL) {
            ${tickdata_name}._cg31 = item->valueint;
        }
        // Receive _cg33
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg33");
        if(item != NULL) {
            ${tickdata_name}._cg33 = item->valueint;
        }
        // Receive _cg36
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg36");
        if(item != NULL) {
            ${tickdata_name}._cg36 = item->valueint;
        }
        // Receive _cg37
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg37");
        if(item != NULL) {
            ${tickdata_name}._cg37 = item->valueint;
        }
        // Receive _cg38
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg38");
        if(item != NULL) {
            ${tickdata_name}._cg38 = item->valueint;
        }
        // Receive _cg41
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg41");
        if(item != NULL) {
            ${tickdata_name}._cg41 = item->valueint;
        }
        // Receive _cg42
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg42");
        if(item != NULL) {
            ${tickdata_name}._cg42 = item->valueint;
        }
        // Receive _cg44
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg44");
        if(item != NULL) {
            ${tickdata_name}._cg44 = item->valueint;
        }
        // Receive _cg47
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg47");
        if(item != NULL) {
            ${tickdata_name}._cg47 = item->valueint;
        }
        // Receive _cg48
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg48");
        if(item != NULL) {
            ${tickdata_name}._cg48 = item->valueint;
        }
        // Receive _cg49
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg49");
        if(item != NULL) {
            ${tickdata_name}._cg49 = item->valueint;
        }
        // Receive _cg5
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg5");
        if(item != NULL) {
            ${tickdata_name}._cg5 = item->valueint;
        }
        // Receive _cg52
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg52");
        if(item != NULL) {
            ${tickdata_name}._cg52 = item->valueint;
        }
        // Receive _cg53
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg53");
        if(item != NULL) {
            ${tickdata_name}._cg53 = item->valueint;
        }
        // Receive _cg55
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg55");
        if(item != NULL) {
            ${tickdata_name}._cg55 = item->valueint;
        }
        // Receive _cg58
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg58");
        if(item != NULL) {
            ${tickdata_name}._cg58 = item->valueint;
        }
        // Receive _cg6
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg6");
        if(item != NULL) {
            ${tickdata_name}._cg6 = item->valueint;
        }
        // Receive _cg61
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg61");
        if(item != NULL) {
            ${tickdata_name}._cg61 = item->valueint;
        }
        // Receive _cg64
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg64");
        if(item != NULL) {
            ${tickdata_name}._cg64 = item->valueint;
        }
        // Receive _cg66
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg66");
        if(item != NULL) {
            ${tickdata_name}._cg66 = item->valueint;
        }
        // Receive _cg68
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg68");
        if(item != NULL) {
            ${tickdata_name}._cg68 = item->valueint;
        }
        // Receive _cg71
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg71");
        if(item != NULL) {
            ${tickdata_name}._cg71 = item->valueint;
        }
        // Receive _cg72
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg72");
        if(item != NULL) {
            ${tickdata_name}._cg72 = item->valueint;
        }
        // Receive _cg75
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg75");
        if(item != NULL) {
            ${tickdata_name}._cg75 = item->valueint;
        }
        // Receive _cg76
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg76");
        if(item != NULL) {
            ${tickdata_name}._cg76 = item->valueint;
        }
        // Receive _cg78
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg78");
        if(item != NULL) {
            ${tickdata_name}._cg78 = item->valueint;
        }
        // Receive _cg81
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg81");
        if(item != NULL) {
            ${tickdata_name}._cg81 = item->valueint;
        }
        // Receive _cg84
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg84");
        if(item != NULL) {
            ${tickdata_name}._cg84 = item->valueint;
        }
        // Receive _cg87
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg87");
        if(item != NULL) {
            ${tickdata_name}._cg87 = item->valueint;
        }
        // Receive _cg89
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg89");
        if(item != NULL) {
            ${tickdata_name}._cg89 = item->valueint;
        }
        // Receive _cg9
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg9");
        if(item != NULL) {
            ${tickdata_name}._cg9 = item->valueint;
        }
        // Receive _cg91
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg91");
        if(item != NULL) {
            ${tickdata_name}._cg91 = item->valueint;
        }
        // Receive _cg93
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg93");
        if(item != NULL) {
            ${tickdata_name}._cg93 = item->valueint;
        }
        // Receive _cg95
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg95");
        if(item != NULL) {
            ${tickdata_name}._cg95 = item->valueint;
        }
        // Receive _cg97
        item = cJSON_GetObjectItemCaseSensitive(root, "_cg97");
        if(item != NULL) {
            ${tickdata_name}._cg97 = item->valueint;
        }
        // Receive _g115
        item = cJSON_GetObjectItemCaseSensitive(root, "_g115");
        if(item != NULL) {
            ${tickdata_name}._g115 = item->valueint;
        }
        // Receive _g116
        item = cJSON_GetObjectItemCaseSensitive(root, "_g116");
        if(item != NULL) {
            ${tickdata_name}._g116 = item->valueint;
        }
        // Receive _g125
        item = cJSON_GetObjectItemCaseSensitive(root, "_g125");
        if(item != NULL) {
            ${tickdata_name}._g125 = item->valueint;
        }
        // Receive _g126
        item = cJSON_GetObjectItemCaseSensitive(root, "_g126");
        if(item != NULL) {
            ${tickdata_name}._g126 = item->valueint;
        }
        // Receive _g127
        item = cJSON_GetObjectItemCaseSensitive(root, "_g127");
        if(item != NULL) {
            ${tickdata_name}._g127 = item->valueint;
        }
        // Receive _g135
        item = cJSON_GetObjectItemCaseSensitive(root, "_g135");
        if(item != NULL) {
            ${tickdata_name}._g135 = item->valueint;
        }
        // Receive _g136
        item = cJSON_GetObjectItemCaseSensitive(root, "_g136");
        if(item != NULL) {
            ${tickdata_name}._g136 = item->valueint;
        }
        // Receive _g147
        item = cJSON_GetObjectItemCaseSensitive(root, "_g147");
        if(item != NULL) {
            ${tickdata_name}._g147 = item->valueint;
        }
        // Receive _g151
        item = cJSON_GetObjectItemCaseSensitive(root, "_g151");
        if(item != NULL) {
            ${tickdata_name}._g151 = item->valueint;
        }
        // Receive _g159
        item = cJSON_GetObjectItemCaseSensitive(root, "_g159");
        if(item != NULL) {
            ${tickdata_name}._g159 = item->valueint;
        }
        // Receive _g17
        item = cJSON_GetObjectItemCaseSensitive(root, "_g17");
        if(item != NULL) {
            ${tickdata_name}._g17 = item->valueint;
        }
        // Receive _g18
        item = cJSON_GetObjectItemCaseSensitive(root, "_g18");
        if(item != NULL) {
            ${tickdata_name}._g18 = item->valueint;
        }
        // Receive _g19
        item = cJSON_GetObjectItemCaseSensitive(root, "_g19");
        if(item != NULL) {
            ${tickdata_name}._g19 = item->valueint;
        }
        // Receive _g60
        item = cJSON_GetObjectItemCaseSensitive(root, "_g60");
        if(item != NULL) {
            ${tickdata_name}._g60 = item->valueint;
        }
        // Receive _g61
        item = cJSON_GetObjectItemCaseSensitive(root, "_g61");
        if(item != NULL) {
            ${tickdata_name}._g61 = item->valueint;
        }
        // Receive _g62
        item = cJSON_GetObjectItemCaseSensitive(root, "_g62");
        if(item != NULL) {
            ${tickdata_name}._g62 = item->valueint;
        }
        // Receive _pg115
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg115");
        if(item != NULL) {
            ${tickdata_name}._pg115 = item->valueint;
        }
        // Receive _pg116
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg116");
        if(item != NULL) {
            ${tickdata_name}._pg116 = item->valueint;
        }
        // Receive _pg125
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg125");
        if(item != NULL) {
            ${tickdata_name}._pg125 = item->valueint;
        }
        // Receive _pg127
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg127");
        if(item != NULL) {
            ${tickdata_name}._pg127 = item->valueint;
        }
        // Receive _pg147
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg147");
        if(item != NULL) {
            ${tickdata_name}._pg147 = item->valueint;
        }
        // Receive _pg159
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg159");
        if(item != NULL) {
            ${tickdata_name}._pg159 = item->valueint;
        }
        // Receive _pg17
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg17");
        if(item != NULL) {
            ${tickdata_name}._pg17 = item->valueint;
        }
        // Receive _pg60
        item = cJSON_GetObjectItemCaseSensitive(root, "_pg60");
        if(item != NULL) {
            ${tickdata_name}._pg60 = item->valueint;
        }
        // Receive _region0_Main_AVI_Stop
        item = cJSON_GetObjectItemCaseSensitive(root, "_region0_Main_AVI_Stop");
        if(item != NULL) {
            ${tickdata_name}._region0_Main_AVI_Stop = item->valueint;
        }
        // Receive _region0_Main_VEvents_Stop
        item = cJSON_GetObjectItemCaseSensitive(root, "_region0_Main_VEvents_Stop");
        if(item != NULL) {
            ${tickdata_name}._region0_Main_VEvents_Stop = item->valueint;
        }
        // Receive _taken_transitions
        item = cJSON_GetObjectItemCaseSensitive(root, "_taken_transitions");
        if(item != NULL) {
            for (int i0 = 0; i0 < cJSON_GetArraySize(item); i0++) {
                cJSON *item0 = cJSON_GetArrayItem(item, i0);
                ${tickdata_name}._taken_transitions[i0] = item0->valueint;
            }
        }
    }
  
    cJSON_Delete(root);
    free(buffer);
}

void sendVariables(int send_interface) {
    cJSON* root = cJSON_CreateObject();
    cJSON *array;
    
    // Send AS
    cJSON_AddItemToObject(root, "AS", cJSON_CreateBool(${tickdata_name}.AS));
    // Send VS
    cJSON_AddItemToObject(root, "VS", cJSON_CreateBool(${tickdata_name}.VS));
    // Send deltaT
    cJSON_AddItemToObject(root, "deltaT", cJSON_CreateNumber(${tickdata_name}.deltaT));
    // Send AP
    cJSON_AddItemToObject(root, "AP", cJSON_CreateBool(${tickdata_name}.AP));
    // Send AR
    cJSON_AddItemToObject(root, "AR", cJSON_CreateBool(${tickdata_name}.AR));
    // Send VP
    cJSON_AddItemToObject(root, "VP", cJSON_CreateBool(${tickdata_name}.VP));
    // Send VR
    cJSON_AddItemToObject(root, "VR", cJSON_CreateBool(${tickdata_name}.VR));
    // Send sleepT
    cJSON_AddItemToObject(root, "sleepT", cJSON_CreateNumber(${tickdata_name}.sleepT));
    // Send #ticktime
    cJSON_AddItemToObject(root, "#ticktime", cJSON_CreateNumber(_ticktime));
    // Send AVI_Clock
    cJSON_AddItemToObject(root, "AVI_Clock", cJSON_CreateNumber(${tickdata_name}.AVI_Clock));
    // Send VEvents_Clock
    cJSON_AddItemToObject(root, "VEvents_Clock", cJSON_CreateNumber(${tickdata_name}.VEvents_Clock));
    // Send _GO
    cJSON_AddItemToObject(root, "_GO", cJSON_CreateBool(${tickdata_name}._GO));
    // Send _Pacemaker_local__Atrig
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig));
    // Send _Pacemaker_local__Atrig1
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig1", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig1));
    // Send _Pacemaker_local__Atrig10
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig10", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig10));
    // Send _Pacemaker_local__Atrig2
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig2", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig2));
    // Send _Pacemaker_local__Atrig3
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig3", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig3));
    // Send _Pacemaker_local__Atrig4
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig4", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig4));
    // Send _Pacemaker_local__Atrig5
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig5", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig5));
    // Send _Pacemaker_local__Atrig6
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig6", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig6));
    // Send _Pacemaker_local__Atrig7
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig7", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig7));
    // Send _Pacemaker_local__Atrig8
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig8", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig8));
    // Send _Pacemaker_local__Atrig9
    cJSON_AddItemToObject(root, "_Pacemaker_local__Atrig9", cJSON_CreateBool(${tickdata_name}._Pacemaker_local__Atrig9));
    // Send _TERM
    cJSON_AddItemToObject(root, "_TERM", cJSON_CreateBool(${tickdata_name}._TERM));
    // Send _cg10
    cJSON_AddItemToObject(root, "_cg10", cJSON_CreateBool(${tickdata_name}._cg10));
    // Send _cg100
    cJSON_AddItemToObject(root, "_cg100", cJSON_CreateBool(${tickdata_name}._cg100));
    // Send _cg110
    cJSON_AddItemToObject(root, "_cg110", cJSON_CreateBool(${tickdata_name}._cg110));
    // Send _cg113
    cJSON_AddItemToObject(root, "_cg113", cJSON_CreateBool(${tickdata_name}._cg113));
    // Send _cg119
    cJSON_AddItemToObject(root, "_cg119", cJSON_CreateBool(${tickdata_name}._cg119));
    // Send _cg12
    cJSON_AddItemToObject(root, "_cg12", cJSON_CreateBool(${tickdata_name}._cg12));
    // Send _cg126
    cJSON_AddItemToObject(root, "_cg126", cJSON_CreateBool(${tickdata_name}._cg126));
    // Send _cg129
    cJSON_AddItemToObject(root, "_cg129", cJSON_CreateBool(${tickdata_name}._cg129));
    // Send _cg135
    cJSON_AddItemToObject(root, "_cg135", cJSON_CreateBool(${tickdata_name}._cg135));
    // Send _cg15
    cJSON_AddItemToObject(root, "_cg15", cJSON_CreateBool(${tickdata_name}._cg15));
    // Send _cg18
    cJSON_AddItemToObject(root, "_cg18", cJSON_CreateBool(${tickdata_name}._cg18));
    // Send _cg21
    cJSON_AddItemToObject(root, "_cg21", cJSON_CreateBool(${tickdata_name}._cg21));
    // Send _cg23
    cJSON_AddItemToObject(root, "_cg23", cJSON_CreateBool(${tickdata_name}._cg23));
    // Send _cg26
    cJSON_AddItemToObject(root, "_cg26", cJSON_CreateBool(${tickdata_name}._cg26));
    // Send _cg27
    cJSON_AddItemToObject(root, "_cg27", cJSON_CreateBool(${tickdata_name}._cg27));
    // Send _cg30
    cJSON_AddItemToObject(root, "_cg30", cJSON_CreateBool(${tickdata_name}._cg30));
    // Send _cg31
    cJSON_AddItemToObject(root, "_cg31", cJSON_CreateBool(${tickdata_name}._cg31));
    // Send _cg33
    cJSON_AddItemToObject(root, "_cg33", cJSON_CreateBool(${tickdata_name}._cg33));
    // Send _cg36
    cJSON_AddItemToObject(root, "_cg36", cJSON_CreateBool(${tickdata_name}._cg36));
    // Send _cg37
    cJSON_AddItemToObject(root, "_cg37", cJSON_CreateBool(${tickdata_name}._cg37));
    // Send _cg38
    cJSON_AddItemToObject(root, "_cg38", cJSON_CreateBool(${tickdata_name}._cg38));
    // Send _cg41
    cJSON_AddItemToObject(root, "_cg41", cJSON_CreateBool(${tickdata_name}._cg41));
    // Send _cg42
    cJSON_AddItemToObject(root, "_cg42", cJSON_CreateBool(${tickdata_name}._cg42));
    // Send _cg44
    cJSON_AddItemToObject(root, "_cg44", cJSON_CreateBool(${tickdata_name}._cg44));
    // Send _cg47
    cJSON_AddItemToObject(root, "_cg47", cJSON_CreateBool(${tickdata_name}._cg47));
    // Send _cg48
    cJSON_AddItemToObject(root, "_cg48", cJSON_CreateBool(${tickdata_name}._cg48));
    // Send _cg49
    cJSON_AddItemToObject(root, "_cg49", cJSON_CreateBool(${tickdata_name}._cg49));
    // Send _cg5
    cJSON_AddItemToObject(root, "_cg5", cJSON_CreateBool(${tickdata_name}._cg5));
    // Send _cg52
    cJSON_AddItemToObject(root, "_cg52", cJSON_CreateBool(${tickdata_name}._cg52));
    // Send _cg53
    cJSON_AddItemToObject(root, "_cg53", cJSON_CreateBool(${tickdata_name}._cg53));
    // Send _cg55
    cJSON_AddItemToObject(root, "_cg55", cJSON_CreateBool(${tickdata_name}._cg55));
    // Send _cg58
    cJSON_AddItemToObject(root, "_cg58", cJSON_CreateBool(${tickdata_name}._cg58));
    // Send _cg6
    cJSON_AddItemToObject(root, "_cg6", cJSON_CreateBool(${tickdata_name}._cg6));
    // Send _cg61
    cJSON_AddItemToObject(root, "_cg61", cJSON_CreateBool(${tickdata_name}._cg61));
    // Send _cg64
    cJSON_AddItemToObject(root, "_cg64", cJSON_CreateBool(${tickdata_name}._cg64));
    // Send _cg66
    cJSON_AddItemToObject(root, "_cg66", cJSON_CreateBool(${tickdata_name}._cg66));
    // Send _cg68
    cJSON_AddItemToObject(root, "_cg68", cJSON_CreateBool(${tickdata_name}._cg68));
    // Send _cg71
    cJSON_AddItemToObject(root, "_cg71", cJSON_CreateBool(${tickdata_name}._cg71));
    // Send _cg72
    cJSON_AddItemToObject(root, "_cg72", cJSON_CreateBool(${tickdata_name}._cg72));
    // Send _cg75
    cJSON_AddItemToObject(root, "_cg75", cJSON_CreateBool(${tickdata_name}._cg75));
    // Send _cg76
    cJSON_AddItemToObject(root, "_cg76", cJSON_CreateBool(${tickdata_name}._cg76));
    // Send _cg78
    cJSON_AddItemToObject(root, "_cg78", cJSON_CreateBool(${tickdata_name}._cg78));
    // Send _cg81
    cJSON_AddItemToObject(root, "_cg81", cJSON_CreateBool(${tickdata_name}._cg81));
    // Send _cg84
    cJSON_AddItemToObject(root, "_cg84", cJSON_CreateBool(${tickdata_name}._cg84));
    // Send _cg87
    cJSON_AddItemToObject(root, "_cg87", cJSON_CreateBool(${tickdata_name}._cg87));
    // Send _cg89
    cJSON_AddItemToObject(root, "_cg89", cJSON_CreateBool(${tickdata_name}._cg89));
    // Send _cg9
    cJSON_AddItemToObject(root, "_cg9", cJSON_CreateBool(${tickdata_name}._cg9));
    // Send _cg91
    cJSON_AddItemToObject(root, "_cg91", cJSON_CreateBool(${tickdata_name}._cg91));
    // Send _cg93
    cJSON_AddItemToObject(root, "_cg93", cJSON_CreateBool(${tickdata_name}._cg93));
    // Send _cg95
    cJSON_AddItemToObject(root, "_cg95", cJSON_CreateBool(${tickdata_name}._cg95));
    // Send _cg97
    cJSON_AddItemToObject(root, "_cg97", cJSON_CreateBool(${tickdata_name}._cg97));
    // Send _g115
    cJSON_AddItemToObject(root, "_g115", cJSON_CreateBool(${tickdata_name}._g115));
    // Send _g116
    cJSON_AddItemToObject(root, "_g116", cJSON_CreateBool(${tickdata_name}._g116));
    // Send _g125
    cJSON_AddItemToObject(root, "_g125", cJSON_CreateBool(${tickdata_name}._g125));
    // Send _g126
    cJSON_AddItemToObject(root, "_g126", cJSON_CreateBool(${tickdata_name}._g126));
    // Send _g127
    cJSON_AddItemToObject(root, "_g127", cJSON_CreateBool(${tickdata_name}._g127));
    // Send _g135
    cJSON_AddItemToObject(root, "_g135", cJSON_CreateBool(${tickdata_name}._g135));
    // Send _g136
    cJSON_AddItemToObject(root, "_g136", cJSON_CreateBool(${tickdata_name}._g136));
    // Send _g147
    cJSON_AddItemToObject(root, "_g147", cJSON_CreateBool(${tickdata_name}._g147));
    // Send _g151
    cJSON_AddItemToObject(root, "_g151", cJSON_CreateBool(${tickdata_name}._g151));
    // Send _g159
    cJSON_AddItemToObject(root, "_g159", cJSON_CreateBool(${tickdata_name}._g159));
    // Send _g17
    cJSON_AddItemToObject(root, "_g17", cJSON_CreateBool(${tickdata_name}._g17));
    // Send _g18
    cJSON_AddItemToObject(root, "_g18", cJSON_CreateBool(${tickdata_name}._g18));
    // Send _g19
    cJSON_AddItemToObject(root, "_g19", cJSON_CreateBool(${tickdata_name}._g19));
    // Send _g60
    cJSON_AddItemToObject(root, "_g60", cJSON_CreateBool(${tickdata_name}._g60));
    // Send _g61
    cJSON_AddItemToObject(root, "_g61", cJSON_CreateBool(${tickdata_name}._g61));
    // Send _g62
    cJSON_AddItemToObject(root, "_g62", cJSON_CreateBool(${tickdata_name}._g62));
    // Send _pg115
    cJSON_AddItemToObject(root, "_pg115", cJSON_CreateBool(${tickdata_name}._pg115));
    // Send _pg116
    cJSON_AddItemToObject(root, "_pg116", cJSON_CreateBool(${tickdata_name}._pg116));
    // Send _pg125
    cJSON_AddItemToObject(root, "_pg125", cJSON_CreateBool(${tickdata_name}._pg125));
    // Send _pg127
    cJSON_AddItemToObject(root, "_pg127", cJSON_CreateBool(${tickdata_name}._pg127));
    // Send _pg147
    cJSON_AddItemToObject(root, "_pg147", cJSON_CreateBool(${tickdata_name}._pg147));
    // Send _pg159
    cJSON_AddItemToObject(root, "_pg159", cJSON_CreateBool(${tickdata_name}._pg159));
    // Send _pg17
    cJSON_AddItemToObject(root, "_pg17", cJSON_CreateBool(${tickdata_name}._pg17));
    // Send _pg60
    cJSON_AddItemToObject(root, "_pg60", cJSON_CreateBool(${tickdata_name}._pg60));
    // Send _region0_Main_AVI_Stop
    cJSON_AddItemToObject(root, "_region0_Main_AVI_Stop", cJSON_CreateBool(${tickdata_name}._region0_Main_AVI_Stop));
    // Send _region0_Main_VEvents_Stop
    cJSON_AddItemToObject(root, "_region0_Main_VEvents_Stop", cJSON_CreateBool(${tickdata_name}._region0_Main_VEvents_Stop));
    // Send _taken_transitions
    array = cJSON_CreateArray();
    for (int i0 = 0; i0 < 17; i0++) {
        cJSON *item0 = cJSON_CreateNumber(${tickdata_name}._taken_transitions[i0]);
        cJSON_AddItemToArray(array, item0);
    }
    cJSON_AddItemToObject(root, "_taken_transitions", array);
    
    if (send_interface) {
        cJSON *interface = cJSON_CreateObject();
        cJSON *info, *properties;
        
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("input"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "AS", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("input"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "VS", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("input"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("dynamic-ticks"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("float"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "deltaT", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("output"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "AP", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("output"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "AR", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("output"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "VP", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("output"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("signal"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "VR", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("output"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("dynamic-ticks"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("float"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "sleepT", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("ticktime"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("float"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "#ticktime", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("float"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "AVI_Clock", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("float"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "VEvents_Clock", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("goGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_GO", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig1", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig10", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig2", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig3", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig4", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig5", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig6", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig7", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig8", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_Pacemaker_local__Atrig9", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("term"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_TERM", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg10", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg100", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg110", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg113", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg119", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg12", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg126", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg129", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg135", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg15", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg18", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg21", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg23", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg26", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg27", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg30", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg31", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg33", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg36", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg37", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg38", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg41", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg42", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg44", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg47", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg48", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg49", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg5", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg52", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg53", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg55", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg58", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg6", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg61", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg64", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg66", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg68", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg71", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg72", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg75", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg76", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg78", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg81", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg84", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg87", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg89", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg9", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg91", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg93", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg95", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("conditionalGuard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_cg97", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g115", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g116", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g125", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g126", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g127", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g135", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g136", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g147", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g151", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g159", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g17", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g18", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g19", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g60", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g61", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_g62", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg115", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg116", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg125", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg127", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg147", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg159", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg17", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("preGuard"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("guard"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_pg60", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_region0_Main_AVI_Stop", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("bool"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_region0_Main_VEvents_Stop", info);
        info = cJSON_CreateObject();
        properties = cJSON_CreateArray();
        cJSON_AddItemToArray(properties, cJSON_CreateString("sccharts-generated"));
        cJSON_AddItemToArray(properties, cJSON_CreateString("simulation"));
        cJSON_AddItemToObject(info, "type", cJSON_CreateString("int"));
        cJSON_AddItemToObject(info, "properties", properties);
        cJSON_AddItemToObject(interface, "_taken_transitions", info);
        
        cJSON_AddItemToObject(root, "#interface", interface);
    }

    // Get JSON object as string
    char* outString = cJSON_Print(root);
    cJSON_Minify(outString);
    // Flush to stdout
    printf("%s\n", outString);
    fflush(stdout);

    cJSON_Delete(root);
    free(outString);
}
</#macro>
