#ifndef PXT_header_only
#include "pxt.h"
#endif

#include <iostream>

namespace PXT_namespace {

    std::ostream& PXT_class::out_stream{PXT_ostream};

    PXT_class::Result PXT_class::counter{0, 0};

    PXT_class::Result::~Result() {
        if (failed > 0) {
            PXT_class::out_stream << "** " << failed << " of "
                                           << total << " tests failed **" << std::endl;
        }
        else if (total > 0) {
            PXT_class::out_stream << "** ALL " << total << " TESTS PASSED **" << std::endl;
        }
    }

    std::ostream& PXT_class::source_location() const {
        return out_stream << file_ << ' ' << '[' << func_ << ':' << line_ << ']' << ' ' << texpr_;
    }

    void PXT_class::plain_output() {
        source_location() << " == " << streamed_result.str() << std::endl;
    }

    void PXT_class::two_line_compare() {
        done_ = true;
        ++counter.total;
        if (streamed_result.str() != expected_result.str()) {
            ++counter.failed;
            source_location() << '\n'
                << " = received: " << streamed_result.str() << '\n'
                << " ! expected: " << expected_result.str() << std::endl;
        }
    }

    void PXT_class::multi_line_compare() {
        std::string streamed_line{};
        std::string expected_line{};
        std::ostringstream common{};
        while (std::getline(streamed_result, streamed_line),
                (expected_result >> std::ws),
                std::getline(expected_result, expected_line),
                !streamed_result.eof()
            && !expected_result.eof()
            && (streamed_line == expected_line)) {
                common << " =           " << expected_line << '\n';
        }
        done_ = true;
        ++counter.total;
        if (streamed_result.eof()
            && expected_result.eof()) return; // no difference

        ++counter.failed;
        if (streamed_result.eof()) { // less streamed than expected
            source_location() << '\n'
                << common.str()
                << " + expected: " << expected_line << std::endl;
            return;
        }
        if (expected_result.eof()) { // less expected than streamed
            source_location() << '\n'
                << common.str()
                << " + received: " << streamed_line << std::endl;
            return;
        }
        source_location() << '\n' // difference in streamed to expected
            << common.str()
            << " ~ received: " << streamed_line << '\n'
            << " ~ expected: " << expected_line << std::endl;
    }

} // namespace
