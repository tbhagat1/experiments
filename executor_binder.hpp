#pragma once

namespace std {
namespace net {

  template <class T, class Executor>
  class executor_binder {
  public:

    using target_type = T;
    using executor_type = Executor;

    executor_binder(T t, const Executor& ex);
    executor_binder(const executor_binder& other) = default;
    executor_binder(executor_binder&& other) = default;

    template <class U, class OtherExecutor>
    executor_binder(const executor_binder<U, OtherExecutor>& other);
    
    template <class U, class OtherExecutor>
    executor_binder(executor_binder<U, OtherExecutor>&& other);

  };

}}
