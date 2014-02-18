#include "examplePrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4IonTable.hh"
#include "G4UnitsTable.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleDefinition.hh"

examplePrimaryGeneratorAction::examplePrimaryGeneratorAction()
{
	particleGun = new G4ParticleGun;
}

examplePrimaryGeneratorAction::~examplePrimaryGeneratorAction()
{
	delete particleGun;
}

void examplePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
}
