#ifndef TASTR_AST_S4_TYPE_NODE_HPP
#define TASTR_AST_S4_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class S4TypeNode final: public TypeNode {
  public:
    explicit S4TypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~S4TypeNode() = default;

    S4TypeNode(const S4TypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    S4TypeNode(S4TypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    S4TypeNode& operator=(const S4TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    S4TypeNode& operator=(S4TypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<S4TypeNode> clone() const {
        return std::unique_ptr<S4TypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual S4TypeNode* clone_impl() const override final {
        return new S4TypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using S4TypeNodePtr = S4TypeNode*;
using S4TypeNodeUPtr = std::unique_ptr<S4TypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_S4_TYPE_NODE_HPP */
