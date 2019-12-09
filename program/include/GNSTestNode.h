#include "GNSModel.h"
#include "GNSModelStack.h"

class TestNode : public GNS_ModelStack
{
public:
    TestNode();
    ~TestNode();

    void SetTrigger();
}