#ifndef TASTR_AST_CHARACTER_TYPE_H
#define TASTR_AST_CHARACTER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class CharacterScalarTypeNode final: public ScalarTypeNode {
  public:
    CharacterScalarTypeNode(const std::string& identifier)
        : ScalarTypeNode(identifier) {
    }

    ~CharacterScalarTypeNode() = default;

    CharacterScalarTypeNode(const CharacterScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    CharacterScalarTypeNode(CharacterScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    CharacterScalarTypeNode& operator=(const CharacterScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    CharacterScalarTypeNode& operator=(CharacterScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<CharacterScalarTypeNode> clone() const {
        return std::unique_ptr<CharacterScalarTypeNode>(this->clone_impl());
    }

    bool is_character_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual CharacterScalarTypeNode* clone_impl() const override final {
        return new CharacterScalarTypeNode(*this);
    };
};

using CharacterScalarTypeNodePtr = CharacterScalarTypeNode*;
using CharacterScalarTypeNodeUPtr = std::unique_ptr<CharacterScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_CHARACTER_TYPE_H */
