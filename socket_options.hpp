#pragma once

#include <sys/socket.h>
#include <chrono>
#include <socket_base.hpp>

namespace std {
namespace net {

  namespace chrono = std::chrono;

  class socket_base::linger {
  public:

    linger() noexcept;
    linger(bool e, chrono::seconds t) noexcept;

    bool enabled() const noexcept;
    void enable(bool e) noexcept;

    chrono::seconds timeout() const noexcept;
    void timeout(chrono::seconds) noexcept;

    template <class Protocol>
    int level(const Protocol& p = Protocol()) const noexcept;

    template <class Protocol>
    int name(const Protocol& p = Protocol()) const noexcept;

    template <class Protocol>
    const void* data(const Protocol& p = Protocol()) const noexcept;

    template <class Protocol>
    const size_t size(const Protocol& p = Protocol()) const noexcept;

  private:
    bool             enabled_;
    chrono::seconds  timeout_;
    ::linger         linger_;
  };

  inline
  socket_base::
  linger::
  linger() noexcept :
    enabled_(false),
    timeout_(0) {
    linger_.l_onoff = 0;
    linger_.l_linger  = 0;
  }

  inline
  socket_base::
  linger::
  linger(bool e,
         chrono::seconds t) noexcept :
    enabled_(e),
    timeout_(t) {
    linger_.l_onoff = enabled_ ? 1 : 0;
    linger_.l_linger = timeout_.count();
  }

  inline bool
  socket_base::
  linger::
  enabled() const noexcept {
    return enabled_;
  }

  inline void
  socket_base::
  linger::
  enable(bool e) noexcept {
    enabled_ = e;
    linger_.l_onoff = enabled_ ? 1 : 0;
    linger_.l_onoff = enabled_ ? linger_.l_onoff : 0;
  }

  inline chrono::seconds
  socket_base::
  linger::
  timeout() const noexcept {
    return timeout_;
  }

  inline void
  socket_base::
  linger::
  timeout(chrono::seconds t) noexcept {
    timeout_ = t;
  }

  template <class Protocol>
  inline int
  socket_base::
  linger::
  level(const Protocol& p) const noexcept {
    return SOL_SOCKET;
  }

  template <class Protocol>
  inline int
  socket_base::
  linger::
  name(const Protocol& p) const noexcept {
    return SO_LINGER;
  }

  template <class Protocol>
  inline const void*
  socket_base::
  linger::
  data(const Protocol& p) const noexcept {
    return &linger_;
  }

  template <class Protocol>
  inline const size_t
  socket_base::
  linger::
  size(const Protocol& p) const noexcept {
    return sizeof(linger_);
  }

}}
