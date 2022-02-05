/*
 *  Copyright 2012-2016 Robert Marmorstein
 *
 */
#include <iostream>
#include "filesys.h"
#include <string>
#include <charconv>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

void FileSystem::format() {
	N = m_disk_size / 1048 * 24;

	for (int i = 0; i < N; ++i) {
		m_disk[i] = '*';
	}


}

bool FileSystem::create(const string name) {
	bool is_empty = true;
	bool found_curr = false;
	int block_index = N;
	int pos = 0;
	int curr_pos = 0;
	int temp_pos = 0;
	int i;
	string temp_string = "";
	

	for (i = 0; i < N; i += 24) {
		if (m_disk[i] == '*') {
			if (!found_curr) {
				pos = i;
				found_curr = true;
			}
			continue;
		}
		else {
			read_string(i, temp_string, name.length());
			if (temp_string == name) return false;
			is_empty = false;
			read_int(i + 16, temp_pos);
			if (temp_pos > curr_pos) {
				curr_pos = temp_pos;
			}

		}	
	}
	if (i >= N && found_curr == false) {
		return false;
	}


	if (!is_empty) {
		block_index += (1024 + curr_pos);
	}

	write_string(pos, name, name.length());
	write_int(pos+16, block_index);
	write_int(pos+20, 0);

	return true;
}

//not completed
string FileSystem::list() const {
	ostringstream sout;
	string name;
	int size;

	for (int i = 0; i < N; i += 24) {
		if (m_disk[i] != '*') {
			read_string(i, name, 15);
			read_int(i + 20, size);
			name.erase(remove(name.begin(), name.end(), '*'), name.end());
			name.erase(remove(name.begin(), name.end(), '\0'), name.end());

			sout << left << setw(16) << name << left << setw(8) << size << endl;
		}
		
	}
	

	return sout.str();
}

bool FileSystem::rm(const string name) {
	string curr_file;
	string temp = name;


	for (int i = 0; i < N; i += 24) {
		if (m_disk[i] != '*') {
			read_string(i, curr_file, 15);
			curr_file.erase(remove(curr_file.begin(), curr_file.end(), '*'), curr_file.end());
			curr_file.erase(remove(curr_file.begin(), curr_file.end(), '\0'), curr_file.end());
			
			if (temp.compare(curr_file) == 0) {
				for (int j = i; j < i+24; j++) {
					m_disk[j] = '*';
				}
				return true;
			}
		}
		
	}

	return false;
}

bool FileSystem::rename(const string old_name, const string new_name) {

	int i;
	string curr_file;
	string old_file_check;



	for (i = 0; i < N; i += 24) {
		if (m_disk[i] == '*') continue;
		read_string(i, curr_file, 16);
		curr_file.erase(remove(curr_file.begin(), curr_file.end(), '*'), curr_file.end());
		curr_file.erase(remove(curr_file.begin(), curr_file.end(), '\0'), curr_file.end());
		if (curr_file == old_name) {
			for (int j = 0; j < N; j += 24) {
				if (m_disk[j] == '*') continue;
				read_string(j, old_file_check, 16);
				old_file_check.erase(remove(old_file_check.begin(), old_file_check.end(), '*'), old_file_check.end());
				if (old_file_check == new_name) return false;
			}
			write_string(i, new_name, new_name.length() > 15 ? 15 : new_name.length());
			return true;
		}

	}

	return false;
}

bool FileSystem::copy(const string old_name, const string new_name) {
	string curr_file;
	int old_block_index;
	int old_size;

	// find old_name
	for (int i = 0; i < N; i += 24) {
		if (m_disk[i] == '*') continue;
		read_string(i, curr_file, 16);
		curr_file.erase(remove(curr_file.begin(), curr_file.end(), '*'), curr_file.end());
		curr_file.erase(remove(curr_file.begin(), curr_file.end(), '\0'), curr_file.end());
		if (curr_file == old_name) {
			read_int(i + 16, old_block_index);
			read_int(i + 20, old_size);
			if (create(new_name)) {

				for (int j = 0; j < N; j += 24) {
					if (m_disk[i] == '*') continue;
					read_string(i, curr_file, 16);
					curr_file.erase(remove(curr_file.begin(), curr_file.end(), '*'), curr_file.end());
					curr_file.erase(remove(curr_file.begin(), curr_file.end(), '\0'), curr_file.end());
					if (curr_file == new_name) {
						write_int(j + 16, old_block_index);
						write_int(j + 20, old_size);
						break;
					}
				}
				return true;
			}
			return false;
		}

	}
	
	return false;
}

int FileSystem::open(const string name) {
	string curr_file;
	int size;
	int block_index;

	for (int i = 0; i < N; i++) {
		read_string(i, curr_file, name.length());
		if (curr_file == name) {
			read_int(i+16, block_index);
			read_int(i + 20, size);
			fh = new FileHandle(i, block_index, size);
			return fh->get_fd();
		}
	}
	return -1;
	
}


bool FileSystem::close(const int fd) const {

	return fh->close_file(fd);
	
}


bool FileSystem::read(const int fd, string& buffer, const unsigned int size) const {
	FileHandle* curr;
	if (!fh->exist_fd(fd)) return false;
	curr = fh->open_file(fd);

	read_string(curr->offset+curr->pos, buffer, size);

	curr = nullptr;
	delete curr;
	return true;
}


bool FileSystem::write(const int fd, const string str, const unsigned int size) {
	FileHandle* curr;

	if (!fh->exist_fd(fd)) return false;
	curr = fh->open_file(fd);
	write_string(curr->offset+curr->pos, str, size);
	write_int(curr->offset+20, size > curr->size ? size : curr->size);
	fh->offset = size;


	return true;
}