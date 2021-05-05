#pragma once

namespace std {
namespace net {

  template <class CompletionToken, class Signature>
  class async_completion {
  public:

    using completion_handler_type =
      async_result<decay_t<CompletionToken>, Signature>::completion_handler_type;

    explicit async_completion(CompletionToken& t);

    async_completion(const async_completion&) = delete;
    async_completion& operator=(const async_completion&) = delete;

    async_result<decay_t<CompletionToken>, Signature> result;
  };

}}
