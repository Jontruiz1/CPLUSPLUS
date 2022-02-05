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
#include "test_base.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

static string build_answer()
{
	ostringstream sout;
	sout << left << setw(16) << "FileOne" << left << setw(8) << "0" << endl;
	sout << left << setw(16) << "FileTwo" << left << setw(8) << "0" << endl;
	return sout.str();
}

TestSimpleList::TestSimpleList(const string test_name) : TestBase(test_name)
{
	fs->format();
	fs->create("FileOne");
	fs->create("FileTwo");
	string list = fs->list();
	if (list != build_answer()) {
		fail_out << "directory listing is incorrect: " << endl;
		fail_out << "Instead of " << endl;
		fail_out << build_answer() << endl;
		fail_out << "You have " << endl;
		fail_out << list << endl;
	}
}
