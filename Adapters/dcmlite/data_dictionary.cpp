#include "data_dictionary.h"

#include <memory>
#include <mutex>

#include "tag_table.h"

namespace dcmlite {

DataDictionary& DataDictionary::Get() {
  static std::unique_ptr<DataDictionary> s_instance;
  static std::mutex s_mutex;

  if (!s_instance) {
    std::lock_guard<std::mutex> lock(s_mutex);

    if (!s_instance) {
      s_instance.reset(new DataDictionary());
    }
  }

  return *s_instance;
}

const DataEntry* DataDictionary::FindEntry(Tag tag) const {
  std::uint32_t tag_value = tag.ToUint32();

  std::size_t j = 0;  // begin
  std::size_t k = TAG_COUNT;  // end
  std::size_t i = 0;

  while (j < k) {
    i = j + (k - j) / 2;

    const DataEntry& entry = g_tag_table[i];

    if (tag_value < entry.tag) {
      k = i;
    } else if (tag_value > entry.tag) {
      j = i + 1;
    } else {
      return &entry;
    }
  }

  return NULL;
}

}  // namespace dcmlite
