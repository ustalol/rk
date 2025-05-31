#include "HtmlDocument.hpp"

namespace DocumentsExample {

HtmlDocument::HtmlDocument(std::string path) : m_path{std::move(path)} {}

std::vector<std::string> HtmlDocument::getText() {
    return {"Text from HTML"};
}

}
