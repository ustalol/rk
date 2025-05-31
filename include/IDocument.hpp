#pragma once
#include <string>
#include <memory>
#include <functional>
#include <vector>

namespace DocumentsExample {

struct IDocument {
    virtual ~IDocument() = default;
    virtual std::vector<std::string> getText() = 0;
};

using DocumentType = std::unique_ptr<IDocument>;
using DocumentReader = std::function<DocumentType(std::string)>;

}
