#include "GNSTestRepeater.h"

#include "GNSEvent.h"
#include "GNSScenario.h"

#include <unistd.h>

TestRepeater::TestRepeater(GNS_Scenario * scn) : GNS_Model(scn) {

}

void TestRepeater::HandleEvent(GNS_Event * event) {
    if (event->EventType == 2) {
        std::cout << "Handling event generated in model " 
                  << event->srcNode << ". eid = " 
                  << event->Eid << ". Sim time: " 
                  << MyScn->SimClock() << ".\n";
        std::cout << "Processing...\n" << std::endl;
        sleep(2);
    }
    
    auto replyEvent = GenerateNewEvent(Mid, event->srcNode, 1000);
    MyScn->NewEvent(replyEvent);
}