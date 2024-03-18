#include "Command.hpp"

Command::Command(){
	this->commandsMap_["PASS"] = Command::pass;
}

void Command::executeCommand(const int fd){
	CommandFunction func = this->commandsMap_[this->command_];
	if (func) {
		func(fd, this->arg_);
	}
	else {
		std::cout << "Unknown Command: " << this->command_ << std::endl;
	}
}

void Command::pass(const int fd, std::vector<std::string> & arg){
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

void Command::recCommand(const int fd, std::string message){
	parseMessage(message);
	executeCommand(fd);
	

}