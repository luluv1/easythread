# Introduction #

Easythread is a library which simplifies the use of thread in C++. The only thing you have to do, is to create a subclass which implements two methods.


# Details #
Example :
```
class Test : public EasyThread
{
    public:
       void setup();
       void execute(void*);
       void startListen();
       void stopListen();
}

void Test::execute(void *param)
{
    while (getRunningStatus())
    {
        //Tasks
    }
}

void Test::setup()
{
    //Before thread start process
}

void Test::stopListen()
{
    stop();
}

void Test::startListen()
{
    start(NULL);
}
```