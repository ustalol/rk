#pragma once
#include "IDocument.hpp"

namespace DocumentsExample {

class PdfDocument : public IDocument {
private:
    std::string m_path;

public:
    explicit PdfDocument(std::string path);
    std::vector<std::string> getText() override;
};

}
