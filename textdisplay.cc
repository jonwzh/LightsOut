#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

// Ctor for TextDisplay
TextDisplay::TextDisplay(int n): theDisplay{}, gridSize{n} { // ????
    for (int r = 0; r < n; ++r) {
        vector<char> bigvec{};
        for (int c = 0; c < n; ++c) {
            bigvec.emplace_back(false);
        }
        theDisplay.emplace_back(bigvec); // copy ctor called??
    }

}

// notify(whoNotified) notifies the corresponding td
void TextDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    if (theDisplay[i.row][i.col]) {
        theDisplay[i.row][i.col] = false;
    } else {
        theDisplay[i.row][i.col] = true;
    }
}

// Ctor for TextDisplay
TextDisplay::~TextDisplay() {}

// subType() returns the subscriptiontype of the td
SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

// operator<<(out, td) outputs the td
ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int r = 0; r < td.gridSize; ++r) {
        for (int c = 0; c < td.gridSize; ++c) {
            if (td.theDisplay[r][c]) {
                out << 'X';
            } else {
                out << '_';
            }
        }
        out << endl;
    }
    return out;
}

