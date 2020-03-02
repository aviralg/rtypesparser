#ifndef TASTR_AST_TYPE_DECLARATION_SEQUENCE_H
#define TASTR_AST_TYPE_DECLARATION_SEQUENCE_H

#include "Sequence.h"
#include "TypeDeclarationNodeSequenceNode.h"
#include "TypeNode.h"

#include <string>

namespace tastr::ast {

class TopLevelNode final: public Node {
  public:
    explicit TopLevelNode(const std::string& name)
        : name_(name), sequence_(new TypeDeclarationNodeSequenceNode()) {
    }

    explicit TopLevelNode(const std::string& name,
                          TypeDeclarationNodeSequenceNodeUPtr sequence)
        : name_(name), sequence_(std::move(sequence)) {
    }

    TopLevelNode(const TopLevelNode& node)
        : Node(node), sequence_(node.get_type_declarations().clone()) {
    }

    ~TopLevelNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<TopLevelNode> clone() const {
        return std::unique_ptr<TopLevelNode>(this->clone_impl());
    }

    bool is_top_level_node() const override final {
        return true;
    }

    const TypeDeclarationNodeSequenceNode& get_type_declarations() const {
        return *sequence_.get();
    }

    TypeDeclarationNodeSequenceNode& get_type_declarations() {
        return *sequence_.get();
    }

  private:
    virtual TopLevelNode* clone_impl() const override final {
        return new TopLevelNode(*this);
    }

    std::string name_;
    TypeDeclarationNodeSequenceNodeUPtr sequence_;
};

using TopLevelNodePtr = TopLevelNode*;
using TopLevelNodeUPtr = std::unique_ptr<TopLevelNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_SEQUENCE_H */
