/*
 *	Unlike all other documents provided, you may modify this document slightly (but do not change its name)
 */
#include "Factory.h"
#include "Arena.h"
//You may add #include statments here
using namespace std;

//=======================================================================================
/*
 *	createArena()
 *
 *	Creates and returns an object whose class extends ArenaInterface.
 *	This should be an object of a class you have created.
 *
 *	Example: If you made a class called "Arena", you might say, "return new Arena();".
 */
ArenaInterface* Factory::createArena()
{
	ArenaInterface* a1 = new Arena();
	return a1;//Modify this line
}
//=======================================================================================