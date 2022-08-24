#include "User.h"
#include"Server.h"
#include"Client.h"
#include<chrono>
#include <thread>
#include <future>

inline User* create_user(char type, std::future<std::string>* connect_ip)
{
	User* user;
	if (type == 's')
	{
		user = new Server();

	}
	else if (type == 'c')
	{
		user = new Client();
		std::cout << "Enter ip friend " << std::endl;
		std::string IP = connect_ip->get();
		std::cout << IP << std::endl;
		user->set_connect_ip(IP);

	}
	else
	{
		std::cout << "no connection \t error symbol\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(true);
	}
	return user;
}
inline void handle_connection(User* user)
{
	if (user->connect())
	{
		std::cout << "connect is correct\n";
	}
	else
	{
		std::cout << "connect is not correct\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::exit(true);
	}
}

template<typename T>
inline T read(std::string str)
{
	std::cout << str;
	T type;
	std::cin >> type;
	return type;
}

inline void connecting(char type, std::future<std::string>* connect_ip)
{
	User* user = create_user(type, connect_ip);
	handle_connection(user);

	std::string user_name = read<std::string>("Enter your name: \n");
	user->set_name(user_name);

	std::cout << "Enter message\n";
	user->run_message();
}
