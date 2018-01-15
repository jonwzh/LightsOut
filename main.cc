#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit|ios::badbit);
  string cmd;
  Grid g;
  int moves = 0;

  Xwindow w;

  // You will need to make changes to this code.
  int size;

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        cin >> size;
        g.init(size, w);

      }
      else if (cmd == "init") {
        int r, c;
        while (cin >> r >> c) {
          if (r == -1 && c == -1) {
            break;
          } else {
            if (r > -1 && c > -1) {
              g.turnOn(r, c);
            }
          }
        }

        cout << g;
      }
      else if (cmd == "game") {
        cin >> moves;

        if (moves < 0) {
          continue;
        }

        // print moves left first
        if (moves == 1) {
          cout << moves << " move left" << endl;
        } else {
          cout << moves << " moves left" << endl;
        }

        // will deal with winning immediately
        if (moves == 0) {
          if (g.isWon()) {
            cout << "Won" << endl;
          } else {
            cout << "Lost" << endl;
          }
          break;
        }
      }
      else if (cmd == "switch") {

        int r = 0, c = 0;
        cin >> r >> c;


        if (!(r < 0 || c < 0 || r > size - 1 || c > size - 1)) {
          g.toggle(r, c);
          --moves;
        }

        // print current grid
        cout << g;

        if (moves == 1) {
          cout << moves << " move left" << endl;
        } else {
          cout << moves << " moves left" << endl;
        }

        if (g.isWon()) {
          cout << "Won" << endl;
          break;
        }

        if (moves == 0) {
          cout << "Lost" << endl;
          break;
        }
      }
    }
  }
  catch (ios::failure &) {
  }
}

