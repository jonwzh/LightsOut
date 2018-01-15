#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "observer.h"
#include "window.h"
class Cell;

extern int total_width;

class GraphicsDisplay : public Observer {
    const int n;
    Xwindow &w;

public:

    GraphicsDisplay(int n, Xwindow &w);

    void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;



    ~GraphicsDisplay();



};






#endif
