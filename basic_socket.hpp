#include <socket_base.hpp>

namespace std {
  class error_code;
}

namespace std {
namespace net {

  template <class Protocol>
  class basic_socket : public socket_base {
  public:

    // using executor_type = io_context::executor_type;
    using native_handle_type = int;
    using protocol_type = Protocol;
    using endpoint_type = typename protocol_type::endpoint;

    // executor_type get_executor() noexcept;

    // returns the native representation of this socket
    native_handle_type native_handle();

    //////
    // establishes a connection handle as if by:
    //   ::socket(proto.family(), proto.type(), proto.protocol())
    //////
    void open(const protocol_type& protocol = protocol_type());
    void open(const protocol_type& protocol, error_code& ec);

    void assign(const protocol_type& protocol,
                const native_handle_type& native_socket);
    void assign(const protocol_type& protocol,
                const native_handle_type& native_socket,
                error_code& ec);

    native_handle_type release();
    native_handle_type release(error_code& ec);

    bool is_open() const noexcept;

    void close();
    void close(error_code& ec);

    void cancel();
    void cancel(error_code& ec);

    template <class SettableSocketOption>
    void set_option(const SettableSocketOption& option);

    template <class SettableSocketOption>
    void set_option(const SettableSocketOption& option, error_code& ec);

    template <class GettableSocketOption>
    void get_option(const GettableSocketOption& option);

    template <class GettableSocketOption>
    void get_option(const GettableSocketOption& option, error_code& ec);

    template <class IoControlCommand>
    void io_control(IoControlCommand& command);

    template <class IoControlCommand>
    void io_control(IoControlCommand& command, error_code& ec);

    void non_blocking(bool mode);
    void non_blocking(bool mode, error_code& ec);
    bool non_blocking() const;

    void native_non_blocking(bool mode);
    void native_non_blocking(bool mode, error_code& ec);
    bool native_non_blocking() const;

    bool at_mark() const;
    bool at_mar(error_code& ec) const;

    size_t available() const;
    size_t available(error_code& ec) const;

    void bind(const endpoint_type& endpoint);
    void bind(const endpoint_type& endpoint, error_code& ec);

    void shutdown(shutdown_type what);
    void shutdown(shutdown_type what, error_code& ec);

    endpoint_type local_endpoint() const;
    endpoint_type local_endpoint(error_code& ec) const;

    endpoint_type remote_endpoint() const;
    endpoint_type remote_endpoint(error_code& ec) const;

    void connect(const endpoint_type& endpoint);
    void connect(const endpoint_type& endpoint, error_code& err);

    template <class CompletionToken>
    void async_connect(const endpoint_type& endpoint, CompletionToken&& token);

    void wait(wait_type w);
    void wait(wait_type w, error_code& ec);

    template <class CompletionToken>
    void async_wait(wait_type w, CompletionToken&& token);

  protected:

    // explicit basic_socket(io_context& ctx);

    // basic_socket(io_context& ctx, const protocol_type& protocol);
    // basic_socket(io_context& ctx, const endpoint_type& endpoint);
    // basic_socket(io_context& ctx, const endpoint_type& endpoint,
    //              const native_handle_type& native_socket);

    basic_socket(const basic_socket&) = delete;

    basic_socket(basic_socket&& rhs);
    template <class OtherProtocol>
    basic_socket(basic_socket<OtherProtocol>&& rhs);

    ~basic_socket();

    basic_socket& operator=(const basic_socket&) = delete;

    basic_socket& operator=(basic_socket&& rhs);
    template <class OtherProtocol>
    basic_socket& operator=(basic_socket<OtherProtocol>&& rhs);

  private:
    protocol_type protocol_;
  };

}}
