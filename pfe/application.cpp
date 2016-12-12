/////////////////////////////
///
/// @file application.cpp
///
/////////////////////////////

#include "application.h"

using namespace std;

Application::Application()
{

}

float Application::loiLaplace(double centre, double epsilon)
{
    float u= uniformeAleatoire(-0.5,0.5,"real");
    return (centre - u/qAbs(u)*qLn(1-2*qAbs(u))/epsilon);

}

float Application::uniformeAleatoire(float min, float max, QString type)
{

    QTime t;
    int t2;
    t = t.currentTime();
    t2 = t.hour()*3600*1000+t.minute()*60*1000+t.second()*1000+t.msec();
    mt19937 gen(t2);

/*
    random_device rd;
    mt19937 gen(rd());
  */

    if (type=="int")
    {
        uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
    else if (type=="real")
    {
        uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }
    else cout << "erreur de type" <<endl;
    return 0;

}
