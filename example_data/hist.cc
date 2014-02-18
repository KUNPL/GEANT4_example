#include <TROOT.h>
#include <Riostream.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TH1D.h>
#include <TCanvas.h>

#include <fstream>

void hist();

int main()
{
	hist();

	return 0;
}

void hist()
{
	gStyle -> SetOptStat(0000);
	gStyle -> SetPadLeftMargin(0.15);
	gStyle -> SetPadRightMargin(0.05);
	gStyle -> SetPadTopMargin(0.05);
	gStyle -> SetPadBottomMargin(0.11);
	gStyle -> SetTitleXOffset(1.2);
	gStyle -> SetTitleYOffset(1.7);

	TCanvas *cvs = new TCanvas("cvs", "", 800, 800);
		cvs -> SetFillColor(0);
		cvs -> SetFillStyle(0);
		cvs -> cd();

	TH1D *hist = new TH1D("hist", "", 900, 0, 900);
	ifstream openFile("edep.out");

	Int_t x,y,z;
	Double_t edep;
	while (openFile)
	{
		openFile >> x >> y >> z >> edep;
		hist -> Fill(z, edep/1000);
	}

	hist -> GetXaxis() -> SetTitle("z (mm)");
	hist -> GetXaxis() -> CenterTitle();
	hist -> GetYaxis() -> SetTitle("dE_{dep}/dx (MeV/mm)");
	hist -> GetYaxis() -> CenterTitle();
	hist -> Draw();

	cout << hist -> Integral() << endl;

	cvs -> SaveAs("finalResult.pdf");
}
