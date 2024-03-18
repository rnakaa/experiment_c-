#include <Command.hpp>

Command::Command(){
	this->commandsMap_["PASS"] = Command::pass;
}

void Command::executeCommand(const ssize_t fd, const std::string & command, std::vector<std::string> & arg){
	CommandFunction func = this->commandsMap_[command];
	if (func) {
		func(fd, arg);
	}
	else {
		std::cout << "Unknown Command: " << command << std::endl;
	}
}

void Command::pass(const ssize_t fd, std::vector<std::string> & arg){
	std::cout << "pass is " << arg.at(0) << std::endl;
}

void Command::parseMessage(std::string& message){
	std::istringstream iss(message);
	std::string word;

	iss >> this->command_;
	while (iss >> word){
		this->arg_.push_back(word);
	}
}