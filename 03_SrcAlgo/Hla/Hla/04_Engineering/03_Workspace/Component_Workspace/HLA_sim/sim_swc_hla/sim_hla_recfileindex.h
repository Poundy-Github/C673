#pragma once

#include <string>
#include <vector>

class CSimHlaRecFileIndex
{
public:
  CSimHlaRecFileIndex();
  ~CSimHlaRecFileIndex();

  void importFile(std::string location);

  bool findRecFileName(const std::string category,
                       const std::string recFileName
                      );

private:
  std::vector< std::pair< std::string, std::string > > recFileIndex; // location to store the found rec file names
};
