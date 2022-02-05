#pragma once
/*
 *  Copyright 2012-2016 Robert Marmorstein
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 */
#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H
#include <vector>
#include <utility>

class FileHandle {
public:
	//The starting position of the open file (in the m_disk array)
	int pos;

	//How big the file is, so we know when to stop reading.
	int size;

	//The current position within the file block
	int offset;

	static std::vector<FileHandle*> opened;
	int current_fd = 0;
	
	FileHandle(int pos, int index, int size);
	int find_file(int fd);
	bool exist_fd(int fd);
	int get_fd() { return current_fd; }
	FileHandle* open_file(int fd);
	bool close_file(int fd);

};

#endif //FILE_HANDLE_H