#include "MetaServer.hpp"

/**
	@author Sean Ryan <sryan@evercrack.com>
	@brief The handler that takes care of incoming connections
*/
class MetaServerHandlerUDP
{

public:

	MetaServerHandlerUDP(boost::asio::io_service& ios, const std::string& address, const unsigned int port);
	~MetaServerHandlerUDP();
	void start_receive();
	void handle_receive(const boost::system::error_code& error, std::size_t);

private:

	boost::asio::ip::udp::socket socket_;
	boost::asio::ip::udp::endpoint remote_endpoint_;
	boost::array<char, 1> recv_buffer_;

	const std::string address_;
	const unsigned int port_;

};