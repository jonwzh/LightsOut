#include "cell.h"
#include "graphicsdisplay.h"
#include "info.h"
int total_width = 500;

// Ctor for GraphicsDisplay
GraphicsDisplay::GraphicsDisplay(int n, Xwindow &w): n{n}, w{w} {
    int blockWidth = total_width / n;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            w.fillRectangle(c * blockWidth, r * blockWidth, blockWidth, blockWidth, Xwindow::White);
        }
    }
}

// notify(whoNotified) notifies the current gd
void GraphicsDisplay::notify(Subject &whoNotified) {
    int blockWidth = total_width / n;
    Info i = whoNotified.getInfo();
    int row = i.row;
    int col = i.col;
    if (i.state) {
        w.fillRectangle(col * blockWidth, row * blockWidth, blockWidth, blockWidth, Xwindow::Black);
    } else {
        w.fillRectangle(col * blockWidth, row * blockWidth, blockWidth, blockWidth, Xwindow::White);
    }
}

// returns the subscriptiontype of the current gd
SubscriptionType GraphicsDisplay::subType() const {
    return SubscriptionType::All;
}

// Dtor for GraphicsDisplay
GraphicsDisplay::~GraphicsDisplay() {}
