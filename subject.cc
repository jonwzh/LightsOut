#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

// attach(o) attaches the observer to the current subject
void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

// notifyObservers(t) notifies the observers
void Subject::notifyObservers(SubscriptionType t) {
    if (t == SubscriptionType::All) {
        for (auto ob : observers) {
          if (ob->subType() == SubscriptionType::All) {
            ob->notify(*this);
          }
        }
    } else {
        for (auto ob : observers) {
            if (ob->subType() == SubscriptionType::SwitchOnly) {
                // avoid switching two times for the centre cell
                // you've already called notify when you toggle itself
                ob->notify(*this);
            }
        }
    }
}

// Dtor for Subject
Subject::~Subject() {}


