#pragma once

#include <sys/socket.h>

namespace std {
namespace net {

  class socket_base {
  public:

    class broadcast;
    class debug;
    class do_not_route;
    class keep_alive;
    class linger;
    class out_of_band_inline;
    class receive_buffer_size;
    class receive_low_watermark;
    class reuse_address;
    class send_buffer_size;
    class send_low_watermark;

    using shutdown_type = int;
    static constexpr shutdown_type shutdown_receive = 1;
    static constexpr shutdown_type shutdown_send    = 2;
    static constexpr shutdown_type shutdown_both    = 3;

    using wait_type = int;
    static constexpr shutdown_type wait_read  = 4;
    static constexpr shutdown_type wait_write = 5;
    static constexpr shutdown_type wait_error = 6;

    using message_flags = int;
    static constexpr shutdown_type message_peek         = MSG_PEEK;
    static constexpr shutdown_type message_out_of_band  = MSG_OOB;
    static constexpr shutdown_type message_do_not_route = MSG_DONTROUTE;

    static const int max_listen_connections = SOMAXCONN;

  protected:

    socket_base();
    ~socket_base();

  };

}}
