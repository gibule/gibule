#ifndef GBLCHAT_H
#define GBLCHAT_H

#include "../GBL_Library/gblworker.h"

class GBLChat : public GBLWorker
{
public:
    GBLChat();

    void onstart();
    void onwork();
    void onstop();

};

#endif // GBLCHAT_H
