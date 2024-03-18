#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <arpa/inet.h>
#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <fstream>
#include <sstream>

typedef void (*CommandFunction)(const ssize_t, std::vector<std::string> &);

class Command{
	private:
		std::map<std::string, CommandFunction> commandsMap_;

	public:
		Command();
		void executeCommand(const ssize_t fd, const std::string & command, std::vector<std::string> & arg);
		void parseMessage(std::string &message);

	private:
		static void pass(const ssize_t fd, std::vector<std::string> & arg);
		std::vector<std::string> arg_;
		std::string command_;
};

#endif