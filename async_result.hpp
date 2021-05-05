#pragma once

namespace std {
namespace net {

  template <class CompletionToken, class Signature>
  class async_result {
  public:
    using completion_handler_type = CompletionToken;
    using return_type = void;

    explicit async_result(completion_handler_type&) {}
    async_result(const async_result&) = delete;
    async_result& operator=(const async_result&) = delete;

    return_type get() {}
  };

}}
