#ifndef TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class RawScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit RawScalarTypeNode(const std::string& name): ScalarTypeNode(name) {
    }

    ~RawScalarTypeNode() = default;

    RawScalarTypeNode(const RawScalarTypeNode& node): ScalarTypeNode(node) {
    }

    RawScalarTypeNode(RawScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    RawScalarTypeNode& operator=(const RawScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    RawScalarTypeNode& operator=(RawScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<RawScalarTypeNode> clone() const {
        return std::unique_ptr<RawScalarTypeNode>(this->clone_impl());
    }

    bool is_raw_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual RawScalarTypeNode* clone_impl() const override final {
        return new RawScalarTypeNode(*this);
    };
};

using RawScalarTypeNodePtr = RawScalarTypeNode*;
using RawScalarTypeNodeUPtr = std::unique_ptr<RawScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_RAW_SCALAR_TYPE_NODE_HPP */
