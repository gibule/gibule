#include "gblchat.h"
#include "../GBL_Library/gbllistener.h"
#include <fstream>
#include <map>

GBLChat::GBLChat()
{

}

void GBLChat::onstart()
{
    cout << workers->size() << std::endl;
    listmtx->lock();
    map<string,GBLWorker*>::iterator it;
    for (it= workers->begin();it!=workers->end();it++)
    {
        cout<<it->first<<endl;
    }
    listmtx->unlock();
    cout << "gamovida" << endl;
}
void GBLChat::onwork()
{
    std::string s;
    //    s.resize(100);
    vector<string>s1;
    map<string, vector<string>> d;


    if(wsd.receiveData(s))
    {
        split(s,"@",s1);

        std::cout << s << std::endl;

        if (s1.at(0)=="REG")
        {

            fstream file;
            fstream file4reg;
            string regreq=s1.at(1);
            string reglist;
            map<string,string> mreg;
            vector<string> vreglist;
            vector <string> vregreq;
            split (regreq,"$",vregreq);
<<<<<<< HEAD
            file.open("/home/levan/gibule/gibule/Registration",fstream::in);
            while (!file.eof())
            {
                file>>reglist;
                //                cout << reglist;
                if (reglist!="")
                {
                    split(reglist,"$",vreglist);


                    for (uint i=0;i<vreglist.size();i=i+2)
                    {


                        mreg.insert(pair<string,string>(vreglist.at(i),vreglist.at(i+1)));
                    }


                }

=======
            file.open("/home/dato/Projects/gibule/gibule/Registration",fstream::in);
            while (!file.eof())
            {
                file>>reglist;
                if (reglist!="")
                {
                    split(reglist,"$",vreglist);
                    if (vreglist.size()==2)
                    {
                        m.insert(pair<string,string>(vreglist.at(0),vreglist.at(1)));
>>>>>>> d6bbc000cc1c3934f8351b338ecf4a8fdd37c036

                    }
                }
            }
            file.close();

            map<string,string>::iterator it;
<<<<<<< HEAD

            //            for (it=m.begin();it!=m.end();it++)
            //            {
            //                cout<<it->first<<endl<<it->second<<endl;


            //            }


            if(mreg.find(vregreq.at(0))!=mreg.end())
            {

                //gavugzavnot false
                wsd.sendData("Declined");
            }
            else
            {
                file4reg.open("/home/levan/gibule/gibule/Registration",fstream::app);


                file4reg<<regreq << endl;
=======
            //            for (it=m.begin();it!=m.end();it++)


            if(m.find(vregreq.at(0))!=m.end())
            {

                //gavugzavnot false
                wsd.sendData("Declined");
            }
            else
            {
                file1.open("/home/dato/Projects/gibule/gibule/Registration",fstream::app);


                file1<<regreq<<endl;

                regreq.clear();
                file1.close();
                wsd.sendData("Accepted");


            }

>>>>>>> d6bbc000cc1c3934f8351b338ecf4a8fdd37c036

                regreq.clear();
                file4reg.close();
                wsd.sendData("Accepted");








        }
        else if (s1.at(0)=="LOG")
        {
            fstream file4log;
            string logreq=s1.at(1);
            string loglist;
            map<string,string> mlog;
            vector<string> vloglist;
            vector <string> vlogreq;
            split(logreq,"$",vlogreq);
            file4log.open("/home/levan/gibule/gibule/Registration",fstream::in);
            while (!file4log.eof())
            {

                file4log>>loglist;
                if (loglist!="")
                {
                    split(loglist,"$",vloglist);

                    for (uint i=0;i<vloglist.size();i=i+2)
                    {

                        mlog.insert(pair<string,string>(vloglist.at(i),vloglist.at(i+1)));
                    }

                }

            }
            file4log.close();
            if(mlog.find(vlogreq.at(0))==mlog.end())
            {

                //gavugzavnot false
                wsd.sendData("Declined");
            }
            else if (mlog.find(vlogreq.at(0))->second==vlogreq.at(1))
            {

                logreq.clear();

                wsd.sendData("Accepted");


            }




        }

        else {





            map <string,GBLWorker*>::iterator it;
            mtx.lock();
            for (it=workers->begin();it!=workers->end();it++)
            {
                if(it->first==s1.at(0))
                {
                    it->second->sendbuff.push_back(s1.at(1));

                }
            }
            mtx.unlock();

        }

        vector <string>:: iterator it2;
        mtx.lock();
        for (it2=sendbuff.begin();it2!=sendbuff.end();  it2++)
        {

            wsd.sendData(*it2);
        }
        sendbuff.clear();
        mtx.unlock();

        if(wsd.getState()==ssDisconnected)
        {
            stop();
            cout << "Connection closed" << std::endl;
        }

        usleep(100);
    }
}
void GBLChat::onstop()
{
    cout << "Thread Stopped" << std::endl;
}
