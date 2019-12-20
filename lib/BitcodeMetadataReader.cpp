#include "mull/BitcodeMetadataReader.h"

#include "mull/Bitcode.h"
#include "mull/Logger.h"

#include <llvm/IR/DebugInfoMetadata.h>
#include <llvm/IR/Module.h>

#include <cassert>

std::map<std::string, std::string> mull::BitcodeMetadataReader::getCompilationDatabase(
    std::vector<std::unique_ptr<mull::Bitcode>> &bitcode) {

  std::map<std::string, std::string> bitcodeCompilationFlags;

  if (bitcode.empty()) {
    return bitcodeCompilationFlags;
  }

  for (auto &bitcodeModule: bitcode) {
    llvm::Module *module = bitcodeModule->getModule();

    std::string moduleFileName = module->getSourceFileName();

    for (llvm::DICompileUnit *unit : module->debug_compile_units()) {
      if (!unit->getFlags().empty()) {
        mull::Logger::info() << "Found compilation flags in the input bitcode\n";
      }
      bitcodeCompilationFlags[moduleFileName] = unit->getFlags().str();
    }
  }

  return bitcodeCompilationFlags;
}
