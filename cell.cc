#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

// Ctor for Cell
Cell::Cell() {}

// getState() returns the state of the cell
bool Cell::getState() const {
    return isOn;
}

// getInfo() returns the Info for the cell
Info Cell::getInfo() const {
    Info i{r, c, isOn};
    return i;
}

// setOn() sets the cell on
void Cell::setOn() {
    isOn = true;
}

// toggle() toggles the cell
void Cell::toggle() {
    if (isOn) {
        isOn = false;
    } else {
        isOn = true;
    }

    this->notifyObservers(SubscriptionType::All);
}

// setCoords(r, c) sets the coordinates of the cell
void Cell::setCoords(int r, int c) {
    this->r = r; this->c = c;
}

// notify(whoNotified) notifies the cell
void Cell::notify(Subject &whoNotified) {
    Cell::toggle();
    // is this->toggle() valid?

}

// subType() returns the subscriptiontype of the cell
SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

