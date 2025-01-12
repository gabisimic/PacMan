#include <iostream>  
#include <stdexcept>     
#include "Game.h"

using namespace std;

int main() {
    try {
        Game game(35, 9, 3);
        game.run();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
