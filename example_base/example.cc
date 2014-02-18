#include "G4RunManager.hh"
#include "A01PhysicsList.hh"
#include "exampleDetectorConstruction.hh"
#include "examplePrimaryGeneratorAction.hh"

int main()
{
	G4RunManager *runManager = new G4RunManager();

	exampleDetectorConstruction* exampleDC = new exampleDetectorConstruction();
	runManager -> SetUserInitialization(exampleDC);

	A01PhysicsList* physicsList = new A01PhysicsList();
	runManager -> SetUserInitialization(physicsList);

	examplePrimaryGeneratorAction* examplePGA = new examplePrimaryGeneratorAction();
	runManager -> SetUserAction(examplePGA);

	runManager -> Initialize();

	delete runManager;

	return 0;
}
