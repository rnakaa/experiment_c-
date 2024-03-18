#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <fstream>
#include <sstream>

typedef void (*CommandFunction)(const int, std::vector<std::string> &);

class Command{
	private:
		std::map<std::string, CommandFunction> commandsMap_;

	public:
		Command();
		void executeCommand(const int fd);
		void parseMessage(std::string &message);
		void recCommand(const int fd, std::string message);

	private:
		static void pass(const int fd, std::vector<std::string> & arg);
		std::vector<std::string> arg_;
		std::string command_;
};

#endif