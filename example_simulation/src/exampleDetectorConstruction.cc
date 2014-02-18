#include "exampleDetectorConstruction.hh"

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"

#include "G4Box.hh"
#include "G4PVPlacement.hh"

exampleDetectorConstruction::exampleDetectorConstruction()
{
	ConstructMaterials();
	DefineDimensions();
}

exampleDetectorConstruction::~exampleDetectorConstruction()
{
	DestructMaterials();
}

void exampleDetectorConstruction::DefineDimensions()
{
	labX = 20*cm;
	labY = 20*cm;
	labZ = 40*cm;

	detX = 15*cm;
	detY = 15*cm;
	detZ = 30*cm;
}

G4VPhysicalVolume* exampleDetectorConstruction::Construct()
{
	G4Box* labSolid = new G4Box("labSolid", labX/2, labY/2, labZ/2);
	G4LogicalVolume* labLV = new G4LogicalVolume(labSolid, Air, "labLV");
	G4VPhysicalVolume* labPV = new G4PVPlacement(0, G4ThreeVector(), "labPV", labLV, 0, false, 0);

	G4Box* detSolid = new G4Box("detSolid", detX/2, detY/2, detZ/2);
	G4LogicalVolume *detLV = new G4LogicalVolume(detSolid, Scint, "detLV");
	new G4PVPlacement(0, G4ThreeVector(0, 0, 5*cm), "detPV", detLV, labPV, false, 0);

	return labPV;
}

void exampleDetectorConstruction::ConstructMaterials()
{
	// STP_Temperature = 0 degree Celcius
	const G4double labTemp = STP_Temperature + 20.*kelvin;

	// Elements - G4Element(name, symbol, Z-number, molecular mass)
	elN = new G4Element("Nitrogen", "N", 7, 14.00674*g/mole);
	elO = new G4Element("Oxygen", "O", 8, 15.9994*g/mole);
	elAr = new G4Element("Argon", "Ar", 18, 39.948*g/mole);
	elC = new G4Element("Carbon", "C", 6, 12.011*g/mole);
	elH = new G4Element("Hydrogen", "H", 1, 1.00794*g/mole);

	// Materials - G4Material(name, density, # of element, state, temperature)
	Air = new G4Material("Air", 1.2929e-03*g/cm3, 3, kStateGas, labTemp);
		Air -> AddElement(elN, 75.47/99.95); 
		Air -> AddElement(elO, 23.20/99.95); 
		Air -> AddElement(elAr, 1.28/99.95); 

	Scint = new G4Material("Scintillator", 1.05*g/cm3, 2, kStateSolid, labTemp);
		Scint -> AddElement(elC, 10);
		Scint -> AddElement(elH, 11);
}

void exampleDetectorConstruction::DestructMaterials()
{
	delete Scint;
	delete Air;

	delete elH;
	delete elC;
	delete elAr;
	delete elO;
	delete elN;
}
