#ifndef GBLUTILITY_H
#define GBLUTILITY_H

#endif // GBLUTILITY_H
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace  std;



inline void split(string asa, string basa, vector<string> &v)
{
    ulong pos1=0;
    ulong pos2=0;
    while (pos2!=string::npos)
    {

        pos2=asa.find(basa,pos1);

        v.push_back(asa.substr(pos1,pos2-pos1));

        pos1=pos2+basa.length();
    }
}
