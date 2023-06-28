#ifndef PXT_off

#ifndef PXT_ostream
#define PXT_ostream std::cout
#endif

#define PX(...)\
    PXT_namespace::PXT_class{__func__, __FILE__, __LINE__, #__VA_ARGS__, (__VA_ARGS__)}

#if defined(PXT_HAVE_BOOST_TYPEINDEX)\
 || defined(__has_include) && __has_include(<boost/type_index.hpp>)
#include <boost/type_index.hpp>
#define PT(...)\
    PXT_namespace::PXT_helper(__func__, __FILE__, __LINE__, #__VA_ARGS__,\
                              boost::typeindex::type_id_with_cvr<__VA_ARGS__>())
#endif

#if !defined(PX)\
 || !defined(PT)
struct PXT_dummy{ 
    template<typename T> void operator==(T const&) const {}
    template<typename T> void operator*=(T const&) const {}
    template<typename T> void operator>>=(T const&) const {}
    template<typename T> void operator%=(T const&) const {}
};
#if !defined(PX)
#define PX(...) PXT_dummy{}
#endif
#if !defined(PT)
#define PT(...) PXT_dummy{}
#endif
#endif

#include <sstream>
#include <iostream>

namespace PXT_namespace {
    
    class PXT_class {
        bool done_{};
        char const* func_;
        char const* file_;
        int const line_{};
        char const* texpr_;
        std::stringstream streamed_result{};
        std::stringstream expected_result{};
        std::ostream& source_location() const;
        void plain_output();
        void two_line_compare();
        void multi_line_compare();
        void glob_pattern_compare();

        struct Result {
            unsigned long long total;
            unsigned long long failed;
            ~Result();
        };
        static Result counter;

    public:
        static std::ostream& out_stream;
        static bool ignore_expecations;

        template<typename T>
        PXT_class(char const* func, char const* file, int line, char const* texpr, T const& expr)
            : func_{func}, file_{file}, line_{line}, texpr_{texpr}
        {
            streamed_result.copyfmt(out_stream);
            streamed_result << expr;
        }

        ~PXT_class() {
            if (not done_) plain_output();
        }

        template<typename T>
        void operator==(T const& expr) {
            expected_result.copyfmt(streamed_result);
            expected_result << expr;
            two_line_compare();
        }
       
        void operator>>=(std::string lines) {
            expected_result << lines;
            multi_line_compare();
        }

        void operator*=(std::string smatch) {
            glob_pattern_compare();    
        }
  
    };

} // namespace

#ifdef PXT_header_only
#include "pxt.cpp"
#endif

#endif
