#pragma once

#include "llvm/Object/ObjectFile.h"

#include <string>
#include <map>

namespace Mutang {
  class MutangModule;
  class MutationPoint;

  class ObjectCache {
    std::map<std::string, llvm::object::OwningBinary<llvm::object::ObjectFile>> inMemoryCache;

  public:
    ObjectCache();

    llvm::object::ObjectFile *getObject(const MutangModule &module);
    llvm::object::ObjectFile *getObject(const MutationPoint &mutationPoint);

    void putObject(llvm::object::OwningBinary<llvm::object::ObjectFile> object,
                   const MutangModule &module);

    void putObject(llvm::object::OwningBinary<llvm::object::ObjectFile> object,
                   const MutationPoint &mutationPoint);

  private:
    llvm::object::ObjectFile *getObject(const std::string &identifier);
    void putObject(llvm::object::OwningBinary<llvm::object::ObjectFile> object,
                   const std::string &identifier);
  };
}
