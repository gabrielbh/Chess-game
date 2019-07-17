#include "Game.h"


/**
 * main function of the chess game, runs everything together.
 * @return 0 if everything went well, NOT 0 otherwise.
 */
int main()
{
    auto *game = new Game();
    game->runGame();
    delete(game);
    return 0;
}