#ifndef GBLCHAT_H
#define GBLCHAT_H

#include "gblworker.h"

class GBLChat
{
public:
    GBLChat();

    void onstart();
    void onwork();
    void onstop();

};

#endif // GBLCHAT_H
