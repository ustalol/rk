#include "PdfDocument.hpp"

namespace DocumentsExample {

PdfDocument::PdfDocument(std::string path) : m_path{std::move(path)} {}

std::vector<std::string> PdfDocument::getText() {
    return {"Text from PDF"};
}

}
