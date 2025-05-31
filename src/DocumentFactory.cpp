#include "DocumentFactory.hpp"
#include <stdexcept>

namespace DocumentsExample {

void DocumentFactory::add(const std::string& extension, const DocumentReader& reader) {
    m_readers.emplace(extension, reader);
}

DocumentType DocumentFactory::open(std::string path) {
    auto lastDot = path.find_last_of('.');
    if (lastDot != std::string::npos) {
        std::string extension = path.substr(lastDot + 1);
        auto it = m_readers.find(extension);
        if (it != m_readers.end()) {
            return it->second(path);
        }
    }
    throw std::invalid_argument("Trying to open a file with no extension or unsupported extension");
}

}
