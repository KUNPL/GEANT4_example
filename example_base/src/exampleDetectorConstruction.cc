#include "exampleDetectorConstruction.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

exampleDetectorConstruction::exampleDetectorConstruction()
{
	ConstructMaterials();
	DefineDimensions();
}

exampleDetectorConstruction::~exampleDetectorConstruction()
{
	DestructMaterials();
}

exampleDetectorConstruction::DefineDimensions()
{
}

G4VPhysicalVolume* exampleDetectorConstruction::Construct()
{
}

void exampleDetectorConstruction::ConstructMaterials()
{
}

void exampleDetectorConstruction::DestructMaterials()
{
}
