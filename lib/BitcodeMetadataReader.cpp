#include "mull/BitcodeMetadataReader.h"

#include "mull/Bitcode.h"

#include <llvm/IR/DebugInfoMetadata.h>
#include <llvm/IR/Module.h>

#include <cassert>

std::string mull::BitcodeMetadataReader::getCompilationDatabase(
    std::vector<std::unique_ptr<mull::Bitcode>> &bitcode) {

  if (bitcode.empty()) {
    return "";
  }

  llvm::Module *module = bitcode.at(0)->getModule();
  ///module->print(llvm::errs(), nullptr);

  for (llvm::DICompileUnit *unit : module->debug_compile_units()) {
    llvm::StringRef flags = unit->getFlags();
    if (!flags.empty()) {
      return flags.str();
    }
  }

  return "";
}
