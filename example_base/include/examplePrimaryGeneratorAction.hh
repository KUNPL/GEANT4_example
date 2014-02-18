#ifndef examplePrimaryGeneratorAction_h
#define examplePrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;

class examplePrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{
	private:
		G4ParticleGun* particleGun;

	public:
		examplePrimaryGeneratorAction();
		~examplePrimaryGeneratorAction();

		virtual void GeneratePrimaries(G4Event* anEvent);
};
#endif
