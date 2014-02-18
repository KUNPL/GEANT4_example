#ifndef exampleDetevtorConstruction_h
#define exampleDetevtorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class exampleDetectorConstruction: public G4VUserDetectorConstruction
{
	public:
		exampleDetectorConstruction();
		virtual ~exampleDetectorConstruction();

		virtual G4VPhysicalVolume* Construct();

	private:
		// comment: When you change dimensions of a detector in the interactive
		//          mode, dimensions should be set outside of Construct().
		void DefineDimensions();

		// comment: You'd better define all material pointers here and initialize
		//					them as 0 in the constructor. Finally, allocate them in
		//					function below.
		void ConstructMaterials();
		void DestructMaterials();
};
#endif
