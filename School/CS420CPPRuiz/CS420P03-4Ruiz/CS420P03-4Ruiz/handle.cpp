#include "handle.h"


std::vector<FileHandle*> FileHandle::opened = {};

FileHandle::FileHandle(int offset, int index, int size) {
	
	this->pos = index;
	this->size = size;
	this->offset = offset;
	while (exist_fd(current_fd)) {
		current_fd++;
	}

	opened.push_back (this);

}


bool FileHandle::exist_fd(int fd) {
	for (int i = 0; i < opened.size(); i++) {
		if (opened[i]->get_fd() == fd) {
			return true;
		}
	}
	return false;
}

FileHandle* FileHandle::open_file(int fd) {

	for (int i = 0; i < opened.size(); i++) {
		if (opened[i]->get_fd() == fd) {
			return opened[i];
		}
	}
	
}

bool FileHandle::close_file(int fd) {
	
	for (int i = 0; i < opened.size(); i++) {
		if (opened[i]->get_fd() == fd) {
			delete opened[i];
			opened.erase(opened.begin() + i);
			return true;
		}
	}
	return false;

}