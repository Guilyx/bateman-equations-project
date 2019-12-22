#include "Reader.h"
#include "SolveBateman.h"

int main()
  {
  Reader* reader = new Reader("Radon");                       // Initializing Radon's Radioactive Decay Chain
  reader->SetInputFile("../radon222.txt");                       // File to read
  reader->FillListOfNuclei();                                 // Constructing a vector of "Nucleus"
  vector<Nucleus*> list = reader->GetListOfNuclei();          // Giving the vector to SolveBateman
  SolveBateman* solve = new SolveBateman();                   // Define the solving class

  solve->SetIJ(reader->GetNumberOfLinesInTextFile());         // Giving the defined list of cores to the class
  solve->SetListOfNuclei(list);
  
  // Option de debug a 0
  // solve->SetDebug(0);

  solve->Process();                                           //Calling Process to execute
  return 0;
  }
