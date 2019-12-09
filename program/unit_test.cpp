#include "GNSScenario.h"
#include "GNSEvent.h"

int main(int argc, char ** argv) {
    GNS_Scenario scn;
    scn.SimInit();
    scn.SimRun();
    scn.SimStop();

    return 0;
}