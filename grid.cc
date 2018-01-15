#include <iostream>
#include "grid.h"
#include <vector>
using namespace std;

// Ctor for Grid
Grid::Grid() : theGrid{{}}, gridSize{1}, td{nullptr}, gd{nullptr} {}

// Dtor for Grid
Grid::~Grid() {
    delete td;
    delete gd;
}

// clearGrid() clears the grid
void Grid::clearGrid() {
    for (vector<vector <Cell>>::reverse_iterator it = theGrid.rbegin(); it != theGrid.rend(); ++it) {
        for (vector<Cell>::reverse_iterator it2 = (*it).rbegin(); it2 != (*it).rend(); ++it2) {
            (*it).erase((*it).end());
        }
        theGrid.erase(theGrid.end());
    }
    // Check: dangerous??


    gridSize = 0;
    delete td; // calls TextDisplay's dtor
    delete gd; // calls GraphicsDisplay's dtor
    td = nullptr;
    gd = nullptr;
}

// isWon() returns true if all the lights are off, false otherwise
bool Grid::isWon() const {
    for (int i = 0; i < theGrid.size(); ++i) {
        for(int j = 0; j < theGrid.size(); ++j) {
            if (theGrid[i][j].getState()) {
                return false; // if some lights are still on
            }
        }
    }
    return true;
}

// init(n) initializes the grid
void Grid::init(int n) {
    Grid::clearGrid();

    gridSize = n * n;

    // initialize theGrid
    for (int r = 0; r < n; ++r) {
        vector <Cell> bigvec;
        for (int c = 0; c < n; ++c) {
            Cell ce;
            ce.setCoords(r, c);
            bigvec.emplace_back(ce); // copy ctor called??
        }
        theGrid.emplace_back(bigvec); // copy ctor called??
    }

    // initialize td
    td = new TextDisplay{n}; // td is on heap

    // initialize gd
    gd = nullptr;

    // Set Subscribers
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (c != 0) {
                theGrid[r][c].attach(&(theGrid[r][c - 1]));
            }

            if (c != n - 1) {
                theGrid[r][c].attach(&(theGrid[r][c + 1]));
            }

            if (r != 0) {
                theGrid[r][c].attach(&(theGrid[r - 1][c]));
            }

            if (r != n - 1) {
                theGrid[r][c].attach(&(theGrid[r + 1][c]));
            }

            theGrid[r][c].attach(td); // What is equivalent to this?
            theGrid[r][c].attach(gd);
        }
    }
}

// init(n, w) initializes the grid
void Grid::init(int n, Xwindow &w) {
    Grid::clearGrid();

    gridSize = n * n;

    // initialize theGrid
    for (int r = 0; r < n; ++r) {
        vector <Cell> bigvec;
        for (int c = 0; c < n; ++c) {
            Cell ce;
            ce.setCoords(r, c);
            bigvec.emplace_back(ce); // copy ctor called??
        }
        theGrid.emplace_back(bigvec); // copy ctor called??
    }

    // initialize td
    td = new TextDisplay{n}; // td is on heap

    // initialize gd
    gd = new GraphicsDisplay{n, w};

    // Set Subscribers
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (c != 0) {
                theGrid[r][c].attach(&(theGrid[r][c - 1]));
            }

            if (c != n - 1) {
                theGrid[r][c].attach(&(theGrid[r][c + 1]));
            }

            if (r != 0) {
                theGrid[r][c].attach(&(theGrid[r - 1][c]));
            }

            if (r != n - 1) {
                theGrid[r][c].attach(&(theGrid[r + 1][c]));
            }

            theGrid[r][c].attach(td); // What is equivalent to this?
            theGrid[r][c].attach(gd);
        }
    }
}

// turnOn(r, c) turns the corresponding light on
void Grid::turnOn(int r, int c) {
    if (!theGrid[r][c].getState()) { // Why? In case turn off when init (problem: td)
        theGrid[r][c].setOn();
        td->notify(theGrid[r][c]);
        gd->notify(theGrid[r][c]);
    }
}

// toggle(r, c) toggles the corresponding light
void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly); //???????
}

// operator<<(out, g) outputs the grid
ostream &operator<<(ostream &out, const Grid &g) {
    out << (*g.td);
    return out;
}

