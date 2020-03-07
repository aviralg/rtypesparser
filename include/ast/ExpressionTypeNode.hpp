#ifndef TASTR_AST_EXPRESSION_TYPE_NODE_HPP
#define TASTR_AST_EXPRESSION_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class ExpressionTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit ExpressionTypeNode(const std::string& name)
        : TypeNode(), Name(name) {
    }

    ~ExpressionTypeNode() = default;

    ExpressionTypeNode(const ExpressionTypeNode& node)
        : TypeNode(node), Name(node) {
    }

    ExpressionTypeNode(ExpressionTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    ExpressionTypeNode& operator=(const ExpressionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    ExpressionTypeNode& operator=(ExpressionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ExpressionTypeNode> clone() const {
        return std::unique_ptr<ExpressionTypeNode>(this->clone_impl());
    }

    bool is_expression_type_node() const override final {
        return true;
    }

  private:
    virtual ExpressionTypeNode* clone_impl() const override final {
        return new ExpressionTypeNode(*this);
    };
};

using ExpressionTypeNodePtr = ExpressionTypeNode*;
using ExpressionTypeNodeUPtr = std::unique_ptr<ExpressionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_NODE_HPP */
