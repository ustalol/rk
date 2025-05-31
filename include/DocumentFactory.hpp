#pragma once
#include "IDocument.hpp"
#include <unordered_map>

namespace DocumentsExample {

class DocumentFactory {
private:
    std::unordered_map<std::string, DocumentReader> m_readers;

public:
    void add(const std::string& extension, const DocumentReader& reader);
    DocumentType open(std::string path);
};

}
