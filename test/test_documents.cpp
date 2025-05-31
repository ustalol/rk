#include <iostream>
#include <memory>
#include <vector>
#include "DocumentFactory.hpp"
#include "PdfDocument.hpp"
#include "HtmlDocument.hpp"
#include "OdtDocument.hpp"

bool test_extension_pdf() {
    using namespace DocumentsExample;
    DocumentFactory factory;
    factory.add("pdf", [](auto path) { return std::make_unique<PdfDocument>(path); });
    auto doc = factory.open("file.pdf");
    return doc->getText()[0] == "Text from PDF";
}

bool test_extension_html() {
    using namespace DocumentsExample;
    DocumentFactory factory;
    factory.add("html", [](auto path) { return std::make_unique<HtmlDocument>(path); });
    auto doc = factory.open("file.html");
    return doc->getText()[0] == "Text from HTML";
}

bool test_extension_odt() {
    using namespace DocumentsExample;
    DocumentFactory factory;
    factory.add("odt", [](auto path) { return std::make_unique<OdtDocument>(path); });
    auto doc = factory.open("file.odt");
    return doc->getText()[0] == "Text from ODT";
}

int main() {
    int failed = 0;
    if (!test_extension_pdf()) {
        std::cerr << "[FAIL] PDF test\n";
        failed++;
    }
    if (!test_extension_html()) {
        std::cerr << "[FAIL] HTML test\n";
        failed++;
    }
    if (!test_extension_odt()) {
        std::cerr << "[FAIL] ODT test\n";
        failed++;
    }

    if (failed == 0) {
        std::cout << "[OK] All tests passed.\n";
        return 0;
    } else {
        std::cerr << "[ERROR] Some tests failed.\n";
        return 1;
    }
}
