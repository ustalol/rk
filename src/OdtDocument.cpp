#include "OdtDocument.hpp"

namespace DocumentsExample {

OdtDocument::OdtDocument(std::string path) : m_path{std::move(path)} {}

std::vector<std::string> OdtDocument::getText() {
    return {"Text from ODT"};
}

}
