#include "gblworker.h"

GBLWorker::GBLWorker()
{

}

void GBLWorker::run()
{
    cout << "worker started" << endl;
    onstart();
    while (isRunning())
    {
        onwork();
    }
    onstop();
}



