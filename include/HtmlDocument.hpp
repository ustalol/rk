#pragma once
#include "IDocument.hpp"

namespace DocumentsExample {

class HtmlDocument : public IDocument {
private:
    std::string m_path;

public:
    explicit HtmlDocument(std::string path);
    std::vector<std::string> getText() override;
};

}
