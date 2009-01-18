/*
 * EasyThread.h - Easy thread management in C++
 */

/*************************************************************************
 *  Copyright © 2008 DUB Olivier.                                        *
 *  This program is free software: you can redistribute and/or modify    *
 *  it under the terms of the GNU Affero General Public License as       *
 *  published by the Free Software Foundation, versions 2 or 3 of        *
 *  the license.                                                         *
 *                                                                       *
 *  This program is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *  GNU Affero General Public License for more details.                  *
 *                                                                       *
 *  You should have received a copy of the GNU  Affero General Public    *
 *  License along with this program. If not, see                         *
 *  <http://www.gnu.org/licenses/>.                                      *
 *************************************************************************/


#ifndef EASYTHREAD_H
#define EASYTHREAD_H

#include <pthread.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class EasyThread
{
public:
    //Start the thread
    int start(void * arg);
    void stop();
    virtual ~EasyThread();
    bool getRunningStatus()
    {
        return shouldRun;
    }
protected:
    EasyThread();
    void run(void * arg);
    virtual void setup()=0;
    virtual void execute(void*)=0;
    //Getter and setter for run's args
    void * arg() const
    {
        return _arg;
    }
    void arg(void* a)
    {
        _arg = a;
    }
    //static
    static void * entryPoint(void*);
    void lockShouldRun()
    {
        pthread_mutex_lock(&mutex);
    };
    void unlockShouldRun()
    {
        pthread_mutex_unlock(&mutex);
    };
private:
    pthread_t th_id;
    void * _arg;
    bool shouldRun;
    pthread_mutex_t mutex;

};


#endif // EASYTHREAD_H
