#pragma once
#include "IDocument.hpp"

namespace DocumentsExample {

class OdtDocument : public IDocument {
private:
    std::string m_path;

public:
    explicit OdtDocument(std::string path);
    std::vector<std::string> getText() override;
};

}
