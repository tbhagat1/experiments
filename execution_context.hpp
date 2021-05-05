#pragma once

#include <stdexcept>

namespace std {
namespace net {

  enum class fork_event {
    prepare,
    parent,
    child
  };

  class execution_context {
  public:

    class service;
    execution_context();
    execution_context(const execution_context&) = delete;
    execution_context& operator=(const execution_context&) = delete;
    virtual ~execution_context();

    void notify_fork(fork_event e);

  protected:

    void shutdown() noexcept;
    void destroy() noexcept;
  };

  template <class Service> typename Service::key_type&
    use_service(execution_context& ctx);

  template <class Service, class... Args> Service&
    make_service(execution_context& ctx, Args&&... args);

  template <class Service>
  bool has_service(const execution_context& ctx) noexcept;

  class service_already_exists : public logic_error {};

  class execution_context::service {
  protected:

    explicit service(execution_context& owner);

    service(const service&) = delete;
    service& operator=(const service&) = delete;

    virtual ~service();

    execution_context& context() noexcept;

  private:

    virtual void shutdown() noexcept = 0;
    virtual void notify_fork(fork_event e) {}

    execution_context& context_;
  };

}}
