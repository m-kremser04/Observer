// Main.cpp //
#include "ObserverInterface.h"
#include "ConcreteSubject.h"
#include "ConcreteObserver.h"
#include "iostream"

using namespace std;
int main()
{
    int x = 1000;
    string abc;
    string test = "wert vom string";
    // Das Objekt hält alle Daten (=notfier = subject)
    ConcreteSubject* subj = new ConcreteSubject();

    ObserverInterface* obs1 = new ConcreteObserver(subj,"A");
    ObserverInterface* obs2 = new ConcreteObserver(subj,"B");

    // Observer(=views) an Subjekt anhängen (attachen)
    subj->attach(obs1);
    subj->attach(obs2);

    // Daten ändern und Observer informieren (notify)
    subj->setData("TestData");
    subj->notify();

    // Daten ändern und Observer informieren (notify)
    subj->setData("TestData 1111111");
    subj->notify();

    // Daten ändern und Observer informieren (notify)
    subj->setData("Der neue Wert " + to_string(x));
    subj->notify();
    abc = subj->getData();
    cout << abc << endl;
    subj->setData(test);
    subj->notify();

    subj->detach(obs1);

    subj->setData("nur B");
    subj->notify();
    subj->detach(obs2);
    subj->notify();
    subj->attach(obs1);
    subj->setData("Nur A");
    subj->notify();
    subj->attach(obs2);
    subj->setData("Beide");
    subj->notify();


    /*
     Ausgabe:
     Observer A hat neuen Zustand: TestData
     Observer B hat neuen Zustand: TestData
    */

    return 0;
}