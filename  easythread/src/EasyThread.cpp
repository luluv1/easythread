/*
 * EasyThread.cpp - Easy thread management in C++
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

#include "../include/EasyThread.h"

int EasyThread::start(void * argum)
{
    shouldRun=true;
    arg(argum); //store user agrs
    int code = pthread_create(&th_id, NULL, EasyThread::entryPoint, this);
    return code;
}

void EasyThread::stop()
{
    lockShouldRun();
    shouldRun=false;
    unlockShouldRun();
}

void EasyThread::run(void * argum)
{
    setup();
    execute(argum);
}

/*static */
void * EasyThread::entryPoint(void * pthis)
{
    EasyThread * pt = (EasyThread*) pthis;
    pt->run(pt->arg());
}

EasyThread::EasyThread()
{
    shouldRun=false;
    pthread_mutex_init(&mutex, NULL);
}

EasyThread::~EasyThread()
{
    pthread_mutex_destroy(&mutex);
}
