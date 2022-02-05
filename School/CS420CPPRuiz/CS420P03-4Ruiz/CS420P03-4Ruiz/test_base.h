/*
 *  Copyright 2012-2016 Robert Marmorstein
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TEST_H
#define TEST_H

#include "filesys.h"

#include <sstream>

class TestBase {
	protected:

	std::string m_test_name;
	std::ostringstream fail_out;
	
	FileSystem* fs;

	public:

	TestBase(const std::string test_name);
	~TestBase();
};

class TestFormat : public TestBase {
	public:
	TestFormat(const std::string test_name);
};

class TestCreate: public TestBase {
	public:
	TestCreate(const std::string test_name);
};

class TestList: public TestBase {
	public:
	TestList(const std::string test_name);
};

class TestSimpleList: public TestBase {
	public:
	TestSimpleList(const std::string test_name);
};

class TestDelete: public TestBase {
	public:
	TestDelete(const std::string test_name);
};

class TestRename: public TestBase {
	public:
	TestRename(const std::string test_name);
};

class TestCopy: public TestBase {
	public:
	TestCopy(const std::string test_name);
};

class TestOpen: public TestBase {
	public:
	TestOpen(const std::string test_name);
};

class TestClose: public TestBase {
	public:
	TestClose(const std::string test_name);
};

class TestWrite: public TestBase {
	public:
	TestWrite(const std::string test_name);
};

class TestRead: public TestBase {
	public:
	TestRead(const std::string test_name);
};

#endif //TEST_H
