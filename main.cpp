#include "EntityManager.h"
#include "Esp.h"
#include "Player.h"

// Create a new instance of the EntityManager
EntityManager *entityManager = new EntityManager();

// Define function pointers for the original and modified versions of the 'update' function
void(*orig_Update)(void * player);

// Modified version of the 'update' function
void update(void* player)
{
    // Check if instance exists
    if (player)
    {
        // Check if 'player' is not the local player and not on the same team as the local player
        if (!Player::isMine(player) && !Player::onTeam(myPlayer, player))
        {
            // Add 'player' as an enemy to the entity manager
            entityManager->addEnemy(player);

            // Update enemy information in the entity manager
            entityManager->updateEnemies(player);
        }
    }
    // Call the original 'update' function
    orig_Update(player);
}

int main()
{
  
  esp->render(*entityManager); //Render ESP
  
  HOOK(offset::player::update, update, orig_Update); //Hooking player update
}