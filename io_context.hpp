#pragma once

#include <chrono>
#include <execution_context.hpp>

namespace std {
namespace net {

  class io_context : public execution_context {
  public:

    class executor_type;
    using count_type = int;

    io_context();
    explicit io_context(int concurrency_hint);
    io_context(const io_context&) = delete;
    io_context& operator=(const io_context&) = delete;

    ~io_context();
    executor_type get_executor() noexcept;

    count_type run();

    template <class Rep, class Period>
    count_type run_for(const chrono::duration<Rep, Period>& rel_time);

    template <class Clock, class Duration>
    count_type run_until(const chrono::time_point<Clock, Duration>& abs_time);

    count_type run_one();

    template <class Rep, class Period>
    count_type run_one_for(const chrono::duration<Rep, Period>& rel_time);

    template <class Clock, class Duration>
    count_type run_one_until(const chrono::time_point<Clock, Duration>& abs_time);

    count_type poll();

    count_type poll_one();

    void stop();

    bool stopped() const noexcept;

    void restart();

  private:

    class io_context_impl* impl_;

  };

}}

#include <io_context.ipp>
