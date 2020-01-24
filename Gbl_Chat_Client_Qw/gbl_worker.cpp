#include "gbl_worker.h"

GBL_Worker::GBL_Worker()
{

}

void GBL_Worker :: run ()
{
    cout << "worker started" << endl;
    onstart();
    while (isRunning())
    {
        onwork();
    }
    onstop();
}
