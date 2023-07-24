#include "sim_hla_recfileindex.h"
#include <fstream>

CSimHlaRecFileIndex::CSimHlaRecFileIndex()
{
  // constructor
}

CSimHlaRecFileIndex::~CSimHlaRecFileIndex()
{
  // destructor
}

void CSimHlaRecFileIndex::importFile(std::string location)
{
  std::ifstream inputStream;
  std::string lineInFile;
  std::string heading = "";
  
  const std::string headingTag = "::";


  // clear old data
  recFileIndex.clear();

  // open file specified at location
  inputStream.open(location);

  if (inputStream.is_open())
  {
    // parse each line
    while (std::getline(inputStream, lineInFile))
    {
      
      if (   (lineInFile.find_first_of("#") != 0 )  // line starting with # -> comment
          && (lineInFile.empty() != true)           // ignore empty lines
         )
      {
        // found a valid line
        if (lineInFile.find(headingTag) != std::string::npos)
        {
          // set up first field of pair
          heading = lineInFile.substr(headingTag.size(), lineInFile.size() - 1);
        }
        else
        {
          // store as pair <heading, recfilename>
          this->recFileIndex.push_back(std::make_pair<std::string, std::string>(heading, lineInFile));
        }
      }
    }
  }

  // close file handle
  inputStream.close();
}

bool CSimHlaRecFileIndex::findRecFileName(const std::string category,
                                          const std::string recFileName
                                         )
{
  bool foundInIndex = false;

  // iterate through vector of string pairs
  for (std::vector<std::pair<std::string, std::string>>::iterator it = recFileIndex.begin(); it != recFileIndex.end(); ++it)
  {
    // check if recoding file name is somehow to be found in the index
    if (   ( (*it).first.find(category)           != std::string::npos) // check if correct category is set
        && (   ( (*it).second.find(recFileName)   != std::string::npos) // check if rec file is listed
            || ( recFileName.find( (*it).second ) != std::string::npos) //    OR if keyword is mentioned in rec file name
           )
       )
    {
      // indicate a hit
      foundInIndex = true;
      break;
    }
  }
  return foundInIndex;
}
