#pragma once

#include <memory>
#include <vector>

namespace mull {
class Bitcode;

class BitcodeMetadataReader {
public:
  std::string getCompilationDatabase(std::vector<std::unique_ptr<mull::Bitcode>> &bitcode);
};

} // namespace mull
