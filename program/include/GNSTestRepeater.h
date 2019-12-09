#include "GNSModel.h"

class GNS_Event;
class GNS_Scenario;

class TestRepeater : public GNS_Model
{
public:
    TestRepeater(GNS_Scenario * scn);

    void HandleEvent(GNS_Event * event) override;
};