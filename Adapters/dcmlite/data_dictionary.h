#ifndef DCMLITE_DATA_DICTIONARY_H_
#define DCMLITE_DATA_DICTIONARY_H_
#pragma once

// Data dictionary singleton.

#include "data_entry.h"
#include "tag.h"

namespace dcmlite {

class DataDictionary {
public:
  static DataDictionary& Get();

  ~DataDictionary() = default;

  const DataEntry* FindEntry(Tag tag) const;

private:
  DataDictionary() = default;
};

}  // namespace dcmlite

#endif  // DCMLITE_DATA_DICTIONARY_H_
