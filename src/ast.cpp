#include "ast.h"

#include "Lexer.hpp"
#include "Parser.hxx"
#include "ParsingContext.h"
#include "visitor/Unparser.h"

#include <fstream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node) {
    tastr::visitor::Unparser(os).visit(node);
    return os;
}

std::string to_string(const tastr::ast::Node& node) {
    std::stringstream stream;
    stream << node;
    return stream.str();
}

tastr::ast::TopLevelNodeUPtr parse_(std::istream& input_stream,
                                    std::string& input_stream_name,
                                    bool debug_lexer,
                                    bool debug_parser) {
    tastr::parser::ParsingContext context(input_stream, input_stream_name);
    tastr::parser::Lexer lexer(context);
    lexer.set_debug_level(debug_lexer);
    tastr::parser::Parser parser(lexer, context);
    parser.set_debug_level(debug_parser);
    parser.parse();
    return std::move(context.get_top_level_node());
}

tastr::ast::TopLevelNodeUPtr parse_stdin(bool debug_lexer, bool debug_parser) {
    std::string input_stream_name("<stdin>");
    return parse_(std::cin, input_stream_name, debug_lexer, debug_parser);
}

tastr::ast::TopLevelNodeUPtr
parse_string(const std::string& string, bool debug_lexer, bool debug_parser) {
    std::istringstream input_stream(string);
    std::string input_stream_name("<string>");
    return parse_(input_stream, input_stream_name, debug_lexer, debug_parser);
}

tastr::ast::TopLevelNodeUPtr parse_file(const std::filesystem::path& filepath,
                                        bool debug_lexer,
                                        bool debug_parser) {
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: path '" << filepath << "' does not exist!";
    }

    if (std::filesystem::is_directory(filepath)) {
        std::cerr << "Error: expected file, path '" << filepath
                  << "' is a directory!";
    }

    std::ifstream input_stream(filepath);
    std::string input_stream_name(filepath.native());
    return parse_(input_stream, input_stream_name, debug_lexer, debug_parser);
}
